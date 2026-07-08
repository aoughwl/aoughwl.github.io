---
title: Issue #8 — Imported `{.async.}` macros: three cross-target failures
parent: Changelog
nav_order: 8
---

# Issue #8
{: .no_toc }

## Imported `{.async.}` macros: three cross-target failures
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `issue-fix` · **Status** <span class="pill ok">Fixed</span> · **Verified by** `tasyncsugar` · [← ledger](../nimony)
</div>

## Symptom
Getting an **imported** `{.async.}` macro to work across the native/JS bit-width boundary surfaced three distinct failures (8a/8b/8c below).

## Root cause
A macro plugin is a host-native tool, but it was being resolved, built, and run as if it shared the target compile's module set, bit width, and nifcache.

## The fix
Three coordinated fixes in the macro-plugin path — see the breakdown below.

**Files touched:** `nimony/semcall.nim`, `nimony/macro_plugin.nim`

## Verification
Covered by `tasyncsugar`.

## Breakdown

### 8a — imported macro not recognized
**Symptom** “macro '…' not compiled”. **Cause** an imported macro's declaration is checked in its *defining* module, so it is absent from the importer's `compiledMacros`. **Fix** fall back to the on-disk plugin the dependency build already produced — `macroPluginExists` (`semcall.nim`, `macro_plugin.nim`).

### 8b — plugin build failed on cross-bit targets
**Symptom** “Pointer size mismatch…”. **Cause** a macro plugin is a HOST-native tool but inherited the target compile's `--bits:NN`. **Fix** strip `--bits:` from the forwarded args — `hostifyPluginArgs` (`macro_plugin.nim`).

### 8c — plugin built but segfaulted at run
**Symptom** segfault when the plugin runs on a cross-bit target. **Cause** the host plugin reused the target's stdlib artifacts from the shared nifcache. **Fix** build the plugin in an isolated host-bits nifcache, seeded with `import std/[syncio, macros]` (`macro_plugin.nim`).
