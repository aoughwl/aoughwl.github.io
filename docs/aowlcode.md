---
repo: aoughwl/aowlcode
---

# aowlcode — Nim/Nimony Claude Code plugin & MCP server

Mediates agent access to the **Nim** and **Nimony** toolchains through
structured MCP tools: an agent works from compact diagnostics, outlines, and
targeted NIF slices instead of raw compiler output and multi-hundred-kilobyte
S-expression artifacts. One interface, both toolchains — the same commands and
tools resolve to `nim`/`nimsuggest`/`nimble` or to `nimony`/`nimsem`/`hastur`
(auto-detected per project, overridable).

[[toc]]

---

## Install

```text
/plugin marketplace add aoughwl/aowlcode
/plugin install aowlcode@aowlcode
```

`aowlcode@aowlcode` is `<plugin>@<marketplace>` — the repo is its own
marketplace. Enabling the plugin registers the `nimlang` MCP server, activates
all hooks, and exposes `/aowlcode:*` commands (see `/help`).

## Map

| Page | Covers |
|---|---|
| [Tools](aowlcode/tools) | Every `nimlang` MCP tool — args, return shape, one-line purpose. The full reference. |
| [Commands](aowlcode/commands) | `/aowlcode:*` slash commands, each mapped to its backing tool. |
| [Agents](aowlcode/agents) | Subagents (`nif-inspector`, `nim-fixer`, `nim-applier`), model tiering, and the `fanout-apply` workflow. |
| [Execution](aowlcode/execution) | `trace` / `debug` — running and inspecting a program via the aowli interpreter, not just compiling it. |
| [Internals](aowlcode/internals) | Skills, hooks, LSP dispatch, config env vars. |
| [Full README](reference/aowlcode) | Verbatim upstream README archive. |

## Toolchain detection

`toolchain="auto"` (the default) walks up from the target file for a
`nimony.paths`/`nimony.cfg`, or a `nim.cfg` mentioning nimony → Nimony;
otherwise Nim. `NIMLANG_TOOLCHAIN=nim|nimony` forces it globally; an explicit
`toolchain` arg wins per call. `nimony c` exits 0 on failure — every tool
computes `ok` from parsing for an `Error:` diagnostic, never the exit code.
