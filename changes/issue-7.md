---
title: "Issue #7 — Generic `race[T]` spawned via `delay` failed to link"
grand_parent: Fork
parent: Changelog
nav_order: 7
---

# Issue #7
{: .no_toc }

## Generic `race[T]` spawned via `delay` failed to link
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** `tgenrace` (native + JS) · [← ledger](../nimony)
</div>

## Symptom
A generic `race[T]` spawned as `delay raceW(...)` failed to link on **both** native and JS: `loadForeign`: “Symbol not found: raceW.0.coro.<sfx>”.

## Root cause
`semDelay`'s generic-instantiation branch copied the delayed callee **verbatim**, so a generic callee was never instantiated — its `.coro` frame type was therefore never emitted, and the linker had nothing to bind.

## The fix
Reconstruct the `(call …)`, re-sem it (which instantiates the generic and emits the `.coro` frame), then re-flatten back to `(delay …)`.

**Files touched:** `nimony/sem.nim`

## Verification
Covered by `tgenrace` (native + JS).
