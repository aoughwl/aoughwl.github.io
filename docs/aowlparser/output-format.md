---
nav_exclude: true
title: The .p.aif format
parent: Parser — aowlparser
grand_parent: aowlmony
nav_order: 6
---

# The `.p.aif` format
{: .no_toc }

What aowlparser emits — enough to read a parse-dialect AIF by eye. This is the
untyped wire form the nimony frontend consumes; the semantic pass later turns it
into the typed `.s.aif`.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Shape

A `.p.aif` is a whitespace-insignificant tree of parenthesised nodes. Three
token kinds appear:

- **Trees** — `(tag …children…)`. The tag is the first atom after `(`, glued to
  its line-info suffix.
- **Atoms** — identifiers, integers, floats, strings (`"…"`), chars. Plain atoms
  carry no tag; only typed/decorated literals do (see [`suf`](#literals)).
- **Empties** — a bare `.` is an absent optional slot.

Inter-token whitespace is meaningless; aowlparser's indentation is pretty-print,
not structure.

## Header

Every file opens with three directives, one per line:

```
(.aif27)
(.vendor "aowlparser")
(.dialect "nim-parsed")
```

- `(.aif27)` — wire-format version 27.
- `(.vendor "aowlparser")` — producer id. aowlparser stamps its own name rather
  than nifler's `"Nifler"`; this line is the only deliberate byte difference from
  nifler output. See [Differential testing](testing).
- `(.dialect "nim-parsed")` — untyped, parser-level dialect.

The header is followed by the root `(stmts …)` tree carrying an absolute
line-info of column 0, line 1, and the source filename.

## Line-info suffixes

Every node can carry a position, encoded as a suffix glued directly onto the
preceding tag or atom with no whitespace. An all-zero suffix is omitted.

| Form | Introducer | Meaning |
|:--|:--|:--|
| Absolute | `@` | the node's own `(col, line[, file])` — root only |
| Relative | `@` or `~` | delta from the parent's `(col, line)` — everywhere else |

Suffix grammar (each segment optional):

- **Column** — `@` then the column; a negative column uses bare `~` (no `@`).
  Column `0` emits `@` with nothing after it.
- **Line** — `,` then the line delta; negative is `~`-then-digits; an interior
  zero collapses to just the comma.
- **File** — `,` then the filename (control chars escaped). Absolute root only.

Numbers are base62 (`0-9A-Za-z` = 0–61, most-significant first: `A`=10, `G`=16,
`J`=19). Columns 0-based, lines 1-based. Relative deltas are measured against the
parent baseline threaded down the descent (nifler's parent-relative scheme).

### Example

`assign.nim` containing `n = 3*n + 1`:

```
(stmts@,1,assign.nim     root, absolute: @ = col 0, ,1 = line 1, file "assign.nim"
 (asgn@2 n~2             asgn at col +2 (the '='); target n at col −2
  (infix@6 \2B           infix at col +6; operator '+' escaped as \2B
   (infix~3 * 3~1 n@1)   inner infix at col −3; '*' raw; int 3 at −1; n at +1
   1@2)))                literal 1 at col +2
```

`(call@3 foo~3 1@1 2@4)` is `foo(1, 2)`. `(proc@,2 fib@5 …)` is a proc placed two
lines below its parent. A zero-delta node (`(cmd echo …)`) carries no suffix.

## Operator & atom escaping

An atom whose leading byte is `.`, a digit, `+`, `-`, `~`, or a control character
is escaped so it can't be read as a suffix or number: the leading byte becomes
`\HH`. So `+` → `\2B`, `-` → `\2D`, `..` → `\2E\2E`. Non-colliding operators
(`*`, `/`, `<`, `>`, `=`) emit raw.

## Tag vocabulary

The tags aowlparser emits, by category. (Plain identifiers, ints, floats,
strings, chars, and `.` empties are atoms, not tags.)

**Blocks & root**
: `stmts` (root and every block body), `block`, `defer`, `staticstmt`

**Control flow**
: `if`, `when`, `elif`, `else`, `while`, `for`, `case`, `of`, `ranges`, `try`,
  `except`, `fin`

**Flow keywords**
: `ret`, `discard`, `raise`, `yld`, `break`, `continue`, `import`, `include`,
  `export`, `fromimport`, `comment`

**Declarations**
: `asgn`, `var`, `let`, `const`, `type`, `proc`, `func`, `method`, `converter`,
  `iterator`, `macro`, `template`, `params`, `param`, `typevars`, `typevar`,
  `pragmas`, `pragmax`, `unpackdecl`, `unpacktup`, `unpackflat`

**Type expressions**
: `object`, `enum`, `efld`, `fld`, `concept`, `tuple`, `proctype`, `itertype`,
  and prefix modifiers `ref`, `ptr`, `out`, `distinct`, `mut` (nimony's spelling
  for `var T`)

**Expressions**
: `call`, `cmd`, `infix`, `prefix`, `dot`, `at`, `curlyat`, `bracket`, `par`,
  `tup`, `kv`, `vv`, `cast`, `expr`, `nil`, `quoted`

<a id="literals"></a>**Decorated literals**
: `suf` (typed numeric/string literal, e.g. `123u`, `1.0'f32`), `callstrlit`
  (`ident"…"`)

For where each tag is emitted and the range-splitter that produces
`infix`/`prefix` nesting, see [Architecture](architecture) and
[Grammar coverage](grammar).
