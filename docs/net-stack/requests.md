---
repo: aoughwl/requests
---

# requests — a browser-impersonating HTTP client

A native nimony HTTP client that impersonates real browsers at the byte level — TLS cipher/extension ordering, GREASE, the post-quantum key_share, ALPN/ALPS, HTTP/2 SETTINGS and pseudo-header order, and the exact default header set. It is a C-FFI binding over `libcurl-impersonate` (the lexiforest fork), driving a single `curl_easy_impersonate(target, 1)` call to install the whole fingerprint. Standalone: it does not use the rest of the aoughwl net stack, but the impersonation **requires** the vendored C library. It is a nimony-idiom reimplementation of the Nim2 client under `src/requests/` — status-based returns (no exceptions), top-level `{.cdecl.}`/`{.nimcall.}` callbacks (no closures), and caller-owned lifetimes.

> **Status** — Run-verified against httpbin.org (all verbs, 7 profiles, full header/TLS/proxy/cookie/streaming/multipart/concurrency/hooks/retry paths). Three items are deferred `TODO(nimony)`: cross-thread `CURLSH` lock callbacks (single-thread share works), file-IO cookie-jar auto-save (text dump/seed only), and the `INFO_CERTINFO` chain walker (the struct is bound but unported).

## Quickstart

```nim
import requests

let s = newSession("chrome136")            # falls back to builtins[0] if unknown
let r = s.get("https://httpbin.org/get")
echo r.status, " ", r.ok(), " ", r.contentType()

# full header control — verbatim order, or strip a browser default
discard s.get(url, cfg = orderedHeaders(@[("X-A", "1"), ("X-B", "2")]))
discard s.get(url, cfg = withoutHeaders(@["Accept-Language"]))

# auth + typed bodies
discard s.get(url, @[bearer("token")])
discard s.postForm(url, @[("user", "bob")])
discard s.postJson(url, """{"k":1}""")

# streaming, multipart, upload
discard s.download(url, onChunk, addr ctx)                 # {.nimcall.} sink
discard s.uploadString("PUT", url, bigBody)                # READFUNCTION stream
discard s.postMultipart(url, @[field("u", "bob"),
                               fileField("f", "/a.png")])   # curl owns the boundary

# proxy rotation, coherence audit, retry, concurrency
let pool = newProxyPool(@[proxyEntry("http://p1:8080")])
discard s.get(url, cfg = pool.pick().toConfig())
echo auditSession(s, myHeaders)                            # fingerprint tells
discard s.request("GET", url, retry = retryPolicy(maxAttempts = 3))
let rs = s.getAll(@[u1, u2, u3])                           # curl_multi, order kept
s.close()
```

`request` never raises: on a transport failure the returned `Response` has a non-empty `.error` and `.status == 0`.

## API

### Core types

| symbol | signature | what it does |
| --- | --- | --- |
| `Session` | `ref object` (`handle`, `profile`, `verifyTls`, `timeoutMs`, `followRedirects`, `maxRedirs`, `proxy*`, `cookieFile`, `share`, `extra`, `defaults`, `retry`, hooks) | Wraps ONE persistent curl easy handle reused across calls — connection reuse, TLS-session cache and cookie engine all live on it. |
| `Response` | `object` (`status`, `body`, `headers`, `setCookies`, `effectiveUrl`, `httpVersion`, `totalTime`, `info`, `error`) | Result of a transfer. `headers` keeps order + dups; `setCookies` are raw Set-Cookie values; non-empty `error` &rArr; transport failure. |
| `ResponseInfo` | `object` (`primaryIp`, `primaryPort`, `ttfb`, `nameLookup`, `connect`, `redirectCount`, `redirectUrl`) | Connection/transfer metrics pulled off the handle via getinfo. |
| `RequestConfig` | `object` (`headerOrder`, `removeHeaders`, `proxy`, `proxyAuth`, `proxyKind`, `noProxy`, `tls`, `resolve`, `connectTo`, `interfaceName`, `localPort`, `ipFamily`, `postRedir`, `unrestrictedAuth`, `autoReferer`, `rawLong`, `rawStr`) | Every advanced override a single request can carry. A default value inherits the session/profile — `RequestConfig()` changes nothing. |
| `TlsConfig` | `object` (`cipherList`, `tls13Ciphers`, `sslVersionMin/Max`, `alpn`, `verifyPeer/Host`, `caInfo`, `caPath`, `clientCert/Key`, `clientCertType`, `keyPassword`) | Opt-in TLS overrides applied on top of the profile. |
| `PreparedRequest` | `object` (`meth`, `url`, `body`, `headers`) | The mutable request a before-hook sees; editing fields changes the wire. |
| `RetryPolicy` | `object` (`maxAttempts`, `baseDelayMs`, `maxDelayMs`, `onTransport`, `on429`, `on5xx`, `honorRetryAfter`) | Opt-in retry/backoff config; `maxAttempts <= 1` &rArr; off. |
| `ProxyKind` | `enum pkAuto pkHttp pkHttps pkSocks4 pkSocks4a pkSocks5 pkSocks5h` | Proxy scheme; `pkAuto` lets curl infer it from the URL. |
| `IpFamily` | `enum ipAny ipV4 ipV6` | Address family; `ipAny` = happy-eyeballs. |
| `Tri` | `enum triInherit triOff triOn` | Tri-state whose default leaves the session/profile value. |
| `DataCb` | `proc(chunk: pointer, n: int, userdata: pointer) {.nimcall.}` | Per-chunk body sink for streaming `download`. |
| `ReadCb` | `proc(buf: pointer, cap: int, userdata: pointer): int {.nimcall.}` | Upload source: fill up to `cap` bytes, return count (0 &rArr; EOF). |
| `BeforeHook` / `AfterHook` | `proc(prep: ptr PreparedRequest, ud: pointer)` / `proc(resp: ptr Response, ud: pointer)` `{.nimcall.}` | Request/response interceptor proc types. |

