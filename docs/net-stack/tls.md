---
repo: aoughwl/tls
---

# tls — TLS 1.3 for the aoughwl net stack

`tls` adds encrypted transport to the aoughwl networking stack. A `TlsSocket`
wraps an already-connected `net.Socket`, driving the TLS 1.3 handshake and
record layer through OpenSSL 3 (`libssl.so.3` / `libcrypto.so.3`) over a
header-free `dynlib` FFI. It sits directly above `net` + `tcp` and supports both
roles: a client context (SNI, hostname verification, ALPN, trust store) and a
server context (PEM cert chain + key, ALPN selection).

> **Status** — Production-ready. TLS 1.3 client+server, SNI + hostname
> verification, ALPN (both directions), configurable cipher/suite and
> min/max version, and non-blocking handshake/I-O all shipped. Session
> resumption (tickets/PSK) is not tuned, and server-side ALPN preference is a
> single process-global (no per-SNI multi-cert virtual hosting).

## Quickstart

```nim
import tls

var ctx = newTlsClientContext()          # verify against the system trust store
discard ctx.setAlpnProtocols(@["http/1.1"])

var conn = ctx.connectTls("example.com", 443)   # resolve + TCP + handshake
if conn.isValid and conn.handshakeDone:
  echo conn.protocolVersion()            # "TLSv1.3"
  echo conn.negotiatedAlpn()             # "http/1.1"
  echo conn.verifyOk()                   # true

  discard conn.sendAll("GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n")
  echo conn.readAll()

conn.closeTls()                          # close_notify + free SSL + close socket
ctx.freeContext()
```

## API

### Types

| symbol | signature | what it does |
| --- | --- | --- |
| `TlsMode` | `enum tlsClient, tlsServer` | Role a context was built for. |
| `TlsContext` | `object { handle: pointer; mode: TlsMode }` | Long-lived config wrapping `SSL_CTX`; reuse across connections. `handle` is nil when construction failed. |
| `TlsSocket` | `object { socket: Socket; ssl: pointer; handshakeDone: bool }` | One TLS connection over a `Socket`, wrapping `SSL`. |
| `TlsStatus` | `enum tlsOk, tlsWantRead, tlsWantWrite, tlsClosed, tlsError` | Result of a handshake/read/write. The `tlsWant*` values are the non-blocking retry signals. |

### Constants (protocol versions)

| symbol | value | what it does |
| --- | --- | --- |
| `TLS1_VERSION` | `0x0301` | Version selector for `setMinVersion` / `setMaxVersion`. |
| `TLS1_1_VERSION` | `0x0302` | " |
| `TLS1_2_VERSION` | `0x0303` | " |
| `TLS1_3_VERSION` | `0x0304` | " |

### Context construction

| symbol | signature | what it does |
| --- | --- | --- |
| `newTlsClientContext` | `proc(verify = true): TlsContext` | Build a client context. With `verify` (default) the server chain is checked against the system trust store; pass `false` only for self-signed testing. |
| `newTlsServerContext` | `proc(certChainFile: string; keyFile: string): TlsContext` | Build a server context from a PEM cert chain + private key. Returns an invalid context (`isValid` false) if a file fails to load or the key does not match the cert. |
| `close` | `proc(ctx: var TlsContext)` | Free the underlying `SSL_CTX` and nil the handle. |
| `freeContext` | `proc(ctx: var TlsContext)` | Alias for `close(TlsContext)`; use at call sites that also import `net` (whose `Socket` has its own `close`) where `ctx.close()` is ambiguous. |

### Context configuration

| symbol | signature | what it does |
| --- | --- | --- |
| `setVerifyPeer` | `proc(ctx: TlsContext; enabled: bool)` | Turn peer certificate verification on/off. |
| `loadVerifyLocations` | `proc(ctx: TlsContext; caFile: string): bool` | Trust an extra CA bundle / cert file (PEM). Returns success. |
| `useDefaultVerifyPaths` | `proc(ctx: TlsContext): bool` | (Re)load the system default trust store. Returns success. |
| `setCipherList` | `proc(ctx: TlsContext; ciphers: string): bool` | Restrict the TLS 1.2-and-below cipher list (OpenSSL cipher string). |
| `setCipherSuites` | `proc(ctx: TlsContext; suites: string): bool` | Restrict the TLS 1.3 cipher suites (colon-separated suite names). |
| `setMinVersion` | `proc(ctx: TlsContext; version: int): bool` | Floor the negotiated protocol version (e.g. `TLS1_2_VERSION`). |
| `setMaxVersion` | `proc(ctx: TlsContext; version: int): bool` | Cap the negotiated protocol version. |
| `setAlpnProtocols` | `proc(ctx: TlsContext; protocols: seq[string]): bool` | (Client) Advertise an ALPN list, e.g. `@["h2", "http/1.1"]`. Encodes the length-prefixed wire form. |
| `setAlpnServer` | `proc(ctx: TlsContext; protocols: seq[string]): bool` | (Server) Register the selection callback that picks the server's most-preferred protocol from the client offer, so `negotiatedAlpn` reflects the choice. |

### Connecting & handshake

