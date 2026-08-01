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
| `AOWLCODE_DEFAULT_MODE` | Baseline aowl mode when no state file exists: `off`/`guided`/`strict`. | `guided` |
| `AOWLCODE_MODE_TTL_HOURS` | How long an explicit mode (including `off`) survives before falling back to the baseline. | `12` |
| `AOWLCODE_NO_MODE_GATE` | `1` → disable the aowl-mode hook and the session banner entirely. | unset |
| `AOWLCODE_ALLOW_GENERATED_GREP` | `1` → allow unscoped searches over generated artifact trees. | unset |
| `AOWLCODE_NO_SRC_GUARD` | `1` → allow whole-file reads of large sources. | unset |
| `AOWLCODE_SERVER` | `python` forces the Python server; `nim` requires the Nimony one and fails loudly if it cannot be built. | auto |
| `AOWLCODE_NO_BUILD` | `1` → never rebuild the Nimony server; run whatever binary is present. | unset |
| `AOWLCODE_BUILD_WAIT` | Seconds `launch.sh` lets a rebuild finish **before** serving, when the sources are newer than the binary. `0` = never wait. | `25` |

## Hooks

Stdlib-only Python, fail-open (any error exits 0 rather than blocking).

| Hook | Event / matcher | Behavior |
|---|---|---|
| `session-banner.py` | `SessionStart` | Injects ~200 tokens: the active mode plus the redirect table, once per session. Cheaper than the denial messages it prevents; silent when the mode is `off`. |
| `aowl-mode.py` | `PreToolUse` / `Bash\|Grep\|Glob` | **The lock, on by default** (`guided`). Denies code archaeology and names the tool to use instead; state re-read per call, so toggling needs no restart. See [Aowl mode](aowl-mode). |
| `guard-generated-grep.py` | `PreToolUse` / `Grep\|Glob` | Denies an *unscoped* search over a tree containing checked-in `nimcache/*.nif` or emitted `.c`, handing back the scoped re-invocation. A single NIF hit can be one 40KB line. |
| `guard-source-read.py` | `PreToolUse` / `Read` | Denies a whole-file `Read` of a large `.nim`, returning a `symbol → line-range` outline in the same turn so the follow-up read is a window. |
| `guard-nif-read.py` | `PreToolUse` / `Read` | Denies reading a `.nif` >15000 bytes; embeds a compact outline of the file in the denial reason (transform-not-block) so the same turn still gets useful structure. |
| `guard-nif-bash.py` | `PreToolUse` / `Bash` | Denies `cat`/`head`/`tail`/`less`/`more`/`bat` targeting a `.nif` >15000 bytes — the shell-side bypass of the Read guard. |
| `trim-build-output.py` | `PostToolUse` / `Bash` | For `nimony`/`hastur`/`nim c`/`nimble` invocations, strips `nifmake:`/`FAILURE:`/`niflink` noise and surfaces the real diagnostics as `additionalContext`. |
| `precompact-nudge.py` | `PreCompact` (no matcher) | Reminds the agent to run `/land` first if durable learnings from the session haven't been flushed to memory — compaction discards anything not written down. Emits `systemMessage`: `hookSpecificOutput` is valid for `PreToolUse`/`UserPromptSubmit`/`PostToolUse`/`PostToolBatch`/`Stop` but **not** `PreCompact`, where it fails validation and the output is discarded. |

The session banner also warns when the MCP server is running a build older than
its sources — see [Which copy is running](#which-copy-is-running).

## Which copy is running

Claude Code does not execute the marketplace checkout. It installs a copy to
`~/.claude/plugins/cache/<marketplace>/<plugin>/<version>/` and records the path
in `~/.claude/plugins/installed_plugins.json`. If a reload fetches a newer
version directory but leaves that record on the old one, the session keeps
running the old code — visible only as a command or tool that does not exist.
`doctor` reports this directly (`plugin.stale`); the fix is to repoint the
`installPath`/`version` entry (or reinstall) and restart, not another reload.

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
