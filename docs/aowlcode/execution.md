# Execution — trace & debug

[[toc]]

---

Nimony-only. `trace` and `debug` go past compiling — they **run** the program
under the [aowli](../aowli) tree-walking interpreter and report what happened,
without adding `echo`/`write` statements to the source.

## Pipeline (shared by both tools)

1. `nimony c --nimcache:<tmp> -f <file>` — fresh compile to a scratch nimcache,
   forced (`-f`) so the typed `.s.nif` is always emitted.
2. Any `Error:` diagnostic short-circuits with `{error: "compile failed: ..."}`
   — neither tool proceeds on a broken build.
3. Locate the main module's `.s.nif` by its `stmts` header naming the source
   basename.
4. Run the aowli binary against that artifact; scratch nimcache is removed on
   exit (`finally`).

## `trace`

| | |
|---|---|
| Args | `file`, `max_lines=300`, `raw` |
| Returns | `{ok, trace, stdout, exit_code}` |
| Binary | `aowli-interp --trace <main.s.nif>` |

`trace` is stderr from `aowli-interp`; `stdout` is the program's own output,
kept separate. The call tree: `→ callee(args) :LINE` on enter, `← <ret>` on
exit, depth-indented, ending in a `-- trace: N calls, max depth M` summary —
that footer is always preserved even when the body is trimmed to `max_lines`.
`stdout` is capped at 4000 chars.

## `debug`

| | |
|---|---|
| Args | `file`, `breaks=[int]` (line numbers), `break_funcs=[str]` (routine names), `raw` |
| Returns | `{ok, captures, stdout, exit_code}` |
| Binary | `aowli-dbg --break:LINE ... --break-func:NAME ... <main.s.nif>` |

At least one of `breaks`/`break_funcs` is required. **Non-interactive**: no
pause/resume/step. Each time a breakpoint's line (any routine) or a
break-func's routine (every statement inside it) is reached, aowli-dbg
snapshots that frame's locals and execution continues — every hit is
recorded, not just the first. `captures` is one block per hit: source line +
enclosing routine + `name = value` per local. Captures are taken at statement
**entry**, so a line shows the value *before* that statement runs — break on
the following line to see a post-assignment value. `captures` capped at 20000
chars, `stdout` at 4000.

## Binary resolution

Both tools resolve the aowli binaries through `aowli_bin(name)`, in order:

1. `$AOWLI_BIN_DIR/<name>`
2. `~/.aowl/bin/<name>` — the `aowl` version-manager's install location
3. `~/aowli/bin/<name>` — dev source-tree fallback
4. bare name on `PATH`, as a last resort

This plugin is public, so it prefers a **released** binary
([aoughwl/aowli-release](../aowli-release)) over a private source checkout —
steps 1–2 before the dev fallback at step 3. A missing/non-executable binary
returns `{error: "aowli-interp/aowli-dbg binary not found or not executable ..."}`
naming the path it looked for.

## `raw` mode

`raw: true` adds `main_snif` (the resolved `.s.nif` path) and `invocation`
(the exact `nimony c ...` and `aowli-interp`/`aowli-dbg` command lines run).

## Failure modes

| Condition | Result |
|---|---|
| Compile error | `{error: "compile failed: <first ≤5 diagnostics>"}` |
| No main `.s.nif` found | `{error: "could not locate main module .s.nif for <basename> ..."}` |
| `nimony c` hangs | `{error: "nimony compile timed out"}` (180s budget) |
| Traced/debugged program hangs | `{error: "aowli-interp/aowli-dbg timed out (possible infinite loop ...)"}` (120s budget) |
| Binary missing | `{error: "... binary not found or not executable ..."}` |

On any compile-error result, hand off to `/check` or `/explain-failure` rather
than retrying trace/debug blind.
