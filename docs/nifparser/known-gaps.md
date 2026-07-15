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
library — nifparser matches native nifler on **162** and differs structurally on
**22**, with **zero crashes and zero hangs**. Every one of the 22 produces
well-formed NIF; they are wrong-tree diffs, not failures to parse.

The standard library itself (`nimony/src/lib`, 29 modules) passes **in full**, and
the curated corpus passes 52/52. So the gaps live specifically in the denser,
more exotic corners of the compiler's own source.

## The categories

The remaining 22 mismatches cluster into a small number of well-defined edge
cases, ordered roughly by frequency:

1. **Doc-comment placement** — the standalone-vs-trailing `##` boundary: whether
   a `(comment)` node stands alone or attaches to an adjacent declaration. This
   is now the dominant remaining category (~7 files) and needs nifler's full
   leading/trailing doc-attachment rule, not a blanket emit-or-drop.
2. **`do` / postExprBlock orderings** — `(call … (stmts …))` and `do`-notation
   shapes in the largest modules (dagon, nifmake, sempragmas).
3. **Command line-info on a dotted callee** — `x.add ".s"` distributes the
   relative line-info across the `cmd`/`dot`/arg nodes differently than nifler
   (structurally identical, a byte-level position difference; visible on dce2,
   pnak).
4. **Assorted structural corners** — tuple-unpack (`unpacktup`) shapes,
   `importexcept`, and a few dense expression orderings in individual modules.

## Recently closed

A large batch of former gaps was closed by matching nifler construct-by-construct:
control-flow values in parentheses (`when`/`case` bare branches, plus `case` as a
value expression), per-piece line-info on quoted accent-idents in **every**
declaration and dot-field position, empty `(params)` on paramless routines,
prefix-operator return values (`return -1` / `@[]` / `$x`), set literals inside an
`if`-value (no longer mis-scanned as a pragma), generalised call-string-literals
with dotted callees, `mixin`/`bind` statements, type-modifier keywords in generic
arguments (`seq[ref T]`, `sink seq[string]`), call/range bounds and quoted operands
in type-argument position, multi-constraint generic params (`[T: A, L: B]`), and
`nil`/`discard` object-variant bodies.

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
