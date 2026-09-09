---
repo: savannt/jester
title: Jester — Unity, turned into a game you mod while it is running
---

# Jester

**A real engine, a real compiled language, no platform, and no built-in game to
work around.** The host boots, loads a shell mod, and the shell picks a modpack.
Player, weapons, world, inventory, the menu you just used: all mods, all
replaceable, all swappable without stopping the game.

Roblox and s&box let you build games on someone else's engine, in their sandbox,
shipped through their platform. Jester takes the other half of the idea.

|  | Roblox | s&box | Jester |
| --- | --- | --- | --- |
| Language | sandboxed Lua | C# | [aowlmony](/docs/aowlmony), statically typed, compiled |
| Iteration | restart the place | recompile, reload | edit while running, state survives |
| Built-in game | theirs | theirs | none; the menu is a mod |
| Cross-mod coupling | direct references | direct references | catalogs, no imports |
| Assets | their store | their pipeline | import from games you own |
| Distribution | their platform, revenue cut | their platform | one build, your releases |

Mods are written in **[aowlmony](/docs/aowlmony)**, compiled to a typed
intermediate form and executed by **[aowli](/aowli)** — the same interpreter the
[playground](https://aoughwl.github.io/playground/) runs on, embedded in the
Unity player behind a C ABI.

```nim
proc start() =
  createCatalog("weapons", "infiniteless.part", "Things to spawn")
  addToCatalog("weapons", "crate", "builtin://cube")

proc update() =
  if pressed(Space):
    discard spawnPart("weapons", "crate", vec3(0.0, 3.0, 0.0))
```

→ **[Getting started](/docs/jester/getting-started)** ·
**[The mod API](/docs/jester/mod-api)** ·
**[Catalogs](/docs/jester/catalogs)** ·
**[The host surface](/docs/jester/host-surface)**

> **Private repo, public docs.** The code lives at `savannt/jester` and is
> private. Questions: Discord **timbuktu_guy**.

[[toc]]

---

## Three hacks, stacked

### 1. The host is a very small Unity game

Jester is not an engine fork, a custom renderer, or a Unity plugin. It is a
Unity project of a few thousand lines that draws nothing and plays nothing. It
loads an interpreter, hands it a mod, and answers the calls that come back.

The boundary is **220 host calls**. That is the entire contract between a mod
and Unity, and the C# dispatch tables and the mod-side `importc` declarations
are the same 220 names — no case without a wrapper, no wrapper without a case,
and no mod declaring an `importc` of its own. Gameplay never crosses into C#;
C# never knows what game is running.

Because the host is small, it can be frozen. Ship it once, and every game after
that is content. [What it can and cannot reach today](/docs/jester/host-surface)
is counted call by call, including the parts that are still holes.

### 2. Reload the code, keep the data

`aowli` separates a module's code from its data. Rebuilding a mod replaces the
code and leaves the interpreter's globals where they are, so `update()` keeps
running against the same values it had a frame earlier. The host polls each
active mod's built artifact and swaps on change: no restart, no reconnect, no
reload prompt.

State that must outlive the process goes through `remember(key, default)`, which
reads from a host-side store rather than interpreter memory. That store is
flushed before every modpack switch and teardown, so it survives a crash, a
quit, or swapping the whole game out from under itself.

A mod that throws is caught, named, and left loaded — and after five consecutive
failures in one phase, that phase stops being called at all, so a broken
`update()` costs nothing per frame. Fixing the file clears the quarantine
without touching the session.

### 3. Importers are not a subsystem

There is no importer subsystem. A mod claims a file extension or a URI scheme,
and when something asks for a model nothing recognises, that mod is handed the
bytes and answers with `beginMesh` / `addVertex` / `addTriangle` / `finishMesh`.

That is all an "importer" is: a mod that speaks a format. The ones that ship
happen to speak OBJ, glTF, LDraw, Minecraft jars and Source model files, and you
can delete them or replace them like any other mod. Adding a format that does
not exist yet is the same work, and none of it touches the host. The
[mechanism](/docs/jester/importers) is the point; the format list is not.

Importers read from games already installed on the player's machine, in-game.
Jester ships no third-party content, so extraction is local and nothing is
redistributed — and each game's licence governs what a player may do with their
own copy. Multiplayer replicates catalog references and a content signature
rather than geometry, so peers rebuild from the copies they own.

## Catalogs

Mods cannot import each other, which means they cannot break each other. They
publish into **[catalogs](/docs/jester/catalogs)** instead.

One mod declares that a kind exists. Another creates a catalog of that kind. A
third fills it. None knows the others' names, types, or load order, and every
entry records which mod contributed it. Nothing is registered centrally and
nothing is edited to add content.

Concretely: a weapons mod creates `weapons`; an importer adds four hundred
entries to it; an inventory mod iterates it without knowing either of them
exists; removing the importer removes exactly its four hundred entries. Asking a
catalog nobody has created yet returns nothing rather than failing, because in a
system with no load order that is the ordinary state of a catalog before its
owner arrives.

## Networking

Peer identity is minted by the server, out of a counter no client can see, so an
id can be received but never claimed. Placement authority is decided per request
rather than by per-channel permissions: a mod *asks*, the game decides, and every
peer — the asker included — is told.

Parts are not network objects. Nothing is spawned into a replication table and
nothing is sent per frame; what travels is one small request, one small answer,
and a catalog signature, and every peer builds the part itself. Verified with
real OS processes over real sockets: **100,000 parts, zero events missed**, five
peers holding one fingerprint. [The whole model](/docs/jester/networking).

## Distribution

One host build, shipped once. Content updates arrive as mods, verified by
SHA-256 against a manifest, applied atomically, and picked up by the existing
reload path without a restart. The host self-updates by staged replacement when
it has to, which is rare by design. Releases go through GitHub Releases.

Manifest signing is designed and **not implemented** — the reserved `.sig`
assets are checked by nothing today, so an update is verified by hash and not by
signature.

## Where to go next

| | |
|---|---|
| [Getting started](/docs/jester/getting-started) | What a mod is, building one, the four callbacks, and the traps that cost the most time. |
| [The mod API](/docs/jester/mod-api) | The language-facing surface: three layers, the SDK modules, and what a mod can call. |
| [Catalogs](/docs/jester/catalogs) | The only cross-mod channel there is: kinds, ownership, generations, signatures. |
| [The UI library](/docs/jester/ui) | Clipping, ids, a pointer state machine, drag and drop — all in mod code, over three drawing calls. |
| [Importers](/docs/jester/importers) | The five stages, the file-access policy, and why the mechanism is not a feature list. |
| [Networking](/docs/jester/networking) | Identity, the event log, placement authority, saved worlds, voice. |
| [The host surface](/docs/jester/host-surface) | Every call area, measured; the reflection escape hatch and its exact walls; the ranked gaps. |
