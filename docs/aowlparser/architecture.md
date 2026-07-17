# Architecture

[[toc]]

---

## Fused parse + emit

aowlparser builds no AST. It is a recursive-descent parser that writes AIF
directly through the builder as it recognises each construct; there is no tree
stage.

This is forced, not just convenient: constructing an object-variant `ref` AST
trips nimony's field magics, a self-hosting-compiler constraint. It is also
sufficient — emission is one left-to-right walk of the token stream, and a
node's tag, children, and line-info are all decidable from a bounded token
window, so an intermediate tree buys nothing.

Consequence: line-info is not a post-pass. Each node's `@line,col` suffix is
written as the node is written, relative to its parent's position. Byte-exact
output therefore comes out of the same walk that produces the structure; no
separate step can drift.

## Range-splitter expressions

Precedence is resolved without a precedence-climbing machine. Given a token span
`[lo, hi)`, `parseExprRange` finds the lowest-precedence depth-0 operator
(rightmost, for left-associativity), emits `(infix op L R)`, and recurses on the
two sub-ranges. `parsePrimaryRange` handles the high-precedence end: postfix
chains (`.`→`dot`, `[]`→`at`, `{}`→`curlyat`, `()`→`call`/`oconstr`), prefix
operators, and keyword-led forms (`nil`/`cast`/`addr`/`if`/`when`/`try`/anon
`proc`).

The precedence table is a port of the classic compiler's `getPrecedence`:
assignment-like operators loosest (level 1), arrows below (level 0), the rest by
leading character. Nesting matches nifler's, so the tree and its pretty-print
indentation match.

## Module map

The grammar is split across `include` files over one shared cursor. `parser.nim`
splices them in a fixed order; cross-file mutual recursion resolves through
forward declarations in `parsecore.nim`.

| module | role |
|:--|:--|
| `tokens.nim` | `Token` contract shared by lexer and parser. |
| `lexer.nim` | Hand-written lexer: numeric bases + typed suffixes, raw/triple/char strings with escapes, backtick idents → `(quoted …)`, `#` / `#[ ]#` / `##` / `##[ ]##` comments, significant indentation. |
| `parsecore.nim` | The spine: `Parser` type, token cursor, line-info emission, operator classification, range-scanning helpers, forward decls. |
| `parse_expr.nim` | Expressions, operators, constructors, named args. |
| `parse_type.nim` | Type defs, routine/proc defs, params, generics, pragmas. |
| `parse_stmt.nim` | Statements, control flow, `var`/`let`/`const` sections. |
| `parser.nim` | Aggregator + module loop `parseModule`. |
| `aowlparser.nim` | CLI driver (file I/O only, JS-build friendly). |

Splice order `parsecore → parse_expr → parse_type → parse_stmt`. Because the
files are `include`d into one module, a proc in one file may call a not-yet-defined
proc in another as long as its signature is in the `FORWARD DECLS` block.

## Significant indentation

There is no Indent/Dedent token. Every token that is first on its source line
records its column in `Token.indent`; all others carry `indent == -1`. The
off-side rule is `ps.tok(i).indent > refIndent`, enough to delimit indented
blocks, object/enum bodies, and value-position control flow whose keyword sits
mid-line (`let x = try:`). Column computation from spaces and tabs is
[configurable](configuration).

## The oracle

aowlparser is specified against the classic Nim compiler's `lexer.nim` and
`parser.nim`, which nifler mirrors. Rules reproduced verbatim include:

- `accQuoted` piece splitting (`` `[]=` `` → one piece; `` `value=` `` → `value`, `=`),
- `scanComment` run-merging (consecutive `##` lines → one node),
- `getPrecedence`,
- the `*:` two-token split (`var v*: int`),
- `##`-as-`nkCommentStmt` and `##[ ]##` doc blocks,
- spacing-based prefix-vs-infix disambiguation (`f $v` vs `a $ b`),
- `postExprBlocks` (trailing `:` block arguments).

Where behaviour is unclear, the compiler source decides, not intuition.
