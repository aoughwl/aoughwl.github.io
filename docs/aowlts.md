# aowlts — idiomatic TypeScript backend

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

> In **faithful mode** (below) the width-64 integer types `int` / `int64` /
> `uint` / `uint64` map to **`bigint`** instead of `number`; the narrower widths
> (`int8`…`int32`, `uint8`…`uint32`, `byte`, `char`) stay `number`.

## Faithfulness / export modes

`aowlts` has two output modes. The default is **fast mode**; `--faithful` opts
into a numerically exact one. Fast mode stays the default because its output is
the most idiomatic and the fastest — most programs never touch the boundary
where it diverges.

| | fast mode (default) | `--faithful` |
|---|---|---|
| every nimony int | JS `number` | 64-bit → `bigint`, narrower → `number` |
| exact past 2^53 | **no** (silently rounds) | **yes** |
| int64 / uint64 overflow | wrong (no wrap) | wraps (two's complement) |
| speed / readability | fastest, cleanest | a touch heavier (bigint ops) |

### Why fast mode is silently wrong

JS `number` is an IEEE-754 double: it holds integers exactly only up to 2^53.
A nimony `int64` past that rounds, and `int64`/`uint64` arithmetic never wraps.
Compile this with nimony and with each mode:

```nim
var a: int64 = 9223372036854775807'i64   # INT64_MAX
echo a
echo a + 1'i64                            # wraps to INT64_MIN
var u: uint64 = 18446744073709551615'u64  # UINT64_MAX
echo u
```

| line | nimony (reference) | `--faithful` | fast mode |
|---|---|---|---|
| `a` | `9223372036854775807` | `9223372036854775807` ✅ | `9223372036854776000` ❌ |
| `a + 1` | `-9223372036854775808` | `-9223372036854775808` ✅ | `9223372036854776000` ❌ |
| `u` | `18446744073709551615` | `18446744073709551615` ✅ | `18446744073709552000` ❌ |

Faithful mode is **byte-for-byte identical to native nimony**; fast mode is off
by hundreds and never wraps.

### The design: native `bigint`, zero dependencies

JS has had `BigInt` as a language primitive since ES2020 — it works in Node,
Deno and the browser with **no addon and no import**. Its operators are the
ordinary ones (`a + b`, `a < b`, `a === b`), and its `/` and `%` **truncate
toward zero exactly like Nim integer division**. Faithful mode leans on that:

- **64-bit types → `bigint`.** A `bigint` literal carries the `n` suffix
  (`123n`); the emitter threads a "want-bigint" context so every literal in a
  64-bit position is emitted as `bigint` (JS throws on mixing `5n + 5`).
- **Width wrapping.** 64-bit `add`/`sub`/`mul`/`shl` and the bitwise ops are
  wrapped with the built-in `BigInt.asIntN(64, x)` (signed) / `asUintN(64, x)`
  (unsigned) — that is exactly Nim's two's-complement wrap-around.
- **Division.** `div` → `_idiv(a, b)`, `mod` → `_imod(a, b)` — bigint `/` and `%`
  already truncate toward zero, so the helpers only add the Nim `DivByZero` check.
- **Crossing widths.** A `number` value entering a 64-bit position is coerced
  `BigInt(x)` (a float first `BigInt(Math.trunc(x))`); a `bigint` used where a
  `number` is needed — array indices, narrower ints — is coerced `Number(x)`.
- **`echo`.** A `bigint` prints through `String(x)`, i.e. `5n` renders `5`, not
  `5n` — output matches nimony with no special-casing.

### Runtime helpers

Faithful mode needs four tiny helpers. They are **inlined into the emitted
program's prelude**, so a single emitted `.ts` file still runs standalone with no
import:

```ts
const _i64  = (x: bigint): bigint => BigInt.asIntN(64, x);
const _u64  = (x: bigint): bigint => BigInt.asUintN(64, x);
const _idiv = (a: bigint, b: bigint): bigint => { if (b === 0n) throw new Error("DivByZero"); return a / b; };
const _imod = (a: bigint, b: bigint): bigint => { if (b === 0n) throw new Error("DivByZero"); return a % b; };
```

The same four are also exported from **`runtime/aowl-rt.ts`** for real projects
that prefer to `import` one shared copy rather than rely on the inlined prelude.

### Invoking it

```sh
bin/aowlts --faithful /tmp/nc/<mainhash>.s.nif > prog.ts
node --experimental-transform-types prog.ts
```

`tests/run_faithful.sh` compiles each `tests/faithful/*.nim` with nimony for the
reference stdout, transpiles it with `--faithful`, runs the emitted `.ts` under
node, and diffs — **byte-exact** — while also showing that fast mode gets the same
programs wrong (the whole point). Suite: `overflow` (INT64_MAX / MIN, UINT64_MAX),
`modmul` (products past 2^53 in a modular loop), `divmod` (truncating `div`/`mod`,
signed and unsigned).

### Boundary — what faithful mode does *not* fix

Faithful mode is about **numeric** faithfulness. Two other faithfulness axes are
deliberately out of scope:

- **Value semantics.** Nim copies `object`/`tuple`/`seq` values on assignment and
  argument passing; the idiomatic TS emitter shares references (like the fast
  mode). Deep-copy-on-assign is a separate, future axis of faithfulness.
- **Raw pointers, `addr`, `cast`, manual memory, pointer arithmetic.** These have
  no honest idiomatic-JS representation. If a program depends on them, use the
  machine-faithful [aowlweb](aowlweb) backend, whose linear-memory model *is* the
  faithful answer for pointer-level code.

One honest numeric edge: faithful mode implements **wrapping** two's-complement
arithmetic (`_i64`/`_u64` around every 64-bit result), not Nim's *checked*
integer defects. So negating `INT64_MIN`, or an `add` that overflows, wraps
silently instead of raising an `OverflowDefect`. In practice this matches what
nimony emits with runtime overflow checks off (its default here — `-INT64_MIN`
prints `-9223372036854775808` under both, byte-exact); a build that raises
overflow defects is a possible future refinement, but wrapping is the same trade
every wrapping backend makes and is what hardware does.

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
- `ref object` → object reference (construct/field-read/mutate, `== nil` → `=== null`);
  ARC/RTTI hooks are dropped (JS is GC'd);
- inheritance (`object of`) → `interface … extends …`, base fields flattened; upcast
  is identity (structural);
- custom `iterator`s → native generators (`function*` + `yield`, driven by `for..of`);
- closures → inline arrow functions with native lexical capture;
- `enum` → real TS `enum`, qualified member references;
- `seq`/`array` literals, indexing, index-store (`s[i] = v`), `len`, `add`,
  `newSeq(n)`;
- string ops (`&`, `len`, `add`, `$`, relational `==`/`<`/`>`/…, slicing
  `s[a..b]`/`s[a..<b]`, case/trim/split/contains helpers);
- user procs whose names collide with builtins (`add`, `len`, `inc`, `ord`, …)
  emit real calls — magic dispatch is gated on symbol origin, not name;
- user generic instances (monomorphized) are emitted;
- tuples (construction, indexing, tuple return types);
- `var`/`out` parameters via boxing;
- float values print with a trailing `.0` via `echo`/`$` (tracked through a static
  float-type environment, incl. tuple float elements);
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
Current suite: **12/12 byte-identical** fast + **9/9 faithful**. The shared
differential corpus (`aowlhl/corpus`, 44 programs vs native nimony) sits at
**41/44 fast, 44/44 faithful** (faithful is a clean sweep); the remaining fast-mode
fails are the by-design int64 cases below.

## Known limitations / TODO

- **enums** compile to real TS `enum`s, which are not erasable — plain
  `node --experimental-strip-types` rejects them; use
  `--experimental-transform-types`, `tsc`, or `deno`;
- **fast-mode int64/uint64** wrap/precision past 2⁵³ — by design; use `--faithful`
  (the corpus's only fast-mode fails are these);
- **`set[T]`** membership emits an inline `Set`/OR-chain (functional, not typed as
  a nominal set);
- **macros / compile-time execution**, `try`/`except`/`raise`, and `defer` are
  future work.
