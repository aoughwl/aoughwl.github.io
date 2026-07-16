---
title: nifmony
grand_parent: Nimony
parent: NIF Toolchain Alternatives
nav_order: 5
---

# nifmony — the nimony rewrite driver
{: .no_toc }

`nifmony` is the driver that unifies the aoughwl self-owned stack into one
compiler: give it a `.nim` file and it runs parser → sem → lowering → **your
choice of native code or interpretation**, using aoughwl's own components
wherever they exist and reusing nimony's for the parts not yet rebuilt.
{: .fs-6 .fw-300 }

Repo: **`aoughwl/nifmony`** (public).

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## The pipeline

```
   .nim ──► nifparser (ours) ──► nimony sem + hexer (reused) ──► .s.nif / .c.nif
                                                                    │        │
                              nifi (ours) ◄── interpret ───────────┘        └──► nifc (ours) ──► C ──► gcc ──► native
```

## Ours vs reused — the honest map

| stage | tool | owned? |
|---|---|---|
| parse `.nim` → `.p.nif` (user modules) | [nifparser](nifparser) | ✅ ours |
| parse stdlib → `.p.nif` | `nifler` | reused — nifparser has `concept`/typed-nil gaps |
| sem `.p.nif` → `.s.nif` | nimony `nimsem` | reused — **nifsem not finished yet** |
| lower `.s.nif` → `.c.nif` | nimony `hexer` (ARC, closures, exceptions, mono) | reused — the genuinely hard pass |
| **native** `.c.nif` → binary | [nifc](nifc) → gcc | ✅ ours |
| **interpret** `.s.nif` | [nifi](../nifi) (tree-walk + bytecode VM) | ✅ ours |
| web `.s.nif` → JS | [nifjs](nifjs) | ✅ ours |

Today nifmony proves the **ends** of the pipeline are self-owned — our parser
feeds it, our backends consume it — while the **middle** (sem + hexer) is reused
from nimony exactly as intended until nifsem lands and a self-owned lowering pass
is written. That reuse is deliberate: hexer's lowering is the one genuinely hard
component (it's what makes [nifc](nifc) a mere printer), so it is reused, not
rebuilt first.

Provenance is verifiable: nifparser stamps `(.vendor "nifparser")` into the
`.p.nif` it produces, so `nifmony nif prog.nim -v` reports *which* parser
produced the module that flows into sem → hexer → codegen.

## The interpreter is first-class

[nifi](../nifi) is not a fallback — it is a primary execution mode
(`nifmony interp`), and it is the intended answer to the one feature the native
path is missing: **macros / compile-time execution**.

nimony today builds each macro into a *host-native executable* and exec's it at
every call site (`macro_plugin.nim`). The self-owned stack replaces that with the
interpreter: evaluate the macro's `.s.nif` directly with `nifi` at compile time —
no per-macro native build, and the *same* evaluator that runs `nifmony interp`
runs `static:` blocks and constant folding. Wiring this into nifsem is the next
milestone; nimony's own macro expansion is used until then.

## Two backends, verified to agree

The same program, through the same self-owned frontend, run both ways:

```sh
$ nifmony interp demo.nim         # nifi, full runtime (strings, echo, seqs)
6765
3628800
true
$ nifmony exec demo.nim --entry fib     --arg 20   # nifc → gcc
6765
$ nifmony exec demo.nim --entry fact    --arg 10
3628800
$ nifmony exec demo.nim --entry isPrime --arg 97
1
```

`npm test` asserts 9/9: native ([nifc](nifc)) and interpreter ([nifi](../nifi))
produce consistent results for `fib`/`fact`/`ack`/`isPrime`, and the user module
is confirmed parsed by nifparser.

Native vs interpret today: [nifc](nifc) covers the arithmetic/control-flow core
but does not yet link the 54 KB system runtime, so `echo`/strings/seqs run under
`interp` while pure computation also runs natively. `nifmony exec --entry`
bridges the two — it harnesses any proc to a native binary so a `gcc`-compiled
result can be compared against the interpreter's.

## Usage

```sh
nifmony run    prog.nim                        # native: whole module → binary → run
nifmony build  prog.nim -o prog                # native: emit a binary
nifmony exec   prog.nim --entry fib --arg 20   # native: call one proc, print result
nifmony interp prog.nim                        # interpret via nifi
nifmony vm     prog.nim                        # interpret via nifi's bytecode VM
nifmony parse  prog.nim                        # show OUR nifparser .p.nif
nifmony nif    prog.nim  -v                    # .p/.s/.c.nif paths + provenance
```

## Finishing the rewrite — repos to create

nifmony makes the missing pieces concrete:

1. **`aoughwl/nifmony`** — *this repo*: the unified driver (the rewrite itself).
2. **`aoughwl/niflib`** (or `nifsys`) — the **self-owned system module + runtime**
   (strings, seqs, ARC helpers, GC objects) so [nifc](nifc)/[nifjs](nifjs) link
   real programs without nimony's `system.c.nif`. The biggest unlock: it's what
   lets `echo "hello"` compile *natively* through the stack.
3. **`aoughwl/niflower`** (or `nifhexer`) — a **self-owned lowering pass** to
   replace the reused nimony `hexer`, removing the last nimony dependency.

Already existing and slotting in: [nifparser](nifparser) (finish `concept`/typed-nil
so it parses the stdlib too), **nifsem** (finish → drop reused `nimsem`),
[nifi](../nifi) (promote to macro/CTFE engine), [nifc](nifc), [nifjs](nifjs).
Per the aoughwl convention (`nifjs` + `nifjs-js`), each hand-written JS component
is a **bootstrap seed & oracle** for a later nimony-native implementation.
