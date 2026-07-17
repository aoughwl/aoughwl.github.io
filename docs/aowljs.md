# aowljs — a `.s.nif` → native-JavaScript backend

`aowljs` transpiles a typed nimony NIF (`.s.nif`) to **real JavaScript** — mapping
nimony values onto native JS values instead of onto a simulated linear memory —
so the browser's JIT compiles the hot loops. It runs at **near-native-JS speed**
and its output is **readable**. It's the **Native JS** engine in the
[playground](https://aoughwl.github.io/playground/).

Repo: **`aoughwl/aowljs`** (public). A single, dependency-free JS file that reads a
`.s.nif` and emits JavaScript.

[[toc]]

---

## Two backends, one decision

Nimony reaches the web through two JavaScript emitters that operate at
**different IR levels**, and that single choice is what makes them fast-or-slow
and readable-or-mangled:

| | **[aowlweb](aowlweb)** (leng, faithful) | **aowljs** (native, fast) |
|---|---|---|
| input IR | `.c.nif` — *after* hexer lowers everything to pointers / `memcpy` / ARC | `.s.nif` — *before* lowering; still has `int` / `string` / `seq` / objects |
| values | one simulated linear memory (`ArrayBuffer` + `DataView`) | native JS (`number`, `string`, `Array`, `{}`) |
| result | **slow** (`_dv.getInt32(p)` per access) **and mangled** (`sysvq0asl`, raw offsets) | **fast** (V8 JITs it) **and readable** (`function fib(n){ … }`) |
| fidelity | exact — int64 wraparound, `ptr`/`addr`, ARC timing, C FFI | native-value approximation (see [trade-off](#the-fidelity-trade-off)) |

**Speed and readability are the same decision.** The faithful
backend is slow *and* mangled for one reason (it simulates C memory from the
lowered IR); aowljs is fast *and* readable for the mirror reason (it emits native
values from the high-level IR). You get both or neither — they are not separate
features in tension.

## Benchmark

The same tight arithmetic loop, timed per iteration:

| engine | per iteration | vs. a hand-written JS loop |
|---|---:|---:|
| native JS (hand-written) | ~2.9 ns | 1× |
| **aowljs** (transpiled) | **~2.1 ns** | **~1× — the emitted loop *is* native JS** |
| bytecode VM ([aowli](aowli)) | ~39 µs | ~15,000× slower |
| tree-walk ([aowli](aowli)) | ~61 µs | ~24,000× slower |

- **~18,000–28,000× faster** than the interpreter on compute-bound loops.
- **10,000,000 iterations in ~21 ms** — and *no out-of-memory*: aowljs has no
  fixed bump heap, so integer arithmetic doesn't allocate and the GC reclaims.
  (The interpreter's simulated heap OOMs on large allocating loops.)
- Output **byte-identical** to the interpreter on supported programs.

## Readable output

Because aowljs works from the typed IR and keeps source names, the emitted code
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

aowljs covers a **(growing) subset** of the language. On any node it doesn't
handle, the emitter throws `Unsupported(…)` and the run falls back to the
faithful [aowli](aowli) engines — so **correctness is never worse than a normal
Run**, and the playground's run footer says *which* engine ran and *why* it fell
back (e.g. `unsupported expr 'prefix'`).

Coverage is broad — aowljs runs essentially all of the language nimony can
currently express: procs and recursion (mutual **and nested**); **generic**
instances (monomorphised); `int` **and** `float` arithmetic (float
`/` kept distinct from `div`) and comparisons; logical **and** bitwise
`and`/`or`/`xor`/`not`/`shl`/`shr`; `if`/`elif`/`else` **and if-expressions**;
`case` (statement **and** expression, ranges, string selectors); `while` with
`break`/`continue`; `for` over ranges, collections, `countdown`, and `for i, x in`
pairs; `inc`/`dec`; `const`, **enums** (→ ordinals), `when`, `discard`;
`seq`/array literals, `len`, indexing (get/set), index-store, `newSeq(n)`,
`add`/`pop`; **objects** (construct / field read+write, incl. through a seq),
object **variants**, and **tuples** (construct / access / unpack); `string`
concat, `add`, `$`, `len`, indexing, relational (`==`/`<`/`>`/…), slicing
(`s[a..b]`/`s[a..<b]`), `ord`/`chr`; imported user modules (dependency-first);
`echo` (float-aware); `bool`. User procs named like a builtin (`add`, `len`, …)
emit real calls — magic dispatch is gated on symbol origin, not name. (Beyond
aowljs's reach — `Table`/`HashSet`, `try`/`except` — don't yet compile in nimony
either.) Also lowered to native JS: `ref object` (object reference + field mutate,
`== nil` → `=== null`; ARC/RTTI hooks dropped under GC), inheritance (`object of`,
base fields flattened, upcast = identity), custom `iterator`s → generators
(`function*`/`yield`/`for..of`), and closures → inline arrow functions (lexical
capture).

Against the shared differential corpus (`aowlhl/corpus`, 44 programs diffed vs
native nimony) aowljs sits at **41/44 fast, 43/44 faithful**; `tests/run_faithful.sh`
is **5/5**. (Float values print with a trailing `.0` — `echo`/`$` consult a static
float-type environment, including tuple float elements.)

Plus **enums** (values → ordinals), **const**, fixed-size **arrays**, and a
**shim registry**.

### Shims — the FFI / `importc` path

When a called routine isn't one aowljs built itself, and a *shim* exists, aowljs
emits the native-JS equivalent directly — no body to transpile, no marshaling.
The registry maps stdlib / `importc` proc names to JS: `math.*` → `Math.*`,
`strutils.*` → `String`/`Array` methods (`toUpperAscii`, `strip`, `split`,
`repeat`, `contains`, …), `parseInt`/`parseFloat`, `abs`/`min`/`max`. A user proc
of the same name always wins. This is how aowljs "allows `importc`": an `importc`
proc has no transpilable body, so it resolves through the shim table (or, with a
registered shim, a `console.log`-style call to a provided JS function).

### Robustness & safety

aowljs never emits a reference to a routine it didn't build. A call to a proc/func
it can't transpile makes the program fall back to the interpreter rather than
crash on an undefined function. And a `var`/`out` parameter — whose mutation
can't round-trip through JS's pass-by-value — drops the routine so its callers
fall back too, rather than run silently wrong. Emitting each routine is
best-effort and isolated, so one un-transpilable routine only forces a fall back
for programs that actually reach it.

## The fidelity trade-off

Native values buy speed and readability by giving up **low-level fidelity**:

- `int64` wraparound and unsigned overflow — JS numbers are exact only to 2⁵³.
  *(This one is opt-out: `--faithful` mode fixes it — see [export modes](#faithfulness--export-modes) below.)*
- bitwise/shift ops run in JS's **32-bit** space, so a mask or shift past 2³¹
  diverges (fine for the usual small-flag bit-twiddling).
- pointer arithmetic, `ptr` / `addr`, object *identity* vs value.
- precise ARC / destructor timing.
- C FFI (`importc`) — there is no C to call.

For the overwhelming majority of Nim that is invisible; for code that leans on
exact machine-integer overflow or pointer identity it diverges. That is exactly
why nimony keeps hexer and the faithful backend — the two emitters are
**complementary, not a replacement**:

- **[aowlweb](aowlweb) / leng (faithful)** builds the playground's own
  engine bundles, runs anything, and preserves exact semantics.
- **aowljs (native)** is the fast, readable path for user programs, with the
  interpreter as its safety net.

> **Want the *true faithful* version?** The exact, semantics-preserving compile —
> `int64`, pointers, ARC, the works — is **done end-to-end for both JavaScript
> *and* WebAssembly**. If you want access, DM me on Discord: **timbuktu_guy**.

## Faithfulness / export modes

`aowljs` has two output modes. The default is **fast mode**; `--faithful` opts
into a numerically exact one. Fast mode stays the default because its output is
the most idiomatic and the fastest — most programs never touch the boundary
where it diverges.

| | fast mode (default) | `--faithful` |
|---|---|---|
| every nimony int | JS `number` | 64-bit → `bigint`, narrower → `number` |
| exact past 2^53 | **no** (silently rounds) | **yes** |
| int64 / uint64 overflow | wrong (no wrap) | wraps (two's complement) |
| speed / readability | fastest, cleanest | a touch heavier (bigint ops) |

### Why fast mode is silently wrong

JS `number` is an IEEE-754 double: it holds integers exactly only up to 2^53.
A nimony `int64` past that rounds, and `int64`/`uint64` arithmetic never wraps.
Compile this with nimony and with each mode:

```nim
var a: int64 = 9223372036854775807'i64   # INT64_MAX
echo a
echo a + 1'i64                            # wraps to INT64_MIN
var u: uint64 = 18446744073709551615'u64  # UINT64_MAX
echo u
```

| line | nimony (reference) | `--faithful` | fast mode |
|---|---|---|---|
| `a` | `9223372036854775807` | `9223372036854775807` ✅ | `9223372036854776000` ❌ |
| `a + 1` | `-9223372036854775808` | `-9223372036854775808` ✅ | `9223372036854776000` ❌ |
| `u` | `18446744073709551615` | `18446744073709551615` ✅ | `18446744073709552000` ❌ |

Faithful mode is **byte-for-byte identical to native nimony**; fast mode is off
by hundreds and never wraps.

### The design: native `bigint`, zero dependencies

JS has had `BigInt` as a language primitive since ES2020 — it works in Node,
Deno and the browser with **no addon and no import**. Its operators are the
ordinary ones (`a + b`, `a < b`, `a === b`), and its `/` and `%` **truncate
toward zero exactly like Nim integer division**. Faithful mode leans on that:

- **64-bit types → `bigint`.** A `bigint` literal carries the `n` suffix
  (`123n`); the emitter threads a "want-bigint" context so every literal in a
  64-bit position is emitted as `bigint` (JS throws on mixing `5n + 5`). A
  bigint local's default value is `0n`.
- **Width wrapping.** 64-bit `add`/`sub`/`mul`/`shl` and the bitwise ops (and
  unary `neg`/`bitnot`) are wrapped with the built-in `BigInt.asIntN(64, x)`
  (signed) / `asUintN(64, x)` (unsigned) — that is exactly Nim's two's-complement
  wrap-around. Comparisons and `>>`/arithmetic-shift-right stay bare.
- **Division.** `div` → `_idiv(a, b)`, `mod` → `_imod(a, b)` — bigint `/` and `%`
  already truncate toward zero, so the helpers only add the Nim `DivByZero` check.
- **Crossing widths.** A `number` value entering a 64-bit position is coerced
  `BigInt(x)` (a float first `BigInt(Math.trunc(x))`); a `bigint` used where a
  `number` is needed — array indices, narrower ints — is coerced `Number(x)`.
- **`echo`.** A `bigint` prints through `String(x)`, i.e. `5n` renders `5`, not
  `5n` — output matches nimony with no special-casing.

### Runtime helpers

Faithful mode needs four tiny helpers. They are **inlined into the emitted
program's prelude**, so the emitted file still runs standalone with no import:

```js
const _i64  = (x) => BigInt.asIntN(64, x);
const _u64  = (x) => BigInt.asUintN(64, x);
const _idiv = (a, b) => { if (b === 0n) throw new Error("DivByZero"); return a / b; };
const _imod = (a, b) => { if (b === 0n) throw new Error("DivByZero"); return a % b; };
```

The same four are also exported from **`runtime/aowl-rt.js`** for real projects
that prefer to `import` one shared copy rather than rely on the inlined prelude.

### Invoking it

```sh
bin/aowljs --faithful /tmp/nc/<mainhash>.s.nif > prog.js
node prog.js
```

`tests/run_faithful.sh` compiles each `tests/faithful/*.nim` with nimony for the
reference stdout, transpiles it with `--faithful`, runs the emitted `.js` under
node, and diffs — **byte-exact** — while also showing that fast mode gets the same
programs wrong (the whole point). Suite: `overflow` (INT64_MAX / MIN, UINT64_MAX),
`modmul` (products past 2^53 in a modular loop), `divmod` (truncating `div`/`mod`,
signed and unsigned).

### Boundary — what faithful mode does *not* fix

Faithful mode is about **numeric** faithfulness. Two other faithfulness axes are
deliberately out of scope, and for them the machine-faithful
[aowlweb](aowlweb) backend (linear memory) is the honest answer:

- **Value semantics.** Nim copies `object`/`tuple`/`seq` values on assignment and
  argument passing; the native-JS emitter shares references (like fast mode).
  Deep-copy-on-assign is a separate, future axis of faithfulness.
- **Raw pointers, `addr`, `cast`, manual memory, pointer arithmetic.** These have
  no honest idiomatic-JS representation. If a program depends on them, use
  [aowlweb](aowlweb), whose linear-memory model *is* the faithful answer for
  pointer-level code.

One honest numeric edge: faithful mode implements **wrapping** two's-complement
arithmetic (`_i64`/`_u64` around every 64-bit result), not Nim's *checked*
integer defects. So negating `INT64_MIN`, or an `add` that overflows, wraps
silently instead of raising an `OverflowDefect` — matching what nimony emits with
runtime overflow checks off (its default here, byte-exact), and what hardware
does. A build that raises overflow defects is a possible future refinement.

See the [playground](https://aoughwl.github.io/playground/) to switch engines and compare.
