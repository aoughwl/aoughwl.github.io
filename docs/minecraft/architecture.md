---
title: Minecraft client architecture
description: The mods that make up the Jester Minecraft client and how a frame moves through them.
---

# Architecture

The client is a modpack: a set of Jester mods loaded together. Each owns one
concern and talks to the others through Jester's catalogs and the shared host
surface, never through hardcoded references.

## The mods

| Concern | Role |
| --- | --- |
| Importer | Reads an installed game, publishes blocks, models, recipes and sounds into catalogs |
| Voxel | World data, meshing, level of detail, streaming around the player |
| Network protocol | Wire framing, connection states, packet decode and chunk decode |
| Play client | Turns decoded packets into world, entity and inventory changes |
| Block mapping | Maps the names a server sends onto registry ids |
| Menu UI | Title, world select, options, pause |
| Sky and sound | Day cycle, weather, audio |
| Join helper | Reads a server address and starts the join |

Because they are all mods, one can be swapped for another. A different importer
can feed the same voxel mod, and the voxel mod does not care whether a world
comes from local generation or from a server.

## A frame

1. The play client drains the socket and applies decoded packets.
2. The voxel mod adopts any new chunk sections, restores kept ones, and slides
   the window if the player has moved.
3. Meshing and level-of-detail work runs under a per-frame budget.
4. Entities and the player are updated, and the UI mod builds its draw list.
5. The host draws, and reports the cost of any frame that ran slow together with
   where it went.

## Pacing

Work that scales with content is paced so a frame stays short: mesh rebuilds and
catalog reads run against per-frame budgets. There are two deliberate
exceptions, and both exist to protect the socket. When connected to a server the
block catalog read is unbudgeted, and the login and configuration phases are
serviced every frame, because they have hard deadlines.

## Catalogs

Block and model data is published into indexed catalogs. An early version scanned
linearly per insert, which made import cost grow with the square of the row
count. Catalogs are indexed now, and a test checks the ratio: four times the rows
must cost about four times, not sixteen.
