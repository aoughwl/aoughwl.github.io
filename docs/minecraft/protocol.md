---
title: Minecraft protocol in the Jester client
description: How the client frames, decodes and applies the Minecraft network protocol.
---

# The network protocol

The protocol layer is a mod written in Nimony. It uses the host's plain TCP calls
and does its own framing and decoding, so the same code can be run under a test
harness with no game running.

## Target version

The client targets vanilla 1.21.11 (protocol 774) in offline or LAN mode.

## Layers

1. **Wire.** Variable-length integers, length-prefixed packets, strings, positions
   and the other primitive types.
2. **Framing.** A byte stream is split into packets, with compression handled
   after the threshold negotiated at login.
3. **State.** The connection moves through handshake, login, configuration and
   play. Each state has its own packet table.
4. **Chunks.** Chunk data is decoded into sections: paletted containers, block
   states and biome data.
5. **Play.** Decoded packets change the world, entities, inventory and the
   player's own state.

## Packet tables

Packet names and ids come from a table generated from the game's own data, not
from memory. A misspelled packet name matches nothing and fails silently, so the
constants are swept against the generated table in tests.

## Login

Login finishes with a packet that carries an identity: a UUID, a name and a list
of properties. It must be read in full. An early version treated it as empty and
failed one step after the handshake with a complaint about trailing bytes.

## Keep-alives and deadlines

A vanilla server drops a client that never speaks after the handshake within
about thirty seconds, and one that stays silent afterwards within forty-five. So
the socket must be serviced on every frame from the moment it opens, whatever else
the client is doing. See [Joining a server](/docs/minecraft/joining-a-server).

## What is not done

Encryption for online mode is not wired to a login flow, so servers requiring
Mojang authentication are out of scope.
