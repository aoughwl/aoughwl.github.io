---
title: aowlparser
parent: Compiler Pipeline
nav_order: 1
has_children: true
---

# aowlparser — Nim → NIF parser
{: .no_toc }

A pure-**nimony** recursive-descent parser that turns Nim source into the
parse-dialect NIF (`.p.nif`) the compiler frontend consumes — the same job as the
compiler's `nifler`, but self-hosted and free of the classic Nim compiler, so it
can be compiled to JavaScript and run in the browser.
{: .fs-6 .fw-300 }

[Repo → github.com/aoughwl/aowlparser](https://github.com/aoughwl/aowlparser){: .btn .btn-primary }
[Playground →](../playground){: .btn }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## Why it exists

The [playground](../playground) runs [aowli](../aowli) client-side today, but only on
**precompiled** typed NIF. To recompile edits live in the browser (Tier 2), the
compiler *frontend* — parse then semcheck — has to run in JS too. Semcheck
(`nimsem`) already self-hosts under nimony and translates cleanly to JS. The
parser did not: the stock `nifler` is built on the **classic** Nim compiler
(`compiler/lexer`, `parser`, `syntaxes`, `ast`), which is Nim 2 and not
nimony-compilable — so it cannot go to the browser.

`aowlparser` closes that gap: a from-scratch parser written in nimony, emitting
the identical `.p.nif` wire format, that compiles through the nimony JS backend.
The chain `source → aowlparser → nimsem → aowli` is what makes an in-browser,
recompile-on-edit playground possible.

## What it produces

`nifler` — and therefore `aowlparser` — is a **purely syntactic** transducer. It
does no semantic checking and no symbol resolution; every symbol comes out as a
bare identifier. The output is the *parse dialect* of NIF: a faithful, fully
line-info-annotated s-expression rendering of the Nim parse tree. Everything the
compiler does next (name binding, overload resolution, generic instantiation)
happens in later phases that read this file.

## Status

The bar is output **identical to native `nifler` down to the byte** — with one
deliberate exception: aowlparser stamps its own `(.vendor "aowlparser")` header
instead of impersonating `nifler`, so every file differs on exactly that line.
The [differential harness](aowlparser/testing) neutralizes that single directive
and holds everything else strict. Two levels: **structural** (token trees equal
after line-info is stripped — the pass criterion) and **exact** (byte-identical
`.p.nif`, line-info included, apart from the `(.vendor)` line).

| test suite | files | result |
|:--|:--|:--|
| curated corpus | 76 | **76 pass**, 76 byte-exact\* |
| nimony standard library (`nimony/src/lib`) | 29 | **29 pass** structurally, **29 byte-exact**, 0 crash |
| whole nimony compiler tree (`nimony/src`) | 184 | **184 pass**, **184 byte-exact**, 0 crash / 0 hang |

<small>\* byte-exact apart from the one-line `(.vendor)` header identity.</small>

The **entire nimony compiler tree** — the standard library and the compiler's own
dense internals — round-trips structurally identical to native nifler, line-info
stripped: all 184 files, zero mismatches, zero crashes. Beyond that, **every one of
the 184 files is byte-identical** (line-info included, modulo the vendor line) — not
just the token tree but the exact relative line-info of every node: full
byte-for-byte parity across the whole tree. See
[Coverage](aowlparser/known-gaps) for how the line-info model was reverse-engineered
node by node.

## Better errors than the reference

`nifler` inherits the classic compiler's **abort-on-first-error** behaviour;
`aowlparser` does strictly better. It is fully recoverable — it records *every*
problem with a source span, keeps going, and still emits best-effort NIF — which
is what an in-browser editor needs (squiggles for all errors at once). A
`aowlparser check <file>` lint mode emits diagnostics as compiler-style text or, with
`--diagnostics:json`, a machine-readable array for editors; a normal parse streams
them to stderr and never blocks. See [Configuration](aowlparser/configuration).

## The documentation set

| Page | What it covers |
|:--|:--|
| [Architecture](aowlparser/architecture) | Fused parse + emit, the range-splitter, the include-file module map, the line-info model, and the classic-compiler oracle. |
| [Grammar coverage](aowlparser/grammar) | Exactly which lexer, expression, statement, section, and type constructs are reproduced. |
| [The .p.nif format](aowlparser/output-format) | The emitted wire form itself: header directives, the base62 line-info suffix grammar, operator escaping, and the tag vocabulary — enough to read a `.p.nif` by eye. |
| [Browser & JavaScript](aowlparser/browser) | Running aowlparser client-side: the `globalThis.__np_*` contract, the `aowlparser.js` build recipe, and the `webdiag` editor-diagnostics layer. |
| [Differential testing](aowlparser/testing) | The oracle harness, `canon.py`, structural-vs-exact comparison, and how to run it. |
| [Configuration](aowlparser/configuration) | The optional, off-by-default flags: `--curly` block bodies and the indentation/whitespace policy switches. |
| [Known gaps](aowlparser/known-gaps) | The catalogued edge cases that still differ on the broader compiler corpus. |

---

[Repo → github.com/aoughwl/aowlparser](https://github.com/aoughwl/aowlparser){: .btn .btn-primary }