### Sessions & requests

| symbol | signature | what it does |
| --- | --- | --- |
| `newSession` | `proc(profile = "chrome136", proxy = "", verifyTls = true, timeoutMs = 30000, followRedirects = true, maxRedirs = 10, proxyAuth = "", cookieFile = "", share: CURLSH = …, retry = RetryPolicy()): Session` | Create an impersonating session. Unknown profile &rArr; `builtins[0]`. Pass a `share` to pool state across sessions. |
| `close` | `proc(s: Session)` | Clean up the easy handle. |
| `request` | `proc(s, meth, url, body = "", headers = @[], nobody = false, cfg = RequestConfig(), retry = RetryPolicy()): Response` | Perform a request. Runs before/after hooks, honors retry; never raises. |
| `get` / `post` / `put` / `patch` / `delete` | `proc(s, url, [body,] headers = @[], cfg = RequestConfig()): Response` | Convenience verbs over `request`. |
| `head` | `proc(s, url, headers = @[], cfg = RequestConfig()): Response` | A real HEAD via `OPT_NOBODY`: status + headers, no body. |
| `options` | `proc(s, url, headers = @[], cfg = RequestConfig()): Response` | OPTIONS verb. |
| `retryPolicy` | `proc(maxAttempts = 3, baseDelayMs = 200, maxDelayMs = 20000, onTransport = true, on429 = true, on5xx = true, honorRetryAfter = true): RetryPolicy` | Build an opt-in retry policy (exponential backoff, Retry-After wins). |
| `onBeforeRequest` / `onAfterResponse` | `proc(s: Session, hook, userdata = …)` | Register a `{.nimcall.}` interceptor (runs in order; may mutate). |
| `sleepMs` | `proc(ms: int)` | libc `usleep` wrapper used by the backoff path. |

### Response inspection

| symbol | signature | what it does |
| --- | --- | --- |
| `ok` | `proc(r: Response): bool` | True for a 2xx status with no transport error. |
| `header` | `proc(r: Response, name: string): string` | Case-insensitive first-match header ("" if absent). |
| `headerAll` | `proc(r: Response, name: string): seq[string]` | Every value for `name` in wire order (multi-value safe). |
| `hasHeader` | `proc(r: Response, name: string): bool` | Whether the response carried `name`. |
| `headerNames` | `proc(r: Response): seq[string]` | Header names in server order (dups included). |
| `contentType` | `proc(r: Response): string` | Media type sans parameters, lowercased. |

### Header control

