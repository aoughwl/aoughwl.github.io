---
repo: aoughwl/aowlhexer
---

# aowlhexer — the aowl lowering pass

> ▶️ **[Try `aoughwl/aowlhexer` live in the Playground](https://aoughwl.github.io/playground/#clone=aoughwl/aowlhexer)** — clones the repo into the in-browser IDE, no install.

`aowlhexer` lowers a semantically-checked AIF module (`.s.aif`) to the C-shaped
`.c.aif` that the native backend prints — injecting ARC, lifting closures,
inlining iterators, lowering exceptions, and monomorphising generics along the
way. It started from `hexer` in nimony and is being taken over pass by pass.

## Where the hard work happens

Everything difficult is here, which is what lets the backends downstream be
printers:

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

The 25 lowering passes under `src/` started as a copy of `nimony/hexer` and are
what aowlhexer owns and will progressively rewrite. The shared compiler library
is still reused from a `nimony` checkout (`$NIMONY_SRC`) until an aowl-owned core
exists: `build.sh` copies it into `.build/` and overlays `src/` so intra-tree
`../hexer` references resolve to our copies.

### Where we've already diverged

Two passes are no longer the reference's code. Both are places the reference
marks its own behaviour as unfinished, so the change makes aowlhexer stricter or
more precise — never looser:

| pass | what we changed |
|---|---|
| `lambdalifting` | Capturing a `var T` / `out T` parameter in a closure is now a lowering-time error. That capture aliases the *caller's* storage, so an environment that outlives the call dangles. The reference leaves it as a TODO; sem catches the common cases, this is the backstop. |
| `mover` | The "other usage" that blocks a sink was recorded *after* the cursor had advanced past it, so the diagnostic pointed at a closing paren. It's now captured at the use site. |

So the `.c.aif` is near-identical to `hexer`'s rather than identical by
construction: a program that captures a `var` parameter is rejected here and
accepted there.

## Verified in the pipeline

aowlhexer is the **default lowering stage** in [aowlmony](aowlmony): the driver
injects `bin/aowlhexer` in place of `hexer`, so a real build runs
`.nim → aowlparser → sem → aowlhexer → aowlc → gcc` and produces correct native
binaries (`fib(20)=6765`, `ack(3,4)=125`, `fib(25)=75025`).

## Roadmap

Own it incrementally — rewrite passes onto an aowl-owned core (dropping the
`$NIMONY_SRC` dependency), then retarget the shared infra to the aowl AIF
libraries. Paired with [aowlrt](aowlrt) (the runtime ARC injects calls into),
this removes the last nimony dependencies from native codegen.
