---
title: How we test — a byte-exact oracle, and the ways a gate lies
description: Every aoughwl stage that replaces an existing tool is diffed byte for byte against that tool. What that bar catches, and the specific ways our own gates reported green while testing nothing.
---

# How we test

Every stage that replaces an existing tool runs on the same input as that tool,
and the two output files are compared byte for byte. The reference is the
**oracle**. A stage passes a case when the diff is empty, not when the output
looks right.

The parser is diffed against Nimony's `nifler`, the type checker against
`nimsem`, the interpreter against a native compile-and-run, the JavaScript
engine against test262. The scoreboard is the [parity page](/docs/parity).

The bar is easy to state, and most of the work is keeping it honest. This page
is about that second part: the ways our gates reported success while testing
nothing, and the rules each one left behind.

[[toc]]

## Why byte-exact

A semantic comparison ("both programs print the same thing") forgives
everything the test program happens not to exercise. A byte comparison
forgives nothing: symbol numbering, emission order, line info and the exact
spelling of every type all have to match. That is what makes a stage a drop-in
replacement. If a stage's output is byte-identical to the reference's, any
consumer of the reference's output accepts ours.

It also makes failures small. A non-empty diff points at the first token that
differs, and the minimal reproduction is usually a few lines.

## A gate that cannot see its subject reads as green

### "Byte-exact" was canon-exact, and the two are different numbers

The type checker's module gate reported 45 modules "byte-exact". It compares a
**canonicalised** form that strips line info and the import section, which is
what makes the diff readable. Counting real file identity instead: exactly
**1** of the 45 was a byte-identical artifact.

The canonicaliser was right to strip those carriers. The mistake was the word.
Two real divergences lived in the stripped part: line-info attribution for code
expanded from included files (44 of 55 modules), and index checksums (12
modules). Both now have their own gates.

**Rule:** say what the gate compares, not what it is meant to establish.

### An empty diff of two empty files

A canonicaliser crash left both output files empty, `diff` found nothing, and
**all 718 cases passed**. Every gate now checks the exit code and that the
compared files are non-empty.

**Rule:** a comparison of two failures is not a pass.

### `n/n` is true at zero

Several harnesses printed `N/N passed` with the case count derived from
`pass + fail`. A glob that matched nothing printed `0/0`, and some printed a
confident green. Every gate now has a floor (`MIN_CASES`) set to the real
current count, so a case disappearing turns it red.

**Rule:** count the denominator independently of the results.

### The trace channel was the missing filter

On 2026-08-19 a debug trace came back empty under `tests/probe.sh`, and the
empty log was nearly recorded as "this code path is never reached". The probe
script was discarding stderr; the same trace printed twice under another
harness. Since 2026-10-08 aowlsem prints a `traces on:` banner whenever a trace
is set, and the probe fails loudly when the banner is missing.

**Rule:** an absent output is evidence only if the channel is shown to be live.

## The oracle has quirks too

### It caps its error list at four, and drops the earliest

Six identical errors in one file produce exactly four diagnostics, for lines
12, 16, 20 and 24. Lines 4 and 8 are dropped. A multi-shape probe file read as
"the oracle accepts shapes 1 and 2", and a check was wrongly exempted on that
basis. Probes for "does the oracle accept this" now use one shape per file.

**Rule:** an absent error in a multi-error run is not acceptance.

### `--bogus-flag` exits 0

`nimony c --bogus-flag x.nim` prints its help and exits 0 having compiled
nothing. No exit status from a Nimony-family tool is trusted on its own; gates
assert that the artifact exists and is newer than the run.

## Proving a gate can fail

### Put the bug back

A gate nobody has seen fail is not known to work. Each new gate is run twice:
once with the fix, once against a binary with the fix reverted. Deliberately
breaking the canonicaliser took the corpus gate from 718/718 to 0/718, and that
single check is what makes the other 718 credible.

One draft gate scored 4/4 against the reverted binary, so it was testing
nothing. It forced the failure by truncating an input, which crashes the child
under *either* binary; the real defect is a child that diagnoses an error and
still writes a complete output. Rewritten to force that shape, it scores 4/4
with the fix and 1/4 without.

### Kill switches instead of `git stash`

Measuring a change by stashing it fails on the self-hosted rows, where the
compiler compiles itself: stashing shrinks the oracle's input too. Every
significant change ships with an environment kill switch
(`AOWLSEM_NO_DEFINEDGUARD=1`, `AOWLI_NO_SEQCOPY=1`), and `tests/ab.sh` runs one
binary both ways over the same input.

On 2026-10-08 that A/B answered a performance question in two minutes. A
program ran more than 140 times slower interpreted than native, and the obvious
suspect was that day's seq copy-on-assign fix. With the switch: 440 MB at 60
seconds without the copy, 467 MB with it. The copy was not the cause.

## What a green run still does not mean

### A gate run beside another build is not evidence

Every `nimony c` on the machine regenerates one shared object file regardless
of its cache directory, so concurrent builds corrupt each other and the loser
fails with a link error that reads like a real one. Builds take a machine-wide
lock. Any surprising result is re-run alone before it is believed.

### The stale binary

On 2026-08-03 the type checker's binary was 14 hours older than three of that
day's committed source changes, and every gate defaulted to it. A day of
results described code that was not in the binary. Gates now refuse to run
when any source file is newer than the binary, and print its path and mtime.

## Measured, dated, or deleted

Every number on this site is supposed to come from a command, with a date.
`tools/claimcheck.py` in the site repository re-runs the commands behind the
numbers it can and reports which ones disagree. A number it cannot attribute
is either measured and pasted, or removed. On 2026-10-08 it found that the C
backend's test count had grown from 21 to 24 and that a parser throughput
range matched nothing reproducible; both pages now carry the measured figures,
with the hardware named.
