---
title: "Feature — Cross-module `.passive`"
grand_parent: Fork
parent: Changelog
nav_order: 101
---

# Feature
{: .no_toc }

## Cross-module `.passive`
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Area** compiler / async · **Verified by** `tsleep3`, `tgather2` · [← ledger](../nimony)
</div>

## What it enables
`await` / `sleepAsync` / coroutine helpers resolve and compose across module boundaries — so async code can be split into libraries instead of one file.

## How
Mangle and publish coroutine wrappers against their *defining* module (the root fix behind issue #6 in the runtime sense; see issue #1).

**Files:** `hexer/coro_transform.nim`, `hexer/cps.nim`

## Verification
Covered by `tsleep3`, `tgather2`.