| symbol | signature | what it does |
| --- | --- | --- |
| `connectTls` | `proc(ctx: TlsContext; host: string; port: int): TlsSocket` | One-call client entry: resolve `host`, open TCP, run the client handshake with SNI + hostname verification set to `host`. Blocking; check `handshakeDone` / `isValid`. |
| `wrapClient` | `proc(ctx: TlsContext; socket: Socket; serverName: string): TlsSocket` | Start a client session over an already-connected socket; sets SNI + verification hostname to `serverName` and runs the handshake. |
| `wrapServer` | `proc(ctx: TlsContext; socket: Socket): TlsSocket` | Start a server session over an accepted socket and run the handshake. |
| `handshake` | `proc(t: var TlsSocket): TlsStatus` | Drive or resume the handshake. Returns `tlsOk` on completion; on a non-blocking socket may return `tlsWantRead`/`tlsWantWrite` — call again when the socket is ready. |

### Reading & writing

| symbol | signature | what it does |
| --- | --- | --- |
| `tlsReadInto` | `proc(t: var TlsSocket; buf: pointer; len: int; status: var TlsStatus): int` | Read up to `len` plaintext bytes into a caller-owned buffer. Returns count (>0) with `tlsOk`; 0 with `tlsClosed`/`tlsWant*`/`tlsError`; -1 on an invalid socket. |
| `tlsWriteFrom` | `proc(t: var TlsSocket; buf: pointer; len: int; status: var TlsStatus): int` | Write up to `len` plaintext bytes from a buffer. Returns count accepted (>0) with `tlsOk`, else 0 with a want/closed/error status. |
| `recv` | `proc(t: var TlsSocket; maxBytes: int): string` | Blocking convenience: read up to `maxBytes` into a string; stops at EOF or no progress. |
| `readAll` | `proc(t: var TlsSocket): string` | Blocking convenience: read plaintext until the peer closes the TLS session. |
| `send` | `proc(t: var TlsSocket; data: string): int` | Blocking convenience: write the whole string; returns bytes sent (a short return signals a closed/errored session). |
| `sendAll` | `proc(t: var TlsSocket; data: string): bool` | `send(t, data) == data.len` — true when the whole payload went out. |
| `pending` | `proc(t: TlsSocket): int` | Bytes already decrypted and buffered inside OpenSSL; a caller polling the fd must drain these first. |

### Connection info

| symbol | signature | what it does |
| --- | --- | --- |
| `protocolVersion` | `proc(t: TlsSocket): string` | Negotiated protocol, e.g. `"TLSv1.3"`. |
| `cipherName` | `proc(t: TlsSocket): string` | Negotiated cipher suite name. |
| `negotiatedAlpn` | `proc(t: TlsSocket): string` | ALPN protocol the peer selected (e.g. `"h2"`), or `""`. |
| `verifyOk` | `proc(t: TlsSocket): bool` | True when the peer chain verified (`X509_V_OK`). Meaningful only when the context requested verification. |
| `verifyResultCode` | `proc(t: TlsSocket): int` | Raw X509 verification result code (0 == `X509_V_OK`). |

### Status, validity & teardown

| symbol | signature | what it does |
| --- | --- | --- |
| `isValid` | `proc(ctx: TlsContext): bool` | Context has a live `SSL_CTX` handle. |
| `isValid` | `proc(t: TlsSocket): bool` | Socket has a live `SSL`. |
| `lastTlsError` | `proc(): string` | Pop and format the most recent OpenSSL error, or `""` when the queue is empty. |
| `closeTls` | `proc(t: var TlsSocket; closeSocket = true)` | Send `close_notify`, free the `SSL`, and (by default) close the underlying socket. |

## Design notes

- **No headers, no C shim.** OpenSSL is reached purely through `dynlib` FFI to
  `libssl.so.3` / `libcrypto.so.3`; opaque structs are passed around as
  nil-checked `pointer`. Control operations go through the raw `SSL_ctrl` /
  `SSL_CTX_ctrl` command numbers rather than the header macros.
- **Status-based, no exceptions.** Every fallible call returns a `TlsStatus` or
  bool; nothing raises. Construction failures surface as an invalid handle
  (`isValid` false) rather than an error to catch.
- **Caller-owned buffers.** `tlsReadInto` / `tlsWriteFrom` are the primitive I/O
  layer over caller memory; `recv` / `readAll` / `send` / `sendAll` are the
  blocking-socket string conveniences built on top.
- **Blocking with a non-blocking escape hatch.** On a non-blocking socket the
  handshake and I/O surface `tlsWantRead` / `tlsWantWrite`, so the same API
  drives a poll loop. `pending` reports OpenSSL-buffered plaintext that a raw fd
  poll cannot see.
- **Context outlives connections.** A `TlsSocket` holds a reference on the
  context via OpenSSL's refcount, so a context may be closed after
  `connectTls` without tearing down live sessions.
- **ALPN asymmetry.** `setAlpnProtocols` only advertises (client side);
  `setAlpnServer` registers the selection callback. The server preference list
  is a single process-global wire string — one server config per process.

## Requirements

- **Toolchain:** the nimony/aowl compiler.
- **Depends on:** `aoughwl/net` and `aoughwl/tcp` (socket type, resolver,
  `connectTcp4`).
- **C libraries (runtime, via dynlib):** OpenSSL 3 — `libssl.so.3` and
  `libcrypto.so.3`. No build-time headers or linkage required.
