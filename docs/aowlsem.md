# aowlsem — the semantic-analysis stage

`aowlsem` is the semantic checker of the aoughwl toolchain. It reads the parse
dialect of AIF (`.p.aif`, as produced by [aowlparser](aowlparser)) and writes
typed, symbol-resolved AIF (`.s.aif`) ready for the lowering stage
([aowlhexer](aowlhexer)). It resolves names, checks types, picks overloads, and
instantiates generics.

Source: **[github.com/aoughwl/aowlsem](https://github.com/aoughwl/aowlsem)**

```
 .p.aif ──► aowlsem ──► .s.aif
 (parse)   (semcheck)  (typed)
```

## Model

Demand-driven. There is no global multi-phase walk over the module. Every
semantic fact — a symbol's type, an overload choice, a generic instance — is
computed on demand and memoised, so a construct is checked exactly when another
construct needs its result. Forward references and mutual recursion at module
scope need no forward declarations.

Built on the `nifcore` cursor stack, so tree traversal uses fast `skip` over the
AIF token buffer rather than materialising nodes.

## Diagnostics

A semantic error does not stop the check. aowlsem records a structured
diagnostic and continues, so one run reports every independent error in the
module rather than only the first.

Each diagnostic carries a stable code, the source span from the AIF line info,
and optional follow-up notes. The rendering shows the offending source line with
a caret under the exact span, and — where a name is misspelt — the closest
identifier actually in scope, by edit distance:

```
error[E0300]: undeclared field `zz` on `Point`
  --> app.nim:9:8
   |
 9 | echo p.zz
   |        ^^
   = did you mean `x`?
```

Diagnostics are written to stderr after the `.s.aif` is emitted, so they are a
side channel: the typed output is identical whether or not a diagnostic fired.

Current codes:

| Code | Meaning |
|---|---|
| `E0100` | undeclared identifier (with an in-scope suggestion) |
| `E0101` | undeclared routine (with an in-scope suggestion) |
| `E0200` | type mismatch — a declared or assigned-to type the value cannot satisfy |
| `E0300` | undeclared field on a known object type (with a field suggestion) |

## Build

```sh
nimony c --base:src -d:nimony src/aowlsem.nim
# or:
./build.sh          # writes bin/aowlsem  (override compiler with NIMONY=…)
```

## Usage

```sh
aowlsem m <in.p.aif> <out.s.aif> [flags]     # semcheck a module
aowlsem opt <in.s.aif> <out.s.aif>           # run the high-level optimizer
aowlsem passthrough <in.aif> [out.aif]       # load + re-emit (smoke test)
```

`-` or an empty output path writes to stdout. Diagnostics go to stderr after a
complete `.s.aif` is written, so tooling still gets a usable artifact when a
module has errors.

### Flags for `m`

| Flag | Meaning |
|---|---|
| `--sys:<system.s.aif>` | Supply the checked `system` module explicitly. |
| `--imp:<module.s.aif>` | Add an already-checked imported module (repeatable). |
| `--path:<dir>` / `-p:<dir>` | Add a module search path (repeatable). |
| `--nimcache:<dir>` | Where the driver placed the parsed `.p.aif` inputs (defaults to the input's directory). |
| `--noSystem` | Do not auto-load `system`. |

With `--path:` and `--nimcache:` set, `aowlsem m` resolves the module's own
import graph: it reads the module's `.p.deps.aif`, auto-loads `system` and each
imported module's already-checked `.s.aif`, and inlines every `include` into one
flat module before checking. Explicit `--sys:`/`--imp:` override the auto-loaded
choices.

## Capabilities

Checked construct-by-construct. The `tests/corpus/` suite (166 modules) is the
concrete list of what is supported; the categories below summarise it. The
frontier is tracked in `COVERAGE.md`.

**Declarations & bindings**
: `let` / `var` / `const` (global and local); type inference from literals,
in-scope identifiers, calls and operators; explicit-type bindings; typed
constants (`(suf v "i64")`); compile-time constant folding of integer
arithmetic; multi-assignment; tuple unpacking in `let`/`var`.

**Types**
: `int`/`float`/`bool`/`char`; sized-int aliases (`int8`, `uint`, `int64`,
`byte` → `(i N)`/`(u N)`); `string`; `array[N,T]` with indexing, `len`, `high`,
`low`; `seq[T]` with `@[]`, indexing, index-assign, `len`, iteration, `add`;
tuples (positional and named); `distinct` types and conversions; `enum`
declarations (with the synthesized `$`); `set` operations; `HSlice` (`a ..< b`);
`ptr`/pointer casts; `sizeof`.

**Operators & conversions**
: arithmetic `+ - * div mod` and float `/`; bitwise `and`/`or`/`xor`, shifts
`shl`/`shr`; comparisons `< <= == > >= !=`; boolean `and`/`or`/`not`; unary `-`,
`abs`; compound assignment (`+=` etc.); `ord`, `succ`/`pred`, `$`, int/float
conversions; string concatenation, equality, indexing and index-assign,
iteration.

**Control flow**
: `if`/`elif`/`else` (statement and expression); `case`/`of`/`else` including
range branches (statement and expression); `while`; `for` over ranges,
sequences and strings; `break`/`continue`; labelled `block`; `defer`;
`try`/`except`/`finally` and `except T as e`; `return` (explicit, bare, void);
`when`/`elif`/`else` folded at compile time (`defined`, `x is T`, `typeof`).

**Routines**
: procs with parameters, return types and implicit `result`; overload
resolution by arity and by parameter type; `var` parameters (`(mut T)` +
auto-deref); named arguments; UFCS calls (with and without parens); operator
definitions; recursion, mutual recursion and nested procs; forward references;
procs as values; `importc` procs.

**Generics**
: generic routine declarations and instantiation (inference and explicit type
arguments); generic `object` type declarations and instantiation; instantiation
of imported generics; nested instantiation inside instantiated bodies; instance
memoisation.

**Objects, ref & inheritance**
: `object` declarations, field access, assignment, nesting, object params and
returns, default fill and empty construction; `ref object`; object and `ref`
inheritance across multiple levels; `method` declarations with dynamic dispatch
and overrides.

**Templates & macros**
: `template` expansion (inline substitution of arguments into the body);
`macro` declarations and expansion, including compile-time evaluation.

**Modules**
: `import` resolution against already-checked `.s.aif`; `include` inlining;
loading `system` so builtin routines and types (`string`, `&`, `$`, …) resolve.

## Optimizer

`aowlsem opt` runs a high-level pass over an already-checked `.s.aif` and reports
the node count before and after. It is separate from `m`, so semantic output is
unaffected.

## Pipeline

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─► aowlc / aowljs / aowli
    source         parse       semcheck    lower        code / interpret
```

aowlsem is the typing seam: everything downstream reads the symbols, resolved
overloads and generic instances it writes into `.s.aif`.
