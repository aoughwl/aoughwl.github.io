---
title: serve
parent: net stack
grand_parent: Libraries
nav_order: 6
---

# serve — HTTP/1.1 + HTTP/2 server
{: .no_toc }

[Repo → aoughwl/serve](https://github.com/aoughwl/serve){: .btn }
[Reference](../reference/serve){: .btn }

The top of the stack. Pass a handler `proc(req: Request): Response {.closure.}`
and return whatever `Response` you like, or drop in `staticHandler(root)`. A
`ServerConn` transport shim makes the request-read / response-write core
transport-independent, so HTTP and HTTPS share it byte-for-byte.

```nim
import serve
proc hello(req: Request): Response {.closure.} =
  response(200, "text/plain", "hi " & req.path & "\n")
serve(8080, hello)                       # HTTP/1.1
serveTls(8443, "cert.pem", "key.pem", hello)   # HTTPS
```

| Capability | Behavior |
|---|---|
| Programmable / static | `serve(port, handler)`; `serve(root, port)` static files |
| HTTPS | `serveTls(port, cert, key, handler)` — one TLS session per connection |
| Concurrency | `serveConcurrent` / `serveTlsConcurrent` — a pool of worker threads all `accept()` one shared socket |
| HTTP/2 | `import serve/http2`: `serveHttp2` (h2c) and `serveHttp2Tls` (ALPN "h2", the browser path) over nghttp2 |
| Request framing | `Content-Length` **and** `Transfer-Encoding: chunked` (de-chunked in place) |
| `Expect: 100-continue` | interim `100 Continue` before the body is read |
| Compression | opt-in `compressResponse(req, resp)` (`serve/encoding`) — negotiates `Accept-Encoding`, gzip/br-encodes |
| Hardening | 8 MB request cap → `413`, 15 s slowloris read timeout, keep-alive, HEAD, `..` → `403` |

The concurrent pool and HTTP/2 use `{.nimcall.}` handlers (`NimcallHandler`) rather
than closures — a bare function pointer crosses thread and C-callback boundaries
where a captured closure does not. HTTP/3 *serving* would need a QUIC stack (none
installed); the [`requests`](requests) client already speaks HTTP/3.
