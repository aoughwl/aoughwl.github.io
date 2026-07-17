---
title: TypeScript — aowlts
parent: aowlmony
nav_order: 9
---

# aowlts — idiomatic TypeScript backend
{: .no_toc }

An **idiomatic TypeScript** backend for [nimony](../nimony): Nim types become real
TypeScript types, not byte offsets.

> **Status: working core.** The emitter transpiles the computational core of the
> language end-to-end and runs **byte-identically to native nimony** on the test
> suite. Advanced features (closures, generic instantiation edge cases, macros)
> are the remaining work.

## Different from aowlweb

[aowlweb](aowlweb) already takes Nim to the web, but over a
**linear-memory model** — one `ArrayBuffer`, pointers are integers, objects are
byte offsets (`HEAP32[p>>2]`). Fast and faithful, but the output is asm.js-style,
not something a TypeScript developer would read or type-check. `aowlts` is the
opposite trade-off: **idiomatic, readable, fully-typed TS**.

| | aowlweb (nim-js) | aowlts |
|---|---|---|
| memory | one ArrayBuffer, offsets | real JS objects, engine GC |
| `object` | bytes at a byte offset | `interface` / `class` |
| `seq[T]` | header+data in the buffer | `T[]` |
| `string` | linear bytes | `string` |
| output | fast, faithful, asm-style | readable, typed, idiomatic |

They're **separate projects on purpose** — the one asset that unifies aowlweb
(the `jslayout` byte-layout engine) is exactly what an idiomatic backend throws
away.

## Planned architecture

The idiomatic mapping consumes nimony's **sem'd, pre-`hexer` NIF** — the `.s.nif`
artifact nimony already writes unconditionally — which is dramatically more
idiomatic than the post-`hexer` `.c.nif` that aowlweb consumes:

| construct | `.s.nif` (consumed here) | `.c.nif` (aowlweb) |
|---|---|---|
| `echo "x"` | `(cmd write stdout "x")` — literal intact | `LongString` refcount struct + SSO |
| `object` | nominal, named fields | bytes at a byte offset |
| `seq[T]` | generic `(at seq T)` | header+data+cap struct |
| `try`/`raise` | structured `TryS`/`RaiseS` | error-code returns + goto |

The Nim-semantic lowering is **shared** with `aowlpy` via
[aowlhl](aowlhl); `aowlts` is the thin emitter that renders the
High-Level IR into TypeScript.

## Architecture

`aowlts` mirrors the JavaScript emitter [aowljs](aowljs) node-for-node — same
HL-IR walk, same call-site intercepts — and adds a TypeScript **type layer** on
top. It consumes the three [aowlhl](aowlhl) modules:

- **`hlwalk`** — the grammar shape decoders (`decodeLocal` / `decodeParam(s)` /
  `decodeProc` / `decodeIf` / `decodeCase`) so the walk skeleton is shared, not
  re-implemented;
- **`hlclassify`** — routine-pragma classification (`hasImportc`) to skip foreign
  declarations;
- **`hlload`** — the user-module import graph + `moduleInitOrder`, so imported
  **user** modules are emitted in dependency-first order (their top-level init
  runs before the main module, matching native module-initialization order).

Two source files, mirroring the `aowljs` split:

- `src/emitts.nim` — the emitter (type mapping + node emission);
- `src/aowlts_cli.nim` — the ~60-line driver: load the main `.s.nif`, walk the
  import graph, concatenate `prelude + imported modules + main + flush`.

Each nimony symbol is mangled to a stable TS identifier, and a symbol is emitted
only in the pass for its **owning** module — so std/system generic-instance hooks
(the `seq` runtime, `=destroy`/`=copy`, …) are intercepted at call sites and never
leak into the output.

## Type mapping

| nimony | TypeScript |
|---|---|
| `int`, `int8`…`uint64`, `float`, `byte` | `number` |
| `string`, `cstring`, `char` | `string` |
| `bool` | `boolean` |
| `seq[T]`, `array[N, T]`, `openArray[T]` | `T[]` |
| `object` | `interface { … }` |
| `enum` | `enum { … }` (members qualified `E.Member`) |
| `tuple[a: X, b: Y]` | `[X, Y]` |
| `ref T` / `ptr T` | the underlying object type |
| `var`/`out` param | boxed accessor `{v: T}` (pass-by-reference) |

`let`/`const` are chosen from the binding's mutability (`var` → `let`, `let`/
`const` → `const`).

## What's covered

- literals: int / uint / float / char / string / bool;
- arithmetic, bitwise, comparison and boolean operators (with 32-bit wrap via
  `Math.imul` / `| 0` where the type is `int32`/`uint32`);
- `div`/`mod`, integer vs. float division;
- variables (`let`/`const` from mutability, typed), assignment;
- procs → typed `function`s (typed params & return), `result` variable, `return`;
- control flow: `if`/`elif`/`else`, `while`, `case` (as statement and as
  expression via an IIFE), `for` over ranges / `countdown` / collections, with one
  or two loop variables; `break` / `continue`;
- `object` → `interface`, object construction → object literal, field access;
- `enum` → real TS `enum`, qualified member references;
- `seq`/`array` literals, indexing, `len`, `add`, `newSeq`;
- string ops (`&`, `len`, `add`, `$`, case/trim/split/contains helpers);
- tuples (construction, indexing, tuple return types);
- `var`/`out` parameters via boxing;
- `echo` (→ a captured-output shim printed once at the end);
- multi-module programs (imported user modules emitted in dependency order).

## Build & run

```sh
NIM=/path/to/nimony            # a nimony checkout (v0.4.0)
$NIM/bin/nimony c -o:bin/aowlts \
  -p:$NIM/src/lib -p:$NIM/src/nimony -p:$NIM/src/models -p:$NIM/src/gear2 \
  -p:../aowlhl/src -p:src \
  src/aowlts_cli.nim

# produce a program's typed NIF (also runs it natively), then transpile:
$NIM/bin/nimony c -r --nimcache:/tmp/nc -f prog.nim
bin/aowlts /tmp/nc/<mainhash>.s.nif > prog.ts

# the emitted TS runs on node >= 23 (enums need --experimental-transform-types),
# or type-check with tsc / run with deno:
node --experimental-transform-types prog.ts
```

The test harness (`tests/run.sh`) compiles each `tests/*.nim` with nimony for the
reference stdout, transpiles it, runs the emitted `.ts` with node, and diffs.
Current suite: **8/8 byte-identical** (arithmetic, strings, seq+loops, control
flow, objects+enums, `var` params, `countdown`, tuples).

## Known limitations / TODO

- **enums** compile to real TS `enum`s, which are not erasable — plain
  `node --experimental-strip-types` rejects them; use
  `--experimental-transform-types`, `tsc`, or `deno`;
- **closures / first-class `{.closure.}` iterators** — not yet lowered;
- **user generic instantiations** that aren't intercepted at the call site are
  skipped (only the built-in `seq`/`string` machinery is currently intercepted);
- **`set[T]`** membership emits an inline `Set`/OR-chain (functional, not typed as
  a nominal set);
- **macros / compile-time execution**, `try`/`except`/`raise`, and `defer` are
  future work.
