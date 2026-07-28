# Architecture

How `aowlsem` is built: a demand-driven engine in which **checking and lowering
are fused** — every construct is type-checked and emitted as typed AIF in the
same traversal, not in two passes.

[[toc]]

---

## The core contract

Every semantic routine has the same shape:

```nim
proc semExpr(c: var SemContext; dest: var TokenBuf; cur: Cursor): Type
proc semStmt(c: var SemContext; dest: var TokenBuf; cur: var Cursor)
proc semCall(c: var SemContext; dest: var TokenBuf; cur: Cursor): Type
proc semType(c: var SemContext; dest: var TokenBuf; cur: Cursor): Type
```

Three arguments, one invariant:

- **`cur`** — a read-only cursor into the **parse-form** AIF (`.p.aif`) being
  consumed.
- **`dest`** — the **typed** AIF (`.s.aif`) being produced; the routine *writes*
  its lowered output here.
- **return `Type`** — the checked/inferred type of what it just consumed.

So a single call to `semExpr` **both** lowers (appends resolved, symbol-bound,
type-annotated nodes to `dest`) **and** checks (returns the `Type`, records any
diagnostic). There is no intermediate typed tree held in memory between a "check
pass" and a "lower pass": the typed tree *is* `dest`, built as checking proceeds.
Diagnostics are recorded as a side effect and never alter `dest`.

