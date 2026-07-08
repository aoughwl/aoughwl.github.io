---
title: tls
parent: net stack
grand_parent: Projects
nav_order: 3
---

# tls — TLS 1.3 over OpenSSL 3
{: .no_toc }

[Repo → aoughwl/tls](https://github.com/aoughwl/tls){: .btn }

TLS/SSL for the stack, **client and server**, over OpenSSL 3. Wraps a connected
`net.Socket` into a `TlsSocket`; status-based (`TlsStatus`), no exceptions,
caller-owned buffers. Its own repo (`tls → net → tcp`) so `serve`, `ws`, and
future clients can take TLS without the rest of `net`, and `net` stays free of an
OpenSSL dependency.

```nim
import net, tls
var ctx = newTlsClientContext(verify = true)
var c = connectTls(ctx, "example.com", 443)      # resolve + connect + handshake
echo c.protocolVersion(), " / ", c.cipherName()  # TLSv1.3 / TLS_AES_256_GCM_SHA384
```

| Capability | Detail |
|---|---|
| Client context | SNI, hostname verification (`SSL_set1_host`), system trust store, cipher list/suites, min/max version |
| Server context | `newTlsServerContext(cert, key)`, `setAlpnServer` — **real** ALPN negotiation via `alpn_select_cb` |
| Handshake | `wrapClient` / `wrapServer` / `connectTls`; resumable — blocking *or* non-blocking, surfacing `tlsWantRead` / `tlsWantWrite` |
| I/O | `tlsReadInto` / `tlsWriteFrom`, plus `recv` / `readAll` / `send` / `sendAll` |
| Introspection | `protocolVersion`, `cipherName`, `negotiatedAlpn`, `verifyOk` |

The ALPN split matters: `setAlpnProtocols` *advertises* (client role), while
`setAlpnServer` registers the server selection callback — that is what lets an
HTTPS server negotiate `h2`. Browser-fingerprint client TLS is out of scope; that
lives in [`requests`](requests) via curl-impersonate's BoringSSL.
