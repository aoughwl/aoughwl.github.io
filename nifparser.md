---
title: nifparser — Nim → NIF parser
nav_order: 9
---

# nifparser
{: .no_toc }

A pure-**nimony** recursive-descent parser that turns Nim source into the
parse-dialect NIF (`.p.nif`) the compiler frontend consumes — the same job as the
compiler's `nifler`, but self-hosted and free of the classic Nim compiler, so it
can be compiled to JavaScript and run in the browser.
{: .fs-6 .fw-300 }

[Repo → github.com/aoughwl/nifparser](https://github.com/aoughwl/nifparser){: .btn .btn-primary }
[Playground →](playground){: .btn }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Why it exists

The [playground](playground) runs [nifi](nifi) client-side today, but only on
**precompiled** typed NIF. To recompile edits live in the browser (Tier 2), the
compiler *frontend* — parse then semcheck — has to run in JS too. Semcheck
(`nimsem`) already self-hosts under nimony and translates cleanly to JS. The
parser did not: the stock `nifler` is built on the **classic** Nim compiler
(`compiler/lexer`, `parser`, `syntaxes`, `ast`), which is Nim 2 and not
nimony-compilable — so it cannot go to the browser.

`nifparser` closes that gap: a from-scratch parser written in nimony, emitting
the identical `.p.nif` wire format, that compiles through the nimony JS backend.

## What it produces

`nifler` — and therefore `nifparser` — is a **purely syntactic** transducer. It
does no semantic checking and no symbol resolution; every symbol comes out as a
bare identifier. The output is the *parse dialect* of NIF: a faithful, fully
line-info-annotated s-expression rendering of the Nim parse tree. `nifparser`
reproduces it without linking any classic-Nim code.

## What makes it faithful

The bar is **byte-for-byte identical output** to native `nifler`. A differential
harness compiles every input with both tools and compares the `.p.nif`:

- **Structural** — token trees identical after stripping line-info (the pass bar).
- **Exact** — byte-identical `.p.nif`, including the relative line-info suffixes.

| test suite | files | result |
|:--|:--|:--|
| curated corpus | 47 | **47 pass**, 46 byte-exact |
| nimony standard library (`nimony/src/lib`) | 29 | **29 pass** structurally, 0 crash |
| whole nimony compiler tree (`nimony/src`) | 184 | **127 pass**, **0 crash / 0 hang** |

The **entire real standard library** round-trips structurally identical to native
nifler, line-info stripped — zero mismatches, zero crashes. All five playground
example programs — Hello, Fibonacci, FizzBuzz, Collatz, List sum — parse
**byte-identical**, so the real Tier-2 workload is fully covered.

Across the far larger *compiler-internals* tree the parser never crashes and never
hangs; the remaining structural mismatches are a small, catalogued set of
grammar-completion edge cases (see [Known gaps](#known-gaps)) rather than spine
defects.

## Design

- **Fused parse + emit.** It writes NIF directly through `nifbuilder` as it
  recognises constructs — no intermediate `PNode` AST is built (object-variant
  reference trees trip nimony's field magics, so the whole tree stage is skipped).
  Line-info is emitted relative to each node's parent, so the byte-exact
  line-info suffixes fall out of the same left-to-right walk.
- **Range-splitter expressions.** Operator precedence is resolved by finding the
  lowest-precedence depth-0 operator in a token span and recursing on the two
  sides, which reproduces nifler's operator nesting for free.
- **Include-file grammar.** The grammar lives in per-area include files —
  `parse_expr` (expressions), `parse_type` (type/routine defs), `parse_stmt`
  (statements) — over a shared `parsecore` spine, spliced in a fixed order with
  mutual recursion resolved through forward declarations.

### The oracle

nifparser is specified operationally against the classic Nim compiler's lexer and
parser (`compiler/lexer.nim`, `compiler/parser.nim`), which nifler mirrors
exactly. The subtle rules reproduced verbatim include `accQuoted` identifier-piece
splitting, `scanComment` run-merging, `getPrecedence` (assignment operators bind
loosest at 1, arrow operators at 0), the `*:` two-token split, `##`-as-comment and
`##[ ]##` doc blocks, spacing-based prefix-vs-infix disambiguation, and
`postExprBlocks` (trailing `:` block arguments).

## Covered grammar

The full lexer (numeric bases, typed-literal `(suf …)`, raw/triple/char strings
with escapes, backtick-quoted idents → `(quoted …)`, `#`/`#[ ]#`/`##`/`##[ ]##`
comments, significant indentation); expressions with Nim's real operator
precedence (assignment operators, arrows, spacing-based prefix/infix, `-N` and
`-N'suf` literal folding, `ident"…"` call-string-literals, postfix chains,
constructors, named args, `cast`/`addr`/`nil`, `if`/`when`/`try`-expressions,
anonymous `proc` expressions, StmtListExpr `( … ; … )`); command syntax in
statement, expression **and** type position (prefix-op args like `add $v`, dotted
callees like `result.add c`, `lent T`, `postExprBlocks`); statements
(`if`/`case`/`while`/`for`/`try`/`when`/`block`/`static`/`defer`, in multi-line
and one-liner forms, as statements **and** multi-line values, plus `;`-separated
statements and `from … import`); `var`/`let`/`const` sections (pragmas,
tuple-unpack); and type definitions (object with variant `case` and `when`
conditional fields, enum, tuple, `ref`/`ptr`/`distinct`, `concept`, proc types,
generics, pragmas).

## Known gaps

Over the whole `nimony/src` tree, 57 of 184 files still differ structurally. Every
one produces well-formed NIF — none crash or hang — and they cluster into a few
categories:

- **Doc-comment placement** — standalone-vs-trailing `##` boundary cases where a
  comment node attaches to a different sibling.
- **Routine / proc-type pragma & empty-param shapes** — `(params)`-vs-`.` and
  pragma-slot ordering on proc *types* and forward decls.
- **`nil` in annotation position**, **generalised call-string-literals**
  (`pkg.mod"…"` where the callee is not a bare ident), and a handful of
  **`@`-prefix / quoted-ident** placements in dense expressions.
- **Assorted control-flow-value wrapping** — `(stmts …)`-vs-bare and
  `postExprBlock` orderings in the largest modules.

These are grammar-completion items on top of a spine (range-splitter, line-info
model, section/type machinery) that is correct wherever it fires.

## Experimental: curly-brace blocks

Off by default so output stays nifler-compatible. Passing `--curly` lets a
`{ … }` block body stand in **anywhere** a `:` body is accepted, and the two
styles may be mixed freely:

```nim
if c { echo a } else: echo b       # brace + colon in one statement
while x { dec x; use x }            # `;`-separated statements inside a brace
```

A block `{` is disambiguated from a set literal by context — it must follow an
operand (`if c {`) or a bodiless-block keyword (`else {`, `try {`, `block {`,
`finally {`, `defer {`) — so a set in the head (`if {1} == x { … }`) is not
mistaken for the body. This is a nifparser extension; native nifler has no
equivalent.

---

[Repo → github.com/aoughwl/nifparser](https://github.com/aoughwl/nifparser){: .btn .btn-primary }
