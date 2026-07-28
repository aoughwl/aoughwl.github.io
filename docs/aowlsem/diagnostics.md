# Diagnostics

`aowlsem`'s error engine: a **side channel** that carries stable codes, real
source spans with caret underlines, edit-distance "did you mean" suggestions, and
a band of **opinion lints** that flag code the reference compiler silently
accepts — all without changing a single byte of the typed `.s.aif` it emits.

[[toc]]

---

## Side-channel design

A semantic error does **not** stop the check and does **not** alter the output.
When `aowlsem` finds a problem it records a structured `Diagnostic` and continues
emitting typed AIF. Two consequences follow directly:

- **One run reports every independent error** in the module, not just the first.
- **The byte-exact output is invariant.** A valid program yields zero
  diagnostics; the differential corpus (498/498 modules matching the reference's
  typed output) is untouched by the diagnostic layer.

Only *genuine* errors (severity `error`) also populate the legacy flat error
channel and set the failing exit code. **Opinion lints and idiom hints — things
the reference compiler accepts — are advisory** (`warning`): they render for
tooling but never abort a compile or diverge the exit code from the reference's.

```
error[E0300]: undeclared field `zz` on `Point`
  --> app.nim:9:8
   |
 9 | echo p.zz
   |        ^^
   = did you mean `x`?
```

## Two bands

`aowlsem` diagnostics fall into two categories, distinguished by whether the
reference compiler would also reject the code.

### 1. Errors — the reference rejects these too

Severity `error`. These abort the compile and set the exit code, matching the
reference's behavior (with a far better message).

| Code | Meaning |
|---|---|
| `E0100` | undeclared identifier (with the closest in-scope name) |
| `E0101` | undeclared routine (with the closest in-scope name) |
| `E0200` | type mismatch — a declared/assigned type the value cannot satisfy |
| `E0201` | too few arguments in a call |
| `E0202` | integer literal outside its sized-int type's range |
| `E0203` | array/seq index provably out of bounds (constant index) |
| `E0204` | division by zero (constant divisor) |
| `E0207` | empty `for` loop range (`for i in 5..0`) |
| `E0208` | tuple index out of range |
| `E0209` | shift amount ≥ the operand's bit width |
| `E0210` | constant index out of the array's range |
| `E0223` | duplicate element in a `set` literal |
| `E0300` | undeclared field on a known object type (with a field suggestion) |
| `E0400` | assignment to an immutable `let`/`const` (points back at the declaration) |
| `E0500` | non-exhaustive `case` over an enum (lists the uncovered members, in declaration order) |
| `E0501` | duplicate `case` branch — this value is already handled |
| `E0502` | duplicate enum value — two members share an ordinal |
| `E0600` | type mismatch in an expression/return position |
| `E0700` | condition is not `bool` |
| `E0800` | redeclared parameter |
| `E0801` | redeclared field |
| `E0900` | unreachable code after an unconditional exit (`return`/`raise`/`break`/`continue`) |

### 2. Opinion lints — the reference accepts these

Severity `warning`. Codes **E0205–E0222** (the `isOpinionCode` band) flag code
that is *legal* — the reference compiler compiles it without complaint — but is
almost always a mistake: tautologies, no-ops, dead branches. Because the
reference accepts them, `aowlsem` must **not** emit them as hard errors (that
would abort a compile the reference completes and diverge the exit code), so they
are advisory only.

| Code | Flags |
|---|---|
| `E0205` | self-comparison `x < x` / `x == x` — constant `true`/`false` |
| `E0206` | `unsigned < 0` — an unsigned value is never negative |
| `E0211` | self-assignment `x = x` — redundant |
| `E0212` | `x and x` / `x or x` over the same variable — the operator is a no-op |
| `E0213` | redundant arithmetic identity (`x + 0`, `x * 1`, `x and true`) |
| `E0214` | no-op compound assignment (`x += 0`, `x *= 1`, `x div= 1`) |
| `E0215` | double negation `not not x` — yields the original value |
| `E0216` | `while false` — the body is dead code |
| `E0217` | compound assignment that leaves its target unchanged |
| `E0218` | comparing a `bool` against `true`/`false` literally |
| `E0219` | comparison against a literal outside the operand's range — constant result |
| `E0220` | `x mod N` compared against a value it can never take |
| `E0221` | runtime `if` on a compile-time-constant condition — use `when`, or remove the branch |
| `E0222` | duplicate condition — an earlier branch already tests this, so this branch is unreachable |

