---
title: Compiler Pipeline
parent: Documentation
nav_order: 5
has_children: true
---

# Compiler Pipeline
{: .no_toc }

The from-scratch compiler, stage by stage: `source → parse → semcheck → lower →
{ native C | JavaScript | interpret }`. Every stage is written in Nimony, compiles
through the Nimony backends, and is validated to reproduce its stock counterpart —
so the whole pipeline can execute entirely client-side, where the classic-Nim
tools cannot.
{: .fs-6 .fw-300 }

---

## The stages

| Tool | Replaces | What it does |
|:--|:--|:--|
| [aowlparse](aowlparse) | `nifler` (classic-Nim parser) | Parses Nim source into the parse-dialect NIF (`.p.nif`), byte-for-byte identical to native `nifler`, but self-hosted so it can compile to JavaScript. |
| [aowli](../aowli) | native compile-and-run | Interprets a program's *typed* NIF (`.s.nif`) directly — a tree-walking evaluator and a bytecode VM over one value model — checked against nimony's own compile-and-run. |
| [aowljs](aowljs) | leng JS backend | Transpiles the *typed* NIF (`.s.nif`) to **native JavaScript** — fast and readable, trading low-level fidelity for JIT speed. |
| [aowlc](aowlc) | leng C backend (`aowlc`/lengc) | Prints the *lowered* NIF (`.c.nif`) to **C** and links it with `gcc` — the faithful native path; ARC/closures/exceptions already lowered by hexer, so GC is free. |
| [aowlhexer](aowlhexer) | `hexer` (leng lowering) | Lowers `.s.aif` → `.c.aif`: injects ARC, lifts closures, inlines iterators, lowers exceptions, monomorphises. Seeded from Araq's hexer; the default lowering stage in aowlmony. |
| [aowlmony](aowlmony) | the `nimony`/`lengc` driver | Unifies the stack: `.nim` → aowlparse → sem → **aowlhexer** → {aowlc native \| aowli interpret \| aowljs web}. The rewrite driver — parser + lowering + backend + interpreter are self-owned; only sem is reused (until aowlsem). |

## Why "alternatives"

These are not forks of the stock tools; they are **independent implementations of
the same contracts**. `aowlparse` is proven against native `nifler` by a
differential harness (byte-structural equality over the whole standard library);
`aowli` is proven against the compiler's own output over the nimony test corpus.
Holding to the exact wire formats is what lets them slot into the real pipeline —
and what makes the in-browser [playground](../playground) possible.
