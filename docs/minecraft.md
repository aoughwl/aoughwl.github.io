---
title: Minecraft on Jester
description: A Minecraft-compatible client that runs as a set of Jester mods and can join a real server.
---

# Minecraft on Jester

A Jester app that reads a Minecraft install you own and plays it: terrain,
blocks, entities, UI and sound are all drawn by mods, and the client speaks the
Minecraft network protocol so it can join a server. It ships no game content;
assets are imported at runtime from your own copy.

- [What works today](/docs/minecraft/state)
- [Joining a server](/docs/minecraft/joining-a-server)

Like every Jester app it is a set of mods, so each part (world streaming, the
protocol, the mapping of block names to ids, inventory) is replaceable.
