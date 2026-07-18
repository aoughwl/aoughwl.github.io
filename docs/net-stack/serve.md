---
repo: aoughwl/serve
---

# serve — programmable HTTP/1.1 + HTTP/2 server

The top of the aoughwl networking stack. You write a handler
`proc(req: Request): Response` and return whatever `Response` you like; `serve`
owns the accept/read/write loop, request framing, keep-alive, and hardening.
It sits above `tcp`/`net` (transport), `tls` (HTTPS), and `http` (the
transport-free request/response helpers, all re-exported), and speaks HTTP/2
through an opt-in `nghttp2` binding.

> **Status** — Production-ready for HTTP/1.1 and HTTP/2. HTTP/1.1 + HTTPS + a bounded worker-thread pool + h2c/h2-over-TLS all ship and are covered by e2e tests. An opt-in **router + middleware** layer (`serve/router`) now provides method+path routing with `:id` params, a trailing `*` wildcard, and a middleware chain. The remaining gap is HTTP/3 *serving*, which is infeasible (no QUIC library); the `requests` client already speaks h3.

## Quickstart

```nim
import serve

# A programmable handler decides every response. Handlers are `.closure`
# (nimony requires the pragma; they may capture state).
proc app(req: Request): Response {.closure.} =
  if req.path == "/":
    response(200, "text/html", "<h1>hi</h1>")
  else:
    response(404, "text/plain", "not found\n")

serve(8080, app)                                  # HTTP/1.1, loop forever
# serveTls(8443, "cert.pem", "key.pem", app)      # HTTPS, same handler
# serve("/var/www", 8080)                         # built-in static-file server
```

## API

### Handler types

| symbol | signature | what it does |
|---|---|---|
| `Handler` | `proc(req: Request): Response {.closure.}` | The request handler for the single-threaded loops. `.closure` so it can capture state (e.g. a root directory). |
| `NimcallHandler` | `proc(req: Request): Response {.nimcall.}` | A handler as a bare function pointer (no captured env). Required by the worker pool: a `{.nimcall.}` proc crosses module/thread boundaries cleanly where a closure in another module's global does not. Per-request state must come from thread-safe globals. |
| `ServerConn` | `object (isTls: bool; fd: TcpHandle; tls: TlsSocket)` | The transport under one served connection — plaintext `TcpHandle` or `TlsSocket`. `fd` is always the underlying descriptor (so socket options like the read timeout apply to both). Lets the request/response core run byte-for-byte identically over HTTP and HTTPS. |

### Serving (single-threaded)

| symbol | signature | what it does |
|---|---|---|
| `serve` | `proc(port: int; handler: Handler; maxRequests = 0)` | Run a programmable plaintext server. Loops forever unless `maxRequests > 0`, then exits after that many **connections** (used by tests). |
| `serve` | `proc(root: string; port: int; maxRequests = 0)` | Static-file server under `root`, built on `staticHandler` over the same loop. Backwards-compatible API. |
| `serveTls` | `proc(port: int; certFile, keyFile: string; handler: Handler; maxRequests = 0)` | HTTPS. Loads a PEM cert chain + key into a shared `TlsContext`; each accepted socket gets its own server-side TLS session, then runs the same handler loop. |
| `serveConnection` | `proc(fd: TcpHandle; handler: Handler)` | Serve one already-accepted plaintext socket to completion. Exposed so tests/drivers can hand it a socket. |
| `serveConnectionTls` | `proc(fd: TcpHandle; ctx: TlsContext; handler: Handler)` | Wrap one accepted socket in a server-side TLS session and serve it. Drops the connection silently if the handshake fails. |
| `serveConnectionNimcall` | `proc(fd: TcpHandle; handler: NimcallHandler)` | Serve one plaintext socket with a `{.nimcall.}` handler — the thread-safe entry the worker pool uses. |
| `serveConnectionTlsNimcall` | `proc(fd: TcpHandle; ctx: TlsContext; handler: NimcallHandler)` | TLS variant of `serveConnectionNimcall`. |

### Serving (concurrent — `serve/pool`)

A bounded pool of worker threads that all `accept()` on **one** shared listening
socket; the kernel hands each incoming connection to one waiting worker. No
per-connection thread churn, no unbounded growth. The pool is process-global
(one server per process).

