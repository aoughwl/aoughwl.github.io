---
repo: aoughwl/aowlabi
---

# aowlabi — the shared value-representation / ABI truth

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

The single canonical answer to *"how is each type laid out, per target."* Layout
is a fact about a program, not about a backend, and when each backend re-derives
it independently the copies drift. `aowlabi` holds the fact once.

Being canonical is a claim that has to be checkable, not a description. Its gate
diffs the layout engine against what the real nimony compiler lays out, reads
real heap blocks back through the offset table, and asserts the marshal
invariants over a generated corpus — **1090 checks in about 25 seconds**. See
[the gate](#the-gate) below for what that has caught.

> **Status: landed** · private repo. Consumed today by the
> [aowli](aowli) interpreter (`runtimelayer`, `hybridgen`, `arenamat`,
> `aowlcjit`). The [aowlc](aowlc) C backend does not read it yet and
> [aowljs](aowljs) does not exist yet — the JS representation row below is
> written for a port that has not happened. Access via Discord
> **timbuktu_guy**.

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

It covers the parts that are easy to forget, each one a place a hand-written
layout goes wrong:

| Construct | Rule |
|---|---|
| inheritance root | an `{.inheritable.}` object carries a hidden `ptr Rtti` word, so `object of RootObj` starts its own fields at `ptrSize`, not 0 |
| `set[T]` | a bitset — sized by the base type's **range**, not its width; always aligned to 1 |
| `{.packed.}` | no padding between fields, no tail round-up, and it imposes no alignment on whatever contains it |
| `{.union.}` | every field at offset 0; size of the fattest, alignment of the strictest |
| case object | branch fields all start at one union offset (`unionOffset`, `branchFieldOffsets`) |
| `UncheckedArray[T]` | contributes zero size but **does** impose its element's alignment — the shape of every heap block with a `data` tail |
| range type | laid out as its base, but a `set` over it is sized by its upper bound |
| `{.incompleteStruct.}` | the real size belongs to the C compiler; the engine says so rather than pretending |

### 2 · Canonical heap-block spec

Named offset constants for the compound heap types, so nobody hardcodes a magic
number:

| Block | Layout |
|---|---|
| string (SSO) | 16-byte small-string-optimized cell, 4 modes; spills to `LongString{fullLen, rc, cap, data}` |
| seq | `{len, data}` |
| ARC ref box | `{rc @ 0, data @ ptrSize}` |

One truth for these offsets means the interpreter allocating a string and the C
backend indexing into one are reading the identical map. Each offset is both a
64-bit constant and a rule taking `ptrSize`, and the gate checks the two agree
rather than assuming it. `LongString`'s four offsets are *computed* — it is
expressed as a descriptor (`{fullLen, rc, capImpl: int; data: UncheckedArray[char]}`)
and the gate checks the engine's field offsets against the constants, so they
are the layout of the struct they describe rather than four numbers that happen
to be right.

**One thing worth knowing if you decode `slen` yourself.** A string built at
runtime walks the SSO tiers by length and switches to the heap sentinel at 15
characters. A string *literal* does not: it is inlined only while it fits beside
`slen` in the first word (7 characters) and becomes a **static** `LongString`
past that, skipping the middle tier. So a 10-character value is one tier if you
built it and another if you wrote it, and a consumer has to handle both.

### 3 · Marshal matrix

Classifies each type by *how* it crosses a native boundary — by value, by buffer,
or by fallback — across the categories that matter:

| Category | Crosses as |
|---|---|
| scalar | by value |
| POD object / tuple | by value (flat) or by buffer |
| string | by buffer |
| seq | by buffer |
| `set[T]` | by buffer — a flat bitmap |
| ref / closure | fallback |
| case object, `{.union.}`, `{.incompleteStruct.}`, `UncheckedArray` | fallback |

The last row is the interesting one. A case object and a `{.union.}` do not say
which member is live, so copying their bytes means copying whichever
interpretation the far side then guesses at. An `{.incompleteStruct.}` has no
size anyone here knows. An `UncheckedArray` has no length in its type. None of
them can cross on a guess.

An aggregate hiding a **pointer** is refused for the same reason — an address
only means something inside the memory space it came from. A *bare* pointer is
still fine by value: an opaque handle crossing by address is what that is for.
The pointer-holding aggregate has its own route, the shared arena, where each
pointer leaf is rewritten to the arena address of the element it names.

Plus the JS representation mapping the JavaScript backend reads:

| nimony | JS |
|---|---|
| int | `number` |
| faithful 64-bit | `bigint` |
| char | 1-char `string` |
| tuple | positional array |
| object | object literal |
| ref | object ref |

## The gate

A library that only *claims* to be canonical is worth nothing, and the failure
mode here is silent divergence rather than a crash — a wrong size does not throw,
it corrupts something later. So each of the three parts is checked against
something outside itself. `tests/run.sh`, about 25 seconds:

| Part | Checked against | Count |
|---|---|---|
| layout | a true differential — one program prints what the real nimony compiler lays out, another prints what the engine computes from descriptors alone, and the two are diffed | 90 types |
| heap spec | real strings, seqs and refs built by the real compiler, read back *through* the offsets. No check hardcodes a number | 153 |
| marshal | invariants over every leaf kind wrapped in every aggregate shape, with a deliberately separate leaf scanner — checking the module's recursion against itself would prove nothing | 847 |

nimony implements neither `alignof` nor `offsetof`, so the differential measures
alignment structurally: the offset of `t` in `object (c: char, t: T)` *is*
`alignof(T)`. Variant branch offsets are reached by constructing the value once
per branch.

**Every rule was falsified before it was trusted** — put the bug back, watch the
gate redden, put it away again. Removing the rtti word reddens the inheriting
types; shifting the `LongString` data offset by one word reddens the string
checks; sizing a set by its base's width instead of its range reddens nine rows;
restoring an older pointer-as-POD bug reddens twenty marshal invariants. A gate
that has never failed proves nothing.

### What it found

Writing it was not a formality:

- **An inheritance root carries a hidden `ptr Rtti` word**, so `object of RootObj`
  starts its own fields at `ptrSize` rather than 0. The engine placed them at 0 —
  every offset and size of every inheriting object was wrong.
- **`set[T]`, `{.packed.}`, `{.union.}` and range types had no representation at
  all**, so a consumer meeting one had to work around it privately.
- **A constructor's default argument did not compile under nimony** — proof that
  no caller had ever instantiated it.
- **String literals do not follow the same SSO tiering as strings built at
  runtime**, described above.

## When the answer would be a guess

The size engine is total: it answers for any descriptor it is handed, including
one whose caller forgot to fill something in. That is the dangerous case — an
enum with no value range attached comes back as a confident "1 byte", which is
right only while that enum's highest value stays under 256.

`validate` names the descriptors whose answer is a guess rather than a
computation, with a path into the descriptor tree, so a consumer can check where
the descriptor is *built* instead of meeting a wrong number much later. It covers
range-less and inverted enums, zero-count arrays, missing element types,
`packed` and `union` set together, a flexible array member that is not last, and
`{.incompleteStruct.}`.

This caught a live bug in [aowli](aowli), which was mapping every enum onto a
range-less descriptor; it now carries the range.

## Why it matters

This is what makes [aowli](aowli)'s **hybrid mode** sound. In hybrid mode the
interpreter marshals values across a live boundary into natively-compiled code —
and the interpreter's marshaler and the C backend's codegen must agree on layout
*byte-for-byte*, or a single hybrid native call corrupts memory. Because both
sides read `aowlabi` instead of their own copy, they agree by construction rather
than by luck.

"By construction" is the part the gate exists to keep honest. Sharing a spec only
helps if the spec is right, and a layout library is exactly the kind of code that
can be plausible and wrong for a long time without anything falling over.

## Consumed by

[aowli](aowli) builds against it today, in `runtimelayer`, `hybridgen`,
`arenamat` and `aowlcjit`:

```
-p:.../aowlabi/src
import aowlabi
```

[aowlc](aowlc) and [aowljs](aowljs) are the intended readers and are not wired
up yet.

Repo: [github.com/aoughwl/aowlabi](https://github.com/aoughwl/aowlabi).
