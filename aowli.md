---
repo: aoughwl/aowli
---

# aowli — the nimony interpreter

A standalone interpreter for **typed nimony**: it runs the compiler's
post-semcheck typed NIF (`.s.nif`), the exact artifact the native backend
consumes. Two independent engines execute it and agree byte-for-byte, and both
reproduce **100% of the runnable nimony test corpus**.

<div class="hero-actions">
<a href="https://github.com/aoughwl/aowli" target="_blank" rel="noopener">Repo → github.com/aoughwl/aowli</a>
<a href="https://aoughwl.github.io/playground/">Try it in the browser →</a>
</div>

> The source above is private. A prebuilt, binary-only distribution —
> **[aowli-release](docs/aowli-release)** (v0.1.1, obfuscated + licence-gated +
> stripped) — is public: download `aowli-interp`/`aowli-dbg` and run typed NIF
> with no build step. It's also what the [aowlcode](docs/aowlcode) plugin's
> `trace`/`debug` tools run on.

[[toc]]

---

## Two engines, one output

| Engine | Binary | How | Role |
|---|---|---|---|
| Tree-walker | `aowli-interp` | Walks the typed NIF directly | Correctness oracle — simple, source-line accurate |
| Bytecode VM | `aowli-vm` | Compiles NIF into a register/stack instruction chunk, then executes it | Speed path, held honest against the tree-walker |

Both consume nimony's post-semcheck `.s.nif` — no separate parser, no separate
type system, no raw-memory `alloc` path. See [Engines](aowli/engines) for the
shared value layer and the differential harness that keeps the two honest.

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
| [Engines](aowli/engines) | Tree-walker vs VM, the shared value/primitive/IO layer, `.s.nif` input, differential testing, corpus parity. |
| [Debugging](aowli/debugging) | aowlidbg reference: `--break` vs `--break-func`, `--trace` vs `--trace-depth` vs `--trace-profile`, when to use which. |
| [Debugging a real bug](aowli/debugging-a-real-bug) | Case study — a real off-by-one in `aoughwl/css`, found via `--break-func` frame captures, no print statements. |
| [aowli-release](docs/aowli-release) | Public binaries: hardening, distribution, usage. |

## Status

aowli proved itself by running a real pure-nimony program end-to-end: the MDN
CSS validator ([css](docs/css)) runs byte-identical to native on **both**
engines. The VM already supports dynamic method dispatch; work in progress is
retargeting it onto a partial-hexer lowering to gain custom iterators,
closures, and exceptions.
