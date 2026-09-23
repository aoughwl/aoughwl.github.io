---
title: Testing the Minecraft client
description: How the Jester Minecraft client is proven headlessly, and how to read its diagnostic counters.
---

# Testing and diagnostics

## Play scripts

The client is driven by play scripts: text files that pick a modpack, wait for a
state, click a menu item, walk, and assert on values the mods report. Twelve of
them pass against a live vanilla server, covering block import, world render,
returning to explored ground, entities, titles, boss bars, chat, flight, day and
night and weather.

A script can send a command to the server's remote console. That is the strongest
evidence available, because the words on the wire are Minecraft's own and not
ours.

## Recorded joins

A byte-exact recording of a real vanilla client's join is replayed over a loopback
socket, so protocol work is verified rather than guessed. Two independent
decoders agree block for block on thousands of checks against it.

## Diagnostic counters

Mods publish `[assert] name=value` values, which scripts read. The ones that
settled real bugs:

| Counter | Meaning |
| --- | --- |
| `voxel.server.socket` | -1 none, 0 connecting, 1 open, 2 closed |
| `voxel.server.greeted` | the handshake has been sent |
| `voxel.server.columnnote` | one column's geometry against the window's |
| `voxel.catalog.rows`, `rowsseen`, `reading` | inputs to "names are readable" |
| `voxel.dress.at`, `cursor` | progress of block-name resolution |
| `voxel.keep.misses`, `lastmiss`, `sections` | what a slide asked the keep store for |
| `voxel.stream.restored` | restores caused by a window slide only |

## Lessons about measurement

- Aggregates hide geometry. "1,176 sections outside the window" reads the same
  whether the window is one chunk off or in another world.
- A counter told only when it changes makes its own reset invisible. Tell
  counters every frame.
- A server's opening position is provisional. Reset walk counters on every
  placement, because a teleport is never travel.
- A quiet log does not mean a mod is not running; a busy mod can shout everything
  else down. Run the mod headlessly to ask directly.
- Every failure looks like "the server closed the connection" unless the socket
  counters exist, because the host reports every zero-byte read that way.

## Frame cost

A slow mod frame reports where it went, for example how much of it was host calls
and which call was busiest. That split is the whole question: in this project
nearly all of a catalog row's cost was interpreted string-building on the mod
side, not the host, and reading the bare millisecond number without the split
led to optimising the wrong half more than once.
