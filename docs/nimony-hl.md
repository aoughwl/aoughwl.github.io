---
title: nimony-hl
parent: Projects
nav_order: 11
---

# nimony-hl — shared High-Level IR
{: .no_toc }

The **shared lowering** for the idiomatic Nim-to-high-level backends: it turns
nimony's sem'd IR into a small, target-neutral **High-Level IR (HL-IR)** that the
thin language emitters — [nimony-ts](nimony-ts) and [nimony-py](nimony-py) —
render into TypeScript and Python.

> **Status: early scaffold** · private repo. No lowering code has landed yet.
> Access via Discord **timbuktu_guy**.

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
   │  nimony-hl  (this repo)           │   the shared ~85%
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
   nimony-ts emitter          nimony-py emitter
   (HL-IR → TypeScript)       (HL-IR → Python)
```

**HL-IR** is a small target-neutral AST, each node tagged with an HL type
(`Int/Big/Float/Bool/Str/List/Dict/Set/Obj/Ref/Union/Func/Opt`) so the emitters can
make the few divergent decisions (e.g. TS `number`/`bigint`, `Map` keying). Full
design in [`docs/design.md`](https://github.com/aoughwl/nimony-hl/blob/main/docs/design.md)
in the repo.
