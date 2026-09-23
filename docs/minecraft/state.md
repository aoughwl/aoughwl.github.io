---
title: Minecraft client, what works today
description: The current capabilities and gaps of the Jester Minecraft client, with the numbers behind them.
---

# What works today

This page is a snapshot. The client is checked with scripted play sessions
against a live server (see [Testing and diagnostics](/docs/minecraft/testing)),
which is a better guide than any list here.

## Single player

- **Import.** Assets read correctly: about 1,168 blockstates, 2,390 block models
  and 1,470 recipes, giving roughly 1,172 registered blocks.
- **Terrain.** Level-of-detail terrain follows the player at about 5 to 8 chunks
  per second.
- **Interaction.** Blocks can be broken with crack stages and particles.
- **Interface.** Pause screen, debug overlay, sky, sound, entity box models and a
  spawn menu.
- **Options.** Nine options screens whose settings take effect and persist under
  Minecraft's own option key names, plus 34 rebindable keys.

## Over the network

The client logs in to a vanilla 1.21.11 server in offline or LAN mode and
**renders its world**: on the reference run about 95,900 blocks were adopted from
the server with none generated locally.

Reported into the game from the server: health, food, experience, game mode,
inventory slots, held item, entity spawns, movement, damage and death, and block
digs, placements and edits.

Twelve scripted sessions pass against a live server: block import, world
render, returning to explored ground, play, entities, titles, boss bars, chat,
flight, day and night, weather and sky.

## Chunk retention

The client keeps every section the server describes, keyed by chunk position, and
restores them when the window slides back. This matters because the near window
is only three chunks across, so a slide happens every sixteen blocks. Sections
are kept even when they land outside the window, since keeping only what fits
would recreate the same hole one chunk further out. A server's `forget chunk`
packet evicts, which also bounds memory.

## Not yet

- Dimension changes and the End.
- Online-mode authentication (the encryption primitives exist in the host but are
  not wired to a login flow).
- Full parity of inventory, combat and mob behaviour with vanilla.
