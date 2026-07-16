---
title: aifmony
grand_parent: Documentation
parent: Toolchain
nav_order: 5
---

# aifmony — the nimony rewrite driver
{: .no_toc }

`aifmony` is the driver that unifies the aoughwl self-owned stack into one
compiler over **AIF** (the aowl intermediate format): give it a `.nim` file and
it runs parser → sem → lowering → **your choice of native code or
interpretation**, using aoughwl's own components wherever they exist and reusing
nimony's only for the parts not yet rebuilt.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/aifmony`** (public).

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## The pipeline

```
   .nim ──► aifparser (ours) ──► nimony sem (reused) ──► aifhexer (ours) ──► .s.aif / .c.aif
                                                                               │        │
                                        nifi (ours) ◄── interpret ────────────┘        └──► aifc (ours) ──► C ──► gcc ──► native
```

## Ours vs reused — the honest map

| stage | tool | owned? |
|---|---|---|
| parse `.nim` → `.p.aif` (user modules) | [aifparser](nifparser) | ✅ ours |
| parse stdlib → `.p.aif` | `nifler` | reused — aifparser has `concept`/typed-nil gaps |
| sem `.p.aif` → `.s.aif` | nimony `nimsem` | reused — **[aifsem](nifsem) not finished yet** |
| **lower** `.s.aif` → `.c.aif` (ARC, closures, exceptions, mono) | **[aifhexer](aifhexer)** | ✅ **ours** (seeded from Araq's hexer) |
| **native** `.c.aif` → binary | [aifc](nifc) → gcc | ✅ ours |
| **interpret** `.s.aif` | [nifi](../nifi) (tree-walk + bytecode VM) | ✅ ours |
| web `.s.aif` → JS | [aifjs](nifjs) | ✅ ours |

The self-owned stack now covers **parser + lowering + backend + interpreter** —
only semantic analysis is still reused from nimony (until [aifsem](nifsem)
lands). Lowering moved into our column with [aifhexer](aifhexer): the aifmony
driver injects `bin/aifhexer` in place of nimony's `hexer` (via nimony's
`findTool("hexer")` lookup), so a full build reads
`.nim → aifparser → sem → aifhexer → aifc → gcc`.

Provenance is verifiable: aifparser stamps `(.vendor "nifparser")` into the
`.p.aif` it produces, and `aifmony nif prog.nim -v` reports *which* parser and
*which* hexer ran.

## The interpreter is first-class

[nifi](../nifi) is not a fallback — it is a primary execution mode
(`aifmony interp`), and it is the intended answer to the one feature the native
path is missing: **macros / compile-time execution**. nimony today builds each
macro into a host-native executable and exec's it at every call site. The
self-owned stack replaces that with the interpreter: evaluate the macro's
`.s.aif` directly with `nifi` at compile time — the *same* evaluator that runs
`aifmony interp` runs `static:` blocks and constant folding. Wiring this into
aifsem is the next milestone.

## Two backends, verified to agree

The same program, through the same self-owned frontend **and our own lowering**,
run both ways:

```sh
$ aifmony interp demo.nim              # nifi, full runtime (strings, echo, seqs)
6765
3628800
true
$ aifmony exec demo.nim --entry fib     --arg 20   # aifhexer → aifc → gcc
6765
$ aifmony exec demo.nim --entry fact    --arg 10
3628800
```

`npm test` asserts 9/9: native ([aifc](nifc)) and interpreter ([nifi](../nifi))
produce consistent results, the module is confirmed parsed by aifparser, and the
native path lowers through [aifhexer](aifhexer).

Native vs interpret today: [aifc](nifc) covers the arithmetic/control-flow core
but does not yet link the system runtime, so `echo`/strings/seqs run under
`interp` while pure computation also runs natively. [aiflib](aiflib) — the
self-owned runtime — is what will close that gap.

## Usage

```sh
aifmony run    prog.nim                        # native: whole module → binary → run
aifmony build  prog.nim -o prog                # native: emit a binary
aifmony exec   prog.nim --entry fib --arg 20   # native: call one proc, print result
aifmony interp prog.nim                        # interpret via nifi
aifmony vm     prog.nim                        # interpret via nifi's bytecode VM
aifmony parse  prog.nim                        # show OUR aifparser .p.aif
aifmony nif    prog.nim  -v                    # paths + which parser/hexer ran
```

## The AIF family

Per the directive to standardise on **AIF (aowl intermediate format)**, the
self-owned components carry the `aif-` prefix: [aifparser](nifparser),
[aifsem](nifsem), [aifhexer](aifhexer), [aifc](nifc), [aiflib](aiflib),
[aifjs](nifjs), and this driver, aifmony. [nifi](../nifi) is the interpreter over
`.s.aif`. What remains to finish the rewrite:

- **[aifsem](nifsem)** — finish it → drop the reused nimony `nimsem`.
- **[aiflib](aiflib)** — the self-owned system module + runtime, so native
  `echo`/strings/seqs link without nimony's `system.c.aif`. The biggest unlock.
- **[aifhexer](aifhexer)** — progressively rewrite the vendored passes onto an
  aowl-owned core, dropping the `$NIMONY_SRC` dependency.
- **[aifparser](nifparser)** — finish `concept`/typed-nil so it parses the
  stdlib too, not only user modules.
