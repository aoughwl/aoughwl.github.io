---
title: IC — Parallel dependency discovery
parent: Changelog
nav_order: 20
---

# Incremental compilation
{: .no_toc }

## Parallel dependency-discovery pre-pass (`preNifle`)
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Status** <span class="pill ok">Shipped</span> · **Measured** discovery wall `0.43s → 0.24s` (1.77×) · [← ledger](../nimony)
</div>

## Symptom
Cold module dependency discovery was serial: `traverseDeps`' DFS ran `nifler`
one module at a time via a blocking `exec` before recursing into it.

## The change
A breadth-first pre-pass, `preNifle`, runs `nifler` over the **whole import
closure in parallel** (`osproc.execProcesses`) before the DFS starts. It only
writes the on-disk `.p.nif` / `.p.deps.nif` cache files the DFS would have
written anyway and mutates nothing on the node graph. After pre-warming, every
`execNifler` inside the DFS hits the staleness short-circuit and becomes a
no-op, so the DFS does only cheap in-memory work.

Correctness is preserved by construction: if the harvest ever misses a module,
the DFS's own `execNifler` runs it as a self-healing serial fallback.
Over-nifling (ignoring `when` pruning, plugin/include deps) is harmless — it only
warms an unused cache entry.

**Files touched:** `nimony/deps.nim` (`niflerCommandFor` extracted from
`execNifler`; `preNifle` wired into `initDepContext`).

## Verification
Discovery-phase wall time **0.43s → 0.24s median (1.77×)** on the measured tree.
Full build output byte-identical to the serial path.
