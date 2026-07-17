# Issue #6

## `suspend()` in a generic `.passive` proc was mis-typed

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** cps suite · [← ledger](../nimony)
</div>

## Symptom
A generic `.passive` proc that called `suspend()` failed on instantiation with “Continuation must be discarded”.

## Root cause
`semSuspend` typed the `(suspend)` expression as `Continuation`, but `suspend` is `void` — so the instantiation saw a stray Continuation value it insisted be discarded.

## The fix
Type `(suspend)` as `void`.

**Files touched:** `nimony/sem.nim`

## Verification
Covered by cps suite.
