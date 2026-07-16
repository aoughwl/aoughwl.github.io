---
title: "Issue #2 — `delay <call>` crashed inside a generic proc"
grand_parent: Engineering Notes
parent: Changes
nav_order: 2
---

# Issue #2
{: .no_toc }

## `delay <call>` crashed inside a generic proc
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** cps suite · [← ledger](../nimony)
</div>

## Symptom
Using `delay <call>` inside a generic proc aborted the compile with `[Bug] expected ')'`.

## Root cause
`semDelay` wasn't idempotent. A generic body is flattened once at definition, then re-sem'd on each instantiation — the second pass saw an already-lowered `delay` it couldn't re-parse.

## The fix
Make `semDelay` re-entrant so a second pass over an already-flattened `delay` is a no-op instead of a parse error.

**Files touched:** `nimony/sem.nim`

## Verification
Covered by cps suite.
