---
title: nifjs
grand_parent: Nimony
parent: NIF Toolchain Alternatives
nav_order: 3
---

# nifjs — a `.s.nif` → native-JavaScript backend
{: .no_toc }

`nifjs` transpiles a typed nimony NIF (`.s.nif`) to **real JavaScript** — mapping
nimony values onto native JS values instead of onto a simulated linear memory —
so the browser's JIT compiles the hot loops. It runs at **near-native-JS speed**
and its output is **readable**. It's the **Native JS** engine in the
[playground](/playground/).
{: .fs-6 .fw-300 }

Repo: **`aoughwl/nifjs`** (public). A single, dependency-free JS file that reads a
`.s.nif` and emits JavaScript.

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## Two backends, one decision

Nimony reaches the web through two JavaScript emitters that operate at
**different IR levels**, and that single choice is what makes them fast-or-slow
and readable-or-mangled:

| | **[nimony-web](nimony-web)** (leng, faithful) | **nifjs** (native, fast) |
|---|---|---|
| input IR | `.c.nif` — *after* hexer lowers everything to pointers / `memcpy` / ARC | `.s.nif` — *before* lowering; still has `int` / `string` / `seq` / objects |
| values | one simulated linear memory (`ArrayBuffer` + `DataView`) | native JS (`number`, `string`, `Array`, `{}`) |
| result | **slow** (`_dv.getInt32(p)` per access) **and mangled** (`sysvq0asl`, raw offsets) | **fast** (V8 JITs it) **and readable** (`function fib(n){ … }`) |
| fidelity | exact — int64 wraparound, `ptr`/`addr`, ARC timing, C FFI | native-value approximation (see [trade-off](#the-fidelity-trade-off)) |

The key insight: **speed and readability are the same decision**. The faithful
backend is slow *and* mangled for one reason (it simulates C memory from the
lowered IR); nifjs is fast *and* readable for the mirror reason (it emits native
values from the high-level IR). You get both or neither — they are not separate
features in tension.

## Benchmark

The same tight arithmetic loop, timed per iteration:

| engine | per iteration | vs. a hand-written JS loop |
|---|---:|---:|
| native JS (hand-written) | ~2.9 ns | 1× |
| **nifjs** (transpiled) | **~2.1 ns** | **~1× — the emitted loop *is* native JS** |
| bytecode VM ([nifi](nifi)) | ~39 µs | ~15,000× slower |
| tree-walk ([nifi](nifi)) | ~61 µs | ~24,000× slower |

- **~18,000–28,000× faster** than the interpreter on compute-bound loops.
- **10,000,000 iterations in ~21 ms** — and *no out-of-memory*: nifjs has no
  fixed bump heap, so integer arithmetic doesn't allocate and the GC reclaims.
  (The interpreter's simulated heap OOMs on large allocating loops.)
- Output **byte-identical** to the interpreter on supported programs.

## Readable output

Because nifjs works from the typed IR and keeps source names, the emitted code
reads like the program you wrote — no linear memory, no `DataView`, no
content-addressed symbol hashes:

```js
function fib(n){
  if ((n < 2)) { return n; }
  return (fib((n - 1)) + fib((n - 2)));
}
function isPrime(n){
  if ((n < 2)) { return false; }
  let d = 2;
  while (((d * d) <= n)) {
    if (((n % d) === 0)) { return false; }
    (d += 1);
  }
  return true;
}
```

## Coverage and fallback

nifjs covers a **(growing) subset** of the language. On any node it doesn't
handle, the emitter throws `Unsupported(…)` and the run falls back to the
faithful [nifi](nifi) engines — so **correctness is never worse than a normal
Run**, and the playground's run footer says *which* engine ran and *why* it fell
back (e.g. `unsupported expr 'prefix'`).

Supported today: procs and recursion (incl. mutual); `int` **and** `float`
arithmetic (float `/` is kept distinct from integer `div`) and comparisons;
logical `and`/`or`/`not` **and** bitwise `and`/`or`/`xor`/`not`/`shl`/`shr`;
`if`/`elif`/`else` **and if-expressions**; `case` (statement **and** expression,
including ranges); `while` with `break`/`continue`; `for` over integer ranges
**and** over collections; `inc`/`dec`; `seq`/array literals (`@[…]`), `len`,
indexing (get/set), `add`/`pop`; **objects** (construct / field read+write) and
**tuples**; `string` concat, `$`, `len`, indexing, `ord`/`chr`; `abs`/`min`/`max`;
`echo` (float-aware); `bool` — the FizzBuzz / primes / Collatz / records-in-a-seq
class of program runs entirely on it. Growing next: `Table`/`HashSet`, object
variants, exceptions, closures, and monomorphized generics.

**Robustness.** nifjs never emits a reference to a routine it didn't build. A
call to a proc/func it can't transpile — a complex stdlib routine, an unsupported
node — makes the whole program fall back to the interpreter rather than crash on
an undefined function. Emitting each routine is best-effort and isolated, so one
un-transpilable routine only forces a fall back for programs that actually reach
it.

## The fidelity trade-off

Native values buy speed and readability by giving up **low-level fidelity**:

- `int64` wraparound and unsigned overflow — JS numbers are exact only to 2⁵³.
- bitwise/shift ops run in JS's **32-bit** space, so a mask or shift past 2³¹
  diverges (fine for the usual small-flag bit-twiddling).
- pointer arithmetic, `ptr` / `addr`, object *identity* vs value.
- precise ARC / destructor timing.
- C FFI (`importc`) — there is no C to call.
- a float printed straight from a *bare variable* may drop its `.0` (float
  literals and float *expressions* keep it).

For the overwhelming majority of Nim that is invisible; for code that leans on
exact machine-integer overflow or pointer identity it diverges. That is exactly
why nimony keeps hexer and the faithful backend — the two emitters are
**complementary, not a replacement**:

- **[nimony-web](nimony-web) / leng (faithful)** builds the playground's own
  engine bundles, runs anything, and preserves exact semantics.
- **nifjs (native)** is the fast, readable path for user programs, with the
  interpreter as its safety net.

> **Want the *true faithful* version?** The exact, semantics-preserving compile —
> `int64`, pointers, ARC, the works — is **done end-to-end for both JavaScript
> *and* WebAssembly**. If you want access, DM me on Discord: **timbuktu_guy**.
{: .note }

See the [playground](/playground/) to switch engines and compare.
