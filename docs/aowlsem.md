---
repo: aoughwl/aowlsem
---

# aowlsem — the semantic-analysis stage

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

`aowlsem` is the semantic checker of the aoughwl toolchain, a clean-room
replacement for the reference compiler's `nimsem`. It reads the parse dialect of
AIF (`.p.nif`, from [aowlparser](aowlparser)) and writes typed, symbol-resolved
AIF (`.s.nif`) ready for the lowering stage ([aowlhexer](aowlhexer)). On disk the
files are `.nif` — AIF names the format, not an extension (see [AIF](aif)). It resolves
names, checks types, picks overloads, instantiates generics, and synthesizes
lifetime hooks — **checking and lowering fused in one demand-driven pass**.

```
 .p.nif ──► aowlsem ──► .s.nif
 (parse)   (semcheck)  (typed)
```

It is ~51k lines of self-hosted Nimony (`wc -l` over `src/*.nim` and
`src/sem/*.nim`, 2026-09-09).

## Measured status

> **Correction, 2026-09-09.** From 2026-07-28 until today this page said the
> differential corpus stood at "498/498 byte-exact modules, with the entire
> `std/system` checking clean". That number was never a module count. 498 is a
> census of identical-nested `hconv` sites (oracle 527, ours 498) lifted from a
> table in aowlsem's `REQUIREMENTS.md` and mis-transcribed as a corpus score;
> the real module figure at the time was 46 of 55 byte-exact on the Linux
> `moddiff` gate. The table below is what the gates themselves print, with
> where and when each number was measured. Every number on this page carries a
> date and a source from now on; treat one without as stale.

Measured on **Windows, 2026-09-09**, at aowlsem commit `d4955d3e` — the figures
are its commit message and `COVERAGE.md`. Windows and Linux runs are **not
comparable**: module ids are content-hashed and the module sets differ, so the
Linux baselines are listed separately below rather than mixed in.

| gate | what it asserts | verdict |
|---|---|---|
| `tests/diff.sh` | corpus cases byte-exact against `nimsem` | **924 pass / 17 fail of 941**, with 0 INFRA / TIMEOUT / CRASH. 15 of the 17 are oracle-side — `nimsem` itself produces no output for the `sumtype_*` / `variant_*` cluster (an assertion inside `nifcursors.nim`) and one case is `std/posix` on a non-POSIX host. The two that are aowlsem's own are `include_fragment` and `macro_arg_infix` (15 tokens). |
| `tests/moddiff.sh --fresh` | aowlsem's own dependency closure, module by module, against the oracle's nimcache | **31 byte-exact / 21 differing / 0 rejected / 4 canonfail of 56** |
| `tests/sysdiff.sh` | all of `std/system` | **89 differing tokens** over ~92,600 canon lines. It semchecks `system` end to end; it is not yet byte-exact. |
| `tests/consteval.sh` | compile-time `const` evaluation, both executors | **19/19** byte-exact and agreeing. Two days earlier this read 0/18: the entire CTFE subsystem was inert on Windows behind six swallowed errors (commit `e2b63cf1`). |
| `tests/idxchecksum.sh` | the emitted `.s.idx.nif` checksum equals the oracle's, per module | **35/56** |
| `tests/compose.sh` | | 41/43 pairs, 86/98 indices |

When any `diff.sh` bucket is INFRA, TIMEOUT or CRASH the script prints
`DEGRADED, not a clean green` in place of a pass count — that verdict is real
and, if it is the latest one, it is the number this page should show.

Linux, as recorded in the repo: `tests/moddiff.baseline` (last re-baselined
2026-08-19) has **47 of 55** modules at zero differing tokens.

On a real program: every module of a shipping Unity game's seven mods semchecks
canon-exact at **0 differing tokens** (re-measured after each change above;
`COVERAGE.md`, 2026-09-09).

Recent fixes worth knowing about, because each was a whole missing rule rather
than a token nicety: there was no int→float widening (`floatNeedsHconv`) at all;
`defined(x)` was a hardcoded POSIX list, so on Windows every `when` took the
POSIX branch until aowlsem grew a real host/target profile (`--os:`, `--cpu:`,
`-d:` in `nimsem`'s spelling); and the CTFE revival above. A wall-clock/step
bound on compile-time evaluation (`tests/ceguard.sh`, E1000 on a runaway
`const`) is in the working tree and not yet committed at the time of writing.

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

Diagnostics are a **side channel**: they are written to stderr after the `.s.nif`
is emitted, and recording one never alters the typed output — a valid program
yields zero. There are **36 codes** in two bands: genuine **errors** the
reference compiler also rejects, and a band of advisory **opinion lints**
(E0205–E0222) that flag tautologies, no-ops and dead branches the reference
*accepts*. The full table, the rustc-grade renderer, the JSON tooling seam, and a
comparison with the reference's diagnostics are on the [Diagnostics
page](aowlsem/diagnostics).

## Usage

```sh
aowlsem m <in.p.nif> <out.s.nif> --path:<lib> --nimcache:<nc>   # semcheck a module
```

With `--path:` and `--nimcache:` set, `aowlsem m` resolves the module's whole
import graph itself — a real drop-in for `nimsem`. Full command/flag reference and
the programmatic `semcheck*` entry point are on the [CLI & API page](aowlsem/cli).

## What it checks

Everything below is checked construct by construct against the reference
compiler's own output. The `tests/corpus/` suite — 941 cases on 2026-09-09; the
verdict is in the status table above — is the concrete list. What each construct
lowers to, with worked `.p.nif → .s.nif` examples, is on the
[Lowering reference](aowlsem/lowering).

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
params. `macro` declaration and expansion by **running** the macro: its body is
lowered to a plugin module, built, and executed once per call site with the
argument trees marshalled in and the expansion read back.

#### Compile-time evaluation

A `const` initialiser, a `when` condition, an array dimension and an enum member
value are all **evaluated** when no constant fold can compute them — aowlsem
generates a module from the host's own declarations and runs it. The generated
module is a plugin exactly as a macro's is, and takes the same two executors:
interpreted under [aowli](aowli-release), or built native. See
[CLI → Compile-time evaluation](aowlsem/cli#compile-time-evaluation).

#### Modules

`import` resolution against checked `.s.nif`, including `from X import`,
`import X except` and transitive re-exports. `include` inlining. `system`
loading.

## Optimizer

`aowlsem opt` runs a high-level pass over an already-checked `.s.nif` and reports
the node count before and after. It is a **separate pass** from `m`, so semantic
output is unaffected.

## Pages

| Page | Contents |
|---|---|
| [Architecture](aowlsem/architecture) | the fused check+lower model, demand-driven engine, the nine include-fragments, `SemContext`, the prescan, and the *"can the two systems be split?"* answer |
| [Diagnostics](aowlsem/diagnostics) | side-channel design, all 36 codes in two bands (errors vs opinion lints), rustc-grade rendering, "did you mean", JSON seam, comparison to the reference |
| [CLI & API](aowlsem/cli) | `m` / `opt` / `passthrough`, flags, self-resolving imports, exit behavior, and the `semcheck*` programmatic entry |
| [Lowering reference](aowlsem/lowering) | worked `.p.nif → .s.nif` transformations for every major construct |

## Pipeline

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─► aowlc / aowljs / aowli
    source         parse       semcheck    lower        code / interpret
```

aowlsem is the typing seam: everything downstream reads the symbols, resolved
overloads and generic instances it writes into `.s.nif`. The format on both sides
is [AIF, which is NIF](aif) byte-for-byte, so the typed output is interchangeable
with the reference compiler's own.
