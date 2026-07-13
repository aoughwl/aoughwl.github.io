---
title: NIF Toolchain Alternatives
parent: Nimony
nav_order: 5
has_children: true
---

# NIF Toolchain Alternatives
{: .no_toc }

Self-hosted, browser-ready reimplementations of the compiler-pipeline stages that
the stock toolchain implements on top of the **classic** Nim compiler. Each one is
written in Nimony, compiles through the Nimony backends, and is validated to
reproduce its stock counterpart — so the pipeline `source → parse → semcheck → run`
can execute entirely client-side, where the classic-Nim tools cannot.
{: .fs-6 .fw-300 }

---

## The stages

| Tool | Replaces | What it does |
|:--|:--|:--|
| [nifparser](nifparser) | `nifler` (classic-Nim parser) | Parses Nim source into the parse-dialect NIF (`.p.nif`), byte-for-byte identical to native `nifler`, but self-hosted so it can compile to JavaScript. |
| [nifi](../nifi) | native compile-and-run | Interprets a program's *typed* NIF (`.s.nif`) directly — a tree-walking evaluator and a bytecode VM over one value model — checked against nimony's own compile-and-run. |

## Why "alternatives"

These are not forks of the stock tools; they are **independent implementations of
the same contracts**. `nifparser` is proven against native `nifler` by a
differential harness (byte-structural equality over the whole standard library);
`nifi` is proven against the compiler's own output over the nimony test corpus.
Holding to the exact wire formats is what lets them slot into the real pipeline —
and what makes the in-browser [playground](../playground) possible.
