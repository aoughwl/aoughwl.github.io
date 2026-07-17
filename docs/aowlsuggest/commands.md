---
nav_exclude: true
title: Commands
parent: Suggestions — aowlsuggest
grand_parent: aowlmony
nav_order: 2
---

# Commands
{: .no_toc }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

Every command shares three flags: `--parser:PATH` picks the aowlparser binary
(else `$AOWLPARSER`, else the default checkout); `--stdin` reads source from
stdin instead of a file; `--filename:NAME` sets the path reported in diagnostics
and URIs when reading stdin.

## `fix`

```sh
aowlsuggest fix <file> [--write] [--dry-run]
```

Applies the diagnostics' repairs to the source. By default (`--dry-run`) it
prints a unified diff and applies nothing; `--write` writes the corrected file.
Independent errors are all repaired in one pass, cascades included.

```console
$ aowlsuggest fix cascade.nim --write
fixed cascade.nim: applied 2 change(s)
  - insert '=' (was missing-routine-equals at 1:1)
  - change '=' to '==' (was assignment-in-condition at 2:8)
```

Only the four codes with an unambiguous, localized repair are auto-applied (see
[Quick-fixes](fixes)); any other diagnostic that carries a repair hint is
reported as a **suggestion** that needs human judgement, never applied
automatically:

```console
$ aowlsuggest fix elif.nim
no automatic fixes for elif.nim

suggestions (need human judgement — not auto-applied):
  elif.nim:1:1: error[expected-condition]: 'elif' requires a condition before ':'
  help: add a condition, e.g. 'elif cond:'
```

## `lint`

```sh
aowlsuggest lint <files...> [--format:json]
```

Batch-lints many files. Human-readable by default; `--format:json` emits a single
object with a per-file breakdown and a summary. Exits non-zero if any file has an
error-severity diagnostic or fails to run — CI-friendly.

```console
$ aowlsuggest lint src/*.nim
src/a.nim:12:6: error[assignment-in-condition]: '=' assigns; this 'if' condition needs a comparison
  help: did you mean '=='?

3 file(s) checked, 1 with issues: 1 error(s), 0 warning(s)
$ echo $?
1
```

```json
{
  "files": [
    { "file": "a.nim", "ok": true, "errorCount": 1,
      "diagnostics": [ { "file": "a.nim", "severity": "error",
        "code": "assignment-in-condition", "line": 12, "col": 5, "endCol": 6,
        "fix": "did you mean '=='?" } ] }
  ],
  "summary": { "files": 3, "errors": 1, "warnings": 0, "runFailures": 0 }
}
```

## `lsp`

```sh
aowlsuggest lsp <file>
```

Emits an editor payload: LSP `Diagnostic` objects and `CodeAction` quick-fixes in
one JSON object. Covered in full under [Editor integration](editor-integration).

## `check`

```sh
aowlsuggest check <file> [--format:json]
```

A thin pass-through of the raw diagnostics — the same information as the parser's
own `check`, in aowlsuggest's text or native-JSON shape (line 1-based, col
0-based, plus the owning `file`). Useful as a scriptable oracle.

## `version`

```sh
aowlsuggest version      # or --version
```

## stdin: linting an unsaved buffer

Editors want to check a buffer *before* it is written to disk. Pass `--stdin`
(with an optional `--filename:` for the reported path) to any of `check`, `lsp`,
or `fix`:

```console
$ printf 'if x = 5:\n  discard\n' | aowlsuggest check --stdin --filename:buf.nim
buf.nim:1:6: error[assignment-in-condition]: '=' assigns; this 'if' condition needs a comparison
  help: did you mean '=='?
```

In this mode `fix` writes the **corrected source to stdout** (pipe it straight
back into the buffer) and its summary to stderr, so the two never mix:

```console
$ printf 'if x = 5:\n  discard\n' | aowlsuggest fix --stdin 2>/dev/null
if x == 5:
  discard
```
