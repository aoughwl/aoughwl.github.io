# Differential testing

aowlparser's job is to emit the same tree as native nifler, so it is tested by
running both on the same input and comparing output. There is no hand-written
expected output; nifler is the oracle.

[[toc]]

---

## Two levels of match

For each input the harness runs nifler and aowlparser and compares the `.p.aif`:

- **Structural** (the pass criterion) — `tests/canon.py` strips line-info
  (`@…`/`~…`) and comment suffixes and normalises whitespace; the token trees
  must then be identical. String contents are preserved: AIF escapes every marker
  byte inside strings, so a `@` in `"a@b"` is never read as line-info.
- **Exact** — the `.p.aif` bytes are identical, line-info included. This is the
  check that the relative line-info model is right, not just structurally
  plausible.

The only intentional byte difference is the `(.vendor "aowlparser")` header
(nifler emits `"Nifler"`); both harnesses normalise it before comparing.

## The harnesses

```sh
bash tests/diff.sh                    # curated corpus, PASS/FAIL per file
VERBOSE=1 bash tests/diff.sh          # + a canonical diff per failure
bash tests/stress.sh                  # differential over nimony/lib
bash tests/stress.sh /path/dir ...    # differential over any dirs/files
bash tests/diag.sh                    # check-mode diagnostics
```

`diff.sh` runs the curated corpus under `tests/corpus/` — one file per construct,
so a failure names the broken grammar rule.

`stress.sh` points the same comparison at real `.nim` files and reports failure
modes:

```
stress: total=310  pass=310  mismatch=0  our-crash=0  oracle-skip=0  byte-exact=283
```

- `our-crash` — aowlparser produced no output (crash or hang). Must stay zero: a
  mismatch is a wrong tree, a crash is a broken tool.
- `oracle-skip` — nifler itself failed on the file, so it is excluded.
- `byte-exact` — of the passing files, how many matched to the byte.

## Current results

| target | command | structural | byte-exact | crash/hang |
|:--|:--|:--|:--|:--|
| curated corpus | `tests/diff.sh` | 172 / 172 | 156 | 0 |
| nimony/src | `stress.sh …/nimony/src` | 184 / 184 | 184 | 0 |
| nimony/lib | `stress.sh …/nimony/lib` | 105 / 105 | 91 | 0 |
| upstream Nim/lib | `stress.sh …/Nim/lib` | 310 / 310 | 283 | 0 |

599 valid files round-trip structure-identical to nifler; 558 are byte-identical
(relative line-info included). See [Coverage](known-gaps).

## Why differential

A parser that emits a compiler wire format has a sharp oracle: the format is only
useful if a second, independent implementation agrees byte-for-byte. That makes
nifler both the spec and the test suite — any drift shows up as a concrete AIF
diff against the tool the rest of the pipeline already trusts.
