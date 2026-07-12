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

Current status: **44 / 44 corpus programs pass, 43 byte-exact.** All five
playground example programs — Hello, Fibonacci, FizzBuzz, Collatz, List sum —
parse **byte-identical** to native nifler, so the real Tier-2 workload is covered.

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

Covered today: the full lexer (numeric bases, suffixes, raw/triple/char strings,
significant indentation), expressions (postfix chains, constructors, named args,
`cast`, `if`-expressions), statements (`if`/`case`/`while`/`for`/`try`/`when`/
`block`/`defer` and `var`/`let`/`const` sections), and type definitions (object,
enum, tuple, `ref`/`ptr`, proc types, generics, pragmas).

---

[Repo → github.com/aoughwl/nifparser](https://github.com/aoughwl/nifparser){: .btn .btn-primary }
