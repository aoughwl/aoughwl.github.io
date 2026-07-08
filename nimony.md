---
title: Nimony
nav_order: 1
---

# aoughwl/nimony
{: .no_toc }

An opinionated fork of [Nimony](https://github.com/nim-lang/nimony) — the
NIF-based reimplementation of the Nim compiler — that tracks upstream `master`
**daily** and ships a standard library built to *our* taste. Same compiler core;
fewer opinions imposed on you, more of ours baked in.

[Repo → github.com/aoughwl/nimony](https://github.com/aoughwl/nimony){: .btn .btn-primary }

This page is the **canonical record of what our tree fixes and adds over stock
upstream `nim-lang/nimony`**. Our `master` is the branch we use internally and
share: it stays current with upstream and carries our own fixes and features on
top.
{: .fs-5 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## What's different

- **Fewer bugs, more frontline features.** All Nimony work ships here first, and
  we aggressively push lagging features.
- **Stays current.** We pull from `nim-lang/nimony` master ~daily — upstream's
  compiler progress with none of the lag. A fork that keeps up, not one that drifts.
- **A fuller, opinionated stdlib.** 60+ modules and counting — batteries the
  official tree doesn't ship yet, or ships grudgingly: `terminal` (fluent,
  npm-`colors`-style string styling), `base64`, `md5`, `sha1`, `bitops`,
  `complex`, `deques`, `heapqueue`, `editdistance`, `sequtils`, `options`,
  `random`, `wordwrap`, and more. Ergonomics first.

> **The convention:** every time we fix an issue or add a feature, it gets a row
> below (and in `doc/CHANGES.md` in the repo). This is the ledger — kept current.

---

## Features Added

### `.passive` / async ergonomics — compiler side

The compiler support that makes nimony's `{.passive.}` CPS coroutines usable as a
real async library. The runtime itself ships in
**[nimony-web](docs/nimony-web)**.

| Feature | What it enables | Where |
|---|---|---|
| Cross-module `.passive` | `await` / `sleepAsync` / coroutine helpers resolve & compose across module boundaries | `hexer/coro_transform.nim`, `hexer/cps.nim` |
| `delay <call>` in generics | Spawn a coroutine from inside a generic proc (needed for generic `race[T]`) | `nimony/sem.nim` (`semDelay`) |
| `suspend()` in generic `.passive` | Generic passive procs that park now instantiate | `nimony/sem.nim` (`semSuspend`) |
| Proc-pragma macros (e.g. `{.async.}`) | A macro can receive & return a `proc` routine — and works when **imported** and on cross-bit targets | `lib/std/private/macros_nif.nim`, `nimony/semcall.nim`, `nimony/macro_plugin.nim` |

### The async runtime — `aoughwl/nimony-web`

A complete cooperative-async runtime over these coroutines, driven by the host
event loop. Verified end-to-end under Node — **46/46**. Full docs on the
**[nimony-web](docs/nimony-web)** page.

| Feature | What it gives you | Verified by |
|---|---|---|
| `Future[T]` + `await` | Value-returning async, importable across modules | `tfut1/2/3` |
| Dispatcher | `callSoon` / `drainReady` / `runForever`, reentrancy-guarded FIFO | all async tests |
| Importable `sleepAsync` | Reusable `{.passive.}` sleep, called cross-module | `tsleep3` |
| Generic `gather` / `all` | Await many futures, importable & generic | `tgather`, `tgather2` |
| Generic `race[T]` / `any` | First-to-finish wins, returns the real `T` (not a fixed `Future[int]`) | `tgenrace`, `trace` |
| `{.async.}` proc sugar | Write `{.async.}` instead of `{.passive.}`, imported from `asyncmacros` | `tasyncsugar` |

---

## Issues Fixed

| # | Issue | Root cause | Fix (files) | Verified |
|---|---|---|---|---|
| 1 | `.passive` coroutine helpers didn't resolve across modules (`could not find symbol: …init.<caller>`) | helpers mangled with the *caller's* module suffix; the wrapper wasn't published into the defining module's index | `coroSuffix` from the defining module + publish the foreign wrapper | `tsleep3`, `tgather2` |
| 2 | `delay <call>` inside a generic proc → `[Bug] expected ')'` | `semDelay` wasn't idempotent — a generic body is flattened once, then re-semmed on instantiation | make `semDelay` re-entrant (`sem.nim`) | cps suite |
| 3 | Macro plugins failed to compile for any file outside the repo (`cannot open <mod>.s.deps.nif`) | `nimonyDir()/src/lib` was only added per-dir, so module suffixes disagreed | add it unconditionally in `setupPaths` (`semos.nim`) | macros suite |
| 4 | A `.passive` proc capturing a `.raises` non-void result crashed hexer (`assert n.kind==Symbol`) | coro lifts the result local to `(dot(deref env)fld)` | copy the non-Symbol operand verbatim (`constparams.nim`) — removes the crash | cps suite |
| 5 | Proc-pragma macros silently dropped the routine (“expression expected”) | NimNode NIF codec had no `"proc"` case → round-tripped to empty | add `of "proc": nnkProcDef` + map back (`macros_nif.nim`) | macros suite |
| 6 | `suspend()` in a generic `.passive` proc → “Continuation must be discarded” on instantiation | `semSuspend` typed `(suspend)` as `Continuation`, but `suspend` is `void` | type it `void` (`sem.nim`) | cps suite |
| 7 | Generic `race[T]` spawned via `delay raceW(...)` failed to link on **both** native and JS (`loadForeign`: “Symbol not found: raceW.0.coro.<sfx>”) | `semDelay`'s generic-instantiation branch copied the delayed callee verbatim, so a generic callee was never instantiated → its `.coro` frame type was never emitted | reconstruct `(call …)`, re-sem it, then re-flatten to `(delay …)` (`sem.nim`) | `tgenrace` (native + JS) |
| 8a | An **imported** macro wasn't recognized (“macro '…' not compiled”) | an imported macro's declaration is checked in its *defining* module, so it's absent from the importer's `compiledMacros` | fall back to the on-disk plugin the dependency build produced — `macroPluginExists` (`semcall.nim`, `macro_plugin.nim`) | `tasyncsugar` |
| 8b | Macro plugin build failed on cross-bit targets (“Pointer size mismatch…”) | a macro plugin is a HOST-native tool but inherited the target compile's `--bits:NN` | strip `--bits:` from the forwarded args — `hostifyPluginArgs` (`macro_plugin.nim`) | `tasyncsugar` |
| 8c | Macro plugin built but **segfaulted** at run on a cross-bit target | the host plugin reused the target's stdlib artifacts from the shared nifcache | build the plugin in an isolated host-bits nifcache, seeded with `import std/[syncio, macros]` (`macro_plugin.nim`) | `tasyncsugar` |

---

## Known limits (not yet fixed)

- **Raise-across-await** — the `.raises` error-tuple ABI was never threaded
  through the coroutine lowering (`coro_transform` types the lifted result as raw
  `ptr T`, not `ptr (ErrorCode, T)`). The crash is gone (issue #4), but real
  cross-`await` exception propagation is a deferred *feature*; the nimony-web
  library propagates errors via `Future.err`.
- **Dispatcher shutdown** — a coroutine that finishes *after* the entry coroutine
  returns crashes the dispatcher; keep the entry `main` last.
- **WASM async glue** — the runtime core is portable; only the timer/pump seam is
  JS-specific today.

---

## Relationship to upstream

This mirrors and stays in sync with `nim-lang/nimony`. Compiler fixes are meant
to be portable both ways; the standard-library direction is ours to steer. Pull
requests are welcome — no BDFL, just taste. See
[`AGENTS.md`](https://github.com/aoughwl/nimony/blob/master/AGENTS.md) in the repo
for the full toolchain, phase pipeline, and test workflow.
