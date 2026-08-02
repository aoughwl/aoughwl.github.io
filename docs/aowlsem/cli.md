# CLI & API

The `aowlsem` command-line surface and the programmatic `semcheck*` entry point.

[[toc]]

---

## Commands

```sh
aowlsem m <in.p.aif> <out.s.aif> [flags]     # semcheck a module
aowlsem opt <in.s.aif> <out.s.aif>           # run the high-level optimizer
aowlsem passthrough <in.aif> [out.aif]       # load + re-emit (smoke test)
```

`-` or an empty output path writes to **stdout**. Diagnostics are written to
**stderr** *after* a complete `.s.aif` has been emitted, so downstream tooling
still receives a usable artifact even when a module has errors — see
[Diagnostics](diagnostics).

### `m` — semcheck a module

Reads parse-dialect AIF (`.p.aif`, from [aowlparser](../aowlparser)) and writes
typed AIF (`.s.aif`) ready for [aowlhexer](../aowlhexer).

| Flag | Meaning |
|---|---|
| `--sys:<system.s.aif>` | Supply the checked `system` module explicitly. |
| `--imp:<module.s.aif>` | Add an already-checked imported module (repeatable). |
| `--path:<dir>` / `-p:<dir>` | Add a module search path (repeatable). |
| `--base:<dir>` | The project base directory (for path-relative module resolution). |
| `--nimcache:<dir>` | Where the driver placed the parsed `.p.aif` inputs (defaults to the input's directory). |
| `--noSystem` | Do not auto-load `system`. |
| `--diagnostics:json` | Emit diagnostics as a JSON array (see [Diagnostics → JSON](diagnostics#json-output--the-tooling-seam)). |
| `--macros:<mode>` | How a compile-time plugin is executed — `auto` (default), `interp`, `compiled`, `off`. Append `,verbose` to report each step. |
| `--ceDepth:<n>` | Internal. How many const-evaluator generations deep this process is; aowlsem sets it on the child it spawns. Not for hand use. |

#### Compile-time evaluation

Two things run during a check, and they are the same kind of program: a **macro
expansion** and a **`const` evaluator**. Both are generated modules, built from
the host module's own declarations, and both are selected by `--macros:`.

| Mode | What runs the plugin |
|---|---|
| `auto` | Interpret it; fall back to a native build if that fails. |
| `interp` | Semcheck the generated module to `.s.aif` and run it under [aowli](../aowli-release). Nothing is linked, so this is the cheap path — and the only one available before a native toolchain exists. |
| `compiled` | Build a host-native binary. |
| `off` | No plugins: the shape matcher and the constant folds alone. |

A value no fold can compute is **evaluated** rather than matched. aowlsem
generates a module carrying the declarations preceding the value, runs it, and
folds what comes back through `std/writenif` — the serializer emits the AIF atom
exactly, where `echo` would render it for a human and lose float digits.

Evaluated contexts, and what each would otherwise emit:

| Context | Without evaluation |
|---|---|
| `const` initialiser (module level or inside a routine) | the call, inside the `(suf … "i64")` wrapper that promises a literal |
| `when` condition | the `else` branch — an unknown condition is not a false one |
| array dimension — `array[sz(), int]` | a call inside a type, where the form needs a literal bound |
| enum member value — `b = v()` | the auto-increment ordinal |

Scalars (`int`, `float`, `bool`, `string`) return one atom. Aggregates return
their members: an array is read by index, a `seq` by looping to `len` (its length
is not known before it runs), an object by field name; the caller rebuilds the
`(aconstr …)` / `(oconstr …)`, because it holds the type and the generated module
cannot spell it. A member count that does not match is a failure, not a partial
fold.

#### Self-resolving imports

With `--path:` and `--nimcache:` set, `aowlsem m` resolves the module's **entire
import graph itself** — it is a real drop-in for the reference `nimsem`, not a
stage that needs its dependencies spoon-fed:

1. reads the module's `.p.deps.aif`,
2. auto-loads `system` and each imported module's already-checked `.s.aif`
   (following `from X import`, `import X except`, and re-exports transitively
   across the whole closure),
3. inlines every `include` into one flat module,
4. checks.

Explicit `--sys:` / `--imp:` override the auto-loaded choices.

```sh
# resolves the whole graph on its own:
aowlsem m app.p.aif app.s.aif --path:$LIB --nimcache:$NC
```

### `opt` — high-level optimizer

Runs a pass over an already-checked `.s.aif` (`optcore.nim`) and reports the node
count before and after. It is **separate from `m`** — semantic output is
unaffected by it.

### `passthrough` — load + re-emit

Loads an AIF buffer and writes it back unchanged. A smoke test for the AIF
round-trip; no checking.

## Exit behavior

The typed `.s.aif` is written **first**, then diagnostics to stderr. Only genuine
**errors** (not the advisory opinion lints) set a failing exit code — matching
the reference compiler, so `aowlsem` slots into a build that keys off the exit
status while still emitting a usable artifact for tooling on the error path.

## Build

```sh
nimony c --base:src -d:nimony src/aowlsem.nim
# or:
./build.sh          # writes bin/aowlsem  (override the compiler with NIMONY=…)
```

`build.sh` exits 0 even on a compile failure — grep its output for `error:` /
`built` rather than trusting the exit code.

## Programmatic API

The engine's public entry is `semcheck*` (in `sem/module`):

```nim
proc semcheck*(input: var TokenBuf; sysBuf: var TokenBuf; sysSuffix: string;
               modSuffix = ""; impBufs: var seq[TokenBuf];
               impSuffixes: seq[string] = @[];
               impModNames: seq[string] = @[]): TokenBuf
```

- **`input`** — the parsed `.p.aif` buffer to check.
- **`sysBuf` / `sysSuffix`** — an already-parsed `system` module whose exported
  types register in an outer scope (an empty suffix means "no system").
- **`modSuffix`** — this module's mangle suffix (its content-addressed module
  id), baked into the symbols it defines.
- **`impBufs` / `impSuffixes` / `impModNames`** — parallel arrays of the
  already-checked imported modules, their suffixes, and their source names.
- **returns** — the semchecked `.s.aif` as a `TokenBuf`.

The output **shares the input's pools**, so subtrees copied from the parse form
(a template body, a generic instance) keep their interned string/tag ids and the
result serializes without a re-intern pass.

The CLI's `m` command is a thin wrapper: it resolves the deps graph, loads each
buffer, calls `semcheck*`, writes the result, then renders diagnostics.

## AIF on both sides

Input and output are both [AIF, which is NIF](../aif) byte-for-byte — the parse
dialect (`.p.aif`) in, the semchecked dialect (`.s.aif`) out. The typed output is
interchangeable with the reference compiler's own `nimsem` output, which is what
makes the byte-exact differential test possible.
