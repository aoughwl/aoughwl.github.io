---
title: aiflib
grand_parent: Documentation
parent: Toolchain
nav_order: 7
---

# aiflib — the aowl system module + runtime
{: .no_toc }

`aiflib` is the standard `system` layer and the C runtime primitives the native
([aifc](nifc)) and JS ([aifjs](nifjs)) backends link against, so real programs —
strings, seqs, `echo`, ref objects with ARC — compile through the self-owned
stack **without** nimony's `system.c.aif`.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aiflib`** (public). Status: **working** — `echo "hello"` and
14 other programs (strings, string concat/build, `$`, seqs with bounds checks,
`ref` objects with ARC) compile to native binaries through [aifc](nifc) +
aiflib and pass an ASan/UBSan-clean, leak-free acceptance suite. This was the
biggest remaining unlock in the [aifmony](aifmony) rewrite.

## Why it's needed

By the time [aifhexer](aifhexer) has lowered a program, ARC calls and runtime
operations are *injected* into the `.c.aif` — they reference runtime symbols
that must exist at link time. Nimony gets them from its `system` compiled to
`.c.aif`; aiflib provides them as an aowl-owned C layer, and is what lets
`echo "hello"` compile **natively** instead of running under the interpreter
[nifi](../nifi).

## How linking works

Runtime symbols are **content-addressed**: `write.0.syn1lfpjv` is `write` from
the module hashed `syn1lfpjv`. aiflib is written once with hash-independent names
(`aiflib_write_string`, …); the linker `aiflib-cc` reads the *actual* symbols a
given `.c.nif` uses (undefined externs are exactly the referenced atoms carrying
a non-empty module hash), resolves each overload from the IR's types, and
injects a per-program shim that aliases the hashed names onto aiflib before
`gcc`-linking `runtime/aiflib.c`:

```
.c.nif ──aifc printer──▶ C ──inject shim──▶ gcc + aiflib.c ──▶ native binary
```

Any runtime symbol aiflib doesn't cover is reported as an explicit coverage
gap — the runtime is never silently stubbed.

## What shipped

- **C runtime** (`runtime/aiflib.{h,c}`): SSO strings (short/medium/long/static
  tiers per `stringimpl.nim`), `seq`, single-threaded ARC (`rc = refcount-1`),
  libc-backed allocator (`alloc`/`allocFixed`/`allocatedSize`), raw-fd IO
  (`write` string/char/int/uint/bool/float, `nimFlushStdStreams`), `$`
  formatters, and panics (`panic`/`nimIcheckB`/`oomHandler`). `LongString.data`
  is a **pointer** — one allocation per string, and exactly what aifc emits for
  a literal const (a flexible-array compound literal would reserve no storage).
- **`aiflib-cc`** (`bin/`): the `.c.nif → native` linker with IR-driven overload
  resolution and shim generation.
- **Acceptance suite** (`test/`): 15 programs asserting native output; runs from
  committed `.c.nif` (node + gcc) or `--regen` from `.nim` (nimony). 15/15.

Building it also completed three [aifc](nifc) printer points: forward
declarations for object/union structs, prototypes for inline procs, and the
`(ovf)` overflow-flag read.

## Next

1. String indexing (`s[i]`), float `$`, exceptions beyond `panic`.
2. **`system` module** in aowl source, compiled through the stack, replacing the
   hand-written C (which is its seed & oracle).
3. **stdlib** (`std/*`) on top as needed.
