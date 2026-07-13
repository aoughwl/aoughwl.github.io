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
