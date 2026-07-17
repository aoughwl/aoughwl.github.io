# Grammar coverage

What aowlparser reproduces, by area. Everything here is verified structurally
against native nifler (see [Differential testing](testing)); exceptions are on
[Coverage](known-gaps).

[[toc]]

---

## Lexer

- **Numeric literals** — all bases (`0x`/`0o`/`0b`/`0c`) and `_` separators (both
  decoded; nifler emits decimal only, so base and underscores are lost — matched);
  floats with `.` fraction and `e`/`E` exponent; typed suffixes `'i8`/`'u`/`'f32`
  emitted as `(suf N tag)`.
- **Strings & chars** — `"…"` with full escape decoding, `r"…"` raw, `"""…"""`
  and `r"""…"""` triple, `'c'` chars with escapes.
- **Identifiers** — including backtick-quoted `` `foo bar` `` → `(quoted …)`,
  split by the `accQuoted` rule.
- **Comments** — `#` line, `#[ … ]#` nested block, `##` doc, `##[ … ]##` doc
  block. A line-leading doc comment becomes `(comment)`; a trailing one is
  dropped; consecutive `##` lines merge.
- **Layout** — significant indentation on `Token.indent`, the `*:` split, 1-based
  line / 0-based col, per-token `endCol` for spacing checks.

## Expressions

- **Precedence** — assignment operators loosest, arrows below, the rest by
  leading character.
- **Prefix/infix by spacing** — `f $v` (prefix arg) vs `a $ b` (infix), following
  the lexer's leading/trailing-space rule.
- **Literal folding** — `-N` and `-N'suf` fold into one suffixed literal, as
  nifler does.
- **Call-string-literals** — `ident"…"` → `(callstrlit …)`.
- **Postfix chains** — `.field` (`dot`), `[i]` (`at`), `{k}` (`curlyat`),
  `(args)` (`call`, or `oconstr` when the first arg is `name: value`).
- **Keyword-led forms** — `nil`, `cast[T](x)`, `addr`, and `if`/`when`/`try` as
  expressions, plus anonymous `proc`.
- **Grouping & constructors** — tuple `(a, b)` vs paren `(a)`, array/seq `[…]`
  (`bracket`), set `{…}` (`curly`), table `{k: v}` (`tabconstr`), StmtListExpr
  `( … ; … )` (`expr (stmts …) result`).
- **Named args** — `k = v` (`vv`), colon pairs `k: v` (`kv`).

## Commands

Command syntax in statement, expression, and type position: prefix-op arguments
(`add $v`), dotted callees (`result.add c`), type commands (`lent T`), and
`postExprBlocks` — a trailing `:` block becoming a `(stmts …)` argument of the
call (`foo(x): body`, inline and indented).

## Control flow

`if`/`elif`/`else`, `case`/`of` with the `(ranges …)` wrapper, `while`, `for`
(with `unpackflat`/`unpacktup` loop-var normalisation), `try`/`except`/`finally`,
`when`, `block`, `break`/`continue`, `defer`, `static` — in multi-line and
one-liner forms, as statements and as multi-line values (`let x = try:` with the
body on following lines), plus `;`-separated statements on one logical line.

The hard case is **indentation-context branch matching**: a value-position
`try`/`if`/`when`/`case` has its keyword mid-line, so its `except`/`elif`/`of`
branches align with the enclosing statement's indent, not the keyword column. The
body threshold is computed from the body's own indent.

## var / let / const sections

Sections emit no wrapper node — each ident-def is a sibling, with type and value
duplicated across a multi-name group (`(var name . pragma type value)`).
Visibility `*` becomes ` x`; a `{.pragma.}` after the name list is split out;
`var (a, b) = x` becomes `(unpackdecl value (unpacktup (var …) …))`.

## Type & routine definitions

- **`object`** — inheritance (`of Parent`), fields, variant `case`, `when`
  conditional fields.
- **`enum`** — `(efld …)`, one field per line, values and pragmas.
- **`tuple`**, **`ref`**/**`ptr`**/**`distinct`**, **`concept`**.
- **proc / iterator types** — `(proctype …)`/`(itertype …)` with the fixed slot
  layout, including trailing type-pragmas.
- **Generics** — `[T; U: C]` → `(typevars (typevar …) …)`.
- **Pragmas** — `{. … .}` on declarations, statement pragmas as `pragmax`,
  including the leading command word (`{.push ….}`/`{.pop.}`).
