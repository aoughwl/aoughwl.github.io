---
title: aifhexer
grand_parent: Nimony
parent: NIF Toolchain Alternatives
nav_order: 6
---

# aifhexer — the aowl lowering pass
{: .no_toc }

`aifhexer` lowers a semantically-checked AIF module (`.s.aif`) to the C-shaped
`.c.aif` that the native backend prints — injecting ARC, lifting closures,
inlining iterators, lowering exceptions, and monomorphising generics along the
way. It is seeded from Andreas Rumpf's `hexer` in nimony and is being
progressively aowl-owned.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aifhexer`** (public).

## The hard part of the compiler

aifhexer is where the genuinely difficult work happens, so the backends
downstream can be mere printers:

| pass | effect |
|---|---|
| `destroyer` + `duplifier` + `mover` | **ARC** — destructors, `=copy`/`=destroy` hooks, ref-count ops |
| `lambdalifting` | closures → plain functions + env structs |
| `iterinliner` | iterators inlined |
| `eraiser` | exceptions → error-code plumbing |
| `inliner` / `dce2` / `constparams` | inlining, dead-code elimination, const-param specialisation |
| `lengcgen` | emit the sized, ARC'd, monomorphised `.c.aif` |

Because ARC is injected here, every backend that consumes `.c.aif` gets
**deterministic memory management for free** — which is exactly why
[aifc](nifc) can be a printer.

## Ours vs reused

The 25 lowering passes under `src/` are vendored from Araq's `nimony/hexer` and
are what aifhexer owns and will progressively rewrite. The shared compiler
library is reused from a `nimony` checkout (`$NIMONY_SRC`) until an aowl-owned
core exists: `build.sh` copies it into `.build/` and overlays `src/` so
intra-tree `../hexer` references resolve to our copies.

## Verified in the pipeline

Built from Araq's passes, aifhexer produces the same `.c.aif` as nimony's
`hexer`, and it is the **default lowering stage** in [aifmony](aifmony): the
driver injects `bin/aifhexer` in place of `hexer`, so a real build runs
`.nim → aifparser → sem → aifhexer → aifc → gcc`, yielding correct native
binaries (`fib(20)=6765`, `ack(3,4)=125`, `fib(25)=75025`).

## Better than stock hexer — `aifopt`

Stock hexer/lengc lowers *correctly* but leaves measurable slack: **every** proc
it emits carries an unreachable trailing `return result`, the dead `result`
variable behind it, and a dead loop label — plus deeply nested single-child
`(stmts (stmts …))` blocks and un-folded constant arithmetic. `aifopt`
(`opt/aifopt.js`) is the fixpoint simplifier a stock pipeline omits.

The `gcd` proc, before (stock hexer → C) and after (+aifopt): the dead
`result_0` variable, the dead `whileStmtLabel_0:` label, and the unreachable
`return result_0;` all disappear, leaving just the loop and `return x`.

Measured on real hexer output (`node opt/demo.js`):

| file | IR nodes | dead rets | dead vars | dead labels |
|---|---|---|---|---|
| compute | 486 → 444 (−8.6%) | 12 → 8 | 12 → 8 | 4 → 0 |
| fib | 254 → 241 (−5.1%) | 7 → 5 | 6 → 5 | 1 → 0 |
| mathf | 330 → 317 (−3.9%) | 12 → 10 | 5 → 4 | 1 → 0 |
| **total** | **1070 → 1002 (−6.4%)** | **31 → 23** | **23 → 17** | **6 → 0** |

**8/8** optimized programs return identical results. Passes: unreachable-code,
dead-variable and dead-label elimination, `(stmts (stmts …))` flattening, integer
constant folding, and algebraic identities — run to a fixpoint. It runs by
default in the [aifmony](aifmony) pipeline (`AIFMONY_NO_OPT=1` to disable).

Honest scope: for tiny integer programs `gcc -O2` erases the *runtime* difference
downstream, but the cleanup is backend-independent (it shrinks the JS backend's
input and the readable C too) and applies to un-optimized/debug builds. This is
where aifhexer *improves* on stock hexer rather than rewriting its (correct,
mature) lowering passes. `aifopt` grows toward the wins gcc **cannot** do —
eliding redundant ARC `=copy`/`=destroy` calls, opaque to the C compiler.

## Roadmap

Own it incrementally — rewrite passes onto an aowl-owned core (dropping the
`$NIMONY_SRC` dependency), then retarget the shared infra to the aowl AIF
libraries. Paired with [aiflib](aiflib) (the runtime ARC injects calls into),
this removes the last nimony dependencies from native codegen.
