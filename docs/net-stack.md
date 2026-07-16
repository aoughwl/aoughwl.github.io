---
title: net stack
grand_parent: Documentation
parent: Builtin Libraries
nav_order: 1
has_children: true
---

# The net stack
{: .no_toc }

A Nimony-native networking stack, one concern per repo, layered `tcp → net →
tls → serve` with transport-free `http`/`compress` helpers and `ws` / `requests`
alongside. Common stance throughout: nimony-native, no framework runtime,
**status-based errors instead of exceptions**, blocking I/O by default with a
non-blocking escape hatch on every handle. **TLS 1.3**, **dual-stack IPv6**, a
**concurrent worker pool**, **HTTP/2**, **WebSocket**, and **HTTP/3** (client)
are all first-class.

---

## How it layers

```
requests   (HTTP client — curl-impersonate; HTTP/2 + HTTP/3, browser-identical)

ws         (WebSocket, RFC 6455 — ws:// and wss://, server + client)

serve      (HTTP/1.1 + HTTP/2 server; HTTPS; concurrent pool; compression)  ┐
  ├── http (transport-free: headers, URL/form, parsing, status)             │
  ├── compress (gzip / brotli / zstd codecs)                                │  consumed
  ├── tls  (TLS 1.3 over OpenSSL 3 — client + server)   ┐                    │  by serve
  └── net  (Socket / dual-stack IPv6 / dial)           │ tls wraps a Socket  │
        └── tcp (native sockets: IPv4 + IPv6)          ┘                     ┘
```

`http` and `compress` are deliberately **out** of the transport chain — no
sockets — so any transport can reuse them. `tls` sits beside `net` (it wraps a
`net.Socket`), and `serve` / `ws` build on both.

---

## Libraries

| Library | What it is | Repo |
|---|---|---|
| [tcp](net-stack/tcp) | Native blocking sockets, IPv4 + IPv6, raw handles | [aoughwl/tcp](https://github.com/aoughwl/tcp) |
| [net](net-stack/net) | `Socket` ergonomics, dual-stack `dial`/`listen6`, buffered reads | [aoughwl/net](https://github.com/aoughwl/net) |
| [tls](net-stack/tls) | TLS 1.3 over OpenSSL 3 — client + server, ALPN | [aoughwl/tls](https://github.com/aoughwl/tls) |
| [http](net-stack/http) | Transport-free HTTP: headers, URL/form, parsing, status | [aoughwl/http](https://github.com/aoughwl/http) |
| [compress](net-stack/compress) | gzip / brotli / zstd codecs | [aoughwl/compress](https://github.com/aoughwl/compress) |
| [serve](net-stack/serve) | HTTP/1.1 + HTTP/2 server, HTTPS, concurrency | [aoughwl/serve](https://github.com/aoughwl/serve) |
| [ws](net-stack/ws) | WebSocket (RFC 6455), server + client, ws:// + wss:// | [aoughwl/ws](https://github.com/aoughwl/ws) |
| [requests](net-stack/requests) | Browser-identical HTTP client (curl-impersonate) | [aoughwl/requests](https://github.com/aoughwl/requests) |

Verbatim API symbol tables for the older libraries are archived under
**Reference**: [tcp](reference/tcp) · [net](reference/net) · [http](reference/http) ·
[serve](reference/serve) · [requests](reference/requests).
