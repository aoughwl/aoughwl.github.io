---
repo: aoughwl/compress
---

# compress — one-shot gzip / brotli / zstd codecs

Raw, protocol-agnostic compression codecs for the aoughwl networking stack:
plain `string` in, `string` out, with no streaming state and no HTTP assumptions.
It sits at the bottom of the stack with zero dependencies on other stack repos —
extracted from `http` so a WebSocket (`permessage-deflate`), a blob store, or any
binary protocol can depend on just the codecs. It FFIs directly to the system
`libz`, `libbrotli*`, and `libzstd`.

> **Status** — Working and round-trip-tested for all three codecs (gzip, Brotli, Zstandard). One-shot only: no streaming/incremental API (by design — see the streaming note below). All three decompressors are now bounded by a caller-supplied `maxSize` (default 16 MiB), including gzip, which previously inflated unbounded. Errors are still collapsed to an empty-string sentinel by the string-returning procs, but the `try*` variants now return an explicit `(ok, data)` status so a failure is distinguishable from a legitimately-empty result.

## Quickstart

```nim
import compress

let original = "the quick brown fox jumps over the lazy dog. " & "..."

let gz = gzipCompress(original)            # Content-Encoding: gzip
assert gzipDecompress(gz) == original

let br = brotliCompress(original, quality = 5)   # Content-Encoding: br
assert brotliDecompress(br) == original

let zs = zstdCompress(original, level = 3)       # Content-Encoding: zstd
assert zstdDecompress(zs) == original

# "" signals an error (bad payload, allocation failure, or decoded size > maxSize):
if gzipDecompress(corrupt) == "":
  echo "decode failed"

# ...but "" is ambiguous — use the try* variant to tell failure from empty:
let r = tryGzipDecompress(payload, maxSize = 1 * 1024 * 1024)
if r.ok:
  echo "decoded ", r.data.len, " bytes"   # r.data may legitimately be ""
else:
  echo "decode failed or exceeded the 1 MiB cap"
```

## API

Two flavours per operation. The string-returning procs are `string -> string` and
use `""` as the universal error sentinel (ambiguous with an empty result). The
`try*` procs return a `CompressResult` object so success and failure are explicit;
the string procs are thin wrappers over them.

```nim
type CompressResult* = object
  ok*: bool     ## success signal; false on any error
  data*: string ## payload (empty and ok=true when the INPUT was empty)
```

Empty **input** always succeeds: `ok = true`, `data = ""`. A genuine failure gives
`ok = false`, `data = ""`. Compress procs take an optional codec-specific effort
knob; every decompress proc takes a `maxSize` output bound (default 16 MiB).

### gzip / zlib

Backed by `libz.so.1`, driven through a hand-laid `z_stream` matched to the LP64
ABI. Compression uses `deflate` with `windowBits` 31 (15 max window + 16 gzip
wrapper) to emit a gzip container; decompression uses `windowBits` 47 (15 + 32) to
auto-detect a gzip *or* zlib header. Output is streamed through a fixed 16 KiB
scratch buffer; the running output length is checked against `maxSize` on every
block so a decompression bomb is aborted before it is materialised.

| symbol | signature | what it does |
|---|---|---|
| `gzipCompress` | `proc gzipCompress(data: string; level = 6): string` | Compress `data` into the gzip format (`Content-Encoding: gzip`). `level` is the zlib effort 0–9. `""` on error. |
| `gzipDecompress` | `proc gzipDecompress(data: string; maxSize = 16 * 1024 * 1024): string` | Decompress a gzip (or zlib) payload, header auto-detected. `""` on error or if the output would exceed `maxSize`. |
| `tryGzipCompress` | `proc tryGzipCompress(data: string; level = 6): CompressResult` | As `gzipCompress`, returning `(ok, data)` so failure is distinguishable from empty. |
| `tryGzipDecompress` | `proc tryGzipDecompress(data: string; maxSize = 16 * 1024 * 1024): CompressResult` | As `gzipDecompress`, with an explicit `ok` flag; `ok = false` if the payload inflates past `maxSize`. |

### Brotli

