---
title: Feature — Proc-pragma macros (`{.async.}`)
parent: Changelog
nav_order: 104
---

# Feature
{: .no_toc }

## Proc-pragma macros (`{.async.}`)
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Area** compiler / async · **Verified by** `tasyncsugar` · [← ledger](../nimony)
</div>

## What it enables
A macro can receive **and return** a `proc` routine — the mechanism behind writing `{.async.}` instead of `{.passive.}`. Works when the macro is **imported** and across native/JS bit widths.

## How
`proc` survives the NimNode⇄NIF round-trip, imported macros fall back to their on-disk plugin, and plugins build/run host-native regardless of the target (issues #5, #8a/b/c).

**Files:** `lib/std/private/macros_nif.nim`, `nimony/semcall.nim`, `nimony/macro_plugin.nim`

## Verification
Covered by `tasyncsugar`.
