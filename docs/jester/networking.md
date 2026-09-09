# Networking

A length-prefixed TCP protocol, a server that relays, and an event log a mod
polls. There is no entity replication and no state-sync helper, and that is the
design rather than a stage it has not reached yet: what travels is decisions,
never objects.

[[toc]]

## Who is who

Every peer has two names and they are not the same thing.

- Its **id** is minted by the server, out of a counter no client can see, at the
  moment that peer is let in. It is stable for the life of that connection,
  distinct for every peer on the game, and the same string for everybody: the id
  the server minted for you is the id it stamps on your traffic for everyone
  else. **Key anything per-player by this.**
- Its **display name** is whatever that peer asked to be called. It is cosmetic,
  it is not checked, and it is not unique: two players called `bob` are two ids
  with one name.

A client never sends an identity. It sends a name, a password, and nothing else;
the sender slots on every frame it writes are read off the wire and thrown away,
and the server stamps its own record of who that socket is before relaying. A
joining client is told its id in the welcome frame and believes what it is told.
So **an id cannot be claimed, only received** — which is what makes it worth
keying on.

What this does *not* do is decide what a peer is allowed to *say*. Any peer can
send on any channel, and a mod that relays somebody else's id inside its own
message payload is trusting that peer rather than the transport. Who may send
what on a channel is an open decision and is deliberately not made here.
Placement is the one thing that is not left to a channel at all, for exactly
that reason.

## The session

| Call | Effect |
| --- | --- |
| `hostGame(port = 27015; password = ""; name = "player"): bool` | listens on all interfaces, mints its own id, emits a local `connected` event. False when the port could not be opened |
| `joinGame(address; port; password; name): bool` | blocking connect with a 5 s timeout and a password handshake. False when the server was absent, slow, or refused |
| `leaveGame()` | closes listener and peers, clears the last problem |
| `send(channel, data: string)` | server broadcasts and records locally; client sends to the server, which relays. Throws when not connected |
| `hosting()` / `joined()` / `connected()` | role flags |
| `problem(): string` | why the last host or join said no. Never contains the password |
| `me(): Peer` | the id the server minted and the name we asked for |

Hosting and joining fail for ordinary reasons, and a mod offering a join menu
has to survive them, so they answer `false` with a reason rather than aborting
the mod's frame.

## The event log

Events are read by polling. Each mod has its own cursor, initialised to the
newest sequence at load so a mod never sees pre-load traffic.

```nim
for ev in networkEvents():
  case ev.kind
  of Message: log(ev.sender.name & " on " & ev.channel & ": " & ev.data)
  of Placed:  build(placement())
  of World:   forgetEverything()
              for part in worldParts(): build(part)
  of Refused: log(ev.data)
  else: discard
```

| Kind | What happened | data |
| --- | --- | --- |
| `connected` | someone joined, or we did | — |
| `message` | a line on a channel | the line |
| `binary` | a payload on a channel | — (unreachable from a mod today) |
| `disconnected` | a peer said goodbye and closed at a frame boundary | — |
| `dropped` | a peer's connection failed under it | the socket error |
| `unintelligible` | a peer sent bytes this reader cannot make sense of | why |
| `missed` | this mod polled too slowly and the log moved on | how many went by |
| `world` | a whole world arrived at once | how many parts |
| `placed` / `removed` | a part is in the world, or gone | — |
| `refused` | the game said no to something *this* peer asked for | what and why |
| `error` | an incoming connection could not be accepted | the socket error |

Leaving, being cut off, and talking nonsense are three different events because
a mod may reasonably treat them differently: a clean departure is a player
choosing to go, a drop is worth a reconnect offer, and an unintelligible frame
is a version mismatch or something that is not a client of this game at all.

### Nothing a peer sends can end the process

Every read loop and the accept loop contain every exception they can raise, and
a frame that makes no sense ends that one connection with a reason rather than
escaping a background thread. **Lengths are refused before they are believed**:
a text field may claim at most 64 KB and a binary payload at most 16 MB, checked
while the prefix is still four bytes, so a claim of four billion bytes allocates
nothing. A message body gets its own 1 MB limit, and a mod that tries to send
more is told so rather than watching connections end. A socket that connects and
then says nothing is given ten seconds to finish its handshake and dropped.

This is proved over real sockets: six hostile peers — junk, an absurd length
prefix, an unknown frame type, a 2 GB payload claim, a clean leave and a reset —
each ending one connection with a reason while the game keeps relaying.

