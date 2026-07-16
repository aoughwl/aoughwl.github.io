---
title: "Feature — `delay <call>` inside generics"
grand_parent: Compiler work
parent: Changelog
nav_order: 102
---

# Feature
{: .no_toc }

## `delay <call>` inside generics
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Area** compiler / async · **Verified by** `tgenrace` · [← ledger](../nimony)
</div>

## What it enables
Spawn a coroutine from inside a generic proc — the prerequisite for a generic `race[T]`/`gather`.

## How
`semDelay` is re-entrant and re-sems the delayed call on instantiation so the generic callee is actually instantiated (issues #2, #7).

**Files:** `nimony/sem.nim`

## Verification
Covered by `tgenrace`.
