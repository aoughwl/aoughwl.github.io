---
title: Suggestions — aowlsuggest
parent: aowlmony
nav_order: 11
has_children: false
---

# aowlsuggest — diagnostics, quick-fixes & editor integration
{: .no_toc }

The layer that sits **on top of [aowlparser](aowlparser)** and turns its
recoverable diagnostics into something actionable: verified quick-fixes, batch /
CI linting, and editor (LSP) payloads. Written in **nimony**, like the parser it
builds on — so it stays free of the classic Nim toolchain and JS-compilable.
{: .fs-6 .fw-300 }

[Repo → github.com/aoughwl/aowlsuggest](https://github.com/aoughwl/aowlsuggest){: .btn .btn-primary }
[Parser → aowlparser](aowlparser){: .btn }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Why it exists

[aowlparser](aowlparser) already does something the classic `nifler` never
could: it **recovers** past every syntax error instead of dying on the first, and
attaches a source span, a machine-readable `code`, a suggested repair, and even a
related location to each one. That is a genuinely better front end — but a raw
diagnostic stream is only half of a good developer experience.

`aowlsuggest` is the other half. It **consumes** those diagnostics and makes them
*do* something:

- **Quick-fixes.** `if x = 5:` → `if x == 5:`; a missing `:` inserted; a
  mismatched `]` swapped for the `)` its opener wants; a `=` added to a routine
  that forgot it. Each is **verified** by re-running the parser, so a fix can
  never corrupt valid code.
- **Batch / CI linting.** Lint a whole tree, human-readable or JSON, with a
  non-zero exit on any error.
- **Editor integration.** LSP `Diagnostic` objects (0-based ranges, related
  information) plus `CodeAction` quick-fixes — including ranked "did you mean"
  alternatives — and support for checking an **unsaved buffer** over stdin.

## The one rule

**aowlsuggest never lexes or parses Nim, and never duplicates diagnostic
emission.** The raw errors are produced *inside* aowlparser's recovering parse;
that coupling is deliberate and stays there. aowlsuggest only ever reads the
structured output. If a suggestion needs data the diagnostics don't carry, the
fix is to extend *aowlparser's* schema — not to re-derive it here. See
[The contract](aowlsuggest/the-contract).

## At a glance

```sh
aowlsuggest fix   <file> [--write] [--dry-run]   apply verified quick-fixes
aowlsuggest lint  <files...> [--format:json]     batch lint (nonzero exit on error)
aowlsuggest lsp   <file>                          LSP diagnostics + code actions (JSON)
aowlsuggest check <file> [--format:json]          raw diagnostics pass-through
```

```console
$ aowlsuggest fix bad.nim
--- bad.nim
+++ bad.nim (fixed)
@@ -1,2 +1,2 @@
-if x = 5:
+if x == 5:
   discard

1 fix(es) available (re-run with --write to apply)
```

## Pages

- [The contract](aowlsuggest/the-contract) — the one seam to aowlparser, the JSON
  it consumes, and how it is read defensively.
- [Commands](aowlsuggest/commands) — `fix`, `lint`, `lsp`, `check`, stdin buffers.
- [Quick-fixes](aowlsuggest/fixes) — the fix registry and the zero-false-positive
  verify loop that guards every repair.
- [Editor integration](aowlsuggest/editor-integration) — LSP diagnostics, ranked
  code actions, and unsaved-buffer support.
- [Testing](aowlsuggest/testing) — the 599-file zero-FP proof and the 2890-file
  realism gate.

## Where it fits

```
 .nim ──► aowlparser ──► diagnostics (--diagnostics:json) ──► aowlsuggest ──► fixes / lint / LSP
                    └──► .p.nif (the parse output)
```

aowlparser owns *what is an error*; aowlsuggest owns *what to do about it*. The
two evolve in lockstep across one documented boundary.
