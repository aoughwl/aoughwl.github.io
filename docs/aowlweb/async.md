# Async on the JS backend

aowlweb ships a cooperative-async runtime for the JavaScript target, built on
nimony's `{.passive.}` CPS coroutines and driven by the host event loop
(`setTimeout` / `queueMicrotask`).

## What works

- **CPS primitives** (from nimony `system.nim`): `Continuation`, `delay()`,
  `suspend()`, `complete()`, the pluggable `Scheduler`, `parked`/`stopping`/`finished`.
- **Event loop** (`asyncjs.nim`): installs a `TimerHook` that resumes parked
  coroutines via `globalThis.setTimeout`; the dispatcher pumps via `queueMicrotask`.
- **`Future[T]` + `await`** (`asyncfut.nim`, importable): value-returning async,
  concurrency, and error propagation via `Future.err`.
- **Dispatcher**: `callSoon` / `drainReady` / `runForever` — a reentrancy-guarded
  FIFO ready-queue. Waiter wake-ups go through `callSoon` (never inline `complete`),
  so completion cascades stay iterative, not recursive.
- **Importable `sleepAsync`** (`async`): a reusable `{.passive.}` sleep called
  cross-module from any importer's own passive proc — no inline `delay`/`suspend`.
- **Importable combinators** (`asyncfut`): generic `gather`/`all` and
  generic **`race[T]`**/`any`, composed across module boundaries — `race`
  returns the winner's real `T` on the JS backend, not a fixed `Future[int]`.
- **`{.async.}` proc sugar** (`asyncmacros`): write `{.async.}` instead of
  `{.passive.}`, imported from any module — works on the JS backend too.

Verified end-to-end under Node via the official harness (`tests/jsbackend/setup.nim`):
`tsleep1/2/3`, `tfut1/2/3`, `tgather`, `tgather2` (imported generic `gather`),
`trace`, `tgenrace` (generic `race[T]`), `tasyncsugar` (imported `{.async.}`)
— 46/46.

## Usage

```nim
import asyncfut            # Future[T], newFuture, completeFuture, failFuture,
                           # await, generic gather/race, callSoon, runForever
import asyncjs             # installs the setTimeout timer hook (import for effect)
import async               # sleepAsync (reusable {.passive.})
import asyncmacros         # {.async.} sugar

# `await` is importable now (cross-module .passive works); no need to inline it.

# A producer written with the {.async.} sugar instead of {.passive.}:
proc produce(f: Future[int]; ms: int; v: int) {.async.} =
  sleepAsync(ms)           # reusable passive sleep, called cross-module
  completeFuture(f, v)

proc main() {.async.} =
  let f = newFuture[int]()
  callSoon(delay produce(f, 20, 42))
  echo "got ", await(f)    # -> got 42

callSoon(delay main())
runForever()
```

## What the compiler fixes unlocked

Six nimony fixes (branch `fix/async-compiler-bugs`, which folds in
`fix-crossmodule-passive`) turned the hand-rolled, per-file async into a real
importable library. Each fix has a minimal repro and passed the `cps`/`macros`
suites plus the 44-test JS backend suite with no regressions.

- **Cross-module `.passive`** — coro helpers were mangled with the *caller's*
  module suffix and the wrapper was never published into the defining module's
  sem index. Fixed (`coro_transform.nim` + `cps.nim`). Now `await`,
  **`sleepAsync`**, and generic `gather`/`all` live in importable modules
  (`async` / `asyncfut`) and compose across module boundaries — see `tsleep3`
  (imported `sleepAsync`) and `tgather2` (imported generic `gather[T]`).
- **Importable `sleepAsync`** — a reusable `proc sleepAsync*(ms) {.passive.}`
  is now possible (the old "it can't be hidden behind a proc" note was wrong: the
  rule is only "not behind a *template/generic*"; a distinct `.passive` proc is
  fine, and cross-module resolution now works). See `async.sleepAsync`.
- **`delay <call>` in a generic proc** — `semDelay` was not idempotent: a generic
  body is flattened once, then re-semmed on instantiation, and semDelay couldn't
  re-process its own output (`[Bug] expected ')'`). Fixed (idempotent semDelay).
- **`suspend()` in a generic `.passive` proc** — `semSuspend` typed `(suspend)`
  as `Continuation`, but `suspend` is declared `void`; only generic re-sem hit
  that path, so instantiation failed with "expression of type Continuation must
  be discarded". Fixed (typed `void`). Together with the previous fix this makes
  **generic `race[T]`** compile.
- **`{.async.}` proc-pragma macro sugar** — two bugs: macro plugins failed to
  compile for any file outside the repo (search-path/module-suffix mismatch), and
  macros dropped `proc` declarations round-tripping through the NimNode NIF codec
  (no `"proc"` case → became empty). Both fixed, so a proc-pragma macro can
  receive and return a routine. `{.async.}` (inject `.passive`) works — see
  `asyncmacros.nim`.
- **Generic `race[T]` via `delay`** — `race` spawns a per-input waiter with
  `delay raceWaiter(...)`, where `raceWaiter[T]` is a generic `.passive` proc.
  `semDelay`'s generic-instantiation branch copied the delayed callee verbatim,
  so it was never instantiated and its coro frame type never emitted — both the
  native and JS linkers aborted with "Symbol not found". Fixed by re-semming the
  reconstructed call (`sem.nim`). Generic `race[T]` now links on both backends
  (see `tgenrace`).
- **Imported / host-native macro plugins** — an imported macro is absent from
  the importer's `compiledMacros`, and a macro plugin is a HOST-native tool that
  must not inherit the JS target's `--bits:32` or share its 32-bit stdlib. Fixed
  in `semcall.nim` (on-disk plugin fallback) and `macro_plugin.nim` (strip
  `--bits`, build the plugin in an isolated host-bits nifcache). `{.async.}` now
  expands on the JS backend (see `tasyncsugar`).

## Remaining limits

1. **`await` cannot re-raise (errors ride on `Future.err`).** A `.passive` proc
   that captures the result of a `.raises` non-void call no longer *crashes*
   hexer (the `constparams` assert is gone), but the `.raises` error-tuple ABI
   was never threaded through the coroutine lowering (`coro_transform` types the
   lifted result as raw `ptr T`, not `ptr (ErrorCode, T)`), so attempting it is a
   compile error, not silent-wrong code. This is a deferred *feature*; the shipped
   model propagates errors via **`Future.err`**, which is what the library uses.
2. **A spawned coroutine that finishes *after* the entry coroutine returns
   crashes the dispatcher** — keep the entry `main` the last to complete (e.g.
   `race` drains its losing inputs).
3. **`delay()`/`suspend()` are lexical** — directly in the `.passive` body, not
   behind a template/generic (a distinct `.passive` proc such as `sleepAsync` is
   fine).

Generic `race[T]` and imported `{.async.}` sugar — previously JS-only gaps —
now work on the JS backend (see the compiler-fix notes above); the only
remaining semantic limit is raise-across-await.

## Roadmap to "fully finished"

- **Raise-across-await**: thread the `.raises` error-tuple ABI through
  `coro_transform` + `constparams` (recipe recorded) for real exception
  propagation across `await`.
- **WASM glue**: the runtime core is portable; only the timer/pump seam is
  JS-specific.
&lt;/content>
