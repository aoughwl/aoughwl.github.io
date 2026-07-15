---
title: Configuration
parent: nifparser
grand_parent: NIF Toolchain Alternatives
nav_order: 4
---

# Configuration
{: .no_toc }

Every option below is **off / neutral by default**, so a plain
`nifparser p in.nim out.p.nif` produces output byte-identical to native `nifler`
(bar the one-line `(.vendor "nifparser")` header, which nifparser always stamps
as its own).
The flags exist for editors, linters, pipelines, and non-Nim-standard sources;
apart from `--curly` (which only *adds* accepted syntax) and the opt-in
`--doc-comments:off`, none of them can change the NIF a run emits — they gate
input acceptance, add diagnostics, or move I/O.

```
usage: nifparser [OPTIONS] p <in.nim> [out.p.nif]
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

Either way the curly form emits the **same NIF** as the `:`/`=` form. This is a
nifparser extension; native nifler has no equivalent, so output stays
nifler-compatible only while it is off.

## Indentation & whitespace

Nim's layout is column-based, and classic Nim is **spaces-only** — its lexer
hard-errors on a tab in indentation. nifparser keeps that as the default but can
relax it for tab-using sources and validate indentation for tooling. None of these
change the emitted NIF: the off-side rule is a *relative* column comparison, so a
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
leaves both stdout and the emitted NIF untouched.

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

Default off. Exit with a **non-zero status** if the lexer encountered any
unknown / illegal byte (today those are silently skipped), or a rejected BOM.
Turns nifparser into a CI lint gate: a clean file exits `0`, a file with a stray
control byte exits `1`.

### `--max-depth:N`

Default **0 = unlimited**. A recursion-nesting guard on the parser. When `N > 0`,
if parse nesting through the recursive entry points exceeds `N`, nifparser prints
a message naming the line and exits non-zero — protecting the "never crashes /
hangs" property against pathologically nested input. The counter tracks *true*
nesting (not input width), so set it generously: ordinary code nests only a
handful of levels deep, so a ceiling in the hundreds catches abuse without ever
tripping on real source.

## I/O

By default nifparser reads a file and writes `<in>.p.nif` (or the given output
path). For pipelines and the JS build it can use the standard streams instead:

| flag | effect |
|:--|:--|
| `--stdin` (or input arg `-`) | Read source from **stdin**. |
| `--stdout` (or output arg `-`) | Write the NIF to **stdout**. Stdin with no output target defaults to stdout. |
| `--filename:PATH` | The path recorded in line-info when reading stdin (default `stdin`). |

## Worked examples

```sh
# default — nifler-compatible, spaces only
nifparser p mod.nim mod.p.nif

# accept a tab-indented file (8-column tabs), same tree as the space version
nifparser --tabs:tabs --tab-width:8 p tabbed.nim tabbed.p.nif

# lint a file: require a final newline, LF endings, no trailing spaces
nifparser --final-newline:require --newline:lf --trailing-whitespace:warn p mod.nim mod.p.nif

# CI gate — fail on any illegal byte
nifparser --strict p mod.nim mod.p.nif || echo "rejected"

# a pipeline: stdin -> stdout, with a recorded filename for line-info
cat mod.nim | nifparser --stdin --stdout --filename:mod.nim p > mod.p.nif

# guard against pathological nesting
nifparser --max-depth:400 p untrusted.nim out.p.nif

# brace blocks plus tab indentation, mixed freely
nifparser --curly --tabs:both p editor_dialect.nim out.p.nif
```

## Design note: the default is always native `nifler`

Every option defaults to the historical behaviour, and all of them — except
`--curly` (additive syntax) and `--doc-comments:off` (explicit opt-in) — affect
only **input acceptance, diagnostics, or I/O**, never the emitted node tree. That
keeps nifparser's core contract intact: its default output is, and remains,
byte-for-byte native `nifler` — apart from the `(.vendor)` header identity —
verified by the [differential harness](testing) on every commit.
