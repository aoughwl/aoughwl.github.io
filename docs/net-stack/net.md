---
title: net
parent: net stack
grand_parent: Libraries
nav_order: 2
---

# net — sockets with ergonomics
{: .no_toc }

[Repo → aoughwl/net](https://github.com/aoughwl/net){: .btn }
[Reference](../reference/net){: .btn }

The middle layer over `tcp`: a `Socket` value with an `Ipv4Address`/`Endpoint`
model, string-convenience I/O, a buffered line reader, and family-agnostic
connect helpers.

| Capability | Detail |
|---|---|
| Socket model | `Socket`, `Ipv4Address`, `Endpoint`, `$` formatting |
| Family-agnostic connect | `dial` and `connectHost` follow **AAAA and A** records (via `connectHostTcp`) |
| Dual-stack listen | `listen6(port, dualStack = true)` — one listener for IPv4 + IPv6 |
| Buffered reads | `BufferedSocket` with `recvLine` / `readAll` (no over-read past the terminator) |
| Uncapped reads | `recv(sock, maxBytes)` loops to `maxBytes`/EOF — no hidden 8192 cap |
| Timeouts / non-blocking | read/write timeouts, `setNonBlocking`, `poll`, `finishConnect` |

*Versus `std/net`:* the same ergonomics without the exception model — the same
status-code + `NetErrorKind` model as `tcp`, re-exposed under `net*` names. TLS is
**not** here — it lives in the separate [`tls`](tls) layer, so plain-socket users
carry no OpenSSL dependency.