This is the answer to "are the two systems split?" — **they are deliberately
fused per-construct.** See [Checking vs. lowering](#checking-vs-lowering) below.

## Demand-driven, not phased

There is no global multi-phase walk (no separate "resolve names", then "infer
types", then "check", then "instantiate"). Every semantic fact — a symbol's
type, an overload choice, a generic instance, a lifetime hook — is computed the
moment another construct needs it, then **memoised** in `SemContext`. A construct
is checked exactly once, when first demanded.

Consequences:

- **Forward references and mutual recursion at module scope need no forward
  declarations** — a call to a proc defined later resolves through the prescan
  registry (below), and its body is checked on first demand.
- **Generic instances are content-addressed and cached.** `requestInstance` /
  `requestTypeInstance` key an instance by `(origin, type-args)`; the second
  request for `seq[int]` returns the first result. Instantiation is copy +
  substitution of the generic body followed by a normal `semStmt` over the
  substituted form — so an instance is checked by the *same* code that checks
  ordinary source.

The traversal runs on the **nifcore cursor stack**: tree walking is `skip` over
the flat AIF token buffer, never node materialisation.

## One compilation unit, nine fragments

The engine is one Nim module — `semcore.nim` — that `include`s nine fragments in
a fixed order. `include` (not `import`) means every fragment sees `SemContext`,
the tag cache, the scope tables and the cursor API directly, with no interface
boundary; the split is for navigability, and **order matters** (a fragment may
call anything defined earlier).

| # | Fragment | Responsibility |
|---|---|---|
| 1 | `sem/diagnostics` | structured-diagnostic model + rustc-grade renderer + edit-distance suggestions |
| 2 | `sem/types` | the type lattice, scope & overload tables, `emitType`, `typeOf`, `semType`, `pickOverload` |
| 3 | `sem/exprs` | infix/prefix, unify/infer, generic-instance requests, template & macro expansion, `semOconstr` |
| 4 | `sem/calls` | `semCall`, dot/subscript, literals & constructors, **`semExpr`**, locals/const/params |
| 5 | `sem/stmts` | `asgn`/`while`/`for`/`try`/`case`/`if`, `return`, proc bodies, `semProc`/`semTemplate` |
| 6 | `sem/objects` | `object`/`enum`/`ref`/`distinct` type emission, `semTypeDecl` |
| 7 | `sem/instances` | the **`semStmt`** driver, copy+subst instancing, `emitInstance` |
| 8 | `sem/hooks` | ARC lifetime-hook synthesis (value / variant / ref), type-instance emission, field registration |
| 9 | `sem/module` | `semModule` assembly, `system`/type/proc loading, the prescan, the `semcheck*` entry point |

`semcore.nim` itself owns the shared declarations the fragments close over: the
`Type` / `Sym` / `Field` / `VariantInfo` / `Diagnostic` records, the `TagCache`
(interned tag ids), and the ~150-field `SemContext`.

## The prescan — the one preparatory sweep

Before the demand-driven walk, `semModule` runs a **lightweight prescan** over
the flattened module. It does *not* check or lower; it only pre-registers what
forward references need:

- **Type names** (`prescanTypeNamesIn`) then **type bodies**
  (`prescanTypeBodiesIn`) — so a field of a type declared later resolves.
- **Typevar numbers** (`typeTypevarPre`) — every type declaration's type
  parameters are numbered in source order *before* any proc typevar, matching the
  reference compiler's global numbering (`seq`/`openArray` take low `T.` numbers
  even when declared after early procs).
- **Proc signatures** (`preProcs`, `preParamMangles`, `procMagic`, the implicit
  `result` mangle) — so a call to a not-yet-checked proc resolves its overload
  and arity.
- **Compile-time `const bool`s** (`prescanConstBools`) — so a `when
  defined(...)`-gated *declaration* is registered from the taken branch.

`when` conditions that select declarations are folded during the prescan, so
platform-conditional types and fields never reach the main walk as dead code.

## Module assembly & resolution

`semcheck*` (in `sem/module`) is the programmatic entry. Given the module's
parse buffer and the checked `system` buffer, it:

1. **Loads `system`** (unless `--noSystem`) so builtin types and routines
   (`string`, `&`, `$`, `seq`, the arithmetic magics…) resolve.
2. **Resolves the import graph** from the module's `.p.deps.aif`: each imported
   module's already-checked `.s.aif` is loaded and its exported types / procs /
   converters / templates registered. `from X import`, `import X except`, and
   re-exports are followed transitively across the whole closure.
3. **Inlines every `include`** into one flat `(stmts …)` before checking.
4. **Prescans**, then **walks** the flattened module top-level via `semModule` →
   `semStmt`.

The CLI (`aowlsem m …`) is a thin wrapper over `semcheck*`; see [CLI &
API](cli).

## Checking vs. lowering

A frequent question: *can the checker and the lowerer be separated into two
independent stages?* Today they are **one fused stage**, by design:

- **Fused core.** Each `sem*` routine emits lowered AIF into `dest` **and**
  returns the checked `Type` in the same call. The typed tree is never
  materialised separately — it is streamed into `dest` as checking decides each
  node's symbol, overload and instance. Splitting it would mean building an
  intermediate typed AST for a whole module, then a second walk to emit — paying
  for a materialised tree and a second traversal to gain a boundary the
  demand-driven model does not need. The reference compiler fuses them for the
  same reason.

- **What *is* cleanly separated.** Three seams are genuinely decoupled:
  - **Diagnostics** (`sem/diagnostics`) are a pure **side channel**: recording a
    diagnostic never changes `dest`, so the byte-exact typed output is identical
    whether or not a diagnostic fired, and a valid program yields zero. This is
    the seam that lets aowlsem carry richer errors than the reference without
    diverging its output. See [Diagnostics](diagnostics).
  - **The high-level optimizer** (`aowlsem opt`, `optcore.nim`) is a **separate
    pass** over an already-checked `.s.aif`. It does not run inside `m`.
  - **Instantiation** reuses the checker: `requestInstance` copies + substitutes
    a generic body and hands it back to `semStmt`, so there is no parallel
    "instantiate" implementation to keep in sync with the checker.

The practical upshot: the seam you would reach for to "split the systems" already
exists where it pays off (diagnostics, optimization), and stays fused where
splitting would only cost a second pass (core check + lower).

## State: `SemContext`

`SemContext` is the whole engine's mutable state — ~150 fields, most of them
memo tables. The important families:

- **Scopes & overloads** — `scopes: seq[Table[string, seq[Sym]]]` (a stack of
  name → overload-set), plus `counters` (per-name mangle counter).
- **Type facts** — `fieldsOf`, `viewFieldsOf`, `variantOf`, `enumTypes`,
  `sumEnumOf` / `sumLabelOwner` (anonymous sum types), `distinctBase`,
  `aliasTarget`, `objBase` (inheritance depth).
- **Generic machinery** — `genericDecl` / `genericTypeDecl` (the un-instantiated
  bodies), `typeInstReqs` (pending instance emissions), `instDestroyHook` /
  `instWasmovedHook` / `instDupHook` / `instCopyHook` (per-instance lifetime
  hooks), `instRefObj` / `refObjOrigin` (generic `ref object` alias↔`.Obj`).
- **Const folding** — `constVals`, `constBools`, `constStrs`, `constSets`.
- **Prescan registries** — `preProcs`, `typeTypevarPre`, `prescanConstBools`,
  `procMagic`.
- **Output-side** — `errors` (the flat legacy error channel — only genuine
  errors populate it), `diags` (the structured diagnostics).

Because every fact lives in one context object, memoisation is uniform: a
routine checks its table first and computes-then-stores on a miss.

## Pipeline position

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─► aowlc / aowljs / aowli
    source         parse       semcheck    lower        code / interpret
                              (.p.aif→.s.aif)
```

`aowlsem` is the typing seam of the toolchain: everything downstream reads the
symbols, resolved overloads and generic instances it writes into `.s.aif`. The
format on both sides is [AIF, which is NIF](../aif) byte-for-byte, so the typed
output is interchangeable with the reference compiler's own.
