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

## What makes it faithful

The bar is **byte-for-byte identical output** to native `nifler`. A differential
harness compiles every corpus program with both tools and compares the `.p.nif`:

- **Structural** — token trees identical after stripping line-info (the pass bar).
- **Exact** — byte-identical `.p.nif`, including the relative line-info suffixes.

Current status: **47 / 47 corpus programs pass, 46 byte-exact**, and beyond the
curated corpus a `stress.sh` harness runs the same differential comparison over
arbitrary real `.nim` files: **all 29 of the `nimony/src/lib` modules now match
native nifler byte-structurally end-to-end** (line-info stripped) — the whole
real standard library, zero mismatches, zero crashes.
All five playground example programs — Hello, Fibonacci, FizzBuzz, Collatz, List
sum — parse **byte-identical** to native nifler, so the real Tier-2 workload is
covered.

## Design

- **Fused parse + emit.** It writes NIF directly through `nifbuilder` as it
  recognises constructs — no intermediate `PNode` AST is built (object-variant
  reference trees trip nimony's field magics, so the whole tree stage is skipped).
- **Range-splitter expressions.** Operator precedence is resolved by finding the
  lowest-precedence operator in a token span and recursing on the two sides,
  which reproduces nifler's operator nesting for free.
- **Parallel-friendly split.** The grammar lives in per-area include files
  (expressions, statements, type/routine defs) over a shared cursor spine, so the
  areas were implemented independently and integrated without conflicts.

Covered today: the full lexer (numeric bases, typed-literal `(suf …)`,
raw/triple/char strings, backtick-quoted idents → `(quoted …)`, `##` doc
comments → `(comment …)`, significant indentation); expressions with Nim's real
operator precedence (assignment operators, arrows, spacing-based prefix/infix
disambiguation, `-N` literal folding, `ident"…"` call-string-literals, postfix
chains, constructors, named args, `cast`/`addr`, `if`/`try`-expressions,
anonymous `proc` expressions, StmtListExpr `( … ; … )`); command syntax in
statement, expression **and** type position (prefix-op args like `add $v`,
dotted callees like `result.add c`, `lent T`); statements (`if`/`case`/`while`/
`for`/`try`/`when`/`block`/`static`/`defer`, in both multi-line and one-liner
forms, plus `;`-separated statements and `from … import`); `var`/`let`/`const`
sections (pragmas, tuple-unpack); and type definitions (object, enum with
one-per-line fields, tuple, `ref`/`ptr`, proc types, generics, pragmas).

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
