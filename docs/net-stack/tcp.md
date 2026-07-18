---
repo: aoughwl/tcp
---

# tcp — native blocking sockets

The bottom layer of the `tcp → net → serve` stack. Binds directly to the
platform socket API (POSIX / Winsock) with no C shim and no framework runtime,
hands you raw `TcpHandle`s and caller-owned buffers, and reports failures as
status codes plus a classified `TcpErrorKind` rather than exceptions. Depends
only on the nimony toolchain and libc sockets — no third-party packages.

> **Status** — Solid and complete for what it is: IPv4 + IPv6/dual-stack, blocking I/O with a non-blocking + timeout escape hatch, the full common sockopt set, and SIGPIPE-safe writes all ship and are covered by tests. The addressing helpers are IPv4-only (no `parseIpv6Text`/`formatIpv6`), and endpoints carry a `uint32` IPv4 address — an accepted IPv6 peer surfaces no textual address.

## Quickstart

```nim
import tcp

initTcp()                          # no-op on POSIX; WSAStartup on Windows

# Family-agnostic client: resolves A + AAAA, connects to the first that accepts.
let fd = connectHostTcp("example.com", 80)
if not isValidTcp(fd):
  echo "connect failed: ", $lastTcpErrorKind()
  quit 1

let req = "GET / HTTP/1.0\r\nHost: example.com\r\n\r\n"
discard writeAllTcp(fd, req.toCString(), req.len)

var buf = newString(4096)
let n = readTcp(fd, buf[0].addr, buf.len)   # >0 bytes, 0 EOF, <0 error
if n > 0:
  buf.setLen(n)
  echo buf

closeTcp(fd)
shutdownTcp()
```

## API

The whole surface lives in `tcp/native.nim` and is re-exported by the `tcp`
umbrella module. Handles are raw platform descriptors (`cint` on POSIX,
`uint`/`SOCKET` on Windows); the library never owns or frees them for you beyond
`closeTcp`.

### Types & constants

| symbol | signature | what it does |
|---|---|---|
| `TcpHandle` | `cint` (POSIX) / `uint` (Windows) | Raw platform socket descriptor. |
| `InvalidTcpHandle` | `const TcpHandle` | Sentinel for a failed/absent handle (`-1` POSIX, `not 0'u` Windows). |
| `TcpErrorKind` | `enum` | Portable error class: `tcpErrorNone`, `tcpErrorRetry`, `tcpErrorTimeout`, `tcpErrorInterrupted`, `tcpErrorDisconnected`, `tcpErrorRefused`, `tcpErrorUnreachable`, `tcpErrorUnknown`. |
| `TcpConnectStatus` | `enum` | `tcpConnectFailed`, `tcpConnectInProgress`, `tcpConnectConnected`. |
| `TcpEndpoint` | `object` | `address: uint32` (host-order IPv4) + `port: int`. |
| `TcpConnectResult` | `object` | `handle: TcpHandle`, `status: TcpConnectStatus`, `errorCode: int`. |
| `TcpPollRequest` | `object` | `read: bool`, `write: bool` — readiness interest passed to `pollTcp`. |
| `TcpPollResult` | `object` | `read`, `write`, `error`, `hangup`, `invalid` bools — decoded poll revents. |

### Lifecycle

| symbol | signature | what it does |
|---|---|---|
| `initTcp` | `proc initTcp()` | Initialise sockets. No-op on POSIX; `WSAStartup` (idempotent) on Windows. |
| `shutdownTcp` | `proc shutdownTcp()` | Tear down. No-op on POSIX; `WSACleanup` on Windows. |

### Errors