| symbol | signature | what it does |
| --- | --- | --- |
| `setHeader` | `proc(s: Session, name, value: string)` | Add/replace a session-default header (case-insensitive dedup). |
| `appendHeader` | `proc(s: Session, name, value: string)` | Append WITHOUT dedup (allows multi-value). |
| `removeHeader` | `proc(s: Session, name: string)` | Drop a session-default header. |
| `orderedHeaders` | `proc(pairs: seq[(string, string)]): RequestConfig` | A config whose `headerOrder` REPLACES the computed appended set with a verbatim, ordered list — byte-exact control. |
| `withoutHeaders` | `proc(names: seq[string]): RequestConfig` | A config that strips named curl-default headers (`Name:` with no value). |
| `mergedHeaders` | `proc(s: Session, headers = @[]): seq[(string, string)]` | Preview the final appended set: `profile.extraHeaders` &rarr; `session.extra` &rarr; call `headers`, deduped. |
| `mergeHeaders` | `proc(profile, session, call: seq[(string, string)]): seq[(string, string)]` | The underlying three-way merge (last wins). |

### Streaming, upload & multipart

| symbol | signature | what it does |
| --- | --- | --- |
| `download` | `proc(s, url, onData: DataCb, userdata: pointer, headers = @[], cfg = RequestConfig()): Response` | Stream the body to `onData(chunk, n, ud)` instead of buffering; Response has headers/status/timing but empty `body`. |
| `uploadStream` | `proc(s, meth, url, read: ReadCb, userdata: pointer, size: int64 = -1, headers = @[], cfg = RequestConfig()): Response` | Stream a body from a READFUNCTION; `size = -1` &rArr; chunked. |
| `uploadString` | `proc(s, meth, url, data: string, headers = @[], cfg = RequestConfig()): Response` | Convenience: stream `data` as the body via READFUNCTION. |
| `field` | `proc(name, value: string, contentType = ""): Part` | A plain multipart text field. |
| `fileField` | `proc(name, path: string, filename = "", contentType = ""): Part` | A file-upload field; curl streams from `path`, filename defaults to basename. |
| `postMultipart` | `proc(s, url, parts: seq[Part], headers = @[], cfg = RequestConfig()): Response` | POST a multipart/form-data body via `OPT_MIMEPOST` (curl owns the boundary). |
| `Part` | `object (name, filename, contentType, …)` | One multipart field; build with `field` / `fileField`. |

### Convenience helpers (util)

| symbol | signature | what it does |
| --- | --- | --- |
| `basicAuth` | `proc(user, password: string): (string, string)` | `Authorization: Basic <base64>` header tuple. |
| `bearer` | `proc(token: string): (string, string)` | `Authorization: Bearer <token>` header tuple. |
| `encodeUrl` | `proc(s: string): string` | Percent-encode (RFC 3986 unreserved kept); local encoder, no `std/uri`. |
| `encodeForm` | `proc(fields: seq[(string, string)]): string` | Build an `application/x-www-form-urlencoded` body. |
| `withQuery` | `proc(url: string, params: seq[(string, string)]): string` | Append params to `url` as a percent-encoded query string. |
| `postForm` | `proc(s, url, fields, headers = @[]): Response` | POST a urlencoded form (sets Content-Type). |
| `postJson` | `proc(s, url, body: string, headers = @[]): Response` | POST a raw JSON string (sets Content-Type: application/json). |

### TLS & evasion (tls)

| symbol | signature | what it does |
| --- | --- | --- |
| `insecureTls` | `proc(): TlsConfig` | Disable peer + host verification (testing only). |
| `withCA` | `proc(caInfo = "", caPath = ""): TlsConfig` | Trust a custom CA bundle file and/or directory. |
| `withClientCert` | `proc(cert, key: string, password = "", certType = "PEM"): TlsConfig` | Present a client certificate (mutual TLS). |
| `withAlpn` | `proc(on: bool): TlsConfig` | Toggle ALPN explicitly. |
| `customCiphers` | `proc(tls12List: string, tls13List = ""): TlsConfig` | Override cipher/ciphersuite lists. **Rewrites the ClientHello — breaks JA3/JA4.** |
| `pinTlsVersion` | `proc(minVer = 0, maxVer = 0): TlsConfig` | Pin TLS min/max. **Pinning MIN breaks the fingerprint.** |
| `withTls` | `proc(cfg: RequestConfig, tls: TlsConfig): RequestConfig` | Attach a TlsConfig to a RequestConfig (fluent). |
| `tlsConfig` | `proc(tls: TlsConfig): RequestConfig` | A RequestConfig carrying just this TlsConfig. |
| `auditTls` | `proc(cfg: RequestConfig): seq[string]` | Warnings for any TLS override that would break the fingerprint. Empty &rArr; ClientHello still the profile's. |

### HTTP version & low-level escape hatch

