# Agents & fan-out

[[toc]]

---

Subagents run in their own context and hand the parent conversation only a
conclusion — never raw compiler output, NIF dumps, or full file contents.

## Model tiering

| Agent | Model | Tools | Job |
|---|---|---|---|
| `nif-inspector` | default (no override) | `Read`, `Bash`, `Glob`, `Grep` | Absorbs bulky NIF/phase artifacts and large Nim/Nimony source; returns the specific tag/symbol/phase/`file:line` that answers the question, one-to-few sentences, at most a tiny snippet. Prefers `nif_outline`/`nif_query`/`nif_diff` over raw reads (blocked >15KB anyway). |
| `nim-fixer` | `haiku` | `Bash`, `Read`, `Edit`, `compile`, `explain_failure`, `shrink`, `outline`, `nif_query`, `nif_render` | Runs the diagnose loop: `explain_failure` → (optionally) `shrink` → targeted `Read`/`Edit` → `compile` to recheck → repeat. Stops at `ok:true`, ~6 attempts with no progress, or genuine ambiguity. Returns a minimal diff + one verdict line. |
| `nim-applier` | `haiku` | `Bash`, `Read`, `Edit`, `compile`, `build` | Applies ONE pre-specified exact edit (old/new text or diff) + runs a given verify command. Does not diagnose, shrink, or improvise — ambiguous match or edit-doesn't-apply is reported and it stops. The mechanical fan-out worker for `nim-fixer`'s decisions. |

The split: `nim-fixer` is the expensive reasoning loop (diagnose → decide →
edit, one file at a time); `nim-applier` is the cheap, dumb, parallel-safe
worker for edits someone else already fully specified. Never route a design
decision or diagnosis to `nim-applier` — it will stop rather than guess.

## `workflows/fanout-apply`

The parallel mechanical fan-out step, for after an expensive-model pass has
already produced **N independent, exact edit specs** across a repeated
pattern (e.g. the same lowering fix applied at N call sites):

```
{file, description, edit: {old, new} | diff, verify: "compile/build command", toolchain?}
```

Each spec is handed to one `haiku` `nim-applier`-style stage, run in
parallel — no cross-talk, so every item must be independently applicable
(disjoint files, or disjoint regions of the same file). Returns:

```
{total, passed, failed, results:[{file, applied, gatePass, verdict, diff}], needsAttention}
```

Not for research, diagnosis, or design decisions — those stay interactive in
the main conversation or a `nim-fixer` delegation, where an expensive model
(or a human) can actually judge an ambiguous diagnostic.

## `nif-inspector` in practice

Referenced from `/nif`, `/phase-diff`, and `/nimony-bug` whenever the read
would be heavy — delegate rather than reading a NIF diff or a wide symbol hunt
inline. It still prefers the same MCP tools (`nif_outline`/`nif_query`/
`nif_diff`) over raw file access; the difference is that its context absorbs
the intermediate bulk instead of the parent's.
