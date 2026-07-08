---
title: tcp
parent: net stack
grand_parent: Projects
nav_order: 1
---

# tcp — native blocking sockets
{: .no_toc }

[Repo → aoughwl/tcp](https://github.com/aoughwl/tcp){: .btn }
[Reference](../reference/tcp){: .btn }

The bottom layer. Binds directly to the platform socket API (POSIX / Winsock)
with no C shim, hands you raw `TcpHandle`s and caller-owned buffers, and reports
failures as status codes + a classified `TcpErrorKind`. Blocking is the default;
non-blocking connect, `pollTcp` readiness, and per-operation timeouts layer onto
the same handle.

| Capability | Detail |
|---|---|
| Addressing | `formatIpv4` / `parseIpv4Text` / `resolveTcp4` (IPv4) |
| Family-agnostic connect | `connectHostTcp(host, port)` — a `getaddrinfo` sweep that connects to the first address that accepts, **IPv4 or IPv6** |
| Dual-stack listen | `listenTcp6` binds an IPv6 wildcard listener that also accepts IPv4-mapped connections on one socket |
| Socket options | reuseaddr/port, keepalive, nodelay, linger, rcv/snd buffers, generic get/set |
| Non-blocking | non-blocking connect, `pollTcp`, `waitReadable`/`waitWritable`, per-op timeouts |
| SIGPIPE-safe | writes use `MSG_NOSIGNAL` so a broken pipe returns `EPIPE`, not a signal |

*Versus `std/nativesockets`:* no `OSError`, no `Sockaddr` unions, no stdlib-grown
buffers — every call returns a status/count; the library never allocates for you.
The `connectHostTcp` / `listenTcp6` pair is the family-agnostic core the rest of
the stack rides on.
