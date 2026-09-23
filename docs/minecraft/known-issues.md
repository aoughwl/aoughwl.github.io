---
title: Minecraft known issues
description: The open problems in the Jester Minecraft client, ordered by value.
---

# Known issues

1. **A long frame in the publish and icon pipeline.** The main remaining source of
   lag: a frame of a few seconds. It needs pacing, as other pipelines in the
   client already have.
2. **World generation is slow in the editor**, under one frame per second.
3. **Placing certain imported parts can crash the editor.** The suspect is a large
   metadata parse inside a re-entrant resolver.
4. **No dimension changes**, and no End.
5. **No online-mode authentication.**
6. **Player builds must not follow the import folder.** A build that follows a
   link to imported content can bundle tens of gigabytes that must never be
   distributed, and can fill a disk.

Older items that were fixed and are worth knowing about: the join ordering bugs
(see [Joining a server](/docs/minecraft/joining-a-server)), a quadratic catalog
insert, and a registry that was never re-read behind the menu.
