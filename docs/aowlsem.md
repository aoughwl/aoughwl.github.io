---
repo: aoughwl/aowlsem
---

# aowlsem — the semantic-analysis stage

`aowlsem` is the semantic checker of the aoughwl toolchain, a clean-room
replacement for the reference compiler's `nimsem`. It reads the parse dialect of
AIF (`.p.aif`, from [aowlparser](aowlparser)) and writes typed, symbol-resolved
AIF (`.s.aif`) ready for the lowering stage ([aowlhexer](aowlhexer)). It resolves
names, checks types, picks overloads, instantiates generics, and synthesizes
lifetime hooks — **checking and lowering fused in one demand-driven pass**.

```
 .p.aif ──► aowlsem ──► .s.aif
 (parse)   (semcheck)  (typed)
```

It is ~20.8k lines of self-hosted Nimony. Its byte-exact differential corpus
stands at **498/498** modules matching the reference compiler's own typed output,
with the entire `std/system` checking clean.

## Model

**Demand-driven, checking and lowering fused.** Every semantic routine has the
shape `sem*(c, dest, cur): Type` — it consumes parse-form AIF at `cur`, *writes*
the lowered typed AIF into `dest`, and *returns* the checked type. There is no
separate check pass and lower pass, and no global multi-phase walk: each fact — a
symbol's type, an overload choice, a generic instance — is computed the moment
another construct needs it, then memoised. Forward references and mutual
recursion at module scope need no forward declarations.

Built on the `nifcore` cursor stack, so traversal is fast `skip` over the AIF
token buffer rather than materialising nodes. The engine is one compilation unit
of nine `include` fragments. See [Architecture](aowlsem/architecture) for the
full model — including a direct answer to *"can the checker and lowerer be split
into two stages?"*

## Diagnostics

A semantic error does not stop the check. `aowlsem` records a structured
diagnostic and continues, so one run reports every independent error in the
module. Each diagnostic carries a **stable code**, a real **source span** with a
caret underline, and `help:`/`note:` follow-ups — including edit-distance "did you
mean" suggestions computed over the names actually in scope:

```
error[E0300]: undeclared field `zz` on `Point`
  --> app.nim:9:8
   |
 9 | echo p.zz
   |        ^^
   = did you mean `x`?
```

Diagnostics are a **side channel**: they are written to stderr after the `.s.aif`
is emitted, and recording one never alters the typed output — a valid program
yields zero. There are **36 codes** in two bands: genuine **errors** the
reference compiler also rejects, and a band of advisory **opinion lints**
(E0205–E0222) that flag tautologies, no-ops and dead branches the reference
*accepts*. The full table, the rustc-grade renderer, the JSON tooling seam, and a
comparison with the reference's diagnostics are on the [Diagnostics
page](aowlsem/diagnostics).

## Usage

```sh
aowlsem m <in.p.aif> <out.s.aif> --path:<lib> --nimcache:<nc>   # semcheck a module
```

With `--path:` and `--nimcache:` set, `aowlsem m` resolves the module's whole
import graph itself — a real drop-in for `nimsem`. Full command/flag reference and
the programmatic `semcheck*` entry point are on the [CLI & API page](aowlsem/cli).

## What it checks

Everything below is checked construct by construct against the reference
compiler's own output. The `tests/corpus/` suite — 498 modules, all byte-exact —
is the concrete list. What each construct lowers to, with worked
`.p.aif → .s.aif` examples, is on the [Lowering reference](aowlsem/lowering).

#### Declarations and bindings

`let` / `var` / `const`, global and local. Type inference from literals,
identifiers, calls and operators. Explicit-type bindings, typed constants
(`(suf v "i64")`), compile-time integer const-folding, multi-assignment, and
tuple unpacking in `let` / `var`.

#### Types

`int`, `float`, `bool`, `char`. Sized-int aliases (`int8`, `uint`, `int64`,
`byte` → `(i N)` / `(u N)`) with explicit `hconv` narrowing. `string`.
`array[N,T]` with indexing, `len`, `high`, `low`. `seq[T]` — `@[]`, indexing,
index-assign, `len`, iteration, `add`. Tuples, positional and named. `distinct`
types and their conversions. `enum`, with a synthesized `$`. `set` operations.
`HSlice` (`a ..< b`). `ptr` and pointer casts. `sizeof`.

