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

## Capabilities

Checked construct-by-construct; the `tests/corpus/` suite (498 modules, all
byte-exact against the reference oracle) is the concrete list. What each construct
lowers to — with worked `.p.aif → .s.aif` examples — is catalogued on the
[Lowering reference](aowlsem/lowering).

**Declarations & bindings**
: `let` / `var` / `const` (global and local); type inference from literals,
identifiers, calls and operators; explicit-type bindings; typed constants (`(suf
v "i64")`); compile-time integer const-folding; multi-assignment; tuple unpacking
in `let`/`var`.

**Types**
: `int`/`float`/`bool`/`char`; sized-int aliases (`int8`, `uint`, `int64`, `byte`
→ `(i N)`/`(u N)`) with explicit `hconv` narrowing; `string`; `array[N,T]` with
indexing, `len`, `high`, `low`; `seq[T]` (`@[]`, indexing, index-assign, `len`,
iteration, `add`); tuples (positional and named); `distinct` types and
conversions; `enum` (with synthesized `$`); `set` operations; `HSlice` (`a ..<
b`); `ptr`/pointer casts; `sizeof`.

**Operators & conversions**
: arithmetic `+ - * div mod` and float `/`; bitwise `and`/`or`/`xor`, shifts
`shl`/`shr`; comparisons `< <= == > >= !=`; boolean `and`/`or`/`not`; unary `-`,
`abs`; compound assignment; `ord`, `succ`/`pred`, `$`, int/float conversions;
string concat, equality, indexing, index-assign, iteration.

**Control flow**
: `if`/`elif`/`else` (statement and expression); `case`/`of`/`else` with range
branches; `while`; `for` over ranges, sequences and strings; `break`/`continue`;
labelled `block`; `defer`; `try`/`except`/`finally` and `except T as e`;
`return`; `when` folded at compile time (`defined`, `x is T`, `typeof`).

**Routines**
: procs with parameters, return types and implicit `result`; overload resolution
by arity and parameter type; `var` parameters (`(mut T)` + auto-deref); named
arguments; UFCS (with and without parens); operator definitions; `{.borrow.}`
operators (including distinct-return conversion); recursion, mutual recursion,
nested procs; forward references; procs and iterators as values; anonymous proc
literals (lambdas); `importc` procs.

**Generics**
: generic routine and `object` declaration + instantiation (inference,
multi-typevar inference, callback/proc-type inference, and explicit type args);
instantiation of imported generics; nested instantiation; instance memoisation.
Generic **sum types** instantiate and construct by inference (`Some(99)` →
`Option[int]`; `Either[int,string]`; `Pair(first:1,second:2)` → `Pair[int]`),
with named-variant branch fields resolving inside generic bodies. Generic **`ref
object`** types emit both halves (ref-alias + `.Obj`) with correct per-instance
identity, lifetime hooks, and typevar numbering, and construct the concrete
instance.

**Objects, ref & inheritance**
: `object` declarations, field access/assignment, nesting, params/returns,
default fill, empty construction; `ref object`; **anonymous variants (sum
types)** with `of`-label constructors and `of Label(field)` pattern matching;
object and `ref` inheritance across multiple levels; `method` declarations with
dynamic dispatch and overrides (value-object methods emit a vtable-only pragma).

**Templates & macros**
: `template` expansion (inline substitution; `untyped`/`typed` wildcard params);
`macro` declaration and expansion via compile-time evaluation.

**Modules**
: `import` resolution against checked `.s.aif` (with `from X import`, `import X
except`, transitive re-exports); `include` inlining; `system` loading.

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
