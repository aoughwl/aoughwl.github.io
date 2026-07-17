# Coverage

Where aowlparser stands against native nifler, and what it deliberately does not
do.

[[toc]]

---

## Parity

| target | files | structural | byte-exact |
|:--|:--|:--|:--|
| nimony/src | 184 | 184 | 184 |
| nimony/lib | 105 | 105 | 91 |
| upstream Nim/lib | 310 | 310 | 283 |
| curated corpus | 172 | 172 | 156 |

599 valid files parse to a tree structure-identical to nifler's, with zero
crashes and zero hangs. Every construct the nimony compiler's own source and the
full upstream Nim standard library exercise round-trips. Measured by
[`tests/stress.sh`](testing).

## Byte-exactness

Structural parity means the same token tree; byte-exactness additionally means
the same relative line-info on every node. It is complete on `nimony/src`
(184/184) and holds for 558 of the 599 valid files overall. The remainder are
structurally identical but differ in some line-info deltas — same tree, same
tags, a different `@col,line` on a few nodes.

Byte-exactness came down to matching nifler's anchoring model
(`relLineInfo(n, parent)`, stamping each node with `n.info − parent.info`) per
construct — which source token each node anchors at. The non-obvious anchors:

- **Commands** — a statement command anchors at the callee's info (the `.` for a
  dotted callee); an expression command anchors at the first argument, giving the
  callee a negative delta.
- **Module `stmts`** — anchors at the first real token (a leading `##` counts, a
  plain `#` does not).
- **Name wrapping** — `Name*` is `nkPostfix` (anchor = `*`); `Name {.p.}` is
  `nkPragmaExpr` (anchor = `{.`), for section members and object fields alike.
- **`do`-notation** — the call anchors at the callee's `.`; the `do` node itself
  anchors at the body's first token, not the `do` keyword.
- **Portable paths** — nifler relativises the recorded path to the cwd by
  default; mirrored via `--portable-paths`.

## What nifler catches that aowlparser does not

A residue of *indentation-context* errors — cases nifler rejects by tracking a
running indentation stack the range-splitter does not maintain. These are left
out on purpose: detecting them risks a false positive on valid code, which would
make the tool worse than nifler, not better. Everything aowlparser flags is
proven zero-false-positive against the 599 valid files and the full Nim standard
library.

For what aowlparser catches *beyond* nifler — recoverable diagnostics with
fix-its and related locations — see [Configuration → Diagnostics](configuration#diagnostics).

## Not attempted

aowlparser is syntactic only. Type and semantic errors (undeclared names, type
mismatches, effect violations) surface later, from the semantic pass over the
typed `.s.aif`. Semantic suggestions (e.g. `x == 5` used as a statement, `&&` for
`and`) belong to a separate lint layer, not the parser.
