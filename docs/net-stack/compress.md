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

> **Status** — Working and round-trip-tested for all three codecs (gzip, Brotli, Zstandard). One-shot only: no streaming/incremental API, and errors are collapsed to an empty-string sentinel rather than a distinguishable status. Decompression is bounded by a caller-supplied `maxSize` for Brotli/zstd.

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
```

## API

Every proc is `string -> string`. A returned `""` is the universal error sentinel
(and, trivially, the result of compressing/decompressing an empty input). Compress
procs take an optional codec-specific effort knob; decompress procs for the
capacity-based codecs take a `maxSize` output bound.

### gzip / zlib

Backed by `libz.so.1`, driven through a hand-laid `z_stream` matched to the LP64
ABI. Compression uses `deflate` with `windowBits` 31 (15 max window + 16 gzip
wrapper) to emit a gzip container; decompression uses `windowBits` 47 (15 + 32) to
auto-detect a gzip *or* zlib header. Output is streamed through a fixed 16 KiB
scratch buffer, so gzip needs no output-size estimate or `maxSize`.

| symbol | signature | what it does |
|---|---|---|
| `gzipCompress` | `proc gzipCompress(data: string; level = 6): string` | Compress `data` into the gzip format (`Content-Encoding: gzip`). `level` is the zlib effort 0–9. `""` on error. |
| `gzipDecompress` | `proc gzipDecompress(data: string): string` | Decompress a gzip (or zlib) payload, header auto-detected. No output bound. `""` on error. |

### Brotli

Backed by `libbrotlienc.so.1` / `libbrotlidec.so.1` via their one-shot
`BrotliEncoderCompress` / `BrotliDecoderDecompress` entry points. The encoder sizes
its output buffer with `BrotliEncoderMaxCompressedSize`; the decoder must be given
an upper bound on the decoded size.

| symbol | signature | what it does |
|---|---|---|
| `brotliCompress` | `proc brotliCompress(data: string; quality = 5): string` | Compress `data` with Brotli (`Content-Encoding: br`), generic mode, `lgwin` 22. `quality` is 0–11. `""` on error. |
| `brotliDecompress` | `proc brotliDecompress(data: string; maxSize = 16 * 1024 * 1024): string` | Decompress a Brotli payload into a `maxSize`-capped buffer. `""` on error or if the output would exceed `maxSize`. |

### Zstandard

Backed by `libzstd.so.1` via the one-shot `ZSTD_compress` / `ZSTD_decompress`
simple API. The encoder sizes output with `ZSTD_compressBound`; the decoder needs a
`maxSize` bound. Errors are detected with `ZSTD_isError`.

| symbol | signature | what it does |
|---|---|---|
| `zstdCompress` | `proc zstdCompress(data: string; level = 3): string` | Compress `data` with Zstandard (`Content-Encoding: zstd`). `level` is the zstd effort (typ. 1–22). `""` on error. |
| `zstdDecompress` | `proc zstdDecompress(data: string; maxSize = 16 * 1024 * 1024): string` | Decompress a Zstandard payload into a `maxSize`-capped buffer. `""` on error or if the output would exceed `maxSize`. |

## Design notes

- **One-shot, `string` boundaries.** Every codec takes and returns a whole
  `string`; there is no incremental/streaming state object. This keeps the API
  trivially reusable across protocols but means the entire input and output live in
  memory at once.
- **Empty string is the only error channel.** There are no exceptions and no status
  enum — a failed init, a corrupt stream, or a decode larger than `maxSize` all
  collapse to `""`. Callers that must distinguish "empty input" from "error" need to
  guard on `data.len` themselves.
- **Bounded decompression.** Brotli and zstd decoders pre-allocate a `maxSize`
  output buffer (default 16 MiB), a deliberate decompression-bomb guard. gzip streams
  through a fixed 16 KiB scratch buffer instead and is unbounded.
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