Backed by `libbrotlienc.so.1` / `libbrotlidec.so.1` via their one-shot
`BrotliEncoderCompress` / `BrotliDecoderDecompress` entry points. The encoder sizes
its output buffer with `BrotliEncoderMaxCompressedSize`; the decoder must be given
an upper bound on the decoded size.

| symbol | signature | what it does |
|---|---|---|
| `brotliCompress` | `proc brotliCompress(data: string; quality = 5): string` | Compress `data` with Brotli (`Content-Encoding: br`), generic mode, `lgwin` 22. `quality` is 0–11. `""` on error. |
| `brotliDecompress` | `proc brotliDecompress(data: string; maxSize = 16 * 1024 * 1024): string` | Decompress a Brotli payload into a `maxSize`-capped buffer. `""` on error or if the output would exceed `maxSize`. |
| `tryBrotliCompress` | `proc tryBrotliCompress(data: string; quality = 5): CompressResult` | As `brotliCompress`, returning `(ok, data)`. |
| `tryBrotliDecompress` | `proc tryBrotliDecompress(data: string; maxSize = 16 * 1024 * 1024): CompressResult` | As `brotliDecompress`, with an explicit `ok` flag. |

### Zstandard

Backed by `libzstd.so.1` via the one-shot `ZSTD_compress` / `ZSTD_decompress`
simple API. The encoder sizes output with `ZSTD_compressBound`; the decoder needs a
`maxSize` bound. Errors are detected with `ZSTD_isError`.

| symbol | signature | what it does |
|---|---|---|
| `zstdCompress` | `proc zstdCompress(data: string; level = 3): string` | Compress `data` with Zstandard (`Content-Encoding: zstd`). `level` is the zstd effort (typ. 1–22). `""` on error. |
| `zstdDecompress` | `proc zstdDecompress(data: string; maxSize = 16 * 1024 * 1024): string` | Decompress a Zstandard payload into a `maxSize`-capped buffer. `""` on error or if the output would exceed `maxSize`. |
| `tryZstdCompress` | `proc tryZstdCompress(data: string; level = 3): CompressResult` | As `zstdCompress`, returning `(ok, data)`. |
| `tryZstdDecompress` | `proc tryZstdDecompress(data: string; maxSize = 16 * 1024 * 1024): CompressResult` | As `zstdDecompress`, with an explicit `ok` flag. |

## Design notes

- **One-shot, `string` boundaries.** Every codec takes and returns a whole
  `string`; there is no incremental/streaming state object. This keeps the API
  trivially reusable across protocols but means the entire input and output live in
  memory at once. A streaming API (feeding fixed-size blocks through a retained
  `z_stream` / `ZSTD_DCtx`) is deliberately out of scope — layer it separately if you
  need to bound memory below `maxSize` for very large payloads.
- **Two error channels.** The string-returning procs collapse a failed init, a
  corrupt stream, or a decode larger than `maxSize` to `""` — which is ambiguous with
  a legitimately-empty result. The `try*` procs resolve that: they return
  `CompressResult(ok, data)`, where empty **input** is a success (`ok = true`,
  `data = ""`) and any failure is `ok = false`, `data = ""`.
- **Bounded decompression, all codecs.** Every decoder respects `maxSize` (default
  16 MiB) as a decompression-bomb guard. Brotli and zstd pre-allocate a `maxSize`
  output buffer; gzip streams through a fixed 16 KiB scratch buffer and checks the
  running output length against `maxSize` on every block, aborting before an oversized
  output is materialised. (gzip was previously unbounded — that hole is closed.)
- **Hand-laid zlib ABI.** The `z_stream` struct is written out field-by-field to the
  LP64 layout (size 112) rather than pulling in zlib headers, and gzip/zlib framing
  is selected purely through `windowBits`. Brotli and zstd instead lean on each
  library's own bound/one-shot helpers.
- **Protocol-agnostic.** No knowledge of HTTP; `Content-Encoding` negotiation lives
  one layer up in `http`.

## Requirements

- The nimony toolchain (aoughwl `aowl` / nimony).
- System shared libraries, loaded via `dynlib` at runtime:
  - `libz.so.1` (zlib) — gzip.
  - `libbrotlienc.so.1` and `libbrotlidec.so.1` — Brotli.
  - `libzstd.so.1` — Zstandard.
- No dependency on any other aoughwl stack repo.
