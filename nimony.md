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

Compiler support that makes nimony's `{.passive.}` CPS coroutines usable as a real
async library. Each links to its full writeup in the [Changelog](changelog).

| # | Feature | Files | Verified by |
|---|---|---|---|
| [F1](changes/feat-cross-module-passive) | [Cross-module `.passive`](changes/feat-cross-module-passive) | `coro_transform.nim` `cps.nim` | `tsleep3` `tgather2` |
| [F2](changes/feat-delay-in-generics) | [`delay <call>` inside generics](changes/feat-delay-in-generics) | `sem.nim` | `tgenrace` |
| [F3](changes/feat-suspend-in-generic-passive) | [`suspend()` in a generic `.passive` proc](changes/feat-suspend-in-generic-passive) | `sem.nim` | cps suite |
| [F4](changes/feat-proc-pragma-macros) | [Proc-pragma macros (`{.async.}`)](changes/feat-proc-pragma-macros) | `macros_nif.nim` `semcall.nim` `macro_plugin.nim` | `tasyncsugar` |
{: .ledger}

### The async runtime — `aoughwl/nimony-web`

A complete cooperative-async runtime over these coroutines, driven by the host
event loop — **46/46** under Node. Each row is documented on the
**[async runtime](docs/nimony-web/async)** page.

| Feature | What it gives you | Docs |
|---|---|---|
| `Future[T]` + `await` | value-returning async, importable across modules | [async](docs/nimony-web/async) |
| Dispatcher | `callSoon` / `drainReady` / `runForever`, reentrancy-guarded FIFO | [async](docs/nimony-web/async) |
| Importable `sleepAsync` | reusable `{.passive.}` sleep, called cross-module | [async](docs/nimony-web/async) |
| Generic `gather` / `all` | await many futures, importable & generic | [async](docs/nimony-web/async) |
| Generic `race[T]` / `any` | first-to-finish wins, returns the real `T` | [async](docs/nimony-web/async) |
| `{.async.}` proc sugar | write `{.async.}` instead of `{.passive.}` | [async](docs/nimony-web/async) |
{: .ledger}

---

## Issues Fixed

Eight compiler fixes over stock upstream. Each row opens its own writeup —
symptom, root cause, the fix, files, and the verifying test.

| # | Issue | Verified by |
|---|---|---|
| [1](changes/issue-1) | [`.passive` helpers didn't resolve across modules](changes/issue-1) | `tsleep3` `tgather2` |
| [2](changes/issue-2) | [`delay <call>` crashed inside a generic proc](changes/issue-2) | cps suite |
| [3](changes/issue-3) | [Macro plugins failed to compile outside the repo](changes/issue-3) | macros suite |
| [4](changes/issue-4) | [`.passive` capturing a `.raises` result crashed hexer](changes/issue-4) | cps suite |
| [5](changes/issue-5) | [Proc-pragma macros silently dropped the routine](changes/issue-5) | macros suite |
| [6](changes/issue-6) | [`suspend()` in a generic `.passive` proc was mis-typed](changes/issue-6) | cps suite |
| [7](changes/issue-7) | [Generic `race[T]` spawned via `delay` failed to link](changes/issue-7) | `tgenrace` |
| [8](changes/issue-8) | [Imported `{.async.}` macros: three cross-target failures](changes/issue-8) | `tasyncsugar` |
{: .ledger}

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
