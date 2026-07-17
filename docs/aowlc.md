---
title: C — aowlc
parent: aowlmony
nav_order: 6
---

# aowlc — a `.c.nif` → C native backend
{: .no_toc }

`aowlc` compiles nimony's **post-`hexer`** IR (`.c.nif`) to **real C** and links it
with `gcc` to a native binary. It's the self-owned native counterpart to
[aowljs](aowljs) (the JavaScript backend) — same architecture (NIF reader +
emitter), retargeted from JS to C.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aowlc`** (public). A single dependency-free JS file that reads a
`.c.nif` and emits C, plus a CLI driver that shells `gcc`.

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## The cheat: a backend is a *printer*

You don't write a code generator. By the time nimony's `hexer` pipeline has
lowered a program to a `.c.nif`, every genuinely hard piece of compiler work is
already done and baked into the IR:

| hexer pass | what it did |
|---|---|
| `destroyer` + `duplifier` + `mover` | **ARC** — destructor calls, `=copy`/`=destroy` hooks, ref-count ops injected |
| `lambdalifting` | closures → plain functions + env structs |
| `iterinliner` | iterators inlined |
| `eraiser` | exceptions → error-code plumbing |
| generic mono + `dce` + `inliner` | generics monomorphised, dead code stripped, inlined |

What remains is a C-shaped tree with **sized types spelled out** (`(i 32)`), an
**explicit `result` var**, explicit everything. So:

> A native backend is a `.c.nif` → C printer. `hexer` already did ARC, closures,
> exceptions and monomorphisation, so the printer is mechanical and **GC is free**
> — ARC was injected upstream. C / JS / WASM are all just printers over hexer's
> output.

## The mirror image of aowljs

aowlc and [aowljs](aowljs) start from IR at **opposite ends of hexer**, and that one
choice decides everything — including fidelity:

| | **aowljs** (native JS) | **aowlc** (native C) |
|---|---|---|
| input IR | `.s.nif` — *before* lowering (`int`/`string`/`seq`/objects) | `.c.nif` — *after* hexer (pointers, ARC, sized types) |
| target | native JS values (`number`, `Array`, `{}`) | C with the real sized typedefs (`NI64`, `NU32`, `NF64`, …) |
| fidelity | native-value *approximation* — trades exactness for speed & readability | **exact** — int64 wraparound, sized ops, ARC timing all preserved |
| GC | free (V8 collects) | free (ARC baked into the IR) |
| effort | had to *invent* value mappings & worry about int-wrapping | **mechanical** — hexer already sized and ARC'd everything |

So aowlc is the **faithful native path**: because it reads the lowered IR, it
inherits exact machine-integer semantics and deterministic ARC for free — the
very fidelity aowljs gives up for JIT speed. Both are "no GC to implement," for
opposite reasons.

## Readable output

aowlc uses the real `mangleToC` and the `importc`/`exportc` extern rule, so its C
reads like the reference generator's — from the recursive-fibonacci `.c.nif`:

```c
NI64 fib_1_(NI64 n_0) {
  NI64 result_0;
  if (n_0 < 2) {
    return n_0;
  }
  NI64 X60Qx_0 = fib_1_(((NI64)(n_0 - 1)));
  NI64 X60Qx_1 = fib_1_(((NI64)(n_0 - 2)));
  result_0 = ((NI64)(X60Qx_0 + X60Qx_1));
  return result_0;
}
```

Note the `((NI64)(a - b))` casts — the **wrap-preserving** form the reference C
generator emits so sized-integer arithmetic overflows exactly as the program
means.

## Coverage

Faithful to Andreas Rumpf's own C generator (`nimony/src/lengc`) for the
**computational core**, and verified end-to-end against `.c.nif` produced by
nimony's real frontend + hexer:

- procs / funcs, parameters, recursion
- sized numeric / `char` / `bool` / pointer types
- typed arithmetic & bit-ops with the wrap-preserving cast; comparisons, `and`/`or`/`not`, `neg`, `bitnot`
- `if`/`elif`/`else`, `while`, `loop`, `scope`, `break`/`continue`
- `case` — single values, value lists, ranges (`case 10 ... 20`), `else`
- labels & `goto`, `var`/`let`/`cursor`/`const`/`gvar`, `asgn`/`store`, `ret`/`discard`
- casts / convs, suffixed literals, `sizeof`/`alignof`
- objects / unions / enums / arrays / proc-types (type declarations)
- a self-contained C prelude (`NI`/`NU`/`NF`/`NC8`/`NB8`/`NIM_TRUE`/…) — no nimony runtime needed for the core

Not yet lowered here: the full **system runtime** (strings/seqs/`echo`, GC
objects), which lives in the 54 KB `system` `.c.nif` module. Anything aowlc can't
print raises `aowlc: unsupported …`, so gaps are visible, never silently wrong.

## Verified end-to-end

Each `.c.nif` in `examples/` came out of nimony's own frontend + hexer; aowlc
emits C, `gcc` compiles it, and the native binary returns the right answer:

| program | call | native result |
|---|---|---|
| recursive fib | `fib(30)` | `832040` |
| loop sum | `sumTo(1000)` | `500500` |
| Euclid | `gcd(1071, 462)` | `21` |
| trial division | `isPrime(97)` / `isPrime(91)` | `1` / `0` |
| Collatz steps | `collatz(27)` | `111` |
| bit-twiddling (`uint32`, `and`/`shr`) | `popcount(255)` | `8` |
| float loop | `power(2.0, 10)` | `1024` |
| `case` (values/lists/ranges/else) | `classify(15)` | `300` |

`npm test` runs all 21 cases (18 harnessed procs + 3 whole-module builds).

## Usage

```sh
node bin/aowlc emit  examples/fib.c.nif                 # emit a C translation unit
node bin/aowlc run   examples/fib.c.nif                 # whole module → standalone binary → run
node bin/aowlc build examples/compute.c.nif -o /tmp/x   # native binary at a path
node bin/aowlc exec  examples/fib.c.nif --entry fib --arg 10   # → 55
```

`exec` emits only the procs (and globals) transitively reachable from the entry,
so the nimony bootstrap (`ini`/`main` and its cross-module calls into the system
runtime) is excluded and the program is fully standalone. Whole-module
`build`/`run` emits everything and generates weak no-op stubs for any unresolved
external call so the unit still links on its own.

## Pipeline

```
   nimony frontend            hexer (ARC, closures, exceptions,       aowlc
.nim ──────────────► .s.nif ──── monomorphisation, sized types) ───► .c.nif ──► C ──► gcc ──► native
```

The cleanest self-owned native compiler reuses the one component that's genuinely
hard to rebuild — hexer's lowering — and owns everything else:
[aowlparser](aowlparser) + `nifsem` → `hexer` → **aowlc** → `gcc`.
