---
repo: aoughwl/aowltest
---

# aowltest — content-addressed test runner

A test runner that **skips any test whose transitive input hash is unchanged**,
and reports the cache hit rate it achieved. Written in **nimony**, with no
dependency beyond nimony's own stdlib.

<div class="hero-actions">
<a href="/docs/aowlmony">Driver → aowlmony</a>
</div>

[[toc]]

---

## What it does

```
$ aowltest tests
  CACHED  tests/tparser.nim  (14 inputs, saved 2.31s)
  CACHED  tests/tlexer.nim   (9 inputs, saved 0.88s)
  PASS    tests/tsem.nim     (22 inputs, 3.04s)

aowltest: 3 test(s)   cached 2   ran 1   pass 1   fail 0
cache hit rate: 66.7%  (2/3)
time: 3.04s executed, ~3.19s skipped by cache
```

The hit rate is printed on every run, because a caching test runner whose hit
rate you cannot see is a caching test runner you cannot tell is working.

## The key

Each test gets a **manifest** — sorted, one line per input, of everything that
could change its result:

```
cmd nim c -r --hints:off tests/tsem.nim
salt nimony-2026-08-01
dep tests/tsem.nim        3f2a...
dep src/sem/exprs.nim     91bc...
dep src/types.nim         0d47...
ext std/strutils
gdep bin/nimony           aa10...
```

The cache key is `sha1(manifest)`. An entry filed under that key is proof this
exact set of inputs already produced a result, so the test is skipped.

* `dep` — the **transitive closure** of the test's local imports. The scanner
  reads `import` / `include` / `from … import`, expands `std/[a, b]` bracket
  lists, follows block and comma-continuation forms, and resolves each spec
  against the importer's directory and any `--path` dirs.
* `ext` — a spec that resolves to no file on disk (the stdlib, an installed
  package). Its *name* is key material; its bytes are not. Express a toolchain
  change with `--salt`, or point `--dep` at the compiler binary.
* `gdep` — a `--dep` input, hashed once and folded into every key.

Everything is hashed **by content, never by mtime**. Checking out an older
commit restores the old bytes, so it restores the old keys, so those tests hit
the cache instead of re-running. A `touch` costs nothing.

Import scanning is lexical: it does not evaluate `when` conditions, so a module
imported under `when defined(windows)` folds into the key on Linux too. Over-
approximating is the safe direction — it can cost a needless re-run, never a
wrongly-skipped test.

## Discovered compile-time reads

A file a macro or const evaluator read is an input **no static scan can find**:
it exists only because the compiler ran. [aowlsem](aowlsem) records every
granted compile-time read to `<out>.s.nif.ctfe-reads`; with `--ctfe-dir:DIR`,
aowltest merges those sidecars after a run and re-hashes them on a later key
hit. A moved schema therefore re-runs a test whose every source byte is
identical.

It is **off unless asked**. Guessing the sidecar location wrong would silently
skip a changed test, and an unsound cache is worse than one that admits it does
not know. What *is* recorded can only ever cause an extra run.

## Why did this re-run?

```
$ aowltest --explain
  PASS    tests/tsem.nim  (22 inputs, 3.04s)
            changed: - dep src/types.nim 0d47a1...
            changed: + dep src/types.nim 8be302...
```

`--explain` diffs the manifest against the one recorded for that test's last
run, so a miss names the input that actually moved.

## Using it

```sh
aowltest [options] [<dir-or-file> ...]
```

Default root is `tests/`. A test is a `.nim`, `.nims` or `.sh` file under a root
whose name starts with `t`; `--all` drops the prefix rule. Without `--cmd`, the
command follows the extension: `.sh` → `bash {}`, `.nim`/`.nims` →
`nim c -r --hints:off --warnings:off {}`. Exit status is 1 if any test failed.

| option | meaning |
| --- | --- |
| `--cache:DIR` | cache root (default `.aowltest-cache`) |
| `-p:DIR`, `--path:DIR` | module search path for import resolution |
| `--dep:PATH` | extra input folded into every key; a directory is walked |
| `--salt:STR` | opaque string folded into every key |
| `--cmd:TEMPLATE` | command per test; `{}` is the test path |
| `--ctfe-dir:DIR` | merge compile-time-read sidecars found under `DIR` |
| `--explain` | on a miss, print which manifest lines moved |
| `--list` | print each test with its key and input count; run nothing |
| `--no-cache`, `--force` | run everything; still record and report the rate |
| `--read-only` | use the cache, do not write to it |
| `--cache-failures` | also cache failing runs (default: successes only) |
| `--clear-cache` | delete every entry, then run |
| `--fail-fast`, `--json`, `-v` | stop at the first failure / machine-readable summary / verbose |

Failing runs are **not** cached by default. `--cache-failures` records them,
which is right for a deterministic test and will happily skip a flaky one until
an input changes.

## Cache layout

```
entries/<key>          one recorded outcome, keyed by transitive input hash
last/<sha1(testpath)>  that test's most recent manifest (for --explain)
disc/<key>             compile-time reads discovered under that key
```

Entries are **immutable and never invalidated** — a key is either present or
absent. That is what makes branch-switching cheap.

## The conformance suite

The gate is not a script that tests this binary; it is a **standalone,
implementation-neutral conformance suite** for the behaviour itself. It needs
only `bash` and `awk`.

```sh
bash conformance/run.sh                       # default adapter → bin/aowltest
bash conformance/run.sh --adapter mine.sh     # some other implementation
bash conformance/run.sh -v 030                # one case, showing observations
```

The corpus is **data**: nine `cases/*.case` files, one scenario each, written in
a small step language — `use` a fixture tree, `write`/`append`/`save`/`restore`
its files, `run`, then `expect ran=2 cached=1 hitrate=33.3`. The runner knows
that language and nothing about any implementation.

Everything implementation-specific sits behind an **adapter** with three verbs:

```
adapter capabilities                                  # neutral feature tokens
adapter run <root> <cache-dir> <cmd|-> [neutral-opt…] # → observation record
adapter ctfe-sidecar <ctfe-dir> <file>…               # record a compile-time read
```

The adapter translates a neutral option vocabulary (`list`, `explain`, `salt=`,
`dep=`, `ctfe-dir=`, `no-cache`, `cache-failures`, `clear-cache`, …) in, and a
line-oriented **observation record** out:

```
total 3 / cached 1 / ran 2 / passed 2 / failed 0 / hitrate 33.3 / exit 0
test basic/ta.nim pass inputs=3
test basic/tb.nim cached inputs=1
explain dep basic/lib/base.nim
```

A case may declare `requires ctfe-dir`; a case whose token the adapter does not
declare is **skipped, not failed**, so a partial implementation still scores.

The nine cases state the contract: discovery and closure size, cold/warm,
transitive invalidation *including that restoring the original bytes restores
the old keys*, `--explain` blaming the right input and nothing else, salt and
command line as key material, global `dep`, failure handling and exit status,
cache bypass that does not poison the cache, and discovered compile-time reads
with a negative control.

The suite is checked against a deliberately broken implementation, which is the
only way to know a gate still bites: an adapter that silently drops `salt=` and
`ctfe-dir=` must fail exactly `050-key-material` and `090-compile-time-reads`,
and nothing else.

## Build

```sh
./build.sh          # → bin/aowltest  (override with NIMONY=/path/to/nimony)
bash tests/run.sh   # the conformance suite: 72 assertions, aowltest as the adapter
```
