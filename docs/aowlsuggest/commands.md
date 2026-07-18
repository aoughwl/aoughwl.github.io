# Commands

[[toc]]

---

`fix` and `lint` accept **files or directories** — a directory is walked for
`*.nim`, with repeatable `--exclude:GLOB` (supporting `*` and `?`) to prune it.
Shared flags: `--parser:PATH` picks the aowlparser binary (else `$AOWLPARSER`,
else the default checkout); `--stdin` reads source from stdin; `--filename:NAME`
sets the path reported in diagnostics and URIs when reading stdin; `--color`
colorizes human output; `--no-suppress` ignores inline suppression markers.

## `fix`

```sh
aowlsuggest fix <file> [--write] [--dry-run] [--check]
```

Applies the diagnostics' repairs to the source. By default (`--dry-run`) it
prints a unified diff and applies nothing; `--write` writes the corrected file.
`--check` (gofmt -l / prettier --check style) writes nothing and **exits
non-zero if any fix is available** — the CI gate for "this code is already
clean" (pair it with `--pedantic` to enforce style too). Independent errors are
all repaired in one pass, cascades included.

```console
$ aowlsuggest fix cascade.nim --write
fixed cascade.nim: applied 2 change(s)
  - insert '=' (was missing-routine-equals at 1:1)
  - change '=' to '==' (was assignment-in-condition at 2:8)
```

Only the codes with an unambiguous, localized repair are auto-applied (see
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
aowlsuggest lint <paths...> [--format:text|json|sarif] [--stats]
                            [--max-warnings:N] [--quiet] [--exclude:GLOB]
```

Batch-lints files and directories. Human-readable by default; `--format:json`
emits a per-file breakdown with a summary; `--format:sarif` emits SARIF 2.1.0 for
GitHub code scanning and other dashboards (see [Editor
integration](editor-integration#ci-formats-sarif)). `--stats` adds a per-code
count. Exits non-zero if any file has an error-severity diagnostic or fails to
run — CI-friendly. `--max-warnings:N` also fails the run when the warning count
exceeds `N` (the eslint-style adoption gate); `--quiet` shows only errors in text
output (warnings are still counted toward the gate).

```console
$ aowlsuggest lint src --exclude:'*/vendor/*' --stats
src/a.nim:12:6: error[assignment-in-condition]: '=' assigns; this 'if' condition needs a comparison
  help: did you mean '=='?

by code:
  1	assignment-in-condition

7 file(s) checked, 1 with issues: 1 error(s), 0 warning(s)
```

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

## `lsp` and `lsp-server`

```sh
aowlsuggest lsp <file>        # one-shot payload
aowlsuggest lsp-server        # a persistent stdio Language Server
```

`lsp` emits a one-shot editor payload; `lsp-server` is a full stdio JSON-RPC
Language Server. Both are covered under [Editor
integration](editor-integration).

## `explain`

```sh
aowlsuggest explain [code] [--format:json]
```

Describes a diagnostic code — what it means, a bad/good example, and whether it
is auto-fixable — or, with no argument, lists every known code. The knowledge
base is derived from aowlparser's diagnostic set.

```console
$ aowlsuggest explain assignment-in-condition
assignment-in-condition — Assignment '=' where a comparison was meant

A bare '=' at the top level of an if/elif/while/when condition assigns rather
than compares — almost always a typo for '=='.

  bad:  if x = 5:
  good: if x == 5:

auto-fixable: yes
```

## Style lint policies

aowlparser owns diagnostic *emission*, and several of its stylistic checks are
**off by default** — which is exactly what keeps the zero-false-positive corpus
clean. aowlsuggest turns them on **on request** and makes each actionable with a
verified fix. Nothing changes in the default pipeline; these are strictly opt-in.

```sh
aowlsuggest lint --pedantic          <paths...>   # trailing-ws + final-newline + bom
aowlsuggest fix  --style:lf  --write <paths...>   # normalize CRLF → LF
aowlsuggest fix  --pedantic  --write <paths...>   # apply the whole safe style set
```

| flag | policy enabled | code surfaced |
|------|----------------|---------------|
| `--style:trailing-whitespace` | trailing whitespace | `trailing-whitespace` |
| `--style:final-newline` | require a final newline | `missing-final-newline` |
| `--style:lf` / `--style:crlf` | assert an EOL convention | `line-ending` |
| `--style:bom` | reject a UTF-8 BOM | `bom-rejected` |
| `--style:c-operators` | flag `&&` / `\|\|` (use `and` / `or`) | `c-style-operator` *(suggestion only)* |
| `--style:semicolons` | remove a redundant trailing `;` | `redundant-semicolon` |
| `--style:idioms` | flag `x == true` / `not not x` / `not x in y` / `not x == y` | `redundant-bool-literal`, `double-negation`, `not-in-precedence`, `not-compare-precedence` *(suggestion only)* |
| `--style:float-equality` | flag exact `==` / `!=` on a float literal | `float-equality` *(suggestion only)* |
| `--style:indent-consistency` | derive & check the indent step | `indent-consistency` *(advisory)* |
| `--indent-width:N` | warn when indent isn't a multiple of `N` | `indent-width` *(advisory)* |
| `--pedantic` | trailing-whitespace + final-newline + bom + float-equality | those four |

`--style:` is repeatable. The whitespace/BOM flags flow through the same verify
loop as every other fix, so a style edit is kept only if re-checking under the
*same* policy strictly improves it — and each touches nothing but
whitespace/BOM, so it can never change what the program means. The **idiom** and
**float-equality** lints are different: they fire on *valid* code (a redundant
bool compare, a double negation, fragile exact-float equality), so they stay
**suggestions** — reported with concrete guidance, never auto-applied, since the
rewrite (`not <expr>`, an epsilon tolerance) needs your eye.

## Project config — `.aowlsuggest`

A repo can commit its lint/style defaults once so `lint`, `fix`, and
`lsp-server` all behave identically — and so an [aowllsp](aowl-lsp) editor
session inherits the same policy. Discovery walks **up** from the target file's
directory (or `--filename`) to the filesystem root and uses the first
`.aowlsuggest` it finds.

```ini
# .aowlsuggest
pedantic     = true
style        = trailing-whitespace, final-newline, lf
indent-width = 2
exclude      = tests/fixtures/*, vendor/*
suppress     = true
parser       = /opt/aowlparser/bin/aowlparser
```

The config sets **defaults**; a command-line flag always overrides (scalars) or
extends (lists) it, so it never weakens any guarantee. `--config:PATH` forces a
specific file; `--no-config` ignores discovery. Unknown keys degrade to a stderr
warning; an explicit `--config` that can't be read is a hard error.

## Inline suppression

A project can silence an accepted diagnostic with a comment. This is a **source
line scan** (it looks for the marker after a `#`), not a reparse:

```nim
foo(bar)     # aowlsuggest:ignore                  suppress every code on this line
baz(qux)     # aowlsuggest:ignore[expected-colon]  suppress only these codes
# aowlsuggest:ignore-next
risky_line()                                       # suppressed by the line above
```

Suppression is on by default for `lint` and `check`; `--no-suppress` disables it.

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