| symbol | signature | what it does |
| --- | --- | --- |
| `useHttpVersion` | `proc(s: Session, version: int)` | Pin the negotiated HTTP version via an `HTTP_VERSION_*` constant. |
| `useHttp3` | `proc(s: Session)` | Prefer HTTP/3 (QUIC), falling back to h2/1.1 (curl built with ngtcp2). |
| `useHttp3Only` | `proc(s: Session)` | Require HTTP/3 — fail rather than fall back. |
| `setOption` | `proc(s: Session, opt: CURLoption, value: clong)` / `(…, value: string)` | Set any un-wrapped CURLOPT on the handle now. |
| `getInfoStr` / `getInfoLong` / `getInfoDouble` | `proc(s: Session, info: CURLcode): string / int / float` | Read any curl getinfo metric off the handle. |

### Proxies (proxy)

| symbol | signature | what it does |
| --- | --- | --- |
| `PickStrategy` | `enum ppRoundRobin ppRandom` | Pool rotation strategy (`ppRandom` uses a local xorshift). |
| `ProxyEntry` | `object (url, auth, kind)` | A single proxy: URL + `user:password` + `ProxyKind`. |
| `ProxyPool` | `ref object (entries, strategy, idx, rngState)` | A rotating pool of proxies for a fleet. |
| `proxyEntry` | `proc(url: string, auth = "", kind = pkAuto): ProxyEntry` | Build a proxy entry. |
| `newProxyPool` | `proc(entries = @[], strategy = ppRoundRobin): ProxyPool` | Create a rotating pool. |
| `add` | `proc(pool: ProxyPool, url: string, auth = "", kind = pkAuto)` | Append a proxy to the pool. |
| `len` | `proc(pool: ProxyPool): int` | Pool size. |
| `pick` | `proc(pool: ProxyPool): ProxyEntry` | Next proxy per strategy (empty entry if pool empty). |
| `toConfig` | `proc(e: ProxyEntry): RequestConfig` | A RequestConfig selecting this proxy (per-request rotation). |
| `setProxy` | `proc(s: Session, e: ProxyEntry)` | Point a session at this proxy (session-level). |
| `rotate` | `proc(pool: ProxyPool, s: Session): ProxyEntry` | Advance the pool and bind the chosen proxy to the session. |

### Cookies (session engine)

| symbol | signature | what it does |
| --- | --- | --- |
| `Cookie` | `object (domain, includeSubdomains, path, secure, httpOnly, expires, name, value)` | A typed cookie over curl's in-memory engine. |
| `cookies` | `proc(s: Session): seq[Cookie]` | Every cookie in the session jar (`INFO_COOKIELIST`). |
| `cookie` | `proc(s, name: string, domain = ""): string` | Value of the first matching cookie ("" if absent). |
| `hasCookie` | `proc(s, name: string, domain = ""): bool` | Whether a matching cookie exists. |
| `setCookie` | `proc(s, cookie: Cookie)` / `proc(s, domain, name, value, path = "/", secure = false, httpOnly = false, expires = 0, includeSubdomains = false)` | Insert/replace a cookie (applied immediately, `OPT_COOKIELIST`). |
| `clearCookies` | `proc(s: Session)` | Erase all cookies (`ALL`). |
| `clearSessionCookies` | `proc(s: Session)` | Drop only session cookies (`SESS`). |
| `loadCookieLines` | `proc(s: Session, lines: seq[string])` | Seed the jar from Netscape cookie-file lines. |
| `dumpCookies` | `proc(s: Session): string` | The jar as Netscape cookie-file text. |
| `parseNetscapeLine` / `toNetscapeLine` | `proc(line: string): (Cookie, bool)` / `proc(c: Cookie): string` | Netscape cookie-file line round-trip. |

### Cookie jar manager (cookiejar)

| symbol | signature | what it does |
| --- | --- | --- |
| `CookieJar` | `ref object (bound: seq[Session])` | A programmatic management layer over a session's live engine. |
| `newCookieJar` | `proc(): CookieJar` | Create an unattached jar. |
| `attach` | `proc(s: Session, jar: CookieJar)` | Bind a jar to a session. |
| `isAttached` | `proc(jar: CookieJar): bool` | Whether the jar is bound. |
| `list` | `proc(jar: CookieJar, domain = ""): seq[Cookie]` | Cookies (optionally domain-filtered, suffix match). |
| `get` | `proc(jar: CookieJar, name: string, domain = ""): Cookie` | First matching cookie (empty `name` if absent). |
| `set` | `proc(jar, cookie)` / `proc(jar, domain, name, value, …)` | Insert/replace a cookie. |
| `delete` | `proc(jar: CookieJar, name: string, domain = "")` | Remove matches (rebuilds the jar without them). |
| `dumpText` / `seedText` | `proc(jar: CookieJar): string` / `proc(jar: CookieJar, text: string)` | Round-trip the whole jar to/from Netscape text. |

