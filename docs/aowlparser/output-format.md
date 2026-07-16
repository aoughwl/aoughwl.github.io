---
title: The .p.nif format
parent: aowlparser
grand_parent: Compiler Pipeline
nav_order: 6
---

# The `.p.nif` format
{: .no_toc }

What aowlparser actually emits — enough to *read* a parse-dialect NIF by eye. This
is the untyped wire form the nimony frontend consumes; the later `nimsem` stage
turns it into the typed `.s.nif`.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Shape

A `.p.nif` is a whitespace-insignificant tree of parenthesised nodes. Three kinds
of token appear:

- **Trees** — `(tag …children…)`. The tag is the first atom after `(`, glued to
  its line-info suffix (below).
- **Atoms** — bare identifiers, integers, floats, strings (`"…"`), and chars.
  Plain atoms are *not* wrapped in a tag; only typed/decorated literals are (see
  [`suf`](#literals)).
- **Empties** — a bare `.` stands for an absent optional slot.

Inter-token whitespace is meaningless; aowlparser's own indentation is a
pretty-print, not structure.

## Header

Every file begins with three directives, one per line, in this order:

```
(.nif27)
(.vendor "aowlparser")
(.dialect "nim-parsed")
```

- `(.nif27)` — the NIF wire-format version (format 27). Fixed by the NIF builder,
  not chosen by aowlparser.
- `(.vendor "aowlparser")` — the producer id. aowlparser stamps **its own** name
  here rather than impersonating classic `nifler` (which emits `"Nifler"`); this
  one line is the only place a aowlparser file deliberately differs from nifler's
  bytes. See [Differential testing](testing).
- `(.dialect "nim-parsed")` — the dialect: untyped, parser-level NIF.

The header is followed immediately by the root `(stmts …)` tree carrying an
**absolute** line-info of column 0, line 1, and the source filename.

## Line-info suffixes

Every node can carry a position, encoded as a suffix glued directly onto the
preceding tag-name or atom with **no whitespace**. This is the densest part of
the format.

Two forms:

| Form | Introducer | Meaning |
|:--|:--|:--|
| **Absolute** | `@` | the node's own `(col, line[, file])` — used at the root |
| **Relative** | `@` or `~` | a **delta** from the parent node's `(col, line)` — used everywhere else |

Grammar of a suffix (each segment optional; an all-zero suffix is omitted
entirely):

- **Column**: `@` then the column; a negative column uses a bare `~` shorthand
  (no `@`) instead. Column `0` emits `@` with nothing after it.
- **Line**: `,` then the line delta. A negative delta is written `~`-then-digits;
  an interior zero collapses to just the comma.
- **File**: `,` then the filename (control chars escaped). Present only in the
  absolute root suffix; relative suffixes carry no file.

Numbers are **base62** — digits `0-9A-Za-z` = values 0–61, most-significant first
(so `A`=10, `G`=16, `J`=19). Columns are 0-based, lines are 1-based, matching
nimony's `TLineInfo`. Relative deltas are measured against the parent baseline
threaded down the recursive descent (nifler's parent-relative scheme).

### Reading a real example

`assign.nim` containing `n = 3*n + 1`:

```
(stmts@,1,assign.nim     root, ABSOLUTE: @ = col 0, ,1 = line 1, file "assign.nim"
 (asgn@2 n~2             asgn at col +2 (the '='); target n at col −2 (~2)
  (infix@6 \2B           infix at col +6; operator '+' is the escaped atom \2B
   (infix~3 * 3~1 n@1)   inner infix at col −3; '*' raw; int 3 at −1; n at +1
   1@2)))                literal 1 at col +2
```

More: `(call@3 foo~3 1@1 2@4)` is `foo(1, 2)`; `(proc@,2 fib@5 …)` is a proc whose
`@` (col 0) and `,2` (line +2) place it two lines below its parent; a node with a
zero delta (e.g. `(cmd echo …)`) carries **no** suffix at all.

## Operator & atom escaping

An atom whose **leading** character is `.`, a digit, `+`, `-`, `~`, or a control
character is escaped so it can't be mistaken for a suffix or number: the leading
byte becomes `\HH` (two hex digits). Hence `+` → `\2B`, `-` → `\2D`, `..` →
`\2E\2E`. Operators that don't collide — `*`, `/`, `<`, `>`, `=` — are emitted
raw.

## Tag vocabulary

The substantially-complete set of tags aowlparser emits, by category. (Plain
identifiers, ints, floats, strings, chars and `.` empties are atoms, not tags.)

**Blocks & root**
: `stmts` (module root and every block body), `block`, `defer`, `staticstmt`

**Control flow**
: `if`, `when`, `elif`, `else`, `while`, `for`, `case`, `of`, `ranges`,
  `try`, `except`, `fin`

**Flow keywords**
: `ret`, `discard`, `raise`, `yld`, `break`, `continue`, `import`, `include`,
  `export`, `fromimport`, `comment`

**Declarations**
: `asgn`, `var`, `let`, `const`, `type`, `proc`, `func`, `method`, `converter`,
  `iterator`, `macro`, `template`, `params`, `param`, `typevars`, `typevar`,
  `pragmas`, `pragmax`, `unpackdecl`, `unpacktup`, `unpackflat`

**Type expressions**
: `object`, `enum`, `efld`, `fld`, `concept`, `tuple`, `proctype`, `itertype`,
  and the prefix modifiers `ref`, `ptr`, `out`, `distinct`, and `mut` (nimony's
  spelling for `var T`)

**Expressions**
: `call`, `cmd`, `infix`, `prefix`, `dot`, `at`, `curlyat`, `bracket`, `par`,
  `tup`, `kv`, `vv`, `cast`, `expr`, `nil`, `quoted`

<a id="literals"></a>**Decorated literals**
: `suf` (a typed numeric/string literal, e.g. `123u`, `1.0'f32`), `callstrlit`
  (generalized `ident"…"`)

For where each is emitted (file:line in `src/`), and the *conceptual* model behind
the range-splitter that produces `infix`/`prefix` nesting, see
[Architecture](architecture) and [Grammar coverage](grammar).
