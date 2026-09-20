---
title: aowli licence
---

# aowli — $9.99/month

The **aowli** interpreter and debugger, and the compiler backends that emit
**TypeScript**, **Python**, and **faithful JavaScript / WebAssembly** — as
maintained binaries, from one subscription and one command:

```sh
aowlup login AOWL-XXXX-XXXX-XXXX-XXXX
```

The [documentation is public](/aowli); the source is not.

<BuyButton product="aowli" price="999" interval="month" label="Subscribe"
  demo="https://aoughwl.github.io/playground/" demoLabel="Try it now — free" />

## What the subscription buys

| | |
|---|---|
| **aowli-interp** | A tree-walker and bytecode VM that execute nimony's post-semcheck typed AIF — the exact artifact the native backend consumes. |
| **aowli-dbg** | The interactive stepping debugger: runs the program once and stays paused between commands. `step` / `next` / `finish`, live breakpoints added mid-run, path-addressable `--expand`, time-travel `snapshot` / `restore`. Also what the [aowlcode](/docs/aowlcode) plugin's `debug_session` tool drives. |
| **aowlts** | [Idiomatic TypeScript](/docs/aowlts): real types, real control flow, readable output. |
| **aowlpy** | [Idiomatic Python](/docs/aowlpy) with type hints, on Python's own GC and arbitrary-precision `int`. |
| **aowlweb** | [Faithful JavaScript and WebAssembly](/docs/aowlweb) over one linear-memory model: `nim-js`, `nim-js-link`, `nim-wasm`, plus the runtime they link against. |
| **Every update, immediately** | Correctness fixes land here first. No version to buy again. |
| **Three machines** | Activate up to three at a time; release one from your [licence page](/store/license) to move it. |
| **Priority support** | Issues from subscribers are answered first, on Discord, by the person who wrote it. |

It does **not** buy the source. `aoughwl/aowli`, `aowlweb`, `aowlts` and `aowlpy`
stay private.

## After subscribing

1. Your key appears on screen and arrives by email.
2. Install [aowlup](/docs/aowlup) if you have not, then:
   ```sh
   aowlup login YOUR-KEY
   ```
   That downloads the release, checks its sha256, activates this machine, and
   registers everything in the package. `aowlup shim` puts the tools on your PATH.
3. No `aowlup`? Download from your [licence page](/store/license), extract, and
   run `bin/aowli-activate YOUR-KEY` once.

After activation nothing needs the network. A new release needs one
re-activation, which happens by itself while the key is stored on the machine.

## How it is protected

The tools ship **encrypted**, under a key that is not in the download. Activating
a machine fetches that key, wrapped so that only that machine can open it. A
copied install has nothing to run, and there is no licence check to patch out —
skipping the decryption skips the program. Every release uses a new key.

That does not make it impossible to get around: a paying customer can still lift a
decrypted program out of their own process's memory. So every activation is
watermarked to its licence, and a leaked build names the key that leaked it.
We say this plainly because a licence system that claims to be uncrackable is
lying to you.

## Why a subscription and not a one-off

The tools are maintained against a moving toolchain: nimony changes, the
backends chase it, and every release is re-sealed under a fresh key. A one-time
price would be a promise to keep doing that forever for one payment, and the
honest ways to keep that promise are all worse.

So: **cancel whenever.** Your key does not die when you cancel — it goes
dormant, and restarting the subscription wakes the same key up with its machines
still on it.

## What it is honestly not

- **Not a compiler.** aowli runs typed AIF that nimony has already semantically
  analysed. The compiler, the parser and the other emitters
  [stay free and open](/store/).
- **Not complete parity with native.** Two engines agree byte-for-byte with each
  other and are held against native compilation by a differential harness — but
  the harness has a denominator, and it is written down rather than rounded up.
  The backends are working cores, not finished products; each page says where
  the gaps are.
- **Not a source licence, and not redistributable.** One key, your machines.

## Requirements

- Linux x86-64 with glibc ≥ 2.35 (Ubuntu 22.04+, Debian 12+). The tools are
  self-contained.
- `curl` and `tar` (for `aowlup login`).
- A `.s.aif` to run — i.e. a nimony toolchain, which is free.
- Network once, to activate.

Questions before you subscribe: **timbuktu_guy** on
[Discord](https://discord.gg/nxa3W7w4rJ).
