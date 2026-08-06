# aoughwl compiler fixes

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

Compiler fixes that went into [`aoughwl/nimony`](https://github.com/aoughwl/nimony)
(branch `master`). Each is written against the Nim language and portable to
[`nim-lang/nimony`](https://github.com/nim-lang/nimony). Each entry records a bug
fixed or feature added, and why.

- TOC

---

## Fixes

### Reject capturing a `var`/`out` parameter in a closure (memory safety)

*Commit `8878ac65`.*

**What.** Implements a memory-safety check Araq left as an in-code `# XXX` in
`src/hexer/lambdalifting.nim`: *"Check here for memory safety violations: Cannot
capture a `var T` parameter."*

**Why.** A `var T` / `out T` parameter aliases the **caller's** storage. When a
closure captures it, the parameter is stored into the closure's environment
object (`env.<field> = param`); if that environment outlives the call, the field
dangles — a use-after-return. Nimony's sem rejects the common cases, but the
lowering pass that actually builds the environment had no backstop.

**Fix.** In `treParams`, at the point a captured parameter is written into the
env, check the parameter's type: if it is `MutT`/`OutT`, raise
`cannot capture 'var'/'out' parameter '…' in a closure: its storage belongs to
the caller`. The guard's blast radius is exactly the var/out-param-capture path
(which is unsafe anyway), so `tests/nimony/{closures,casestmt,object}` stay
green.

### `mover`: point the "other usage" diagnostic at the real use site

*Commit `6fe69882`.*

Two of Araq's `# XXX Fixme: pc advanced to ')'` markers in `src/hexer/mover.nim`.
`containsRoot(pc, x)` takes `pc` as a `var Cursor` and advances it while scanning,
so `otherUsage = pc` afterwards recorded the position *after* the matched subtree
(the closing `)`), not the actual read. Capture `usageAt = pc` before the call.
Diagnostic-position only — move decisions are unchanged; `tests/nimony/lastuse`
(the mover's own suite) stays green.

**Status of the remaining hexer markers (all read, some coded + test-gated).** We audited and *attempted* all nine of
Araq's in-code recommendations (reading each implementation). Three sites are
implemented above (the var/out capture check + both mover Fixmes). The remaining
five are invasive changes to correctness-critical codegen where the current
behaviour is verified correct: `desugar` set-element offset (a *coordinated*
change — bitset sizing plus every `in`/`incl`/`excl` index site; a partial edit
breaks sets); `lifter`/`lengcgen` case-object `=copy` (deep ARC-hook / union
codegen — variant copies already correct); `duplifier` prefer-`=copy` (an
ARC-semantics change, marginal codegen-cleanliness); `mover` innermost-scope CF
build (a cached-analysis restructuring, negligible since lowering is already ~40×
faster than the C compile it feeds). These are Araq's deliberate deferred
optimizations; landing them would require ARC-hook expertise *and* a reliable
regression gate — which the shared test harness cannot currently provide (a
concurrent `nimcache_static/static.o` clobber that `hastur.nim` itself documents,
plus pre-existing `install.nim` breakage on `combined-prs`). Sharper findings after building an isolated toolchain (the fork's own
`nimcache_static`, immune to the parallel-session clobber) and *coding* the
attempts: **`duplifier` `=copy`** — implemented and run through the ARC gate; it
produced a gcc type-mismatch and a runtime `[Assertion Failure] moved?!`, so the
naive `=copy` substitution is genuinely wrong (it also perturbs nested hook
generation) — reverted. **`desugar` set-offset** — *not* a TODO to implement:
`expreval.bitsetSizeInBytes` documents "*we don't use an offset != 0 anymore for
set construction*", so offsetting was **deliberately removed**; implementing it
would reverse that decision. **`lifter`/`lengcgen` case-object** — these are
sophisticated *working* implementations (variant→union plus a `(variant
(ranges…))` debug pragma, issue #2068); the "counts each field separately" note
is a vague refinement on correct code, not a missing feature. So beyond the three
sites landed above, the markers are not implementable recommendations.

### Init-check diagnostic names `result`, not the mangled `result.0`

*Commit `9f15ac4d`.*

**Symptom.** A proc that can leave `result` (or an `out` parameter)
uninitialized reports, e.g.:

```
cannot prove that result.0 has been initialized [pass --verbose for the NJ IR]
```

The trailing `.0` reads exactly like a **tuple field index** — so on a
tuple-typed `result` (`proc f(): tuple[a, b: int]`), users reasonably conclude
the compiler is pointing at field 0, and go hunting for a per-field
initialization problem that isn't there.

**Root cause.** The definite-initialization checker
(`src/nimony/contracts_fir.nim`) built its message from `pool.syms[symId]` —
the raw *mangled* local symbol name. A local's mangled form is
`name.<disambiguator>` (the same scheme that names a proc `g.0.<modulehash>`),
so a plain `result` serializes as `result.0`. The `.0` is a name-mangling
artifact, never a field index — the `tupat` field stores in the NJ IR are a
separate thing entirely.

**Fix.** Add `userSymName`, which strips the disambiguator via
`splitLocalSymName` (`result.0` → `result`, `x.14` → `x`), and route the three
`cannot prove that … has been initialized` messages through it. Purely a
diagnostic-text change — no analysis behaviour is affected.

**Verified.** Rebuilt `nimsem`; the message now reads `cannot prove that
result has been initialized` for both tuple and scalar results and for
used-before-init locals, and a valid program still compiles and runs. (Note: a
separate, deeper limitation remains — the checker does not track *per-field*
initialization, so `result.a = 1; result.b = 2` is still rejected in favour of a
whole `result = (…)`; that is analysis behaviour, not message text, and is left
for a future change.)

### Control-flow no longer descends into stored macro bodies

*Commit `6b80fc99`.*

**Symptom.** Importing a module that defines a `macro` whose body contains a
**nested recursive helper proc**, and using that macro from another module,
crashed the compiler:

```
typenav.nim(622,3) `n.kind == SymbolDef` expected SymbolDef, got: <helper>
[AssertionDefect]
```

This blocked, for example, a small `ingest:` block macro (whose body carried a
nested recursive tree→source unparser) from living in a reusable library instead
of being copy-pasted into every call site.

**Root cause.** `src/nimony/controlflow.nim`'s `trStmt` routed `MacroS` through
the same branch as `ProcS`/`FuncS` (`trProc`). When later move / last-use
analysis (`src/hexer/mover.nim` `isLastUse`, which builds a control-flow graph
over the whole module buffer) reached a stored macro, the CF walk descended into
the macro's body and called `takeRoutineHeader` on its **nested** proc. Stored
macro bodies encode nested routine names as plain **Symbol uses, not
`SymbolDef`s** (in the `.s.nif`, `(proc name@…` — no leading `:` — versus a real
definition's `(proc :name…`), so the `SymbolDef` assertion in `typenav.nim:622`
fired. Templates were already skipped in the adjacent branch; macros were not.
The duplifier already treats macros opaquely, confirming the CF descent was the
anomaly.

**Fix.** Remove `MacroS` from the `trProc` branch and skip it alongside
`TemplateS` in `controlflow.nim`'s `trStmt`. A macro's body is not ordinary
control flow to be walked for move analysis.

**Verified.** Minimal cross-module and same-file repros compile and run; the
`macros` test suite passes 6/6; and a macro-with-nested-recursive-helper now
works as an imported library.

### Nested `case`-in-`case` objects no longer crash construction

*Commit `efd5adc6`.*

**Symptom.** A variant object with a `case` branch whose body itself holds
another `case` crashed the compiler while building an object constructor:

```
nifcursors.nim(149,3) `c.p != nil and c.rem > 0` [AssertionDefect]
```

Minimal repro:

```nim
type
  Outer = object
    case a: bool
    of true:
      case b: bool
      of true: x: int
      of false: y: int
    of false: z: int
var o = Outer(a: true, b: true, x: 1)
```

**Root cause.** In `src/nimony/sem.nim`, a variant branch body is either a bare
field or, when it holds more than one member, a `(stmts …)` list. The
object-constructor default-fill path assumed the list contained only fields:
`fieldsPresentInInitExpr` (the scan deciding which branch a set field belongs to)
and the field-emit loops in `fieldsPresentInBranch` called `takeLocal` on every
list item. A nested `(case …)` node is not a local, so `takeLocal` returned a
`Local` with an unset `name` cursor, and the following `name.symId` load tripped
the `load` assertion at `nifcursors.nim:149`.

**Fix.** Intercept `case` nodes in both the scan and the emit loops and recurse.
`caseHasSetField` scans a nested case's discriminator and every branch body for a
set field; `emitNestedCase` re-enters the standard selector + `fieldsPresentInBranch`
path for the nested variant. The recursion is depth-independent, so it also
covers three-or-more-level nesting, variants inside a `ref object`, and branches
carrying managed (`string`/`seq`/`ref`) fields.

**Verified.** The repro and a battery of variants (default-fill of an inner
branch, the other outer branch, triple nesting, ref-wrapped, and a managed-string
branch) all compile and emit the expected constructor; `tests/nimony/object`
(20 cases) and `tests/nimony/casestmt` (4 cases) stay green.

### `syncio.readLine` corrupted every line longer than 79 characters

*Commit [`b7ba4975`](https://github.com/aoughwl/nimony/commit/b7ba4975).*

**What.** `addReadLine` in `lib/std/syncio.nim` reads a line in 80-byte chunks
via C `fgets`. `fgets` stores at most `bufsize - 1` characters and *always*
NUL-terminates, so the NUL marks the end of **that chunk**, not the end of the
line. The copy loop ran the full `bufsize` and appended the terminator as if it
were data:

```nim
for i in 0 ..< bufsize:
  if buf[i] == '\n':
    done = true
    break
  s.add buf[i]        # copies the NUL terminator too
```

Any line past the first chunk came back with a stray `'\0'` every 79 characters
and a length inflated by one per chunk. A 224-character line read back as 226
bytes, with NULs at indices 79 and 159.

**Why it matters.** This is silent. Nothing raises, nothing truncates, and short
lines — nearly all lines in nearly all test files — are perfectly fine, so the
bug hides until a file happens to carry a long line. Every nimony program using
`readLine`, `lines`, or `readAll`-by-line on real-world text was affected.

**Fix.** Stop the copy at the NUL and let the enclosing `while` fetch the next
chunk:

```nim
if buf[i] == '\0': break
```

Verified at 5, 79, 80, 158 and 224 characters, and on a file whose last line has
no trailing newline.

**How it surfaced.** A rewrite-rule file in `aoughwl` whose rule was 224
characters long simply stopped matching. The pattern hole `?d2` had been read as
`?d\0 2`, so the rule bound a hole named `"d 2"` that nothing on the right-hand
side referenced — and a rule that matches nothing produces no error, just no
results. Worth noting as a general hazard: a corrupted *pattern* fails silently,
where corrupted *data* usually announces itself.

### `return` or `yield` outside a routine crashed the compiler

*Fixed in `src/nimony/sem.nim` (`semReturn`, `semYield`).*

**What.** Any module-level `return` — or `yield` — crashed nimsem instead of
reporting an error:

```
Error: unhandled exception: src/lib/nifcursors.nim(149, 3)
  `c.p != nil and c.rem > 0`  [AssertionDefect]
```

```nim
var x = 1
if x == 1:
  return          # crash, not a diagnostic
```

**Why.** `semReturn` *did* diagnose the case — `` `return` only allowed within a
routine`` — but then fell through to the code that type-checks the returned value
against `c.routine.returnType`. Outside a routine there is no routine record, so
that cursor is empty, and `typeKind` on an empty cursor trips the nifcursors
`load` assertion. `semRaise` next door is written as an `if/elif` chain and so
never had the problem; `semReturn` and `semYield` read the type unconditionally.

**Fix.** Treat "no enclosing routine" the way both procs already treat a
template: there is no expected type, so use `autoType` and let the error that was
already reported stand on its own. In `semReturn` the bare-`return` branch also
has to skip the `returnType.typeKind != VoidT` test, because reading it is itself
the crash.

**How it surfaced.** A differential batch for
[aowlsem](https://github.com/aoughwl/aowlsem) — hand-written invalid programs
whose ACCEPT/REJECT verdict is compared against the real driver. The crash had
been hiding as an agreement: a crash exits non-zero, so it *looked* like a
rejection, and the oracle never got far enough to reveal that aowlsem was
accepting the program. Stock Nim rejects both (`'return' not allowed here`), so
aowlsem gained the matching check (`E0279`) in the same pass.

### `sizeof` under-reported every object with an aggregate field

*Commit `c596bfc4`, `src/nimony/sizeof.nim` (`combine`).*

**What.** `sizeof` in a **constant** context lost the padding in front of an
aggregate field, so every field after it sat too low and the type came out too
small. The C backend was right, so the two disagreed silently:

```nim
type
  Sub = object
    x: int64
    y: int64
  A = object
    a: char
    b: Sub
    c: char
const cA = sizeof(A)
echo cA, " ", sizeof(A)      # was: 24 32
```

`b: string` and `b: seq[int32]` were wrong the same way. `b: ref int` was right,
and so was an aggregate as the **last** field.

**Why.** `update`, which handles a scalar field, rounds the running offset up to
the field's alignment before adding it. `combine`, which merges an aggregate
field, added `inner.size` to an unaligned `c.size`. For `A`: `char` → 1;
`Sub` (16, align 8) → `1 + 16 = 17` instead of `align(1, 8) + 16 = 24`;
`char` → 18; `finish` → `align(18, 8) = 24`. Correct is 32. That same tail
round-up in `finish` is why an aggregate in last position looked correct — it
covered the missing padding — and why the bug survived.

**Fix.** Align `c.size` to `inner.maxAlign` before adding, exactly as `update`
does. `inner.maxAlign == 0` is the `{.packed.}` sentinel and still imposes no
alignment on the container.

This was a wrong answer rather than a refusal: anything sizing a buffer from a
const `sizeof` allocated short.

**How it surfaced.** [aowlabi](aowlabi)'s layout differential, which diffs the
compiler's own numbers against an independent engine — specifically its new
32-bit tier, which reads folded `sizeof` literals out of the C emitted for
`--bits:32`. The defect turned out not to be width-specific at all. Worth
recording separately: `sizeof.nim`'s own `when isMainModule` suite does not run —
`nim c -r src/nimony/sizeof.nim` dies on its first case at
`assert n.kind == IntLit`, before and after this change — so the module carrying
this bug had no working self-test.

### A `{.closure.}` proc type in an object field was never lowered

*Commit `75da5035`, `src/hexer/lambdalifting.nim`.*

**What.** A closure-typed field did not compile at all; gcc rejected the struct:

```nim
type
  PC = proc (x: int): int {.closure.}
  H = object
    p: PC
proc main =
  var h = default(H)
main()
```

```
error: incompatible types when initializing type 'NI64 (*)(NI64)'
  using type 'struct X60Qt_0_IAtupleAiS64ZArefSX52ootX4fbj0sysvq0asl...'
```

**Why.** The field was emitted as a bare nimcall proc pointer — one word, no env
parameter — while every value of that type is the two-word `(fn, env)` tuple
lambdalifting builds. Closure proc types are lowered by `treProcType`, reached
through `treType` and `trLocal`. Object fields are `FldS`, which is not in
`LocalDecls`, so a field decl never reached that path: pass 2's `TypeS` case was
a plain `takeTree`, and pass 1's rewrote exactly one thing (an itertype alias).
The same held for a closure type inside a tuple or array element.

**Fix.** Pass 2's `TypeS` walks the body through a new `treTypeBody`, which
lowers a `{.closure.}` routine type wherever it occurs and publishes the type
when it rewrote anything, so importers see the lowered field rather than the
shape the declaring module started with. A tuple already in the lifted shape is
left alone, or its own `fn` slot would be wrapped a second time. Pass 1 sets
`hasClosures` when a type body contains such a type, because a module that only
*declares* one has none of the other signals that make pass 2 run.

`sizeof(H)` is now 16, matching the tuple — and matching what
[aowlabi](aowlabi)'s `akClosure` says a closure is.

**How it surfaced.** Adding a closure-typed row to aowlabi's layout corpus. It
also settled the layout question the row was for: `sizeof` of a `{.closure.}`
type is 16, because hexer rewrites it to the tuple before `sizeof` sees it, so
`sizeof.nim`'s one-word `RoutineTypes` arm only ever answers for `nimcall`.

### A declared object field default was silently ignored

*Commit `3f406b4d`, `src/nimony/sem.nim`.*

**What.** A field's declared default value never reached the object. Both the
constructor and `default(T)` produced the type's zero instead:

```nim
type
  K = enum kA, kB
  P = object
    labelCounter: int = 1
    kind: K

P(kind: kA).labelCounter   # nimony said 0, Nim 2 says 1
default(P).labelCounter    # nimony said 0, Nim 2 says 1
var r: P; r.labelCounter   # 0 in both — correct, defaults don't apply here
```

**Why.** Sem *records* the default on the declaration and then ignores it when
completing the constructor. Both halves are visible in the `.s.nif`:

```
(fld :labelCounter.0 . . (i 64) 1)                                   <- declared
(kv labelCounter.0 (expr .. std/system/defaults.nim (suf 0 "i64")))  <- 0 emitted
```

`buildObjConstrField` called `callDefault(typ)` unconditionally and never
consulted `field.val`. One path serves both `T(a: x)` and `default(T)`, which is
why the two symptoms are one bug.

**Fix.** Emit `field.val` when it is not a `DotToken`. It is already semchecked
at the declaration, so it splices in directly.

Not done when `bindings` is non-empty — an invoked generic type reached through
the parent/instantiation walk, whose default still mentions the type's typevars.
Substituting it with `instantiateExprIntoBuf` (the obvious move, and the first
version of this fix) re-sems into the constructor buffer and emits a tree the
post-sem phase validator walks off the end of: it SIGSEGVs in `collectChildKinds`
on `tests/nimony/converter/tgenericconverter.nim` and breaks
`tests/nimony/track/ttype_usage.nim`. Measured against a baseline run of the same
suite — 587/594 before, 585/594 with the substitution, 587/594 with the guard,
and those two were the only delta (7 pre-existing `nosystem/*` failures in every
run). The remaining gap is narrow: an ordinary `G[int](v: 3)` still takes the
splice path and honours `n: int = 5`.

**Why it mattered more than it looks.** The bug is invisible in the source and
silent at runtime — a type states its starting value, the program reads a
plausible zero, nothing warns. And it only bit **nimony-compiled** programs: the
compiler's own tools are built by Nim 2, so the same source was correct in
`bin/hexer` and wrong in any nimony port of it.

**How it surfaced.** A closure iterator run under
[aowli](https://github.com/aoughwl/nimony)'s destructor-lowering mode exited
before its first iteration. `hexer/coro_transform.nim` declares
`ProcContext.labelCounter: int = 1` precisely so an emitted coroutine label can
never collide with the hardcoded entry state 0. Inside aowli's nimony-compiled
partial hexer that default was dropped, the first yield emitted `(lab 0)`, and
the lowering grew **two procs named `once.0.s0.`** — in NIF the symbol is the
identity, so the yield's continuation resolved to the *done* state and the loop
stopped before it started. Rebuilding with the fixed compiler turns
`once.0.s0. + once.0.s0.` into `once.0.s0. + once.0.s1.`, and 0 iterations into 1.

### The shared object cache was keyed by basename, so its compile flags were not part of its identity

*Commit `4e65d2ad`.*

**What.** `nimcache_static/` holds the object files produced from `{.compile.}`
pragmas — in practice mimalloc's `static.c`. They do not depend on per-project
state, so one build compiles them and every other build on the machine reuses
the result. But the object was keyed by **basename**: a single `static.o` slot,
with nothing in its identity recording the flags it had been built with.

**Why it matters.** Whichever build ran last decided the allocator for every
other nimony program on the machine, including builds already running in another
session. A `-O0` debug build, a `--cc:clang` build and a test run injecting
`--passC:-DMI_TRACK_VALGRIND=1` all wrote the same file; two builds wanting
different flags could not coexist at all. This was already live rather than
hypothetical — `hastur`'s `prebuildSharedObjects` had to `removeFile` the slot
before a valgrind test run precisely because a plain `bin/nimony c foo.nim`
could leave a stale, untracked object there for the tests to silently reuse.

**Fix.** `sharedObjFile` (`src/nimony/deps.nim`) now names the object
`static_<digest>.o`, where the digest covers the exact `cc` invocation — driver,
`-O` level, `--passC` and `{.passC.}` flags, the `-I` project root — plus that
TU's own `{.compile.}` arguments. The `cc` flags are collected into a seq once
and used both to emit the command and to compute the key, so the two cannot
drift apart. `hastur`'s deletion workaround is removed.

### Every nimony program linked a debug-mode mimalloc, `-d:danger` included

*Same commit `4e65d2ad`; it depends on the keying fix above.*

**What.** `lib/std/system/mimalloc.nim` compiled `static.c` with
`-DMI_STATS=1 -I…` and nothing else. mimalloc's `types.h` sets `MI_DEBUG 2`
unless `MI_BUILD_RELEASE` or `NDEBUG` is defined, which turns on `MI_PADDING`,
`MI_PADDING_CHECK`, `MI_ENCODE_FREELIST` and `mi_assert_internal`. `nm` on a
shipped `-d:danger` binary showed `_mi_assert_fail`, `mi_check_padding`,
`mi_is_valid_pointer` and `mi_page_decode_padding`. Separately, `MI_STATS` is
not tested anywhere in mimalloc — the macro the library reads is `MI_STAT`, so
that `-D` defined a name nothing looks at, and the counters
`getOccupiedMem`/`getTotalMem`/`getFreeMem` report were on only as a side effect
of `MI_DEBUG>0`.

**Fix.** `-d:release`/`-d:danger` compile with `-DMI_BUILD_RELEASE`, and both
modes ask for `-DMI_STAT=1` explicitly so the three public procs report the same
thing in every build mode. This is only safe *because* the cache is now keyed on
the flags: with the old basename key, a `when defined(danger)` in a build pragma
would have made the last program built on the machine choose every other
program's allocator.

**Measured.** With a toolchain built from this change, a plain build, a
`-d:danger` build and a `--passC:-DMI_TRACK_VALGRIND=1` build produce three
coexisting objects instead of clobbering one. The danger object is 241KB with
**0** `mi_assert_fail`/`mi_check_padding`/`mi_page_decode_padding` symbols,
against 352KB and 3 for the debug one; both programs run.

### An inline range as a set's element type crashed the compiler

*Commit `1dc52142`.*

**What.** `set['a'..'z']` — which Nim defines as `set[range['a'..'z']]` — did
not compile. `semArrayType` recognises an inline range expression
(`isRangeExpr` → `semRangeTypeFromExpr`), so `array['a'..'z', T]` works; the
`SetT` branch in `semtypes.nim` went straight to `semLocalTypeImpl`, which
semmed `'a'..'z'` as a **value** expression. That is not an ordinal type, so a
correct program was rejected with *"set element type must be ordinal"*.

**Why it was a crash and not a diagnostic.** The `SetT` branch closes its own
tree with `takeParRi` *before* it validates the element type, so `buildErr`
appended the error node **after** a complete `(set T)`. The type-decl reader
expects one well-formed tree and aborted with a `[Bug]` traceback —
`expected ')', but got: (err . "set element type must be ordinal")`. That hit
every invalid set element type, not just this one: `set[string]`,
`set[1.0..2.0]` and `set[someProc]` all crashed the compiler rather than being
reported. `semArrayType` was unaffected because it errors while its own tree is
still open.

**Fix.** Handle `isRangeExpr` in the set branch exactly as arrays do, and make
the error node *replace* the set tree (`dest.shrink setStart`) instead of
following it.

The bug was wider than the char range it was reported for — `set[0..9]` failed
identically. `set[char]` and the named `set[range['a'..'z']]` were unaffected,
which is why it went unnoticed. Gated by `tests/nimony/sets/tsetrange.nim`,
checked against the unfixed compiler and failing there.

### A char literal could never satisfy a char range

*Commit `9225cbe9`.*

**What.** `var c: range['a'..'z'] = 'b'` was rejected with *"cannot prove value
is in range 97..122"*.

**Why.** The range-proof pass (`contracts_fir.nim`) models a literal operand by
reading its ordinal value, but handled only `IntLit` and `UIntLit`. A `CharLit`
fell through to the "value we cannot model" branch, which rejects
unconditionally — so no char literal, in range or not, could ever be assigned to
a char range. The integer analogue (`range[0..9] = 5`) always worked.

**Fix.** Read the literal the way `getConstOrdinalValue` does. An out-of-range
char now also gets the precise literal diagnostic instead of the vague one:
`value out of range: 66 notin 97..122`.
