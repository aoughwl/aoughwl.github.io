---
repo: aoughwl/aowli-release
---

# aowli-release — public binaries for the aowli interpreter

A prebuilt, **binary-only** distribution of [aowli](../aowli), the typed-NIF
interpreter for Nimony. The source stays private in `aoughwl/aowli`; this repo
ships only the built binaries, hardened for public distribution.

> **Now public** — anyone can access, download, and use it. Issues are welcome:
> [github.com/aoughwl/aowli-release/issues](https://github.com/aoughwl/aowli-release/issues).

[[toc]]

---

## What's in it

Two binaries, each a fully self-contained interpreter over a `.s.nif` (a
Nimony program's typed, post-semcheck NIF):

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
[v0.1.0](https://github.com/aoughwl/aowli-release/releases/tag/v0.1.0), with the
binaries as release assets. Each build lists a SHA256 and a VirusTotal-by-hash
link so the asset can be verified independently of trusting the download host.

## Usage

```sh
chmod +x bin/aowli-interp
./bin/aowli-interp <module.s.nif>          # run
./bin/aowli-interp --trace <module.s.nif>  # execution call-tree
./bin/aowli-dbg  --break:29 <module.s.nif> # batch breakpoint, dumps frame vars
```

## Resolution order

Tools built against aowli (notably [aowlcode](aowlcode)'s `trace`/`debug`)
resolve a binary in this order, so a released install never needs source:

```
$AOWLI_BIN_DIR → ~/.aowl/bin → dev ~/aowli/bin
```
