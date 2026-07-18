---
repo: aoughwl/obfuscate
---

# obfuscate — a NIF/AIF obfuscator for Nimony

An obfuscator for [Nimony](../nimony), built as a **test article**: a
program-analysis that claims to understand code by its execution *structure*
rather than its identifier *names* — or its source *shape* — should behave
identically whether the input is readable or obfuscated. `obfnif` produces the
adversarial input for that test.

It works **entirely on the compiler's own IR** — parsed or typed NIF/AIF — and
never on source text. Because it rides on the token tree rather than characters,
it *inherently* cannot corrupt runtime data: string literals, char literals and
comments are `Str`/`Char` tokens, not identifiers, so they are never rewritten.
There is no char-level scanner to get wrong, no map file, no risk of touching a
string that happens to look like a name.

> The previous source-text name-mangler (`obfuscate.nim`) has been **removed**.
> The parsed-layer pass below subsumes it — and does it structurally, so it can
> never mis-tokenise the input.

- TOC

---

## `obfnif` — one pass, two layers

`obfnif` reads a `.nif`/`.aif`, rewrites it as a balanced token tree, and writes
it back **in place** — a standalone filter in the same family as nimony's own
`nifler` / hexer passes, i.e. literally a compiler-pipeline plugin. It
auto-detects (by header dialect, then filename) which of the two layers a file is
and adapts every rewrite to that dialect:

### Parsed layer (`.p.nif` / `.nif`, `nim-parsed`)

The untyped tree `nifler` / `aowlparser` emit straight from source. Identifiers
here are plain `Ident` tokens, so renaming is by **spelling**: `obfnif` harvests
the first `Ident` child of every *definer* node — the name a module declares
(`proc`/`func`/`type`/`param`/`var`/`let`/`const`/enum-field …) — maps each to an
opaque token under one shared map, and rewrites every matching occurrence.
Foreign names (stdlib, keywords, imports) are never in the map, so they are left
alone; a keep-list preserves any declared anchor you want to remain callable. The
result **re-feeds `nimsem`** and behaves identically.

This is the structural replacement for the old source renamer: same effect
(defined names → opaque), but it cannot corrupt a string or a comment because it
never sees characters — only tokens.

### Typed layer (`.s.nif` / `.s.aif`)

The sem-checked tree the interpreter and backends run. Identifiers are `Symbol`s
carrying `base.disamb.module`, so renaming is **symbol-precise**: a definition and
every cross-module use collapse to one canonical key and get the same opaque base,
while the machinery the runtime binds by name or convention is provably left
intact — lifetime hooks (`=destroy`/`=copy`/…), operators, locals, and re-homed
generic instantiations of natives (`inc`, `Table`, `newSeqUninit`, whose disamb
carries an instantiation hash rather than pure digits). This is exactly the
precision a source-text renamer cannot safely reach.

## Obfuscation techniques

On top of renaming, `obfnif` weaves in behaviour-preserving control flow and
destroys provenance. Each technique is **dialect-aware** — it emits a node valid
in whichever layer the file is:

| flag | effect |
|------|--------|
| *(default)* / `--no-rename` | rename declared identifiers/symbols to opaque tokens |
| `--wrap-opaque` | wrap a statement as `if TRUE: S` (typed) / `if TRUE: S else: S` (parsed) |
| `--dead-else` | give the opaque `if` a dead `else` that never runs (typed) |
| `--dead-guard` | precede a statement with a never-firing `if FALSE:` branch |
| `--opaque-pred` | make the injected `TRUE`/`FALSE` **computed** constants — `not(false)`, `or(true,false)`, `and(true, not false)` — so a naive *is-it-literally-true?* scan is defeated while a sound *did-it-vary?* check still sees through them |
| `--junk-discard` | inject side-effect-free `discard <opaque-bool>` no-op statements |
| `--nest` | wrap a statement in redundant `stmts` nesting |
| `--strip-info` | zero every token's line-info — annihilates source *shape* and provenance at the IR level, in both layers |
| `--wrap-rate:N` | apply the per-statement injections on every Nth statement |
| `--name-style:opaque\|confuse` | `o0,o1,…` (default) or a visually-confusable `l/I/1/i/j` soup |
| `--all` | enable the full recommended set |
| `--parsed` / `--typed` | force the layer instead of auto-detecting it |

