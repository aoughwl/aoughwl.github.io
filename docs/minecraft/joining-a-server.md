---
title: Joining a Minecraft server
description: The ordering rules that make the Jester client render a real server's world, and the failures that taught them.
---

# Joining a server

The rule underneath everything: **a client must be able to name blocks before it
asks a server for any.** Right after a client leaves the configuration phase the
server sends the columns around spawn, each exactly once. Anything the client
cannot map to a block name in that window is adopted as air and is gone for good,
and the world shows up with holes.

## The order that works

1. Start the mods and let the importer publish block names.
2. Resolve every name a server might send onto a registry id, to completion.
3. Only then open the socket and begin the handshake.
4. Place the world window at the position the server gives, before adopting
   columns.
5. Service the connection every frame from then on.

## Five things that broke it

1. **Opening the socket at boot.** The join was requested twenty seconds before
   the catalog existed. Setup that only decides "this is somebody else's world"
   runs early; the connection itself waits until names are readable.
2. **Waiting inside the protocol.** Holding the configuration acknowledgement
   looks right and fails: once a vanilla server has sent its finish message it
   sends nothing further, not even keep-alives, and hangs up with a timeout.
   There is no backpressure in that state, so wait *before* connecting.
3. **Name resolution paced too finely.** Resolving 128 names a call left most of
   them unresolved when the join went ahead. Run it to completion first; with no
   socket and nothing drawn, pacing protects nothing.
4. **The wrong completion test.** A pass that finishes leaves its cursor at the end
   of the list, and zero means "not started". Gate on a completion marker, not on
   the cursor being zero.
5. **The window was at its birthplace.** Columns were written against origin
   `(0,0)` while the player was far away, because placement lived only in the
   steady-state path and the menu path skipped it. Both now call the same routine.

## Two starvation rules

- **Service the control plane every frame.** Login and configuration have a
  thirty-second deadline, and the staged boot, the menu and a catalog re-read each
  return early. An unconditional step for a not-yet-playing connection sits at the
  top of update.
- **A catalog catch-up must never starve the socket.** In server mode the read is
  unbudgeted, because fifty frames of paced reading is fifty frames of not being
  connected.

## Do not ask about the player before there is one

Reporting the block under the player's feet requires the player's position, and
during boot there is no player yet. The host refuses the call, the mod's update
throws and the mod is quarantined, which looks exactly like a connection timeout.
Only the world-free half of the report may run during boot.

## Retention

Sections are retained by position, so walking away and back restores ground
instead of re-requesting it. The server is used as the referee: a command over the
server's remote console confirms the block under the player's feet independently
of anything the client claims.
