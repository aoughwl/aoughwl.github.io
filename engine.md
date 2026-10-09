---
repo: aoughwl/engine
title: engine — one runtime for JavaScript and Nimony
description: The aoughwl runtime. Our JavaScript engine and our Nimony interpreter in one process, on one heap, collected by one garbage collector, calling each other by address. It replaces aowli as the home of the interpreter.
---

# engine

**One process, one heap, one garbage collector, two languages.**

`engine` is the aoughwl runtime. It puts our JavaScript engine
([aowljs-engine](/docs/aowljs-engine)) and our Nimony interpreter (the
former [aowli](/aowli)) into a single binary, so that:

- both languages allocate from **one heap** and are traced by **one GC**;
- a JavaScript function can call a compiled Nimony procedure, and the reverse,
  passing objects **by address**, with no copying or serialization;
- a reference cycle that runs through both languages is still collected.

It replaces [aowli](/aowli) as the home of the interpreter. aowli's two engines
(the tree-walker and the bytecode VM) carry on inside `engine`, ported onto the
shared heap. The aowli repository is archived.

::: info Status: in development, source private
The pieces below run and are gated, but `engine` is not yet something you can
download. Every figure on this page comes from the repository's own gates and
is dated.
:::

## Why one runtime

Mixed-language programs normally pay at the boundary. A browser engine
embedding a scripting language keeps two heaps and copies values between them.
A game hosting mods keeps a wall of handles and marshalling code. Every
crossing costs a copy, and every object that both sides hold needs a manual
reference count to stop one collector freeing what the other still uses.

`engine` has one heap, so there is no boundary to pay for:

| | Two runtimes side by side | engine |
|:--|:--|:--|
| Heaps | two | one |
| Collectors | two, each blind to the other's roots | one, with a root provider per language |
| Passing an object | copy, or a handle with manual refcounts | the address |
| A cycle through both languages | leaks | collected |
| Type ids | two namespaces | one table, separated by family |

## What runs today

Milestones from the repository, newest first.

**P12 (2026-10-08) — both real engines in one binary, one real GC pass.**
One heap is created once. The real aowljs engine boots on it and runs a
5,000-object JavaScript program (objects, strings, closures, checked by a
computed checksum). aowli's real tree-walking interpreter runs a compiled
Nimony program (`ref`, `seq` and `string` together) on the same heap. A
JavaScript native then calls a compiled Nimony procedure that mutates a field
inside an interpreter object, in place. A full collection follows, with
stress mode and the heap verifier on:

- verifier: **0 errors**, deterministic across 8+ runs in both `-d:danger`
  and `-d:release`;
- **31,305 live objects** across 97 pages traced in the one pass, so both
  engines' objects really are on the same heap;
- the cross-call's write survives the collection.

Getting there found and fixed three real defects: under-tracing in the
interpreter's argument pool, an init-order race over the one shared heap, and
the JS engine allocating during an active mark phase.

**P11 — the interpreter half on the shared heap.** aowli's native object
representation (the same boxes the tree-walker and the VM use for an
interpreted `ref T`) allocated on the shared heap: a 5,000-box chain traced
and kept, 100,000 short-lived boxes under GC stress with the verifier clean and
the live set bounded.

**P10 — the real JavaScript engine calling compiled Nimony.** The real aowljs
engine (interpreter and JIT) calls two compiled Nimony procedures through the
embedding seam, one by value and one mutating a `var` argument by address.
5/5 checks, 5/5 under collect-on-every-allocation, and the engine's own
embedding self-test still 12/12.

**P9 — the join in miniature.** One heap, a JavaScript family and a Nimony
family in one type table, two root providers, calls both ways by address, a
cross-language cycle collected, and 2,000 such cycles under GC stress with the
verifier inside every collection: **0 errors**, 33/33 checks in debug, release
and danger builds.

**No regression in the interpreter.** aowli's cross-check corpus, rebuilt for
the shared-GC runtime: 461 cases agree between the tree-walker, the VM and
native, **0 diverge**, unchanged from the baseline.

## What is not done

- **A release.** There is no downloadable `engine` build yet.
- **The `-O0` debug build** has a known lifetime-model mismatch between
  interpreter buffers owned by ARC and finalization deferred to the GC. The
  optimized builds are the gated ones.
- **The interpreter's argument pool** stays disabled until it is re-tested
  against the fix that made P12 pass.

## The two engines inside

| | JavaScript | Nimony |
|:--|:--|:--|
| Engine | [aowljs-engine](/docs/aowljs-engine) | the aowli interpreter ([archived docs](/aowli)) |
| Execution | bytecode interpreter, baseline x86-64 JIT, optimizing tier | tree-walker and bytecode VM over typed `.s.nif` |
| Conformance | test262: 53,593 / 53,595 | Nimony test corpus: 460 / 460 runnable cases byte-identical to native |
| Written in | Nimony | Nimony |

## Where it is used

- **[Jester](/jester)** runs mods on the interpreter, and its in-game browser,
  titicaca, runs page scripts on the JavaScript engine. One runtime means a
  mod and a web page inside the same game share objects instead of copying
  them.
- **defense**, our licensing layer, is designed to split an
  application between the client and a server at the interpreter's wall, so
  the part worth protecting never ships. Today it ships whole batch tools that
  way; splitting at the wall is the next step.
