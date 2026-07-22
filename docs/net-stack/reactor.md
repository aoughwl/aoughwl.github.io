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
| **WebSocket** RFC 6455 (`serve/reactorws.nim`) | `serveWsReactor(port, handler)` | handshake + masked-frame echo, 40 clients = 160/160, one thread |

Each connection is a **single flat coroutine**: HTTP reads a full request
(Content-Length or chunked), runs the handler, writes the response, loops for
keep-alive; WebSocket reads the Upgrade, handshakes, then decodes frames
incrementally (its own buffer-based decoder, since the `ws` package ships only a
transport-coupled reader), reassembling fragments and auto-answering ping/close.

```nim
import serve/reactorhttp, http/request, http/response

proc handler(req: Request): Response {.nimcall.} =
  response(200, "text/plain", "hello from the async reactor\n")

serveHttpReactor(8140, handler)   # one thread, epoll, many connections
```

The blocking worker-pool servers (`serve/loop.nim`, `serve/pool.nim`) remain for
thread-per-connection; the reactor variants are the single-thread-multiplexing
alternative for high connection counts. [aowlmcp](/docs/aowlmcp)'s HTTP transport
(`serveHttpAsync`) runs on this reactor.

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