| symbol | signature | what it does |
|---|---|---|
| `lastTcpErrorCode` | `proc lastTcpErrorCode(): int` | Last platform socket error for the current thread (`errno` / `WSAGetLastError`). |
| `lastTcpErrorKind` | `proc lastTcpErrorKind(): TcpErrorKind` | `classifyTcpErrorCode(lastTcpErrorCode())`. |
| `classifyTcpErrorCode` | `proc classifyTcpErrorCode(code: int): TcpErrorKind` | Map a raw code onto a portable `TcpErrorKind`. |
| `tcpErrorWouldRetry` | `proc tcpErrorWouldRetry(code: int): bool` | True for EAGAIN/EWOULDBLOCK/EINPROGRESS/EALREADY-class codes. |
| `tcpErrorTimedOut` | `proc tcpErrorTimedOut(code: int): bool` | True for a timeout code. |
| `tcpErrorInterrupted` | `proc tcpErrorInterrupted(code: int): bool` | True for EINTR. |
| `tcpErrorDisconnected` | `proc tcpErrorDisconnected(code: int): bool` | True for disconnect/refused/unreachable classes. |

### Addressing (IPv4)

| symbol | signature | what it does |
|---|---|---|
| `formatIpv4` | `proc formatIpv4(address: uint32): string` | Host-order IPv4 → dotted-decimal `"a.b.c.d"` (high byte first). |
| `parseIpv4Text` | `proc parseIpv4Text(s: string; dest: var uint32): bool` | Char-walked, range-checked inverse of `formatIpv4`; rejects bad/empty octets and wrong dot counts. |
| `resolveTcp4` | `proc resolveTcp4(host: string; dest: var uint32): bool` | Resolve the first IPv4 (`getaddrinfo`) address for `host` into host order. |

### Connecting

| symbol | signature | what it does |
|---|---|---|
| `connectTcp4` | `proc connectTcp4(hostOrderAddr: uint32; port: int): TcpHandle` | Blocking IPv4 connect to a host-order address. |
| `connectTcp4NonBlocking` | `proc connectTcp4NonBlocking(hostOrderAddr: uint32; port: int): TcpConnectResult` | Start a non-blocking connect; poll writable then `finishTcpConnect`. |
| `connectTcp4Timeout` | `proc connectTcp4Timeout(hostOrderAddr: uint32; port: int; timeoutMillis: int): TcpConnectResult` | Blocking connect with a timeout (non-blocking connect + `pollTcp`); handle restored to blocking on success. |
| `connectLocalhostTcp` | `proc connectLocalhostTcp(port: int): TcpHandle` | Blocking connect to `127.0.0.1:port`. |
| `connectLocalhostTcpNonBlocking` | `proc connectLocalhostTcpNonBlocking(port: int): TcpConnectResult` | Non-blocking `127.0.0.1` connect. |
| `connectHostTcp` | `proc connectHostTcp(host: string; port: int): TcpHandle` | Resolve `host` `AF_UNSPEC` (IPv4 and IPv6) and connect to the first address that accepts — family-agnostic client entry point. |
| `finishTcpConnect` | `proc finishTcpConnect(fd: TcpHandle): bool` / `proc finishTcpConnect(fd: TcpHandle; errorCode: var int): bool` | Check whether a non-blocking connect completed (reads `SO_ERROR`). |

### Listening & accepting

| symbol | signature | what it does |
|---|---|---|
| `listenTcp4` | `proc listenTcp4(hostOrderAddr: uint32; port: int; backlog = 128): TcpHandle` | Bind + listen on a host-order IPv4 address (sets `SO_REUSEADDR`). |
| `listenTcp` | `proc listenTcp(port: int; backlog = 128): TcpHandle` | `listenTcp4(INADDR_ANY, …)` — listen on all IPv4 interfaces. |
| `listenTcp6` | `proc listenTcp6(port: int; backlog = 128; dualStack = true): TcpHandle` | IPv6 wildcard listener; with `dualStack` clears `IPV6_V6ONLY` so one socket also accepts IPv4-mapped connections. |
| `acceptTcp` | `proc acceptTcp(listenFd: TcpHandle): TcpHandle` | Accept the next connection. |
| `acceptTcpWithPeer` | `proc acceptTcpWithPeer(listenFd: TcpHandle; peer: var TcpEndpoint): TcpHandle` | Accept and fill the peer's (IPv4) endpoint. |