### The log holds what happened, never what is

It is capped and trimmed in blocks, so a mod that polls slowly does lose events
— but it is **told**: a cursor older than the oldest event kept gets one `missed`
event carrying the count before it gets anything else, and reading it is one
step rather than a walk over the backlog.

Bulk history does not go through the log at all. A world entered, a world handed
over on joining, or a world asked for again is **one** `world` event carrying
the world it announces, walked with its own iterator. So the size of a world has
nothing to do with the size of the log, and a full log means a mod that has not
polled for several seconds and genuinely is too slow.

## Building together

Placement is the one part of the network that is not a channel. A mod does not
announce that it placed something; it **asks**, the game decides, and every peer
— the asker included — is told.

That is what makes it authority rather than etiquette: the announcement is a
frame only the server is allowed to write, so a client cannot produce one by
sending the same bytes. A client may write place, remove and resync; a server
may write placed, removed and a refusal. A client that writes a *placed* frame
at a server is talking nonsense and its connection ends like any other frame
that means nothing.

**Placed parts are not network objects.** Nothing is spawned into a replication
table, nothing has a networked identity, and nothing is sent per frame. What
travels is one small request and one small answer, and then every peer builds
the part itself out of its own copy of the [catalog](/docs/jester/catalogs). A
hundred thousand parts cost a hundred thousand rows in a list and nothing else.

```nim
proc place(catalog, item: string) =
  discard requestPlacement(catalog, item, aim(eye).point)

proc build(p: Placement) =          # one part, however it arrived
  let thing = spawnPart(p.catalog, p.item, p.at)
  thing.rotation(p.turn)
  ids.add p.id                      # the id is the only name it has
  things.add thing
```

`requestPlacement` returns whether the request went out, never whether it was
allowed — the verdict is a `placed` or a `refused` event.

### What the authority actually decides

The server, and only the server, mints the id, and it is a counter over the life
of one game, so no peer can name a placement into existence or guess one that is
not there. It refuses a placement whose coordinates are not finite or are more
than 1e6 from the middle of the world, one that would take the world past
100,000 parts, and one whose catalog signature is not the one this world was
already built from.

**That is the whole of it.** There is no per-channel permission system, no rate
limit, no check on which catalog or which item, and no notion of a player who
may not build. Those are wider questions and this does not answer them.

**Who may remove what:** the peer that placed it, and whoever is hosting.
Nothing else — naming an id you did not place gets a refusal saying so, so an id
is a name and never a key. Building alone, you are the host, so undo and
clear-all work with nobody connected. A peer leaving does not remove what it
built; the world outlasts the session that made it.

**Late joiners.** The server keeps the live placements as an ordered log and
sends the whole of it to a joining peer in one frame, before that peer is on the
list that hears about new ones. Both halves happen under one lock, so a
placement made at that instant is either in the world that goes over or is
broadcast after it, never both and never neither. The joiner therefore builds
the same world as everybody else without anything having been spawned or
serialized.

**Bulk is not history.** Entering a saved world, joining a game, and asking for
the world again are the same thing three ways round. All three produce exactly
one `world` event, and the world it announces travels *with* it — so a mod that
reads that event ten frames later walks the world that was announced, not
whatever the world has drifted into since. Walking is not polling: nothing in a
snapshot expires, so a hundred thousand parts may take as many frames as they
take and none of them can be missed.

**Catalog divergence** is the one failure this design can produce, and it is not
left silent. A signature hashes a catalog's kind and every item in it — id,
contributing mod and value — sorted, so load order is not mistaken for
disagreement. The signature travels with every placement: the authority refuses
a placement whose signature is not this world's, naming both, and a receiving
peer can ask whether the placer's catalog was its own — with the engine saying
so in the log once per catalog whether the mod asks or not.

**What is not replicated:** everything after the placement. A part with physics
falls on each peer independently, and carrying, throwing and pushing are local.
The design replicates the *decision* to place, not the object, which is what
makes it cost nothing per frame; per-frame motion would be a different feature.

## Saving a world

A built world survives quitting, and what is saved is the placement log itself —
not the parts it produces — because the log is already the ordered, replayable
list of exactly the facts a peer needs, and replaying it into a mod is something
the engine does anyway every time somebody joins.

**Reloading is therefore the same code path as joining**: one `world` event to
walk, and every peer still builds every part itself. Nothing is serialized,
nothing becomes a network object, and the property the whole design rests on is
untouched.

