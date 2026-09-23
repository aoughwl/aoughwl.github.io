---
title: Minecraft client, what works today
description: The current capabilities and gaps of the Jester Minecraft client.
---

# What works today

**Single player.** Imported assets are read correctly (blockstates, block models
and recipes by the thousand). Terrain streams in around the player with level of
detail, blocks can be broken with crack stages and particles, and there is a
pause screen, a debug overlay, a sky, sound, entity models, and options screens
whose settings persist under Minecraft's own option names, with rebindable keys.

**Over the network.** The client logs in to a vanilla 1.21.11 server in
offline/LAN mode and renders its world, adopting tens of thousands of blocks
with no local generation. Health, hunger, experience, game mode, inventory slots
and entity events are reported into the game.

**Not yet.** Dimension changes, the End, and online-mode authentication are
absent. The client is checked with scripted play sessions against a live server
rather than by trusting this list, so treat it as a snapshot.
