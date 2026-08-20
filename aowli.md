---
repo: aoughwl/aowli
---

# aowli — the nimony interpreter

A standalone interpreter for **typed nimony**: it executes the compiler's
post-semcheck typed AIF (`.s.aif`) — the exact artifact the native backend
consumes — on a real runtime substrate (not a per-shape stdlib re-impl). Two
independent engines run it and agree byte-for-byte.

<div class="hero-actions">
<a href="https://github.com/aoughwl/aowli" target="_blank" rel="noopener">Repo → github.com/aoughwl/aowli</a>
<a href="https://aoughwl.github.io/playground/">Try it in the browser →</a>
</div>

> The source above is private. A prebuilt, binary-only distribution —
> **[aowli-release](docs/aowli-release)** (v0.3.5, obfuscated + licence-gated +
> stripped) — carries `aowli-interp`/`aowli-dbg`, which run typed AIF with no
> build step and are what the [aowlcode](docs/aowlcode) plugin's `trace`/`debug`
> tools drive. Builds come from the [store](store/aowli).

[[toc]]

---

## Two engines, one output

| Engine | Binary | How | Role |
|---|---|---|---|
| Tree-walker | `aowli-interp` | Walks the typed AIF directly | Correctness oracle — simple, source-line accurate |
| Bytecode VM | `aowli-vm` | Compiles AIF into a register/stack instruction chunk, then executes it | Speed path, held honest against the tree-walker |

Both consume nimony's post-semcheck `.s.aif` — no separate parser, no separate
type system. See [Engines](aowli/engines) for the shared value layer and the
differential harness that keeps the two honest.

## Runtime

Six primitive layers the ordinary stdlib runs on — not one intercept per proc:

| Layer | Provides |
|---|---|
| Flat memory | byte-addressable load/store under the value tree: `cast`, `copyMem`/`zeroMem`/`equalMem`, `alloc`, `UncheckedArray`, `{.union.}` — SHA256/CRC/binary codecs run |
| OS / fd | fd table + `open`/`read`/`write`/`close`/`lseek`/`pipe`, `getEnv`/`putEnv` — real files, hermetic in-proc env |
| Finalization | ARC `=destroy`/`=copy`/`=sink`/`=wasMoved` in reverse-decl order; `ref` refcount + `assertRc`; RAII close-on-scope-exit |
| Loud dispatch | every unported foreign leaf fails *named* — no silent `nil` (one explicit no-op allowlist) |
| Async | `Future[T]`/`await` on a deterministic virtual-clock event loop |
| Threads | cooperative run-to-completion scheduler over `rawthreads` / `threadpool` / `\|\|` parfor |

Flat memory / OS / finalization / loud-dispatch hold on **both** engines; async +
threads are **tree-walker-only** (the VM has no coroutine frame model).

## Runtime layer — one spine for every boundary crossing

Those layers used to be scattered — host natives here, flat memory there,
syscalls somewhere else, a miss policy hardcoded per call site. They're now
unified into **one spine** with three pieces:

| Piece | What it is |
|---|---|
| Provider registry | who services a crossing: `interpret` · `host-native` · `syscall` · `hybrid-native` |
| Codec | how a value crosses: `identity` · flat C-ABI · JS value |
| Policy | what happens on a miss — never silently wrong: an unsupported crossing either **fails loud** or **falls back to interpret**, never returns a bogus value |

The point is that there's no fourth outcome. Every foreign leaf is either
serviced by a registered provider or refused by name; the interpreter never
guesses.

## Hybrid mode — interpret one file, run the rest native

Interpret only the file(s) you name; run every *other* module as
natively-compiled code at full speed. aowli auto-generates C-callable shims for
the calls that cross the boundary, marshals the arguments across using
[aowlabi](docs/aowlabi)'s layout — scalars, POD objects and tuples, strings,
seqs — and dispatches at the call site. The native side is **byte-identical to a
fully-native build**; anything that can't cross honestly (refs, closures) falls
back to interpret, so a hybrid run is never *wrong*, only sometimes slower.

```sh
aowli --hybrid --interpret:mymod prog
```

The motivating use: debug one file slowly, with full frame-level observability,
while its libraries run at native speed instead of being walked. The layout that
keeps the two sides in agreement lives in [aowlabi](docs/aowlabi).

## aowlidbg — debug without instrumenting the source

`aowli-dbg` adds batch breakpoints (`--break:LINE`, `--break-func:NAME`) that
dump every hit's frame locals in one non-interactive pass, plus
`--trace`/`--trace-depth`/`--trace-profile` for the call tree. See
[Debugging](aowli/debugging) for the flag reference, and
[Debugging a real bug](aowli/debugging-a-real-bug) for a full session that
found and fixed an actual off-by-one in a real nimony library using nothing but
frame captures.

## Map

| Page | Covers |
|---|---|
| [Engines](aowli/engines) | Tree-walker vs VM, the shared value/primitive/IO layer, `.s.aif` input, differential testing, corpus parity. |
| [Debugging](aowli/debugging) | aowlidbg reference: `--break` vs `--break-func`, `--trace` vs `--trace-depth` vs `--trace-profile`, when to use which. |
| [Debugging a real bug](aowli/debugging-a-real-bug) | Case study — a real off-by-one in `aoughwl/css`, found via `--break-func` frame captures, no print statements. |
| [aowli-release](docs/aowli-release) | Prebuilt binaries: hardening, distribution, usage. |

## Status

Complete runtime across all six layers (single-thread + async + cooperative
threads; real-parallelism *timing* is the native backend's job, not an
interpreter's). Corpus parity — oracle `nimony c -r`, byte-identical stdout + exit:

- **Tree-walker: 432 / 469 runnable (92%)** — and **zero** in-scope cases that run
  but silently return a wrong answer.
- **Both engines lockstep: 358 PASS-BOTH.** The gap is VM-backend-only (async/threads
  are tree-walker-only) plus enumerated leaf ports — all fail loudly, all in
  excluded tests.
- Non-runnable = negative `.msgs` tests + nimony-frontend rejects, not runtime holes.

Real end-to-end proof: the MDN CSS validator ([css](docs/css)) runs byte-identical
to native on both engines.
