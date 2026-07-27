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
| `--expand:PATH[,…]` | `aowli-dbg` | Drill into a **deep field** of a captured local without dumping the whole value — dotted/indexed paths like `c.currentModule.name` or `xs.3.field` (fields by name, seq/array by index, `ref`/`ptr` auto-followed), each rendered with a generous budget as an extra `path = value` line. |
| `--session` | `aowli-dbg` | **Interactive / progressive mode** — run once and pause, stepping and inspecting the live frame on demand over a stdin/stdout control channel (see below). |
| `--trace` | `aowli-interp` | Renders the whole call tree: `→ callee(args) :LINE` on enter, `← <ret>` on exit, depth-indented. |
| `--trace-depth:N` | `aowli-interp` | Caps the call tree at depth `N` — use on a *deep* call chain where the full tree is too long to read. |
| `--trace-profile` | `aowli-interp` | Aggregates call counts/time instead of printing every frame — use on a *wide* program (many calls, shallow tree) where a full trace would be mostly repetition. |

All of `--break`/`--break-func` can repeat and combine in one invocation. In the
default **batch** mode every hit is captured (not just the first) and dumped at
exit; for pause/step/resume, use `--session` (below).

## Bounded value rendering

Every captured value is rendered under a whole-value **character budget**, so a
large frame local — a compiler's `SemContext`, a memo table, a grammar blob —
can no longer explode a frame dump into a wall of interning-table internals. When
the budget runs out, expansion stops with a `…{budget}` marker: the value's shape
stays legible and you know detail was *deferred*, not missing. To see a deferred
field, name it directly with **`--expand:PATH`** (or the `expand` command in a
session) rather than re-dumping the whole value — token-thrift without losing the
thread.

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

## Interactive / progressive mode (`--session`)

Batch mode re-runs the *whole* program every time you want to look somewhere new,
so you must decide up front what to capture — and a slow program (an `aowlsem`
compile) pays that full re-run on every inspection. **`--session`** turns
`aowli-dbg` into a co-process instead: it runs **once** and **stays paused between
commands**, so you inspect and step the *live* frame on demand — no re-execution,
no predicting captures in advance.

The interpreter emits **JSON events** on stdout (`paused`, `output`, `expanded`,
`locals`, `stack`, `exited`) and reads **plain line commands** on stdin:

| Command | Effect |
|---|---|
| `step` | Step **into** the next statement (descends into calls). |
| `next` | Step **over** — stay in this frame; skip into called routines. |
| `finish` | Step **out** — run until the current routine returns. |
| `continue` | Run to the next breakpoint (or exit). |
| `break func:NAME` · `break file.nim:LINE` · `break LINE` | Add a breakpoint **live**, mid-session. |
| `clear` | Remove all breakpoints. |
| `expand PATH[,…]` | Drill dotted/indexed paths in the paused frame (stays paused). |
| `locals` · `stack` | Re-inspect the paused frame's locals / routine-name call stack. |
| `quit` | End the session. |

The session stops on entry, then you set the pace. It needs no coroutine
machinery: the interpreter is already parked on the stack inside its
per-statement hook, so a blocking read on the control channel *is* the pause.
Batch mode and the zero-overhead default path are byte-for-byte unchanged. Via
[aowlcode](../docs/aowlcode/execution), this is the **`debug_session`** tool.

## Via aowlcode

The `trace`/`debug`/`debug_session` MCP tools wrap this exact binary pipeline
(compile → locate `.s.aif` → run `aowli-interp`/`aowli-dbg`) with structured JSON
returns and binary resolution through `$AOWLI_BIN_DIR` → `~/.aowl/bin` →
`~/aowli/bin` → `PATH`. Full args/returns/failure-mode reference:
[aowlcode → Execution](../docs/aowlcode/execution).
