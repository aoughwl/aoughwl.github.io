---
repo: aoughwl/aowli-release
---

# aowli-release — public binaries for the aowli interpreter

A prebuilt, **binary-only** distribution of [aowli](../aowli), the typed-AIF
interpreter for Nimony. The source stays private in `aoughwl/aowli`; this repo
ships only the built binaries, hardened for public distribution.

> **Now public** — anyone can access, download, and use it. Issues are welcome:
> [github.com/aoughwl/aowli-release/issues](https://github.com/aoughwl/aowli-release/issues).

[[toc]]

---

## v0.3.0 — correctness-complete

The current release is **v0.3.0**, the correctness-complete build of aowli. Both
engines — the tree-walker behind `aowli-interp` / `aowli-dbg` and the internal
bytecode VM — now reach **zero in-scope divergence across a 423-program
differential corpus** run against the nimony compiler. The engines agree with
each other and with native execution, program for program.

What v0.3.0 closes:

- **Value-copy (`=copy`) semantics** — assigning or binding a value object,
  tuple, or value-array copies the envelope (refs stay shared). `var x = a;
  x.a = 999` no longer mutates `a`.
- **The last OS-boundary gaps** — real host `stat` / `lstat` (correct
  `fileExists` / `dirExists`), pointer identity in `==` / `!=`, `cast[int](ptr)`
  round-tripping through flat memory, and VM argv / stdin seeding.
- **Broad fixes** — float→int conversion, block-expression values,
  cyclic-import init order, a self-nested-iterator hang, and `Table` element
  write-back.

One boundary is **documented, not a gap**: `{.emit.}` literal-C and C FFI aren't
handled by the pure value interpreter — there's no C to execute in the value
model. That's precisely what the **hybrid-native provider** absorbs: the module
in question runs through the real C toolchain as a shared object, while the rest
of the program stays interpreted. It's on the roadmap — not a correctness gap in
the interpreter.

---

## What's in it

Two binaries, each a fully self-contained interpreter over a `.s.aif` (a
Nimony program's typed, post-semcheck AIF):

- **`aowli-interp`** — run a program, or `--trace` it for its execution
  call-tree.
- **`aowli-dbg`** — batch breakpoints: run with `--break:LINE`, dumping every
  hit frame's variables in one pass.

These are the same binaries the [aowlcode](aowlcode) Claude Code plugin's
`trace`/`debug` tools shell out to — a public user of that plugin runs entirely
off this release, never a private aowli checkout.

## Hardening

Before publishing, each build goes through:

- A **licence gate** (fail-closed, checked at module init) — the binary refuses
  to run without a valid licence rather than degrading silently.
- **`strip --strip-all`** — the symbol table is removed entirely.

Both were verified against the shipped binary: the stripped artifact exposes no
aowli source paths and no internal proc/type names.

## Distribution

Shipped as a **GitHub Release**,
[v0.3.0](https://github.com/aoughwl/aowli-release/releases/tag/v0.3.0), with the
binaries as release assets. Each build lists a SHA256 and a VirusTotal-by-hash
link so the asset can be verified independently of trusting the download host.

## Usage

```sh
chmod +x bin/aowli-interp
./bin/aowli-interp <module.s.aif>          # run
./bin/aowli-interp --trace <module.s.aif>  # execution call-tree
./bin/aowli-dbg  --break:29 <module.s.aif> # batch breakpoint, dumps frame vars
```

## Resolution order

Tools built against aowli (notably [aowlcode](aowlcode)'s `trace`/`debug`)
resolve a binary in this order, so a released install never needs source:

```
$AOWLI_BIN_DIR → ~/.aowl/bin → dev ~/aowli/bin
```
