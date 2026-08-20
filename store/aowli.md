---
title: aowli licence
---

# aowli — $9.99/month

The **aowli** interpreter and its debugger, as maintained binaries: a
tree-walker and a bytecode VM that execute nimony's post-semcheck typed AIF —
the exact artifact the native backend consumes — plus `aowli-dbg`, an
interactive stepping debugger that runs the program once and stays paused
between commands. The [documentation is public](/aowli); the source is not.

<BuyButton product="aowli" price="999" interval="month" label="Subscribe"
  demo="https://aoughwl.github.io/playground/" demoLabel="Try it now — free" />

## What the subscription buys

| | |
|---|---|
| **The binaries** | `aowli-interp` and `aowli-dbg`, with `SHA256SUMS.txt`. Hardened: obfuscated typed IR, fail-closed licence gate, stripped symbol table. |
| **A licence that does not expire under you** | The free builds carry a fixed expiry date baked in at build time. A subscription build re-licences itself while the subscription is live, so it never stops working mid-project. |
| **Every update, immediately** | Correctness fixes land here first. No version to buy again. |
| **Three machines** | Activate up to three at a time; release one from your [licence page](/store/license) to move it. |
| **The debugger** | `--session` progressive mode: step / next / finish, live breakpoints added mid-run, path-addressable `--expand` drill-down, budgeted value rendering. Also what the [aowlcode](/docs/aowlcode) plugin's `debug_session` tool drives. |
| **Support** | Discord, from the person who wrote it. |

It does **not** buy the source. `aoughwl/aowli` stays private.

## What happens to the free build

**Nothing is taken away from anybody who already has one.**
[`aoughwl/aowli-release`](https://github.com/aoughwl/aowli-release) stays
public and stays up. **v0.3.5 is the last free build**; it keeps working until
the expiry compiled into it, and its GitHub Release, assets and checksums are
not going anywhere.

What the subscription changes is *going forward*: new correctness releases, and
a build whose licence is renewed rather than fixed, are what you are paying
for. If the free v0.3.5 does what you need, keep it — it is honestly still
there.

## Why a subscription and not a one-off

Because the binary has an expiry in it, and re-issuing one is ongoing work, not
a one-time act. A one-off price would be a promise to keep re-licensing and
re-releasing forever for a single payment, and the honest ways to keep that
promise are all worse — a build that quietly rots on its gate date, or a paid
upgrade every time the gate rolls.

So: **cancel whenever.** Your key does not die when you cancel — it goes
dormant, and restarting the subscription wakes the same key up with its
machines still on it.

## What it is honestly not

- **Not a compiler.** aowli runs typed AIF that nimony has already
  semantically analysed. The compiler, the parser and the emitters
  [stay free and open](/store/).
- **Not complete parity with native.** Two engines agree byte-for-byte with
  each other and are held against native compilation by a differential
  harness — but the harness has a denominator, and it is written down rather
  than rounded up.
- **Not a source licence, and not redistributable.** One key, your machines.

## Requirements

- Linux x86-64. The binaries are self-contained.
- A `.s.aif` to run — i.e. a nimony toolchain, which is free.
- A network connection now and then. Activation is once; after that it runs
  offline and re-checks the subscription when it happens to be online.

## After subscribing

1. Your key appears on screen and arrives by email.
2. Open your [licence page](/store/license), paste the key, download the build.
3. Run `aowli-interp activate <your-key>` once, then use it offline.

Questions before you subscribe: **timbuktu_guy** on
[Discord](https://discord.gg/nxa3W7w4rJ).
