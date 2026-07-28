# Blog

Development updates from the aoughwl toolchain. Newest first.

[[toc]]

---

## 2026-07-28 — aowli: debugging a big program stopped meaning "recompile it every time"

*Tuesday, July 28, 2026*

Pointing the [aowli](/aowli) debugger at a large program — the semantic checker
[aowlsem](/docs/aowlsem) itself — used to take minutes per run, and it was easy to
conclude the interpreter was simply slow on a program that size. It wasn't. The
interpret is about a second; the minutes were the tooling **recompiling the whole
program from scratch before every run**, then throwing the build away.

### The cost was the compile, not the interpret

The [aowlcode](/docs/aowlcode) `debug` and `trace` tools compiled the target into a
fresh throwaway build directory with `-f` (force a full rebuild) on *every* call.
For aowlsem — its ~20k-line self-hosted compiler plus all of the standard library
it imports — that cold build is ~47 seconds, paid again on every step of a
debugging session.

The fix you reach for first is "use a persistent build cache so it rebuilds
incrementally." We measured it: it doesn't help here. A warm rebuild into the same
cache, with nothing changed, costs the **same ~47 seconds** — the toolchain has no
fast incremental path for this shape yet. So the real fix is to **not run the
compiler at all when nothing changed**: keep the built `.s.nif` and reuse it,
recompiling only when a source file under the project is actually edited. The first
debug of a session is cold (~47s); every one after is **~1 second**, until you
change code. You can also hand the tools a prebuilt `.s.nif` directly and skip the
compile entirely.

### aowli v0.3.3 — hybrid mode crosses richer data

[aowli v0.3.3](https://github.com/aoughwl/aowli-release/releases/tag/v0.3.3) extends
the interpreter's optional **hybrid-native** mode, which runs the modules you are
*not* debugging as real compiled code at full speed while interpreting the one you
are. Until now only simple signatures (numbers, PODs, strings, flat seqs) could
cross that boundary. A new shared-memory **arena** lays a live value graph out in
real native memory layout, so calls taking `ref` objects, nested ref graphs, and
`seq[T]` fields (including seqs of objects) cross too — the native side reads and
mutates the same memory, and the changes are reflected back into the interpreter's
values.

It is additive and dormant: without the hybrid flag, execution is byte-for-byte
identical to v0.3.2, and anything that still can't be marshalled safely falls back
to plain interpretation rather than risk a wrong answer.

---

## 2026-07-28 — aowlsem: generic ref objects reach byte-identity, and value-object method dispatch

*Tuesday, July 28, 2026*

[aowlsem](/docs/aowlsem) — the from-scratch semantic checker that replaces the
reference compiler's `nimsem` — spent the day closing real gaps against the
reference's own typed output. The method is deliberately low-tech: write a small,
*valid* program that exercises one language feature, run both checkers, and diff
the results token-for-token. Every difference is either a bug to fix or a
deliberate lowering choice to record. It is now **~20.8k lines** of self-hosted
Nimony across **700 commits**, with the byte-exact differential corpus holding at
**498/498** modules and `std/system` checking clean.

### Generic `ref object` — the last mile to byte-identical

Yesterday these instantiated *structurally*; today they match the reference
**byte for byte**. Three residual differences fell:

- **Construction emits a heap allocation, not a value.** `Container[int](items: …)`
  now lowers to `(newobj (ref Container.Obj … ) …)` — a real `ref` allocation —
  instead of a stack `oconstr` of the value half.
- **Per-instance lifetime hooks carry no module suffix.** A generic instance is
  content-addressed already (its hash makes it globally unique), so its synthesized
  `=destroy`/`=copy`/… names must *not* also bake in the defining module — an
  inconsistency that also kept the comparison from folding the hash.
- **Typevar numbering.** The underlying object half now numbers its type parameter
  `T.1` (the alias took `T.0`), matching how the reference counts a `ref object`'s
  two synthesized declarations.

### Value objects that carry methods

The standout fix. An inheritable object with managed fields that *also* declares
`method`s — `type Animal = object of RootObj … method sound(a: Animal)` — was
getting the full four-hook lifetime-pragma form. The reference emits **only** the
user-method vtable table: a type with a real vtable routes its own destruction
through the vtable's destroy slot (filled in a later pass), so the checker lists
just the methods. The discriminator turned out to be the *presence of a user
method*, not inheritability — an identical object with no method still gets its
hooks. A common polymorphism pattern, now byte-identical.

### And a run of smaller parity fixes

- **Generic variants resolve their branch fields.** `o.val` inside a generic
  `unwrap[T](r: Result[T])` now finds the named-variant branch field instead of
  emitting a bare, unmangled name.
- **`{.borrow.}` operators that return a distinct type** convert their result back:
  `+`(Celsius, Celsius) computes in `float` and wraps the answer in `(dconv Celsius …)`.
- **`untyped`/`typed` template parameters are wildcards** — a `template twice(x: untyped)`
  now *inlines* at the call site instead of emitting a spurious call to the template.
- **Bool `case` labels** emit the literal `(true)`/`(false)` tags rather than
  resolving to the bool enum's member symbols.

Earlier in the day the same grind landed lambdas/anonymous procs as expressions,
cross-scope iterator resolution (so a local variable named like an iterator no
longer hides it), custom `[]`/`[]=`/`{}`/`contains` operators, multi-index
`x[i, j]` read and write (two assertion crashes fixed), and a batch of
cross-module import-resolution fixes in the driver. Throughout, the three
regression gates stayed green: **498/498** corpus, **64/64** diagnostics, and
`std/system` within its expected seven-line window.

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
