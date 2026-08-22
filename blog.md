# Blog

Development updates from the aoughwl toolchain. Newest first.

[[toc]]

---

## 2026-08-22 — aowlspt: a live inspector for a client that cannot be asked what it is

*Saturday, August 22, 2026*

Client-side work on [aowlspt](/docs/aowlspt) was slow, and the reason was not
that the problems were hard. The reason was the loop. Asking the running game
one question cost an edit, a rebuild, a deploy, a launch, and roughly 90 seconds
to reach the menu — and at the end of it you learned exactly **one** thing: the
thing somebody had predicted in advance by writing a log line for it. If the
answer wasn't in a line written beforehand, nothing was learned, and the whole
cost was paid again.

The build numbers are the smaller half of that. A full build is **18m25s cold,
4m27s warm**; naming the single target you actually changed (`aowl build host`)
is **48 seconds** — 23x. The bigger half was the launch and the human sitting in
front of it. The loop is now about **2.5 minutes**, and none of it is a person's
attention.

### Why this target makes it hard

Post-1.0 Tarkov is IL2CPP, and on this build **reflection is dead**.
`il2cpp_object_get_class`, `il2cpp_class_get_name`, `il2cpp_value_box` and field
iteration all fault. You cannot ask an object what it is. What works is a short
list: raw field reads and writes at static offsets, direct calls at a static
RVA, and `il2cpp_string_new`.

That single constraint shapes the whole design. There is no object browser to
write, because there is nothing to enumerate. What you can build is a pointer
walker with a very good safety story, and a vocabulary for moving between
objects without ever asking a name.

### Nothing new that can fail

The command channel is a **file** next to the DLL, `aowlspt-inspect.txt`, polled
by the host's existing tick loop. Answers land in `aowlspt-inspect-out.txt` and
in the host log. No new socket, no new thread, no port to collide with, nothing
left listening. A file is also the only channel that is scriptable from a shell
with no UI — which is the real working situation here: a human at the keyboard of
the game, an agent driving it from outside.

Execution has to be on Unity's **main thread**, because managed access is. It
gets there by **riding an existing detour** on `EFT.UI.PreloaderUI::Update` — the
same one the F3 overlay and the menu-label feature use — by aliasing its slot.
Two detours on one function is a bug, not a pattern: the second overwrites the
first's trampoline. So there is exactly one detour, and the dispatcher calls
every rider whose slot matches.

The grammar is small enough to hold in your head:

```
read/write EXPR TYPE     i8..i64 u8..u64 f32 f64 ptr bool str klass
parent EXPR [N]   children EXPR   tree EXPR [DEPTH]   find NAME [ROOT]
component EXPR TypeName   rect EXPR   label EXPR   fields EXPR [N]
call TARGET SIG [ARGS]    click EXPR / invoke EXPR    allow write
let NAME EXPR   wait N   until EXPR [FRAMES]
EXPR = $anchor | 0xhex ( +0xNN | @0xNN )*   '+' moves, '@' DEREFERENCES
```

`+` is pointer arithmetic, `@` is a dereference, and every `@` is a place the
process can die.

### The safety discipline

This is the part that is actually engineering.

- **Every hop goes through a readability guard.** Never a faulting dereference
  used as a probe — you check, then you read.
- **A breadcrumb is written before every dereference**, so when a fault *is*
  caught the report names the **last hop attempted** and the pointer it was
  given. "It crashed somewhere" is not a diagnostic.
- **One SEH guard per command**, never nested — the guard is not re-entrant — and
  per *command* rather than per *batch*, so a bad address on line 3 does not take
  lines 4 through 20 with it.
- Every loop capped, every output capped.
- Writes need **two** switches: a host flag *and* an `allow write` line in the
  batch itself.
- It self-disables after N faults.

### What it cannot do

It cannot **name a type**. `klass` reports the raw `Il2CppClass*` and nothing
else. Two objects with the same klass pointer are the same type — which is
genuinely useful — but *which* type has to come from offline metadata.

It cannot **enumerate fields**. `fields` classifies each 8-byte slot by what the
bytes look like, and it says, in its own output, that it is guessing.

Both limits are printed rather than smoothed over, for reasons the last section
is about.

### What it found

Each of these used to cost a full rebuild cycle to learn.

