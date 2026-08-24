# Features

What aowlspt does today, on a post-1.0 client. Everything on this page has been
played; anything still being tuned says so in its own row.

[[toc]]

## Raids

- **Offline raids on every map**, populated by bots: scavs, PMCs and bosses, by
  faction and role.
- **Real bot AI.** SAIN rewritten natively — layered decisions, per-bot
  personalities, cover use, search behaviour, squads. MoreBots raises the
  population; Black Division adds a hostile PMC faction with its own roles,
  gear and spawn behaviour.
- **Generated loot, extracts, insurance and death handling.** Dying does not
  cost you your stash.
- **Path To Tarkov**, if you enable it: the deploy screen stops being a
  teleporter. You are standing somewhere, you may only go where that place
  connects to, and the map you climb out onto is where you now are.

## The progression loop

Served by the game server that ships with the system:

- Profiles, and **profile selection at launch**. Profiles survive a restart.
- The stash, traders and **trading**, with trader, quest and handbook **images**
  served to the client.
- **Quests**, with their descriptions and their conditions evaluated.
- The hideout and its production queue, the flea market, insurance, mail,
  skills, and the scav.

## Feel and visuals

| | |
|---|---|
| **FOV fix** | Optic and non-optic FOV multipliers, camera distance offsets, a zoom toggle. |
| **Classic movement** | No inertia, quick tilting, no bush slowdown, optional nostalgia mode — and the same for bots. |
| **Weapon sway** | Five physically modelled sources — respiration, cardiac, tremor, postural drift, weapon inertia — summed, scaled by the shooter's condition and the weapon, and pushed into the game's own rotation springs. |
| **Textures** | High-res PBR texture replacement, with a quality tier and a VRAM budget. |
| **Resource packs** | Swapping whole packs of game resources, with a drive-grade setting so a slow disk is not asked to do a fast disk's job. |
| **Performance** | Engine-level quality, HUD, application and time settings, plus a frame sampler. |
| **Graphics** | A togglable full-frame post-processing stack, with the game's own PostFX controls folded in as a subtab: tonemapping, exposure, contrast, saturation, temperature. *Defaults are still being tuned against real raids.* |

## Running the thing

- **In-game settings, in the game's own screen.** Tarkov's settings screen
  grows a sixth tab — **MODS** — beside Game, Graphics, Sound, Controls and
  PostFX. It carries a subtab per mod, plus the game server's own settings and
  the full server config surface. The rows are real Tarkov controls, not an
  overlay drawn on top. Edits persist back to that mod's `config.json` and
  hot-apply where the mod supports it.
- **PostFX now lives under Graphics.** The post-processing controls are a
  subtab of the Graphics tab rather than a tab of their own, which is what
  makes room for MODS.
- **A mod manager.** Turn mods on and off — on the server while it is serving,
  and on the client while the game is running. Your selection is a file, and so
  is a named mod list, so "my raid night setup" is something you can send
  someone.
- **Clean window and exit handling.** Closing the game closes the game; the
  launcher can take the backend down with it.
- **An admin panel** on **F6**: ESP, god mode, infinite stamina, no recoil, no
  weight, instant heal, unlimited ammo, thermal and night vision, fly, teleport.
- **Two logs that say what happened** — one for the client host, one for the
  server. [Troubleshooting](/docs/aowlspt/troubleshooting) is organised around
  the lines in them.

## For mod authors

- One small **C ABI**, three exported functions, and a mod library that the host
  loads, ticks and unloads.
- **Reach into the running game**: types and methods by name, live objects as
  handles, fields by name, hooks that read their arguments and can suppress the
  original, and a bind-once fast path for per-frame code.
- **Reach into the server**: routes, the database, the notifier websocket.
- **A settings API**: declare what your mod's config keys are, and they are
  drawn as native Tarkov controls in the MODS tab. No overlay, no F12 config
  menu of your own to write.
- **A simulator** that loads your mod with no game and no server behind it, so
  the edit-build-run loop is about a second.
- **A live inspector** — a diagnostics tool for developers debugging the game
  client while it runs, so a question about the running game does not cost a
  rebuild.

→ [For mod developers](/docs/aowlspt/for-mod-developers).

## Scope

Single-player, offline, PvE, Windows, post-1.0 clients only. Not multiplayer,
not a cheat against BSG's live service, and not a manager for other people's
BepInEx mods — see the [FAQ](/docs/aowlspt/faq).
