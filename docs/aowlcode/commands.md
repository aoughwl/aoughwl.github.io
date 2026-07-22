# Commands

[[toc]]

---

All namespaced `/aowlcode:<name>` (listed by `/help`). Each wraps one or more
`nimlang` MCP tool calls — commands never shell out to `nim`/`nimony` directly.

| Command | Argument hint | Backing tool(s) | Purpose |
|---|---|---|---|
| `/check` | `[file] [toolchain: nim\|nimony\|auto]` | `compile` | Type-check, report diagnostics only. Trusts `ok`, not exit code. |
| `/build` | `[file] [run] [release] [toolchain]` | `build` | Linked executable + diagnostics + binary path; `run`/`release` optional. |
| `/explain-failure` | `[file] [toolchain]` | `explain_failure` | One-shot verdict + culprit; no raw diagnostics dump. |
| `/shrink` | `[file] [toolchain]` | `shrink` | Minimal still-failing repro, reports line-count reduction + kept error. |
| `/symbols` | `<name> [--uses]` | `symbols` | Project-wide definition (+ optional usage) search by name. |
| `/api` | `<module> [needle]` | `api` | Typed API of a stdlib module / nimble package / `.nim` / `.nif`. |
| `/nif` | `<file.nif> [needle]` | `nif_outline` / `nif_query` | Outline (no needle) or query (needle) a NIF artifact. |
| `/render` | `<file.nif> [needle]` | `nif_render` | Pseudo-Nim view of NIF node(s). |
| `/phase-diff` | `<file.nim> [phaseA phaseB]` | `compile` + `nif_diff` | Compile then structurally diff two adjacent nimcache phases (default `.p.nif` vs `.s.nif`). |
| `/trace` | `[file]` | `trace` | Run under aowli-interp, report the call-tree. |
| `/debug` | `[file] [line ...]` | `debug` | Run under aowli-dbg batch breakpoints, report captured frame locals. |
| `/nimony-bug` | `[file.nim]` | `compile`, `nif_outline`, `nif_query`, `nif_diff` | Drives the `~/nimony/AGENTS.md` compiler debug loop (build→reproduce→nimcache diff→test); delegates heavy NIF reads to `nif-inspector`. |
| `/aggressive` | `[on\|off]` | — | Explains/toggles terse mode (env-wide vs per-call). |
| `/land` | `[repo path] [feature label]` | — | End-of-feature checkpoint: flush learnings to memory, commit+push (author `savannt`, no co-author trailer), print `✅ landed`. |

## Notes on specific commands

- **`/check` vs `/build`** — `/check`/`compile` only type-checks (`nim check`);
  it never produces a runnable binary, even for Nim. Use `/build` when you need
  to actually run the program.
- **`/explain-failure`** replaces the manual `compile → outline → nif_query`
  sequence with one call; report only the verdict + culprit, never the full
  diagnostics list or a raw NIF dump.
- **`/phase-diff`** phase pipeline: `.p.nif` (nifler) → `.s.nif` (nimony sem,
  `.s.idx.nif` = index) → `.x.nif`/`.dce.nif` (hexer lowering) → Leng/C.
  `.deps.nif` are dependency lists, not phase bodies. Per `AGENTS.md`, assume
  `nifler`/`nifmake`/`lengc` are stable — suspect `nimony` or `hexer`.
- **`/nimony-bug`** is for the Nimony **compiler itself** (miscompiles, bad
  NIF, phase regressions), not user code errors — those go through `/check`.
- **`/trace` / `/debug`** are Nimony-only, and resolve a released `aowli`
  binary — see [Execution](execution).