### Reading & writing

| symbol | signature | what it does |
|---|---|---|
| `readTcp` | `proc readTcp(fd: TcpHandle; buf: pointer; len: int): int` | `recv` into a caller-owned buffer. Returns bytes read, `0` on EOF, `<0` on error. |
| `writeTcp` | `proc writeTcp(fd: TcpHandle; buf: pointer; len: int): int` | `send` from a caller-owned buffer. Uses `MSG_NOSIGNAL` on Linux/BSD (broken pipe → EPIPE, not a signal). |
| `writeAllTcp` | `proc writeAllTcp(fd: TcpHandle; buf: pointer; len: int): int` | Retry short writes until `len` bytes sent or error; returns bytes written. |
| `closeTcp` | `proc closeTcp(fd: TcpHandle)` | Close the handle (no-op on `InvalidTcpHandle`). |
| `isValidTcp` | `proc isValidTcp(fd: TcpHandle): bool` | `fd != InvalidTcpHandle`. |
| `shutdownTcpRead` | `proc shutdownTcpRead(fd: TcpHandle): bool` | Half-close the receive side (`SHUT_RD`). |
| `shutdownTcpWrite` | `proc shutdownTcpWrite(fd: TcpHandle): bool` | Send EOF to the peer, keep receiving (`SHUT_WR`). |
| `shutdownTcpBoth` | `proc shutdownTcpBoth(fd: TcpHandle): bool` | Half-close both directions (`SHUT_RDWR`), handle stays open. |

### Non-blocking & readiness

| symbol | signature | what it does |
|---|---|---|
| `setTcpBlocking` | `proc setTcpBlocking(fd: TcpHandle; blocking: bool): bool` | Switch blocking/non-blocking (`fcntl O_NONBLOCK` / `ioctlsocket FIONBIO`). |
| `setTcpNonBlocking` | `proc setTcpNonBlocking(fd: TcpHandle): bool` | Convenience for `setTcpBlocking(fd, false)`. |
| `pollTcp` | `proc pollTcp(fd: TcpHandle; request: TcpPollRequest; timeoutMillis: int; ready: var TcpPollResult): int` | Wait for readiness via `poll` / `WSAPOLL`. Returns `>0` ready, `0` timeout, `<0` error; decodes revents into `ready`. |
| `waitTcpReadable` | `proc waitTcpReadable(fd: TcpHandle; timeoutMillis: int): bool` | True if readable within the timeout. |
| `waitTcpWritable` | `proc waitTcpWritable(fd: TcpHandle; timeoutMillis: int): bool` | True if writable within the timeout. |
| `tcpSocketErrorCode` | `proc tcpSocketErrorCode(fd: TcpHandle; errorCode: var int): bool` / `proc tcpSocketErrorCode(fd: TcpHandle): int` | Read the pending `SO_ERROR` value (`-1` if unreadable in the single-return form). |

### Socket options

