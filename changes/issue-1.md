---
title: "Issue #1 — `.passive` helpers didn't resolve across modules"
grand_parent: Engineering Notes
parent: Changes
nav_order: 1
---

# Issue #1
{: .no_toc }

## `.passive` helpers didn't resolve across modules
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** `tsleep3`, `tgather2` · [← ledger](../nimony)
</div>

## Symptom
A `.passive` coroutine helper (`await`, `sleepAsync`, …) defined in one module and used from another failed to link: `could not find symbol: …init.<caller>`.

## Root cause
The helper was name-mangled with the **caller's** module suffix, and the generated wrapper was never published into the *defining* module's index — so the importer looked for a symbol that lived under the wrong module.

## The fix
Derive `coroSuffix` from the module that *defines* the helper, and publish the foreign wrapper into that module's index so cross-module lookups resolve.

**Files touched:** `hexer/coro_transform.nim`, `hexer/cps.nim`

## Verification
Covered by `tsleep3`, `tgather2`.