### Cross-session share (share)

| symbol | signature | what it does |
| --- | --- | --- |
| `Share` | `ref object (handle: CURLSH)` | A pool of browser-coherent state for several single-thread sessions. |
| `newShare` | `proc(cookies = true, dns = true, tlsSessions = true, connections = true): Share` | Create a `CURLSH` sharing cookies/DNS/TLS-session/connection cache. |
| `close` | `proc(sh: Share)` | Tear the share down (after every attached session is closed). |

### Concurrency (multi)

| symbol | signature | what it does |
| --- | --- | --- |
| `Request` | `object (meth, url, body, headers, cfg, nobody)` | One request in a concurrent batch. |
| `req` | `proc(url: string, meth = "GET", body = "", headers = @[], cfg = RequestConfig(), nobody = false): Request` | Build a batch request. |
| `fetchAll` | `proc(s: Session, reqs: seq[Request], maxConcurrent = 8): seq[Response]` | Run `reqs` concurrently over `curl_multi` (order preserved; one failure doesn't sink the batch). |
| `getAll` | `proc(s: Session, urls: seq[string], maxConcurrent = 8): seq[Response]` | GET a list of URLs concurrently. |

### Profiles (profiles)

| symbol | signature | what it does |
| --- | --- | --- |
| `Engine` | `enum eChromium eFirefox eSafari` | Browser engine family. |
| `Profile` | `object (name, target, engine, version, os, released, extraHeaders)` | An impersonation cohort as data; `target` is the curl-impersonate token. |
| `builtins` | `const array[7, Profile]` | The 7 profiles: `chrome136`, `chrome131`, `chrome131_android`, `edge101`, `firefox135`, `safari18_4`, `safari18_4_ios`. |
| `findProfile` | `proc(name: string): (bool, Profile)` | Look up a profile by name (found flag + value). |
| `get` | `proc(name: string): Profile` | Look up by name; default (empty `.name`) on miss. |
| `profileNames` | `proc(): string` | Comma-joined built-in names (diagnostics). |
| `acceptEncoding` | `proc(p: Profile): string` | The cohort's exact `Accept-Encoding`. |
| `epochDayOf` | `proc(iso: string): int` | Parse `yyyy-MM-dd` to days-since-epoch (-1 on bad input). |
| `ageDays` | `proc(p: Profile, asOfEpochDay: int): int` | Days between release and `asOf`. |
| `stale` | `proc(p: Profile, asOfEpochDay: int, maxAgeDays = 120): bool` | Whether the cohort is older than `maxAgeDays`. |
| `freshnessNote` | `proc(p: Profile, asOfEpochDay: int): string` | Human-readable freshness/staleness warning. |

### Coherence audit (coherence)

| symbol | signature | what it does |
| --- | --- | --- |
| `Warning` | `type = string` | A single coherence finding. |
| `audit` | `proc(p: Profile, headers: seq[(string, string)], proxyGeoLang = ""): seq[Warning]` | Lint headers against a profile: dup/managed/botty headers, UA-vs-engine, platform-vs-OS, Accept-Language-vs-geo, Firefox Sec-CH-UA. Empty &rArr; coherent. |
| `auditSession` | `proc(s: Session, headers = @[], proxyGeoLang = ""): seq[Warning]` | Audit everything a session would send against its active profile. |

### FFI (ffi)

The full libcurl-impersonate binding, re-exported by the umbrella. Opaque handle types `CURL`, `CURLM`, `CURLSH`, `curl_mime`, `curl_mimepart`; code types `CURLcode`/`CURLMcode`/`CURLSHcode`; option enums `CURLoption`/`CURLMoption`/`CURLSHoption`; and the `curl_slist`/`CurlSlistNode`/`CURLMsg` structs. Constant families: `OPT_*`, `INFO_*`, `PROXYTYPE_*` (0/2/4/5/6/7 = http/https/socks4/5/4a/5h), `AUTH_*`, `SSLVERSION_*`, `HTTP_VERSION_*` (`_1_0`/`_1_1`/`_2_0`/`_2TLS`/`_3`/`_3ONLY`), `LOCK_DATA_*`, `SHOPT_*`.

| symbol | signature | what it does |
| --- | --- | --- |
| `curl_easy_init` / `_cleanup` / `_reset` / `_perform` | over `CURL` | Handle lifecycle + synchronous transfer. |
| `curl_easy_setopt` / `_getinfo` | `{.varargs.}` over `CURL` | Set an option / read an info metric. |
| `curl_easy_impersonate` | `proc(handle: CURL, target: cstring, defaultHeaders: cint): CURLcode` | Install a browser's whole TLS+HTTP/2 fingerprint. |
| `curl_easy_strerror` / `errStr` / `curlOk` | code &rarr; string / bool | Error text and OK test. |
| `curl_slist_append` / `_free_all` | over `nil ptr curl_slist` | Build/free a header list. |
| `curl_mime_*` | `init`/`free`/`addpart`/`name`/`data`/`filedata`/`filename`/`type` | Multipart MIME construction. |
| `curl_multi_*` | `init`/`cleanup`/`add_handle`/`remove_handle`/`perform`/`poll`/`info_read`/`setopt` | The concurrent transfer interface. |
| `curl_share_*` | `init`/`cleanup`/`setopt`/`strerror` | Cross-session shared state. |
| `curl_global_init` | `proc(flags: clong): CURLcode` | One-time global init (driven by the client). |
| `cstrToString` | `proc(cs: cstring): string` | Walk a NUL-terminated C string into a nimony `string` (no `$`(cstring) in nimony). |

## Design notes

- **The fingerprint is installed inside the library.** A single `curl_easy_impersonate(target, 1)` call sets the exact TLS ordering, GREASE, key_share, ALPN/ALPS, HTTP/2 SETTINGS, pseudo-header order and default header set. Everything you layer on (headers, TLS knobs, HTTP version) risks *breaking* that coherence — hence `auditTls` and the coherence linter, which name the exact tells.
- **No exceptions.** Transport failures surface as `Response.error` (status 0); lookups return default/empty values, with a found-flag where the distinction matters. This is the aoughwl idiom throughout the stack.
- **Callbacks are top-level `{.nimcall.}`/`{.cdecl.}` procs, not closures**, always paired with an explicit `userdata: pointer` you cast back inside. The pointed-at object must outlive the synchronous `perform` — the streaming/upload/multi paths pre-size their sink seqs so element addresses stay valid.
- **Header precedence** (appended set, lowest&rarr;highest): `profile.extraHeaders` &rarr; `session.extra` &rarr; per-call `headers`, deduped last-wins — unless `orderedHeaders` replaces the whole computed set with a verbatim list.
- **One handle per session** (reuse = browser-like connection/TLS/cookie behavior); the concurrency path uses its own easy handles under `curl_multi` on a single thread — genuine I/O concurrency without OS threads or shared-handle hazards.
- **nimony gotchas**, learned porting: nilable pointers/refs need an explicit `nil ptr T`/`nil pointer` qualifier (plain forms are non-nil); `toCString` only on `var` string locals; POST bodies use `OPT_COPYPOSTFIELDS` so curl owns the copy; ASCII helpers char-walk (strutils slice ops are `.raises`); no `std/random` (local xorshift) or `std/uri` (local percent-encoder).

## Requirements

- **nimony toolchain** (aoughwl `aowl` / nimony). Umbrella `import requests` re-exports every module: `ffi`, `profiles`, `client`, `util`, `headers`, `tls`, `proxy`, `coherence`, `cookies`, `cookiejar`, `share`, `multi`.
- **`libcurl-impersonate`** (the lexiforest curl-impersonate fork, built with ngtcp2 for HTTP/3) — the impersonation is *not optional*; the browser fingerprint lives in this C library. Vendored under `vendor/curl-impersonate/lib`. Link it and set an rpath at build time (nimony has no compile-time rpath block):
  ```
  nimony c -r \
    --passl:-L.../vendor/curl-impersonate/lib \
    --passl:-Wl,-rpath,.../vendor/curl-impersonate/lib \
    --path:.../requests/nimony \
    yourprog.nim
  ```
- **Origin**: a nimony-native reimplementation of the Nim2 client under `src/requests/`, over the same libcurl-impersonate FFI. No dependency on the rest of the aoughwl net stack.
