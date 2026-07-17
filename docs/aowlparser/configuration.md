---
nav_exclude: true
title: Configuration
parent: Parser — aowlparser
grand_parent: aowlmony
nav_order: 4
---

# Configuration
{: .no_toc }

Every option below is **off / neutral by default**, so a plain
`aowlparser p in.nim out.p.aif` produces the same tree as native `nifler` —
byte-identical across the nimony compiler source, structure-identical everywhere
tested (bar the one-line `(.vendor "aowlparser")` header, which aowlparser always
stamps as its own; see [Coverage](known-gaps)).
The flags exist for editors, linters, pipelines, and non-Nim-standard sources;
apart from `--curly` (which only *adds* accepted syntax) and the opt-in
`--doc-comments:off`, none of them can change the AIF a run emits — they gate
input acceptance, add diagnostics, or move I/O.

```
usage: aowlparser [OPTIONS] p <in.nim> [out.p.aif]
```

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Block bodies

### `--curly`

Lets a `{ … }` block body stand in **anywhere** a `:` body is accepted, and the
two styles may be mixed freely:

```nim
if c { echo a } else: echo b       # brace + colon in one statement
while x { dec x; use x }            # `;`-separated statements inside a brace

proc add(a, b: int): int {          # routine bodies too — `{ … }` for `= …`
  result = a + b
}
proc twice(x: int): int {.inline.} {  # a pragma AND a curly body
  result = x * 2
}
```

A **control-flow** block `{` is disambiguated from a set literal by context — it
must follow an operand (`if c {`) or a bodiless-block keyword (`else {`, `try {`,
`block {`, `finally {`, `defer {`) — so a set in the head (`if {1} == x { … }`)
is not mistaken for the body.

A **routine** body (`proc`/`func`/`method`/`iterator`/`converter`/`template`/
`macro`) may use `{ … }` in place of the `= …` body. Here the body `{` is a bare
brace (not a `{.` pragma) with **no preceding `=`**, so a set-literal expression
body — `proc empty(): set[int] = {}` — keeps its `=` and is never read as a
block. A one-line `= body` is left untouched.

Either way the curly form emits the **same AIF** as the `:`/`=` form. This is a
aowlparser extension; native nifler has no equivalent, so output stays
nifler-compatible only while it is off.

## Indentation & whitespace

Nim's layout is column-based, and classic Nim is **spaces-only** — its lexer
hard-errors on a tab in indentation. aowlparser keeps that as the default but can
relax it for tab-using sources and validate indentation for tooling. None of these
change the emitted AIF: the off-side rule is a *relative* column comparison, so a
tab-indented file parses to the same tree as its space-indented equivalent.

| flag | default | effect |
|:--|:--|:--|
| `--tabs:spaces\|tabs\|both` | `spaces` | What may indent a line. `spaces` = classic-Nim (a stray tab = one column). `tabs` = tabs allowed, each advancing `--tab-width` columns. `both` = either, and a line that *mixes* them in its leading whitespace is reported on stderr. |
| `--tab-width:N` | `8` | Columns a `\t` advances when tabs are permitted. Scales the recorded `indent`/`col`; the parse structure is width-independent. Ignored under `--tabs:spaces`. |
| `--tab-stops:hard\|round` | `hard` | `hard` = additive (`col += tab-width`). `round` = advance to the next multiple of `--tab-width` (true tab-stop behaviour). They agree at column 0, so indentation is identical; they differ only for a tab that follows mid-line content. |
| `--indent-width:N` | `0` (off) | Advisory. When `N > 0`, warn on stderr for any line whose indentation column is not a multiple of `N`. |
| `--indent-consistency` | off | Advisory. Derives the indent unit from the first line that indents deeper than its predecessor, then warns for any indentation that is not a whole multiple of that derived unit — a lexer-level approximation of "siblings disagree on the step". |

## Source hygiene (advisory)

Diagnostic-only checks for linting and CI. Each writes warnings to **stderr** and
leaves both stdout and the emitted AIF untouched.

