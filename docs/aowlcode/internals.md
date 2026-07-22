# Internals — config, hooks, LSP, skills

[[toc]]

---

## Config (env vars, all optional)

| Variable | Effect | Default |
|---|---|---|
| `NIMLANG_TOOLCHAIN` | Forces `nim` or `nimony` for every call. | unset (auto-detect) |
| `NIM_BIN_DIR` | Directory holding `nim`, `nimsuggest`, `nimble`. | `PATH`, then `~/Nim/bin` |
| `NIMONY_BIN_DIR` | Directory holding `nimony`, `nimsem`, `hastur`. | `PATH`, then `~/nimony/bin` |
| `NIMLANG_AGGRESSIVE` | Truthy → every tool defaults to terse output. | unset (verbose) |
| `AOWLI_BIN_DIR` | Directory holding `aowli-interp`/`aowli-dbg` (for `trace`/`debug`). | `PATH`, then `~/.aowl/bin`, then `~/aowli/bin` |
| `NIFLENS` | Path to the optional `niflens`/`aiflens` helper. | `PATH` lookup |

## Hooks

Stdlib-only Python, fail-open (any error exits 0 rather than blocking).

| Hook | Event / matcher | Behavior |
|---|---|---|
| `guard-nif-read.py` | `PreToolUse` / `Read` | Denies reading a `.nif` >15000 bytes; embeds a compact outline of the file in the denial reason (transform-not-block) so the same turn still gets useful structure. |
| `guard-nif-bash.py` | `PreToolUse` / `Bash` | Denies `cat`/`head`/`tail`/`less`/`more`/`bat` targeting a `.nif` >15000 bytes — the shell-side bypass of the Read guard. |
| `trim-build-output.py` | `PostToolUse` / `Bash` | For `nimony`/`hastur`/`nim c`/`nimble` invocations, strips `nifmake:`/`FAILURE:`/`niflink` noise and surfaces the real diagnostics as `additionalContext`. |
| `precompact-nudge.py` | `PreCompact` (no matcher) | Reminds the agent to run `/land` first if durable learnings from the session haven't been flushed to memory — compaction discards anything not written down. |

## `.lsp.json` — single dispatching entry

Nim and Nimony share the `.nim` extension; Claude Code has no documented way
to run two servers against the same extension. `.lsp.json` ships **one**
entry whose command is a dispatcher (`scripts/lsp-dispatch.py`, stdlib-only):

```json
{
  "aowlcode": {
    "command": "python3",
    "args": ["${CLAUDE_PLUGIN_ROOT}/scripts/lsp-dispatch.py"],
    "extensionToLanguage": { ".nim": "nim", ".nims": "nim" },
    "diagnostics": true
  }
}
```

On launch it applies the same toolchain detection as the MCP server, then
`exec`s exactly one real server, piping JSON-RPC through untouched:

| Detected | Server | Install |
|---|---|---|
| Nim (default) | `nimlangserver` | `nimble install nimlangserver` |
| Nimony | `aoughwl/aowl-lsp` | build `server/`, put `aowl-lsp` on `PATH` |

Overrides: `NIMONY_LSP`/`NIM_LANGSERVER` point at server binaries;
`NIMONY_EXE` sets the Nimony compiler the LSP shells out to. Optional
enhancement only — every tool, hook, command, and skill works with no LSP
installed; `"diagnostics": false` keeps navigation but suppresses per-edit
injection.

## Skills (load on demand)

| Skill | Read it when |
|---|---|
| `token-thrift` | Working Nim/Nimony code and want compact diagnostics/NIF without flooding context; prefer recipe tools (`explain_failure`) over manual multi-call sequences. |
| `repo-map` | Navigating a codebase across a session — keep a lazy incremental project map in file-memory, use `symbols`/`api` before grep/reads. |
| `nif-format` | Working with `.nif` artifacts or the phase pipeline — tag vocabulary, `.p`/`.s`/`.x`/`.dce` suffixes, which tool produces which. |
| `compiler-contracts` | Building tooling ON the toolchain (LSP, formatter, driver) rather than fixing a bug — the contracts the MCP tools normally hide: idetools relative-path rule, exit-code-0-on-error, coordinate bases, NIF decl-vs-use encoding. Pair with `raw` mode. |
| `debug-loop` | Debugging the Nimony compiler itself (miscompiles, bad NIF, phase regressions) — the `~/nimony/AGENTS.md` workflow. |
| `nim-vs-nimony` | Before writing/compiling/debugging code that might target Nimony — which binary for what, feature-set deltas; do not assume Nim 2 semantics. |

## Wiring

- `.mcp.json` registers the server: `python3 ${CLAUDE_PLUGIN_ROOT}/mcp/server.py`, server name `nimlang`, protocol `2024-11-05`.
- Commands live under `commands/*.md`, namespaced `/aowlcode:<name>`.
- Agents under `agents/*.md` (see [Agents](agents)).
