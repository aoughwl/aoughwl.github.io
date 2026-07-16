---
title: Grammar coverage
parent: aowlparse
grand_parent: Compiler Pipeline
nav_order: 2
---

# Grammar coverage
{: .no_toc }

What `aowlparse` reproduces today, by area. Everything here is verified
byte-structurally against native `nifler` (see [Differential testing](testing));
the honest exceptions are on [Known gaps](known-gaps).

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Lexer

- **Numeric literals** — all bases (`0x` / `0o` / `0b` / `0c`) and `_` digit
  separators (both decoded — nifler emits decimal only; base and underscores are
  lost, matching nifler); float literals with `.` fraction and `e`/`E` exponent;
  typed suffixes `'i8`.. / `'u`.. / `'f32`.. recorded and emitted as `(suf N tag)`.
- **Strings & chars** — `"…"` with full Nim escape decoding, `r"…"` raw,
  `"""…"""` / `r"""…"""` triple, `'c'` char literals with escapes.
- **Identifiers** — including backtick-quoted `` `foo bar` `` → `(quoted …)`,
  split into pieces by the classic `accQuoted` rule.
- **Comments** — `#` line, `#[ … ]#` nested block, `##` doc, and `##[ … ]##` doc
  block. A standalone (line-leading) doc comment becomes `(comment)`; a trailing
  one is dropped; consecutive `##` lines merge into one node.
- **Layout** — significant indentation on `Token.indent`, the `*:` split, 1-based
  `line` / 0-based `col`, and a per-token `endCol` powering spacing checks.

## Expressions

- Nim's **real precedence** — assignment operators bind loosest, arrow operators
  below them, the rest by leading character.
- **Spacing-based prefix/infix disambiguation** — `f $v` (prefix arg) vs `a $ b`
  (infix), following the classic lexer's leading/trailing-space rule.
- **Literal folding** — `-N` and `-N'suf` fold into a single (suffixed) literal,
  exactly as nifler does.
- **Call-string-literals** — `ident"…"` → `(callstrlit …)`.
- **Postfix chains** — `.field` (`dot`), `[i]` (`at`), `{k}` (`curlyat`), `(args)`
  (`call`, or `oconstr` when the first arg is a `name: value` field).
- **Keyword-led forms** — `nil`, `cast[T](x)`, `addr`, and `if` / `when` / `try`
  used as **expressions**, plus anonymous `proc` expressions.
- **Grouping & constructors** — tuple `(a, b)` vs paren `(a)`, array/seq `[…]`
  (`bracket`), set `{…}` (`curly`), table `{k: v}` (`tabconstr`), and StmtListExpr
  `( … ; … )` (`expr (stmts …) result`).
- **Named args** — `k = v` (`vv`) and colon pairs `k: v` (`kv`).

## Commands

Command syntax in **statement, expression, and type** position: prefix-op
arguments (`add $v`), dotted callees (`result.add c`), type-position commands
(`lent T`), and `postExprBlocks` — a trailing `:` block that becomes a `(stmts …)`
argument of the call/command (`foo(x): body`, inline and indented).

## Control flow

`if` / `elif` / `else`, `case` / `of` with the `(ranges …)` wrapper, `while`,
`for` (with `unpackflat` / `unpacktup` loop-var normalisation), `try` / `except` /
`finally`, `when`, `block`, `break` / `continue`, `defer`, and `static` — in
**multi-line and one-liner** forms, as **statements and as multi-line values**
(`let x = try:` with the body on following lines), plus `;`-separated statements
on one logical line.

The hard case handled here is **indentation-context branch matching**: a
value-position `try`/`if`/`when`/`case` has its keyword mid-line, so its
`except`/`elif`/`of` branches align with the *enclosing statement's* indent, not
the keyword column. The body threshold is computed from the body's own indent.

## var / let / const sections

Sections emit **no wrapper node** — each ident-def is its own sibling, with the
type and value **duplicated** across a multi-name group
(`(var name . pragma type value)`). Visibility `*` becomes ` x`; a `{.pragma.}`
after the name list is split out; var-tuple unpacking `var (a, b) = x` becomes
`(unpackdecl value (unpacktup (var …) …))`.

## Type & routine definitions

- **`object`** — inheritance (`of Parent`), fields, variant `case`, and `when`
  conditional fields.
- **`enum`** — `(efld …)`, one field per line, values and pragmas.
- **`tuple`**, **`ref`** / **`ptr`** / **`distinct`**, and **`concept`**.
- **proc / iterator types** — `(proctype …)` / `(itertype …)` with the fixed slot
  layout, including trailing type-pragmas.
- **Generics** — `[T; U: C]` → `(typevars (typevar …) …)`.
- **Pragmas** — `{. … .}` on declarations, and statement pragmas as `pragmax`,
  including the leading command-pragma word (`{.push ….}` / `{.pop.}`).
