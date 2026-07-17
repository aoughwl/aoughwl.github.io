---
nav_exclude: true
title: Editor integration
parent: Suggestions — aowlsuggest
grand_parent: aowlmony
nav_order: 4
---

# Editor integration
{: .no_toc }

The `lsp` command turns diagnostics into an editor-ready payload: LSP
`Diagnostic` objects and `CodeAction` quick-fixes, derived entirely from the
parser's output.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The payload

```sh
aowlsuggest lsp <file>          # or: … lsp --stdin --filename:buf.nim
```

emits one JSON object:

```json
{
  "uri": "file:///abs/path/buf.nim",
  "diagnostics": [ … LSP Diagnostic objects … ],
  "codeActions": [ … LSP CodeAction quick-fixes … ]
}
```

## Diagnostics

Each LSP `Diagnostic` uses fully **0-based** ranges (the parser's 1-based line
becomes 0-based; its column is already 0-based), the stable `code`, a `source`
of `"aowlparser"`, and — when the diagnostic has one — `relatedInformation`
built from the `related` block, so an editor renders the secondary location (the
`(` an unclosed bracket was opened at) as its own marker instead of buried text.

```json
{
  "range": { "start": {"line":0,"character":5}, "end": {"line":0,"character":6} },
  "severity": 1,
  "code": "assignment-in-condition",
  "source": "aowlparser",
  "message": "'=' assigns; this 'if' condition needs a comparison"
}
```

Severities map `error → 1`, `warning → 2`, `hint → 4`.

## Code actions & "did you mean" ranking

Each diagnostic contributes every plausible auto-fix as a `CodeAction` carrying a
`WorkspaceEdit`. When there is more than one — a mismatched bracket, for
instance, can be repaired at the **close** or at the **open** — they are emitted
as a *ranked set*: the first is marked `isPreferred` (what `fix` would apply), the
rest are equally valid alternatives the editor offers the user.

```json
[
  { "title": "change ']' to ')'", "kind": "quickfix", "isPreferred": true,
    "edit": { "changes": { "file:///…": [ { "range": …, "newText": ")" } ] } } },
  { "title": "change the opening '(' to '['", "kind": "quickfix",
    "isPreferred": false,
    "edit": { "changes": { "file:///…": [ { "range": …, "newText": "[" } ] } } }
]
```

The `WorkspaceEdit` ranges are converted from the same byte-offset edits the
`fix` command applies, so an editor accepting the preferred action gets exactly
the repair `fix --write` would have made.

## Unsaved buffers

Editors check a buffer before it hits disk. `--stdin` feeds the current buffer
in; `--filename:NAME` supplies the path to report in the `uri` and in
diagnostics. This means the whole surface — diagnostics, related locations, and
quick-fixes — works on in-flight edits, not just saved files. See
[Commands](commands#stdin-linting-an-unsaved-buffer).

## The LSP server

`aowlsuggest lsp-server` is a persistent **Language Server** over stdio, so an
editor drives it directly rather than shelling out per file. It speaks JSON-RPC
2.0 with LSP's `Content-Length` framing and implements:

| message | behaviour |
|---------|-----------|
| `initialize` | advertises `textDocumentSync: 1` (Full) and `codeActionProvider` |
| `textDocument/didOpen` | store the buffer, publish diagnostics |
| `textDocument/didChange` | replace the buffer (full sync), re-publish |
| `textDocument/didSave` | re-publish for the saved buffer |
| `textDocument/didClose` | drop the buffer, clear its diagnostics |
| `textDocument/codeAction` | quick-fixes for diagnostics in the requested range |
| `shutdown` / `exit` | clean teardown |

Each `didOpen`/`didChange` runs aowlparser on the current buffer and pushes a
`textDocument/publishDiagnostics` notification; the diagnostics and the
`codeAction` responses are the exact objects described above. A minimal session:

```
→ initialize                     ← { capabilities: { textDocumentSync: 1, codeActionProvider: true } }
→ didOpen  "if x = 5:\n …"        ← publishDiagnostics [ assignment-in-condition ]
→ codeAction (line 0)            ← [ { title: "change '=' to '=='", … } ]
→ didChange "let ok = 1\n"        ← publishDiagnostics [ ]
→ shutdown / exit
```

## CI formats: SARIF

For batch use, `lint --format:sarif` emits **SARIF 2.1.0** — the format GitHub
code scanning ingests to annotate pull requests. Rules are the distinct codes
seen, described from the [explain](commands#explain) knowledge base; regions use
SARIF's 1-based line and column convention.

```yaml
# a CI step
- run: aowlsuggest lint src --format:sarif > aowlsuggest.sarif
- uses: github/codeql-action/upload-sarif@v3
  with: { sarif_file: aowlsuggest.sarif }
```

`lint` also offers `--format:json` (a per-file breakdown plus a summary) and a
non-zero exit on any error, so it slots into any CI without SARIF too.