| Call | Effect |
| --- | --- |
| `enterWorld(name = "default"): bool` | go into that saved world and keep it saved from here on. It arrives as one `world` event |
| `eraseWorld(name)` | throw away what was saved under that name. The only call that destroys a save |
| `leaveWorld()` | stop saving. What is on disk stays, and so does what is in this game |
| `worldName(): string` | which world is being written down |

A world name *is* a save profile name, so one slot is one folder holding both
the parts in it and every mod's memory of it.

**Whose save it is.** The world is the authority's. Hosting or alone, this game
writes it; joined to someone else's game, entering a world is refused, because
what a client is looking at is a mirror of a world that belongs to whoever is
hosting. A mirror is never promoted to a save. A world also cannot be swapped
under players who are standing in it.

**Ownership does not survive.** Peer ids are minted from a counter that starts
again with every session, so a part loaded from a save comes back owned by
nobody rather than by whoever is handed that id next. A returning player is a
new player.

**Catalog drift across time.** A placement names a catalog and an item, and the
catalog is rebuilt from whatever mods are loaded now. The rule is the strict
one: **a world loads only if every catalog it names is present in this session
and hashes to exactly what it hashed to when the world was saved.** Otherwise
nothing loads, nothing is written, and the problem names the catalog and both
shapes. It is all or nothing — a half-loaded world is the silent wrongness the
signature exists to prevent — and the file is left untouched, so putting the
mods back puts the world back.

**Crash safety.** Records are appended, one line each, because rewriting a
hundred thousand rows every time somebody puts down a brick is a stall and not a
save. Every record reaches the operating system as it is made and the disk at
least every two seconds, and a record counts as written when its newline is, so
a process killed mid-append loses that line and nothing else. A log that has
become more removals than world is republished the way mod state is: staged,
flushed, swapped over the live name — one copy of the crash-safety discipline
rather than two to drift apart.

## What is measured

Real OS processes, over real TCP, judged by what the mods say out loud rather
than by what the engine claims.

- **Building together.** Four processes of the real building mod: two place a
  part each, a third joins afterwards and is handed both, a peer is refused when
  it reaches for somebody else's, and a peer whose catalog is a different
  catalog is told so and refused. The three worlds are then compared as the
  three mods described them, line for line.
- **Restarting.** A process builds three parts into a world and is *killed*
  where it stands; a second enters the same world and reports the same three
  parts in its own words. A third, whose catalog differs, is refused with both
  shapes named; a fourth shows the refusal changed nothing on disk.
- **Scale.** In the runtime alone, **100,000 parts cost 21 MB and 0.1 s to
  place**, asking for the whole world posts **one** event, and the snapshot comes
  back in 0.1 ms. Over four more processes of the real mod: one builds 100,000
  parts into a saved world in 20 s (5 MB of log), a second reads them back off
  disk in 13 s, a third serves them, and a fourth is handed all 100,000 over a
  socket in 14 s and then asks for them all over again. Each of the five prints
  a fingerprint of what it is holding, all five are identical, and **not one
  event is missed anywhere**. The gate's own line reads
  `PASS: 100000 parts built and saved`.

## Voice

48 kHz mono, 960-sample chunks, 16-bit PCM, sent as binary frames on a reserved
channel. Capture and playback are driven from the runtime, independent of any
mod. A mod gets availability, open and close, mute, a talking flag, an RMS
level, a VAD threshold, push-to-talk with a key, and device enumeration and
selection.

Push-to-talk is honoured rather than merely stored: a chunk is transmitted only
when the mod is unmuted, the chunk is above the threshold, and either
push-to-talk is off or its key is down.

Playback is **unmixed and non-spatial** — every peer's chunks go through one
shared audio source with a fresh clip per 20 ms chunk. There is no jitter
buffer, no per-speaker volume and no positioning.

## Open decisions

- **Nothing decides what a peer is allowed to send.** Identity cannot be forged,
  but every peer may still send on every channel and the server relays whatever
  it is given. There is no way for a mod to declare that a channel is the
  server's to speak on, and no validation hook. That is the next decision, not
  an oversight.
- **Who may build at all is undecided.** The server decides whether a placement
  is *possible* and nothing about who is asking.
- **A wedged connection is noticed only at the next read or write.** There is no
  keepalive.
- **Binary payloads can be observed and not read** from a mod.