Every opinion lint is **zero-false-positive by construction**: each fires only on
an unambiguous shape (a self-comparison over a *bare leaf*, a *constant* divisor,
a *literal* discriminator), never on an expression that could carry a side effect
or a value the checker only partially inferred. Valid, intentional code never
trips one.

## Rendering

The renderer (`renderDiag`) produces a rustc-style block:

```
error[E0100]: undeclared identifier `ehco`
  --> app.nim:2:3
   |
 2 |   ehco "hi"
   |   ^^^^ did you mean `echo`?
   |
   = help: …
```

- **Location** from the AIF line info attached to the offending cursor
  (`file:line:col`, 1-based column for humans).
- **Source line** re-read from the file on the error path (no caching — the
  common no-error path pays nothing).
- **Caret underline** — `col` leading spaces then `span` carets; `tokenSpan`
  widens the caret to cover the whole identifier/literal/string (including its
  quotes) rather than a single column.
- **Notes** — `help:` / `note:` follow-up lines, including the "did you mean"
  suggestion.

### "Did you mean" — edit distance over the live scope

`suggestName` computes classic Levenshtein distance from the misspelt name to
**every identifier actually in scope** — walked inner-scope-first across the whole
`scopes` stack, plus the template, imported-template and macro registries. The
threshold scales with length (≈ one edit per three characters, capped at 3), so
short names demand a closer match; a strict `<` on ties keeps the more-local
name (your own `count` beats an imported `cint` for `cont`). No suggestion is
offered when nothing is genuinely close, so the hint is never noise.

## JSON output — the tooling seam

`--diagnostics:json` emits a single JSON array, one object per diagnostic:

```json
[{"severity":"error","code":"E0300","message":"undeclared field `zz` on `Point`",
  "file":"app.nim","line":9,"col":7,"endCol":9,"notes":["did you mean `x`?"]}]
```

The schema (`severity`, `code`, `message`, `file`, `line`, `col`, `endCol`,
`notes`) is **field-compatible with [aowlparser](../aowlparser)'s**
`--diagnostics:json`, so a single tooling seam — [aowlsuggest](../aowlsuggest) —
consumes parse-stage and sem-stage diagnostics uniformly and drives quick-fixes
and the LSP. `col`/`endCol` are 0-based; `notes` is the `aowlsem` extension.

## How this compares to the reference

The reference compiler's diagnostics are terse, positionless in places, and have
no stable codes. `aowlsem`'s diagnostic layer is a deliberate step up:

- **Stable codes** (`E0xxx`) you can suppress, document, or match in tooling.
- **A real caret span** against the original source line, not just `file(line,
  col)`.
- **Suggestions** computed over the live scope, not a fixed dictionary.
- **A whole class of lints the reference lacks** — the opinion band flags
  tautologies and no-ops the reference silently miscompiles into dead code.
- **Structured JSON** shared with the parse stage, so one fix/LSP layer serves
  the whole front end.

And because it is a pure side channel, none of this costs a byte of divergence
from the reference's typed output — the richer errors are *added*, not traded
against parity.

## Magic-name suppression

A small guard (`isBuiltinMagicName`) keeps the undeclared-routine check
(`E0101`) from false-positiving on the names `aowlsem` lowers as **magics**
rather than ordinary routines — `ord`, `chr`, `succ`, `pred`, `len`, `high`,
`low`, `sizeof`, `card`, `incl`, `excl`, `contains`, `default`, `abs`, `min`,
`max`, `new`, `toOpenArray`, `items`, `pairs`, `mitems`, `mpairs`, `move`,
`swap`. These have no scope symbol by design, so an unresolved call to one is not
an error. Suppression is safe precisely because the diagnostic is a side channel.
