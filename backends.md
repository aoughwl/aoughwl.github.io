---
title: Backends
nav_order: 4
has_children: true
permalink: /backends
---

# Backends

Where a lowered program *goes* — every way to run or emit it. Two families: the
**native / faithful** backends (exact semantics: C, native JS, an interpreter, the
linear-memory web backend) and the **idiomatic language** backends (readable
TypeScript / Python via a shared IR). Each page below is the canonical docs for its
repo.

## Native & faithful

| Backend | Repo | Status |
|---|---|---|
| [aowlc](docs/aowlc) — `.c.aif` → C, linked with gcc (ARC baked in, GC-free) | `aoughwl/aowlc` | public |
| [aowljs](docs/aowljs) — `.s.aif` → **native** JavaScript; fast, readable | `aoughwl/aowljs` | public |
| [aowli](aowli) — two-engine interpreter (tree-walker + bytecode VM) | `aoughwl/aowli` | private |
| [aowlweb](docs/aowlweb) — **faithful** JavaScript + WebAssembly (linear-memory, exact int64/ARC/FFI) + async runtime | `aoughwl/aowlweb` | private repo · public docs |

## Idiomatic language targets

| Backend | Repo | Status |
|---|---|---|
| [aowlts](docs/aowlts) — idiomatic TypeScript backend | `aoughwl/aowlts` | early scaffold · private |
| [aowlpy](docs/aowlpy) — idiomatic Python backend | `aoughwl/aowlpy` | early scaffold · private |
| [aowlhl](docs/aowlhl) — shared High-Level IR feeding `aowlts` / `aowlpy` | `aoughwl/aowlhl` | early scaffold · private |

> **aowljs vs aowlweb** — two JavaScript paths on purpose: `aowljs` emits *native*
> JS (map Nimony values onto JS values) for speed and readability; `aowlweb` runs a
> *faithful* linear-memory model (exact int64, pointers, ARC, C-FFI) and also targets
> WASM. Pick fidelity or JIT speed.
