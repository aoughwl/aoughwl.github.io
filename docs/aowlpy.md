---
title: Python — aowlpy
parent: Backends
nav_order: 6
---

# aowlpy — idiomatic Python backend
{: .no_toc }

An **idiomatic Python** backend for [nimony](../nimony): Nim types become real
Python objects, not byte offsets.

> **Status: early scaffold** · private repo. The architecture is being designed;
> no working codegen has landed yet. Access via Discord **timbuktu_guy**.

## What it is (and isn't)

There are two ways to target Python from Nim:

1. **Linear-memory Python** — a `bytearray` + `struct`/`memoryview` as one flat
   heap, pointers as offsets. Reuses [aowlweb](aowlweb)'s `jslayout` engine
   verbatim, but is slow and unreadable. *If ever wanted, it belongs in aowlweb
   as a third linear target — not here.*
2. **Idiomatic Python** — real `class`/`@dataclass`, `list`, `dict`, Python's own
   GC. Readable, fast enough, Pythonic. **This repo is #2.**

Python is in some ways an *easier* idiomatic target than TypeScript:

| | idiomatic value |
|---|---|
| integers | native arbitrary-precision `int` — no `number`/`bigint` split, no wrap footgun |
| `object` | `@dataclass` / `class` |
| `seq[T]` | `list` |
| `Table[K,V]` / `HashSet` | `dict` / `set` |
| `string` | `str` |
| memory | Python's refcount + cycle GC |

## Planned architecture

Shared with its sibling [aowlts](aowlts): a common Nim→high-level lowering
([aowlhl](aowlhl)) feeds thin per-language emitters. Both consume nimony's
**sem'd, pre-`hexer` NIF** (`.s.nif`) — `echo` stays a named `write` call with the
literal intact, `object` types nominal, `seq[T]` generic, `try`/`raise` structured
— none of the C-model lowering the post-`hexer` `.c.nif` carries. It loads with
existing nimony APIs (`programs.loadModuleContent` / `setupProgram`), so no
compiler changes are needed.
