---
title: aowllib
grand_parent: Documentation
parent: Compiler Pipeline
nav_order: 4
---

# aowllib — the aowl system module + runtime
{: .no_toc }

`aowllib` is the standard `system` layer and the C runtime primitives the native
([aowlc](aowlc)) and JS ([aowljs](aowljs)) backends link against, so real programs —
strings, seqs, `echo`, ref objects with ARC — compile through the self-owned
stack **without** nimony's `system.c.aif`.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aowllib`** (public). Status: **working** — `echo "hello"` and
39 other programs compile to native binaries through [aowlc](aowlc) + aowllib and
pass a **40/40, ASan/UBSan/LSan-clean, leak-free** acceptance suite. Covered:
strings (concat/build, `$`, char index, `==`/`<`/`<=`/`cmp`, `case`-on-string,
`for c in s` iteration, `s[a..b]` slicing, `s[i] = c` mutation with copy-on-write,
`newString`), seqs (growth, nesting, `[]=`, return-by-value, equality, bounds
checks), value / `ref` / **case (variant)** objects, non-zero-based arrays with
bounds panics, fixed arrays, `INT64_MIN` and SSO tier boundaries. This was the
biggest remaining unlock in the [aowlmony](aowlmony) rewrite.

## Why it's needed

By the time [aowlhexer](aowlhexer) has lowered a program, ARC calls and runtime
operations are *injected* into the `.c.aif` — they reference runtime symbols
that must exist at link time. Nimony gets them from its `system` compiled to
`.c.aif`; aowllib provides them as an aowl-owned C layer, and is what lets
`echo "hello"` compile **natively** instead of running under the interpreter
[aowli](../aowli).

## How linking works

Runtime symbols are **content-addressed**: `write.0.syn1lfpjv` is `write` from
the module hashed `syn1lfpjv`. aowllib is written once with hash-independent names
(`aowllib_write_string`, …); the linker `aowllib-cc` reads the *actual* symbols a
given `.c.nif` uses (undefined externs are exactly the referenced atoms carrying
a non-empty module hash), resolves each overload from the IR's types, and
injects a per-program shim that aliases the hashed names onto aowllib before
`gcc`-linking `runtime/aowllib.c`:

```
.c.nif ──aowlc printer──▶ C ──inject shim──▶ gcc + aowllib.c ──▶ native binary
```

Any runtime symbol aowllib doesn't cover is reported as an explicit coverage
gap — the runtime is never silently stubbed.

## What shipped

- **C runtime** (`runtime/aowllib.{h,c}`): SSO strings (short/medium/long/static
  tiers per `stringimpl.nim`) with index/slice/mutate (copy-on-write) and
  `==`/`<`/`<=`/`cmp`; `seq` with `recalcCap` growth; single-threaded ARC
  (`rc = refcount-1`); libc-backed allocator; raw-fd IO
  (`write` string/char/int/uint/bool/float, `nimFlushStdStreams`); `$`
  formatters; and all four bounds checks (`nimIcheckB`/`nimIcheckAB`/
  `nimUcheckB`/`nimUcheckAB`) plus `panic`/`oomHandler`. `LongString.data` is a
  **pointer** — one allocation per string, and exactly what aowlc emits for a
  literal const (a flexible-array compound literal would reserve no storage).
- **`aowllib-cc`** (`bin/`): the `.c.nif → native` linker with IR-driven overload
  resolution and shim generation. For ops whose type is program-local — string
  `for c in s` (`toOpenArray`) and `s[a..b]` (`[]`(HSlice)) — it emits a real
  wrapper *after* the type section instead of a `#define`. It compiles with
  `-Werror=implicit-function-declaration` so a missing runtime prototype (which
  would silently truncate a 64-bit pointer return) is a hard error.
- **Acceptance suite** (`test/`): 40 programs asserting native output; runs from
  committed `.c.nif` (node + gcc) or `--regen` from `.nim` (nimony). 40/40,
  ASan/UBSan/LSan-clean.

Building it also completed five [aowlc](aowlc) printer points: forward
declarations for object/union structs, prototypes for inline procs, the `(ovf)`
overflow-flag read, **value-dependency ordering of type declarations** (a struct
with a by-value field of another struct is emitted after it), and **case-object
variant records** as anonymous C11 unions.

## Next

1. `object of RootObj` inheritance / method dispatch (the `RootObj`/`Rtti`
   type-info subsystem + vtables); float `$`; exceptions beyond `panic`.
2. **`system` module** in aowl source, compiled through the stack, replacing the
   hand-written C (which is its seed & oracle).
3. **stdlib** (`std/*`) on top as needed.
