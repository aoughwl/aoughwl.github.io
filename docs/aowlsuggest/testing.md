---
nav_exclude: true
title: Testing
parent: Suggestions — aowlsuggest
grand_parent: aowlmony
nav_order: 5
---

# Testing
{: .no_toc }

The zero-false-positive guarantee is not a claim — it is a gate, proven two ways
over tens of thousands of real lines.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Behavioural tests — `tests/fix.sh`

Mirroring aowlparser's own `diag.sh` discipline, each fix has two cases:

- **before → after**: a malformed file gets exactly the expected repair, and the
  repaired file then **lints clean** — the fix is verified end to end.
- **valid stays untouched**: a well-formed file yields no fix and is left
  byte-for-byte unchanged.

Plus coverage of the dry-run diff, `lint --format:json`, exit codes, the ranked
LSP code actions, stdin buffers, and `version`.

## Zero false positives — `tests/zerofp.sh`

Run over aowlparser's own oracle corpus of **known-valid** files:

| corpus | files |
|--------|------:|
| `nimony/src` (the nimony compiler) | 184 |
| `nimony/lib` (the nimony stdlib) | 105 |
| `Nim/lib` (the full upstream Nim stdlib) | 310 |
| **total** | **599** |

Two guarantees are asserted across all 599:

1. **lint reports zero errors** — no false diagnostics on valid code, and
2. **fix proposes no change to any file** — a fix can never touch valid code.

The second is the strong claim and is independent of the parser's diagnostic
state: even if aowlparser ever emitted a spurious diagnostic, aowlsuggest
verifies every candidate edit against the checker and discards one that does not
strictly reduce errors — so a valid file is left untouched regardless.

```console
$ bash tests/zerofp.sh
corpus: 599 valid files
lint census: errors=0 runFailures=0
fix scan: 599 file(s) checked, 0 changed
zerofp: PASS — 0 errors and 0 fixes across 599 valid files
```

## Realism gate — `tests/stress.sh`

Valid files prove the tool doesn't *invent* problems; the realism gate proves it
never *worsens* one. It runs over the **entire Nim compiler test corpus — 2890
files, deliberately malformed** — and checks the monotonicity invariant the
verify loop must never break:

- **(I1)** the error count after `fix` is never greater than before, and
- **(I2)** if `fix` changed a file, the error count strictly *dropped* — every
  applied edit was a real, verified improvement.

```console
$ bash tests/stress.sh
stress: 2890 of 2890 files from /home/savant/Nim/tests
stress: changed=2 improved=2 worsened=0
stress: PASS — no fix ever increased errors; every change reduced them
```

The two files it changed were genuine "indented body but no `=`" cases in the
parser's own regression tests — repaired correctly, with nothing else across the
2890 ever made worse.

## Running everything

```sh
bash tests/run.sh    # builds if needed, then fix.sh + zerofp.sh + stress.sh
```

The whole suite runs in well under a minute. `stress.sh` skips cleanly if the
Nim test corpus isn't present, so the core proof runs anywhere the parser and a
nimony toolchain do.
