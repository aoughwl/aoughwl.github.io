# Debugging — aowlidbg

[[toc]]

---

aowlidbg is aowli's trace/debug layer: the `aowli-dbg` binary, plus the
`trace`/`debug` tools the [aowlcode](../docs/aowlcode/execution) Claude Code
plugin exposes over it. Both inspect a live typed-AIF execution — call tree or
frame locals — without adding a single `echo`/`write` to the source.

## Flags

| Flag | Binary | Effect |
|---|---|---|
| `--break:LINE` | `aowli-dbg` | Breakpoint on a source **line number**. Fires in *every* routine that line number appears in, across every module — file-agnostic. |
| `--break-func:NAME` | `aowli-dbg` | Breakpoint scoped to a **routine name**. Fires on every statement inside that routine only. |
| `--trace` | `aowli-interp` | Renders the whole call tree: `→ callee(args) :LINE` on enter, `← <ret>` on exit, depth-indented. |
| `--trace-depth:N` | `aowli-interp` | Caps the call tree at depth `N` — use on a *deep* call chain where the full tree is too long to read. |
| `--trace-profile` | `aowli-interp` | Aggregates call counts/time instead of printing every frame — use on a *wide* program (many calls, shallow tree) where a full trace would be mostly repetition. |

All of `--break`/`--break-func` can repeat and combine in one invocation; every
hit is captured, not just the first (non-interactive — there is no
pause/resume/step).

## `--break` vs `--break-func`

A line number is not a unique coordinate across a whole program — the same
line number exists in every module. `--break:LINE` breaks on *that line in
whichever routine reaches it*, so a common line number (a helper's return
statement, a loop increment) can fire hundreds of times across unrelated
routines. `--break-func:NAME` scopes capture to one routine's own statements,
which is almost always what you actually want when chasing a bug you've
already localized to a function. See
[Debugging a real bug](debugging-a-real-bug) for a real instance of `--break`
firing 271 times as noise before `--break-func` isolated the actual frame.

## Reading a capture

Each hit is one block: source line + enclosing routine + `name = value` per
local, taken at statement **entry** — a line shows the value *before* that
statement runs. Break on the following line to see a post-assignment value.

## Choosing a mode

| Situation | Use |
|---|---|
| Know roughly where the bug is, want every local at that point | `--break-func:NAME` |
| Want to see the shape of execution (what called what) | `--trace` |
| Call tree is very deep and unreadable | `--trace-depth:N` |
| Program is wide (many shallow calls) rather than deep | `--trace-profile` |
| Only have a line number, no routine name yet | `--break:LINE`, expect noise, then narrow to `--break-func` |

## Via aowlcode

The `trace`/`debug` MCP tools wrap this exact binary pipeline (compile → locate
`.s.aif` → run `aowli-interp`/`aowli-dbg`) with structured JSON returns and
binary resolution through `$AOWLI_BIN_DIR` → `~/.aowl/bin` → `~/aowli/bin` →
`PATH`. Full args/returns/failure-mode reference:
[aowlcode → Execution](../docs/aowlcode/execution).
