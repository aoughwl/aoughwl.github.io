# Blog

Development updates from the aoughwl toolchain. Newest first.

[[toc]]

---

## 2026-07-27 — A progressive debugger for aowli

*Monday, July 27, 2026*

Debugging a real, compiler-grade program under [aowli](/aowli) — the point where
its `debug`/`trace` tools stop being toys and start earning their keep — turned
up three sharp edges this week. All three are now fixed, and the debugger picked
up a genuinely new capability along the way: **interactive, progressive
stepping**.

### The 15,000-token wall

Dumping a single frame local from the semantic checker — a `SemContext`, a wide
object whose fields are themselves wide tables — produced a **~15,000-token wall**
of interning-table internals. The renderer already capped each node (long strings
elided, wide aggregates truncated, depth bounded), but nothing capped the
**total**: a wide object of wide objects multiplies out to thousands of tiny
nodes within the depth limit.

The fix is a whole-value **character budget** threaded through the renderer. Every
leaf debits it; when it runs out, expansion stops with a `…{budget}` marker — so
the output is a constant size no matter the value's shape, and you can always tell
detail was deferred rather than missing.

### Drilling in without dumping everything

Budgeting the dump raised the obvious question: what if the one field you need got
elided? So the debugger learned **path-addressable expansion** —
`expand c.currentModule.name`, `expand xs.3.field` — navigating object fields by
name and seq/array elements by index (following `ref`/`ptr` transparently),
rendering just that sub-value with a generous budget. Read the shape from the
budgeted dump, then drill the exact path. Token-thrift without losing the thread.

### Progressive debugging — run once, step, inspect

The batch model re-ran the *whole* program on every command, so you had to decide
up front what to capture, and a slow program (an `aowlsem` compile) paid that cost
on every look. The new `--session` mode makes `aowli-dbg` a **co-process**: it
runs once and **stays paused between commands**, inspecting and stepping the live
frame on demand.

- **Step** into / **next** over / **finish** out, with correct call-frame-depth
  semantics; stop-on-entry, then you set the pace.
- **Set breakpoints live** while paused — look around, break deeper, continue to
  it — and `clear` them.
- **`expand`** any path, **`locals`**, **`stack`**, all against the paused frame,
  with no re-execution.

It didn't need coroutine gymnastics: the interpreter is already parked on the
stack inside the per-statement hook, so a blocking read on the control channel
*is* the pause. JSON events flow out on stdout, line commands in on stdin. Batch
mode and the zero-overhead default path are byte-for-byte unchanged.

### And the reason a rebuild "did nothing"

One last papercut: rebuilding the debugger binary sometimes appeared to do
nothing. The tool resolves `~/.aowl/bin` *before* the dev build directory, so a
stale copy there **shadowed** every rebuild. The build now stamps a version into
the binary (`aowli-dbg --version`) and installs to every resolved location at
once, so a rebuild can never be shadowed again.

All of this is exposed through [aowlcode](/docs/aowlcode)'s `debug` and new
`debug_session` tools — see [Debugging](/aowli/debugging) and
[aowlcode → Execution](/docs/aowlcode/execution).
