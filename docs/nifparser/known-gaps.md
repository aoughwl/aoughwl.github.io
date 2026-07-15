---
title: Known gaps
parent: nifparser
grand_parent: NIF Toolchain Alternatives
nav_order: 5
---

# Known gaps
{: .no_toc }

An honest map of where `nifparser` still differs from native `nifler`, and why
those differences are grammar-completion work rather than defects in the parser
spine.

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The headline number

Over the whole `nimony/src` compiler tree — 184 files, far beyond the standard
library — nifparser matches native nifler on **127** and differs structurally on
**57**, with **zero crashes and zero hangs**. Every one of the 57 produces
well-formed NIF; they are wrong-tree diffs, not failures to parse.

The standard library itself (`nimony/src/lib`, 29 modules) passes **in full**, and
the curated corpus passes 47/47. So the gaps live specifically in the denser,
more exotic corners of the compiler's own source.

## The categories

The 57 mismatches cluster into a small number of well-defined edge cases, ordered
roughly by frequency:

1. **Doc-comment placement** — a few standalone-vs-trailing `##` boundary cases
   where a `(comment)` node attaches to a different sibling than nifler chooses.
2. **Routine / proc-type pragma & empty-param shapes** — some `(params)`-vs-`.`
   and pragma-slot orderings on proc **types** and forward declarations.
3. **`nil` in annotation position** — e.g. `(nil)` inside certain pragma or type
   contexts.
4. **Generalised call-string-literals** — `expr"…"` where the callee is not a bare
   identifier (`pkg.mod"…"`, `(expr)"…"`).
5. **`@`-prefix and quoted-ident corners** — a handful of `(prefix @ …)` and
   `(quoted …)` placements inside dense expressions.
6. **Assorted control-flow-value wrapping** — a few `(stmts …)`-vs-bare and
   `(call … (stmts …))` postExprBlock orderings in the largest modules.

## Why these are not spine defects

The load-bearing machinery is correct everywhere it fires: the range-splitter
resolves precedence, the relative line-info model is byte-exact (46/47 corpus
files match to the byte, apart from the `(.vendor)` header nifparser stamps as its
own), and the section/type/pragma emitters are right across
the entire standard library. Each remaining category is a *specific construct*
whose exact NIF shape has not yet been matched — the kind of thing a targeted
corpus file plus a small emitter tweak closes, the same way the whole standard
library was brought to green one construct at a time.

## How a gap gets closed

1. Find a failing file with `tests/stress.sh` and locate the first divergence with
   `tests/canon.py` + `diff`.
2. Reduce it to a one-line repro and check the shape native `nifler` emits.
3. Confirm the rule against the classic compiler source
   (`Nim/compiler/{lexer,parser}.nim`) — the [oracle](architecture#the-oracle).
4. Adjust the relevant emitter, add the repro to the corpus, and re-run both
   harnesses (the standard library and corpus must stay green).

That loop is exactly how the parser reached full standard-library coverage, and it
is what the remaining categories are queued for.
