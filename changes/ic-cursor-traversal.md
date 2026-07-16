---
title: IC — Incremental cursor traversal
grand_parent: Engineering Notes
parent: Changes
nav_order: 21
---

# Incremental compilation
{: .no_toc }

## `nimsem`: incremental structured cursor traversal
{: .no_toc .text-delta }

<div class="entry-meta" markdown="1">
**Type** `feature` · **Status** <span class="pill ok">Shipped</span> · **Toward** #2064 · [← ledger](../nimony)
</div>

## The change
`nimsem` walks the module structure with an incremental structured cursor rather
than re-materializing the whole tree, cutting redundant work on re-check. This is
groundwork toward incremental semchecking (#2064) — the machinery that lets a
warm worker re-check only what changed.

**Upstream:** #2070.

## Verification
Existing semcheck suite (byte-identical `.s.nif` output).
