---
title: "Feature — `suspend()` in a generic `.passive` proc"
parent: Changelog
nav_order: 103
---

# Feature
{: .no_toc }

## `suspend()` in a generic `.passive` proc
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Area** compiler / async · **Verified by** cps suite · [← ledger](../nimony)
</div>

## What it enables
Generic passive procs that park (`suspend()`) now instantiate cleanly, so combinators like `race`/`gather` can be written generically.

## How
`semSuspend` types `(suspend)` as `void` (issue #6).

**Files:** `nimony/sem.nim`

## Verification
Covered by cps suite.