**EFT's buttons are not Buttons.** They are `DefaultUIButton`, which is not a
`UnityEngine.UI.Button`. Proven live rather than assumed: `GetComponent("Button")`
and `GetComponent("Selectable")` both return NULL on one, while
`GetComponent("MonoBehaviour")` returns it — and the same probe confirms Unity's
string overload *does* match base type names, so the NULLs mean what they look
like. Its real click event is `OnClick`, a UnityEvent at **+0x120**. At **+0x100**
sits `_iconContainer`, a GameObject — and +0x100 is exactly the slot
`UnityEngine.UI.Button` uses for `m_OnClick`. A Button-shaped "invoke" therefore
calls `UnityEvent::Invoke` on a GameObject, and the batch leaves through its
guard.

**A false positive you can hear.** Calling `ButtonFeedback::OnPointerClick`
**plays the click sound** and does nothing else. Audible, immediate, and
indistinguishable from a successful press.

**The names lie.** The UI slot named `CharacterSlotView_pvp` is labelled
**"PvE"**. If you are selecting things by object name you are selecting the wrong
thing; you have to read the text a player actually sees.

**A caught fault is not free.** The guard keeps the game alive, but it unwinds
the *whole* guarded body — statements after the faulting call never run. A
settings page cloned itself on every visit because a `renderedFor` assignment two
statements past a fault never executed. From a later read, "did not persist" and
"never executed" look identical. A log line placed immediately after the
statement tells them apart in one build.

### The bugs in the instrument were all the same bug

The inspector's own defects were found by using it, and every one was the same
species: **a confidently wrong answer**.

A failed `component` lookup left the *previous* batch's pointer bound. The next
command duly pressed the wrong object and printed a complete, coherent, entirely
fictional field map of a Button that does not exist. Nothing about the output
looked wrong.

`label` on a Transform answered `text = ""`. That reads as "the label is empty."
It is not an answer at all — it is a lookup that did not apply, formatted as a
measurement.

The fix in both cases was the same, and it is the thesis of the whole exercise:
**refuse, and say why.** A failed lookup unbinds the anchor rather than leaving a
stale one. Feeding a GameObject to a walker that wants a Transform is now
*refused* — it used to fault, and worse, could read a plausible `childCount` and
invent a hierarchy of wrong children without faulting at all. `find` reports
whether it `searched EXHAUSTIVELY` or `STOPPED EARLY`, because "not found" and
"ran out of budget" are different facts. `state` explains *why* an anchor is null
instead of printing null and leaving you to guess.

For an instrument, a crash is a bad afternoon; a wrong answer delivered plausibly
is a wrong model of the system that you then build on for a week. Most of the
engineering here is not in the reads. It is in making every failure path announce
itself.

### Where it led

Once the client can be asked questions cheaply, it can be *driven* cheaply. The
same channel now takes the game from a cold launch to the main menu with no human
present — and selects a game mode by the text a player sees on the slot, rather
than by the object name, because we know from the inspector that the object name
is lying.

More on the constraints this lives under in
[Reaching into IL2CPP](/docs/aowlspt/il2cpp) and
[Architecture](/docs/aowlspt/architecture).

---

## 2026-08-01 — aowlcode: verdicts that rested on nothing

*Saturday, August 1, 2026*

One question applied across [aowlcode](/docs/aowlcode): what is each tool's
verdict actually resting on? Every row below reported success, or a clean
comparison, for work that had not happened.

### False successes

| Tool | Reported | Actual | Fix |
|---|---|---|---|
| `compile` | `ok:true`, `diagnostics:[]` | `nimony c --bogus-flag f.nim` prints 63 usage lines and **exits 0**, compiling nothing — no `Error:`, no crash marker, no artifact | usage banner is a failure spelling, alongside `undefined reference`/`collect2:`/`[Bug] `; diagnostic names `extra_args` |
| `explain_failure` | `OK (nimony): compiles clean` | any failing compile with no recognised `Error`, timeouts included (`if ok or errors.len == 0`) | verdict derives from `ok`; the no-diagnostic case says so and names the timeout |
| `compile` | empty `diagnostics` | unparsed toolchain output was dropped entirely; `raw:true` shows the invocation, never the output | `unparsed_output`: last 12 lines when the parser matched nothing |
| `nif_run` | `identical:true` | both variants **crashed** (rc=1, 21B stdout); the guard only covered a *silent* reference | warns when variants agree on a failure or a timeout |
| `trace_diff` | `behavior preserved at trace granularity` | **neither** run produced a trace — equal because both empty; exit codes reported but excluded from the verdict | exit status folded into `identical`; empty-trace and identical-failure warnings; `exit_diff` for status-only divergence |
| `bisect` | `minimal` set | a killed run satisfies `exit_nonzero`, so timed-out subsets were recorded as reproducing unobserved | `timed_out_runs` + warning naming the predicate |
| `shrink` | `minimal_source` | 200-compile cap hit mid-search returned a partially reduced file | `truncated` + `next_steps`; wall-clock `budget` |
| `parity.py` | `0 cases, 0 divergent`, exit 0 | filter matched no case | names the unmatched filter, exits 2 |