| symbol | signature | what it does |
|---|---|---|
| `serveConcurrent` | `proc(port: int; handler: NimcallHandler; workers = 4)` | Concurrent plaintext server: `workers` threads share one listener. Loops forever (workers never return). |
| `serveTlsConcurrent` | `proc(port: int; certFile, keyFile: string; handler: NimcallHandler; workers = 4)` | Concurrent HTTPS server: `workers` threads share one listener and a single `TlsContext`. |
| `configurePool` | `proc(listenFd: TcpHandle; handler: NimcallHandler; useTls: bool; ctx: TlsContext)` | Install the shared listening socket + handler that workers serve. Lower-level; tests drive it directly. |
| `spawnWorker` | `proc(t: var RawThread)` | Create one worker thread into caller-owned storage `t`. `t` **must** outlive the thread (`create` passes `addr t` to the OS; a by-value `RawThread` would dangle). Keep it in a long-lived array/global. |
| `MaxWorkers` | `const = 256` | Upper bound; `runPool` clamps the requested `workers` into `1..MaxWorkers`. |

### Routing + middleware (`serve/router`)

Opt-in `import serve/router`. A `Router` dispatches on **method + path**: `:id`
segments are path params and a trailing `*` captures the remainder of the path,
both read back off the request with `param` / `wildcard`. A middleware chain
wraps the matched handler (and the 404/405 responses). No path match → `404`
(or your `notFound` handler); path matches but wrong method → `405` with an
`Allow` header; `HEAD` falls back to a `GET` route.

Handlers and middleware are **`{.nimcall.}`** function pointers, not closures —
a hard requirement: the current nimony C backend miscompiles a closure stored
in a `seq`/object field, and cannot pass a closure as a parameter of another
closure (the classic `next: Handler` middleware shape). Storing bare function
pointers sidesteps both, and as a bonus makes the router worker-pool compatible.
The middleware continuation is passed as a plain `Chain` value and advanced with
`proceed(nxt, req)` — the idiomatic stand-in for `next(req)`.

```nim
import serve
import serve/router

proc getUser(req: Request): Response {.nimcall.} =
  response(200, "text/plain", "user " & param(req, "id") & "\n")

proc logging(req: Request; nxt: Chain): Response {.nimcall.} =
  let resp = proceed(nxt, req)          # run the rest of the chain + handler
  echo req.meth, " ", req.path, " -> ", resp.status
  return resp

var r = newRouter()
r.use(logging)
r.get("/users/:id", getUser)
r.get("/static/*", serveAsset)          # wildcard(req) == the rest of the path
r.post("/users", createUser)
serveRouter(8080, r)
```

| symbol | signature | what it does |
|---|---|---|
| `Router` | `object (id: int)` | A handle to a registered router (its route/middleware tables live in a module-global registry, since function pointers can't be captured). |
| `RouteHandler` | `proc(req: Request): Response {.nimcall.}` | A route handler — same shape as `NimcallHandler`. Reads the request (incl. captured params) and returns the response. |
| `Middleware` | `proc(req: Request; nxt: Chain): Response {.nimcall.}` | Wraps the downstream chain; run logic before/after `proceed(nxt, req)`, short-circuit by not calling it, or rewrite the response. |
| `Chain` | `object (rid, idx: int)` | Opaque continuation handed to a middleware; advance with `proceed`. |
| `newRouter` | `proc(): Router` | Create an empty router (no routes, no middleware, default 404). |
| `get` / `post` / `put` / `patch` / `delete` / `head` / `options` | `proc(r: Router; pattern: string; h: RouteHandler)` | Register `h` for that method + `pattern`. `:name` = path param, trailing `*` = wildcard. |
| `use` | `proc(r: Router; mw: Middleware)` | Append a middleware (runs in registration order; first is outermost). |
| `notFound` | `proc(r: Router; h: RouteHandler)` | Custom handler for unmatched paths (replaces the default 404). |
| `param` | `proc(req: Request; name: string): string` | Captured value of path param `name` (e.g. `:id`), or `""`. |
| `hasParam` | `proc(req: Request; name: string): bool` | Whether param `name` was captured (distinguishes empty from absent). |
| `wildcard` | `proc(req: Request): string` | The remainder captured by a trailing `*` (e.g. `/static/*` on `/static/js/app.js` → `js/app.js`). |
| `proceed` | `proc(nxt: Chain; req: Request): Response` | From a middleware, run the rest of the chain and the matched handler — the idiomatic `next(req)`. |
| `dispatch` | `proc(r: Router; req: Request): Response` | Route one request directly (middleware included), bypassing the socket loop — handy for unit tests. |
| `toHandler` | `proc(r: Router): NimcallHandler` | Install `r` as the active router and return the `{.nimcall.}` handler that `serveConnectionNimcall` / the pool accept. |
| `serveRouter` | `proc(port: int; r: Router; maxRequests = 0)` | Run `r` on `port` over the single-threaded plaintext loop. |

Params ride as reserved pseudo-headers under a control-character prefix that a
conforming HTTP client can't inject (and spoofed copies are stripped before
dispatch), so `param` only ever returns router-populated values. Because the
`{.nimcall.}` dispatcher carries no state, the most recently installed router is
the active one — fine for the usual single-server process.

