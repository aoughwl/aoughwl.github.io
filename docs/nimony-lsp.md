---
title: nimony-lsp
parent: Projects
nav_order: 4
---

# nimony-lsp — Language Server + VSCode extension
{: .no_toc }

A [Language Server Protocol](https://microsoft.github.io/language-server-protocol/)
implementation for **[Nimony](../nimony)**, together with a full VSCode extension.

[Repo → github.com/aoughwl/nimony-lsp](https://github.com/aoughwl/nimony-lsp){: .btn .btn-primary }

The server is built directly on Nimony's own infrastructure. Navigation is served
by the compiler's `idetools` backend (`--def` / `--usages`), diagnostics by
parsing `nimony check`, and document symbols, hover, and completion by reading the
NIF artifacts (`nimcache/*.s.nif` / `*.s.idx.nif`) **in-process** through Nimony's
own reusable NIF libraries — no re-parsing of the on-disk S-expressions, no
shelling out to a second tool. One statically linked Nim binary speaks JSON-RPC
over stdio; the VSCode extension is a thin `vscode-languageclient` wrapper.

## Why

Nimony ships a real IDE backend (`idetools`) and a lowered, fully typed
representation of every module in `nimcache/` — but nothing consumed either from
an editor. `nimony-lsp` turns those existing outputs into the standard protocol
every editor already speaks, rather than building a parallel analysis engine:

| Editor need | What Nimony already emits | How the server uses it |
|---|---|---|
| Errors while you type | `nimony check` diagnostics on stdout | parsed into `Diagnostic[]`; `Trace` lines fold into `relatedInformation` |
| Go to definition / references | `idetools` `--def` / `--usages` records | parsed into `Location[]` and deduplicated |
| Outline, hover, completion | typed `.s.nif` / `.s.idx.nif` | read in-process via `nifstreams` / `nifcursors` / `nifindexes` / `symparser` |
| Syntax highlighting | — | a TextMate grammar (`source.nimony`) shipped with the extension |

Because the typed NIF is read directly, symbols and completion reflect what the
compiler actually resolved — not a regex approximation. Every capability has been
driven end-to-end against the compiled server binary and verified against
`nimony` 0.4.0.

See the [repo README](https://github.com/aoughwl/nimony-lsp) for build, editor
setup, configuration, coordinate conventions, and the data-format ground truth.
