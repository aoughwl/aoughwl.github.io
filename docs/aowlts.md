---
title: TypeScript — aowlts
parent: The compiler — aowlmony
nav_order: 9
---

# aowlts — idiomatic TypeScript backend
{: .no_toc }

An **idiomatic TypeScript** backend for [nimony](../nimony): Nim types become real
TypeScript types, not byte offsets.

> **Status: early scaffold** · private repo. The architecture is being designed;
> no working codegen has landed yet. Access via Discord **timbuktu_guy**.

## Different from aowlweb

[aowlweb](aowlweb) already takes Nim to the web, but over a
**linear-memory model** — one `ArrayBuffer`, pointers are integers, objects are
byte offsets (`HEAP32[p>>2]`). Fast and faithful, but the output is asm.js-style,
not something a TypeScript developer would read or type-check. `aowlts` is the
opposite trade-off: **idiomatic, readable, fully-typed TS**.

| | aowlweb (nim-js) | aowlts |
|---|---|---|
| memory | one ArrayBuffer, offsets | real JS objects, engine GC |
| `object` | bytes at a byte offset | `interface` / `class` |
| `seq[T]` | header+data in the buffer | `T[]` |
| `string` | linear bytes | `string` |
| output | fast, faithful, asm-style | readable, typed, idiomatic |

They're **separate projects on purpose** — the one asset that unifies aowlweb
(the `jslayout` byte-layout engine) is exactly what an idiomatic backend throws
away.

## Planned architecture

The idiomatic mapping consumes nimony's **sem'd, pre-`hexer` NIF** — the `.s.nif`
artifact nimony already writes unconditionally — which is dramatically more
idiomatic than the post-`hexer` `.c.nif` that aowlweb consumes:

| construct | `.s.nif` (consumed here) | `.c.nif` (aowlweb) |
|---|---|---|
| `echo "x"` | `(cmd write stdout "x")` — literal intact | `LongString` refcount struct + SSO |
| `object` | nominal, named fields | bytes at a byte offset |
| `seq[T]` | generic `(at seq T)` | header+data+cap struct |
| `try`/`raise` | structured `TryS`/`RaiseS` | error-code returns + goto |

The Nim-semantic lowering is **shared** with `aowlpy` via
[aowlhl](aowlhl); `aowlts` is the thin emitter that renders the
High-Level IR into TypeScript.
