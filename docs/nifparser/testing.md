---
title: Differential testing
parent: nifparser
grand_parent: NIF Toolchain Alternatives
nav_order: 3
---

# Differential testing
{: .no_toc }

nifparser has one job — emit the same NIF as native `nifler` — so it is tested by
running both tools on the same input and comparing their output. There is no
hand-written expected-output; the classic compiler's `nifler` **is** the oracle.

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Two levels of match

For every input file the harness runs the native `nifler` oracle and `nifparser`,
then compares the resulting `.p.nif`:

- **Structural** — the pass criterion. `tests/canon.py` strips line-info
  (`@…` / `~…`) and comment suffixes and normalises whitespace; the two token
  trees must then be identical. String-literal contents are preserved: NIF escapes
  every marker byte inside strings, so a `@` inside `"a@b"` can never be mistaken
  for a line-info suffix.
- **Exact** — no longer a bonus. The `.p.nif` bytes are identical, line-info
  included. nifparser now reaches this on **every** corpus file and every file in
  the whole compiler tree, which is the real proof that its relative line-info
  model is correct and not merely structurally plausible.

## The two harnesses

```sh
bash tests/diff.sh                    # curated corpus, PASS/FAIL per file
VERBOSE=1 bash tests/diff.sh          # + a canonical diff for each failure
bash tests/stress.sh                  # differential over nimony/src/lib
bash tests/stress.sh /path/dir ...    # differential over any dirs/files
```

`diff.sh` runs the small **curated corpus** under `tests/corpus/` — one file per
construct, chosen so a failure names exactly which grammar rule broke.

`stress.sh` points the *same* comparison at **arbitrary real `.nim` files**. With
no argument it sweeps the whole nimony standard library; given directories it
sweeps those. Crucially it also reports what the parser could **not** do
gracefully:

```
stress: total=184  pass=184  mismatch=0  our-crash=0  oracle-skip=0
```

- `our-crash` — nifparser produced no output (a crash or hang). **This is the
  number that must stay zero**; a structural mismatch is a wrong tree, but a crash
  is a broken tool.
- `oracle-skip` — the *native* nifler itself failed on the file, so it is excluded
  (nothing to compare against).

## Current results

| suite | command | result |
|:--|:--|:--|
| curated corpus | `tests/diff.sh` | **76 / 76** pass, 76 byte-exact (apart from the `(.vendor)` header) |
| standard library | `tests/stress.sh` | **29 / 29** structural, **29 byte-exact**, 0 crash |
| whole compiler tree | `tests/stress.sh /home/savant/nimony/src` | **184 / 184** structural, **184 byte-exact**, 0 crash / 0 hang |
| diagnostics | `tests/diag.sh` | `check` mode: multi-error, spans, JSON, clean-file cases |

The whole compiler tree passing in full is the headline: every one of the 184
files under `nimony/src` — the standard library and the compiler's own dense
internals — round-trips structurally identical to native nifler, with zero
crashes, and **all 184 are byte-identical** (relative line-info included).
`tests/stress.sh` now reports that byte-exact count (`byte-exact=N`) alongside the
structural pass count, so the line-info frontier is a tracked, regression-protected
number. See [Coverage](known-gaps) for how the line-info model was closed.

## Why a differential harness

A parser that emits a compiler wire-format has an unusually crisp correctness
oracle: the wire-format is only useful if a *second, independent* implementation
agrees with it byte-for-byte — save for one line nifparser owns on purpose, its
`(.vendor "nifparser")` header, which both `diff.sh` (byte) and `canon.py`
(structural) neutralize before comparing so the rest stays strict. That makes the
reference (`nifler`) both the spec
and the test suite, and it makes regressions impossible to miss — any construct
where nifparser drifts shows up as a concrete NIF diff against the tool the rest
of the pipeline already trusts.
