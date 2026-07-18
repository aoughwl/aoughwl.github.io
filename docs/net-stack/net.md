---
repo: aoughwl/net
---

# net — stdlib-style ergonomic sockets

The middle layer of the `tcp → net → serve` stack. `net` is a thin, blocking,
stdlib-shaped wrapper over `tcp`: it boxes raw handles in a `Socket` value, adds an
`Ipv4Address`/`Ipv6Address`/`Endpoint` addressing model, string-convenience I/O, and a
buffered line reader. Depends on `tcp`. Status-based errors, no exceptions.

> **Status** — Production-ready. Blocking I/O with a full non-blocking escape hatch (poll, per-op timeouts, non-blocking connect), family-agnostic `connectHost`/`dial` and dual-stack `listen6` all shipped. The IPv6 addressing gap is now closed: an `Ipv6Address` type (`$`/`parseIpv6`, RFC 5952) and a family-carrying `Endpoint` mean `localEndpoint`/`peerEndpoint` of a v6 socket return the real address — `$` renders `"[::1]:8080"` for v6 and `"127.0.0.1:8080"` for v4. The IPv4 API is unchanged. TLS was extracted into its own `tls` repo, which simply wraps a `net.Socket`.

## Quickstart

```nim
import net

initNet()

let r = dial("example.com", 80)
if r.status == socketConnectConnected:
  var sock = r.socket
  discard sock.sendAll("GET / HTTP/1.0\r\nHost: example.com\r\n\r\n")

  var reader = newBufferedSocket(sock)
  let status = reader.recvLine()          # "HTTP/1.0 200 OK"
  while true:
    let line = reader.recvLine()
    if line.len == 0: break                # blank line ends the headers
  let body = reader.readAll()             # drain the rest to EOF
  echo "got ", body.len, " bytes"

  sock.close()

shutdownNet()
```

## API

### Addressing types

| symbol | signature | what it does |
|---|---|---|
| `Ipv4Address` | `object` with `value*: uint32` | Host-order IPv4 address. |
| `Ipv6Address` | `object` with `bytes*: array[16, byte]` | A 128-bit IPv6 address (network-order bytes). |
| `AddressFamily` | `enum` | `familyV4` / `familyV6` — which address an `Endpoint` carries. |
| `Endpoint` | `object` with `family*: AddressFamily`, `address*: Ipv4Address`, `v6*: Ipv6Address`, `port*: int` | An address+port pair; `family` selects `address` (v4, default) or `v6`. The v4 fast path is unchanged. |
| `ipv4` | `proc ipv4(a, b, c, d: int): Ipv4Address` | Build an address from octets; any octet out of `0..255` yields the all-zero address. |
| `anyIpv4` | `proc anyIpv4(): Ipv4Address` | The wildcard `0.0.0.0`. |
| `localhostIpv4` | `proc localhostIpv4(): Ipv4Address` | `127.0.0.1`. |
| `ipv4Value` | `proc ipv4Value(ip: Ipv4Address): uint32` | Extract the raw host-order `uint32`. |
| `formatIpv4` | `proc formatIpv4(ip: Ipv4Address): string` | Dotted-decimal text `"a.b.c.d"`. Inverse of `parseIpv4`. |
| `ipv6FromBytes` | `proc ipv6FromBytes(b: array[16, byte]): Ipv6Address` | Wrap 16 network-order bytes as an `Ipv6Address`. |
| `anyIpv6` | `proc anyIpv6(): Ipv6Address` | The unspecified address `::`. |
| `localhostIpv6` | `proc localhostIpv6(): Ipv6Address` | The loopback address `::1`. |
| `ipv6Bytes` | `proc ipv6Bytes(ip: Ipv6Address): array[16, byte]` | Extract the raw 16 bytes. |
| `formatIpv6` | `proc formatIpv6(ip: Ipv6Address): string` | RFC 5952 canonical text (delegates to `tcp`). |
| `` `$` `` | ``proc `$`(ip: Ipv4Address): string`` | Dotted-decimal string form. |
| `` `$` `` | ``proc `$`(ip: Ipv6Address): string`` | RFC 5952 canonical text, e.g. `"::1"`. |
| `` `$` `` | ``proc `$`(endpoint: Endpoint): string`` | `"a.b.c.d:port"` for v4, bracketed `"[::1]:port"` for v6. |
| `parseIpv4` | `proc parseIpv4(s: string; dest: var Ipv4Address): bool` | Parse dotted-decimal text; `false` on malformed input. |
| `parseIpv6` | `proc parseIpv6(s: string; dest: var Ipv6Address): bool` | Parse IPv6 text (full / `::`-compressed / v4-mapped tail); `false` on malformed input. |
| `isIpv6` | `proc isIpv6(endpoint: Endpoint): bool` | True when the endpoint carries an IPv6 address. |
| `invalidEndpoint` | `proc invalidEndpoint(): Endpoint` | Sentinel endpoint with `port == -1`. |
| `isValid` | `proc isValid(endpoint: Endpoint): bool` | True when `port >= 0`. |

