---
title: aiflib
grand_parent: Nimony
parent: NIF Toolchain Alternatives
nav_order: 7
---

# aiflib — the aowl system module + runtime
{: .no_toc }

`aiflib` is the standard `system` layer and the C runtime primitives the native
([aifc](nifc)) and JS ([aifjs](nifjs)) backends link against, so real programs —
strings, seqs, `echo`, ref objects with ARC — compile through the self-owned
stack **without** nimony's `system.c.aif`.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aiflib`** (public). Status: **scaffolding** — the biggest
remaining unlock in the [aifmony](aifmony) rewrite.

## Why it's needed

By the time [aifhexer](aifhexer) has lowered a program, ARC calls and runtime
operations are *injected* into the `.c.aif` — they reference runtime symbols
that must exist at link time. Today those come from nimony's `system` compiled
to `.c.aif`. aiflib provides them as an aowl-owned layer, and is what lets
`echo "hello"` compile **natively** (today `echo`/strings/seqs run under the
interpreter [nifi](../nifi)).

## The concrete surface

A minimal `echo "hello"` lowers to `.c.aif` referencing a `LongString` payload
(`fullLen`/`rc`/`capImpl`/`data`), a small-string-optimised `string` header,
`write(File, string)`, `nimFlushStdStreams`, and the `cmdCount`/`cmdLine` argv
bridge. Ref/seq programs additionally need the ARC hooks (`=destroy`, `=copy`,
`=sink`, `=trace`), an allocator or GC, the `NimSeqV2` layout, and the `$`/`echo`
numeric formatters.

## Plan

1. **C runtime core** (`runtime/aiflib.h` + `.c`) — string/seq structs, ARC
   helpers, allocator, IO shims: hand-written C, the seed & oracle, unblocking
   native `echo`/string programs through [aifc](nifc).
2. **`system` module** in aowl source, compiled through the stack, replacing the
   reused nimony `system`.
3. **stdlib** (`std/*`) on top as needed.
