---
title: aowlspt licence
---

# aowlspt — $39

A modding platform for post-1.0 **Escape From Tarkov**: a native client host
injected into the game, a backend server, an in-game overlay, one C ABI, one
build command — and a from-scratch Tarkov server emulator written *as a mod on
top of it*. The [documentation is public](/docs/aowlspt); the build is not.

<BuyButton product="aowlspt" price="3900" label="Buy aowlspt" />

## What the $39 buys

| | |
|---|---|
| **The release archive** | `aowlspt-<version>.zip` — installer, payload, mods, `MANIFEST.sha256`. Reproducible: two builds of the same tree are byte-identical. |
| **Every update** | Perpetual licence. New Tarkov version, new build, same key. |
| **Three machines** | Activate up to three at a time; release one from your [licence page](/store/license) to move it. |
| **The mods** | sway, SAIN, MoreBots, Black Division, Icebreaker, FOV, Classic Movement — ported, and building under one `aowl build`. |
| **Support** | Discord, from the person who wrote it. |

It does **not** buy the source. `savannt/aowlspt` stays private.

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
- A network connection **once**, to activate. After that it runs offline
  indefinitely; the licence re-checks itself when you happen to be online.

## After buying

1. Your key appears on screen and arrives by email.
2. Open your [licence page](/store/license), paste the key, download the build.
3. Extract, and run `install\aowlspt-install.exe activate <your-key>` — see
   [Installing](/docs/aowlspt) for the full walk-through.

Questions before you buy: **timbuktu_guy** on
[Discord](https://discord.gg/nxa3W7w4rJ).
