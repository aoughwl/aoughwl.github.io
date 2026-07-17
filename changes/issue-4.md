# Issue #4

## `.passive` capturing a `.raises` result crashed hexer

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** cps suite · [← ledger](../nimony)
</div>

## Symptom
A `.passive` proc that captured a `.raises`, non-void result crashed hexer: `assert n.kind == Symbol`.

## Root cause
The coroutine transform lifts the result local into the environment as `(dot (deref env) fld)` — a non-Symbol operand the assertion didn't expect.

## The fix
Copy the non-Symbol operand verbatim instead of asserting it is a Symbol. This removes the crash; full raise-across-await remains a deferred feature (see Known limits).

**Files touched:** `hexer/constparams.nim`

## Verification
Covered by cps suite.
