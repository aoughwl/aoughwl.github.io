---
title: IC — Batch-intern ceiling + proof
grand_parent: Fork
parent: Changelog
nav_order: 23
---

# Incremental compilation
{: .no_toc }

## Batch-intern ceiling measurement + proof
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `experiment` · **Status** <span class="pill ok">Measured</span> · **Result** index intern `91.6ms → 8.6ms` (20 modules) · [← ledger](../nimony)
</div>

## The question
How much does re-interning shared indexes actually cost, and how much would a
compile daemon (or in-process batching) claw back?

## The measurement
Added `-d:idxProfile` timing around the single `load()` seam in `programs.nim`
(per-suffix cold/warm parse+intern counts, dumped by `nimsem` / `hexer`), and
fixed the latent `-d:vfsProfile` build (missing `std/monotimes` import in
`vfs.nim`).

**Ceiling** (`tall.nim`, 41 imports, 164 procs): `system.s.idx.nif` was
re-interned **107×**, ~505ms aggregate CPU; ~642ms across all indexes (aggregate,
partly hidden by `nifmake` parallelism).

## The proof
Running 20 independent modules in **one** `nimsem m` invocation (shared
`prog` / `pool` via `semcheckCycleGroup`) interns `system` **once instead of
20×** (cold 20→1), cutting index parse+intern CPU **91.6ms → 8.6ms** and giving
~1.3× wall.

**Recommendation** (`docs/daemon-prototype-findings.md`): ship in-process
depth-batching (reuses the existing cycle-group path, no IPC) *before* the full
`nimsem serve` daemon.

**Files touched:** `nimony/programs.nim`, `nimony/vfs.nim`, experiment script,
`docs/daemon-prototype-findings.md`.
