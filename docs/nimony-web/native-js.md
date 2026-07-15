---
title: Native JS backend
parent: nimony-web
grand_parent: Backends
nav_order: 6
---

# Native JS (`nifjs`) — the fast, readable path
{: .no_toc }

`nifjs` transpiles a typed `.s.nif` to **real JavaScript** — mapping nimony
values onto native JS values instead of onto a simulated linear memory — so the
browser's JIT compiles the hot loops. It runs at **near-native-JS speed** and
its output is **readable**. It powers the **Native JS** engine in the
[playground](/playground/).
{: .fs-6 .fw-300 }

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## Two backends, one decision

Nimony reaches the web through two JavaScript emitters that operate at
**different IR levels**, and that single choice is what makes them fast-or-slow
and readable-or-mangled:

| | **nimony-web** (leng, faithful) | **nifjs** (native, fast) |
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
| bytecode VM (nifi) | ~39 µs | ~15,000× slower |
| tree-walk (nifi) | ~61 µs | ~24,000× slower |

- **~18,000–28,000× faster** than the interpreter on compute-bound loops.
- **10,000,000 iterations in ~21 ms** — and *no out-of-memory*: nifjs has no
  fixed bump heap, so integer arithmetic doesn't allocate and the GC reclaims.
  (The interpreter's simulated heap OOMs on large allocating loops.)
- Output **byte-identical** to the interpreter on supported programs (verified on
  the playground's default demo: `fib` / `isPrime` / `collatz`).

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

nifjs deliberately covers a **subset** of the language and grows outward. On any
node it doesn't handle, the emitter throws `Unsupported(…)` and the run falls
back to the faithful nifi engines — so **correctness is never worse than a normal
Run**, and the playground's run footer says *which* engine ran and *why* it fell
back (e.g. `unsupported expr 'prefix'`).

Supported today: procs and recursion; `int`/`float` arithmetic and comparisons;
`if`/`elif`/`else` and `case` (statement **and** expression, including ranges);
`while`; `for` over integer ranges **and** over collections; `inc`/`dec`;
`seq`/array literals (`@[…]`), `len`, indexing, `add`; `string` concatenation and
`$`; `echo`; `bool`. That's enough for the whole FizzBuzz / primes / Collatz /
seq-building class of program. Growing next: `Table`/`HashSet`, objects / tuples
/ variants, exceptions, closures, and monomorphized generics — each step widens
what runs native-fast before falling back.

## The fidelity trade-off

Native values buy speed and readability by giving up **low-level fidelity**:

- `int64` wraparound and unsigned overflow — JS numbers are exact only to 2⁵³.
- pointer arithmetic, `ptr` / `addr`, object *identity* vs value.
- precise ARC / destructor timing.
- C FFI (`importc`) — there is no C to call.

For the overwhelming majority of Nim that is invisible; for code that leans on
exact machine-integer overflow or pointer identity it diverges. That is exactly
why nimony keeps hexer and the faithful backend — so the two emitters are
**complementary, not a replacement**:

- **nimony-web / leng (faithful)** builds the playground's own engine bundles,
  runs anything, and preserves exact semantics.
- **nifjs (native)** is the fast, readable path for user programs, with the
  interpreter as its safety net.

> **Want the *true faithful* version?** The exact, semantics-preserving compile —
> `int64`, pointers, ARC, the works — is **done end-to-end for both JavaScript
> *and* WebAssembly**. If you want access, DM me on Discord: **timbuktu_guy**.
{: .note }

See the [playground](/playground/) to switch engines and compare.
