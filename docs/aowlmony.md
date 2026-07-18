# aowlmony — the nimony rewrite driver

`aowlmony` is the driver that unifies the aoughwl self-owned stack into one
compiler over **AIF** (the aowl intermediate format): give it a `.nim` file and
it runs parser → sem → lowering → **your choice of native code or
interpretation**, using aoughwl's own components wherever they exist and reusing
nimony's only for the parts not yet rebuilt.

Repo: **`aoughwl/aowlmony`** (public).

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

The **parser** (`aowlparser` vs `nifler`) and **lowering** (`aowlhexer` vs nimony
`hexer`) are swapped in through nimony's tool-resolution seam, so the active
profile genuinely controls them — `aowlmony +aowl run f.nim -v` reports *parsed by
aowlparser · lowering via aowlhexer*, `+nimony` reports *nifler · nimony hexer*.
Backends resolve from the registry. The one slot still pending is **sem**:
`aowlsem` can't yet semcheck `std/system` inside this build, so `sem=aowlsem`
falls back to nimony's `nimsem` with a note (and adopts `aowlsem` automatically
once it covers `system`).

## The pipeline

```
   .nim ──► aowlparser (ours) ──► nimony sem (reused) ──► aowlhexer (ours) ──► .s.aif / .c.aif
                                                                               │        │
                                        aowli (ours) ◄── interpret ────────────┘        └──► aowlc (ours) ──► C ──► gcc ──► native
```

## Ours vs reused — the honest map

| stage | tool | owned? |
|---|---|---|
| parse `.nim` → `.p.aif` (user modules) | [aowlparser](aowlparser) | ✅ ours |
| parse stdlib → `.p.aif` | `nifler` | reused — aowlparser has `concept`/typed-nil gaps |
| sem `.p.aif` → `.s.aif` | nimony `nimsem` | reused — **[aowlsem](aowlsem) not finished yet** |
| **lower** `.s.aif` → `.c.aif` (ARC, closures, exceptions, mono) | **[aowlhexer](aowlhexer)** | ✅ **ours** (seeded from Araq's hexer) |
| **native** `.c.aif` → binary | [aowlc](aowlc) → gcc | ✅ ours |
| **interpret** `.s.aif` | [aowli](../aowli) (tree-walk + bytecode VM) | ✅ ours |
| web `.s.aif` → JS | [aowljs](aowljs) | ✅ ours |
| idiomatic `.s.aif` → TS / Py / JS | [aowlts](aowlts) / [aowlpy](aowlpy) / [aowljs](aowljs) | ✅ ours |

## Idiomatic source export

Beyond native/interpret, the driver emits **readable source** in another language:

```
aowlmony ts prog.nim [--faithful] [--run]   # → prog.ts (idiomatic TypeScript)
aowlmony py prog.nim [--run]                # → prog.py (idiomatic Python)
aowlmony js prog.nim [--faithful] [--run]   # → prog.js (native-JS)
```

Each lowers `.nim → sem → .s.aif` and hands it to the matching backend. Output is
hand-written-looking source, not a machine simulation; `--run` executes it and its
stdout matches `nimony c -r` byte-for-byte (verified end-to-end). `--faithful`
(ts/js) maps 64-bit ints to `BigInt` for exact int64/uint64 semantics — see the
per-backend pages for the fast/faithful trade-off.

The self-owned stack now covers **parser + lowering + backend + interpreter** —
only semantic analysis is still reused from nimony (until [aowlsem](aowlsem)
lands). Lowering moved into our column with [aowlhexer](aowlhexer): the aowlmony
driver injects `bin/aowlhexer` in place of nimony's `hexer` (via nimony's
`findTool("hexer")` lookup), so a full build reads
`.nim → aowlparser → sem → aowlhexer → aowlc → gcc`.

Provenance is verifiable: aowlparser stamps `(.vendor "aowlparser")` into the
`.p.aif` it produces, and `aowlmony nif prog.nim -v` reports *which* parser and
*which* hexer ran.

## The interpreter is first-class

[aowli](../aowli) is not a fallback — it is a primary execution mode
(`aowlmony interp`), and it is the intended answer to the one feature the native
path is missing: **macros / compile-time execution**. nimony today builds each
macro into a host-native executable and exec's it at every call site. The
self-owned stack replaces that with the interpreter: evaluate the macro's
`.s.aif` directly with `aowli` at compile time — the *same* evaluator that runs
`aowlmony interp` runs `static:` blocks and constant folding. Wiring this into
aowlsem is the next milestone.

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

`npm test` asserts 9/9: native ([aowlc](aowlc)) and interpreter ([aowli](../aowli))
produce consistent results, the module is confirmed parsed by aowlparser, and the
native path lowers through [aowlhexer](aowlhexer).

Native vs interpret today: [aowlc](aowlc) covers the arithmetic/control-flow core
but does not yet link the system runtime, so `echo`/strings/seqs run under
`interp` while pure computation also runs natively. [aowllib](aowllib) — the
self-owned runtime — is what will close that gap.

## Usage

```sh
aowlmony run    prog.nim                        # native: whole module → binary → run
aowlmony build  prog.nim -o prog                # native: emit a binary
aowlmony exec   prog.nim --entry fib --arg 20   # native: call one proc, print result
aowlmony interp prog.nim                        # interpret via aowli
aowlmony vm     prog.nim                        # interpret via aowli's bytecode VM
aowlmony parse  prog.nim                        # show OUR aowlparser .p.aif
aowlmony nif    prog.nim  -v                    # paths + which parser/hexer ran
aowlmony +nimony run prog.nim                   # one-shot: compile with the nimony profile
```

The active profile (and which parser/hexer/sem it selects) is shown by
`aowlmony help` and managed with [aowlup](aowlup).

## The AIF family

Per the directive to standardise on **AIF (aowl intermediate format)**, the
self-owned components carry the `aif-` prefix: [aowlparser](aowlparser),
[aowlsem](aowlsem), [aowlhexer](aowlhexer), [aowlc](aowlc), [aowllib](aowllib),
[aowljs](aowljs), and this driver, aowlmony. [aowli](../aowli) is the interpreter over
`.s.aif`; [aowlsuggest](aowlsuggest) is the diagnostics / quick-fix / editor layer
built on the parser's recoverable errors. What remains to finish the rewrite:

- **[aowlsem](aowlsem)** — finish it → drop the reused nimony `nimsem`.
- **[aowllib](aowllib)** — the self-owned system module + runtime, so native
  `echo`/strings/seqs link without nimony's `system.c.aif`. The biggest unlock.
- **[aowlhexer](aowlhexer)** — progressively rewrite the vendored passes onto an
  aowl-owned core, dropping the `$NIMONY_SRC` dependency.
- **[aowlparser](aowlparser)** — finish `concept`/typed-nil so it parses the
  stdlib too, not only user modules.
