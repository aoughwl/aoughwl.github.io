# The reactor — single-threaded async

The net stack's asynchronous concurrency model: one OS thread multiplexes
thousands of connections with **epoll** and **passive-proc coroutines**, the
alternative to the blocking worker pool. It is the async backbone that the
async HTTP and WebSocket servers ride on.

[[toc]]

---

## The model

Nimony's *passive procs* are continuation coroutines: `delay()` reifies a
coroutine's continuation, `suspend()` parks it, and a scheduler drives it with
`complete()`. The reactor **is** that scheduler, driven by epoll:

- Our own epoll binding (`tcp/epoll.nim`) — the tcp layer previously owned only
  `poll(2)`.
- A `Reactor` holds the epoll fd and a table of parked continuations keyed by
  fd. `run()` calls `epoll_wait` and, for each ready fd, resumes the parked
  coroutine.
- The async I/O primitives (`awaitAccept` / `awaitRead` / `awaitWriteAll`) try a
  nonblocking syscall and, on `EAGAIN`, park the calling coroutine against the
  fd and `suspend()`.

The language hands us suspendable continuations; the reactor is the scheduler
epoll drives. No nimony `std` async, no thread pool — one thread, everything
cooperatively multiplexed.

---

## Async servers

| Server | Entry | Verified |
|---|---|---|
| **HTTP/1.1** (`serve/reactorhttp.nim`) | `serveHttpReactor(port, handler)` | 60 keep-alive conns × 5 reqs = 300/300, one thread |
| **WebSocket** RFC 6455 (`serve/reactorws.nim`) | `serveWsReactor(port, handler)` | Autobahn-grade, 40 clients = 160/160, one thread |
| **HTTP/3 (QUIC)** (`serve/reactorh3.nim`) | `serveH3Reactor(port, cert, key, handler)` | 20 independent QUIC clients = 20/20, one thread |
| **QUIC datagrams** (RFC 9221) | `sendDatagram` / `takeDatagram` | round-trip echo, ASan-clean |
| **WebTransport** (extended CONNECT + WT datagrams) | `clientWtConnect` / `wtSendDatagram` | session + datagram round-trip (needs vendored nghttp3 ≥ 1.x) |

Each TCP connection is a **single flat coroutine**: HTTP reads a full request
(Content-Length or chunked), runs the handler, writes the response, loops for
keep-alive; WebSocket reads the Upgrade, handshakes, then decodes frames
incrementally (its own buffer-based decoder, since the `ws` package ships only a
transport-coupled reader), reassembling fragments and auto-answering ping/close.

**WebSocket conformance.** The async WS path is Autobahn-strict: every client
frame must be masked; RSV2/3 and non-negotiated RSV1 are refused; reserved
opcodes and oversized/fragmented control frames are refused; text is UTF-8
validated *incrementally across fragments* (Höhrmann DFA, Close 1007 on invalid);
close codes are validated and echoed (Close 1002 on a bad code); and
permessage-deflate is compressed/inflated per message — 19/19 conformance cases,
one thread.

**HTTP/3** rides QUIC over a single UDP socket. The QUIC transport, TLS 1.3
handshake, connection-ID routing, timers, and the HTTP/3 (QPACK) layer live in a
C glue shim (`quic/quicglue.c`) compiled against system **ngtcp2 + nghttp3 +
GnuTLS**; the shim exposes a small pull-based API and the reactor owns only the
epoll wait on the UDP fd (feeding datagram readiness and QUIC timer expiries into
the shim). GET and POST are supported — the same design that lets
[aowlmcp](/docs/aowlmcp) run its MCP transport over HTTP/3.

```nim
import serve/reactorhttp, http/request, http/response

proc handler(req: Request): Response {.nimcall.} =
  response(200, "text/plain", "hello from the async reactor\n")

serveHttpReactor(8140, handler)   # one thread, epoll, many connections
```

The blocking worker-pool servers (`serve/loop.nim`, `serve/pool.nim`) remain for
thread-per-connection; the reactor variants are the single-thread-multiplexing
alternative for high connection counts. [aowlmcp](/docs/aowlmcp)'s HTTP and
HTTP/3 transports (`serveHttpAsync`, `serveH3`) both run on this reactor.

```nim
import serve/reactorh3

proc handle(meth, path, body: string): H3Response {.nimcall.} =
  response(200, "text/plain", "hello over QUIC: " & meth & " " & path & "\n")

serveH3Reactor(8443, "cert.pem", "key.pem", handle)   # HTTP/3 on one thread
```

Build the QUIC glue shim first with `quic/build.sh` (Ubuntu deps:
`libngtcp2-dev libngtcp2-crypto-gnutls-dev libnghttp3-dev libgnutls28-dev`) and
put `libaowlquic.so` on the loader path.

---

## Two coroutine-transform constraints

Building this surfaced two defects in the current Nimony coroutine transform,
both worked around locally (and worth filing against the fork):

1. **A caller looping over a suspending callee corrupts the coroutine frame.**
   So the `await*` primitives are **templates** that inline their suspend loop
   into one flat coroutine, rather than passive procs called in a loop.
2. **`break`/`return` in the same branch as a `suspend` crashes goto-lowering.**
   So loop exits are carried by a `done`/`failed` flag on the `while` condition.

Both rules are mechanical; when the transform is fixed the templates can become
ordinary passive procs unchanged.
