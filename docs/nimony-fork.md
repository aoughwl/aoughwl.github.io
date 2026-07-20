# aoughwl compiler fixes

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
