---
title: Faithful JS/WASM — aowlweb
parent: The compiler — aowlmony
nav_order: 8
has_children: true
---

# aowlweb — JavaScript & WebAssembly backends
{: .no_toc }

Two backends that take Nim to the web: one emits JavaScript, the other emits
WebAssembly. Both are plugins for [nimony](../nimony) — they read the lowered IR
nimony hands its C backend and produce a `.js` or `.wasm` file instead of C. They
share almost all of their code.

> **Private repo, public docs.** The code lives at `aoughwl/aowlweb` and is
> private. Want access? Discord **timbuktu_guy**.

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## The memory model

A WebAssembly module has a single linear memory: one flat, byte-addressable
`ArrayBuffer` that grows a page at a time. A pointer is an integer offset. A fast,
faithful compile of a systems language to JavaScript works the same way — instead
of mapping Nim objects onto JS objects, it allocates one `ArrayBuffer`, treats it
as heap-plus-stack, and reads/writes it through typed-array views (`HEAP32[p >> 2]`).

This faithfulness — simulated linear memory — is what makes the output *exact*
(int64, pointers, ARC, C FFI all behave), but also what makes it slow and
mangled. For a **fast, readable** path that maps nimony values onto native JS
values instead, see the complementary **[aowljs backend](aowljs)** — it trades that
low-level fidelity for near-native speed and legible output, and powers the
playground's Native JS engine.
{: .note }

The two targets are the **same machine described twice**. The memory model is
identical; only the instruction that touches memory differs:

| operation | JavaScript backend | WebAssembly backend |
|---|---|---|
| load i32 at `p` | `HEAP32[p >> 2]` | `i32.load` (addr `p`) |
| store i32 | `HEAP32[p >> 2] = v` | `i32.store` |
| field `x.f` | base + `offsetof(f)` | base + `offsetof(f)` |
| copy an aggregate | `HEAPU8.copyWithin(...)` | `memory.copy` |

Everything above the instruction — field offsets, array strides, string headers,
what a `ref` is at runtime — is computed by one module, `src/jslayout.nim`, the
C-ABI layout engine both backends call. That is why WASM was **additive**: a new
instruction selector over the same layout, loader, and type navigator.

## The pipeline

```
nim source ── nimony ──▶ <module>.c.nif ── nim-js  ──▶ <module>.js  ── nim-js-link ──▶ bundle.js
                          (the Leng IR)  └─ nim-wasm ──▶ <module>.wasm
```

`nim-js` and `nim-wasm` are standalone binaries: `.c.nif` in, artifact out — the
same shape as nimony's other out-of-tree codegens. `nim-js-link` bundles the
per-module JS and prepends the runtime. The target is 32-bit (`--bits:32`):
`int`/`uint` are a JS `Number` / WASM `i32`; `int64`/`uint64` are a `BigInt` / `i64`.

## What works today

**JavaScript backend** — mature for its scope. Runs under Node; covers arithmetic
and integer wrapping, control flow, objects and variant objects,
`seq`/`string`/`Table`/`HashSet`, `strutils`/`sequtils`, closures, exceptions, the
GC, `cstring` and FFI both directions, and a **live DOM** (`tdom.nim` drives a real
jsdom document — `createElement`, event listeners, `classList` — from compiled Nim).

One bug: `Table` hashes use 32-bit multiply-add, and JS does all
arithmetic in float64, so `hash * prime` silently loses the top bits and
string-keyed tables corrupt. The fix wraps every sub-64-bit `*`/`+` through
`Math.imul` / `| 0` / `>>> 0` — see `binTyped` in `src/jscodegen.nim`.

Load-bearing rough edges: **no** overflow/bounds/nil checks emitted (intentional
for JS); the Number/BigInt split can throw when mixing `int` and `int64` in one op;
console-only runtime (no stdin/file I/O); heap `ArrayBuffer` fixed at **64 MiB**.

**WebAssembly backend** — younger but real: every module is executed (and
*validated*) by Node's `WebAssembly` engine. In: scalar arithmetic across
i32/i64/f32/f64 (native wrap — the JS fix is free here), structured control flow,
field/array/pointer load-store at `jslayout` offsets, aggregate construction in a
bump region, multi-module linking, module globals, constant string data segments,
and whole-program mode. `echo "hello world"` compiles to a `.wasm` that runs under
Node and prints. The frontier is the heap: `seq`/`string` growth needs the ported
allocator running inside the module.

## The async runtime

aowlweb also ships the cooperative-async runtime built on nimony's
`{.passive.}` coroutines — **46/46 under Node**. The compiler-side enablers are
recorded on the [nimony](../nimony) page.

| Piece | What it gives you | Where |
|---|---|---|
| `Future[T]` + `await` | value-returning async, importable across modules | `asyncfut.nim` |
| Dispatcher | `callSoon` / `drainReady` / `runForever` | `asyncfut.nim` |
| Event-loop seam | `TimerHook` over `setTimeout`; microtask pump | `async.nim`, `asyncjs.nim` |
| `sleepAsync` | reusable `{.passive.}` sleep, cross-module | `async.nim` |
| `gather` / `all` | await many futures, generic | `asyncfut.nim` |
| `race[T]` / `any` | first-to-finish, returns real `T` | `asyncfut.nim` |
| `{.async.}` sugar | write `{.async.}` instead of `{.passive.}` | `asyncmacros.nim` |

**Deferred:** raise-across-await (errors propagate via `Future.err`); dispatcher
shutdown ordering (keep the entry `main` last); WASM timer/pump seam.

## Building

You need Nim (to build the plugins) and a sibling nimony checkout that's built:

```
nim c src/nim-js.nim        # -> bin/nim-js
nim c src/nim-wasm.nim      # -> bin/nim-wasm
nim c src/nim-js-link.nim   # -> bin/nim-js-link
nim c -r tests/tester.nim   # drives both suites via nimony's hastur
```

The FFI/DOM package is maintained separately at
[`aoughwl/js`](https://github.com/aoughwl/js). `jslayout` is aowlweb's own; the
type navigator, module loader, and name mangler are consumed from the sibling
nimony checkout via `--path`.
