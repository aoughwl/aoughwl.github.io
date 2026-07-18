---
repo: aoughwl/aowl-code
---

# aowl-code — Nim/Nimony Claude Code plugin & MCP server

A Claude Code plugin that mediates agent access to the **Nim** and **Nimony**
toolchains through structured tools, so an agent works from compact diagnostics,
outlines, and targeted NIF slices instead of raw compiler output and
multi-hundred-kilobyte S-expression artifacts.

> The repo was renamed `nim-code → aowl-code`. The installed plugin's command
> namespace (`/nim-code:*`) and marketplace slug still read `nim-code` until the
> plugin manifest is republished.

The plugin supports both toolchains from one interface: the same commands and
tools operate on Nim (`nim`, `nimsuggest`, `nimble`) and on
[Nimony](../nimony) (`nimony`, `nimsem`, `hastur`, and the `nimcache/*.nif`
artifacts its pipeline emits). Toolchain selection is automatic and overridable.

[[toc]]

---

## Why

Both toolchains produce output that is costly to pass through an agent verbatim.
The plugin targets six recurring sources of token waste:

| Source | Cost | Mitigation |
|---|---|---|
| NIF artifacts in `nimcache/` | a single lowered `.nif` is 160 KB–700 KB of parenthesized S-expression | read only via `nif_outline` / `nif_query` / `nif_diff` / `nif_render`; direct reads intercepted by hooks |
| Noisy compiler output | `nimony c` / `hastur` interleave `nifmake:` / `FAILURE:` / `niflink` with real diagnostics | `compile` parses diagnostics; a `PostToolUse` hook strips noise |
| `nimony c` exits 0 on failure | the exit code is unreliable | failure determined by parsing for an `Error:` diagnostic, not exit status |
| Large NIF test diffs | `hastur --overwrite` diffs run to thousands of lines | `nif_diff` collapses unchanged regions to a structural diff |
| Symbol lookup across a large tree | grep is repetitive and unbounded | `symbols` (name) and `defs_uses` (position) return structured results in one call |
| Repeated context loss | the NIF tag vocabulary + Nim/Nimony distinction re-derived each session | shipped as on-demand skills; a project map lives in persistent memory |

## What's in it

- **MCP tools** — `compile`, `build`, `outline`, `symbols`, `defs_uses`,
  `nif_outline` / `nif_query` / `nif_diff` / `nif_render`, `explain_failure`,
  `shrink`, `phase_report`, `api`, and more.
- **Terse / builder modes** — compact `file:line` output; a build-and-report loop.
- **Hooks** — intercept raw NIF reads and strip build noise automatically.
- **Skills & subagents** — the NIF format, phase pipeline, and debug loops shipped
  as on-demand skills; specialized subagents (`nif-inspector`, `nim-fixer`).
- **Optional LSP** integration.

## Install

Loaded from a plugin directory — nothing is published to a registry:

```bash
claude --plugin-dir /path/to/aowl-code
```

The repository README (linked above) carries the complete MCP tool reference,
configuration, hooks, and toolchain-detection details.
