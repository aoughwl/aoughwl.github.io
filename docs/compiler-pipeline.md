---
title: aowlmony
nav_order: 1
has_children: true
---

# aowlmony
{: .no_toc }

The whole compiler, driven by `aowlmony`: `source → parse → semcheck → lower →
{ native C · JavaScript · WASM · interpret · TypeScript · Python }`. Every stage is
written in Nimony, holds to the exact AIF (≡ NIF) wire format so it drops into the
real toolchain, and runs client-side where the classic-Nim tools can't. The pages
in this section are its parts, front to back.
{: .fs-6 .fw-300 }

---

## Front to back

| Part | Repo | What it does |
|:--|:--|:--|
| parse | [aowlparser](aowlparser) | Nim/Nimony source → `.p.aif`; byte-for-byte identical to `nifler`, self-hosted so it compiles to JavaScript. |
| semcheck | aowlsem *(private)* | `.p.aif` → typed `.s.aif`: resolves symbols, picks overloads, instantiates generics. |
| lower | [aowlhexer](aowlhexer) | `.s.aif` → `.c.aif`: ARC, closures, iterators, exceptions, monomorphisation. Seeded from Araq's hexer. |
| driver | [aowlmony](aowlmony) | Ties it together: one command, `.nim` → parse → sem → lower → a backend. |
| runtime | [aowllib](aowllib) | Strings, seqs, ARC, GC — what the native/JS backends link against. |
| run / emit | [aowli](../aowli) · [aowlc](aowlc) · [aowljs](aowljs) · [aowlweb](aowlweb) · [aowlts](aowlts) · [aowlpy](aowlpy) · [aowlhl](aowlhl) | Every target the lowered IR can become — interpret, native C, native/faithful JS, WASM, TypeScript, Python. |

## Why it drops in

Each part is an **independent implementation of the same contract**, not a patch on
the stock tool. `aowlparser` is proven against `nifler` by a differential harness
(byte-structural equality over the whole standard library). Holding to the exact
AIF wire format is what lets any stage slot into the real pipeline beside nimony's
own — and what makes the in-browser [playground](../playground) possible.