### Socket types

| symbol | signature | what it does |
|---|---|---|
| `Socket` | `object` with `handle*: TcpHandle` | A boxed TCP handle — the core value type. |
| `invalidSocket` | `proc invalidSocket(): Socket` | Sentinel invalid socket. |
| `isValid` | `proc isValid(s: Socket): bool` | Whether the socket wraps a live handle. |
| `SocketConnectStatus` | `enum` | `socketConnectFailed` / `socketConnectInProgress` / `socketConnectConnected`. |
| `SocketConnectResult` | `object` with `socket*: Socket`, `status*: SocketConnectStatus`, `errorCode*: int` | Returned by the non-blocking / timeout / `dial` connect paths. |
| `SocketPollRequest` | `object` with `read*: bool`, `write*: bool` | Which readiness events to wait for. |
| `SocketPollResult` | `object` with `read*`, `write*`, `error*`, `hangup*`, `invalid*: bool` | Readiness flags returned by `poll`. |
| `BufferedSocket` | `object` with `socket*: Socket` (+ private buffer/pos) | Buffered line-oriented reader over a `Socket`. |

### Lifecycle & errors

| symbol | signature | what it does |
|---|---|---|
| `initNet` | `proc initNet()` | Initialize the network subsystem (delegates to `initTcp`; needed on Windows). |
| `shutdownNet` | `proc shutdownNet()` | Tear down the subsystem. |
| `lastNetErrorCode` | `proc lastNetErrorCode(): int` | Last platform socket error code for this thread. |
| `lastNetErrorKind` | `proc lastNetErrorKind(): TcpErrorKind` | Classified last error. |
| `classifyNetErrorCode` | `proc classifyNetErrorCode(code: int): TcpErrorKind` | Classify an arbitrary error code. |
| `netErrorWouldRetry` | `proc netErrorWouldRetry(code: int): bool` | Would-block / retryable (`EAGAIN`/`EWOULDBLOCK`). |
| `netErrorTimedOut` | `proc netErrorTimedOut(code: int): bool` | Timeout error. |
| `netErrorInterrupted` | `proc netErrorInterrupted(code: int): bool` | Interrupted (`EINTR`). |
| `netErrorDisconnected` | `proc netErrorDisconnected(code: int): bool` | Peer-disconnect error. |

### Listening & accepting

| symbol | signature | what it does |
|---|---|---|
| `listen` | `proc listen(port: int; backlog = 128): Socket` | Listen on `0.0.0.0:port`. |
| `listen` | `proc listen(ip: Ipv4Address; port: int; backlog = 128): Socket` | Listen bound to a specific IPv4 address. |
| `listen6` | `proc listen6(port: int; backlog = 128; dualStack = true): Socket` | IPv6 listener; with `dualStack` one socket also serves IPv4-mapped clients. |
| `accept` | `proc accept(server: Socket): Socket` | Accept the next connection (`invalidSocket()` if `server` is invalid). |
| `acceptWithPeer` | `proc acceptWithPeer(server: Socket; peer: var Endpoint): Socket` | Accept and report the peer endpoint. |

### Connecting

