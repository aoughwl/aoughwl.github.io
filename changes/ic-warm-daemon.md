# Incremental compilation

## `nimsem serve` — persistent warm-worker daemon

<div class="entry-meta" markdown="1">
**Type** `feature` · **Status** <span class="pill ok">Prototype (Phase 1)</span> · **Consumed by** [aowl-lsp](../docs/aowl-lsp) (opt-in) · [← ledger](../nimony)
</div>

## The change
A persistent semcheck worker that keeps the interner (`pool`), the
loaded-interface cache (`prog.mods`) and the derived style indexes **warm across
many requests**, so shared interfaces (notably `std/system`) are parsed and
interned once per *session* instead of once per module. This is the foundation
for interactive / incremental (LSP) rebuilds.

**Protocol** (`docs/daemon-protocol.md`, envelope `v0`): line-framed JSONL on
stdin/stdout. Verbs:

- `semcheck` — byte-identical to `nimsem m`
- `setOverlay` / `clearOverlay` / inline `overlays` — **dirty-buffer submit**: an
  editor client can override an on-disk file with an in-memory buffer via the
  `openNifStream` seam
- `shutdown`
- reserved (schema fixed, handler stubbed): `recheck`, `defs`, `symbols`

Invalidation (`prepareForNextRequest`) puts correctness before speed: state that
could be stale is dropped before each request. Does not touch the `idetools`
text format.

**Files touched:** `nimony/nimsem.nim`, `docs/daemon-protocol.md`.

## Why it's opt-in for the cold build
The cold full-build payoff is marginal — `system` re-intern is CPU-cheap and
hidden behind the parallel fan-out — so `serve` is oriented toward
persistent-session use. [aowl-lsp](../docs/aowl-lsp) wires it as an **opt-in**
navigation backend that falls back to `idetools` on any miss.
