# Parity

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

Every stage of this toolchain is written from scratch and then held to one
standard: run the same input through the reference tool and through ours, and
the two outputs have to be **identical down to the byte**. Same parse tree, same
typed IR, same generated code.

That bar is unforgiving on purpose. Every naming decision, emission order,
whitespace convention and line-info offset has to match, and at the end you are
looking at a diff that is either empty or it isn't — there is no partial credit
and no room to talk your way past it. Clearing it is what makes a stage an
actual drop-in replacement instead of something that looks like one.

We have not cleared it everywhere. This page is the scoreboard, including the
parts that aren't green.

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

0 crashes, 0 hangs across all four. The byte gaps that remain are written down
one by one rather than left as a mystery — see
[Parity & gaps](aowlparser/known-gaps).

## Semantic checker

`aowlsem` is a clean-room replacement for `nimsem`, and it is the stage where
parity is currently being ground out construct by construct. The corpus stands
at **498/498 modules byte-exact**, including all of `std/system`.

What's left is not a long tail of near-misses. Differential runs over the whole
nimcache oracle set point at specific missing features — anonymous sum-type
construction and `of`-pattern matching are the two biggest — rather than at
drift inside code that already works. That's the good kind of remaining work:
you can name it, and finishing one construct moves a countable number of
modules. Details on the [aowlsem page](aowlsem).

## Lowering

`aowlhexer` still runs the reference compiler's 25 lowering passes, so its
`.c.aif` matches by construction almost everywhere. There are two deliberate
exceptions, both in places the reference marks its own code as unfinished:

- **Captured `var` / `out` parameters are now rejected.** A closure that captures
  a `var T` parameter holds a pointer into the *caller's* frame, so an
  environment that outlives the call is left pointing at dead stack. The
  reference leaves this as a TODO in `lambdalifting`; we make it a lowering-time
  error.
- **Move analysis reports the right token.** In `mover`, the "other usage" that
  blocks a sink was recorded after the cursor had already advanced past it, so
  the diagnostic pointed at a closing paren. It now points at the use.

Both make aowlhexer stricter or more accurate than the original rather than
looser, so either one can reject a program the reference accepts. That is the
trade we want. The passes get rewritten onto an aowl-owned core next, and then
this row stops saying ⏳.

## How we measure

Every claim on this page comes out of a differential harness: run the same input
through the reference tool and ours, normalize only what genuinely doesn't
matter, diff the bytes. A green diff is the only thing that counts as done for a
construct — everything else is a punch-list item, not a rounding error. That is
how the parser got where it is, and it is how each remaining stage closes.

If a number here looks wrong to you, we would rather hear it than not. The
harnesses are in the repos, and the argument is welcome on
[Discord](https://discord.gg/nxa3W7w4rJ).
