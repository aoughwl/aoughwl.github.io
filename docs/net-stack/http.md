# http — transport-free HTTP

[Repo → aoughwl/http](https://github.com/aoughwl/http)
[Reference](../reference/http)

Headers, URL/query/form codecs, request parsing, typed methods and status codes,
response building, a chunked-transfer codec, and `Content-Encoding` negotiation —
with **no socket loop**. The same HTTP layer can back any transport.

| Module | Provides |
|---|---|
| `http/headers` | `Header` — a case-insensitive, total value type |
| `http/url` | percent-encode/decode, query/form parse & build |
| `http/request` | `parseRequest` — a pure string→`Request` parse |
| `http/response` | `Response`, `HttpCode` (`distinct int`, `is1xx`..`is5xx`, full reason table), `responseToString`, chunked encode/decode |
| `http/contentcoding` | `pickEncoding` (Accept-Encoding → `br`>`zstd`>`gzip`), `encodeFor`, `decodeFrom` — over the [`compress`](compress) codecs |

Consolidates what Nim 2 splits across `std/httpcore` and `std/uri`, and keeps the
HTTP-specific compression *policy* here while the raw codecs live in
[`compress`](compress).
