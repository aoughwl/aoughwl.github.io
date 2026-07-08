---
title: Issue #5 — Proc-pragma macros silently dropped the routine
parent: Changelog
nav_order: 5
---

# Issue #5
{: .no_toc }

## Proc-pragma macros silently dropped the routine
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** macros suite · [← ledger](../nimony)
</div>

## Symptom
A proc-pragma macro (e.g. `{.async.}`) silently produced nothing — the routine vanished with an “expression expected”.

## Root cause
The NimNode ⇄ NIF codec had no `"proc"` case, so a `proc` routine round-tripped through the codec to an empty node.

## The fix
Add `of "proc": nnkProcDef` to the decoder and map it back on the encode side, so `proc` routines survive the round-trip.

**Files touched:** `lib/std/private/macros_nif.nim`

## Verification
Covered by macros suite.
