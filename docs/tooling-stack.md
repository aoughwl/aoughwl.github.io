# The tooling stack: incremental compilation, aowl-lsp & aiflens

How editor tooling for [Nimony](../nimony) actually works, end to end — the
**incremental compiler** at the bottom, the **[aowl-lsp](aowl-lsp)** server
that rides it, and the **[aiflens](aiflens)** NIF-reading core they share.

[[toc]]

---

## The three layers

| Layer | What it is | Role in tooling |
|---|---|---|
| **IC** — incremental `nimony check` | the compiler's one-shot check + on-disk artifact cache (`nimcache/*.s.nif`) | the *engine*: warm re-checks are ~0.00s, so navigation/diagnostics can be one-shot instead of a daemon |
| **aowl-lsp** | a JSON-RPC LSP server + VSCode client | the *shaping*: turns compiler output into hover, definition, references, completion, inlay, semantic tokens, live diagnostics |
| **aiflens** | a thin library/CLI over Nimony's NIF libraries | the *reader*: walks `.s.nif` artifacts into structured facts (symbols, types, outline) that the LSP shapes |

The design commitment, aligned with Araq's `nim track` direction: **one-shot
checks against a warm cache, no semantic daemon.** No long-lived analysis
process to drift out of sync — the compiler's own incremental cache *is* the
state.

---

## Incremental compilation: the engine

A cold `nimony check` on a real module is ~1.1–1.5s. A **warm** re-check — same
sources on disk, nothing changed — is **~0.00s**. That gap is the entire reason
one-shot tooling is viable: after the first check, every hover/definition/
keystroke-check is effectively free.

Warmth is fragile. Two non-obvious failure modes broke it (both now fixed in
aowl-lsp — see below); they are properties of *IC itself*, not the LSP:

### 1. The cache is keyed by the path string as given

nimony keys its incremental cache by the file path **exactly as passed**. Check
a file by its **absolute** path and then query it by its **relative** path and
you hit two *different* cache entries — the second is always cold. Any tool must
funnel every invocation of a given file through one canonical path form.

### 2. `--isMain` vs. dependency artifacts thrash a shared cache
> nimony writes **different artifacts** for a module
> compiled as the main module (`--isMain`) versus as a dependency of some other
> main module. If two different main modules share **one** `nimcache`, checking
> the second **overwrites** the shared-module artifacts the first needs — and
> from then on **neither warms again**. Every check reverts to a full ~1.3s
> recompile, forever.

Proven directly: `check registry.nim` warms to 0.00s; a single
`check nodes.nim` (a *different* main module) knocks registry back to 1.25s, and
after that nothing warms. An editor checks **every open file as its own main
module**, so the moment you touch a second file the shared cache is poisoned.
This was the true cause of "Loading forever" and "typing does nothing" on real
multi-file projects.

**The fix (IC-aware):** give each open file its **own** nimcache
(`nimcache/lsp/<file>`). Each stays warm independently; interleaving files no
longer thrashes. Measured: interleaved hovers **71ms → 10ms** instead of
~1.3s-each-forever.

---

## aowl-lsp: shaping IC into an editor experience

Every feature request is a one-shot `nimony check` against the (now per-file)
warm cache:

- **diagnostics** — parse `nimony check` output; run as-you-type against an
  isolated live cache so unsaved buffers get errors without a save.
- **definition / references / hover** — the compiler's `idetools`
  (`--def` / `--usages`), reading the *unsaved buffer* when it differs from disk.
- **completion, inlay hints, document symbols, semantic tokens, type/call
  hierarchies** — read the `.s.nif` artifact directly (this is the aiflens
  layer, below).

### Symptoms, root causes, fixes

| Symptom | Root cause | Fix |
|---|---|---|
| Every nav recompiled the whole project, forever | abs-path warm vs. rel-path query → separate cache entries | one canonical path form (`canonFile`) |
| "Loading forever" / "typing does nothing" across files | `--isMain` vs. dep artifacts thrashing one shared cache | per-file nimcache (`moduleCacheDir`) |
| Completion / inlay / symbols returned nothing | the per-file fix moved artifacts; readers still walked the old dir | route all readers through the same per-file dir |
| Live diagnostics silently produced nothing on unsaved buffers | the live temp file was a **dotfile**; a leading-dot filename yields an empty module id and crashes the checker (`nifreader: r.thisModule.len > 0`) | non-dot temp name, hidden via `files.exclude` |
| Hover/definition stale while editing | handlers read the on-disk file | route nav through the live buffer temp when dirty |
| Bogus `: int` inlay hints in comments/imports | synthesized NIF decls with misattributed line-info | gate hints to real `let`/`var`/`const` sites |
| Up to 3 servers thrashing one cache | client ran `startClient()` before `stopClient()` finished | serialize stop→start in the client |

Full ledger: the repo's [`doc/CHANGES.md`](https://github.com/aoughwl/aowl-lsp/blob/main/doc/CHANGES.md).

---

## aiflens: the shared NIF-reading core

Everything the LSP does *beyond* diagnostics and `--def`/`--usages` — nested
document symbols, hover signatures, member/UFCS completion, semantic tokens,
inlay types — comes from **reading the `.s.nif` artifact**. That reading is
exactly what [aiflens](aiflens) does: a thin library over Nimony's own NIF
libraries that emits structured facts (the flat symbol table, outlines, types),
and which also backs the `aowlcode` MCP plugin via its CLI.

Today aowl-lsp's `nifindex.nim` carries its own copy of that NIF-walk. The
**convergence plan**: extract aiflens's core as a linkable library, have the LSP
**link** it (not shell out — that would add per-request process-spawn latency),
and keep only the LSP-shaping (SymbolKind mapping, coordinate conversion, wire
types, the member-completion temp-compile) on top. One reader, two mouths
(aiflens CLI + linked lib), no drift.

On the **daemon question**, both agree with Araq: navigation rides the one-shot
`idetools`/`track` path; any `serve` is scoped to *NIF-index caching only*
(keeping hot `.s.idx.nif` indexes in RAM), never a semantic server.

---

## Roadmap: what would make IC a great tooling backend

These are **compiler-side** primitives, not things the LSP or aiflens should
reimplement:

1. **Structured/JSON diagnostics from `nimony check`** — kill the fragile
   text-scraping; emit `{file, range, severity, code, message, related[]}`.
2. **Overlay / incremental `check` for unsaved buffers** — check editor contents
   without writing a temp file (`--overlay`/`--stdin`), with partial results on
   parse error. This removes the temp-file dance *and* makes cold-open cheap —
   the last real rough edge.
3. **A `--def`/`track` that returns the resolved type + signature at a position**
   — exact hover and go-to-type-definition for free, instead of the LSP
   re-deriving types from `.s.nif`.

Everything else is polish: per-file cache cleanup for closed files, background
pre-warming of open files, and the aiflens core extraction.
&lt;/content>
