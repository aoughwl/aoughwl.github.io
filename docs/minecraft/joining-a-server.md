---
title: Joining a Minecraft server
description: Why the ordering of a Minecraft join matters and what a client must do to render a server's world.
---

# Joining a server

The rule underneath a successful join: **a client must be able to name blocks
before it asks a server for any.** Right after a client leaves the configuration
phase, the server sends the chunks around spawn, each exactly once. Anything the
client cannot map to a block name at that moment is lost, and the world shows up
with holes.

In practice that means, in order: finish login and configuration, load the
registry so block ids map to names, and only then let play-state traffic
through. Starvation is the other failure: if the client stalls consuming
packets, the server stops sending, so reading must stay ahead of everything else
during the join.

Sections received are retained by position, so walking away from an area and
back restores it instead of re-requesting it. The client is checked with a suite
of scripted sessions against a real server, and the server itself is used to
confirm the block under the player's feet.
