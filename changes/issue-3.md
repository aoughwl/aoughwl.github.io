---
title: "Issue #3 — Macro plugins failed to compile outside the repo"
grand_parent: Fork
parent: Changelog
nav_order: 3
---

# Issue #3
{: .no_toc }

## Macro plugins failed to compile outside the repo
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** macros suite · [← ledger](../nimony)
</div>

## Symptom
Any file living outside the nimony checkout failed to build a macro plugin: `cannot open <mod>.s.deps.nif`.

## Root cause
`nimonyDir()/src/lib` was added to the search path only per-directory, so module suffixes computed for an out-of-tree file disagreed with the ones baked into the plugin build.

## The fix
Add `nimonyDir()/src/lib` **unconditionally** in `setupPaths`, so every compilation agrees on the same module suffixes.

**Files touched:** `nimony/semos.nim`

## Verification
Covered by macros suite.
