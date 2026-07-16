---
title: nimony-lsp
grand_parent: Documentation
parent: Tools
nav_order: 3
---

# nimony-lsp — Language Server + VSCode extension
{: .no_toc }

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/)
implementation for **[Nimony](../nimony)**, together with a full VSCode extension.

[Repo → github.com/aoughwl/nimony-lsp](https://github.com/aoughwl/nimony-lsp){: .btn .btn-primary }

The server is built directly on Nimony's own infrastructure. Navigation is served
by the compiler's `idetools` backend (`--def` / `--usages`), diagnostics by
parsing `nimony check`, and document symbols, hover, completion, semantic tokens,
inlay hints, and the type/call hierarchies by reading the NIF artifacts
(`nimcache/*.s.nif` / `*.s.idx.nif`) **in-process** through Nimony's own reusable
NIF libraries — no re-parsing of the on-disk S-expressions, no shelling out to a
second tool. One statically linked Nim binary speaks JSON-RPC over stdio; the
VSCode extension is a thin `vscode-languageclient` wrapper.

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Live as-you-type diagnostics

**Errors and warnings update on every keystroke**, against the *unsaved* buffer —
no save required.

This is possible because [our Nimony tree](../nimony#incremental-compilation--the-tooling-backend)
makes `nimony check` genuinely incremental: ~1.1s cold, but **~10–25ms** on a
warm re-check. On each change the server writes the live buffer to a stable
sibling temp file and checks it into an **isolated** nimcache
(`.nimlsp_livecache`) — isolation is the trick that keeps the re-check
incremental instead of invalidating the main cache. The temp file's diagnostics
are remapped back onto the real document URI. It runs synchronously on the stdio
loop (25ms doesn't lag typing) with no background daemon and no threads; `didOpen`
warms the cache once so even the first edit is fast.

{: .note }
> The live temp file is a **non-dot** sibling (`nimlsp_live_*`), hidden from the
> explorer via the extension's `files.exclude`. It must not start with a dot:
> Nimony derives a module id from the filename and a leading-dot name yields an
> empty id, crashing the checker (`nifreader: r.thisModule.len > 0`) — which had
> silently broken live diagnostics on every unsaved buffer until it was fixed.

---

## Responsiveness: one warm cache, one-shot checks

Navigation, hover, and references run as **one-shot `nimony check`** requests
against a **warm nimcache** — no daemon, the same one-shot + incremental-cache
shape as Araq's `nim track`. The whole model hinges on one thing: every request
must hit the same warm cache entry.

- **One shared warm cache.** Nimony keys its incremental cache by the file path
  *exactly as passed*. Diagnostics were warming it with the **absolute** path
  while hover/definition/references queried with the **relative** path, so the
  two never shared an entry — every navigation recompiled the whole project
  (~1.5s) on *every* request, forever. Funnelling every check through one
  canonical path form fixed it: on a real multi-module project, `definition`
  went **1481 ms → 62 ms** after a single ~1.47s warm on open.
- **Live-buffer navigation.** Hover / definition / references reflect *unsaved*
  edits (routed through the same live temp the diagnostics use), falling back to
  the last-saved answer when the buffer is mid-edit so nav never blanks.
- **Inlay hints only on real declarations.** The semchecked NIF carries
  compiler-synthesized decls (loop temps, `result`, lowered statements) whose
  line-info points at arbitrary tokens; hints are gated to sit exactly at an
  identifier end on a `let`/`var`/`const` line, killing bogus `: int` hints in
  comments and `import` words.
- **No overlapping servers.** The client serializes stop→start so rapid
  restarts/reloads can't spawn multiple servers that thrash one shared nimcache.

The tradeoff: the *first* interaction after opening a project pays one full
`nimony check` (~1.1–1.5s) to warm the cache; there's no daemon keeping it hot
across sessions. Everything after the warm is in the tens of milliseconds. Making
that first check cheap is a compiler-side problem (incremental `check`).

---

## Why

Nimony ships a real IDE backend (`idetools`) and a lowered, fully typed
representation of every module in `nimcache/` — but nothing consumed either from
an editor. `nimony-lsp` turns those existing outputs into the standard protocol
every editor already speaks, rather than building a parallel analysis engine:

| Editor need | What Nimony already emits | How the server uses it |
|---|---|---|
| Errors while you type | incremental `nimony check` diagnostics | parsed into `Diagnostic[]`; `Trace` lines fold into `relatedInformation`; run against the live buffer in an isolated cache |
| Go to definition / references | `idetools` `--def` / `--usages` records | parsed into `Location[]` and deduplicated |
| Outline, hover, completion | typed `.s.nif` / `.s.idx.nif` | read in-process via `nifstreams` / `nifcursors` / `nifindexes` / `symparser` |
| Types & call graph | the same typed NIF | type/call hierarchies walked directly from the object/proc graph |
| Syntax highlighting | — | a TextMate grammar (`source.nimony`) shipped with the extension |

Because the typed NIF is read directly, symbols and completion reflect what the
compiler actually resolved — not a regex approximation. Every capability has been
driven end-to-end against the compiled server binary.

---

## Capabilities

The server implements **26 LSP methods**:

| Group | Methods |
|---|---|
| Diagnostics | live (as-you-type) + on-save `publishDiagnostics`, with `relatedInformation` |
| Navigation | definition, declaration, references (cross-module), type definition, implementation |
| Reading | hover (signature + doc comment), completion (module, imported exports, dot-context members / UFCS) |
| Structure | documentSymbol, workspace/symbol, folding ranges, selection ranges |
| Editing | rename (+ prepareRename), signature help (overload-aware), document highlight |
| Semantic | semanticTokens (full + range, with declaration / readonly modifiers), inlay hints (inferred types + parameter names) |
| Hierarchies | call hierarchy (incoming / outgoing), type hierarchy (super / subtypes) |
| Extras | document links (imports → module files), code lens ("N references") |

Compiler-synthesized hooks (`=destroy`, `$`, backtick/dotted junk) are filtered
out of the outline and completion so you see only real symbols.

Member completion (`obj.`) resolves the receiver's fully-qualified type and
gathers its fields **and** UFCS methods across every module, walking the
`object of Base` inheritance chain — so a `Circle` value offers `Shape`'s
inherited fields and methods too, each annotated with its type. **References**
and **rename** span modules: a usage or rename in another open file is found and
updated, not left dangling.

### Optional warm-daemon backend

Definition / references / workspace-symbol can be routed through a persistent
`nimsem serve` worker (the [IC daemon](../nimony#incremental-compilation--the-tooling-backend))
for warm cross-module resolution on large trees. It's **opt-in** (set
`nimony.daemonPath`) and fail-safe: any miss falls back to the built-in idetools
path, so navigation never regresses or hangs.

---

## Editor setup (VSCode)

Build the server, then install the bundled extension:

```
cd server && nimble build          # -> server/bin/nimony-lsp
cd ../client && npm install && npm run bundle
npx vsce package                   # -> nimony-<version>.vsix
code --install-extension nimony-<version>.vsix --force
```

Then **Developer: Reload Window**. Open a Nimony file and you should see a
`Nimony: running` item in the status bar. The extension auto-resolves the server
binary from the sibling `server/bin/` directory; override with `nimony.serverPath`
if you install it elsewhere.

{: .note }
> The extension **must be bundled** (esbuild inlines `vscode-languageclient`).
> A plain `tsc` build ships an extension that can't find its dependency at
> runtime, because `.vscodeignore` excludes `node_modules`. `npm run bundle`
> (also the `vscode:prepublish` hook) handles this.

### Settings

| Setting | Default | Purpose |
|---|---|---|
| `nimony.serverPath` | *(auto)* | Path to the `nimony-lsp` binary |
| `nimony.nimonyPath` | `.../nimony/bin/nimony` | Path to the Nimony compiler |
| `nimony.extraPaths` | `[]` | Extra module search paths |
| `nimony.daemonPath` | *(empty)* | Optional `nimsem serve` binary for the warm backend |
| `nimony.trace.server` | `off` | JSON-RPC trace verbosity |

---

## Coordinate conventions

Single source of truth for line/column bases and units:

| Surface | line base | col base | col unit |
|---|---|---|---|
| LSP wire | 0 | 0 | UTF-16 code units |
| nimony diagnostics | 1 | 1 | bytes/codepoints |
| idetools input | 1 | 1 | codepoints |
| idetools output | 1 | 0 | codepoints |

`documents.nim` owns all conversion between LSP UTF-16 columns and byte offsets;
driver modules only do the 0/1-based line/col shift.

---

See the **[full reference](../reference/nimony-lsp)** for the module contracts and
the complete data-format ground truth.
