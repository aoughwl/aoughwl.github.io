---
repo: aoughwl/aowlmony
---

# aowlmony — the nimony rewrite driver

> ▶️ **[Try `aoughwl/aowlmony` live in the Playground](https://aoughwl.github.io/playground/#clone=aoughwl/aowlmony)** — clones the repo into the in-browser IDE, no install.

`aowlmony` is the driver that unifies the aoughwl self-owned stack into one
compiler over **AIF** (the aowl intermediate format): give it a `.nim` file and
it runs parser → sem → lowering → **your choice of native code or
interpretation**, using aoughwl's own components wherever they exist and reusing
nimony's only for the parts not yet rebuilt.

[[toc]]

---

## Manager + driver — `aowlup : aowlmony`

The interface splits into two tools, modelled on **`rustup` : `cargo`**:

- **[aowlup](aowlup)** *manages the toolchain* — installs, versions, and *selects*
  the components (parser/sem/hexer/backends/LSP), writing its choice to a registry
  at `~/.aowl`.
- **`aowlmony`** *compiles your code* — it reads that registry and runs the
  selected components. It never installs anything.

The seam is one-directional: **aowlup writes the registry, aowlmony reads it.**
Which implementations run is therefore a property of the active *profile* —
`aowl` (all ours), `nimony` (all nimony), or `hybrid` (ours parser + nimony sem +
ours hexer, the default). Switch it with `aowlup profile use <name>`, or override
one build with rustup-style `+profile` syntax:

```sh
aowlmony run foo.nim            # compile with whatever aowlup selected
aowlmony +nimony run foo.nim    # compile once with the all-nimony stack
```

> **Profiles only exist if aowlup is installed.** `aowlmony` reads the profile
> by asking `aowlup config` (it looks for `~/aowlup/bin/aowlup`, then
> `~/.aowl/bin/aowl`). On a machine without either, the registry read returns
> nothing, the profile is `hybrid`, and `+aowl` / `+nimony` / `aowlup profile
> use` are **silent no-ops** — the `+profile` prefix only sets `AOWL_PROFILE`
> in the environment, and nothing but aowlup reads it. Use the `AOWLMONY_*`
> environment variables (`AOWLMONY_SEM=aowlsem`, `AOWLMONY_NIFPARSER=…`,
> `AOWLMONY_HEXER=…`) to select components directly in that case, and check
> with `-v`, which reports what actually ran rather than what was asked for.
> (Source: `loadStack()` / `resolveTools()` in `bin/aowlmony`, 2026-09-09.)

The **parser** (`aowlparser` vs `nifler`) and **lowering** (`aowlhexer` vs nimony
`hexer`) are swapped in through nimony's tool-resolution seam, so the active
profile genuinely controls them — `aowlmony +aowl run f.nim -v` reports *parsed by
aowlparser · lowering via aowlhexer*, `+nimony` reports *nifler · nimony hexer*.
Backends resolve from the registry.

**The sem slot.** This page used to say `sem=aowlsem` fell back to `nimsem`
because "aowlsem can't yet semcheck `std/system`" and "doesn't emit the
`.s.idx.nif` index". Neither has been true since 2026-08-14/16: aowlsem
semchecks all of `std/system` (its `sysdiff` gate, 89 differing tokens over
~92,600 lines on 2026-09-09) and writes the `.s.idx.nif` index (its
`idxchecksum` gate), and aowlmony commit `80f2a0c` (2026-08-14) closed the three
argv incompatibilities that had produced "43 errors on a five-line program" —
they were the driver's, not the checker's. Selecting `sem=aowlsem` (or
`AOWLMONY_SEM=aowlsem`) now stages a `nimsem` shim that routes `m` to aowlsem and
keeps real `nimsem x` as the mechanical indexer, and the cache key records that it
did. What is still true: the **default** sem is `nimsem` — the registry's
default has not flipped, and `hybrid` means *ours parser + nimony sem + ours
hexer*. See [Windows](#windows) for the one platform where the shim cannot run.

## The pipeline

```
   .nim ──► aowlparser (ours) ──► nimony sem (default) ──► aowlhexer (ours) ──► .s.nif / .c.nif
                                                                               │        │
                                        aowli (ours) ◄── interpret ────────────┘        └──► aowlc (ours) ──► C ──► gcc ──► native
```

## Ours vs reused — the honest map

| stage | tool | owned? |
|---|---|---|
| parse `.nim` → `.p.nif` (user modules) | [aowlparser](aowlparser) | ✅ ours |
| parse stdlib → `.p.nif` | `nifler` | reused — aowlparser has `concept`/typed-nil gaps |
| sem `.p.nif` → `.s.nif` | nimony `nimsem` by default; [aowlsem](aowlsem) with `sem=aowlsem` | ✅ ours is selectable (since 2026-08-14); the default has not flipped |
| **lower** `.s.nif` → `.c.nif` (ARC, closures, exceptions, mono) | **[aowlhexer](aowlhexer)** | ✅ **ours** (seeded from Araq's hexer) |
| **native** `.c.nif` → binary | [aowlc](aowlc) → gcc | ✅ ours |
| **interpret** `.s.nif` | [aowli](../aowli) (tree-walk + bytecode VM) | ✅ ours |
| web `.s.nif` → JS | [aowljs](aowljs) | ✅ ours |
| idiomatic `.s.nif` → TS / Py / JS | [aowlts](aowlts) / [aowlpy](aowlpy) / [aowljs](aowljs) | ✅ ours |

## Idiomatic source export

Beyond native/interpret, the driver emits **readable source** in another language:

```
aowlmony ts prog.nim [--faithful] [--run]   # → prog.ts (idiomatic TypeScript)
aowlmony py prog.nim [--run]                # → prog.py (idiomatic Python)
aowlmony js prog.nim [--faithful] [--run]   # → prog.js (native-JS)
```

Each lowers `.nim → sem → .s.nif` and hands it to the matching backend. Output is
hand-written-looking source, not a machine simulation; `--run` executes it and its
stdout matches `nimony c -r` byte-for-byte (verified end-to-end). `--faithful`
(ts/js) maps 64-bit ints to `BigInt` for exact int64/uint64 semantics — see the
per-backend pages for the fast/faithful trade-off.

The self-owned stack now covers **parser + lowering + backend + interpreter**,
and semantic analysis on request — the default profile still reuses nimony's
`nimsem` until the registry default flips to [aowlsem](aowlsem). Lowering moved
into our column with [aowlhexer](aowlhexer): the aowlmony
driver injects `bin/aowlhexer` in place of nimony's `hexer` (via nimony's
`findTool("hexer")` lookup), so a full build reads
`.nim → aowlparser → sem → aowlhexer → aowlc → gcc`.

Provenance is verifiable: aowlparser stamps `(.vendor "aowlparser")` into the
`.p.nif` it produces, and `aowlmony nif prog.nim -v` reports *which* parser and
*which* hexer ran. Since 2026-09-08 the cache key also folds in which components
*actually resolved*, not which were requested: before that, a run whose
`sem=aowlsem` had silently fallen back to `nimsem` wrote its artifacts under the
same key as a genuine aowlsem run, and the next real run was served the fallback's
output while reporting aowlsem (commit `5dc2568`).

## The interpreter is first-class

[aowli](../aowli) is not a fallback — it is a primary execution mode
(`aowlmony interp`), and it is the intended answer to the one feature the native
path is missing: **macros / compile-time execution**. nimony today builds each
macro into a host-native executable and exec's it at every call site. The
self-owned stack replaces that with the interpreter: evaluate the macro's
`.s.nif` directly with `aowli` at compile time — the *same* evaluator that runs
`aowlmony interp` runs `static:` blocks and constant folding. That wiring exists:
aowlsem's `const` evaluator and macro executor generate a module and run it under
aowli (its `interp` executor), with a native-build executor as the alternative —
its `consteval` gate reads 19/19 byte-exact under both (Windows, 2026-09-09). See
[aowlsem → Compile-time evaluation](aowlsem/cli#compile-time-evaluation).

## Two backends, verified to agree

The same program, through the same self-owned frontend **and our own lowering**,
run both ways:

```sh
$ aowlmony interp demo.nim              # aowli, full runtime (strings, echo, seqs)
6765
3628800
true
$ aowlmony exec demo.nim --entry fib     --arg 20   # aowlhexer → aowlc → gcc
6765
$ aowlmony exec demo.nim --entry fact    --arg 10
3628800
```

`npm test` (`test/test.js`) asserts that native ([aowlc](aowlc)) and interpreter
([aowli](../aowli)) produce consistent results, the module is confirmed parsed by
aowlparser, and the native path lowers through [aowlhexer](aowlhexer). Its latest
recorded verdict is **24 ok / 16 fail on Windows** (commits `b2bce2e` and
`5dc2568`, 2026-09-08; the 16 predate both and are unchanged by them). An earlier
version of this page said "9/9" without a date or platform; that figure is not
reproducible from the repo and has been dropped.

Native vs interpret today: this page used to say aowlc "does not yet link the
system runtime, so `echo`/strings/seqs run under `interp`". That is no longer the
case. aowlc lowers the system runtime — strings, seqs, `echo`, exceptions, GC
objects and method dispatch (its README, 2026-08-06) — and on 2026-09-09
`aowlmony build` took a 1,178-line real program (Windows FFI, closures, SHA-256,
`startProcess`) to a working 343 KB binary through aowlc, byte-identical in
behaviour to the nimony-linked build (commit `63bb978`). Six emitter defects were
fixed on the way, two of them silent miscompiles: unsigned literals emitted as
32-bit `u` (every wide string lost its last byte) and `bitsOf` reading the wrong
child of a sized type (every `DWORD` widened to 64 bits). [aowlrt](aowlrt) is
still the plan for a self-owned runtime, but it is no longer what stands between
you and a native `echo`.

## Usage

```sh
aowlmony run    prog.nim                        # native: whole module → binary → run
aowlmony build  prog.nim -o prog                # native: emit a binary (aowlc)
aowlmony build  prog.nim --native:nimony        # …or copy the binary nimony linked (since 2026-09-09)
aowlmony exec   prog.nim --entry fib --arg 20   # native: call one proc, print result
aowlmony interp prog.nim                        # interpret via aowli
aowlmony vm     prog.nim                        # interpret via aowli's bytecode VM
aowlmony verify prog.nim [--native:aowlc]       # run both legs; report the first divergent op
aowlmony parse  prog.nim                        # show OUR aowlparser .p.nif
aowlmony nif    prog.nim  -v                    # paths + which parser/hexer ran
aowlmony +nimony run prog.nim                   # one-shot: compile with the nimony profile (needs aowlup)
```

`build --native:nimony|aowlc` takes the same spelling `verify` has taken since
`5a44c24`; the default is unchanged (aowlc). It exists so a regression in the C
emitter is not the end of the road — the nimony-linked binary is already sitting
in the nimcache, paid for by the compile that just ran.

## Windows

Measured on Windows, 2026-09-08/09, from the aowlmony commit log:

- **Every probe missed until `b2bce2e`.** Candidate paths were spelled without an
  executable suffix; on Windows every aoughwl binary is `<tool>.exe`, so every
  slot fell back to nimony while `-v` reported `parser=aowlparser
  hexer=aowlhexer`. Fixed at the one chokepoint where a candidate is tested.
- **The parser and sem shims are shell scripts, and Windows cannot exec one.**
  nimony's `findTool` looks for `nifler`/`nimsem` on `PATH`; the aowlmony shims
  carry routing logic (user module vs stdlib; the `m`/`x` argv translation) so
  they are scripts, and `CreateProcessW` will not start a file whose first line
  is `#!`. On Windows those two slots therefore fall back to nimony's tools and
  the driver says so under `-v`. The hexer shim is a pure passthrough, so it is
  staged as the binary itself under the name nimony looks for and **does** run.
  A native trampoline (`src/shim/aowlshim.c`, staged as `nifler.exe` /
  `nimsem.exe`) is in the working tree and not yet committed at the time of
  writing.
- `~/.aowl/bin/nimlock` is also a `#!` script; `ec0f2b6` routes it through bash
  so a compile does not fail with an empty error report.
- `aowlmony-ng` (the Nimony-language port) builds on Windows but does not run
  there yet — it assembles its stage directory by shelling out and `cmd.exe`
  rejects the command (`8a4f224`). The JS driver is what runs on Windows.

The active profile (and which parser/hexer/sem it selects) is shown by
`aowlmony help` and managed with [aowlup](aowlup).

## The AIF family

Per the directive to standardise on **AIF (aowl intermediate format)**, the
self-owned components carry the `aowl-` prefix (an `aif-` prefix was used for
about a day in July 2026 — `aifi`, `aifhexer`, `aifmony` — and renamed to `aowl-`
on 2026-07-16/18; the on-disk artifacts have always been `.nif`, see
[AIF](aif)): [aowlparser](aowlparser),
[aowlsem](aowlsem), [aowlhexer](aowlhexer), [aowlc](aowlc), [aowlrt](aowlrt),
[aowljs](aowljs), and this driver, aowlmony. [aowli](../aowli) is the interpreter over
`.s.nif`; [aowlsuggest](aowlsuggest) is the diagnostics / quick-fix / editor layer
built on the parser's recoverable errors. What remains to finish the rewrite:

- **[aowlsem](aowlsem)** — flip the registry's default sem slot to it, and drop
  the reused nimony `nimsem`. It is selectable today; the remaining distance is
  on the [aowlsem page](aowlsem#measured-status), with dates.
- **[aowlrt](aowlrt)** — the self-owned system module + runtime, so native
  builds no longer lower nimony's `system` module.
- **[aowlhexer](aowlhexer)** — progressively rewrite the vendored passes onto an
  aowl-owned core, dropping the `$NIMONY_SRC` dependency.
- **[aowlparser](aowlparser)** — finish `concept`/typed-nil so it parses the
  stdlib too, not only user modules.
