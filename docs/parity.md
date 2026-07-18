# Parity — byte-for-byte, from scratch

The goal is blunt: an **AI-built, from-scratch reimplementation of the entire
Nim / Nimony toolchain** whose output is **byte-for-byte identical** to the
originals — the same parse tree, the same typed IR, the same generated code, down
to the byte. Not a fork, not a wrapper around Araq's binaries: each stage is
rewritten and then held to the real compiler's exact output by a differential
harness.

We are not all the way there yet — and that's the point of this page. It's the
honest scoreboard.

## Why byte-for-byte

Anyone can write a compiler that's "close." Byte-for-byte is a different bar: it
means every naming decision, every emission order, every whitespace convention,
every line-info offset matches the reference exactly. It's a brutal, unambiguous
oracle — the diff is either empty or it isn't. Hitting it proves the
reimplementation didn't just *approximate* Nim/Nimony's behaviour; it reproduced
it. That's what makes each stage a genuine **drop-in** beside nimony's own.

## Where each stage stands

| Stage | ours | vs. | from scratch | byte parity |
|:--|:--|:--|:--:|:--|
| **parse** | [aowlparser](aowlparser) | `nifler` | ✅ | **byte-exact** on the whole compiler tree (184/184); 91–283 files byte-exact on the stdlib, **100% structural** everywhere |
| **semcheck** | [aowlsem](aowlsem) | `nimsem` | ✅ | construct-by-construct; the 166-module corpus is diff-green, the byte-level diff is closing |
| **lower** | [aowlhexer](aowlhexer) | `hexer` | ⏳ | currently runs Araq's own 25 passes, so its `.c.aif` is **identical by construction**; a from-scratch rewrite is the target |
| **C codegen** | [aowlc](aowlc) | `lengc` | ✅ | end-to-end correct today (runs, ASan-clean); text byte-parity with `lengc` is the active push |
| **interpret / VM** | [aowli](/aowli) | *(new)* | ✅ | two independent engines, byte-identical to each other, held honest against native nimony execution |
| **emit → TS / Py / JS / WASM** | [aowlts](aowlts) · [aowlpy](aowlpy) · [aowljs](aowljs) · [aowlweb](aowlweb) | *(nimony backends)* | ✅ | idiomatic, readable output; behaviour-verified against native, run-for-run |

✅ = written from scratch · ⏳ = reuses the reference implementation for now

## The parser — proof the bar is reachable

The front of the pipeline is already there. `aowlparser` is diff-tested against
native `nifler` — *structural* = token trees equal with line-info stripped;
*byte-exact* = identical `.p.aif` including every line-info offset.

| corpus | files | structural | byte-exact |
|:--|--:|--:|--:|
| nimony/src (the compiler itself) | 184 | 184 | **184** |
| nimony/lib (stdlib) | 105 | 105 | 91 |
| upstream Nim/lib | 310 | 310 | 283 |
| curated | 172 | 172 | 156 |

0 crashes, 0 hangs across all four. The remaining byte gaps are catalogued, not
mysterious — see [Parity & gaps](aowlparser/known-gaps).

## How we measure

Every claim here comes from a **differential harness**, not a vibe: run the input
through both the reference tool and ours, normalize nothing that matters, and diff
the bytes. A green diff is the only thing that counts as "done" for a construct;
everything else is a punch-list item. That's how the parser got to byte-exact,
and it's how each remaining stage closes the gap.

## Built with AI

The whole stack is written from scratch **with AI** — the reimplementation, the
test harnesses, the byte-diff grind. That's the experiment: can a full,
production-grade compiler toolchain be rebuilt to byte-for-byte fidelity this way?
The scoreboard above is the running answer.