| symbol | signature | what it does |
|---|---|---|
| `connect` | `proc connect(hostOrderAddr: uint32; port: int): Socket` | Blocking connect to a raw host-order address. |
| `connect` | `proc connect(ip: Ipv4Address; port: int): Socket` | Blocking connect to an `Ipv4Address`. |
| `connectLocalhost` | `proc connectLocalhost(port: int): Socket` | Blocking connect to `127.0.0.1:port`. |
| `connectHost` | `proc connectHost(host: string; port: int): Socket` | Resolve `host` (A **and** AAAA) and connect to the first address that accepts. |
| `dial` | `proc dial(host: string; port: int): SocketConnectResult` | Family-agnostic connect that sweeps the full `getaddrinfo` set (happy-eyeballs-lite); on failure `errorCode` is the last connect error. |
| `resolveIpv4` | `proc resolveIpv4(host: string; dest: var Ipv4Address): bool` | Resolve a hostname to a single IPv4 address. |
| `connectNonBlocking` | `proc connectNonBlocking(hostOrderAddr: uint32; port: int): SocketConnectResult` | Non-blocking connect; complete it with `finishConnect`. |
| `connectNonBlocking` | `proc connectNonBlocking(ip: Ipv4Address; port: int): SocketConnectResult` | As above, from an `Ipv4Address`. |
| `connectLocalhostNonBlocking` | `proc connectLocalhostNonBlocking(port: int): SocketConnectResult` | Non-blocking connect to localhost. |
| `connectHostNonBlocking` | `proc connectHostNonBlocking(host: string; port: int): SocketConnectResult` | Resolve then non-blocking-connect (IPv4 path). |
| `connectTimeout` | `proc connectTimeout(hostOrderAddr: uint32; port: int; millis: int): SocketConnectResult` | Blocking connect bounded by `millis`. |
| `connectTimeout` | `proc connectTimeout(ip: Ipv4Address; port: int; millis: int): SocketConnectResult` | As above, from an `Ipv4Address`. |
| `finishConnect` | `proc finishConnect(socket: Socket; errorCode: var int): bool` | Check whether a non-blocking connect completed; reports the error code. |
| `finishConnect` | `proc finishConnect(socket: Socket): bool` | Value form of the above. |

### Reading & writing

| symbol | signature | what it does |
|---|---|---|
| `recvInto` | `proc recvInto(socket: Socket; buf: pointer; len: int): int` | Single read into a caller-owned buffer; bytes read, `0` at EOF, `-1` on error. |
| `sendFrom` | `proc sendFrom(socket: Socket; buf: pointer; len: int): int` | Single write from a caller-owned buffer. |
| `sendAllFrom` | `proc sendAllFrom(socket: Socket; buf: pointer; len: int): int` | Write the whole buffer, looping over partial writes. |
| `recv` | `proc recv(socket: Socket; maxBytes: int): string` | Read up to `maxBytes` into a string, looping until `maxBytes` / EOF / would-block — no hidden 8192 cap. |
| `readAll` | `proc readAll(socket: Socket): string` | Drain the whole stream to EOF into a string. |
| `send` | `proc send(socket: Socket; data: string): int` | Send the whole string unless the socket errors; returns bytes sent. |
| `sendAll` | `proc sendAll(socket: Socket; data: string): bool` | `send == data.len`; `true` iff the whole string went out. |

### Buffered reader

| symbol | signature | what it does |
|---|---|---|
| `newBufferedSocket` | `proc newBufferedSocket(socket: Socket): BufferedSocket` | Wrap a socket in a buffered line reader. |
| `bufferedSocket` | `proc bufferedSocket(socket: Socket): BufferedSocket` | Alias for `newBufferedSocket`. |
| `recvLine` | `proc recvLine(reader: var BufferedSocket): string` | Read one CRLF/LF-terminated line (terminator stripped); over-read bytes stay buffered; `""` at EOF. |
| `recv` | `proc recv(reader: var BufferedSocket; maxBytes: int): string` | Read up to `maxBytes`, draining the buffer first so it composes with `recvLine`. |
| `readAll` | `proc readAll(reader: var BufferedSocket): string` | Read everything left: buffer first, then the socket to EOF. |

### Non-blocking, polling & timeouts

