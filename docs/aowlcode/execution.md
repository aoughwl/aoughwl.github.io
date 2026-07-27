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
| Args | `file`, `breaks=[int]` (line numbers), `break_funcs=[str]` (routine names), `watch=[str]`, `expand=[str]`, `raw` |
| Returns | `{ok, captures, stdout, exit_code}` |
| Binary | `aowli-dbg --break:LINE ... --break-func:NAME ... <main.s.nif>` |

At least one of `breaks`/`break_funcs` is required. **Batch** (for interactive
stepping, use `debug_session` below): each time a breakpoint's line (any routine)
or a break-func's routine (every statement inside it) is reached, aowli-dbg
snapshots that frame's locals and execution continues — every hit is recorded,
not just the first. `captures` is one block per hit: source line + enclosing
routine + `name = value` per local, taken at statement **entry** (a line shows
the value *before* that statement runs — break on the following line for a
post-assignment value). `captures` capped at 20000 chars, `stdout` at 4000.

Each value is rendered under a **character budget**, so a huge local (a
`SemContext`, a memo table) can't explode the capture into a wall of internals —
it elides with a `{budget}` marker instead. Two knobs narrow a dump losslessly:
`watch=[names]` keeps only the named locals; **`expand=[paths]`** drills a deep
field directly — dotted/indexed paths like `["c.currentModule.name", "xs.3"]`,
rendered with a generous budget as extra `path = value` lines — so you can read
one field of a giant value without dumping the whole thing.

## `debug_session` — interactive / progressive

Batch `debug` re-runs the whole program on every call, so you must predict what
to capture, and a slow program pays a full re-run per inspection. `debug_session`
runs the program **once** and keeps it **paused between tool calls**, stepping and
inspecting the *live* frame on demand.

| | |
|---|---|
| Args | `action`, `session_id`, plus start args (`file`, `breaks`, `break_funcs`, `program_args`, `extra_args`) and `paths`/`spec` |
| Returns | `{session_id, status, location, locals, stack, …}` |
| Binary | `aowli-dbg --session … <main.s.nif>` |

`action` drives the session: `start` (compile + launch, pause on entry) →
`step` (into) · `next` (over) · `finish` (out) · `continue` (to next breakpoint
/ exit) · `expand` (drill `paths` in the paused frame) · `locals` · `stack` ·
`break` (add breakpoints **live** via `breaks`/`break_funcs`/`spec`) · `clear` ·
`stop`. Every non-`start` action takes the `session_id` returned by `start`. A
resume that hits a breakpoint returns the new paused state; one that runs off the
end returns `status:"exited"`. The subprocess is held across calls; program output
comes back interleaved as it's produced.

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
