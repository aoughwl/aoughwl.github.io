# Configurability roadmap

What "100% configurable, both sides" definitively means for this stack, what is
concretely missing today, and the order to build it in.

[[toc]]

---

## Why this document exists

Every library in this stack works. Most of them are *not configurable* — the
decisions are made, correctly, and then baked in as literals. A 16 KiB scratch
buffer, a 15-second read timeout, `initial_max_data = 1 MiB`, a GnuTLS priority
string, `br > zstd > gzip`. None of those are wrong. All of them are somebody
else's problem the moment a user's workload differs from ours.

This is an audit of every such decision across the eight repos, plus the
definition of "done" we are holding ourselves to.

## What "100% configurable" definitively means

A knob is not "exposed" because a value can be reached somehow. The bar is
eight properties, and a capability counts as configurable only when it has all
eight:

| # | Property | Test |
|---|---|---|
| 1 | **Named** | The value has a public identifier, not a literal at a call site |
| 2 | **Settable** | A caller can change it without editing or forking the library |
| 3 | **Scoped** | It can be set per process, per server, per connection, and per request/stream — with a documented merge order |
| 4 | **Defaulted** | The default is public and readable, so "the default plus one change" doesn't mean re-hardcoding it |
| 5 | **Observable** | The *effective* value (after negotiation) can be read back |
| 6 | **Bounded loudly** | When a limit is hit, the caller learns — a status, a hook, a log — never a silent drop |
| 7 | **Escapable** | Anything we did not wrap can still be reached raw at the FFI boundary |
| 8 | **Composable** | Setting it does not require a different entry point, a second code path, or a global |

Property 3 is the one every other stack gets wrong in the same way, and it is
where we can actually be better. Go's `http.Server` has fields but no
per-request override; Node's config is per-server; hyper's is per-connection
builder. Nothing mainstream offers one merge discipline from process default
down to a single stream. Our `requests` client already does exactly that
(profile → session → call), so the pattern is proven in-house — the work is
making the other seven repos obey it.

Property 6 is the one *we* currently get wrong the most. The audit below found
silent drops in at least eight places.

### The scope ladder

```
process defaults  →  server / session  →  connection  →  request / stream
```

Every knob lives at the highest scope where it makes sense and may be narrowed
at any lower one. Settings that are protocol-negotiated (ALPN, extensions,
transport parameters) are *proposed* at the higher scope and *observable* at the
lower one.

### The escape hatch rule

At every FFI boundary there must be a raw passthrough, so that "we didn't wrap
it" is never the same as "you can't have it":

| Boundary | Escape hatch | Status |
|---|---|---|
| sockets | `setTcpOption` / `getTcpOption` | ✅ present |
| libcurl | `setOption` / `getInfo` | ✅ present |
| OpenSSL | raw `SSL_CTX*` / `SSL*` accessor | ❌ missing |
| zlib / brotli / zstd | codec parameter record | ❌ missing |
| ngtcp2 / nghttp3 | transport-params + settings struct | ❌ missing |
| nghttp2 | SETTINGS table passthrough | ❌ missing |

---

## Cross-cutting findings

Four patterns explain most of the gaps, and each has a single structural fix.

**1. Knobs get swallowed one layer up.** `compress` exposes a level;
`http/contentcoding.encodeFor` calls it with no level. `ws/deflate` exposes
level and cap; `ws.sendFrame` drops both. `tls` supports SNI multi-cert and ALPN;
`serve.serveTls` builds the context internally and never hands it back, making
every one of those knobs unreachable. `net` never re-exports `tcp`, so
`import net` gives you a socket you cannot set `SO_REUSEPORT` on.
→ *Fix: config records that pass through, and re-export the layer below.*

**2. Config is positional, never a record.** There is no `GzipOpts`, no
`ServerConfig`, no `WsConfig`, no `ParserLimits` anywhere in the stack. Adding a
knob is therefore a breaking signature change every single time — which is
precisely why the pattern has been to hardcode at the call site instead.
→ *Fix: introduce the record types first; they are the prerequisite for
everything else in this roadmap.*

**3. Handlers are process-global.** `gHandler`, `gWsHandler`, `gPoolHandler`,
`gReg`/`gActive` — one server, one handler, one router per process. This is not
laziness; it is forced by `{.nimcall.}`-only handlers, which are in turn forced
by nimony's lambda lifter (it cannot lift a closure capturing a proc-typed var,
and closures stored in another module's global do not survive the coroutine
boundary). `serve/loop.nim` literally duplicates its connection core to serve
both shapes.
→ *Fix: a handler-plus-config carrier passed as an explicit parameter, and the
lambda-lifter bug filed against the compiler fork. Until then, config records
travel beside the nimcall pointer rather than inside a closure.*

**4. Limits fail silently.** `cid_add`, `queue_request`, `enqueue_dgram`, the
incoming-datagram ring, `conn_alloc`, HTTP/2 `allocStream`, HTTP/2 response
headers past 39, and oversized reactor requests all drop on the floor with no
signal. `sendto`'s return value is discarded outright, so a full UDP send buffer
loses packets invisibly.
→ *Fix: every bounded resource returns a status, and every server config carries
an `onLimit` hook.*

