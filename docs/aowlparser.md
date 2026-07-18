# aowlparser — Nim → AIF parser

Pure-nimony recursive-descent parser: Nim source to parse-dialect AIF (`.p.aif`).
Produces the same output as the classic compiler's `nifler`, but is self-hosted —
no dependency on the classic Nim compiler, so it compiles through the nimony JS
backend and runs in the browser. Output is byte-identical to `nifler` except the
one header line it owns, `(.vendor "aowlparser")`.

[Repo → github.com/aoughwl/aowlparser](https://github.com/aoughwl/aowlparser)
[Playground →](../playground)

## Scope

Purely syntactic. No semantic checking, no symbol resolution — every symbol is
emitted as a bare identifier. The output is the parse dialect of AIF: a
line-info-annotated s-expression of the Nim parse tree. Name binding, overload
resolution and generic instantiation run in later phases (`aowlsem` onward) that
read this file.

It exists in nimony so the browser playground can run the compiler frontend
(`source → aowlparser → aowlsem → aowli`) client-side. `nifler` can't: it is built
on the Nim-2 classic compiler and does not compile under nimony.

## Conformance

Differential-tested against native `nifler`. *Structural* = token trees equal with
line-info stripped; *byte-exact* = identical `.p.aif` including line-info, modulo
the `(.vendor)` line.

| corpus | files | structural | byte-exact |
|:--|--:|--:|--:|
| nimony/src (compiler tree) | 184 | 184 | 184 |
| nimony/lib (stdlib) | 105 | 105 | 91 |
| upstream Nim/lib | 310 | 310 | 283 |
| curated | 172 | 172 | 156 |

0 crashes and 0 hangs across all four. The upstream Nim/lib pass — reached by
differential fuzzing — covers term-rewriting template patterns, `Inf`/`NaN`
hex-bit literals, custom numeric literals (`1'big`), method-chain continuations,
multi-`do` calls and pragma-decorated lambda sugar. The line-info model was
reverse-engineered per construct against the oracle; see [Known gaps](aowlparser/known-gaps).

## Diagnostics

Recoverable, unlike `nifler`'s abort-on-first-error: records every error with a
source span, keeps parsing, and still emits best-effort AIF — so one run surfaces
every problem with no phantom end-of-file cascade. On the Nim compiler test
corpus, on files where both report errors, `nifler` emits ~2× the error lines.

- Fix-its per error (`help: insert ':'`, `help: did you mean '=='?`).
- Related locations as structured fields (a mismatched bracket points at both ends).
- `aowlparser check <file>` lint mode; `--diagnostics:json` emits
  `{severity, code, message, line, col, endCol, fix, related}` per diagnostic.
- Full classic-lexer error parity, recovering past each: bad char literals, illegal
  tabs, unterminated block/triple/raw strings, malformed escapes, malformed numbers
  (including an exponent with no digits like `1e`, and a C/Java/JS suffix or stray
  letter glued to a number like `100L`/`100n` — Nim's typed literal uses an
  apostrophe, `100'i64`), unterminated accent-quoted identifiers.
- Detections `nifler` lacks: assignment-in-condition (`if`/`elif`/`while`/`when x = 5:`),
  comparison-in-binding (its mirror — `let`/`const x == 5`),
  the cross-language habits `let x := 5` (Pascal/Go walrus), `proc f() -> int`
  (Rust/Python-3/C++ return arrow), `std::vector` (C++ scope resolution),
  `proc f<T>()` (C++/Java/Rust/TS angle-bracket generics), `let mut x` (the Rust
  mutable-binding habit — Nim's is `var`), `var x int` (the Go/Java/C#/Swift
  `name type` binding, missing Nim's `:`), `fn`/`function`/`fun name() { … }` (a
  routine written with a Rust/JS/Kotlin function keyword and a brace body),
  `class`/`struct`/`interface`/`impl`/`trait`/`namespace`/`module name { … }` (an
  OO/type/module block from another language — Nim types are `type Name = object`
  and modules are files), `switch`/`match x { … }` (Nim's is `case x:` with `of`
  branches), a C/JS `do { } while` loop and Ruby `do |x|` block params, a C-style
  `/* … */` block comment (Nim's is `#[ … ]#`), a Java `throws` or Rust/Swift/C#
  `where` routine clause (Nim uses a `{.raises.}` pragma and `[T: Constraint]`), a
  stray `end`
  (Ruby/Pascal/Lua block terminator) and a C-style `{ }` body; `else if` used for
  `elif`, empty conditions (`elif:`), empty comma slots (`foo(a,,b)`),
  missing-introducer
  bodies (`proc f()` then an indented line with no `=`; `type Name` with a body but
  no `= object`), and precise grammar diagnostics where `nifler` is terse: `func` in
  a type description, a keyword where an enum member belongs, an empty object-variant
  branch, `of`/`for` missing their value (`of:`, `for x of xs`).
- UTF-8 identifiers, and `#? stdtmpl` filter files (recognized as non-Nim).

Every check is proven zero-false-positive against the 599 valid files and never
changes the emitted AIF.

## Pages

| Page | Covers |
|:--|:--|
| [Architecture](aowlparser/architecture) | fused parse+emit, range-splitter, include-file module map, line-info model, `nifler` oracle |
| [Grammar coverage](aowlparser/grammar) | lexer / expression / statement / section / type constructs reproduced |
| [The .p.aif format](aowlparser/output-format) | header directives, base62 line-info suffix, operator escaping, tag vocabulary |
| [Browser & JS](aowlparser/browser) | client-side build, the `globalThis.__np_*` contract, `webdiag` |
| [Differential testing](aowlparser/testing) | oracle harness, `canon.py`, structural vs byte-exact |
| [Configuration](aowlparser/configuration) | `--curly` block bodies, whitespace policy switches |
| [Known gaps](aowlparser/known-gaps) | remaining corpus edge cases |
