---
title: nifi — Nimony Interpreter
nav_order: 7
---

# nifi
{: .no_toc }

A standalone interpreter for **typed nimony** — it runs the compiler's
post-semcheck typed NIF (`.s.nif`), the exact artifact the native backend
consumes. Two independent engines execute it and produce byte-identical output,
and they are held honest against native nimony by a differential test harness.
{: .fs-6 .fw-300 }

[Repo → github.com/aoughwl/nifi](https://github.com/aoughwl/nifi){: .btn .btn-primary }
[Try it in the browser →](playground){: .btn }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Two engines, one output

nifi executes the same typed NIF two different ways, and the two paths must
agree to the byte:

- **Tree-walker (`bin/nifi-interp`)** — walks the typed NIF directly. It is the
  correctness oracle: simple, source-line accurate, easy to reason about.
- **Bytecode VM (`bin/nifi-vm`)** — compiles the NIF into a register/stack
  instruction chunk and executes that chunk.

Because both consume the [nimony](nimony) fork's post-semcheck `.s.nif`, they see
exactly what the native backend sees — no separate parser, no separate type
system. nimony's `seq` / `string` / `Table` and friends are library types built
on raw `alloc`; rather than run that pointer code, nifi **intercepts** those
procs as "natives" and supplies its own value model — boxed seq, string, array,
set, and object. The interpreter never touches raw memory.

## Differential testing

`tests/crosscheck.sh` runs **both** nifi engines *and* the native nimony
compiler on the same program, then classifies the result:

- **AGREE-PASS** — both engines match native. Everything is correct.
- **AGREE-FAIL** — the engines agree with each other but not with native: a
  shared gap in nifi.
- **DIVERGE** — the two engines disagree with each other: a real bug in one of
  them.

Splitting "the engines disagree" from "the engines agree but miss native"
catches a whole class of bug a native-only harness hides — if a single
interpreter is wrong, there is nothing to compare it against.

## Tracing

A `--trace` / `--trace-full` mode renders the whole call tree, with arguments and
return values at each node — a structural debugger for typed-NIF execution. You
see the program's evaluation as a tree, not a scroll of `echo` output.

## Status

nifi proved itself by running a real pure-nimony program end-to-end: the MDN CSS
validator ([css](docs/css)) runs byte-identical to native on **both** engines.
The VM already supports dynamic method dispatch. Work in progress is retargeting
the VM onto a "partial-hexer" lowering to gain custom iterators, closures, and
exceptions.
