---
title: requests
parent: net stack
grand_parent: Builtin Libraries
nav_order: 8
---

# requests — browser-identical HTTP client
{: .no_toc }

[Repo → aoughwl/requests](https://github.com/aoughwl/requests){: .btn }
[Reference](../reference/requests){: .btn }

An HTTP client that hands the entire TLS/JA3/JA4/HTTP-2 fingerprint off to
[curl-impersonate](https://github.com/lwthiker/curl-impersonate) — so requests are
byte-indistinguishable from a real browser at the network layer — then puts that
whole machine (headers, cookies, proxies, TLS, DNS, redirects, retries, timing)
under programmatic control.

```nim
import requests
let s = newSession("chrome136", proxy = "socks5h://user:pass@host:1080")
let r = s.get("https://example.com")
echo r.status, " HTTP/", r.httpVersion, " ", r.body.len, "b"
```

| Area | Control |
|---|---|
| Fingerprint | 7 impersonation profiles; browser-exact ClientHello + HTTP/2 SETTINGS |
| **HTTP/2 + HTTP/3** | `useHttp3` / `useHttp3Only` (curl-impersonate's bundled ngtcp2 speaks real h3) |
| Headers | verbatim ordered headers, strip/override, multi-value reads |
| Cookies | in-memory + file-backed jar, `CURLSH` share across sessions |
| Proxy | http/https/socks4/4a/5/5h + `ProxyPool` rotation |
| TLS / DNS | cipher/version/mTLS overrides, `pinHost` (RESOLVE), interface/local-port binding |
| More | streaming up/download, multipart, `fetchAll` concurrency, before/after hooks, opt-in retry/backoff, a coherence `audit` linter |

Where BoringSSL matters — reproducing Chrome's ClientHello — it lives *here* (inside
curl-impersonate), not in the general-purpose [`tls`](tls) layer. A pure-nimony
port over the curl-impersonate FFI lives under `nimony/`.
