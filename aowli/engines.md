# Engines — tree-walker vs VM

[[toc]]

---

Both engines consume the same input and must agree to the byte; they are two
implementations of one semantics, not two features.

## Input & value layer

| | |
|---|---|
| Input | The compiler's post-semcheck typed AIF (`.s.aif`) — the exact artifact the native backend consumes. No separate parser, no separate type system. |
| `seq`/`string`/`Table` | Library types built on raw `alloc` in native nimony. aowli **intercepts** the procs that implement them as "natives" and substitutes its own boxed value model (seq, string, array, set, object) instead of running the pointer code. |
| Memory | The interpreter never touches raw memory — every aggregate is a boxed value the engines share. |
| I/O | Shared primitive layer for stdout/stdin so both engines produce identical program output, not just identical control flow. |

## The two engines

| Engine | Binary | Mechanism | Role |
|---|---|---|---|
| Tree-walker | `bin/aowli-interp` | Walks the typed AIF directly, node by node | Correctness oracle: simple, source-line accurate, easy to reason about |
| Bytecode VM | `bin/aowli-vm` | Compiles the AIF into a register/stack instruction chunk, then executes that chunk | Speed path; already supports dynamic method dispatch |

Work in progress: retargeting the VM onto a "partial-hexer" lowering to gain
custom iterators, closures, and exceptions.

## Differential testing

`tests/crosscheck.sh` runs **both** aowli engines *and* the native nimony
compiler on the same program, then classifies the result:

| Verdict | Meaning |
|---|---|
| AGREE-PASS | Both engines match native. Everything is correct. |
| AGREE-FAIL | The engines agree with each other but not with native — a shared gap in aowli. |
| DIVERGE | The two engines disagree with each other — a real bug in one of them. |

Splitting "the engines disagree" from "the engines agree but miss native"
catches a bug class a native-only harness hides: if a single interpreter is
wrong, there is nothing to compare it against.

## Corpus parity

aowli reproduces **100% of the runnable nimony test corpus** byte-for-byte on
both engines, and runs a real pure-nimony program end-to-end — the MDN CSS
validator ([css](../docs/css)) — byte-identical to native.

## The run rung — a run is an AIF

`--emit-run` (env `AIFI_EMIT_RUN=PATH`) serializes an *execution* back into
AIF: a **run rung** token stream recording every binding, loop iteration, and
value the program produced, each atom carrying an `(at …)` back-pointer to the
`.s.aif` node it evaluated.

```
source AIF (.p.aif) → typed AIF (.s.aif) → the run (run rung)
```

The value walker underneath walks each runtime value off its cell/object
structure rather than stringifying it — aggregates keep their real fields
(nimony's `$` renders every object as the dead string `"(object)"`) and
ref/ptr identity is deduped, so sharing is explicit and cycles terminate.
Emission is gated behind an off-by-default flag; a normal run's stdout stays
byte-identical. The browser [playground](https://aoughwl.github.io/playground/)
surfaces this in its **Run** tab, alongside the Parsed (`.p.aif`) and Typed
(`.s.aif`) rungs.

## Tracing

`--trace` / `--trace-full` renders the whole call tree with arguments and
return values at each node — see [Debugging](debugging) for the full flag
reference and the [aowlcode](../docs/aowlcode/execution) plugin surface.
