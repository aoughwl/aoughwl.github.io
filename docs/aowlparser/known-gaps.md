---
nav_exclude: true
title: Coverage
parent: Parser — aowlparser
grand_parent: aowlmony
nav_order: 5
---

# Coverage
{: .no_toc }

Where `aowlparser` stands against native `nifler` — now at full structural parity
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
library — aowlparser matches native nifler on **all 184**, with **zero crashes and
zero hangs**, and every one of the 184 is **byte-identical** (apart from the
intentional `(.vendor)` header). The standard library (`nimony/src/lib`, 29 modules)
passes in full and byte-exact, and the curated corpus passes 76/76, all byte-exact.

This is complete structural *and* byte-level parity: every construct the nimony
compiler's own source exercises round-trips through aowlparser to the same NIF —
same token tree, same relative line-info — that native nifler emits.

## How the last gaps were closed

The final push closed a cluster of dense, real-world constructs, each matched to
nifler construct-by-construct and locked in with a corpus regression test:

1. **Doc-comment attachment** — the standalone-vs-trailing `##` rule. nifler's
   `indAndComment` attaches a comment indented *deeper* than its statement to
   that declaration and, without `--docs`, never emits it; a comment at the
   statement-list indent is a standalone `(comment)`. aowlparser now drops
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

That loop took the whole compiler tree from 127 → 184 passing structurally.

## Byte-exactness

With structure settled, the next frontier was **byte-exactness** — reproducing
nifler's *relative line-info* on every node, not just the token tree. This came
down to reverse-engineering nifler's anchoring model (`relLineInfo(n, parent)`,
which stamps each node with `n.info − parent.info`) and matching, per construct,
exactly which source token nifler anchors a node at. The high-leverage findings:

- **Two command rules.** A statement command (`parseExprStmt`) anchors at the
  callee's info — the `.` for a dotted callee; an expression command (`commandExpr`)
  anchors at the *first argument*, giving the callee a negative delta.
- **The module `stmts` node** anchors at the first real token (a leading `##` doc
  is that token; a plain `#` is not), removing a delta cascade through every file.
- **Name-node wrapping.** An exported `Name*` is `nkPostfix` (anchor = the `*`); a
  pragma'd `Name {.p.}` is `nkPragmaExpr` (anchor = the `{.`); this applies to
  const/let/var members *and* object fields.
- **`postExprBlock` calls, tuple fields, anonymous lambdas** (info on the empty-name
  placeholder, taken from the token after `proc`), and **bare StmtListExpr-result
  bodies** (a command there is still a statement) each have their own anchor rule.
- **`do`-notation** (`expr do (params) -> ret: body`) was the very last file. Its
  call node anchors at the callee's `.` (so the callee child is delta 0), and — the
  non-obvious part — the `do` node itself anchors at the **body's first token**, not
  the `do` keyword, so `(params)` carries its delta back up to the `(` and the body
  `(stmts)` is delta 0 against the do.
- **Portable paths.** nifler relativises the recorded source path to the cwd by
  default; aowlparser now mirrors that (`--portable-paths`).

Each fix was locked in with a byte-exact corpus regression test and measured
against the whole tree (`tests/stress.sh` reports `byte-exact=N`). The result:
**all 184 files byte-identical**, up from 0 — not just the same token tree as
native nifler, but the exact relative line-info of every node, across the entire
nimony compiler source.
