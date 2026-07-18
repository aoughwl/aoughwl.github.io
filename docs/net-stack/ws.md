---
repo: aoughwl/ws
---

# ws — RFC 6455 WebSockets for nimony, server and client

A pure-nimony WebSocket implementation (RFC 6455): both roles, over plaintext
(`ws://`, a `net.Socket`) or TLS (`wss://`, a `tls.TlsSocket`). It sits directly
above the aoughwl `net`/`tls` sockets and reuses `http`'s request parser for the
Upgrade handshake. No framework runtime and no exceptions — status-based returns
and caller-owned buffers throughout.

> **Status** — Production-ready for text/binary messaging both ways. Framing, fragment reassembly, auto-pong, and the close handshake all work, verified against the RFC 6455 accept-key vector and a live `wss://` echo round-trip. The `permessage-deflate` extension (RFC 7692) is not negotiated and there is no Autobahn suite run yet.

## Quickstart

```nim
import ws

# --- server: upgrade an already-accepted socket and echo every message ---
var conn = acceptWebSocket(sock)          # reads the Upgrade request, sends 101
if conn.open:
  var msg: WsMessage
  while conn.receive(msg):
    if msg.opcode == opClose: break
    discard conn.sendText("echo: " & msg.data)

# --- client over TLS (wss://) ---
var c = newClientWebSocketTls(tlsSock, "example.com", "/chat")
if c.open:
  discard c.sendText("hello")
  var reply: WsMessage
  if c.receive(reply):
    echo reply.data
  discard c.sendClose(1000, "bye")
  c.close()
```

## API

`import ws` re-exports `ws/frame`, so `Opcode`, `isControl`, and `encodeFrame`
are available alongside the connection API. The handshake primitives live in
`ws/handshake` and are used internally; import that module directly if you need
to drive the HTTP Upgrade yourself.

### Types

| symbol | signature | what it does |
|---|---|---|
| `WsRole` | `enum wsServer, wsClient` | Connection role. Decides masking: a client masks every frame it sends, a server never masks. |
| `WebSocket` | `object role*: WsRole; open*: bool` | An open connection over either transport. `open` is `false` after a failed handshake, EOF, protocol error, or `sendClose`/`close`. Other fields (transport, RNG) are private. |
| `WsMessage` | `object opcode*: Opcode; data*: string` | A fully-reassembled application message (all fragments joined). `opcode` is `opText`, `opBinary`, or `opClose` (a close frame is delivered once). |
| `Opcode` | `enum opContinuation=0x0, opText=0x1, opBinary=0x2, opClose=0x8, opPing=0x9, opPong=0xA` | RFC 6455 frame opcode. *(from `ws/frame`)* |

### Server handshake

| symbol | signature | what it does |
|---|---|---|
| `acceptWebSocket` | `proc (sock: Socket): WebSocket` | Turnkey server: read the HTTP Upgrade request straight off `sock`, parse it, and complete the handshake. `open == false` if it is not a valid Upgrade. |
| `newServerWebSocket` | `proc (sock: Socket; req: Request): WebSocket` | Complete the server handshake over a plaintext socket given an already-parsed `Request`: validate the Upgrade, send `101 Switching Protocols`, return an open server-role socket. Non-upgrade request &rarr; `open == false`. |
| `newServerWebSocketTls` | `proc (t: TlsSocket; req: Request): WebSocket` | `newServerWebSocket` over TLS (`wss://`). |

### Client handshake

| symbol | signature | what it does |
|---|---|---|
| `newClientWebSocket` | `proc (sock: Socket; host: string; path = "/"): WebSocket` | Perform the client handshake over an already-connected plaintext socket. Sends a 16-byte nonce key and verifies `Sec-WebSocket-Accept`. `open == false` if rejected. |
| `newClientWebSocketTls` | `proc (t: TlsSocket; host: string; path = "/"): WebSocket` | `newClientWebSocket` over TLS (`wss://`). |

### Sending

