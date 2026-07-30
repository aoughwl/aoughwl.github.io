# MCP tool reference

[[toc]]

---

`nimlang` server, 26 tools, JSON-RPC 2.0 over stdio. Every tool accepts an
optional `terse: bool` (default = truthiness of `NIMLANG_AGGRESSIVE`) — see
[Terse mode](#terse-mode). `compile`, `build`, and `defs_uses` also take
`raw: bool`, echoing the exact argv/contract they ran — see [Raw mode](#raw-mode).

## Compile & build

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `compile` | `file`, `toolchain="auto"`, `extra_args=[]`, `terse`, `raw` | `{ok, toolchain, stage, diagnostics}` | Type-check only (`nim check` / `nimony c`). No binary produced. |
| `build` | `file`, `toolchain="auto"`, `run=false`, `release=false`, `extra_args=[]`, `terse`, `raw` | `{ok, toolchain, diagnostics, binary?, run?}` | Links an executable. `binary`: Nim beside source, Nimony `nimcache/<hash>/<module>`. `run:true` also captures `{exit_code, output}` separately from diagnostics. `release` → `-d:release`. |
| `explain_failure` | `file`, `toolchain="auto"`, `extra_args=[]`, `terse` | `{ok, toolchain, verdict, diagnostics, culprit?}` | Compiles; on failure returns a ≤5-line `verdict` + `culprit` (Nimony: smallest NIF node spanning the error; Nim: ±3 source lines). Replaces compile→outline→query by hand. |
| `shrink` | `file`, `toolchain="auto"`, `terse` | `{original_lines, minimal_lines, minimal_source, kept_error}` | Delta-debugs to a minimal still-failing repro (drops top-level statements while the first `Error:` is preserved). Bounded: ≤200 compiles / 90s. |
| `phase_report` | `file`, `toolchain="auto"`, `extra_args=[]`, `terse` | `{ok, phases:[{phase, artifact, summary}]}` | Compiles with Nimony, 1-line summary (byte size, node count, top tag counts) per `nimcache/*.<phase>.nif`. Nim → empty list + note (no NIF phases). |

## Orientation & search

These two replace the shell habits that [aowl mode](aowl-mode) denies. Both
exclude checked-in generated artifact trees (`nimcache/`, `*.nif`, emitted
`*.c`) and all hidden directories — `.claude/worktrees/` alone can multiply a
repo's apparent source tree by ten.

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `doctor` | `versions=false` | `{found, missing, note?, aowl_mode, terse_default, plugin}` | Which binaries every tool will shell out to (`nim`, `nimsuggest`, `nimble`, `nimony`, `nimsem`, `nifler`, `hastur`, `aowli-interp`, `aowli-dbg`), what is missing and which tools that breaks, the aowl mode currently in force, and whether the **running plugin copy is stale** relative to the marketplace checkout (Claude Code executes an installed copy under `~/.claude/plugins/cache/<marketplace>/<plugin>/<version>/`; a reload that fetches a new version but leaves `installed_plugins.json` on the old directory runs old code, and the only symptom is a missing command or tool). Run first when a failure looks environmental. |
| `map` | `root="."`, `max_dirs=20`, `max_modules=15` | `{toolchain, builds_with?, toolchain_note?, entry_points, config, dirs, largest, modules, lines}` | Whole-repo orientation in ONE call, replacing the `ls` + `find` + `cat README` + outline-three-files opening ritual. `builds_with` parses the build script's actual compiler invocation — which is how a Nimony project carrying no `nimony.cfg` marker stops reading as Nim, with `toolchain_note` flagging the disagreement. |
| `search` | `pattern`, `root="."`, `glob`, `files=false`, `fixed=false`, `case=false`, `max_hits=40`, `per_file=6`, `max_cols=160`, `include_generated=false` | `{matches:[{file, hits:["N: text"]}], files, hits, truncated?, note?}` | The `Grep`/`Glob` replacement. Output is capped on three axes at once — per line, per file, per search — and says so when it truncates; hits are grouped by file so N matches cost one path string. `files: true` returns matching paths only (substring, or fnmatch when the pattern has glob metacharacters). For a Nim *symbol*, `symbols`/`defs_uses` are still sharper. |

## Navigation

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `outline` | `file`, `toolchain="auto"`, `terse` | `{toolchain, symbols:[{name,kind,line,col}], source?}` | Top-level symbols. Nim via `nimsuggest outline`; else a source regex fallback (flagged `source:"regex-fallback"`). |
| `symbols` | `name`, `root=".",` `kind`, `uses=false`, `terse` | `{defs:[{name,kind,file,line}], root, uses?}` | Project-wide name-substring search, regex-based, toolchain-agnostic. Skips `nimcache`/`.git`/nimble dirs; capped at 4000 files / 400 hits. |
| `defs_uses` | `file`, `line`, `col`, `toolchain="auto"`, `terse`, `raw` | `{def, uses}` | Definition + usages at a position. Nim via `nimsuggest def`/`use`; Nimony via `nimsem --def`/`--usages idetools` against the module's `.s.nif`. Degrades to `{error, hint}` if unavailable. |
| `decl_of` | `symbol` (symId or name), `cwd="."`, `kind`, `terse` | `{decls:[{sym,kind,file,line,col,signature,nif}], backend}` | Nimony-only reverse index: symId (`add.0.tgokb0h9q`) or bare name → declaration site(s) across `nimcache/*.s.nif`. Fills the gap `symbols` (name) and `defs_uses` (position) leave for symId-keyed lookups (semantic tokens, workspace symbol). Prefers the `niflens`/`aiflens` helper, falls back to an in-Python NIF walk. |
| `api` | `module`, `toolchain="auto"`, `needle`, `terse` | `{toolchain, module, source?, api:[{name,kind,sig}]}` | Typed public API without reading source. Nim: `nim jsondoc` on a `.nim` path / nimble package / `std/*` module. Nimony or a `.nif` path: renders the compiled artifact via `nif_render`, or a note to compile first. |

## NIF artifact inspection (Nimony-only)

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `nif_outline` | `nif_file`, `terse` | `{tags:[{tag,name,line,col?,sym?}], backend}` | Top-level `(tag name ...)` nodes, no bodies. |
| `nif_query` | `nif_file`, `needle`, `terse` | `{matches:[{tag,name,snippet}], count, backend}` | Subtrees whose head tag or symbol matches `needle`; snippets truncated (~40 lines, ~15 terse). Capped at 50 matches. |
| `nif_render` | `nif_file`, `needle?`, `terse` | `{rendered:[{tag,name?,pseudo_nim}], backend}` | Renders NIF node(s) as compact pseudo-Nim (`proc`/`let`/`call`/`if`/`type`/… mapped to Nim-ish syntax, `sym.NN.mod` demangled to `sym`); unknown tags fall back to a raw s-expr. ~10x smaller than raw NIF. |
| `nif_diff` | `file_a`, `file_b`, `mode="raw"\|"canon"\|"semantic"`, `max_lines` | `{changed:[...], identical, differing}` | Unified diff (context 1) between two NIF/text files, headers trimmed. `mode=canon` strips line-info suffixes and framing directives; `mode=semantic` additionally folds generic-instance hashes and orders instances — the canonical form for oracle comparison, and what makes a differential harness's `canon.py` unnecessary. |
| `nif_run` | `file`, `deps`, `variants=[]`, `program_args=[]`, `install_as`, `timeout=60`, `max_chars` | `{exit, stdout, equivalent?, diverged?}` | Executes an already-built `.s.nif` on the aowli interpreter together with its sibling dependency modules. The module under test is installed under its **real nimcache name** — derived from the `.s.nif`'s own `(stmts …)` header — because getting that step wrong silently runs the *oracle* instead of the candidate. Several `variants` run in identical environments for a one-call behavioural-equivalence verdict; bytes are returned only when they diverge, plus a warning when the reference printed nothing (an equivalence check on a silent program proves nothing). |
| `bisect` | `command` (with a `{flags}` hole), `toggles`, `when="exit_nonzero"` (also `exit_zero`, `stdout_contains`/`_lacks`/`_differs`/`_same`), `pattern`, `cwd`, `timeout=120` | `{minimal, baseline_reproduces, attempts}` | ddmin over a flag matrix: the minimal toggle subset that still reproduces a divergence. Generalises the `--no:PASS` sweep that pins a miscompiling compiler pass, and unlike a linear scan it finds multi-flag interactions. The no-toggle baseline is run and reported, so a vacuous result is visible rather than convincing. |

All four prefer the optional `niflens`/`aiflens` helper (the compiler's own NIF
libraries — set `$NIFLENS` or put it on `PATH`) and fall back to an in-Python
paren-matching scanner otherwise; each response reports which via `backend`.

## Execution (Nimony-only, aowli-backed)

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `trace` | `file`, `max_lines=300`, `raw` | `{ok, trace, stdout, exit_code}` | Compiles to typed NIF, runs `aowli-interp --trace`, returns the depth-indented call tree (`→ callee(args) :LINE` / `← <ret>`) ending in a `-- trace: N calls, max depth M` summary (always kept even when trimmed). |
| `debug` | `file`, `breaks=[int]`, `break_funcs=[str]`, `watch=[str]`, `expand=[str]`, `raw` | `{ok, captures, stdout, exit_code}` | Compiles to typed NIF, runs `aowli-dbg` with `--break:LINE`/`--break-func:NAME`, returns one capture block per hit: line, routine, frame locals. Batch. Values are char-budgeted; `watch` trims to named locals, `expand` drills deep dotted/indexed paths losslessly. |
| `debug_session` | `action`, `session_id`, + start args (`file`, `breaks`, `break_funcs`, …), `paths`/`spec` | `{session_id, status, location, locals, stack, …}` | **Interactive/progressive**: runs once and stays paused between calls. `action` = start/step/next/finish/continue/expand/locals/stack/break/clear/stop — step & inspect the live frame with no re-run per look. |

See [Execution](execution) for the binary-resolution chain and capture semantics.

## Bounded shell

The two remaining unbounded-output habits, which aowl mode deliberately lets
through (they are not archaeology) and which are still among the largest single
context costs in a session.

| Tool | Args | Returns | Purpose |
|---|---|---|---|
| `changes` | `cwd="."`, `rev`, `staged`, `paths=[]`, `patch=false`, `max_files=40`, `max_hunks=8`, `max_chars` | `{files:["+A -D path"], hunks:{path:["@@ …"]}, untracked?, patch?, changed}` | `git diff` reduced to per-file +/- counts and **hunk headers** — which procs changed and by how much, at ~1% of the patch's size. Ask for `patch: true` on the one file that turns out to matter. |
| `run` | `command`, `cwd`, `grep`, `head=30`, `tail=60`, `timeout=300` | `{exit, lines, output, truncated?, matched?}` | Runs a command and elides the **middle** of its output rather than the tail: a build log's ends carry the information — what ran, and why it stopped — while the middle is repetition, so the failing assertion always survives. `grep` filters to matching lines instead. |

## Terse mode

Per-call `terse: true`, or session-wide via `NIMLANG_AGGRESSIVE` (truthy env
var). Effect by tool family:

| Family | Terse shape |
|---|---|
| `compile` / `explain_failure` | Warnings/Hints dropped; each diagnostic → `"file:line:col msg"`. `ok` kept. |
| `outline` | `["name:line", ...]` |
| `defs_uses` | `{def: "file:line"\|null, uses: ["file:line", ...]}` |
| `symbols` | `{defs: ["file:line kind name", ...], uses: [...]}` |
| `api` | Bare signature strings instead of `{name,kind,sig}` objects. |
| `nif_query` / `nif_outline` / `nif_render` | Snippet caps ~15 lines (vs ~40); null/empty fields omitted. |

## Raw mode

`compile`, `build`, `defs_uses` only. `raw: true` adds the exact argv the tool
ran (`invocation`/`invocations`), and for `defs_uses` a `contract` string
spelling out the gotcha the tool otherwise absorbs — e.g. Nimony idetools
requires the tracked path to be the **basename/cwd-relative** form stored in
the `.s.nif`, never absolute (absolute → "symbol not found"). Aimed at anyone
reimplementing a consumer of the toolchain (LSP, formatter, custom driver);
pair with the `compiler-contracts` skill.
