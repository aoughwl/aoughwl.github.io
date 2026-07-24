---
repo: aoughwl/aowlabi
---

# aowlabi — the shared value-representation / ABI truth

The single canonical answer to *"how is each type laid out, per target."* Before
`aowlabi`, three places each kept their own copy of that answer — the
[aowli](aowli) interpreter, the [aowlc](aowlc) C backend, and the
[aowljs](aowljs) JavaScript backend — and the three copies drifted. `aowlabi` is
the one spec they all read, so they agree by construction.

> **Status: landed** · private repo. Consumed by `aowlc`, `aowljs`, and `aowli`
> today. Access via Discord **timbuktu_guy**.

## Why this repo exists

Layout is a fact about a program, not about a backend — the size of a `seq`, the
offset of a variant's discriminator, the shape of a string header. When each
backend re-derives that fact independently, they slip out of sync, and the moment
one boundary uses a layout another disagrees with, data corrupts silently.
`aowlabi` moves the fact to one place. The interpreter's marshaler and the C
backend's codegen read the *same* offsets, so a value written by one and read by
the other is byte-for-byte compatible — no coordination, no drift.

## Three parts

### 1 · Size / alignment / field-offset engine

One implementation of the C-struct layout rules — align, pad, finish; the object
base-size prefix; array stride; the recursive walk over tuple and variant
members. It's parameterized by pointer size, so the same rules give you the
32-bit and 64-bit answers from one source. A caller works against an abstract
type descriptor and maps its own type representation onto it, so nothing about a
particular backend's IR leaks in.

### 2 · Canonical heap-block spec

Named offset constants for the compound heap types, so nobody hardcodes a magic
number:

| Block | Layout |
|---|---|
| string (SSO) | 16-byte small-string-optimized cell, 4 modes; spills to `LongString{fullLen, rc, cap, data}` |
| seq | `{len, data}` |
| ARC ref box | `{rc @ 0, data @ ptrSize}` |

One truth for these offsets means the interpreter allocating a string and the C
backend indexing into one are reading the identical map.

### 3 · Marshal matrix

Classifies each type by *how* it crosses a native boundary — by value, by buffer,
or by fallback — across the categories that matter:

| Category | Crosses as |
|---|---|
| scalar | by value |
| POD object / tuple | by value (flat) or by buffer |
| string | by buffer |
| seq | by buffer |
| ref / closure | fallback |

Plus the JS representation mapping the JavaScript backend reads:

| nimony | JS |
|---|---|
| int | `number` |
| faithful 64-bit | `bigint` |
| char | 1-char `string` |
| tuple | positional array |
| object | object literal |
| ref | object ref |

## Why it matters

This is what makes [aowli](aowli)'s **hybrid mode** sound. In hybrid mode the
interpreter marshals values across a live boundary into natively-compiled code —
and the interpreter's marshaler and the C backend's codegen must agree on layout
*byte-for-byte*, or a single hybrid native call corrupts memory. Because both
sides read `aowlabi` instead of their own copy, they agree by construction rather
than by luck.

## Consumed by

`aowlc`, `aowljs`, and `aowli` all build against it:

```
-p:.../aowlabi/src
import aowlabi
```

Repo: [github.com/aoughwl/aowlabi](https://github.com/aoughwl/aowlabi).
