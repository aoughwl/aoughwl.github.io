---
title: aowlhexer
parent: Compiler Pipeline
nav_order: 2
---

# aowlhexer — the aowl lowering pass
{: .no_toc }

`aowlhexer` lowers a semantically-checked AIF module (`.s.aif`) to the C-shaped
`.c.aif` that the native backend prints — injecting ARC, lifting closures,
inlining iterators, lowering exceptions, and monomorphising generics along the
way. It is seeded from Andreas Rumpf's `hexer` in nimony and is being
progressively aowl-owned.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aowlhexer`** (public).

## The hard part of the compiler

aowlhexer is where the genuinely difficult work happens, so the backends
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
[aowlc](aowlc) can be a printer.

## Ours vs reused

The 25 lowering passes under `src/` are vendored from Araq's `nimony/hexer` and
are what aowlhexer owns and will progressively rewrite. The shared compiler
library is reused from a `nimony` checkout (`$NIMONY_SRC`) until an aowl-owned
core exists: `build.sh` copies it into `.build/` and overlays `src/` so
intra-tree `../hexer` references resolve to our copies.

## Verified in the pipeline

Built from Araq's passes, aowlhexer produces the same `.c.aif` as nimony's
`hexer`, and it is the **default lowering stage** in [aowlmony](aowlmony): the
driver injects `bin/aowlhexer` in place of `hexer`, so a real build runs
`.nim → aowlparser → sem → aowlhexer → aowlc → gcc`, yielding correct native
binaries (`fib(20)=6765`, `ack(3,4)=125`, `fib(25)=75025`).

## Roadmap

Own it incrementally — rewrite passes onto an aowl-owned core (dropping the
`$NIMONY_SRC` dependency), then retarget the shared infra to the aowl AIF
libraries. Paired with [aowllib](aowllib) (the runtime ARC injects calls into),
this removes the last nimony dependencies from native codegen.