### Static files (`serve/static`)

Maps a URL path onto a file under a served root: `/` → `/index.html`, query
stripped, percent-escapes decoded, `..` → `403`, missing → `404`,
Content-Type by extension. Standard-library only.

| symbol | signature | what it does |
|---|---|---|
| `staticHandler` | `proc(root: string): Handler` | Build a `Handler` that serves static files under `root`. This is how `serve(root, port)` is expressed on the handler API. |
| `staticRoute` | `proc(root: string; req: Request): Response` | Route one request against a static `root`: validate, handle OPTIONS/HEAD/GET, `405` other methods, map path to a file. Top-level proc, reusable without nesting closures. |
| `staticResponseObj` | `proc(root: string; urlPath: string): Response` | Route a URL path to a file under `root` and return the in-memory `Response` model (status, headers, full body, plus `X-Content-Type-Options: nosniff`). |
| `staticResponse` | `proc(root: string; urlPath: string; includeBody = true): string` | Thin wrapper: serialize `staticResponseObj` to a full HTTP response string. |
| `serveFile` | `proc(root: string; urlPath: string): string` | Backwards-compatible static-GET helper (`staticResponse` with body). |
| `contentTypeFor` | `proc(path: string): string` | Pick a Content-Type from the file extension (html/js/css/json/svg/png/jpg/gif/webp/ico/wasm/pdf/woff/woff2/…; else `application/octet-stream`). |
| `normalizeUrlPath` | `proc(urlPath: string): string` | Strip query/fragment, percent-decode, force a leading slash, map `/` → `/index.html`. Does not join the filesystem root. |
| `relativePath` | `proc(urlPath: string): string` | Convert a normalized URL path into a root-relative filesystem path. |
| `endsWithSuffix` | `proc(s, suffix: string): bool` | Non-allocating "does `s` end with `suffix`?" (used by the extension match). |

### Compression (`serve/encoding`)

Opt-in: wrap a `Response` before returning it. Kept out of the core loop so
plain servers pay no CPU for compression they didn't ask for. (Named `encoding`
rather than `compress` to avoid a build-key collision with `http/compress`,
whose codecs it wraps and re-exports.)

| symbol | signature | what it does |
|---|---|---|
| `compressResponse` | `proc(req: Request; resp: Response): Response` | Return `resp` with its body compressed for the client's `Accept-Encoding` (best supported codec — br &gt; gzip), setting `Content-Encoding` + `Vary`. Unchanged when it doesn't apply: body &lt; 64 bytes, already `Content-Encoding`'d, client accepts none, or compression didn't shrink it. |
| *(re-exported)* | `pickEncoding`, `encodeFor`, `decodeFrom` | The underlying `http/contentcoding` codec picker/encoder/decoder. |

### HTTP/2 (`serve/http2`)

Opt-in `import serve/http2` so plain `serve` users don't pull the `nghttp2`
(`libnghttp2.so.14`) dependency. Speaks **h2c** (cleartext, prior-knowledge);
the same session driver runs over TLS once ALPN negotiates `"h2"` — the path
real browsers use. Handlers are `{.nimcall.}` (called from C callbacks).

| symbol | signature | what it does |
|---|---|---|
| `H2Handler` | `proc(req: Request): Response {.nimcall.}` | HTTP/2 request handler — a bare function pointer (not a closure, since it's invoked from nghttp2's C callbacks). |
| `serveHttp2` | `proc(port: int; handler: H2Handler; maxRequests = 0)` | Run an h2c (cleartext) server. Test with `curl --http2-prior-knowledge`. |
| `serveHttp2Tls` | `proc(port: int; certFile, keyFile: string; handler: H2Handler; maxRequests = 0)` | HTTP/2 over TLS, advertising ALPN `["h2", "http/1.1"]`. Connections that negotiate `"h2"` are driven by nghttp2; others are dropped (this entry point is h2-only). |
| `serveHttp2Connection` | `proc(fd: TcpHandle; handler: H2Handler)` | Drive one already-accepted h2c connection to completion. |
| `serveHttp2ConnectionTls` | `proc(tlsSock: TlsSocket; handler: H2Handler)` | Drive one HTTP/2-over-TLS connection (ALPN `"h2"` already negotiated). |

### Tuning constants (`serve/loop`)

