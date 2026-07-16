---
title: Roadmap
parent: nimony-web
grand_parent: Backends
nav_order: 6
---

# Roadmap

Where the two backends stand today, and the big work between here and running
arbitrary Nim on the web target. "Full coverage" below means *compile-and-run
arbitrary Nim*, with the JavaScript backend as the more-complete reference.

The percentages are **reasoned estimates**, not measurements. Their basis is the
set of Leng IR node kinds each codegen lowers (versus falling to a counted
`todo` placeholder — see [capabilities.md](capabilities.md)) together with the
breadth of the passing test suites.

| Backend | Coverage | Distance to 100% is mostly… |
|---|---|---|
| JavaScript | **~90%** | threads (frontend-gated) + stdlib breadth — async now shipped |
| WebAssembly | **~30%** | heap allocator → indirect calls → exceptions → `case` |

## JavaScript backend — ~85%

**Where it is.** The codegen lowers essentially the whole Leng IR node set:
overflow-checked arithmetic (`Ovf`/`Keepovf`), full control flow including
`case`, calls, `oconstr`/`aconstr`, RTTI vtables / method tables (`pat` +
flexarray), exceptions (hexer's goto / error-code ABI via `jmp`/`lab`), `emit`,
the GC, and FFI. The 46-test suite spans `Table`/`HashSet`, variant objects,
closures, the GC, a live DOM, and the async runtime. The core language is done.

**Done since this roadmap was first written**

- **`async`/`await`** — shipped as a JS-side runtime: `Future`/`await`, a
  dispatcher/event loop, generic combinators (`gather`/`all`, `race`/`any`), and
  `{.async.}` sugar, all green (46/46). See [async](async).

**Big tasks left**

1. **Threads / `spawn`** — needs Web Workers plus a shared-linear-memory story.
   Not started. Large, and partly gated on nimony's own threading model.
2. **`addr`-of-location edge cases** — a few address-taking forms still hit the
   `todo` placeholder (`src/jscodegen.nim:798`). Small; close the remaining paths.
3. **Stdlib breadth + hardening** — many modules work (`Table`/`HashSet`/
   `strutils`/etc.), but breadth isn't exhaustive. Some modules fail in the
   nimony **frontend** (not this backend) — e.g. `json`, `times`, `envvars` — and
   never reach codegen; more real-world programs are needed to shake out bugs.
   Medium, ongoing.

The gap to 100% is now mostly threads (arguably nimony-frontend-gated) plus
stdlib breadth — not core codegen. Scoped to *synchronous* Nim, the JS backend
is ~95%+ and the only real hole is the stray `addr`-of forms; async is covered by
the runtime above.

**Known rough edges** (caveats, not roadmap items — see
[capabilities.md](capabilities.md) for detail):

- **No runtime checks are emitted** — overflow/bounds/nil checks are intentionally
  not generated, so code relying on them *raising* won't get an exception.
- **The Number/BigInt boundary** — `int`/`uint` are JS Number, `int64`/`uint64`
  are BigInt; mixing them in one operation throws `TypeError`, which heavy-64-bit
  stdlib code (e.g. `std/random`) can hit at internal load/xor sites.
- **No stdin/file I/O** and a fixed **64 MiB** heap (no JS-side growth yet).

## WebAssembly backend — ~30%

**Where it is.** The codegen handles the scalar + aggregate + control spine —
scalar arith/cmp/bitops/conversions, `if`/`while`/`break`, direct (transitive,
cross-module) calls, field/array/pointer load-store at shared `jslayout` offsets,
aggregate construction in a bump region, module globals, string data segments,
and whole-program mode. `echo` runs end to end. Five tests, all straight-line or
aggregate.

**What it is concretely missing** (whole node kinds the JS backend has): no
`CaseS` (no `case` — only `if`/`while`), no `RaiseS` (no exceptions), no
overflow-checked arithmetic or float specials (`Ovf`/`Inf`/`Nan`), no
`Emit`/`Scope`/`Type`. Indirect calls bail (`src/wasmcodegen.nim:457`), and
storage is a bump pointer that never frees.

**Big tasks left, in unlock order**

1. **In-module heap allocator** — the ported allocator running inside linear
   memory via `mmap`/atomics host imports. This is the gate: without it there is
   no *growable* `seq`/`string`/`Table`/`HashSet` — no dynamic data at all. The
   single biggest unlock.
2. **Indirect calls / closures / method dispatch** — `call_indirect` plus a
   function table. Unlocks proc values, closures, and RTTI vtables.
3. **Exceptions** — port the goto / error-code ABI the JS backend already
   implements (`jmp`/`lab` → labeled blocks); the scaffolding is partly present.
4. **`case` statements** — `br_table` or if-chains.
5. **Smaller missing node kinds** — overflow-checked arithmetic, float specials,
   `Suf`/`Emit`/`Scope`/`Type`, and the `addr`/`store`/`global-sym` `todo` paths.
6. **Host-value FFI + DOM** — WASM↔JS glue to reach the JS backend's DOM parity.
   Large, and arguably beyond core language.

Items 1–3 are the bulk of the distance to JS-backend parity.

## Notes on the estimates

- The JS `~85%` counts threads and async as in-scope. Scoped to synchronous Nim
  it is much higher.
- The WASM `~30%` does not move on that distinction — its gaps are structural
  (heap, indirect calls, exceptions), not runtime-subsystem.
- Both figures describe today's committed state; neither backend has been run
  through CI on the PR yet (the workflow is awaiting maintainer approval).
