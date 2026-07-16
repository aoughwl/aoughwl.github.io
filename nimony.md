---
title: Changes
has_children: true
parent: Engineering Notes
nav_order: 1
---

# Changes — what we fixed and added
{: .no_toc }

The single record of the compiler engineering behind the stack: every fix and
every `.passive`/async feature that make the async story and the live tooling
work. Two buckets — **Added** and **Fixed** — and every row links to its own
writeup (symptom, root cause, fix, files, verifying test).
{: .fs-5 .fw-300 }

[Compiler repo → github.com/aoughwl/nimony](https://github.com/aoughwl/nimony){: .btn .btn-primary }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## What we ship

- **Fewer bugs, more frontline features.** We push hard on the machinery the
  async story needs, and when we hit a compiler bug we fix it rather than route
  around it.
- **A fuller, opinionated stdlib.** 60+ modules and counting — the batteries
  you'd otherwise write yourself: `terminal` (fluent, npm-`colors`-style string
  styling), `base64`, `md5`, `sha1`, `bitops`, `complex`, `deques`, `heapqueue`,
  `editdistance`, `sequtils`, `options`, `random`, `wordwrap`, and more.
  Ergonomics first.

> **The convention:** every time we fix an issue or add a feature, it gets a row
> below (and in `doc/CHANGES.md` in the repo). This is the ledger — kept current.

---

## Added

Compiler support that makes nimony's `{.passive.}` CPS coroutines usable as a real
async library. Each links to its full writeup.

| # | Feature | Files | Verified by |
|---|---|---|---|
| [F1](changes/feat-cross-module-passive) | [Cross-module `.passive`](changes/feat-cross-module-passive) | `coro_transform.nim` `cps.nim` | `tsleep3` `tgather2` |
| [F2](changes/feat-delay-in-generics) | [`delay <call>` inside generics](changes/feat-delay-in-generics) | `sem.nim` | `tgenrace` |
| [F3](changes/feat-suspend-in-generic-passive) | [`suspend()` in a generic `.passive` proc](changes/feat-suspend-in-generic-passive) | `sem.nim` | cps suite |
| [F4](changes/feat-proc-pragma-macros) | [Proc-pragma macros (`{.async.}`)](changes/feat-proc-pragma-macros) | `macros_nif.nim` `semcall.nim` `macro_plugin.nim` | `tasyncsugar` |
{: .ledger}

### The async runtime — `aoughwl/aowl-web`

A complete cooperative-async runtime over these coroutines, driven by the host
event loop — **46/46** under Node. Each row is documented on the
**[async runtime](docs/aowl-web/async)** page.

| Feature | What it gives you | Docs |
|---|---|---|
| `Future[T]` + `await` | value-returning async, importable across modules | [async](docs/aowl-web/async) |
| Dispatcher | `callSoon` / `drainReady` / `runForever`, reentrancy-guarded FIFO | [async](docs/aowl-web/async) |
| Importable `sleepAsync` | reusable `{.passive.}` sleep, called cross-module | [async](docs/aowl-web/async) |
| Generic `gather` / `all` | await many futures, importable & generic | [async](docs/aowl-web/async) |
| Generic `race[T]` / `any` | first-to-finish wins, returns the real `T` | [async](docs/aowl-web/async) |
| `{.async.}` proc sugar | write `{.async.}` instead of `{.passive.}` | [async](docs/aowl-web/async) |
{: .ledger}

---

## Incremental compilation & the tooling backend

Nimony's design already leans on cached, typed NIF artifacts per module — which
makes it a natural fit for *fast re-checks*. We push that further so
that interactive tooling (the **[nimony-lsp](docs/nimony-lsp)** language server's
live as-you-type diagnostics, in particular) has a compile path that stays warm
and cheap. These are the concrete wins, most user-visible first.

| Win | What it does | Measured |
|---|---|---|
| [Parallel dependency discovery](changes/ic-parallel-deps) | A breadth-first pre-pass (`preNifle`) runs `nifler` over the *whole import closure in parallel* before the DFS, which then does only cheap in-memory work. Self-healing serial fallback. | discovery wall **0.43s → 0.24s (1.77×)** |
| [Incremental cursor traversal](changes/ic-cursor-traversal) | `nimsem` walks the module structure with an incremental cursor instead of re-materializing it (toward #2064). | — |
| [Warm-worker daemon (`nimsem serve`)](changes/ic-warm-daemon) | Persistent semcheck worker; keeps the interner, interface cache and indexes warm across requests. JSONL protocol with a dirty-buffer seam. Foundation for interactive rebuilds. | `system` interned **1× / session** |
| [Batch-intern ceiling + proof](changes/ic-batch-intern) | Measured the re-intern cost a daemon removes (`system.s.idx.nif` re-interned **107×** on `tall.nim`) and proved batching 20 modules in one process fixes it. | index intern **91.6ms → 8.6ms** |
{: .ledger}

**Why this matters for editors.** A whole-project `nimony check` is ~1.1s cold
but only **~10–25ms** on an incremental warm re-check. That gap is exactly what
lets nimony-lsp publish diagnostics *on every keystroke* (against the unsaved
buffer, in an isolated nimcache) without a background daemon — see the
[nimony-lsp](docs/nimony-lsp) page. The `nimsem serve` daemon above is the
next-tier backend for when cross-module query latency (go-to-def / references on
huge trees) needs to be warm too; it's wired into nimony-lsp as an opt-in path.

---

## Fixed

Eight compiler fixes behind the async story. Each row opens its own writeup —
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

**Compiler safety & diagnostics.** Four more fixes to the checker and its
messages — rejecting a captured `var`/`out` parameter in a closure (memory
safety), pointing the `mover` "other usage" diagnostic at the real use site,
naming `result` instead of the mangled `result.0`, and stopping control-flow
analysis from descending into stored macro bodies. Full root-cause writeups:
**[Safety & diagnostics fixes](docs/nimony-fork)**.

---

## Known limits (not yet fixed)

- **Raise-across-await** — the `.raises` error-tuple ABI was never threaded
  through the coroutine lowering (`coro_transform` types the lifted result as raw
  `ptr T`, not `ptr (ErrorCode, T)`). The crash is gone (issue #4), but real
  cross-`await` exception propagation is a deferred *feature*; the aowl-web
  library propagates errors via `Future.err`.
- **Dispatcher shutdown** — a coroutine that finishes *after* the entry coroutine
  returns crashes the dispatcher; keep the entry `main` last.
- **WASM async glue** — the runtime core is portable; only the timer/pump seam is
  JS-specific today.

---

## Portability

The compiler fixes here are written against the Nim language, not against
anything private — every one is portable to `nim-lang/nimony`, and we send them
that way where they fit. The standard-library direction is ours to steer. Pull
requests are welcome — no BDFL, just taste. See
[`AGENTS.md`](https://github.com/aoughwl/nimony/blob/master/AGENTS.md) in the repo
for the full toolchain, phase pipeline, and test workflow.
