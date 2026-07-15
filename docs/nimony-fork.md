---
title: Divergences from upstream
grand_parent: Nimony
parent: Fork
nav_order: 1
---

# aoughwl's nimony fork
{: .no_toc }

Changes in [`aoughwl/nimony`](https://github.com/aoughwl/nimony) (branch
`master`) that diverge from upstream [`nim-lang/nimony`](https://github.com/nim-lang/nimony).
Each entry records a bug fixed or feature added, and why.

- TOC
{:toc}

---

## Fixes

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