| flag | default | effect |
|:--|:--|:--|
| `--final-newline:require` | off | Warn if the source does not end with a terminating `\n`. |
| `--newline:lf\|crlf\|any` | `any` | Assert an end-of-line convention. `any` = accept anything (CR is normalised as before). `lf` / `crlf` warn per line ending that doesn't match. |
| `--trailing-whitespace:warn` | off | Warn once per physical line that has a space or tab immediately before its newline. |
| `--bom:strip\|reject` | *(legacy skip)* | Handle a leading UTF-8 BOM (`EF BB BF`). `strip` consumes it **without shifting line-1 columns**. `reject` warns (and counts an error, so `--bom:reject --strict` exits non-zero). The default leaves the BOM on the historical unknown-byte path. |

### `--doc-comments:on\|off`

Default **`on`** — a standalone (line-leading) `##` or `##[ … ]##` doc comment is
emitted as a `(comment)` node, matching nifler. `off` **drops** standalone doc
comments entirely (no comment node). This is the one advisory flag that changes
output, so it is an explicit opt-in divergence for tools that don't want comment
nodes. Trailing doc comments are dropped either way.

## Behaviour & robustness

### `--strict`

Default off. Exit with a **non-zero status** if any **error-level diagnostic** was
raised — an unknown/illegal byte, an unterminated string, a rejected BOM, or a
structural bracket problem. Turns a normal `p` parse into a CI lint gate: a clean
file exits `0`, a malformed one exits `1` (while still emitting best-effort AIF).
For lint-only output with no AIF, use the [`check`](#check--lint-mode) command.

### `--max-depth:N`

Default **0 = unlimited**. A recursion-nesting guard on the parser. When `N > 0`,
if parse nesting through the recursive entry points exceeds `N`, aowlparser prints
a message naming the line and exits non-zero — protecting the "never crashes /
hangs" property against pathologically nested input. The counter tracks *true*
nesting (not input width), so set it generously: ordinary code nests only a
handful of levels deep, so a ceiling in the hundreds catches abuse without ever
tripping on real source.

## Diagnostics

Unlike native `nifler` — which inherits the classic compiler's abort-on-first-error
behaviour — aowlparser is **recoverable**: it records every problem with a source
span, keeps parsing, and still emits best-effort AIF. Diagnostics carry a
`severity` (error/warning/hint), a stable `code` slug, a message, and a
`line:col`–`endCol` span, and — where one exists — a suggested `fix` and a
`related` location (e.g. the `(` a stray `)` should have matched). The whitespace
and indentation checks further down surface as warnings/hints.

The catalog of what `check` detects today, every entry proven
**zero-false-positive** against ~600 valid files and the whole Nim standard
library:

- **Full lexer-error parity** — every lexical error native `nifler` reports, and
  then some, each recovered past instead of aborting: bad character literals
  (empty `''`, run-on `'ab'`, unterminated `'a`), illegal tabs, unterminated
  block comments (`#[ … `), malformed escapes (`\q`, empty `\x`, empty `\u{}`),
  unterminated triple/raw strings, doubled/trailing underscores in a number,
  unterminated accent-quoted identifiers, unknown/illegal bytes, unterminated
  strings, and a rejected BOM.
- **Structural bracket problems** — `unmatched-close`, `mismatched-bracket`
  (points at *both* the close and the opener it should have matched, as a
  `related` field), and `unclosed-bracket`.
- **Detections `nifler` lacks or reports vaguely** — `assignment-in-condition`
  (`if x = 5:` → *did you mean `==`?*, across `if`/`elif`/`while`/`when`),
  `expected-condition` (empty `elif:`), and `expression-expected` (an empty
  comma slot `foo(a,,b)`, while still allowing a valid *trailing* comma).
- **"Forgot the introducer" family** — a routine with a body but no `=`
  (`missing-routine-equals`), a `type Name` with an indented body but no
  `= object`/`= enum` (`missing-type-equals`), and a colon-block whose body
  isn't indented past its header. Each names the omission, points at the
  declaration, and carries the exact fix-it — where `nifler` only emits a bare
  *invalid indentation*.
- **Precise grammar diagnostics** — `func-in-type-description`
  (→ *use `proc` with `{.noSideEffect.}`*), `enum-member-not-identifier`
  (a keyword spliced into an `enum` body), `empty-variant-branch` (an `of A:`
  with no field — pointing at the branch itself, not the innocent next one),
  `of-without-value` (an `of` with no value before its `:`), and
  `expected-in` (`for x of xs:` → *write `for <vars> in <iterable>: …*`).
- **Knows what isn't plain Nim** — a file opening with a `#? stdtmpl`
  source-code filter is a template; `check` stays silent instead of flagging the
  raw HTML.

None of these ever changes the emitted AIF — a plain `p` parse stays
byte-compatible with native `nifler`.

### `check` — lint mode

```
aowlparser check <in.nim>            # diagnostics to stdout, no AIF; exit 1 on any error
aowlparser check --diagnostics:json in.nim
```

`check` runs the lexer and the structural validator and prints diagnostics **to
stdout**, emitting no AIF. It exits `1` if any error-level diagnostic was found,
`0` otherwise — a drop-in lint gate that reports *every* problem in one pass, not
just the first.

### `--diagnostics:text\|json\|off`

Selects how diagnostics are rendered (default `text`). During a normal `p` parse
they go to **stderr** and never block the AIF on stdout; `check` sends them to
stdout.

- `text` — compiler-style `file:line:col: severity[code]: message` lines.
- `json` — a single JSON array of `{severity, code, message, line, col, endCol}`
  objects, ready for an editor's diagnostics channel or the browser playground.
- `off` — suppress them entirely.

### `--portable-paths:on\|off`

Default **on**, matching native `nifler`'s default. The source path recorded in
line-info is made relative to the current working directory with `/` separators,
so the output is byte-identical regardless of whether the input was passed as a
relative or absolute path. `off` records the path exactly as given.

## I/O

By default aowlparser reads a file and writes `<in>.p.aif` (or the given output
path). For pipelines and the JS build it can use the standard streams instead:

| flag | effect |
|:--|:--|
| `--stdin` (or input arg `-`) | Read source from **stdin**. |
| `--stdout` (or output arg `-`) | Write the AIF to **stdout**. Stdin with no output target defaults to stdout. |
| `--filename:PATH` | The path recorded in line-info when reading stdin (default `stdin`). |

## Worked examples

```sh
# default — nifler-compatible, spaces only
aowlparser p mod.nim mod.p.aif

# accept a tab-indented file (8-column tabs), same tree as the space version
aowlparser --tabs:tabs --tab-width:8 p tabbed.nim tabbed.p.aif

# lint a file: require a final newline, LF endings, no trailing spaces
aowlparser --final-newline:require --newline:lf --trailing-whitespace:warn p mod.nim mod.p.aif

# CI gate — fail on any illegal byte
aowlparser --strict p mod.nim mod.p.aif || echo "rejected"

# a pipeline: stdin -> stdout, with a recorded filename for line-info
cat mod.nim | aowlparser --stdin --stdout --filename:mod.nim p > mod.p.aif

# guard against pathological nesting
aowlparser --max-depth:400 p untrusted.nim out.p.aif

# brace blocks plus tab indentation, mixed freely
aowlparser --curly --tabs:both p editor_dialect.nim out.p.aif
```

## Design note: the default is always native `nifler`

Every option defaults to the historical behaviour, and all of them — except
`--curly` (additive syntax) and `--doc-comments:off` (explicit opt-in) — affect
only **input acceptance, diagnostics, or I/O**, never the emitted node tree. That
keeps aowlparser's core contract intact: its default output is, and remains,
byte-for-byte native `nifler` — apart from the `(.vendor)` header identity —
verified by the [differential harness](testing) on every commit.