---

## Server side — what is missing

### Resource bounds that cannot be changed

| Bound | Value | Where |
|---|---|---|
| ~~Whole-request cap~~ | 8 MiB **default**, `setServeLimits` / `setReactorLimits` | closed 2026-08-01 |
| H3 request body cap | 1 MiB, re-allocated per `takeRequest` | `quic/quic.nim:127` |
| H3 request body (C side) | unbounded | `quicglue.c` `rbody_append` |
| ~~Keep-alive requests~~ | 100 blocking / 1000 reactor, both **defaults** now — the split is deliberate (a kept-alive connection costs a thread in one model, a coroutine in the other) | closed 2026-08-01 |
| Read chunk | 8192 / 4096 / 16384 depending on file | `loop.nim:35`, `reactorhttp.nim:33`, `http2.nim:369` |
| Write chunk | 65536 | `loop.nim:36` |
| WS max message | 64 MiB | `reactorws.nim:52` |
| Compress threshold | 64 bytes | `encoding.nim:16` |
| Worker threads | clamped 1–256, always stack-allocates 256 | `pool.nim:25,65` |
| epoll batch | 64 events | `reactor.nim:85` |
| QUIC connections | 64, silent drop past it | `quicglue.c:41` |
| QUIC streams / conn | 64 | `quicglue.c:42` |
| WebTransport streams / conn | 32 | `quicglue.c:43` |
| CID routing table | 256, linear scan on every packet | `quicglue.c:44` |
| Pending H3 requests | 256, silent drop | `quicglue.c:45` |
| UDP payload | 1452, no PMTU discovery | `quicglue.c:46` |
| Outgoing datagram queue | 8 per connection | `quicglue.c` `odg[8]` |
| Incoming datagram queue | 128, silent drop | `quicglue.c` `idg[128]` |
| H3 method / path | 16 / 512 bytes, **silently truncated** | `quicglue.c`, `quic.nim:112` |
| HTTP/2 streams / session | 64, silent drop | `http2.nim:97` |
| ~~HTTP/2 response headers~~ | 128, and overflow now answers **500** with `h2HeaderOverflows()` counting it — a dropped `Set-Cookie` is a wrong response, not a trimmed one | closed 2026-08-01 |
| ~~Static file~~ | whole file into memory, now capped (`setStaticFileLimit`, refusals counted); streaming remains the real fix | closed 2026-08-01 |

### Timeouts

The blocking stack has exactly one: `ReadTimeoutMillis = 15000`, a `const`.

**Closed for the reactor (2026-08-01).** It has a clock now: `setIdleTimeout`
arms a `CLOCK_MONOTONIC` deadline while a coroutine is parked and disarms it on
readiness, so it measures idleness rather than connection age; `epoll_wait`
blocks until the nearest deadline instead of forever. Expiry shuts the socket
down, which the coroutine sees as an ordinary EOF, so no server needed new
control flow. Defaults are 60 s for HTTP/1.1 and HTTP/2 and off for WebSocket,
each overridable per server, and the TLS handshake is covered because it is
just more parked I/O. The async client bounds its own exchange too
(`awaitFetch(..., timeoutMs)`, armed before the connect). `awaitReadableFor`
adds the other kind of timer — one that RESUMES the coroutine instead of
tearing the socket down — which is what QUIC's own timers need.

The blocking stack's one timeout is now a default rather than a law
(`setServeReadTimeout`). Still missing: handler-execution timeout, and separate
write/header/close timeouts everywhere.

### Protocol policy

- **TLS on the server is unreachable.** `serveTls` / `serveTlsConcurrent` build
  the `TlsContext` internally. SNI multi-cert, ALPN, versions, ciphers, mTLS —
  all supported by `aoughwl-tls`, all unreachable unless you abandon the entry
  point and write your own accept loop around `serveConnectionTls`.
  **Closed (2026-08-01)** for `serveTls` and `serveTlsConcurrent` too: both take
  a `TlsContext` overload, with the cert/key forms delegating to it.
  **Closed for the reactor servers:** every async TLS entry point
  (`serveHttpsReactor`, `serveWssReactor`, `serveHttp2TlsReactor`,
  `serveHttpsAlpnReactor`) takes a `TlsContext` the caller built and
  configured, with the cert/key form delegating to it. Verified reaching the
  wire: a TLS-1.3-only context refuses a `--tls-max 1.2` client while an h2
  client still gets HTTP/2. The blocking entry points still own their context.
