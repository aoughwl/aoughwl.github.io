# Mods

Every mod that ships with aowlspt. Ports carry their upstream licence unchanged
and name their original author.

`registry/mods.json` in your install is the index: every mod, and every named
**list** that selects a set of them. A list is a document, so "my raid night
setup" is something you can commit and send someone.

[[toc]]

## Core

These are the system, not content.

| mod | side | what it does |
|---|---|---|
| **Tarkov game server** — `aowl.tarkov` | server | Profiles, the stash, traders and trading, the flea market, quests with their conditions evaluated, the hideout and its production queue, raids with generated loot, bots and scavs, skills, insurance, mail. Written entirely on the public mod API. |
| **Mod manager** — `aowl.manager` | server | Reads the registry, resolves it against your selection, and serves the answer — including *why* a mod is not loading — under `/aowlspt/mods`. |
| **Settings hub** | client | The **MODS** tab in Tarkov's own settings screen: a subtab per mod, drawn as native game controls from what each mod declares. |

## Feel and visuals

| mod | side | what it does |
|---|---|---|
| **FOV Fix** — `aowl.fovfix` | client | Fontaine's *Fontaine-FOVFix*, rewritten natively. Optic and non-optic FOV multipliers, camera distance offsets, a zoom toggle. CC BY-NC-SA 3.0. |
| **Classic Movement** — `aowl.classicmovement` | client | TheBoogle's *Old Tarkov Movement*: no inertia, quick tilting, no bush slowdown, optional nostalgia mode — and the same for bots. MIT. |
| **SPT-SWAY** — `com.savannt.sptsway` | client | Five physically modelled sources of weapon sway — respiration, cardiac, tremor, postural drift, weapon inertia — summed, scaled by the shooter's condition and the weapon, and pushed into the game's own rotation springs. |
| **Graphics** — `aowl.graphics` | client | A togglable full-frame post-processing stack: tonemapping, exposure, contrast, saturation, temperature. Ported and expanded from `TarkovGraphics`. The game's own PostFX controls are folded in as a subtab of the Graphics tab. Defaults are still being tuned against real raids. |
| **Textures** — `aowl.textures` | client | High-res PBR texture replacement from [ambientcg](https://ambientcg.com) sets, with a quality tier and a VRAM budget. |
| **Resource packs** | client | Swapping whole packs of game resources, with a drive-grade setting so a slow disk is not asked to do a fast disk's job. |
| **Performance** — `aowl.perf` | client | Engine-level quality, HUD, application and time settings, plus a frame sampler. |

## Bots, factions and maps

| mod | side | what it does |
|---|---|---|
| **SAIN** — `aowl.sain` | server + client | Solarint's SAIN, rewritten: layered decisions, per-bot personalities, real cover use, searching that looks like searching, squads that behave like squads. ~64,000 lines of BepInEx C# reimplemented against the native API. |
| **MoreBots** — `aowl.morebots` | server + client | Two jobs, as upstream had them: the bot-type and faction API other mods register against, and the mod that raises how many bots a map runs. CC BY-NC-SA 4.0. |
| **Black Division** — `aowl.blackdivision` | server | A hostile PMC faction — six roles with their own names, gear, difficulty and spawn behaviour — on top of MoreBots. MIT. |
| **Icebreaker** — `aowl.icebreaker` | server | The nuclear icebreaker BOREAS, locked in arctic ice: a map, delivered by rebinding the dormant `suburbs` location slot. MIT. |
| **Path To Tarkov** — `aowl.pathtotarkov` | server | The deploy screen stops being a teleporter. You are standing somewhere, you may only go where that place connects to, and the map you climb out onto is where you now are. |

## Tools

| mod | side | what it does |
|---|---|---|
| **Admin panel** | client | **F6** for an in-game menu of togglable cheat modes: ESP, god mode, infinite stamina, no recoil, no weight, instant heal, unlimited ammo, thermal and night vision, fly, teleport. ESP and god mode default on; everything else off. |

## Mod lists

| list | what it selects |
|---|---|
| `aowl.list.core` | The mod manager and the game server. The minimum that can serve. |
| `aowl.list.vanillaplus` | Core plus the mods that change how the game feels without changing what is in it: FOV, sway, classic movement, performance, textures. **The default for a fresh install.** |
| `aowl.list.raidnight` | Vanilla Plus with the bots turned up: MoreBots, SAIN, Black Division, Icebreaker and Path To Tarkov on top. |
| `aowl.list.headless` | Raid Night as a server operator wants it: the same content, with the client-only feel mods switched off. |

## Turning mods on and off

The mod manager serves your selection, and `disable`/`enable` record a decision
that `/aowlspt/mods/apply` performs. On the server that happens while it is
serving; on the client it happens while the game is running, provided the host
has a backend port to poll. Without one, the change takes effect the next time
the game starts. See [Configuration](/docs/aowlspt/configuration).

## A note on the registry

The registry does not yet name every mod that ships — the graphics,
resource-pack, admin and settings-hub mods have no entry yet. If a mod is
installed but not listed, the manager reports it as an unmanaged stray rather
than pretending it is not there.
