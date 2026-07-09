---
title: ws
parent: net stack
grand_parent: Nimony Libraries
nav_order: 7
---

# ws — WebSocket (RFC 6455)
{: .no_toc }

[Repo → aoughwl/ws](https://github.com/aoughwl/ws){: .btn }

A pure-nimony WebSocket, **server and client**, over plaintext (`ws://`, a
`net.Socket`) or TLS (`wss://`, a `tls.TlsSocket`) — one `WebSocket` type over
either transport.

```nim
import ws
var conn = acceptWebSocket(sock)         # server: reads Upgrade, sends 101
var msg: WsMessage
while conn.receive(msg):
  if msg.opcode == opClose: break
  discard conn.sendText("echo: " & msg.data)
```

| Capability | Detail |
|---|---|
| Handshake | server validates `Upgrade`/`Sec-WebSocket-Key` → `101`; client sends a 16-byte nonce and verifies `base64(SHA1(key‖GUID))` (checked against the RFC test vector) |
| Framing | FIN + opcode, 7/16/64-bit lengths, per-role masking (client masks, server never does) |
| Messages | `sendText` / `sendBinary`; `receive` reassembles continuation fragments |
| Control | `ping` / `pong` (auto-pong on inbound ping), `sendClose(code, reason)` + echo |
| Transport | `ws://` and `wss://` via the same API (`newClientWebSocketTls` for TLS) |

One private `WsTransport` dispatches to a plaintext `Socket` or a `TlsSocket`, so
`ws://` and `wss://` share every byte of the protocol. Verified against the RFC
6455 accept-key vector and a live public `wss://` echo server.
