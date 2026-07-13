---
title: compress
parent: net stack
grand_parent: Libraries
nav_order: 5
---

# compress — gzip / brotli / zstd codecs
{: .no_toc }

[Repo → aoughwl/compress](https://github.com/aoughwl/compress){: .btn }

One-shot, protocol-agnostic compression: `string → string`, no streaming state,
no HTTP assumptions. Its own repo so a WebSocket (`permessage-deflate`), a blob
store, or any binary protocol can depend on just the codecs.

```nim
import compress
let gz = gzipCompress("...")      # → gzipDecompress
let br = brotliCompress("...")    # → brotliDecompress
let zs = zstdCompress("...")      # → zstdDecompress
```

| Codec | Functions | Library |
|---|---|---|
| gzip / zlib | `gzipCompress` / `gzipDecompress` | `libz.so.1` |
| Brotli | `brotliCompress` / `brotliDecompress` | `libbrotlienc` / `libbrotlidec` |
| Zstandard | `zstdCompress` / `zstdDecompress` | `libzstd.so.1` |

Decompressors are bounded by a `maxSize` argument; `""` signals an error. The zlib
`z_stream` is hand-laid to the LP64 ABI (no headers); brotli/zstd use their
one-shot APIs. HTTP `Content-Encoding` negotiation lives one layer up in
[`http/contentcoding`](http).