| symbol | value | what it does |
|---|---|---|
| `MaxRequestBytes` | `8 * 1024 * 1024` | Reject requests larger than this → `413 Payload Too Large`. |
| `ReadTimeoutMillis` | `15000` | Per-socket blocking read timeout — the slowloris guard. |
| `MaxKeepAliveRequests` | `100` | Max requests served on one kept-alive connection before it's closed. |

### Re-exported `http` helpers (umbrella)

`import serve` re-exports the transport-free `http` pack (`headers`, `url`,
`request`, `response`) plus `tcp` and `tls`, so a handler needs no extra imports.
The essentials a handler touches:

| symbol | signature | what it does |
|---|---|---|
| `Request` | `object (meth, path, version: string; headers: seq[Header]; body: string)` | The parsed request handed to your handler. |
| `Response` | `object (status: int; headers: seq[Header]; body: string)` | The value your handler returns. |
| `response` | `proc(status: int; contentType, body: string): Response` | Build a `Response` with a Content-Type. |
| `withHeader` | `proc(res: var Response; name, value: string)` | Append a header. |
| `isMethod` | `proc(req: Request; meth: string): bool` | Case-checked method test (e.g. `isMethod(req, "GET")`). |
| `isValidRequest` | `proc(req: Request): bool` | Sanity-check a parsed request. |
| `headerValue` / `hasHeader` | `proc(req: Request; name): string` / `bool` | Look up a request header (also `seq[Header]` overloads). |
| `pathOnly` / `queryString` / `queryParam` / `queryParams` / `formParam` | `proc(target …): …` | URL parsing: split path from query, pull query/form params. |
| `percentDecode` / `percentEncode` / `encodeQuery` | `proc(s …): string` | Percent-coding and query-string building. |
| `HttpCode`, `code`, `is2xx`…`is5xx`, `reasonPhrase` | — | Status-code helpers. |
| `redirect` / `optionsResponse` / `httpResponse` | `proc(…): string` | Ready-made response-string builders. |
| `encodeChunked` / `decodeChunked` | `proc(body: string): string` | Chunked transfer coding (the loop de-chunks inbound bodies in place). |

## Design notes

- **One transport-independent core.** `serveConnCore` reads a complete request,
  calls the handler, and streams the response over a `ServerConn` that is either
  a raw `TcpHandle` or a `TlsSocket`. HTTP and HTTPS share the framing,
  keep-alive, HEAD, size-cap, and timeout logic byte-for-byte.
- **Complete-request framing.** The reader accumulates the header block, then
  frames the body by `Content-Length` **or** `Transfer-Encoding: chunked`. A
  chunked body is de-chunked in place, so the handler always sees a plain body.
  `Expect: 100-continue` gets an interim `100 Continue` before the body is read.
- **Streamed responses, no buffer cap.** The body is written through a stack
  chunk buffer rather than concatenating a second whole-response copy or a fixed
  1 MB buffer, so response size is unbounded.
- **Closures vs. `{.nimcall.}`.** The single-threaded loops take `.closure`
  handlers (capture state). The worker pool and HTTP/2 take bare function
  pointers: nimony's lambda lifter can't lift a closure that captures a
  proc-typed variable across threads, and C callbacks can't receive a closure —
  hence the duplicated `…Nimcall` cores and `NimcallHandler`/`H2Handler` types.
- **Hardening by default.** 8 MB request cap → `413`, 15 s slowloris read
  timeout, `..` path segments → `403`, static responses carry
  `X-Content-Type-Options: nosniff`, and keep-alive is capped at 100 requests
  per connection.
- **Routing is opt-in.** The core loop still dispatches through one
  `proc(req): Response`; `import serve/router` layers method+path routing,
  `:id`/`*` capture, and a middleware chain on top (all `{.nimcall.}`). Without
  it you dispatch on `req.path`/`req.meth` yourself, or compose with
  `staticRoute` / `compressResponse`.
- **No HTTP/3 serving.** Serving h3 needs a QUIC stack, and none is installed;
  this is a hard gap, not a tuning item. (The client side already speaks h3 via
  `requests`.)

## Requirements

- **nimony toolchain** (aowl/nimony), `--threads:on` for the concurrent pool.
- **Dependency repos:** `aoughwl/http` (request/response/url/headers/compress
  helpers), `aoughwl/tcp` + `aoughwl/net` (transport), `aoughwl/tls`
  (OpenSSL 3, for HTTPS and ALPN).
- **C libraries it FFIs to (transitively / opt-in):** OpenSSL 3 (`libssl` /
  `libcrypto`, via `tls`) for HTTPS; **`libnghttp2.so.14`** for `serve/http2`
  (structs are hand-laid to the C ABI — no nghttp2 headers required).