#### Operators and conversions

Arithmetic `+ - * div mod` and float `/`. Bitwise `and` / `or` / `xor` and the
shifts `shl` / `shr`. Comparisons `< <= == > >= !=`. Boolean `and` / `or` /
`not`. Unary `-` and `abs`. Compound assignment. `ord`, `succ` / `pred`, `$`,
int↔float conversions. String concat, equality, indexing, index-assign and
iteration.

#### Control flow

`if` / `elif` / `else` as both statement and expression. `case` / `of` / `else`
including range branches. `while`. `for` over ranges, sequences and strings.
`break` / `continue`. Labelled `block`. `defer`. `try` / `except` / `finally`,
including `except T as e`. `return`. `when`, folded at compile time — `defined`,
`x is T`, `typeof`.

#### Routines

Procs with parameters, return types and an implicit `result`. Overload
resolution by arity and parameter type. `var` parameters (`(mut T)` plus
auto-deref). Named arguments. UFCS, with and without parens. Operator
definitions and `{.borrow.}` operators, including distinct-return conversion.
Recursion, mutual recursion and nested procs. Forward references. Procs and
iterators as values, anonymous proc literals, and `importc` procs.

#### Generics

Generic routine and `object` declaration and instantiation: inference,
multi-typevar inference, callback and proc-type inference, and explicit type
arguments. Imported generics instantiate; nested instantiation works; instances
are memoised.

Generic **sum types** instantiate and construct by inference — `Some(99)` →
`Option[int]`, `Either[int,string]`, `Pair(first:1,second:2)` → `Pair[int]` —
with named-variant branch fields resolving inside generic bodies. Generic **`ref
object`** types emit both halves (the ref alias and `.Obj`) with correct
per-instance identity, lifetime hooks and typevar numbering, and construct the
concrete instance.

#### Objects, refs and inheritance

`object` declarations with field access and assignment, nesting, use as
parameters and return types, default fill and empty construction. `ref object`.
Anonymous variants (sum types) with `of`-label constructors and
`of Label(field)` pattern matching. Object and `ref` inheritance across multiple
levels. `method` declarations with dynamic dispatch and overrides — value-object
methods emit a vtable-only pragma.

#### Templates and macros

`template` expansion by inline substitution, with `untyped` / `typed` wildcard
params. `macro` declaration and expansion via compile-time evaluation.

#### Modules

`import` resolution against checked `.s.aif`, including `from X import`,
`import X except` and transitive re-exports. `include` inlining. `system`
loading.

## Optimizer

`aowlsem opt` runs a high-level pass over an already-checked `.s.aif` and reports
the node count before and after. It is a **separate pass** from `m`, so semantic
output is unaffected.

## Pages

| Page | Contents |
|---|---|
| [Architecture](aowlsem/architecture) | the fused check+lower model, demand-driven engine, the nine include-fragments, `SemContext`, the prescan, and the *"can the two systems be split?"* answer |
| [Diagnostics](aowlsem/diagnostics) | side-channel design, all 36 codes in two bands (errors vs opinion lints), rustc-grade rendering, "did you mean", JSON seam, comparison to the reference |
| [CLI & API](aowlsem/cli) | `m` / `opt` / `passthrough`, flags, self-resolving imports, exit behavior, and the `semcheck*` programmatic entry |
| [Lowering reference](aowlsem/lowering) | worked `.p.aif → .s.aif` transformations for every major construct |

## Pipeline

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─► aowlc / aowljs / aowli
    source         parse       semcheck    lower        code / interpret
```

aowlsem is the typing seam: everything downstream reads the symbols, resolved
overloads and generic instances it writes into `.s.aif`. The format on both sides
is [AIF, which is NIF](aif) byte-for-byte, so the typed output is interchangeable
with the reference compiler's own.
