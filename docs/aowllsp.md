# aowllsp — the Language Server, written in Nimony

**[aowllsp](https://github.com/aoughwl/aowllsp)** is a Language Server for Nimony
that is itself **written in Nimony** — a ground-up rewrite of the old (Nim 2)
`nimony-lsp`, so the whole editor stack is self-owned and, the end goal,
**JS-compilable for an in-browser IDE**.

[Repo → github.com/aoughwl/aowllsp](https://github.com/aoughwl/aowllsp)

## What it does

Broad coverage — ~36 LSP methods — over the live, unsaved buffer:

- **Diagnostics** — semantic errors from the checker, **plus** recovering
  *syntax* diagnostics from **[aowlsuggest](aowlsuggest)** over the same buffer,
  each carrying its rule id in LSP's `code` field.
- **Navigation** — definition, declaration, typeDefinition, implementation,
  references, documentHighlight, and hover.
- **Symbols** — documentSymbol + workspaceSymbol, from **[aowllens](aiflens)** `decls`.
- **Completion** — module symbols filtered by the identifier prefix under the
  cursor, and **type-directed member completion**: after `receiver.`, aowllsp
  resolves the receiver's type and offers only that type's fields, enum values,
  and first-parameter routines (UFCS/methods), following `object of Base` for
  inherited members. Resolution is **position-precise** — **[aowllens](aiflens)**
  `typeat` reads the type of the exact symbol under the receiver, so field chains
  (`a.b.c.`), shadowed names, **call results (`make().`)** and **index results
  (`xs[i].`)** all resolve to the right type (a trailing `)`/`]` is bracket-matched
  to the callee/container, whose routine or `[]`-operator return type is the
  receiver's type). It falls back to by-name resolution, then to plain prefix
  completion, so nothing is ever lost.
- **codeAction** — quick-fixes delegated to aowlsuggest, plus a `source.fixAll`
  action that applies every verified auto-fix in the buffer at once.
- **semanticTokens**, **rename** / **prepareRename**, **signatureHelp**,
  **codeLens** ("N references"), **documentLink**, **inlayHint** (inferred `:type`
  on un-annotated bindings), and whole-document **formatting**.

## In the browser — no subprocess

The desktop server reads NIF artifacts **in-process** and talks to the compiler
and [aowllens](aiflens) for the pieces it needs. The **browser build goes all the
way**: both seams are replaced by in-process calls — the parser, semantic
checker, and aowllens all run as JavaScript in the tab, and aowllsp answers
hover / completion / definition / references / symbols by walking the typed NIF
**with zero process spawning**. That is the design the old subprocess LSP
couldn't reach (a cold `nimony check` was seconds); reading the `.s.nif`
in-process is milliseconds.

Try it live in the **[playground](/playground/)**.