- **ALPN is hardcoded**: `h2`/`http1.1` in HTTP/2, a single `h3` in QUIC.
  `serveTls` sets none at all. (The reactor's ALPN list is now the entry point's
  contract rather than a literal — `serveHttpsAlpnReactor` advertises both and
  dispatches per connection — but it is still not caller-supplied, deliberately:
  the dispatcher's protocol choice IS the ALPN result.)
- **QUIC transport parameters are a static function with no context argument** —
  stream limits, flow-control windows, 1 MiB connection window, 30 s idle
  timeout, all fixed. Congestion control is whatever ngtcp2 defaults to (CUBIC);
  BBR is not selectable.
- **The GnuTLS priority string is a literal**, so the QUIC TLS version, cipher
  suites and groups are fixed, there is no server SNI callback (one cert per
  context — no HTTP/3 virtual hosting), and the client verify callback accepts
  any certificate unconditionally.
- ~~**HTTP/2 sends exactly one SETTINGS entry** (MAX_CONCURRENT_STREAMS=100).
  Window sizes, frame size, header table size, max header list size:
  unreachable.~~ **Closed 2026-08-01**: `H2Settings` / `setH2Settings` cover all
  five; a 0 field means "keep nghttp2's default" rather than "announce 0", and
  `MAX_HEADER_LIST_SIZE` — unbounded by default, which is a choice worth
  revisiting — is now settable. Verified on the wire, h2spec still 146/146 with
  the extra entries announced.
- **nghttp3 settings**: only `enable_connect_protocol` and `h3_datagram` are set;
  `max_field_section_size`, QPACK table capacity and blocked streams are not.
- **No Retry / address-validation tokens and no 0-RTT** in QUIC — the server is
  an amplification target bounded only by ngtcp2's built-in 3× limit.
- **QUIC is IPv4-only** (`inet_pton(AF_INET, …)`, `AF_INET` socket), while the
  TCP stack is dual-stack.
- **An H3 handler cannot emit any response header** beyond `:status`,
  `content-type` and `content-length` — no `Set-Cookie`, no cache-control, no
  CORS. This is a fixed-width C marshalling contract, not a knob.
- **WebTransport CONNECT is auto-accepted for any path or origin** — no
  authorization hook.

### Lifecycle and observability

**Graceful shutdown is closed (2026-08-01).** For the blocking stack:
`stopServing` shuts down the registered listeners — the only thing that can
interrupt a blocking `accept` — so workers leave their loops and `runPool`'s
joins return; `serveStopOnSignals` wires SIGINT/SIGTERM to it, opt-in. The same
change fixed a busy-spin: a failed `accept` was a bare `continue`, so a dead
listener span every worker at 100% CPU indefinitely. For the reactor:
`requestStop(graceful)` writes to an eventfd the loop also watches (the only
work a signal handler may do, and the only way to interrupt a blocked
`epoll_wait`); a graceful stop closes the listeners and lets in-flight
connections finish, and the server entry points install SIGINT/SIGTERM
handlers.

Absent across the board otherwise: connection limits and
accept throttling, backpressure, access logging, metrics, tracing, qlog, error
and panic hooks (a raising handler is uncaught — one bad request takes the
process or worker down), custom error-page rendering, and response streaming
(every path materializes the whole body, so no SSE and no chunked responses).

**Closed 2026-08-01:** `static.nim` now does ETag / Last-Modified / 304
(`If-None-Match` including `*` and weak echoes) and byte ranges (206 with
`Content-Range`, 416 when unsatisfiable, `Accept-Ranges`), through
`staticResponseFor(root, req)` which `staticRoute` uses. `If-Modified-Since` is
honoured by exact match against the value we issued — conservative in the only
direction that cannot serve a stale body.

`static.nim` additionally has no `Cache-Control` policy knob, a fixed 17-entry
MIME table and a hardcoded `/index.html`.

### Composability

**Partly closed 2026-08-01:** `toHandler`'s `{.nimcall.}` entry composes with
every reactor server, demonstrated and tested end to end over HTTP/1.1, HTTP/2
and HTTP/3 (`examples/reactor_router.nim`, `tests/reactor_router_e2e.sh`) —
including a path parameter surviving the HTTP/3 path, where the request is
rebuilt from `(method, path, body)`. What remains below is the handler-shape
duplication, not an inability to route asynchronously.

Routing and middleware exist (`serve/router.nim`) but only for the blocking and
nimcall paths. The reactor HTTP, WebSocket, HTTP/2 and HTTP/3 servers each have
their own incompatible handler type and cannot use a router at all. There is
also no h2c `Upgrade:` path and no ALPN fallback — an HTTP/2 TLS listener drops
a client that negotiates `http/1.1` rather than serving it.

---

## Protocol libraries — what is missing

### http

- Only two limits exist (`maxLine` 8192, `maxHeaderBytes` 65536) and they cannot
  be disabled. There is **no max header count, no max body size, no max chunk
  size** — `feed` grows the body buffer without any cap.
- Trailers are parsed and then discarded, in both the parser and `decodeChunked`.
  There is no emit path.
- The response version is hardcoded `HTTP/1.1`, `Content-Type` is always emitted
  first (even when empty), `Content-Length` and `Connection: close` are appended
  unconditionally — a caller cannot control header order or suppress any of them,
  and cannot supply a custom reason phrase.
- `headerValue` returns only the first match; there is no `headerValues`, no
  comma-folding, no duplicate policy.
- `encodeChunked` emits the entire body as one chunk — no chunk size, no
  extensions, no trailers.
- `pickEncoding` ignores q-values entirely and matches by naive substring, so
  `Accept-Encoding: x-brotli` selects brotli and `identity;q=0` is not honored.
- `encodeFor` drops the compression level that `compress` exposes.
- Error statuses (400/431) are baked into the parser.
- `import http` does not give you `contentcoding`.

### compress

The whole configuration surface is three level parameters and three size caps.
Missing, and all supported by stock libz/libbrotli/libzstd: windowBits (so raw
deflate and zlib-wrapped output are unreachable, and `Content-Encoding: deflate`
is not offered), memLevel, strategy, preset dictionaries, zstd dictionaries and
advanced params (`ZSTD_CCtx`, windowLog, checksum, workers), brotli mode and
lgwin (fixed at generic/2²²), and `BrotliEncoderSetParameter` altogether.
Streaming compression is absent by design, so a 16 MiB payload means ~32 MiB
resident — and brotli/zstd decompression **eagerly allocates the full cap** on
every call. Error detail is discarded (`ok: bool` only) even though zlib's `msg`
field is laid out and `ZSTD_getErrorName` exists. The 16 MiB default is private,
and duplicated as a literal in three places.

### ws

- **No max frame size and no max message size.** `readFrame` feeds the wire's
  64-bit length straight to `readExactly`; fragment reassembly is unbounded.
  Close code 1009 is defined and never sent. This is the most serious gap in the
  package.
- The handshake read has no size limit and no timeout, and reads **one byte per
  syscall**.
- **Subprotocol negotiation does not exist** — not read, not emitted, not
  offered, no selection hook.
- Extension negotiation is a single string literal. `client_max_window_bits` /
  `server_max_window_bits` are never offered, parsed or honored — a peer that
  replies with a smaller window gets mis-decoded. Context takeover is asserted
  unilaterally and enforced structurally by rebuilding the z_stream per message.
- Every text/binary message is compressed regardless of size; no level, no
  threshold.
- The synchronous path never calls its own UTF-8 validator or close-code
  validator, even though `ws/protocol` provides both and the async reactor path
  uses them.
- Absent: close-handshake timeout, read/write deadlines, outgoing fragmentation,
  masking-policy override, extra headers on the client handshake (so no `Origin`,
  no `Authorization`, no cookies).
- The client validates the handshake by substring-searching the whole response
  for `101`.

---

## Transport libraries — what is missing

### tcp

Present and good: NODELAY, KEEPALIVE (on/off), REUSEADDR, REUSEPORT, LINGER,
buffer sizes, send/recv timeouts, IPV6_V6ONLY, non-blocking, backlog, and a
generic `setTcpOption`/`getTcpOption` escape hatch that reaches any int-valued
socket option.

Not reachable even through the escape hatch, because they need a different
syscall or a non-int value:

- `SO_BINDTODEVICE` (string optval)
- `sendmsg`/`recvmsg`, iovecs, `MSG_PEEK`/`MSG_WAITALL`/`MSG_OOB` — send and recv
  flags are hardcoded
- `sendfile`/`splice` zero-copy
- `accept4` with `SOCK_CLOEXEC`/`SOCK_NONBLOCK`; **no socket in this library is
  created `CLOEXEC`**, so every fd leaks across `exec`
- explicit local bind before connect (source address/port selection) — there is
  no `bindTcp` at all
- multi-fd `poll` — `pollTcp` is hardwired to `nfds = 1`; epoll is the only
  many-fd path and `tcp.nim` does not re-export it
- edge-triggered epoll (`EPOLLET` is not among the exported masks) and epoll
  user-data (only the `fd` payload)
- UDP/datagram sockets and Unix domain sockets
- `getaddrinfo` hints control, and non-blocking or timeout connect for IPv6 —
  `connectHostTcp` is blocking-only, so `dial`'s "happy-eyeballs-lite" is
  sequential with no per-address timeout and no configurable fallback delay: one
  dead IPv6 address stalls for the full kernel timeout.

`SO_REUSEADDR` is also forced on every listener with no opt-out, and
`epollAdd`/`Mod`/`Del` discard their return values.

### net

`net` wraps `tcp` but **never re-exports it**, so `import net` gives a caller
none of the option setters above; they must `import tcp` separately and reach
into `socket.handle`. `net` itself exposes only NODELAY, KEEPALIVE, timeouts and
blocking mode.

The 8192-byte buffer is baked in four places (`recv`, `readAll`, `fillBuffer`,
and a staging copy inside `send`). `BufferedSocket.buffer` never compacts — it
grows monotonically for the socket's lifetime — and `recvLine` has no maximum
line length, so a peer that never sends a newline grows it without bound.

### tls

Present: min/max version, cipher list and TLS 1.3 ciphersuites, verification
on/off, custom CA file, system trust store, client and server ALPN with a
selection callback, SNI including **multiple certs per hostname**, session
resumption with cache modes, hostname verification, peer CN, negotiated
version/cipher, and non-blocking want-read/want-write.

Absent, all fully supported by OpenSSL 3.0.13 — these are unwritten FFI
declarations, not library limits:

- **custom verify callback** (the cb argument is always `nil`) and therefore no
  soft-fail or inspect-then-accept
- **certificate pinning** — no `X509_digest`, no raw DER; `peerCertCommonName`
  (CN only, 256-byte buffer) is the entire inspection surface, and no SAN
- **client certificates** — a client context takes no cert/key at all, and
  `SSL_CTX_set_client_CA_list` / `set_client_cert_cb` /
  `SSL_VERIFY_FAIL_IF_NO_PEER_CERT` are absent, so mTLS works in neither role
- `SSL_CTX_set_options` (`SSL_OP_NO_RENEGOTIATION`, `NO_TICKET`,
  `CIPHER_SERVER_PREFERENCE`) and `SSL_CTX_set_mode` (`AUTO_RETRY`,
  `ENABLE_PARTIAL_WRITE`)
- **0-RTT / early data**, session-ticket count and lifetime, cache size, external
  session-cache callbacks
- **key logging** (`SSL_CTX_set_keylog_callback`) — no Wireshark decryption
- OCSP stapling, CRL checking, verify depth/purpose/time
- group/curve and signature-algorithm selection
- **custom BIO** — `SSL_set_fd` only, so TLS is welded to a real socket fd: no
  memory BIO means no in-memory test harness and no TLS over a non-socket
- encrypted private keys (no passphrase callback), DER keys, in-memory
  cert/key, PKCS#12 — PEM file paths only
- DTLS, PSK, post-handshake auth, `SSL_key_update`
- `SSL_shutdown` is called once and its result discarded — no bidirectional
  `close_notify`

The library name is pinned to `libssl.so.3`/`libcrypto.so.3`, and several
`SSL_CTX_ctrl` command numbers are baked as raw ints, which is ABI-fragile. The
server ALPN callback returns NOACK on mismatch and so can never reject a client;
the SNI callback always returns OK even with no match. `gServerStates` is an
unguarded global that grows forever.

Genuinely blocked by the dependency: QUIC (3.0.13 has no QUIC API — which is
exactly why the H3 stack uses GnuTLS via ngtcp2) and post-quantum groups.

---

## Client side — what is missing

`requests` is by a wide margin the most configurable thing we have: profiles,
full header order control, a TLS config record, proxies and proxy pools, DNS
pinning and interface binding, cookie jars, retries, streaming up and down,
multipart, concurrency, hooks, cross-session share, and a raw
`rawLong`/`rawStr` escape hatch applied last so the caller always wins. It is
also the only place in the stack that already implements the scope ladder
(profile → session → call). Everything below is measured against that bar.

### Correctness bugs the audit turned up

These are not roadmap items, they are defects:

- **`performOnce` calls `curl_easy_reset` before every transfer**, which wipes
  the session handle. So `useHttpVersion`, `useHttp3`, `useHttp3Only` and
  session-level `setOption` are effectively no-ops unless the same value is also
  routed through `cfg.rawLong`.
- **`Session.defaults` is dead** — declared and assigned, never read. There is no
  `mergeConfig` in the nimony port, so a session-default `RequestConfig` is
  silently ignored.
- **An unknown profile name silently falls back to chrome136** instead of
  reporting an error.
- **`Retry-After` is parsed as bare integer seconds only**; the HTTP-date form is
  silently ignored.
- **`Sink.body` grows one `char` at a time** — an O(n) append per received byte,
  with no preallocation knob.

### Regressions in the nimony port versus the Nim2 original

The nimony port gained real things (cert-chain inspection, cookie-file
persistence, thread-safe share, `COPYPOSTFIELDS` fixing a dangling-pointer
class of bug) but lost these, all of which exist in `src/`:

- **Per-request `timeoutMs` / `followRedirects` / `maxRedirs`** — session-scoped
  only in the port. This is the scope ladder breaking in the one library that
  had it.
- **`config.nim` entirely** — `merge`, `pinHost`, `connectVia`, `bindTo`,
  `useDns`, `forceIPv4/6`, `forceHttp`, `keepAuthAcrossHosts`, `autoReferer`,
  `keepPostOnRedirect`.
- **`fingerprint.nim` entirely** — `fetchFingerprint` / `report` / `matches`, the
  JA3/JA4/Akamai-H2 self-verification loop. Without it we cannot *prove* a
  profile still impersonates what it claims.
- **`info.nim` entirely** — per-phase timings. `ResponseInfo` drops
  `localIp`/`localPort`/`sizeDownload`/`sizeUpload`/speeds/`appConnect`/
  `preTransfer`/`redirectTime` **even though the INFO constants are already
  bound**.
- `baseUrl` + `resolveUrl`, `clone` for fleet spawning, `httpVersionStr`,
  `download`-to-file with partial-file cleanup, the Alt-Svc HTTP/3 policy, and
  hooks + `baseUrl` inside `fetchAll` (the concurrent path skips hooks entirely).

### Knobs absent because we never bound them

The single most important finding: **the vendored curl-impersonate fork exposes
the primitives for building a custom fingerprint, and we expose none of them.**
`TLS_EXTENSION_ORDER`, `TLS_GREASE`, `SSL_PERMUTE_EXTENSIONS`,
`SSL_SIG_HASH_ALGS`, `SSL_EC_CURVES`, `SSL_CERT_COMPRESSION`, `SSL_ENABLE_ALPS`,
`TLS_KEY_SHARES_LIMIT`, `TLS_RECORD_SIZE_LIMIT`, `TLS_SIGNED_CERT_TIMESTAMPS`,
`TLS_DELEGATED_CREDENTIALS`, `ECH` — plus the HTTP/2 fingerprint options
`HTTP2_SETTINGS`, `HTTP2_WINDOW_UPDATE`, `HTTP2_PSEUDO_HEADERS_ORDER`,
`HTTP2_STREAMS`. Our profile list being a closed 7-entry array is our
limitation, not curl's. A user cannot describe a browser we did not ship.

Also bound-by-the-library-but-not-by-us: connection pooling and reuse
(`MAXCONNECTS`, `FRESH_CONNECT`, `FORBID_REUSE`, `MAXAGE_CONN`,
`MAXLIFETIME_CONN`, `PIPEWAIT`, TCP keepalive, `TCP_NODELAY`, `TCP_FASTOPEN`),
`CURLMOPT_MAX_CONCURRENT_STREAMS` and server push, happy-eyeballs and DNS policy
(`HAPPY_EYEBALLS_TIMEOUT_MS`, `DNS_CACHE_TIMEOUT`, `DNS_SHUFFLE_ADDRESSES`,
`DOH_URL`), cert pinning and custom verification (`PINNEDPUBLICKEY`,
`SSL_CTX_FUNCTION`, `CRLFILE`, `SSL_VERIFYSTATUS`), TLS session
export/import (`curl_easy_ssls_export`/`_import` — explicit resumption),
cert/key blobs, unix-socket transport, HSTS and Alt-Svc (Alt-Svc is *declared*
in our FFI and never used), trailers, Expect-100 timeout, decompression control,
rate limiting, `MAXFILESIZE`, and every observability seam
(`DEBUGFUNCTION`, `XFERINFOFUNCTION`, `ERRORBUFFER`, `PREREQFUNCTION`,
`SOCKOPTFUNCTION`, `RESOLVER_START_FUNCTION`).

**WebSocket is a binding gap, not a curl gap** — `curl_ws_send`, `curl_ws_recv`,
`curl_ws_meta`, `CONNECT_ONLY` and `WS_OPTIONS` are all exported by the vendored
library and none are bound. Likewise `curl_easy_pause` (the missing backpressure
primitive), `curl_easy_duphandle` (a real `clone`), `curl_easy_send/recv`,
`curl_url_*`, `curl_easy_header/nextheader`, and `curl_easy_option_by_name`
— which would make a generic `setOption(name, value)` trivial.

Two structural consequences of what *is* missing: a `DataCb` returns `void` and
`streamCb` always reports full consumption, so **a consumer cannot abort a
transfer mid-body**; and a `ReadCb` can only return bytes or EOF, so returning 0
for "not ready yet" **truncates the request body** instead of pausing.

### Genuinely blocked by libcurl

Sub-record TLS shaping beyond `TLS_RECORD_SIZE_LIMIT`; raw QUIC transport
parameters and congestion control (ngtcp2 is inside the library, HTTP/3
configurability is `HTTP_VERSION_3 | 3ONLY` and nothing more); HTTP/2 frame-level
emission ordering beyond the fork's options; TLS keylog by API (env var only);
native continuation-based async (curl's model is a poll loop — a reactor shim on
our side is the only path); and external cancellation without going through a
callback.

### The native client

The server half of this stack is entirely our own code. The client half is
curl. That asymmetry is the reason five of the six items above are "blocked" —
they are blocked by *someone else's* library, which is exactly the thing this
stack exists to not depend on.

A native nimony client can reuse more than expected: `tls` already has the
client role, SNI, ALPN, hostname verification and a session handle for
resumption; `http` has the message model, URL parsing and chunked framing;
`serve/reactor.nim` is the async substrate; `ws` needs only its client-side
masking path; `quic/` already speaks ngtcp2. What it must add: an outbound
connection layer with a caching resolver and happy-eyeballs; a connection pool
keyed by (scheme, host, port, proxy, ALPN, client cert) with h2/h3 coalescing;
an HTTP/1.1 writer with byte-exact header order; a **client** HTTP/2 with
configurable SETTINGS and pseudo-header order (this is where Akamai-fingerprint
parity actually lives); a client HTTP/3 with an Alt-Svc cache; a data-driven
impersonation engine (GREASE, extension order, key shares, ALPS, cert
compression — needs `SSL_CTX`-level hooks `aoughwl-tls` does not have yet);
redirect/cookie/auth/decompression/HSTS engines; proxy CONNECT and TLS-in-TLS;
and cancellation plus backpressure as first-class API.

**The split we should commit to:** curl-impersonate stays the *stealth* path —
it owns the fingerprint and is genuinely hard to beat. The native client becomes
the *control* path: internal service calls, our own servers, tests, and anywhere
cancellation and backpressure matter. The first concrete step toward that is
unifying the types — `requests`' `Request`/`Response`/`Headers` and `http`'s are
today entirely disjoint, and no shared client work is possible until they aren't.

---

## The bar: what other stacks actually expose

"Better than other languages' entire networking stacks" needs a definition that
can be checked, not asserted. Here is what the mainstream stacks give a user,
which is the floor we have to clear before any of our own ideas count.

| Capability | Go | Rust (hyper/rustls) | Node | Java (Netty) | us, today |
|---|---|---|---|---|---|
| Read / write / idle / header timeouts | ✅ `Server` fields | ✅ per-builder | ✅ 4 separate | ✅ handlers | ⚠️ one read timeout, none in the reactor |
| Max header bytes / count | ✅ | ✅ | ✅ | ✅ | ❌ |
| Max body size | middleware | ✅ | middleware | ✅ | ⚠️ fixed 8 MiB |
| Graceful shutdown / drain | ✅ | ✅ | ✅ | ✅ | ❌ |
| Connection-state hook | ✅ `ConnState` | ✅ | ✅ | ✅ pipeline | ❌ |
| Structured error hook / logger | ✅ | ✅ | ✅ | ✅ | ❌ (`echo`) |
| Full TLS config on the server | ✅ | ✅ | ✅ | ✅ | ❌ (context is internal) |
| SNI callback / multi-cert | ✅ | ✅ | ✅ | ✅ | ⚠️ in `tls`, unreachable from `serve`; absent for H3 |
| Custom cert verification / pinning | ✅ | ✅ (`ServerCertVerifier`) | ✅ | ✅ | ❌ |
| mTLS (client certs) | ✅ | ✅ | ✅ | ✅ | ❌ |
| TLS key logging | ✅ `KeyLogWriter` | ✅ | ✅ | ✅ | ❌ |
| Session resumption / 0-RTT | ✅ / ✅ | ✅ / ✅ | ✅ / ✅ | ✅ / ✅ | ⚠️ TLS resumption only, no 0-RTT, none for QUIC |
| HTTP/2 settings (windows, streams, table) | ✅ | ✅ | ✅ | ✅ | ⚠️ one setting |
| HTTP/3 server | ✗ stdlib | ✅ (quinn/h3) | ✗ | ✅ incubator | ✅ |
| QUIC transport params / CC choice | — | ✅ quinn | — | ✅ | ❌ |
| WebTransport | ✗ | ⚠️ crates | ✗ | ⚠️ | ✅ datagrams + streams |
| Response streaming / SSE | ✅ | ✅ | ✅ | ✅ | ❌ |
| Per-request config override | ❌ | ❌ | ❌ | ⚠️ per-pipeline | ⚠️ client only |
| Raw escape hatch at every FFI edge | ⚠️ `Control` hook | ⚠️ partial | ⚠️ partial | ✅ | ⚠️ sockets + curl only |
| Browser-identical TLS/HTTP fingerprint | ❌ | ❌ | ❌ | ❌ | ✅ |

Read the table honestly: we already beat everyone on two axes that are hard to
retrofit — a real HTTP/3 + WebTransport server in the standard stack, and
browser-identical client fingerprinting — and we are *behind the floor* on the
boring operational axes that every production deployment needs on day one.

So "better than other stacks" resolves to three concrete claims we must be able
to make:

1. **Parity on the floor.** Every ✅ in that table is also a ✅ for us. No
   exceptions, no "use the low-level entry point instead".
2. **The scope ladder nobody else has.** Process → server → connection →
   request/stream override with one documented merge rule, uniformly, in every
   library. Go, hyper and Node all stop at the server or connection level.
3. **No silent limits and no unreachable knob.** Every bound is named,
   observable and loud when hit; every FFI boundary has a raw passthrough. The
   escape hatch is what makes "100%" a defensible claim rather than a race
   against other people's feature lists.

---

## The build order

Ordered by dependency, not by appeal. Phases 1 and 2 unlock everything after
them; doing any later phase first means doing it twice.

### Phase 0 — defects (not roadmap, just broken)

Independent of everything else, small, and each one currently makes a documented
feature a lie:

- `curl_easy_reset` wiping session-level options in `requests`
- dead `Session.defaults` / missing `mergeConfig`
- unknown profile name silently falling back to chrome136
- H3 request paths silently truncated at 511 bytes
- `sendto` return value discarded in the QUIC shim (silent packet loss under a
  full UDP send buffer)
- every silent-drop site: `cid_add`, `queue_request`, `enqueue_dgram`, the
  incoming-datagram ring, `conn_alloc`, HTTP/2 `allocStream`, HTTP/2 response
  headers past 39, oversized reactor requests
- `epollAdd`/`Mod`/`Del` discarding their return values
- `Sink.body` per-char growth

### Phase 1 — config records

**The prerequisite for the whole roadmap.** There is no config type anywhere in
the stack today, which is why every knob has been hardcoded at the call site.
Introduce, per library: `TcpOpts`, `TlsConfig` (server-side), `ParserLimits`,
`CodecOpts`, `WsConfig`, `ServerConfig`, `QuicConfig`, and make `requests`'
existing `RequestConfig` the model they all follow. Each is a plain object with
public fields, a `default*()` constructor whose values are readable, and a
`merge` following the scope ladder.

Also in this phase, because they are the same edit: `net` must re-export `tcp`,
and `serveTls`/`serveTlsConcurrent` must accept a caller-supplied `TlsContext`.
Those two changes alone move a large block of existing-but-unreachable knobs into
reach.

### Phase 2 — bounds, timeouts, and the reactor timer

Move every value from the hardcoded tables above into its Phase 1 record. The
one item here that is real engineering rather than mechanical: **the reactor has
no timer facility at all** (`epollWait(..., -1)`, one continuation per fd), so
read/write/idle/header timeouts for the async servers require a timer queue and a
deadline-aware wait — a scheduler change, and the gating item for the whole
timeout story. Also in scope: `onLimit` hooks so Phase 0's silent drops become
observable rather than merely non-silent.

### Phase 3 — escape hatches

Close the table in "The escape hatch rule": a raw `SSL_CTX*`/`SSL*` accessor on
`tls`, a transport-params + settings struct passed through the QUIC shim's C API,
a SETTINGS table passthrough for nghttp2, and codec parameter records for
zlib/brotli/zstd. After this phase, "we didn't wrap it" stops meaning "you can't
have it" anywhere in the stack — which is what makes the 100% claim defensible
before the wrapping work is finished.

### Phase 4 — protocol policy

The long tail, now cheap because Phases 1–3 built the carriers:

- **tls**: custom verify callback, cert pinning (`X509_digest` + raw DER + SAN),
  client certs in both roles, `SSL_CTX_set_options`/`set_mode`, 0-RTT, ticket
  and cache control, key logging, OCSP, CRL, group and sigalg selection, memory
  BIO, DER/in-memory/encrypted keys, bidirectional `close_notify`
- **quic**: transport parameters, congestion control selection, GnuTLS priority
  string, server SNI callback and multi-cert, Retry/address-validation tokens,
  0-RTT, IPv6, PMTU, qlog
- **http2**: the full SETTINGS set, window strategy, h2c upgrade, ALPN fallback
  to HTTP/1.1 instead of dropping the connection
- **http**: header count and body caps, trailers in both directions, header order
  and duplicate policy, custom reason phrases, q-value-aware `Accept-Encoding`
- **ws**: max frame and max message size (the most serious single gap in the
  stack), subprotocol negotiation, real extension negotiation with
  `max_window_bits` and context takeover, compression threshold and level,
  validation on the synchronous path, close-handshake timeout
- **compress**: windowBits, memLevel, strategy, dictionaries, brotli mode/lgwin,
  zstd advanced params, streaming, real error detail
- **tcp**: `CLOEXEC` everywhere (currently every fd leaks across `exec`),
  `accept4`, bind-before-connect, `sendmsg`/`recvmsg` and recv flags, multi-fd
  poll, `EPOLLET`, UDP and Unix domain sockets, real happy-eyeballs in `dial`

### Phase 5 — lifecycle and observability

Graceful shutdown and drain (needs a stop token plus a wakeup for threads blocked
in `accept()`), connection-state hooks, structured logging replacing `echo`,
error and panic hooks so one raising handler stops taking the process down,
access logs, metrics, tracing, and qlog for QUIC.

### Phase 6 — composability

The remaining architectural work: one handler and router shape across the
blocking, reactor, HTTP/2, HTTP/3 and WebSocket servers instead of five
incompatible ones; response streaming (needed for SSE and for not materializing
whole bodies); the H3 arbitrary-header FFI redesign; and retiring the
process-global handler pattern once the lambda-lifter limitation is fixed in the
compiler fork — that bug should be filed now, since it is the root cause of the
duplicated connection cores and the global-handler design.

### Phase 7 — the client

1. Restore the `src/` parity the nimony port lost (per-request scope, `config`,
   `fingerprint`, `info`, `clone`, `baseUrl`, Alt-Svc).
2. Bind the option sweep — everything in "absent because we never bound them",
   with `curl_easy_option_by_name` powering a generic `setOption(name, value)`.
3. **Open the fingerprint**: expose the extension-order / GREASE / ALPS / curve /
   cert-compression primitives and make profiles user-definable data, with
   `fingerprint.nim` restored so a profile can be *verified* rather than trusted.
4. Bind WebSocket, `curl_easy_pause`, and cancellation.
5. Unify `Request`/`Response`/`Headers` with `http`'s types.
6. Then, and only then, the native control-path client.

## Definition of done

The roadmap is complete when, for every library in the stack:

- no literal in the source is a policy decision a user might disagree with
- every bound is named, defaulted publicly, observable, and loud when hit
- every knob is settable at process, server, connection and request scope with
  one documented merge rule
- every FFI boundary has a raw passthrough
- the "what other stacks expose" table has no ⚠️ and no ❌ in our column
- and the client and server halves share one type model

