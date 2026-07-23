---
title: "A net-stack overhaul, a JSON library, and MCP — in one push"
date: 2026-07-23
---

# A net-stack overhaul, a JSON library, and MCP

*July 23, 2026*

The last stretch of work touched three layers of the stack at once — the
networking foundation, a small library we pulled out of it, and a brand-new
server framework on top. Here's what changed and why.

## The net stack grew an async spine

Until now the [net stack](/docs/net-stack) served connections with a blocking
worker pool — one thread per connection. That's fine at low concurrency and
awful at high. So we built a **single-threaded async reactor**: one OS thread,
`epoll`, and Nimony's own passive-proc coroutines. No `std` async, no thread
pool — everything cooperatively multiplexed on one thread. See
[the reactor page](/docs/net-stack/reactor) for the model.

On that spine we brought up four servers, each proven on **one thread**:

- **HTTP/1.1** — keep-alive + chunked, 300/300 across 60 simultaneous
  connections.
- **WebSocket** — and not a toy one. The async WebSocket path is
  **Autobahn-grade**: masked-frame enforcement, RSV/reserved-opcode/control-frame
  rules, a fragmentation state machine, *incremental* UTF-8 validation across
  fragment boundaries (Höhrmann DFA), close-code validation and echo, and
  permessage-deflate. 19/19 conformance cases plus 160/160 echo.
- **HTTP/3 over QUIC** — a *real* one. QUIC needs TLS 1.3 with a QUIC-aware
  handshake, which the system OpenSSL couldn't provide, so we built a small C
  glue shim over **ngtcp2 + nghttp3 + GnuTLS**, exposed it to Nimony through a
  tiny pull-based API, and let the reactor own only the `epoll` wait on the UDP
  socket. 20 independent QUIC clients answered on one thread; the C core is
  ASan/LSan-clean.
- **QUIC datagrams and WebTransport** — RFC 9221 unreliable datagrams, then full
  **WebTransport** on top: extended CONNECT establishes a session, and WT
  datagrams ride the H3-datagram framing over the QUIC datagram layer. Session +
  datagram round-trip, end to end.

The blocking worker-pool servers are still there for thread-per-connection work;
the reactor is the high-concurrency alternative.

## JSON moved into its own library

The MCP work needed a JSON value type that Nimony's `std/json` (root-only,
move-only) couldn't be. So we wrote one — and then, rather than bury it inside
the MCP server, pulled it out into a standalone repo:
[**aowljson**](/docs/aowljson). Error-as-value parsing, a compact serializer,
safe navigation (`v{"key"}`, `v.at(i)`), and builders. One concern, one repo —
the same philosophy the net stack follows.

## aowlmcp: an MCP server framework in Nimony

The headline is a new project: [**aowlmcp**](/docs/aowlmcp), a
[Model Context Protocol](https://modelcontextprotocol.io) server library written
in Nimony. Protocol dispatch is transport-agnostic — one `handleMessage` turns a
JSON-RPC message into a reply — so the same server and the same registered tools
run under **three transports**:

- **stdio** — line-delimited JSON-RPC, for local clients (Claude Code, editors),
  no networking dependency at all.
- **HTTP** — the modern Streamable-HTTP transport, blocking or on the async
  reactor.
- **HTTP/3 (QUIC)** — the same contract carried over QUIC, on the net stack's
  single-thread H3 reactor.

Every transport is verified end to end: stdio 13/13, HTTP 6/6, HTTP/3 4/4
(initialize + tools/list + tools/call over QUIC, one thread). It ships with a
real toolchain server too — compile-to-diagnostics and NIF outline — wired into
the [aowlcode](/docs/aowlcode) plugin.

## Why it hangs together

Every one of these is the same move: **own the seam, FFI the hard native piece,
keep one concern per repo.** TLS wraps OpenSSL, compression wraps zlib, QUIC
wraps ngtcp2 — all behind small, status-based (no-exceptions) Nimony APIs. The
async servers all share the reactor; all three MCP transports share one
`handleMessage`. Nothing is a fork of someone else's runtime; it's a ground-up
stack that happens to speak the same protocols.

Ten end-to-end suites are green as of today. The one remaining frontier is
WebTransport *streams* (datagrams already work); everything else on this list is
done and proven.
