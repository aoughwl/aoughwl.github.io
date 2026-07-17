---
nav_exclude: true
title: The contract
parent: Suggestions — aowlsuggest
grand_parent: aowlmony
nav_order: 1
---

# The contract
{: .no_toc }

The single seam between aowlsuggest and [aowlparser](../aowlparser). Everything
aowlsuggest knows about a program comes through it; nothing else does.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## One boundary, not two

aowlsuggest talks to the parser over exactly one interface:

```sh
aowlparser check --diagnostics:json <file.nim>
```

which emits a JSON array; each element is a diagnostic:

```json
{
  "severity": "error",
  "code": "assignment-in-condition",
  "message": "'=' assigns; this 'if' condition needs a comparison",
  "line": 4, "col": 5, "endCol": 6,
  "fix": "did you mean '=='?",
  "related": { "message": "'(' opened here", "line": 3, "col": 10 }
}
```

The process exits non-zero **iff** any error-severity diagnostic was produced, so
the same command doubles as a CI gate. `src/contract.nim` is the *only* module in
aowlsuggest that crosses this boundary — the lexer, the grammar, the recovery
logic, and the emission of these diagnostics all live in aowlparser and stay
there.

## Coordinates

Positions follow the parser's token convention:

| field | meaning |
|-------|---------|
| `line` | 1-based line number |
| `col` | 0-based column of the span's first character |
| `endCol` | 0-based column just past the span (exclusive; `== col` for a point) |

aowlsuggest converts to whatever a consumer needs — LSP's fully 0-based ranges,
or a 1-based column for human-readable output — but it never invents positions.

## Read defensively

The schema is treated as **versionable**: aowlsuggest tolerates unknown extra
fields (so aowlparser can add to the diagnostic without breaking older
consumers), and fails loudly only when a genuinely required field — `code`,
`line`, `col` — is missing. A `related` block is optional; a `fix` hint is
optional.

## A capture detail worth knowing

aowlparser prints the whole diagnostic array on a **single line**. nimony's
`osproc.execCmdEx` captures a child's output line by line through a fixed-size
buffer, and mangles any line longer than that buffer — which corrupts the JSON.
So the contract layer does not use `execCmdEx`: it redirects the parser's stdout
to a temporary file and reads it whole, which is immune to the buffer size. This
is invisible to callers but is the reason `runCheckerOnFile` looks the way it
does.

## When the JSON isn't enough

If a suggestion ever needs information the diagnostic doesn't carry, that is
**not** a licence to re-derive it by re-parsing. It is a *parser API request*:
a deliberate, additive change to aowlparser's schema, made in that repo and
bumping the contract in lockstep. The repo's `PARSER_API_REQUESTS.md` tracks
these. The current open one asks aowlparser to emit a **structured** `edit`
(offset + replacement) alongside the human-readable `fix` string, so aowlsuggest
could apply repairs for *any* code the parser knows how to fix, instead of the
hand-written mapping described in [Quick-fixes](fixes).
