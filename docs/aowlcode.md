---
repo: aoughwl/aowlcode
---

# aowlcode — Nim/Nimony Claude Code plugin & MCP server

A Claude Code plugin that mediates agent access to the **Nim** and **Nimony**
toolchains through structured tools, so an agent works from compact diagnostics,
outlines, and targeted NIF slices instead of raw compiler output and
multi-hundred-kilobyte S-expression artifacts.

> Renamed `nim-code → aowlcode` (plugin v0.6.0). The internal MCP server keeps
> the name `nimlang`, so tools now live under
> `mcp__plugin_aowlcode_nimlang__…` and commands are `/aowlcode:…`.

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
  `shrink`, `phase_report`, `api`, **`trace`**, **`debug`**, and more.
- **Terse / builder modes** — compact `file:line` output; a build-and-report loop.
- **Hooks** — intercept raw NIF reads and strip build noise automatically; a
  PreCompact hook nudges the agent to run `/land` before context is discarded.
- **Skills & subagents** — the NIF format, phase pipeline, and debug loops shipped
  as on-demand skills; specialized subagents (`nif-inspector`, `nim-fixer`,
  `nim-applier`).
- **Optional LSP** integration.

## New in 0.6.0

- **`trace` tool + `/trace`** — run a program and get its execution call-tree,
  backed by the released [aowli-interp](aowli-release) binary.
- **`debug` tool + `/debug`** — batch breakpoints: run with `--break:LINE` /
  `--break-func:NAME` and capture every hit frame's variables in one call,
  backed by the released [aowli-dbg](aowli-release) binary.
- **`/land`** — a memory-flush checkpoint command: flush session learnings to
  memory, commit, and report "safe to clear".
- **`nim-applier` agent** (`model: haiku`) — a cheap mechanical-edit applier for
  parallel fan-out; keeps `nim-fixer`'s reasoning off the hot path when the
  edits are already fully specified.
- **`workflows/fanout-apply`** — parallel cheap-applier fan-out: an expensive
  model produces exact edit-specs, and concurrent `haiku` agents apply them.
- **PreCompact hook** — nudges the agent to run `/land` before a context
  compaction discards session learnings.

`trace` and `debug` resolve a **released** aowli binary, never a private source
tree: `$AOWLI_BIN_DIR` → `~/.aowl/bin` → dev `~/aowli/bin`, in that order — so a
public user runs off the binaries published in
[aoughwl/aowli-release](aowli-release), not anything internal.

## Install

From the GitHub marketplace (the repo is its own marketplace):

```text
/plugin marketplace add aoughwl/aowlcode
/plugin install aowlcode@aowlcode
```

Enabling the plugin auto-registers the `nimlang` MCP server and activates all
hooks. Commands are namespaced under the plugin — `/aowlcode:check`,
`/aowlcode:trace`, `/aowlcode:debug`, `/aowlcode:nif`, and so on — and listed by
`/help`.

The repository README (linked above) carries the complete MCP tool reference,
configuration, hooks, and toolchain-detection details.
