---
repo: aoughwl/aowljs-engine
title: aowljs-engine — a JavaScript engine in nimony
description: A from-scratch JavaScript engine — parser, bytecode interpreter, baseline x86-64 JIT and an optimizing tier — written in nimony. 53,593 of 53,595 test262 tests pass, and the optimizing tier is within 1.6x of V8 on our benchmark set.
---

# aowljs-engine — a JavaScript engine in nimony

`aowljs-engine` **runs** JavaScript: a parser, a bytecode interpreter, a
baseline x86-64 JIT and an optimizing tier (SSA, speculation with
deoptimization, inlining), written in nimony. (Its sibling [aowljs](aowljs)
goes the other way and compiles nimony *to* JavaScript.)

It is the JavaScript half of [engine](/engine), the aoughwl runtime, and the
engine behind [Titicaca](/docs/titicaca), the browser inside Jester.

::: info Source private
The repository is private; this page and its numbers come from the
repository's own test and benchmark harnesses.
:::

[[toc]]

---

## Conformance

[test262](https://github.com/tc39/test262), the ECMAScript conformance suite,
across `language`, `built-ins`, `annexB`, `intl402` and `staging`:
**53,593 of 53,595 pass** (October 2026).

The result is the same with the JIT off, on (hot functions), forced on for
every function (`--jit=always`), and with the optimizing tier forced almost at
once (`--opt-threshold=2`). Running the whole suite through each compiler is
how the compilers are tested: a compiled function has to give the interpreter's
answer on every test. The two failures are SpiderMonkey tests under
`staging/sm` that require the opposite of test262's own
`annexB/language/function-code/block-decl-func-skip-arguments.js`; passing them
would fail that test.

Covered: ES2025 plus the stage 3/4 features test262 tests — modules and
top-level await, Temporal, ECMA-402 Intl (all constructors), decorators,
explicit resource management (`using`), ShadowRealm, iterator helpers, RegExp
`v` flag with Unicode 17 tables, SharedArrayBuffer and Atomics across agents.

## Performance

### With the optimizing tier (October 2026)

Total CPU seconds over the sixteen programs below, one machine, same run:

| Engine | Total |
|:--|--:|
| V8 (node, all tiers) | 1.29 |
| **aowljs-engine, optimizing tier** | **1.99** |
| aowljs-engine, baseline JIT only | 3.47 |

The optimizing tier beats node on `loop`, is level on `objmap` and `json`, and
is within 1.5 to 3 times elsewhere.

### Per benchmark, before the optimizing tier (September 2026)

Sixteen programs from `tests/engine/perf` (loops, calls, closures, objects,
arrays, strings, JSON, RegExp, Map/Set, a ray tracer, SHA-256, a functional
pipeline). CPU seconds, best of three, one machine, x86-64 Linux (WSL2):

| Benchmark | aowljs-engine JIT | aowljs-engine interp | V8 `--jitless` | QuickJS-ng | QuickJS | V8 |
|:--|--:|--:|--:|--:|--:|--:|
| array | 0.38 | 1.07 | 0.46 | 0.58 | 1.64 | 0.14 |
| closure | 0.47 | 1.24 | 0.42 | 0.43 | 1.06 | 0.06 |
| fib | 0.08 | 0.26 | 0.12 | 0.10 | 0.12 | 0.04 |
| functional | 0.41 | 0.48 | 0.21 | 0.53 | 0.81 | 0.16 |
| json | 0.27 | 0.29 | 0.28 | 0.84 | 0.81 | 0.25 |
| loop | 0.67 | 2.67 | 0.74 | 0.79 | 2.98 | 0.12 |
| mapset | 0.21 | 0.21 | 0.12 | 0.55 | 0.19 | 0.09 |
| nbody | 0.57 | 2.24 | 1.82 | 1.62 | 1.55 | 0.10 |
| objmap | 0.46 | 0.45 | 0.38 | 0.29 | 0.42 | 0.34 |
| props | 0.48 | 0.69 | 0.25 | 0.65 | 0.80 | 0.05 |
| raytrace | 0.19 | 0.31 | 0.18 | 0.30 | 0.31 | 0.08 |
| regexp | 0.11 | 0.11 | 0.06 | 0.06 | 0.11 | 0.06 |
| richards_lite | 0.19 | 0.43 | 0.23 | 0.25 | 0.42 | 0.04 |
| sha | 0.59 | 1.66 | 0.60 | 0.76 | 1.00 | 0.06 |
| sort | 0.40 | 0.56 | 0.46 | 0.43 | 0.48 | 0.27 |
| string | 0.20 | 0.27 | 0.18 | 0.15 | 0.23 | 0.13 |
| **total** | **5.66** | **12.92** | **6.49** | **8.32** | **12.92** | **2.00** |

Versions: node 24.21.0 (V8), QuickJS 2025-09-13, quickjs-ng at its current
`main`. Each figure includes the engine's own start-up.

Read it as: with the JIT, aowljs-engine is ahead of both QuickJS builds and of
V8's interpreter (Ignition) in total, and about 2.8× behind V8 with its
optimizing compilers. Its interpreter alone is level with QuickJS. It is
weakest, relative to V8's interpreter, on allocation-heavy functional code
(object rest, many small callbacks) and on `props`.

Reproduce:

```
python3 tests/engine/perf/run.py --runs 3 \
  --config "jit=@$HOME/jsengine --jit=on" --config "qjs=@/path/to/qjs" \
  --config "v8=@/path/to/node"
```

## How it is built

- **Values**: NaN-boxed 64-bit words. Numbers are doubles; strings are
  one-byte or UTF-16, and long concatenations are ropes, flattened on first
  read.
- **Objects**: hidden classes (shapes) shared along transition trees rooted per
  prototype; a delete, an attribute change or more than 128 properties gives an
  object a dictionary shape of its own. The first four property values live in
  the object itself.
- **Inline caches** on every property read, write and global-name access:
  own, prototype, getter, setter, add-a-property and absent entries, validated
  by shape and a prototype epoch.
- **Interpreter**: a stack bytecode VM. JavaScript calls do not recurse in the
  host; generators and async functions suspend by copying their frame out.
- **JIT**: a template compiler over the interpreter's own frames, so either tier
  can hand a function to the other at any instruction. Property and global
  caches, array elements, closure variables and arithmetic are compiled inline;
  compiled functions call each other directly. `--jit-stats` lists what still
  falls back to the interpreter.
- **GC**: stop-the-world mark and sweep over cells, strings and shapes, with
  weak collections, WeakRef and FinalizationRegistry.

- **Libraries**: `RegExp` is [regex](/docs/regex), Unicode data comes from
  [unicode](/docs/unicode), and the JIT's assembler, executable memory and
  register allocator are extracted as [jit](/docs/jit).

- **Optimizing tier**: SSA over the bytecode, type speculation guarded by
  deoptimization back to the interpreter, call-target and accessor inlining,
  and linear-scan register allocation.
- **Embedding**: `embed.nim` lets a host register natives with static C
  signatures that compiled code calls directly. [engine](/engine) uses it to
  let JavaScript call compiled nimony by address.

The invariants behind all of this are in the repository's
`src/engine/README.md`.

## Build and run

Inside Linux or WSL, with a nimony toolchain at `~/nimony`:

```
tests/engine/build.sh -d:danger          # -> ~/jsengine  (OUTBIN=... to change)
~/jsengine [--jit=off|on|always] [--opt=off] [--jit-stats] [--prof=F] [--dis] a.js b.js
```

`-d:release` keeps nimony's runtime checks on, for development. Scripts given
together share one global; `--module-last` runs the last file as a module.

## Tests

```
python3 tests/engine/test262.py language built-ins annexB intl402 staging \
        -j 8 [--args=--jit=always] --fails /tmp/fails.txt   # needs ~/test262
```
