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
constant folding, algebraic identities, and an ARC pass (`moveDestroyElim`) that
elides an `=destroy(v)` a `=wasMoved(v)` dominates — sound because `=wasMoved`
nils `v.data` and `=destroy` guards on it.

### Does it beat the stock pipeline? (measured — mostly no)

We checked honestly, by disassembly: **`gcc -O2` subsumes all of it.** Dead code
goes at any `-O`; the move/destroy ARC redundancy goes at `-O2` (gcc inlines the
small in-TU `=destroy`, const-propagates the `nil`, elides the call):

| opt level | `=destroy` calls left in a seq round-trip |
|---|---|
| `-O0` / `-O1` | 2 (gcc keeps the redundant one) |
| `-O2` / `-O3` | 0 (gcc does the elision itself) |

This is **why Araq leaves it** — hexer/lengc emit canonical, simple C and defer
local cleanup to the C optimizer (lengc's own output carries the identical dead
code). aifopt's honest value is narrower: `-O0`/`-O1` debug builds, cross-TU
`=destroy` that gcc can't inline, and the backend-independent (JS/readability)
cleanup. Beating `-O2` needs **high-level semantic** passes on the typed `.s.aif`
gcc can't reconstruct — seq/string preallocation, bounds/overflow-check
elimination, cross-module ARC elision — the real roadmap.

## Roadmap

Own it incrementally — rewrite passes onto an aowl-owned core (dropping the
`$NIMONY_SRC` dependency), then retarget the shared infra to the aowl AIF
libraries. Paired with [aiflib](aiflib) (the runtime ARC injects calls into),
this removes the last nimony dependencies from native codegen.
