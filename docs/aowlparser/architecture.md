---
title: Architecture
parent: aowlparser
grand_parent: Compiler Pipeline
nav_order: 1
---

# Architecture
{: .no_toc }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The one idea: fused parse + emit

`aowlparser` does **not** build a Nim `PNode` AST. It is a recursive-descent
parser that writes NIF **directly** through `nifbuilder` as it recognises each
construct. There is no tree stage in between.

Two reasons:

1. **It has to be.** Rebuilding an object-variant `ref` AST trips nimony's field
   magics — a known constraint of the self-hosting compiler. Skipping the tree
   stage sidesteps it entirely.
2. **It's unnecessary.** The emit is a single left-to-right walk of the token
   stream anyway. A node's NIF tag, its children, and its line-info suffix are all
   decidable from a bounded window of tokens, so there is nothing an intermediate
   tree would buy.

The consequence: **line-info is not a post-pass.** Each node's
`@line,col` suffix is emitted *as the node is written*, relative to its parent
node's position. That is why byte-exact output falls out of the same walk that
produces the structure — there is no separate step that could drift.

## Range-splitter expressions

Operator precedence is resolved without a precedence-climbing state machine.
Given a token span `[lo, hi)`, `parseExprRange` finds the **lowest-precedence,
depth-0 operator** (rightmost, for left-associativity), emits `(infix op L R)`,
and recurses on the two sub-ranges. Primary/atom parsing (`parsePrimaryRange`)
handles the high-precedence end: postfix chains (`.` / `[]` → `at` / `{}` →
`curlyat` / `()` → `call`/`oconstr`), prefix operators, and keyword-led forms
(`nil`/`cast`/`addr`/`if`/`when`/`try`/anonymous `proc`).

This mirrors the way native nifler nests operators, so the resulting tree — and
its pretty-print indentation — matches for free. The precedence table itself is a
direct port of the classic compiler's `getPrecedence`: assignment-like operators
bind loosest (level 1), arrow operators below that (level 0), the rest by leading
character.

## Module map

The grammar is split across `include` files over a shared cursor spine. They are
spliced by `parser.nim` in a fixed order, and mutual recursion across files
resolves through forward declarations in `parsecore.nim`.

| module | role |
|:--|:--|
| `tokens.nim` | The `Token` contract shared by lexer and parser. |
| `lexer.nim` | Full hand-written lexer: numeric bases + typed suffixes, raw/triple/char strings with escapes, backtick-quoted idents → `(quoted …)`, `#` / `#[ ]#` / `##` / `##[ ]##` comments, significant indentation. |
| `parsecore.nim` | The spine: `Parser` type, token cursor, line-info emission, operator classification, range-scanning helpers, and the cross-file forward declarations. |
| `parse_expr.nim` | Expressions, operators, constructors, named args. |
| `parse_type.nim` | Type defs, routine/proc defs, params, generics, pragmas. |
| `parse_stmt.nim` | Statements, control flow, `var`/`let`/`const` sections. |
| `parser.nim` | Thin aggregator + the module loop `parseModule`. |
| `aowlparser.nim` | The CLI driver (thin, file-I/O only — JS-build friendly). |

Splice order: `parsecore → parse_expr → parse_type → parse_stmt`. Because the
files are `include`d into one module rather than imported, a proc in one area can
call a not-yet-defined proc in another as long as its signature is listed in
`parsecore.nim`'s `FORWARD DECLS` block.

## Significant indentation

There is no separate Indent/Dedent token. Instead every token that is the first
non-whitespace token on its source line records its column in `Token.indent`;
every other token carries `indent == -1`. The parser implements the off-side rule
by comparing these columns (`ps.tok(i).indent > refIndent`), which is enough to
delimit indented blocks, object/enum bodies, and value-position control flow whose
keyword sits mid-line (e.g. `let x = try:`). How that column is computed from
spaces and tabs is [configurable](configuration).

## The oracle

aowlparser is specified **operationally** against the classic Nim compiler's lexer
and parser (`compiler/lexer.nim`, `compiler/parser.nim`), which `nifler` mirrors
exactly. The subtle rules reproduced verbatim include:

- `accQuoted` identifier-piece splitting (`` `[]=` `` → one piece; `` `value=` ``
  → `value`, `=`),
- `scanComment` run-merging (consecutive `##` lines → one comment node),
- `getPrecedence` (assignment ops loosest, arrows below),
- the `*:` two-token split (`var v*: int`),
- `##`-as-`nkCommentStmt` and `##[ ]##` doc blocks,
- spacing-based prefix-vs-infix disambiguation (`f $v` vs `a $ b`),
- and `postExprBlocks` (trailing `:` block arguments).

When behaviour is in doubt, the compiler source — not intuition — is the tie-breaker.