| symbol | signature | what it does |
|---|---|---|
| `sendText` | `proc (ws: var WebSocket; s: string): bool` | Send a complete text message in one frame. `false` if the socket is not open. |
| `sendBinary` | `proc (ws: var WebSocket; s: string): bool` | Send a complete binary message in one frame. |
| `ping` | `proc (ws: var WebSocket; payload = ""): bool` | Send a ping control frame with optional payload. |
| `pong` | `proc (ws: var WebSocket; payload = ""): bool` | Send a pong control frame (unsolicited; inbound pings are auto-answered by `receive`). |
| `sendClose` | `proc (ws: var WebSocket; code = 1000; reason = ""): bool` | Send a close frame (2-byte big-endian status code + optional UTF-8 reason) and mark `open = false`. |
| `close` | `proc (ws: var WebSocket)` | Close the underlying transport (call after an optional `sendClose`). Sets `open = false`. |

### Receiving

| symbol | signature | what it does |
|---|---|---|
| `receive` | `proc (ws: var WebSocket; msg: var WsMessage): bool` | Read the next application message, reassembling continuation fragments. Inbound pings are answered with a pong automatically; a close frame is echoed, delivered once as `msg` (opcode `opClose`), and closes the socket. Returns `false` at EOF, protocol error, or after close. |

### Frame codec (`ws/frame`)

| symbol | signature | what it does |
|---|---|---|
| `isControl` | `proc (op: Opcode): bool` | True for control opcodes (close/ping/pong, `ord >= 0x8`) — which must be &le; 125 bytes and never fragmented. |
| `encodeFrame` | `proc (op: Opcode; payload: string; fin: bool; masked: bool; maskKey: array[4, uint8]): string` | Serialize one frame: FIN+opcode byte, MASK+length (7/16/64-bit big-endian), optional mask key, payload (XOR-masked when `masked`). |

### Handshake primitives (`ws/handshake`)

Used internally by the constructors; import `ws/handshake` directly only if you
are wiring the HTTP Upgrade yourself.

| symbol | signature | what it does |
|---|---|---|
| `acceptKey` | `proc (clientKey: string): string` | `base64(SHA1(clientKey & GUID))` — the value a server echoes in `Sec-WebSocket-Accept`. |
| `isWebSocketUpgrade` | `proc (req: Request): bool` | True when `req` carries `Upgrade: websocket` + `Connection: Upgrade` + a non-empty `Sec-WebSocket-Key`. |
| `websocketKey` | `proc (req: Request): string` | The request's `Sec-WebSocket-Key` header value. |
| `serverHandshakeResponse` | `proc (clientKey: string): string` | The full `101 Switching Protocols` response completing the server handshake. |
| `clientHandshakeRequest` | `proc (host: string; path: string; key: string): string` | Build the client's `GET` Upgrade request (`Sec-WebSocket-Version: 13`). |
| `clientHandshakeValid` | `proc (responseHeaders: string; sentKey: string): bool` | Verify a server's raw handshake response carries `101` and the expected accept value for `sentKey`. |

## Design notes

- **One socket abstraction.** A private `WsTransport` dispatches reads/writes to
  a plaintext `Socket` or a `TlsSocket`, so `ws://` and `wss://` share every byte
  of the protocol code — a single `WebSocket` type covers both.
- **Role decides masking.** A client masks every frame with a fresh key; a server
  never masks. `receive` unmasks inbound client frames transparently.
- **Blocking, exact reads.** Frames are read with a `readExactly` loop so a frame
  never bleeds into the next; the header-block reader stops at CRLFCRLF so the
  handshake never swallows following frame bytes. Set a socket read timeout via
  `net` for idle / ping-timeout handling.
- **Masking is not cryptographic.** Keys come from `std/random` seeded per
  connection — masking need only be well-formed for the peer to unmask, not
  unpredictable.

## Requirements

- Nimony toolchain.
- [`net`](https://github.com/aoughwl/net) — plaintext `Socket`, plus its `tls`
  module (`TlsSocket`, OpenSSL 3) for `wss://`.
- [`http`](https://github.com/aoughwl/http) — `Request` parsing and headers for
  the Upgrade handshake.
- nimony stdlib: `std/random`, `std/base64`, `std/sha1`.
