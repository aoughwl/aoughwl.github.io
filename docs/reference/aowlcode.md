> Verbatim archive of the `aoughwl/aowlcode` README (repo formerly `nim-code`,
> then briefly `aowl-code`; now `aowlcode`, v1.0.0). Curated summary:
> [aowlcode project page](../aowlcode).

# aowlcode

A Claude Code plugin + MCP server that mediates an agent's access to the **Nim**
and **Nimony** toolchains — so it works from compact diagnostics, outlines and
targeted NIF slices instead of raw compiler output and megabyte S-expression
artifacts.

**📖 Full docs → [aoughwl.github.io/docs/aowlcode](https://aoughwl.github.io/docs/aowlcode)**

```bash
claude --plugin-dir /path/to/aowlcode
```

## The lock is the product

Every tool below existed in 0.7 and was still routinely skipped, because
`grep -rn` is frictionless and a structural tool has to be chosen. **Since 1.0,
aowl mode is ON by default** (`guided`): `Grep`/`Glob` and the shell's
code-archaeology family (`grep`/`rg`/`sed`/`cat`/`find` aimed at `.nim`/`.nif`/
`src`, plus raw `nim c` / `nimony c`) are denied, and every denial names the
tool to use instead. `git`, test scripts and running a built binary still pass.

```
/aowl-mode status     mode + how many archaeology calls it has intercepted
/aowl-mode strict     also deny Bash outright (MCP tools + Read/Edit only)
/aowl-mode off        lift it — a written state that itself expires in 12h
```

Nothing can wedge a session: `off` is always reachable (commands containing
`aowlcode-mode` are never denied), state expires after
`AOWLCODE_MODE_TTL_HOURS` (12) in *both* directions, and
`AOWLCODE_DEFAULT_MODE` / `AOWLCODE_NO_MODE_GATE=1` move or remove the baseline.

A ~200-token session banner states the mode and the redirect table once, up
front — cheaper than the three denial messages it prevents.

## Tools

| | |
|---|---|
| `map` | whole-repo orientation in one call: toolchain, entry points, config, dirs, largest modules |
| `search` | repo text/filename search that **replaces Grep/Glob** — generated artifacts excluded, output capped per line, per file and per search |
| `symbols` · `defs_uses` · `decl_of` | where a symbol is declared / declared-and-used / what a mangled symId resolves to |
| `outline` · `api` | a file's map with line ranges / a module's public signatures without its source |
| `compile` · `build` | structured diagnostics only; `build` also links and can run |
| `explain_failure` · `shrink` | verdict + culprit for a failure / delta-debugged minimal repro (compile error **or** crash) |
| `nif_outline` · `nif_query` · `nif_render` · `nif_diff` | NIF artifacts without dumping them; `nif_diff mode=semantic` applies the oracle canon (line info + framing stripped, generic-instance hashes folded) |
| `nif_run` | execute a built `.s.nif` on the aowli interpreter with its sibling modules — or several variants in identical environments, for a one-call behavioural-equivalence verdict |
| `bisect` | ddmin over a flag matrix → the minimal toggle set that reproduces (the `--no:PASS` sweep that pins a miscompiling pass, generalised) |
| `phase_report` · `trace` · `trace_diff` · `debug` · `explain_crash` | phase artifacts / call-tree traces / batch breakpoints |
| `debug_session` | **ONE paused run**: `start` → `step`/`next`/`finish`/`continue` → `locals`/`expand`/`stack` → `stop`, with fork-based snapshot/restore. Always preferred over echo-instrumenting code |
| `changes` | bounded `git diff`: +/- counts and hunk headers (the shape of a change at ~1% of its size); `patch:true` for the one file that matters |
| `run` | any command with the **middle** of its output elided (head+tail kept, so the failing assertion survives) or filtered by regex |

## Hooks

- **session-banner** — states the mode and the redirect table once per session.
- **aowl-mode** — the lock above, read live per call (toggling needs no restart).
- **guard-generated-grep** — an unscoped search over a tree containing checked-in
  `nimcache/*.nif` or emitted `.c` is denied with the scoped re-invocation.
- **guard-nif-read / guard-nif-bash / guard-source-read** — intercept raw reads
  and dumps of NIF artifacts and oversized sources, naming the structural tool.
- **trim-build-output** — strips toolchain noise from Bash build output.
- **precompact-nudge** — reminds the agent what to preserve before compaction.

## Skills, commands, agents

Skills load on demand: `nif-format`, `nim-vs-nimony`, `debug-loop`,
`compiler-contracts`, `repo-map`, `token-thrift`.
Commands: `/aowl-mode`, `/check`, `/build`, `/api`, `/symbols`, `/nif`,
`/render`, `/shrink`, `/trace`, `/debug`, `/explain-failure`, `/phase-diff`,
`/nimony-bug`, `/aggressive`, `/land`.
Sub-agents (heavy artifacts stay in *their* context): `nif-inspector`,
`nim-fixer`, `nim-applier`.

## Tests

```bash
python3 mcp/test_server.py     # 28 end-to-end checks over the real MCP loop
```

MIT licensed. Part of the [aoughwl](https://github.com/aoughwl) stack.