| symbol | signature | what it does |
|---|---|---|
| `setBlocking` | `proc setBlocking(socket: Socket; blocking: bool): bool` | Set blocking mode. |
| `setNonBlocking` | `proc setNonBlocking(socket: Socket): bool` | Switch the socket to non-blocking. |
| `poll` | `proc poll(socket: Socket; request: SocketPollRequest; timeoutMillis: int; ready: var SocketPollResult): int` | Wait for read/write readiness; fills `ready`, returns the poll count (`-1` if invalid). |
| `waitReadable` | `proc waitReadable(socket: Socket; timeoutMillis: int): bool` | Block until readable or timeout. |
| `waitWritable` | `proc waitWritable(socket: Socket; timeoutMillis: int): bool` | Block until writable or timeout. |
| `setReadTimeoutMillis` | `proc setReadTimeoutMillis(socket: Socket; millis: int): bool` | Per-read timeout. |
| `setWriteTimeoutMillis` | `proc setWriteTimeoutMillis(socket: Socket; millis: int): bool` | Per-write timeout. |
| `setTimeoutMillis` | `proc setTimeoutMillis(socket: Socket; millis: int): bool` | Set both read and write timeouts. |

### Socket options & introspection

| symbol | signature | what it does |
|---|---|---|
| `localEndpoint` | `proc localEndpoint(socket: Socket): Endpoint` | The socket's local address+port (family-aware — a v6 socket yields a v6 endpoint). |
| `peerEndpoint` | `proc peerEndpoint(socket: Socket): Endpoint` | The connected peer's address+port (family-aware — v4 or v6). |
| `setNoDelay` | `proc setNoDelay(socket: Socket; enabled = true): bool` | Toggle `TCP_NODELAY` (Nagle off). |
| `setKeepAlive` | `proc setKeepAlive(socket: Socket; enabled = true): bool` | Toggle SO_KEEPALIVE. |
| `socketErrorCode` | `proc socketErrorCode(socket: Socket; errorCode: var int): bool` | Read `SO_ERROR` into `errorCode`. |
| `socketErrorCode` | `proc socketErrorCode(socket: Socket): int` | Value form of the above (`-1` if invalid). |

### Shutdown & close

| symbol | signature | what it does |
|---|---|---|
| `shutdownRead` | `proc shutdownRead(socket: Socket): bool` | Half-close the read side. |
| `shutdownWrite` | `proc shutdownWrite(socket: Socket): bool` | Half-close the write side. |
| `shutdownBoth` | `proc shutdownBoth(socket: Socket): bool` | Half-close both directions. |
| `close` | `proc close(socket: Socket)` | Close the socket (no-op if already invalid). |
| `closeAndInvalidate` | `proc closeAndInvalidate(socket: var Socket)` | Close and reset the handle to `InvalidTcpHandle`. |

## Design notes

- **Value-typed sockets.** A `Socket` is just a boxed `TcpHandle`; there is no
  hidden allocation or finalizer. You close explicitly, and every op on an invalid
  socket returns a sentinel (`-1`, `false`, `invalidSocket()`) rather than raising.
- **Status-based errors, no exceptions.** Failures surface as return codes plus the
  thread-local `lastNetError*` family, mirroring `tcp`'s `TcpErrorKind` model.
- **Blocking by default, non-blocking on demand.** The plain `recv`/`send`/`connect`
  paths block; `setNonBlocking` + `poll`/`waitReadable` + `connectNonBlocking`/
  `finishConnect` give a complete non-blocking escape hatch over the same `Socket`.
- **Family-agnostic reach.** `connectHost`/`dial` follow both A and AAAA records via
  `tcp`'s `connectHostTcp`, and `listen6` gives one dual-stack listener for both
  families — so callers rarely branch on address family.
- **Family-carrying endpoints.** `Endpoint` tags itself `familyV4`/`familyV6`, so
  `localEndpoint`/`peerEndpoint` of a v6 socket return the real IPv6 address and `$`
  renders it bracketed (`"[::1]:8080"`). The addition is backward-compatible:
  `Endpoint(address: someIpv4, port: p)` still builds a `familyV4` endpoint and
  `.address` keeps working, so the IPv4 fast path is untouched.
- **Caller-owned buffers underneath, strings on top.** The raw `recvInto`/`sendFrom`
  pair takes your buffer; `recv`/`readAll`/`send` and `BufferedSocket` add
  string-convenience and line framing on top without a per-call cap surprise.
- **TLS lives elsewhere.** TLS was extracted into its own `tls` repo; a TLS session
  simply wraps a `net.Socket`, keeping this layer plaintext-only.

## Requirements

- Nimony toolchain (`aowl` / nimony compiler).
- Dependency: `aoughwl/tcp` (the underlying blocking socket layer). No C libraries
  beyond the platform socket API that `tcp` binds.