| symbol | signature | what it does |
|---|---|---|
| `setTcpNoDelay` | `proc setTcpNoDelay(fd: TcpHandle; enabled = true): bool` | Toggle `TCP_NODELAY` (disable Nagle for latency-sensitive small writes). |
| `setTcpKeepAlive` | `proc setTcpKeepAlive(fd: TcpHandle; enabled = true): bool` | Toggle platform-default `SO_KEEPALIVE`. |
| `setTcpReuseAddr` | `proc setTcpReuseAddr(fd: TcpHandle; enabled = true): bool` | Toggle `SO_REUSEADDR` (rebind through `TIME_WAIT`). |
| `setTcpReusePort` | `proc setTcpReusePort(fd: TcpHandle; enabled = true): bool` | Toggle `SO_REUSEPORT`; returns `false` on Windows (unsupported). |
| `setTcpBroadcast` | `proc setTcpBroadcast(fd: TcpHandle; enabled = true): bool` | Toggle `SO_BROADCAST`. |
| `setTcpLinger` | `proc setTcpLinger(fd: TcpHandle; onoff: bool; seconds: int): bool` | Configure `SO_LINGER` — `close()` blocks up to `seconds` to flush, or disable. |
| `setTcpRecvBufferSize` | `proc setTcpRecvBufferSize(fd: TcpHandle; bytes: int): bool` | Request `SO_RCVBUF`. |
| `setTcpSendBufferSize` | `proc setTcpSendBufferSize(fd: TcpHandle; bytes: int): bool` | Request `SO_SNDBUF`. |
| `setTcpReadTimeoutMillis` | `proc setTcpReadTimeoutMillis(fd: TcpHandle; millis: int): bool` | Bound blocking reads (`SO_RCVTIMEO`); `0` restores default. |
| `setTcpWriteTimeoutMillis` | `proc setTcpWriteTimeoutMillis(fd: TcpHandle; millis: int): bool` | Bound blocking writes (`SO_SNDTIMEO`); `0` restores default. |
| `setTcpTimeoutMillis` | `proc setTcpTimeoutMillis(fd: TcpHandle; millis: int): bool` | Apply one timeout to both read and write. |
| `setTcpOption` | `proc setTcpOption(fd: TcpHandle; level, optname: cint; intval: int): bool` | Generic passthrough to set any integer-valued sockopt. |
| `getTcpOption` | `proc getTcpOption(fd: TcpHandle; level, optname: cint; dest: var cint): bool` | Generic passthrough to read any integer-valued sockopt. |

### Endpoints

| symbol | signature | what it does |
|---|---|---|
| `localTcpEndpoint` | `proc localTcpEndpoint(fd: TcpHandle): TcpEndpoint` | The socket's bound IPv4 address + port (`getsockname`), or an invalid endpoint. |
| `peerTcpEndpoint` | `proc peerTcpEndpoint(fd: TcpHandle): TcpEndpoint` | The connected peer's IPv4 address + port (`getpeername`), or invalid. |
| `invalidTcpEndpoint` | `proc invalidTcpEndpoint(): TcpEndpoint` | Sentinel endpoint (`address: 0`, `port: -1`). |

## Design notes

- **Status codes, not exceptions.** Every fallible call returns a `bool`, a
  signed count, or a `TcpConnectResult`; nothing raises. Classify raw codes with
  `classifyTcpErrorCode` / the `tcpError*` predicates, or read `lastTcpErrorKind`.
- **Caller-owned buffers.** `readTcp` / `writeTcp` take a `pointer` + `len` and
  never allocate — you own the memory and the loop. `writeAllTcp` is the only
  retry helper.
- **One handle, two modes.** A socket starts blocking; `setTcpNonBlocking`,
  `pollTcp`, and the `*Timeout` connect flip it as needed on the same descriptor.
- **Family-agnostic core.** `connectHostTcp` (getaddrinfo `AF_UNSPEC` → try
  each) and `listenTcp6(dualStack = true)` (one IPv6 socket, `IPV6_V6ONLY`
  cleared) are the IPv4+IPv6 primitives the `net`/`serve` layers build on; the
  connect path passes the resolver's opaque `sockaddr` straight to `connect`, so
  no per-family struct is needed.
- **SIGPIPE-safe writes.** `writeTcp` sends with `MSG_NOSIGNAL` on Linux/BSD, so
  writing to a broken pipe returns `EPIPE` (→ `tcpErrorDisconnected`) instead of
  killing the process. macOS/Windows lack the flag and fall back to `0`.
- **IPv4-shaped endpoints.** `TcpEndpoint.address` is a `uint32`; dual-stack /
  IPv6 peers connect and transfer data fine, but `peerTcpEndpoint` cannot
  represent their address. Textual IPv6 addressing lives above this layer.

## Requirements

- **Nimony toolchain** (aoughwl fork). Pure nimony; no framework runtime.
- **libc sockets only** — POSIX `<sys/socket.h>` / `<netdb.h>` / `<poll.h>` on
  Unix, `ws2_32.dll` (Winsock2, `WSAPOLL`) on Windows. No third-party package
  dependencies.
