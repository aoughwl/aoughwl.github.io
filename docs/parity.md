# Parity

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

The target is a rewrite of the Nim / Nimony toolchain whose output is **byte-for-byte
identical** to the original: same parse tree, same typed IR, same generated code,
down to the byte. Not a fork and not a wrapper — each stage is written from
scratch and then diffed against the real compiler's output.

We're not all the way there. This page is the scoreboard.

## Why byte-for-byte

"Close" is easy to claim and impossible to check. Byte-for-byte isn't: every
naming decision, emission order, whitespace convention and line-info offset has
to match, and the diff is either empty or it isn't. Passing that bar is what
makes a stage an actual drop-in replacement rather than a lookalike.

## Where each stage stands

| Stage | ours | vs. | from scratch | byte parity |
|:--|:--|:--|:--:|:--|
| **parse** | [aowlparser](aowlparser) | `nifler` | ✅ | **byte-exact** on the whole compiler tree (184/184); 91–283 files byte-exact on the stdlib, **100% structural** everywhere |
| **semcheck** | [aowlsem](aowlsem) | `nimsem` | ✅ | **498/498** corpus modules byte-exact against the reference oracle, `std/system` checking clean; remaining gaps are whole constructs, not diff noise |
| **lower** | [aowlhexer](aowlhexer) | `hexer` | ⏳ | runs the reference's 25 passes with **two of our own fixes** on top (below), so it is near-identical rather than identical by construction; the from-scratch rewrite is next |
| **C codegen** | [aowlc](aowlc) | `lengc` | ✅ | end-to-end correct today (runs, ASan-clean); text byte-parity with `lengc` is the active push |
| **interpret / VM** | [aowli](/aowli) | *(new)* | ✅ | two independent engines that agree with each other and with native across a 423-program differential corpus — zero in-scope divergence (aowli **v0.3.3**) |
| **emit → TS / Py / JS / WASM** | [aowlts](aowlts) · [aowlpy](aowlpy) · [aowljs](aowljs) · [aowlweb](aowlweb) | *(nimony backends)* | ✅ | idiomatic, readable output; behaviour-verified against native, run-for-run |

✅ = written from scratch · ⏳ = still reuses the reference implementation

## Parser results

The front of the pipeline is done. `aowlparser` is diffed against native
`nifler`: *structural* means the token trees match with line info stripped,
*byte-exact* means the `.p.aif` files are identical including every offset.

| corpus | files | structural | byte-exact |
|:--|--:|--:|--:|
| nimony/src (the compiler itself) | 184 | 184 | **184** |
| nimony/lib (stdlib) | 105 | 105 | 91 |
| upstream Nim/lib | 310 | 310 | 283 |
| curated | 172 | 172 | 156 |

0 crashes, 0 hangs across all four. The remaining byte gaps are written down,
not mysterious — see [Parity & gaps](aowlparser/known-gaps).

## Semantic checker

`aowlsem` is a clean-room replacement for `nimsem` and is the stage where parity
is currently being ground out construct by construct. The corpus stands at
**498/498 modules byte-exact**, including all of `std/system`.

What's left is not a long tail of near-misses. Broad differential runs over the
whole nimcache oracle set point at specific missing features — anonymous sum-type
construction and `of`-pattern matching are the largest — rather than at drift in
code that already works. Details on the [aowlsem page](aowlsem).

## Lowering

`aowlhexer` still runs the reference compiler's 25 lowering passes, so its
`.c.aif` matches by construction almost everywhere. Two deliberate exceptions,
both places the reference marks its own code as unfinished:

- **Captured `var` / `out` parameters are now rejected.** A closure that captures
  a `var T` parameter holds a pointer into the *caller's* frame, so an
  environment outliving the call dangles. The reference leaves this as a TODO in
  `lambdalifting`; we make it a lowering-time error.
- **Move analysis reports the right token.** In `mover`, the "other usage" that
  blocks a sink was recorded after the cursor had already advanced past it, so
  the diagnostic pointed at a closing paren. It now points at the use.

Both make aowlhexer stricter or more accurate than the original, not looser —
one can reject a program the reference accepts, which is the point. This is a
staging post: the passes get rewritten onto an aowl-owned core, and then this
row stops saying ⏳.

## How we measure

Every claim here comes from a differential harness: run the same input through
the reference tool and ours, normalize only what genuinely doesn't matter, diff
the bytes. A green diff is the only thing that counts as done for a construct;
everything else is a punch-list item. That's how the parser got here, and it's
how each remaining stage closes.
