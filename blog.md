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

### What the debugger was for: generics that instantiate

The reason the debugger earned this much attention is the program it debugs:
[aowlsem](/docs/aowlsem), the semantic checker. Today that program crossed a real
line — generic *types* now instantiate the way the reference compiler does, all
the way into the cases that were still emitting the un-specialized generic and
cascading into unresolved field accesses and 25-way operator sets downstream.

**Generic sum types construct by inference.** `let d = Some(99)` now works out
`Option[int]` from its argument, so `d.val` is an `int` and `d.val == 99`
resolves to a single integer comparison instead of a giant overload choice. The
same inference drives annotated conversions (`Option[int](x)`) and two-parameter
sums (`Either[int, string]`), and a plain generic object picks its instance from
its fields too — `Pair(first: 1, second: 2)` becomes `Pair[int]`.

**Generic `ref object` types instantiate in full.** This was the deep one. A
`ref object` isn't one type — it lowers to a *reference alias* plus the
underlying object it points at, and each half carries its own set of lifetime
hooks (destroy / move / copy) so values clean themselves up correctly. A generic
one like a recursive

```nim
type Tree[T] = ref object
  case
  of Leaf: val: T
  of Branch: left, right: Tree[T]
```

was never being instantiated at all — it fell out of the generic machinery early
and emitted the un-specialized origin at every use. Now `Tree[int]` mints both
halves with their own separately-keyed identities and per-instance hooks, its
`Branch(…)` / `Leaf(…)` constructors build the concrete instance, and an
annotated `let t: Tree[int] = Branch(…)` heap-allocates against the right type
instead of tripping a type-mismatch.

Every one of these was root-caused by pointing the interpreter's debugger at
aowlsem's own output and diffing against a native compile — the loop the
interactive-stepping work above exists to make cheap. Throughout, the byte-exact
differential corpus held green at **498/498** with full `std/system` parity, so
the generics work landed without regressing anything already passing.
