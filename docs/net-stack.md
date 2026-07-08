---
title: net stack
parent: Projects
nav_order: 5
---

# The net stack — tcp · net · serve · http · requests
{: .no_toc }

A Nimony-native networking stack, layered `tcp → net → serve`, with a
transport-free `http` layer and a browser-impersonating `requests` client
alongside. Common stance throughout: nimony-native, no framework runtime,
**status-based errors instead of exceptions**, blocking I/O by default (with a
non-blocking escape hatch on every handle). **TLS 1.3** (OpenSSL 3),
**dual-stack IPv6**, and a **concurrent worker pool** are first-class — a plain
`serve` call is HTTP/1.1 over IPv4/IPv6, and `serveTls` / `serveConcurrent` add
HTTPS and parallelism over the same handler API.

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## How it layers

```
requests   (HTTP client — curl-impersonate, byte-identical to a real browser)

serve      (programmable HTTP/1.1 server)         ┐
  ├── http (transport-free: headers, URL/form, parsing, status)  │  consumes http
  └── net  (Socket / Ipv4Address / buffered reader / dial)       │  the tcp→net→serve
        └── tcp (native blocking sockets, raw handles)           ┘  transport chain
```

`http` is deliberately kept **out** of the transport chain — no socket loop, no
dependency on the socket substrate — so the same HTTP layer can back any transport.

---

## `tcp` — native blocking sockets
[Repo → aoughwl/tcp](https://github.com/aoughwl/tcp){: .btn }

The bottom layer. Binds directly to the platform socket API (POSIX / Winsock) with
no C shim, hands you raw `TcpHandle`s and caller-owned buffers, and reports
failures as status codes + a classified `TcpErrorKind`. Blocking is the default;
nonblocking connect, `pollTcp` readiness, and per-operation timeouts layer onto the
same handle. `formatIpv4` / `parseIpv4Text` / `resolveTcp4` cover IPv4 addressing;
`connectHostTcp` is **family-agnostic** (a `getaddrinfo` sweep that connects to the
first address that accepts, IPv4 *or* IPv6), and `listenTcp6` binds a **dual-stack**
IPv6 listener that also accepts IPv4-mapped connections on one socket.

*Versus `std/nativesockets`:* no `OSError`, no `getAddrInfo`/`Sockaddr` unions, no
stdlib-grown buffers — every call returns a status/count; the library never
allocates on your behalf.

## `net` — sockets with ergonomics
[Repo → aoughwl/net](https://github.com/aoughwl/net){: .btn }

The middle layer over `tcp`: a `Socket` value with an `Ipv4Address`/`Endpoint`
model, string-convenience I/O, a buffered line reader (`BufferedSocket` with
`recvLine`/`readAll`), and connect helpers (`dial` and `connectHost` are now
family-agnostic — they follow AAAA and A records — and `listen6` binds a
dual-stack IPv6 server). `recv(sock, maxBytes)` loops to `maxBytes`/EOF with no
hidden 8192 cap.

**TLS/SSL** lives here too, in `net/tls` over OpenSSL 3: a `TlsContext` (client
with SNI + hostname verification + ALPN + cipher/version control, or server with a
PEM cert chain + key) wraps a connected `Socket` into a `TlsSocket`. The handshake
is resumable (blocking or non-blocking, surfacing `tlsWantRead`/`tlsWantWrite`), and
`connectTls(ctx, host, port)` does resolve + connect + client handshake in one call.
It negotiates TLS 1.3 against real servers and reports the version, cipher, ALPN,
and verification result.

*Versus `std/net`:* the same ergonomics without the exception model — same
status-code + `NetErrorKind` model as `tcp`, re-exposed under `net*` names — plus a
TLS layer whose handshake you can drive from a poll loop.

## `serve` — programmable HTTP/1.1 server
[Repo → aoughwl/serve](https://github.com/aoughwl/serve){: .btn }

The top of the stack. Pairs transport-free `http` (consumed and re-exported) with
the `tcp` transport (also re-exported) to run a real programmable server: pass a
handler `proc(req: Request): Response {.closure.}` and return whatever `Response`
you like, or drop in the built-in `staticHandler(root)`. A `ServerConn` transport
shim makes the request-read / response-write core transport-independent, so plain
HTTP and HTTPS share it byte-for-byte.

| Capability | Behavior |
|---|---|
| Programmable handler | `serve(port, handler)` — the handler's `Response` returned verbatim |
| HTTPS | `serveTls(port, cert, key, handler)` — one TLS session per connection over `net/tls`, same handler API |
| Concurrency | `serveConcurrent` / `serveTlsConcurrent` — a bounded pool of worker threads all `accept()` on one shared socket |
| Static files | `GET`/`HEAD`/`OPTIONS`, `/`→`/index.html`, MIME by extension |
| Request framing | `Content-Length` **and** `Transfer-Encoding: chunked` (de-chunked in place) |
| `Expect: 100-continue` | interim `100 Continue` sent before the body is read |
| Request cap | over `MaxRequestBytes` (8 MB) → `413` |
| Streamed responses | header then body streamed, no truncation, any size |
| Keep-alive | multiple requests per socket, correct `Connection` headers |
| Slowloris guard | per-socket `ReadTimeoutMillis` (15 s) |
| Path safety | percent-decode, strip query/fragment, reject `..` → `403` |

The concurrent pool uses `{.nimcall.}` handlers (`NimcallHandler`) rather than
closures, since a bare function pointer crosses thread boundaries where a captured
closure does not. HTTP/3 serving would need a QUIC stack (absent here); the
`requests` client already speaks HTTP/2 and HTTP/3 via curl-impersonate.

## `http` — transport-free HTTP
[Repo → aoughwl/http](https://github.com/aoughwl/http){: .btn }

Headers, URL/query/form codecs, request parsing, typed methods and status codes,
response building, and a chunked-transfer codec — with no socket loop. `Header` is
a plain value (case-insensitive, total); `HttpCode` is a `distinct int` with
`is1xx`..`is5xx` and a full RFC reason table; `parseRequest` is a pure
string→`Request` parse. Consolidates what Nim 2 splits across `std/httpcore` and
`std/uri`.

## `requests` — undetectable HTTP client
[Repo → aoughwl/requests](https://github.com/aoughwl/requests){: .btn }

An HTTP client that hands the entire TLS/JA3/JA4/HTTP-2 fingerprint off to
[curl-impersonate](https://github.com/lwthiker/curl-impersonate) — so requests are
byte-indistinguishable from a real browser at the network layer — then puts that
whole machine (headers, cookies, proxies, TLS, DNS, redirects, retries, timing)
under programmatic control.

```nim
import requests

let s = newSession("chrome136", proxy = "socks5h://user:pass@host:1080")
let r = s.get("https://example.com")
echo r.status, " HTTP/", r.httpVersionStr, " ", r.body.len, "b"
s.close()
```

Stock `std/httpclient` (OpenSSL) has a non-browser JA3 the moment it connects.
`requests` binds to the BoringSSL-backed `libcurl-impersonate`, whose
`curl_easy_impersonate` reproduces a chosen browser's ClientHello and HTTP/2
`SETTINGS` verbatim — and the rest of the library is about not squandering that
handshake with a client-side tell (ordered headers, a coherence `audit` linter,
persistent H2-coalescing handles, file-backed cookie jars, a `Share` pool).

---

Full API symbol tables, layout, design notes, and limitations for each library are
archived verbatim under **Reference**:
[tcp](../reference/tcp) · [net](../reference/net) · [http](../reference/http) ·
[serve](../reference/serve) · [requests](../reference/requests).
