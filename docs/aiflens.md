---
repo: aoughwl/aiflens
---

# aiflens — a NIF lens for tooling

A thin CLI over [Nimony](../nimony)'s own NIF libraries (`nifreader` /
`nifstreams` / `nifcursors` / `nifindexes`). It reads `nimcache/*.nif` artifacts
with the **real parser** and emits compact JSON for a host tool to consume.

## Why

Tools that inspect NIF — an LSP, the [aowl-code](aowl-code) plugin, a formatter —
otherwise re-implement a NIF reader (usually a regex/hand-rolled scanner) and
inherit a class of bugs: approximate line-info decoding, mishandled escapes, a
stale tag vocabulary, no real index reading. Because aiflens *links the compiler's
libraries*, its output always matches the toolchain that produced the file, and it
tracks NIF format bumps (`nif26` → `nif27` → …) for free.

Versus a regex reimplementation, `aiflens decls` returns the **name** glyph
position (not the enclosing keyword), the **full module-qualified symId**
(`add.0.<module>`, not a truncated `add.0.`), and the complete symbol table — all
with the compiler's own line info.

## Design

aiflens is the CLI/daemon frontend of a shared NIF core intended to back **both**
the aowl-code plugin and a Nimony LSP. The host shells out to aiflens (the same
subprocess pattern it uses for `nimony` / `nimsem`) and falls back to its own
reader if the binary is absent. Subprocess (not FFI) keeps crash isolation, avoids
an ABI/GC boundary, and needs no per-platform shared library.

## Build & use

aiflens links Nimony's `src/lib` NIF modules — a **source** dependency, not a
nimble package. Point `NIMONY_SRC` at a Nimony checkout:

```
NIMONY_SRC=/path/to/nimony nimble build      # -> bin/aiflens
```

```
aiflens decls <file.s.nif> [symbol]   # declaration sites -> JSON array
aiflens version
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
| `calls` | call sites within a module (caller → callee edges) |
| `types` | object-type declarations + their inheritance parent |
| `members` | **type-directed members of a receiver** — an identifier's fields, enum values, and first-parameter routines (UFCS/methods), following `object of Base` for inherited members |
| `typeat` | **type at a source position** — resolves the symbol at `<line> <col>` to its type base name; the primitive that makes member completion work for *expressions* (`a.b.c.` field chains, shadowed names) not just bare identifiers |
| `serve` | line-oriented stdio daemon (one process across requests) |

**Status & roadmap:** the `serve` daemon and the shared NIF core both exist. The
remaining convergence step — having **[aowllsp](aowllsp)** link aiflens's
core directly (instead of its own in-process NIF readers) — is deliberately
deferred: it wants a real extraction with tests, not a blind cross-repo
restructure. Next for `serve` itself: cache parsed `TokenBuf`s of hot modules
across requests, the persistent-index win that benefits both consumers.
