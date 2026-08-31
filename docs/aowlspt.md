---
repo: savannt/aowlspt
title: aowlspt — mods for post-1.0 Escape From Tarkov
---

# aowlspt

**Mods for post-1.0 Escape From Tarkov.** A native mod host, a game server that
speaks the real client's protocol, a launcher, a mod manager, and a set of mods
— offline, single-player, on your own machine.

Tarkov 1.0 moved the client to IL2CPP. There are no managed assemblies left, so
BepInEx does not load, Harmony has nothing to patch, and every mod written for
the Mono era stopped working. The usual answer is to roll your client back to a
pre-1.0 build. aowlspt does the other thing: **it mods the client you actually
own.**

→ **[Install it](/docs/aowlspt/installation)** ·
**[First run](/docs/aowlspt/getting-started)** ·
**[What it does](/docs/aowlspt/features)** ·
**[Mods](/docs/aowlspt/mods)** ·
**[Get a licence — $19.99/mo](/store/aowlspt)**

::: tip Looking for exhaustive detail?
The **[Reference](/docs/aowlspt/reference/)** section is generated directly from
source — [every host config flag](/docs/aowlspt/reference/host-flags) with its
type, default and read site; [every ABI header](/docs/aowlspt/reference/abi)
with its functions and design notes; [every mod](/docs/aowlspt/reference/mods)
with every settings key.

See also **[Automation](/docs/aowlspt/automation)** for driving the client
without a human, **[the method](/docs/aowlspt/method)** for how this project
decides something is true, and **[traps](/docs/aowlspt/pitfalls)** for the
hard-won facts that keep being rediscovered.
:::

---

## What you get

| | |
|---|---|
| **Offline raids** | Every map, with bots, generated loot, extracts and death handling. No server but yours. |
| **A working progression loop** | Profiles, the stash, traders and trading, quests with their conditions evaluated, the hideout and its production queue, the flea market, insurance, mail, skills, the scav. |
| **Bot AI worth fighting** | SAIN, rewritten natively: layered decisions, personalities, cover use, squad behaviour. MoreBots raises the population; Black Division adds a hostile PMC faction. |
| **The mods people actually run** | FOV fix, classic (no-inertia) movement, physical weapon sway, Path To Tarkov, a graphics overhaul, high-res PBR textures, resource packs, engine performance settings. |
| **In-game settings** | A settings page per mod, edited while the game runs, persisted back to the mod's `config.json`. |
| **A mod manager** | Enable and disable mods live — on the server while it serves, and on the client while the game is running. Mod lists are files you can commit and send someone. |
| **A mod API** | Write mods against one small C ABI, build them with one command, and test them without launching Tarkov. |

The full list, with what is playtested and what is still being tuned, is on
[Features](/docs/aowlspt/features).

## Install it

```
aowlspt-install install --source D:\Games\Tarkov --target D:\Aowlspt --payload payload
aowl importdb --from D:\SPT --out D:\Aowlspt\aowlspt
aowlspt-launch --root D:\Aowlspt
```

Three commands, once. Your existing install is only ever read — everything is
built into a second directory. The long version, including what each refusal
means, is on [Installation](/docs/aowlspt/installation).

## Who this is for

- **Players** who want a modded single-player Tarkov on a post-1.0 client, and
  are willing to run an installer and import a database once.
- **Mod authors** who want to reach a post-1.0 client at all — hooks, live
  objects, fields by name, and a per-frame fast path, with no BepInEx
  underneath. Start at
  [For mod developers](/docs/aowlspt/for-mod-developers).

## Scope, plainly

- **Single-player and offline only.** PvE. The client this produces plays
  against a backend on your own machine.
- **It must never talk to BSG's live service.** The installer does not carry
  BattlEye across and the launcher does not start it. Injecting a DLL into a
  process that is talking to BSG's servers has consequences for your account.
  These tools will not stop you pointing the client somewhere else, and they
  will not help you either.
- **Your existing install is only ever read.** If it goes wrong, delete the
  second directory.
- **You need an SPT install** to import the game's item, trader, quest and map
  data from. This project does not distribute BSG's data. Without that step the
  server starts, answers every route, and has nothing in it.
- **Windows only.**

## Getting the build

The code lives at `savannt/aowlspt` and is private; the documentation here is
public. The build is **[$19.99 a month](/store/aowlspt)** — every update, three
machines, the mods, cancel whenever. Questions first: Discord
**timbuktu_guy**.

## Where to go next

| | |
|---|---|
| [Installation](/docs/aowlspt/installation) | Requirements, the commands, and what lands where. |
| [Getting started](/docs/aowlspt/getting-started) | Your first launch: the launcher, the profile, the menu, the first raid. |
| [Features](/docs/aowlspt/features) | What the system does today, and what is still being tuned. |
| [Mods](/docs/aowlspt/mods) | Every mod that ships, and what each one is for. |
| [Bot AI](/docs/aowlspt/bot-ai) | The enemy-behaviour driver, and how SAIN, population, waypoints and ORBIT fold into one mod. |
| [Configuration](/docs/aowlspt/configuration) | The in-game settings pages, `config.json`, and where each file lives. |
| [Troubleshooting](/docs/aowlspt/troubleshooting) | The failures people hit, in the order they hit them. |
| [FAQ](/docs/aowlspt/faq) | Short answers: pre-1.0, multiplayer, BattlEye, SPT, updates, uninstalling. |
| [For mod developers](/docs/aowlspt/for-mod-developers) | What a mod is, the build command, and the shortest path to a running one. |
| [Under the hood](/docs/aowlspt/architecture) | The internals: the hosts, the ABI, IL2CPP, the game server, the engineering record. |