### Unbounded calls

ddmin is O(n²) runs, so `bisect`'s per-run `timeout` bounded nothing (20 toggles
× 120s = 40+ min, past the client's silence budget → call abandoned, every run
wasted). Total `budget` added: 600s, capped at 900, returning the reached subset
with `budget_exhausted`. Same for `shrink`. `nimsuggest --stdin` (behind
`symbols`/`outline`/`defs_uses`), `nimble path` and `doctor`'s `--version` probe
ran unbounded in the Nimony server while `server.py` had bounded all three —
nimsuggest does not exit on a file it cannot parse, it waits.

### Binary identity

`build.sh` overwrites `bin/server` in place: the running process keeps a
deleted inode, at a path whose contents are now someone else's, under a matching
version. Server records its binary mtime at startup → `doctor.server_stale` +
session-banner warning. `launch.sh` no longer serves stale by design —
`AOWLCODE_BUILD_WAIT` (default 25s, `0` = old behaviour) lets a rebuild finish
first.

**aowli binaries already hot-swap.** Replacing `~/.aowl/bin/aowli-interp` or
`aowli-dbg` takes effect on the next call — path resolved per call, aowli output
never cached (the trace cache key names a nimcache dir for the nimony-built
`.s.nif`). Verified by swapping under a live server. Added: `doctor versions:true`
identifies the live build (`aowli-dbg` via `--version` build id, `aowli-interp`
via size+mtime, having none), and a paused `debug_session` — an already-running
process of the old build — reports `binary_swapped`.

Also fixed: `nif_run` copied only `*.s.nif`, leaving `.idx.nif` VFS indexes
behind, so a module with sibling nimcache deps died on
`vfs: open failed: …/<n>.s.idx.nif` — its stated purpose. Verified against
`~/aowlsem/nimcache` (43 index files).

### False failures

nimony builds through a shared `nimcache_static` regardless of project; two
concurrent compiles overwrite each other's objects → `undefined reference` /
`collect2: error`. Two spurious failures in one day, each costing a re-run to
disbelieve. All nimony invocations (both servers, `build.sh`, test scripts) now
serialise through one `flock`. Serialise, not isolate: a unique `--nimcache:`
per call discards cache reuse and does not cover `nimcache_static` anyway.
Measured: same lock → wall 2.0s; different lock paths → 1.1s.

### Gate blind spots

The differential harness compared tool **names**, so both servers could
advertise the same 26 tools with different contracts — 6 of 26 did. Fixing that
exposed wrong `required` sets on 3 (`nif_file` demanded while `file` is a
documented alias), and fixing that exposed a missing `action` enum on
`debug_session`, leaving its 18 actions undiscoverable from the server that
serves them. Remaining py/nim gaps are an enumerated allow-list; unlisted
divergence fails.

`precompact-nudge` had **never worked**: `hookSpecificOutput` is rejected on
`PreCompact`, so every compaction printed a validation error and discarded the
reminder. Now `systemMessage`. `launch.sh` itself had no test — one stray echo
corrupts the JSON-RPC stream for a whole session; covered now, along with all 8
registered hooks driven from `hooks.json`.

Gates: 197 curated + 116 sweep differential cases, 107 unit checks, 39
end-to-end checks.

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

> **Correction, 2026-09-09.** The "498/498" corpus figure in this post and the
> one below was never a module count — it was a census of `hconv` sites from
> aowlsem's `REQUIREMENTS.md`, mis-read as a corpus score — and `std/system` was
> not byte-exact. The posts are left as written; the dated, measured numbers are
> on the [aowlsem page](/docs/aowlsem#measured-status).

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
