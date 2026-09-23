---
title: Minecraft on Jester
description: A Minecraft-compatible client that runs as a set of Jester mods and can join a real server.
---

# Minecraft on Jester

A Jester app that reads a Minecraft install you own and plays it. Terrain,
blocks, entities, UI and sound are all drawn by mods, and the client speaks the
Minecraft network protocol so it can join a server. It ships **no game content**:
assets are imported at runtime from your own copy of the game.

## Pages

| Page | What is in it |
| --- | --- |
| [What works today](/docs/minecraft/state) | Capabilities, gaps and the numbers behind them |
| [Architecture](/docs/minecraft/architecture) | The mods, and how a frame flows through them |
| [Importing your game](/docs/minecraft/importing) | How assets, blocks, models and recipes are read |
| [The network protocol](/docs/minecraft/protocol) | Framing, states, packets and chunks |
| [Joining a server](/docs/minecraft/joining-a-server) | The ordering rules that make a join render |
| [Playing and controls](/docs/minecraft/playing) | Menus, options, keys and the debug overlay |
| [Testing and diagnostics](/docs/minecraft/testing) | How it is proven headlessly, and what the counters mean |
| [Known issues](/docs/minecraft/known-issues) | Performance and gaps, in order of value |

## Why it is a Jester app

Everything in Jester is a mod loaded from data, and Minecraft is no exception.
World streaming, the protocol, the mapping of block names to ids, inventory, the
menus and the sky are separate mods with separate responsibilities. That means
each can be replaced, and it means the client can be developed and hot-swapped
while a world is running.

It is also a good workload for the engine. A Minecraft world is a large, dense,
constantly streaming data set drawn every frame, and most of what was learned
about Jester's catalogs, pacing and host-call cost came from making this run.

## Legal note

No Mojang assets, code or worlds are distributed with this project or this site.
The importer reads a game install that you already have, on your machine. The
client is intended for offline and LAN servers.
