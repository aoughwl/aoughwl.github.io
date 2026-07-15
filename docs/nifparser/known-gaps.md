---
title: Coverage
parent: nifparser
grand_parent: NIF Toolchain Alternatives
nav_order: 5
---

# Coverage
{: .no_toc }

Where `nifparser` stands against native `nifler` — now at full structural parity
across the entire nimony compiler tree.

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The headline number

Over the whole `nimony/src` compiler tree — 184 files, far beyond the standard
library — nifparser matches native nifler on **all 184**, with **zero crashes and
zero hangs**. The standard library (`nimony/src/lib`, 29 modules) passes in full,
and the curated corpus passes 64/64 (55 byte-exact apart from the intentional
`(.vendor)` header).

This is complete structural parity: every construct the nimony compiler's own
source exercises round-trips through nifparser to the same NIF token tree native
nifler emits.

## How the last gaps were closed

The final push closed a cluster of dense, real-world constructs, each matched to
nifler construct-by-construct and locked in with a corpus regression test:

1. **Doc-comment attachment** — the standalone-vs-trailing `##` rule. nifler's
   `indAndComment` attaches a comment indented *deeper* than its statement to
   that declaration and, without `--docs`, never emits it; a comment at the
   statement-list indent is a standalone `(comment)`. nifparser now drops
   trailing docs (module loop, routine bodies, `emitBody`) and emits section-member
   comments as sibling `(comment)` nodes. This one rule closed six files.
2. **Command precedence** — a command call binds looser than binary operators
   (`f a & b` = `f(a & b)`), and its argument list absorbs the trailing operator
   expression.
3. **postExprBlocks and `do`-notation** — value-position blocks
   (`let x = onRaiseQuit:`), `x.sort do (a, b) -> int: body`, command blocks with
   an `if`-expression argument (`addUIntTypedOp dest, if k: A else: B, 8, info:`),
   and `(block: …)` used as a parenthesized expression.
4. **Anonymous routines** — proc-type return colons in param types
   (`cleanup: proc (b): int = nil`), anon-proc call arguments, and their `= body`
   not being mistaken for an assignment.
5. **Structural forms** — `import/export … except`, mixed tuple-unpack
   (`for i, (a, b) in xs`), `tuple[…]` type-arguments, and multi-type
   `except A, B:` clauses.

## The differential loop

Each gap was closed the same way:

1. Find a failing file with `tests/stress.sh` and locate the first divergence with
   `tests/canon.py` + `diff`.
2. Reduce it to a one-line repro and check the shape native `nifler` emits.
3. Confirm the rule against the classic compiler source
   (`Nim/compiler/{lexer,parser}.nim`) — the [oracle](architecture#the-oracle).
4. Adjust the relevant emitter, add the repro to the corpus, and re-run both
   harnesses (the standard library and corpus must stay green).

That loop took the whole compiler tree from 127 → 184 passing. With structural
parity reached, the remaining frontier is pure byte-exactness: a handful of
constructs match structurally but distribute relative line-info across
`cmd`/`dot`/argument nodes slightly differently than nifler — visible only at the
byte level, never in the token tree.
