---
title: Compiler Pipeline
parent: Documentation
nav_order: 5
has_children: true
---

# Compiler Pipeline
{: .no_toc }

The front half of the compiler: `source → parse → semcheck → lower`. Every stage
is written in Nimony, holds to the exact AIF (≡ NIF) wire format so it drops into
the real toolchain, and runs client-side where the classic-Nim tools can't. Where
the lowered IR *goes* — native C, JavaScript, WASM, an interpreter, TypeScript,
Python — is the [Backends](../backends) section.
{: .fs-6 .fw-300 }

---

## The stages

| Tool | Replaces | What it does |
|:--|:--|:--|
| [aowlparse](aowlparse) | `nifler` | Parses Nim/Nimony source into the parse-dialect AIF (`.p.aif`), byte-for-byte identical to `nifler`, but self-hosted so it can compile to JavaScript. |
| aowlsem *(private)* | `nimsem` | Semantic-checks `.p.aif` → typed `.s.aif`: resolves symbols, picks overloads, instantiates generics. |
| [aowlhexer](aowlhexer) | `hexer` | Lowers `.s.aif` → `.c.aif`: injects ARC, lifts closures, inlines iterators, lowers exceptions, monomorphises. Seeded from Araq's hexer. |
| [aowlmony](aowlmony) | the `nimony` driver | Ties it together: `.nim` → `aowlparse` → sem → `aowlhexer` → a backend. One command, native or interpreted. |
| [aowllib](aowllib) | the system module + runtime | Strings, seqs, ARC, GC — the runtime the native/JS backends link against. |

## Why it drops in

Each stage is an **independent implementation of the same contract**, not a patch
on the stock tool. `aowlparse` is proven against `nifler` by a differential
harness (byte-structural equality over the whole standard library). Holding to the
exact AIF wire format is what lets any stage slot into the real pipeline beside
nimony's own — and what makes the in-browser [playground](../playground) possible.
