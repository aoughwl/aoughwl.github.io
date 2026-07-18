---
repo: aoughwl/http
---

# http — transport-free HTTP/1.x primitives

Pure HTTP logic with no sockets, no I/O, and no aoughwl-substrate dependency:
typed methods and status codes, header primitives, RFC 3986 URL/query/form
codecs, tolerant request parsing, response building, and a chunked-transfer
codec. It sits between `tcp`/`tls` and any server or client — `serve` is built
on it — so the same HTTP layer backs any transport. Standard-library only; the
optional `http/contentcoding` submodule adds `Content-Encoding` negotiation and
pulls in the `compress` package.

> **Status** — Production-ready and complete for HTTP/1.x message handling. Everything is status-based (nothing raises) and operates on caller-owned strings; `parseRequest` is tolerant rather than validating (malformed input yields empty fields, not errors). No streaming/incremental parser — the whole message is a `string`.

## Quickstart

```nim
import http

# Parse a raw request off the wire, dispatch, and build a reply.
let req = parseRequest(rawBytes)
if req.isMethod(HttpGet) and req.path.pathOnly == "/hello":
  let who = req.path.queryParam("name")   # "/hello?name=ada" -> "ada"
  let body = "hi " & (if who.len > 0: who else: "world")
  send responseToString(response(200, "text/plain", body))
else:
  send httpResponse(404, "text/plain", "not found")
```

## API

`import http` re-exports the `headers`, `url`, `request`, `response`, and
`httpmethod` submodules. `import http/contentcoding` is separate and opt-in.

### Types

| symbol | signature | what it does |
|---|---|---|
| `Header` | `object` with `name*, value*: string` | One header field; name matched case-insensitively, original spelling preserved. |
| `Request` | `object` with `meth*, path*, version*, body*: string; headers*: seq[Header]` | Parsed HTTP/1.x request. `path` is the raw request-target (may include `?query`). |
| `Response` | `object` with `status*: int; contentType*, body*: string; headers*: seq[Header]` | In-memory response model consumed by `responseToString`. |
| `HttpMethod` | `enum HttpUnknown, HttpGet, HttpHead, HttpPost, HttpPut, HttpDelete, HttpConnect, HttpOptions, HttpTrace, HttpPatch` | Typed request method (RFC 7231 / RFC 5789). `HttpUnknown` is the parse miss. |
| `HttpCode` | `distinct int` | Typed status code with class predicates and a reason-phrase `$`. |

### Methods

| symbol | signature | what it does |
|---|---|---|
| `toString` | `proc(m: HttpMethod): string` | Canonical upper-case token (`"GET"`…); `""` for `HttpUnknown`. |
| `` `$` `` | `proc(m: HttpMethod): string` | Alias for `toString`. |
| `parseHttpMethod` | `proc(s: string): HttpMethod` | Tolerant, case-insensitive parse; unrecognized tokens map to `HttpUnknown`. |
| `isMethod` | `proc(req: Request; m: HttpMethod): bool` | Typed method check against a parsed request. |

### Headers

| symbol | signature | what it does |
|---|---|---|
| `header` | `proc(name, value: string): Header` | Construct a `Header`. |
| `headerValue` | `proc(headers: seq[Header]; name: string): string` | First matching value (case-insensitive), or `""`. |
| `hasHeader` | `proc(headers: seq[Header]; name: string): bool` | Whether a non-empty value exists for `name`. |
| `lowerAscii` | `proc(s: string): string` | ASCII-only lower-casing. |
| `eqIgnoreCase` | `proc(a, b: string): bool` | ASCII case-insensitive equality. |
| `trimHttp` | `proc(s: string): string` | Trim leading/trailing spaces and horizontal tabs. |

### Request parsing

| symbol | signature | what it does |
|---|---|---|
| `parseRequest` | `proc(raw: string): Request` | Parse request line, headers, and post-blank-line body. Malformed input yields empty fields, never raises. |
| `isValidRequest` | `proc(req: Request): bool` | True when both `meth` and `path` are non-empty. |
| `isMethod` | `proc(req: Request; meth: string): bool` | String method check (case-insensitive). |
| `headerValue` | `proc(req: Request; name: string): string` | Convenience over `req.headers`. |
| `hasHeader` | `proc(req: Request; name: string): bool` | Convenience over `req.headers`. |

### Status codes

