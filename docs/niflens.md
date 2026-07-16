---
title: niflens
grand_parent: Documentation
parent: Tools
nav_order: 2
---

# niflens — a NIF lens for tooling
{: .no_toc }

A thin CLI over [Nimony](../nimony)'s own NIF libraries (`nifreader` /
`nifstreams` / `nifcursors` / `nifindexes`). It reads `nimcache/*.nif` artifacts
with the **real parser** and emits compact JSON for a host tool to consume.

[Repo → github.com/aoughwl/niflens](https://github.com/aoughwl/niflens){: .btn .btn-primary }

## Why

Tools that inspect NIF — an LSP, the [nim-code](nim-code) plugin, a formatter —
otherwise re-implement a NIF reader (usually a regex/hand-rolled scanner) and
inherit a class of bugs: approximate line-info decoding, mishandled escapes, a
stale tag vocabulary, no real index reading. Because niflens *links the compiler's
libraries*, its output always matches the toolchain that produced the file, and it
tracks NIF format bumps (`nif26` → `nif27` → …) for free.

Versus a regex reimplementation, `niflens decls` returns the **name** glyph
position (not the enclosing keyword), the **full module-qualified symId**
(`add.0.<module>`, not a truncated `add.0.`), and the complete symbol table — all
with the compiler's own line info.

## Design

niflens is the CLI/daemon frontend of a shared NIF core intended to back **both**
the nim-code plugin and a Nimony LSP. The host shells out to niflens (the same
subprocess pattern it uses for `nimony` / `nimsem`) and falls back to its own
reader if the binary is absent. Subprocess (not FFI) keeps crash isolation, avoids
an ABI/GC boundary, and needs no per-platform shared library.

## Build & use

niflens links Nimony's `src/lib` NIF modules — a **source** dependency, not a
nimble package. Point `NIMONY_SRC` at a Nimony checkout:

```
NIMONY_SRC=/path/to/nimony nimble build      # -> bin/niflens
```

```
niflens decls <file.s.nif> [symbol]   # declaration sites -> JSON array
niflens version
```

`decls` emits one object per `SymbolDef`: `{sym, name, kind, file, line, col}`
(`col` is 0-based, idetools convention). An optional `symbol` filters by full
symId (exact / prefix) or human base name.

```json
[{"sym":"addup.0.mwsmvs","name":"addup","kind":"proc","file":"m.nim","line":1,"col":5}]
```

## Commands

| Command | What it returns |
|---|---|
| `decls` | declaration sites (SymbolDef walk) |
| `render` | pseudo-Nim per top-level decl |
| `index` | `.s.idx.nif` contents via `nifindexes` (checksum, converters, re-exports) |
| `outline` | top-level declarations with positions |
| `query` | subtrees matching a needle → canonical NIF snippet |
| `serve` | line-oriented stdio daemon (one process across requests) |

**Status & roadmap:** the `serve` daemon and the shared NIF core both exist. The
remaining convergence step — having **[nimony-lsp](nimony-lsp)** link niflens's
core directly (instead of its own in-process NIF readers) — is deliberately
deferred: it wants a real extraction with tests, not a blind cross-repo
restructure. Next for `serve` itself: cache parsed `TokenBuf`s of hot modules
across requests, the persistent-index win that benefits both consumers.
