---
title: aowlmony
grand_parent: Documentation
parent: Compiler Pipeline
nav_order: 3
---

# aowlmony — the nimony rewrite driver
{: .no_toc }

`aowlmony` is the driver that unifies the aoughwl self-owned stack into one
compiler over **AIF** (the aowl intermediate format): give it a `.nim` file and
it runs parser → sem → lowering → **your choice of native code or
interpretation**, using aoughwl's own components wherever they exist and reusing
nimony's only for the parts not yet rebuilt.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aowlmony`** (public).

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## The pipeline

```
   .nim ──► aowlparse (ours) ──► nimony sem (reused) ──► aowlhexer (ours) ──► .s.aif / .c.aif
                                                                               │        │
                                        aowli (ours) ◄── interpret ────────────┘        └──► aowlc (ours) ──► C ──► gcc ──► native
```

## Ours vs reused — the honest map

| stage | tool | owned? |
|---|---|---|
| parse `.nim` → `.p.aif` (user modules) | [aowlparse](aowlparse) | ✅ ours |
| parse stdlib → `.p.aif` | `nifler` | reused — aowlparse has `concept`/typed-nil gaps |
| sem `.p.aif` → `.s.aif` | nimony `nimsem` | reused — **[aowlsem](nifsem) not finished yet** |
| **lower** `.s.aif` → `.c.aif` (ARC, closures, exceptions, mono) | **[aowlhexer](aowlhexer)** | ✅ **ours** (seeded from Araq's hexer) |
| **native** `.c.aif` → binary | [aowlc](aowlc) → gcc | ✅ ours |
| **interpret** `.s.aif` | [aowli](../aowli) (tree-walk + bytecode VM) | ✅ ours |
| web `.s.aif` → JS | [aowljs](aowljs) | ✅ ours |

The self-owned stack now covers **parser + lowering + backend + interpreter** —
only semantic analysis is still reused from nimony (until [aowlsem](nifsem)
lands). Lowering moved into our column with [aowlhexer](aowlhexer): the aowlmony
driver injects `bin/aowlhexer` in place of nimony's `hexer` (via nimony's
`findTool("hexer")` lookup), so a full build reads
`.nim → aowlparse → sem → aowlhexer → aowlc → gcc`.

Provenance is verifiable: aowlparse stamps `(.vendor "aowlparse")` into the
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
produce consistent results, the module is confirmed parsed by aowlparse, and the
native path lowers through [aowlhexer](aowlhexer).

Native vs interpret today: [aowlc](aowlc) covers the arithmetic/control-flow core
but does not yet link the system runtime, so `echo`/strings/seqs run under
`interp` while pure computation also runs natively. [aiflib](aiflib) — the
self-owned runtime — is what will close that gap.

## Usage

```sh
aowlmony run    prog.nim                        # native: whole module → binary → run
aowlmony build  prog.nim -o prog                # native: emit a binary
aowlmony exec   prog.nim --entry fib --arg 20   # native: call one proc, print result
aowlmony interp prog.nim                        # interpret via aowli
aowlmony vm     prog.nim                        # interpret via aowli's bytecode VM
aowlmony parse  prog.nim                        # show OUR aowlparse .p.aif
aowlmony nif    prog.nim  -v                    # paths + which parser/hexer ran
```

## The AIF family

Per the directive to standardise on **AIF (aowl intermediate format)**, the
self-owned components carry the `aif-` prefix: [aowlparse](aowlparse),
[aowlsem](nifsem), [aowlhexer](aowlhexer), [aowlc](aowlc), [aiflib](aiflib),
[aowljs](aowljs), and this driver, aowlmony. [aowli](../aowli) is the interpreter over
`.s.aif`. What remains to finish the rewrite:

- **[aowlsem](nifsem)** — finish it → drop the reused nimony `nimsem`.
- **[aiflib](aiflib)** — the self-owned system module + runtime, so native
  `echo`/strings/seqs link without nimony's `system.c.aif`. The biggest unlock.
- **[aowlhexer](aowlhexer)** — progressively rewrite the vendored passes onto an
  aowl-owned core, dropping the `$NIMONY_SRC` dependency.
- **[aowlparse](aowlparse)** — finish `concept`/typed-nil so it parses the
  stdlib too, not only user modules.
