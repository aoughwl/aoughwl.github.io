---
title: aowlspt licence
---

# aowlspt — $19.99/month

A modding platform for post-1.0 **Escape From Tarkov**: a native client host
injected into the game, a backend server, an in-game overlay, one C ABI, one
build command — and a from-scratch Tarkov server emulator written *as a mod on
top of it*. The [documentation is public](/docs/aowlspt); the build is not.

<BuyButton product="aowlspt" price="1999" interval="month" label="Subscribe" />

## What the subscription buys

| | |
|---|---|
| **The release archive** | `aowlspt-<version>.zip` — installer, payload, mods, `MANIFEST.sha256`. Reproducible: two builds of the same tree are byte-identical. |
| **Every update, immediately** | Tarkov updates, aowlspt updates. No version to buy again, no compatibility gap you have to pay to close. |
| **Three machines** | Activate up to three at a time; release one from your [licence page](/store/license) to move it. |
| **The mods** | sway, SAIN, MoreBots, Black Division, Icebreaker, FOV, Classic Movement — ported, and building under one `aowl build`. |
| **Support** | Discord, from the person who wrote it. |

It does **not** buy the source. `savannt/aowlspt` stays private.

## Why a subscription and not a one-off

Because of what the work actually is. Tarkov updates and breaks things; each
wipe changes the game; the emulator is chased against a moving target
indefinitely. A one-time price would be a promise to keep doing that forever for
one payment, and the honest ways to keep that promise are all worse — a version
that quietly rots, or paid upgrades every few months.

So: **cancel whenever**. Come back for a wipe, subscribe for the month, cancel.
Your key does not die when you cancel — it goes dormant, and restarting the
subscription wakes the same key up. There is nothing to re-buy and no key to
lose track of.

If you play continuously it costs $240 a year, which is a lot; if you play one
wipe it costs $20. Decide which one you are.

## What it is honestly not

- **Not multiplayer, and not a cheat.** It is a single-player modding platform
  for an offline server emulator. It does not touch BSG's live backend.
- **Not finished.** The client API reaches live objects, hooks read their
  arguments and can suppress the original, and the emulator boots a real client
  through a raid — but the surface is still growing, and some pre-1.0 mods are
  documented as *not portable* rather than faked. [The gaps are written
  down](/docs/aowlspt/architecture).
- **Not a mod manager for other people's mods.** aowlspt mods are native DLLs
  built from nimony against its own ABI.

## Requirements

- Windows, and an Escape From Tarkov install the official launcher maintains.
- The installer builds an aowlspt install *beside* your vanilla one and never
  writes into it.
- A network connection now and then. Activation is once; after that it runs
  offline, and it re-checks the subscription when it happens to be online. Go
  offline for longer than a billing period and it will want one connection —
  not your key again.

## After subscribing

1. Your key appears on screen and arrives by email.
2. Open your [licence page](/store/license), paste the key, download the build.
3. Extract, and run `install\aowlspt-install.exe activate <your-key>` — see
   [Installing](/docs/aowlspt) for the full walk-through.

Cancelling is one button on that same licence page, and it takes effect at the
end of the month you have already paid for.

Questions before you subscribe: **timbuktu_guy** on
[Discord](https://discord.gg/nxa3W7w4rJ).
