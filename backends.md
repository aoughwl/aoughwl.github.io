---
title: Backends
parent: Documentation
nav_order: 3
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
| [aowl-web](docs/aowl-web) — **faithful** JavaScript + WebAssembly (linear-memory, exact int64/ARC/FFI) + async runtime | `aoughwl/aowl-web` | private repo · public docs |

## Idiomatic language targets

| Backend | Repo | Status |
|---|---|---|
| [aowl-ts](docs/aowl-ts) — idiomatic TypeScript backend | `aoughwl/aowl-ts` | early scaffold · private |
| [aowl-py](docs/aowl-py) — idiomatic Python backend | `aoughwl/aowl-py` | early scaffold · private |
| [aowl-hl](docs/aowl-hl) — shared High-Level IR feeding `aowl-ts` / `aowl-py` | `aoughwl/aowl-hl` | early scaffold · private |

> **aowljs vs aowl-web** — two JavaScript paths on purpose: `aowljs` emits *native*
> JS (map Nimony values onto JS values) for speed and readability; `aowl-web` runs a
> *faithful* linear-memory model (exact int64, pointers, ARC, C-FFI) and also targets
> WASM. Pick fidelity or JIT speed.