Two invariants keep every combination sound:

- **Injections only ever wrap genuine *executable* statements** — never a
  declaration or directive. Relocating an `import` into an `if` is illegal, and
  scoping a `let`/`type`/`proc` into an injected block would hide it from its
  siblings, so those nodes are emitted untouched (still renamed, still
  info-stripped). Only calls, assignments, loops, conditionals, returns and the
  like are wrapped.
- **The parsed wrap clones the statement into both arms** (`if TRUE: S else: S`).
  Only the always-true arm runs — behaviour is unchanged, `S` executes once — but
  because `nimsem` re-checks the parsed tree, the dead `else` keeps
  definite-assignment provable when `S` initialises `result` or a local. (In the
  typed layer nothing re-runs that check, so a single arm is emitted, which also
  avoids duplicating the statement's `SymbolDef`s.)

## Usage

```sh
# build (needs nimony's NIF libs on the path)
nim c -p:/home/savant/nimony/src/lib obfnif.nim

# parsed layer — obfuscate the untyped tree, then let nimsem re-check it
nifler p mod.nim mod.p.nif
obfnif --all keep.txt mod.p.nif

# typed layer — obfuscate the sem-checked tree the interpreter/backends consume
obfnif --wrap-opaque --dead-else --dead-guard --opaque-pred --strip-info keep.txt mod.s.nif
```

Files are rewritten **in place** and share one rename map, so a call in one module
still resolves to the renamed definition in another — pass every module of a
program together. The **keep-list** is one identifier per line (`#` starts a
comment): put keywords, stdlib names, imported symbols, and the public API you
ground against there.

## Verification

Behaviour preservation is checked end-to-end against nimony's own
`aowli-interp`. For **both** layers and every technique combination the
obfuscated IR — re-`nimsem`'d in the parsed case — produces byte-for-byte
identical program output, including across a multi-module program whose
**exported** symbols are renamed under the shared map (a call in `app` still
resolves to the renamed `proc` in `helper`). On the typed layer, `--all` grows
the IR to ~1.5× while output is unchanged.

## Why the injected control flow is invisible to a sound analysis

A rule-dispatch — the thing worth extracting — fires *different* arms across a
run. An injected `if TRUE` fires the *same* arm every time: it decides nothing.
So the sound criterion is a **runtime** one — *did this branch site's choice ever
vary?* — never a guess from the label or the source shape. A branch that never
varied carries zero information and is dropped before any behaviour is
fingerprinted. `--opaque-pred` sharpens the test further: the condition is no
longer a literal `true` a constant-folder could recognise, yet a variance-based
analysis still discards it because it never chose differently.

The one subtlety that makes this actually sound: a branch *site* must be the
distinct source **construct**, not its line number. An injected `if` wrapping a
`case` shares the `case`'s line, so keying sites on lines lets the (varying) case
drag the (constant) wrapper along with it — and `--strip-info` deletes those line
numbers outright. Keying instead on the branch node's own identity separates them
cleanly.

With that in place, the numbers line up exactly. On a CSS validator the
rule-extractor yields the **same 46 rule-ideas / 63 grounded claims** on the
original, the names-obfuscated, and the names-plus-control-flow-obfuscated inputs,
and the central `matchOne` dispatch reads out its eight combinator rules with
**identical firing counts** (622 / 72 / 36 / 34 / 10 / 4 / 2 / 1) every time; only
the labels change (`opKw → o1`, `opRef → o5`, …). Names gave zero help; shape gave
zero help. The analysis rides on the decisions that actually varied, and nothing
else — which is what "sound" has to mean.
