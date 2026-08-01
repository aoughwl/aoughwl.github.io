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
| **HTTPS** (same module, same coroutine) | `serveHttpsReactor(port, cert, key, handler)` | 30 simultaneous TLS conns × 5 = 150/150, one thread |
| **HTTP/2** (`serve/reactorh2.nim`) | `serveHttp2Reactor(port, handler)` | **h2spec 146/146** |
| **HTTP/2 over TLS** | `serveHttp2TlsReactor(port, cert, key, handler)` | **h2spec 146/146** over TLS |
| **HTTPS with ALPN dispatch** | `serveHttpsAlpnReactor(port, cert, key, handler)` | h2 + http/1.1 interleaved on one port; h2spec 146/146 on that port |
| **WebSocket** RFC 6455 (`serve/reactorws.nim`) | `serveWsReactor(port, handler)` | Autobahn-grade, 40 clients = 160/160, one thread |
| **wss://** (same module, same coroutine) | `serveWssReactor(port, cert, key, handler)` | 20 simultaneous TLS clients = 80/80, one thread |
| **HTTP/3 (QUIC)** (`serve/reactorh3.nim`) | `serveH3Reactor(port, cert, key, handler)` | 20 independent QUIC clients = 20/20, one thread |
| **All three at once** (`serve/reactorall.nim`) | `serveAllReactor(port, cert, key, handler)` | HTTP/1.1 + HTTP/2 + HTTP/3 on one port, one handler, one thread; the HTTP/3 leg driven by third-party aioquic |
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

**HTTP/2** keeps all protocol work in libnghttp2, which is a pure codec — it
never touches a socket. The coroutine drains what the session has queued and
feeds it what it reads; `h2NextOut` / `h2Feed` are the whole seam. Sessions live
in a fixed table because nghttp2 keeps the `user_data` pointer it is given, and
a coroutine local is not address-stable; the table size is the concurrency
bound and overflow is counted, not dropped in silence.

The score was **95/146 before this server existed**, against the blocking
HTTP/2 driver, and the recorded reason — "it never answers a protocol violation
with GOAWAY" — was wrong. Every failing section passes when run alone: the
blocking server drives one connection to completion before accepting again, so
one connection left open wedges the listener and every later case times out.
*When a conformance suite fails only in aggregate, suspect the concurrency
model, not the protocol code.* Three real bugs were hiding behind that
misdiagnosis: `nghttp2_session_mem_recv` may consume less than it is given (a
frame in the tail of a read was being dropped); `close()` with unread bytes
queued makes the kernel send RST where the peer expects FIN; and nghttp2
silently discards a HEADERS naming an already-used stream id without ever
calling `on_begin_headers`, so RFC 7540 §5.1.1 has to be enforced from
`on_begin_frame`.

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

```nim
import serve, serve/reactorh2

proc handler(req: Request): Response {.nimcall.} =
  response(200, "text/plain", "ok " & req.path & "\n")

# One HTTPS port: HTTP/2 for clients that ask for it, HTTP/1.1 for the rest.
serveHttpsAlpnReactor(8443, "cert.pem", "key.pem", handler)
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

## TLS, and one body per protocol

`serve/asynctls.nim` is the TLS twin of the async I/O primitives —
`awaitTlsHandshake` / `awaitTlsRead` / `awaitTlsWriteAll`. Nothing new was
needed underneath: the `tls` package already returns `tlsWantRead` /
`tlsWantWrite` on a non-blocking socket, and those map straight onto parking for
`EPOLLIN` / `EPOLLOUT`. Handshakes are therefore async like everything else — a
peer that stalls half-way through one costs a coroutine, not the thread.

Two traps worth naming:

- **Make the accepted fd non-blocking *before* wrapping it.** `wrapServer`
  starts the handshake; on a blocking fd it runs the entire handshake inline, on
  the reactor thread.
- **The direction is TLS's choice, not the operation's.** A read can want
  writability (a TLS 1.3 key update) and a write can want readability, so each
  primitive parks on whichever the status names.

Teardown is `close_notify` → FIN → bounded drain rather than a bare `close()`:
closing while the peer's last bytes sit unread makes the kernel answer them with
RST. That detail alone was worth two h2spec cases.

`serve/asyncconn.nim` then keeps this from doubling the code. A `Conn` is
`{fd, isTls, tls}` and the `awaitConn*` templates branch on `isTls`, each arm
inlining the primitive it needs — a runtime branch is the only abstraction the
coroutine transform allows, and it costs one predictable branch against a
syscall. HTTP/1.1, HTTP/2 and WebSocket each run **one** connection body for
both transports; only the accept loop differs.

---

## Idle timeouts

The reactor originally had no clock at all: `epoll_wait` blocked forever, so a
coroutine parked on a socket that never became ready stayed parked for the life
of the process. One silent peer could hold a connection — and, for HTTP/2, one
of the fixed session slots — indefinitely.

`setIdleTimeout(fd, ms)` arms a `CLOCK_MONOTONIC` deadline when a coroutine
parks and disarms it on readiness, so it measures *idleness*, not connection
age; `epoll_wait` then blocks until the nearest deadline. An expiry **shuts the
socket down** instead of resuming the continuation with an error — the coroutine
reads 0 and takes the end-of-connection path it already has, so no server needed
a line of new control flow. Defaults: 60 s for HTTP/1.1 and HTTP/2, off for
WebSocket, since a silent subscription is not a stalled one.

---

## Timers that resume, and stopping

Two things the loop gained beyond connections.

**A timer that resumes rather than kills.** The idle timeout above ends a
connection, which is right for a peer that has gone quiet and wrong for a
protocol servicing its own timers. `awaitReadableFor(fd, ms, timedOut)` returns
on readability *or* on the deadline and says which. That is what let HTTP/3 give
up its private epoll loop and join the shared reactor — and therefore what makes
one thread able to serve TCP and QUIC together.

**A stop.** `run()` used to loop until the process was killed, so ending a
server meant cutting a response in half. `requestStop(graceful)` writes 8 bytes
to an eventfd the loop also watches — the only work a signal handler may do, and
the only way to interrupt a blocked `epoll_wait`. A graceful stop closes the
listeners and lets in-flight connections finish; `run()` returns when the last
one closes. The server entry points install SIGINT/SIGTERM handlers, so Ctrl-C
drains.

## One port, three protocols

```nim
import serve, serve/reactorall

proc handler(req: Request): Response {.nimcall.} =
  response(200, "text/plain", "ok " & req.path & "\n")

serveAllReactor(8443, "cert.pem", "key.pem", handler)
```

TLS/TCP with ALPN dispatch (`h2` or `http/1.1`) and QUIC/UDP on the same port
number, from one handler, on one thread. Every TCP response carries
`Alt-Svc: h3=":8443"` — without it a browser never tries HTTP/3, however well
the UDP side works. HTTP/3's `(method, path, body)` shape is adapted to
`Request`/`Response` inside `reactorall`, so callers write one handler rather
than two.

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
