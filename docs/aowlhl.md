---
title: HL-IR — aowlhl
parent: Backends
nav_order: 7
---

# aowlhl — shared High-Level IR
{: .no_toc }

The **shared lowering** for the idiomatic Nim-to-high-level backends: it turns
nimony's sem'd IR into a small, target-neutral **High-Level IR (HL-IR)** that the
thin language emitters — [aowlts](aowlts) and [aowlpy](aowlpy) —
render into TypeScript and Python.

> **Status: reader layer landed** · private repo. The shared HL-IR *reading*
> layer is live and consumed by two backends ([aowli](aowli) interpreter/VM and
> [aowljs](aowljs) emitter); the richer TS/Py *lowering* is the next stage.
> Access via Discord **timbuktu_guy**.

## What has landed: the shared HL-IR reader

Before the lowering below, aowlhl factors out the parts of *reading* the sem'd
NIF that every HL backend duplicates. Three modules are live and shared by the
`aowli` interpreter/VM and the `aowljs` JavaScript emitter:

| Module | What it shares |
|---|---|
| `aowlhl/hlload` | the user-module import graph + `moduleInitOrder` (dependency-first module init) |
| `aowlhl/hlclassify` | routine-pragma classification — `hasImportc` / `importcName` / `hasClosure` |
| `aowlhl/hlwalk` | grammar shape decoders — `decodeLocal` / `decodeParam(s)` / `decodeProc` / `decodeIf` / `decodeCase` |

Each `decode*` turns a node into a shape of captured sub-cursors (which stay
walkable because cursors index an immutable buffer), so no backend hardcodes the
positional grammar. The backend supplies only the *action*: `aowli` evaluates,
`aowljs` prints JavaScript — `aowljs`'s output stayed byte-identical through the
switch. These modules are the concrete foundation the lowering below builds on.

## Why this repo exists

TypeScript and Python differ almost entirely in *surface syntax*, not in *semantic
model* — both have real objects with tracing GC, reference semantics, native
closures, `try`/`finally`, and `list`/`dict`/`set`. So ~85% of an idiomatic backend
is the same for both: the Nim-semantic lowering. That shared part lives here, once,
instead of being duplicated across the two language repos.

```
nimony  ──▶  <module>.s.nif   (sem'd, pre-hexer)
                  │
                  ▼
   ┌──────────────────────────────────┐
   │  aowlhl  (this repo)           │   the shared ~85%
   │  sem'd NIF  →  High-Level IR      │
   │   • structured control flow       │
   │   • inline iterators; defer→finally│
   │   • operator calls resolved        │
   │   • Option→nullable, distinct→base │
   │   • value-copy placement from      │
   │     nimony's move/copy hooks       │
   │   • every node carries an HL type  │
   └──────────────────────────────────┘
        │                          │
        ▼                          ▼
   aowlts emitter          aowlpy emitter
   (HL-IR → TypeScript)       (HL-IR → Python)
```

**HL-IR** is a small target-neutral AST, each node tagged with an HL type
(`Int/Big/Float/Bool/Str/List/Dict/Set/Obj/Ref/Union/Func/Opt`) so the emitters can
make the few divergent decisions (e.g. TS `number`/`bigint`, `Map` keying). Full
design in [`docs/design.md`](https://github.com/aoughwl/aowlhl/blob/main/docs/design.md)
in the repo.
