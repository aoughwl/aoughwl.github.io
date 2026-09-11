---
title: Jester — Unity, turned into a game you mod while it is running
description: A Unity host that never leaves Play mode. Gameplay is compiled aowlmony, run by an interpreter — and there is one running on this page, in JavaScript, on the same artifacts the desktop player loads.
---

# Jester

[Unity](https://unity.com) 6000.6.0f1 is the host, and the host is a few
thousand lines that draw nothing and play nothing. Everything else — player,
weapons, world, inventory, the menu you booted into — is a mod:
[aowlmony](/docs/aowlmony) source, statically typed, compiled by our own
toolchain, executed by [aowli](/aowli). The constraint the rest of the design
follows from is that **you never leave Play mode.** Add a mod, edit it, remove
it, load it, unload it, rebuild it — while the game is running, against the
state it had a frame earlier.

The rest of this page argues that. The demo does not: it is the thing itself.

## The demo is the engine

<iframe src="/jester-demo/" title="Jester running in the browser" loading="lazy"
        style="width:100%;height:820px;border:1px solid var(--vp-c-divider);border-radius:6px;background:#0a0c11"></iframe>

That frame is `aowli` — the same interpreter the Windows player embeds behind a
C ABI — **compiled to JavaScript, not WebAssembly**, drawing through a Canvas 2D
context. The `.s.nif` artifacts it loads are the bytes `tools/build_mod.exe`
published into each mod's `.infiniteless/live/`, copied without transformation:
byte for byte what the desktop player loads. Nothing on the page is a recording.

Three things worth doing with it.

**Arrow-key the boot menu.** `infiniteless.shell` is the mod the desktop player
starts in, drawing the 35 modpacks this repository ships, hit-testing your
pointer and answering your keys. It is a menu, so the page spends a frame when
you do something and not otherwise.

**Load a different mod into the running page.** `demo.web` animates;
`example.readout` is a stock example, unmodified. Each load builds a fresh
interpreter, and the page around it never stops. *Unload* leaves the host
running and drawing nothing, which is what a host with no game loaded should
look like.

**Load a different build of the mod that is running.** `demo.web` ships as three
artifacts, compiled from the three sources shown under the canvas. Loading one
changes the code without touching the page: `frame` restarts, because
interpreter globals do, and `visit` does not, because that counter goes through
`remember`/`save` — host-side state rather than interpreter memory. That is half
of hack 2, and it is the half a browser can show.

The other half is the swap: replace the code and keep the interpreter's globals
too, so `frame` never resets. **That does not work in this browser build, and
the page does not pretend it does.** The seam is wired to aowli's `swapHot` with
`runInit = false` — the same call the native host makes — and it returns
success, raises nothing and increments the module generation while the
interpreter goes on executing the *previous* body. It was measured rather than
assumed: hooking the host call that draws the title bar, a build whose only
change is the string it draws still sends the old string after a swap, and a
plain load of those same bytes sends the new one. So the artifact, the payload
and the virtual filesystem are all fine and the fault is inside `swapHot` on
this target. It is a bug worth fixing, not a limit worth writing around.

### What the browser cannot do

No scene. Nothing 3D exists in this host — no `game_object_create`, no meshes,
no physics, no character controller, no raycast — so a modpack that draws a
world would select and then show nothing. Of the 440 host calls a browser can
serve 380: 122 involve no platform capability at all, 125 map onto a browser API
directly, 133 need a named substitute, and **60 it cannot serve**. Those figures
are derived rather than typed — `web/triage.mjs` reads the live call list out of
the C# dispatch table and refuses to print the table at all while any call has
no verdict.

It used to have a budget, and now it has a frame stack. The JavaScript backend's
storage for value aggregates is a bump pointer, and the runtime never rewound
it — a C stack with no return — so every frame of interpreted work spent a
little of a 1 GiB ceiling and a page eventually had to be reloaded. Measured on
this demo: **627 MB gone after four minutes at ten frames a second**, heading for
the wall.

A bump pointer that models a C stack is a thing you can pop. `boot.js` takes a
mark before `update` and `drawGui` and releases it after, and refuses the
release on any frame where the interpreter's own heap grew above that mark,
because those pages outlive the call. Same mod, same four minutes, the same work
to within one percent of the draw calls: **7 MB**. The gauge still reads the real
pointer, because a flat line is the evidence. The tick runs at sixty now rather
than ten.

What is still not freed is a *retired* interpreter. Loading another mod leaves
the previous one's state behind — about 1.3 MB a load, measured at 25 MB after
eighteen. That is hundreds of loads from the ceiling rather than a handful, so
it is no longer a budget, but it is not nothing and it is not fixed. And the fix
that *is* in is a patch applied over the generated bundle
(`tools/frame-arena.mjs`), which is the wrong home for it: it belongs in the JS
runtime itself, where every embedder would get it. The desktop build has neither
problem.

[**The browser build's memory**](/docs/jester/browser-memory) is the whole story
— the diagnosis, the fix, the measurement, the one case the release has to
refuse, and what is still broken. It is written as a handoff for whoever moves
it into the runtime.

First load is about 11 MB of JavaScript and artifacts, roughly 1.2 MB over the
wire after gzip, and cached after that.

### How it was built

`web/build.sh` in the engine repository puts `web/webmain_host.nim` — the C ABI
seam the Unity host uses, with JavaScript on the far side instead of C# —
through the nimony frontend and the JS backend, and concatenates the result into
one bundle. It reports a link failure on the way past, which is expected: the
32-bit C link is not what this lane wants and nothing links here.

Two changes were needed to make that bundle load a mod at all, and both are in
aowli rather than in Jester. `lib/vfs.nim` exists so a host can put its own
storage behind the module loader, and the browser build does — but
`modload.nim`'s two guards, `artifactReadable` and `moduleArtifactsPresent`,
ask `std/os.fileExists` instead of the relay. On a filesystem that is the same
answer; in a browser it is `false` for every artifact the virtual filesystem is
holding, and before that it was worse — `fileExists` compiles down to a libc
`stat` the JS environment does not define, so the page died on an undefined
name. Routing both guards through `existsRelay` fixes it. The bundle served here
is built with that change; it is a two-line fix and it belongs upstream.

`tools/pack-jester-demo.mjs` in this repository collects the artifacts, and
`tools/verify-jester-demo.mjs` drives a real headless Chrome at the published
page — loads each mod, loads each build, unloads, and prints what the mod
actually asked the host for and what the host had to decline. On the run that
produced this page: every call served, nothing declined, no page errors.

## What it is, by comparison

**Roblox and s&box** let you build games on someone else's engine, in their
sandbox, shipped through their platform. Jester takes the other half of the
idea: a real engine, a real compiled language, no platform, no revenue cut, and
no built-in game to work around. It is simpler than either — the entire contract
between a mod and Unity is one list of 440 calls — and more open-ended, because
there is no shipped game whose assumptions you are modding around. The host
boots, loads a shell mod, and the shell picks a modpack. The menu you just used
is a mod as well.

|  | Roblox | s&box | Jester |
| --- | --- | --- | --- |
| Language | sandboxed Lua | C# | [aowlmony](/docs/aowlmony), statically typed, compiled |
| Iteration | restart the place | recompile, reload | edit while running, state survives |
| Built-in game | theirs | theirs | none; the menu is a mod |
| Cross-mod coupling | direct references | direct references | catalogs, no imports |
| Engine access | sandboxed | their API | typed API, with a raw escape hatch |
| Assets | their store | their pipeline | read them out of games you own |
| Distribution | their platform, revenue cut | their platform | one build, your releases |

**Electron** is the other comparison, and a newer one. A frameless desktop
window family and an HTML/CSS document renderer both ship here as ordinary mods,
so an application is a modpack plus a shortcut. Electron's answer to shipping an
app is a copy of the whole browser per app; Jester's is the .NET runtime's — one
host, installed once, shared by everything, updated on its own schedule. The
committed player was measured at **155 MB of working set and 287 MB of private
bytes** over five launches, by the method `docs/FOOTPRINT.md` sets out. Read that
against Electron's rough public shape — 100–150 MB for a trivial app, 300–800
for a real one — and keep the caveat that page states itself: **no Electron
application was measured on that machine.** It is a comparison against a
reputation, and it is worth redoing properly before anyone leans on it.

What Jester is *not*, today, is a sandbox. The surface is finite and enumerable
and gameplay is interpreted rather than native, so a mod cannot execute
arbitrary machine code by construction and cannot reach a name the host does not
answer. A capability model over that surface is in progress; until it lands, read
"no platform" as *nobody takes a cut*, not *safe to run a stranger's code*.

## Three hacks

**1. The host is a very small Unity game.** Not an engine fork, not a custom
renderer, not a plugin. It loads an interpreter, hands it a mod, and answers the
calls that come back. The boundary is 440 host calls at surface version 1.8.0,
**as of commit `f559ceb`, 2026-09-10** — that is the whole contract — and the C#
dispatch table and the mod-side `importc` declarations are the same 440 names,
checked against each other by a gate rather than by hand. Every count on this
page is pinned to that commit, and [the section below](#the-numbers-on-this-page-and-where-they-came-from)
says why. A mod declares the surface version it needs and
discovery refuses it by name if this host cannot serve it. Because the host is
small it can be frozen: ship it once, and every game after that is content.

**2. Reload the code, keep the data.** `aowli` separates a module's code from
its data. Rebuilding a mod replaces the code and leaves the interpreter's
globals where they are, so `update()` keeps running against the values it had a
frame earlier. The host watches artifact timestamps and swaps on change: no
restart, no reconnect, no reload prompt. State that has to outlive the process
goes through `remember(key, default)`, which reads a host-side store rather than
interpreter memory and is flushed before every modpack switch and teardown. A
mod that throws is quarantined, named and left loaded, so fixing the file brings
it back without touching the session. The demo above is the browser's half of
this: new code without a page reload, and remembered state that outlives the
interpreter it was set in.

**3. Mod games that were never meant to be modded.** Every game ships its
content in some container: an archive format, a mesh format, a texture format.
A mod claims a file extension or a URI scheme, and when something asks for a
model nobody recognises that mod is handed the bytes and answers with
`beginMesh` / `addVertex` / `addTriangle` / `finishMesh`. That is the entire
mechanism, and it is why the readers that exist — Source, Minecraft, Tarkov,
OBJ, glTF, LDraw — are ordinary mods you can delete, replace or ignore rather
than shipped features. A game's own modding surface is whatever its developers
chose to expose, and it is usually a fraction of what is on disk; read the
container yourself and that ceiling is gone. Reading happens in-game, on the
player's machine, from a copy they installed. Jester ships no third-party
content and redistributes none — multiplayer replicates catalog references and a
content signature rather than geometry, so every peer rebuilds from the copy it
owns — and each game's licence governs what you may do afterwards.

## Two ways down to the engine

Most engines make you choose: a safe high-level API that cannot do the thing you
need, or raw access you will regret. Both ship, to the same mod. The floor is
`unity_get`, `unity_set`, `unity_call` and `component_add`, which reflect into
UnityEngine types, so a mod can reach an engine feature the SDK never wrapped
without waiting for anyone. Above it sits a typed API — vectors, colours,
entities, input, drawing, meshes — which is what you should actually write. The
escape hatch exists so you are never blocked; the layer above exists so you
rarely want it.

Mods cannot import each other. They publish into catalogs: one mod declares a
kind, another creates a catalog of that kind, a third fills it, and every entry
records its contributor. Removing a mod removes exactly its entries, and one mod
cannot break another by changing a signature because there are no signatures to
change. It buys coupling that cannot break with coupling that cannot be checked,
and [the catalogs page](/docs/jester/catalogs) is honest about the second half.

## The numbers on this page, and where they came from

The engine repository gates its own prose. `CLAIMS.tsv` pairs every figure in
every document with the command that printed it, and `tools/claimcheck.exe`
re-runs those commands and stops when one disagrees. It has no `--fix`, on
purpose: a checker that edits the prose to match the gate does not verify the
claim, it launders it. Run on 2026-09-10 it read **106/106 verified, 0 wrong,
0 unverifiable**.

**Every count of the host surface below is pinned to commit `f559ceb`
(2026-09-10), and says so.** The surface is under active development and moves
several times a day — it moved twice while this page was being edited. A figure
with no commit beside it is wrong the moment it moves, and re-deriving it every
time the tree changes only means publishing a number that is stale by the time
anyone reads it. A figure *with* a commit beside it is true permanently: it will
still be true when the surface passes five hundred, and a reader can check it by
looking at that commit. So the pin is the honest form, not a hedge. What does
not go stale is the derivation, which is why it is still in the right-hand
column.

| figure | how it was derived |
| --- | --- |
| 440 host calls, at `f559ceb` | the gate reads the prefix-family list out of the C# dispatch itself and then counts each family's cases, so a family nobody told it about is still counted. 158 are inline `case` labels and 282 live in 11 prefix-owned tables |
| the same 440 names on the mod side, at `f559ceb` | the `importc` declarations under `ModSdk/`, deduplicated — overloads share one host call. This is an independent derivation that happens to agree: it reads the mod side of the boundary, the row above reads the host side |
| surface version 1.8.0, at `f559ceb` | `HostSurface.Version` |
| 51 mods, 35 modpacks | the committed `mod.json` and `modpack.json` sets; the shipped player prints the same pair into its session log at boot |
| 155 MB working set, 287 MB private | five launches of the committed IL2CPP player sampled through `System.Diagnostics.Process`; `docs/FOOTPRINT.md` gives the machine, the method and the run-to-run spread |
| 380 of 440 servable — 122 pure, 125 native, 133 shim, 60 no, at `f559ceb` | `node web/triage.mjs` against `web/triage.tsv`, which refuses to answer while any call is untriaged. A third independent route to the same 440, and the one that has to name every call rather than count them |
| 627 MB before the frame stack, 7 MB after | `LIMIT=240000 MOD=demo.web node tools/measure-demo-life.mjs`, run either side of `tools/frame-arena.mjs`: it drives a headless Chrome at the page for four minutes and reports the JS backend's bump pointer, read directly rather than estimated. The two runs made 3948 and 3990 `draw_fill` calls, so it is the same work both times |
| about 1.3 MB left behind per mod load | `LOADS=6 node tools/measure-demo-life.mjs`, which loads every mod in the payload six times round and reports the pointer after each cycle: 25 MB after eighteen loads |
| ~11 MB of assets, ~1.2 MB gzipped | the demo's own harness, which serves the page compressed and adds up what Chrome actually fetched |

Numbers that are deliberately absent: no throughput benchmark, no frame time, no
"N times faster than". None of those has been measured in a way worth quoting.

## Where to go

- **[The documentation](/docs/jester)** — getting started, the mod API,
  catalogs, the UI library, importers, networking, the host surface. Some of its
  counts predate the current surface and are being regenerated; the figures on
  this page are the freshly derived ones.
- **[aowlmony](/docs/aowlmony)** — the language mods are written in: a
  from-scratch clone of the unreleased Nim 3.0, finished, with an interpreter.
- **[Releases](https://github.com/savannt/jester-release)** — the public build.
- **[Discord](https://discord.gg/nxa3W7w4rJ)** — where this is being built.