| symbol | signature | what it does |
|---|---|---|
| `reasonPhrase` | `proc(status: int): string` | Standard reason for a code; `""` for unknown (never a misleading `"OK"`). |
| `code` | `proc(n: int): HttpCode` | Wrap an int as `HttpCode`. |
| `toInt` | `proc(c: HttpCode): int` | Underlying integer. |
| `` `==` `` | `proc(a, b: HttpCode): bool` | Value equality. |
| `is1xx` … `is5xx` | `proc(c: HttpCode): bool` | Class predicates (`is1xx`, `is2xx`, `is3xx`, `is4xx`, `is5xx`). |
| `` `$` `` | `proc(c: HttpCode): string` | `"200 OK"`, or just the number when the code has no known phrase. |

### Response building

| symbol | signature | what it does |
|---|---|---|
| `response` | `proc(status: int; contentType, body: string): Response` | Build the in-memory response model. |
| `withHeader` | `proc(res: var Response; name, value: string)` | Append a header. |
| `responseToString` | `proc(res: Response; includeBody = true): string` | Serialize a full HTTP/1.1 response; auto-adds `Content-Type`, `Content-Length`, `Connection: close` unless already supplied. |
| `httpResponse` | `proc(status: int; contentType, body: string): string` | One-shot response builder. |
| `httpResponse` | `proc(status: int; contentType, body: string; headers: seq[Header]): string` | One-shot with extra headers. |
| `redirect` | `proc(location: string; status = 302): string` | Response with a `Location` header. |
| `optionsResponse` | `proc(allowed: string): string` | `204` with an `Allow` header (preflight/OPTIONS). |

### Chunked transfer

| symbol | signature | what it does |
|---|---|---|
| `encodeChunked` | `proc(body: string): string` | Encode as one chunk plus the zero-length terminator. |
| `decodeChunked` | `proc(s: string): string` | Decode a chunked payload back to the raw body; chunk extensions handled, trailers ignored. |

### URL, query & form codecs

| symbol | signature | what it does |
|---|---|---|
| `pathOnly` | `proc(target: string): string` | Request-target without `?query` or `#fragment`. |
| `queryString` | `proc(target: string): string` | Query portion without the leading `?`. |
| `percentDecode` | `proc(s: string; plusAsSpace = false): string` | RFC 3986 percent-decode; invalid `%xx` copied verbatim. |
| `percentEncode` | `proc(s: string; plusForSpace = false): string` | Percent-encode every non-unreserved byte; optional `+` for space. |
| `queryParam` | `proc(target, key: string): string` | First decoded value for `key` in the target's query, or `""`. |
| `formParam` | `proc(body, key: string): string` | Same lookup over an `application/x-www-form-urlencoded` body. |
| `queryParams` | `proc(q: string): seq[(string, string)]` | All decoded `key`/`value` pairs in order (duplicates preserved). |
| `encodeQuery` | `proc(pairs: openArray[(string, string)]): string` | Build a `k=v&k=v` string, form-urlencoded (`+` for space). |

### Content-Encoding — `import http/contentcoding`

Opt-in submodule; re-exports the `compress` package and adds HTTP negotiation
policy. Not pulled in by `import http`.

| symbol | signature | what it does |
|---|---|---|
| `pickEncoding` | `proc(acceptEncoding: string): string` | Best supported coding for an `Accept-Encoding` header: prefers `br`, then `zstd`, then `gzip`, else `""` (identity). |
| `encodeFor` | `proc(encoding, body: string): string` | Encode a body for a chosen `Content-Encoding`; unchanged for identity/unknown. |
| `decodeFrom` | `proc(encoding, body: string): string` | Decode a body received with the given `Content-Encoding`; unchanged for identity/unknown. |

## Design notes

- **Transport-free by design.** No socket loop, no filesystem, no aoughwl
  substrate — just `string` → `string` transformations. This is what lets one
  HTTP layer back `serve`, a client, or a test harness unchanged.
- **Nothing raises.** `parseRequest` is deliberately tolerant: a short or
  malformed message produces empty fields (check `isValidRequest`), and
  `reasonPhrase` returns `""` rather than inventing a phrase for an unknown code.
- **Caller-owned buffers, no slices.** nimony string slicing raises on
  out-of-range, so every parser/codec char-walks the input with explicit
  bounds and copies into fresh result strings — no aliasing, no hidden allocs
  on the caller's buffer.
- **Case-insensitive headers, preserved spelling.** Lookups fold ASCII case,
  but the original `name` is kept for emission and diagnostics.
- **Consolidates the stdlib split.** Covers ground Nim 2 spreads across
  `std/httpcore` and `std/uri` behind one import.

## Requirements

- nimony toolchain (Nim 3.0-class). The core (`http` and its submodules) is
  standard-library only — no C FFI, no external repos.
- `http/contentcoding` additionally depends on the aoughwl `compress` package
  (gzip / brotli / zstd codecs), which it re-exports.
