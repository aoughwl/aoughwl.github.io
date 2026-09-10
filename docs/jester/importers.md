# Importers

There is no importer subsystem. An importer is a mod that claims a file
extension or a URI scheme and gets handed the bytes. This page is about the
mechanism, because the mechanism is the interesting part; which formats happen
to have a mod today is not.

[[toc]]

## An importer is a mod that speaks a format

Two claims, and they are catalog items like any other — the item id is the
scheme or the extension, and the value is the name of the proc that answers:

```nim
proc start() =
  provideScheme("minecraft")            # minecraft://block/stone
  provideModelFormat(".obj")            # anything named *.obj
```

When something spawns a part whose reference names a scheme nothing recognises,
the request is refused and the registered schemes are named. When it names one
this mod claimed, this mod's proc runs, reads the request, and answers with
exactly one of three things: use a built-in shape, use a model file, or describe
a mesh here and now. No answer, or more than one, throws.

```nim
proc resolvePart() =
  let req = partRequest()               # scheme and locator
  if req.locator.startsWith("block/"):
    beginMesh()
    discard vertex(vec3(0.0, 0.0, 0.0), up, vec2(0.0, 0.0))
    ...
    triangle(0, 1, 2)
    useTexture("Imported/block/stone.png")
    finishMesh()
```

The host builds the mesh filter, the renderer and the collider, and knows no
format at all. An extension nothing claims throws, naming the claimed ones.

### Which way round a triangle goes

Order the three indices so that the right-handed cross product of the first two
edges — `(b−a) × (c−a)` — points along the face's **outward** normal. `quad`
wants its four corners walked that way round the face and makes two triangles of
them. Get it backwards and the face is invisible from outside and solid from
inside, which is the classic way an imported model comes out inside-out.

It is worth saying why the right-handed convention is still right when Unity is
left-handed. Unity's own built-in quad has triangles wound so that the
right-handed cross of the first triangle's edges *is* its outward normal. A
front face is clockwise on screen in Unity, and the Z axis flips the screen
mapping, so the two statements agree: describe geometry right-handed and it will
render facing the way you meant. Nothing in the mesh builder reorders anything.

This was a real bug before it was a rule — the top and bottom faces of an
imported cube came out inside-out — and the importer's test now asserts it for
every triangle it builds.

### The cost of a crossing, and the wide calls

Every mesh call leaves the interpreter, crosses the C ABI and comes back, at
roughly 4 µs whatever it carries. On a generated 26k-vertex, 51k-triangle grid
that is 129k crossings and 517 ms one number at a time, and 51.5k crossings and
223 ms using the vertex-with-channels call and `quad`: **2.3× for the same
mesh**.

There is no flat-array call, and it is not an oversight. The interpreter
marshals a mod's argument into one of nil, integer, number, boolean or string
and refuses everything else, so a sequence has no representation at the seam at
all; packing one into the one variable-length kind that does cross — a string of
numbers — costs the interpreter more than the crossings it would save. So the
bulk path is as wide a call as fixed scalar slots allow, and it is a half-measure
until the seam grows an array kind.

Widening the call is also not what makes a *parsed* model fast. A 3.5 MB,
51k-triangle OBJ spends about 40 s in the mod's own parsing loop and about 1.4 s
crossing the boundary. **The cost of a big model today is the interpreter, not
the seam.**

### A provider is held to three rules

Because one that hangs or loops would otherwise take the session down with it:
it may not ask for a part it provides itself, directly or through anyone else;
delegation is capped at eight deep; and a provider that claims a key and ships
no proc to answer with is a configuration error rather than a silent no-op. A
mesh is capped at 2²¹ vertices and the same in triangles.

## Bringing in a game the player owns

The other half is getting a file onto the disk in the first place. Jester ships
no third-party assets and never will. What it ships is a way for a player who
owns a game to point at their own install and have the models and textures
already on their disk turn into parts this game can spawn.

Five stages, and only the last two are ever about a particular game.

| Stage | What it is | Where it lives |
| --- | --- | --- |
| **Locate** | a folder the player granted, and a file only that game has, so a folder is identified by content and not by its name | generic |
| **Enumerate** | what that folder or archive holds: names, sizes, folders | generic |
| **Extract** | the ones wanted, inflated out of the archive into the importing mod's own folder | generic |
| **Convert** | the game's own format read into geometry and pictures | per source, and lazy |
| **Catalogue** | one item per thing, in a catalog | per source, using the same catalog API as everything else |

### Why convert is lazy

Converting eagerly would mean thousands of meshes built at import time and held
forever. Instead the import writes the *game's own files* into the mod's folder
and publishes a catalog whose values are references — `minecraft://block/stone`
— and the mesh is built when something spawns that reference, by the scheme
provider the mod registered. That is not a special path: it is the ordinary
parts path above, and it means an import costs disk and not memory.

### Where the output goes

Inside the importing mod's own folder. That is not a convenience — it is the
only place the parts system can already read from, because a model file is
resolved relative to the folder of the mod that contributed the catalog item and
a texture relative to the calling mod's. An import that lands there is ordinary
mod content the moment it finishes, with no new asset scheme, no new loader and
no change to spawning. The convention is an `Imported/` folder mirroring the
source layout, with a `.gitignore` beside it.

### Progress and failure

An import is minutes of disk, so nothing about it may block a frame and
everything about it must be visible. A scan or an extract returns a **job id**
at once, or zero with a sentence saying why. The job is polled from `update()`:
done, progress, total, the file it is on right now, and the error. **Nothing is
ever delivered to a mod by the worker thread** — mods are only ever called on
the engine thread, and they find out by asking there.

A *plan* runs on top of that: a queue of jobs driven one at a time from
`update()`, answering idle, running, step-done, done or failed, with one line of
text fit for the screen. An importer's whole progress UI is a percentage and
that line.

### Being interrupted is cheap

The plan remembers its cursor in mod state, so a quit, a crash, a hot swap or a
modpack switch resumes at the step it reached. And the host **skips a file
already there at the size it should be**, so re-running a finished extract of
two thousand files writes nothing and touches no timestamp — even a plan that
lost its cursor costs a re-scan and not a re-copy. Cancelling keeps what was
already written; undo is one call, because everything an import wrote is under a
single folder.

### The ledger

An import declares what it produced by writing a receipt into a catalog: the
importer's own name for the import, and a value naming the catalog it filled,
how many items went in, and a sentence. Anything that wants to know what this
machine holds walks that catalog — without knowing what any of the importers
were.

## The file-access policy

A mod runs in an interpreter with scalar host calls. It cannot walk a directory,
open an archive, write a file or start a process — and must not be able to,
because it is untrusted code and what it would be walking is the player's own
machine. It is also slow on bytes, so inflating a 29 MB archive in the
interpreter is not a slow path; it is not a path. So the host grew one family of
calls, and two boundaries that are the whole of the safety story:

- **Reading happens only inside a root the player granted**, one line at a time
  in a file beside their saves, re-read live, with an environment variable
  saying the same thing for a launch script or a headless run. **No manifest can
  grant itself a root.** A mod that wants one prints the line to add and waits.
- **Writing happens only inside the calling mod's own folder.** There is no call
  that writes anywhere else, and no call that reads a granted root into anywhere
  else. Every path goes through one normaliser that refuses `..`, absolute paths
  and drive letters.

Jobs belong to the mod generation that made them. A different mod polling the
same id gets nothing; an unloading generation has everything cancelled and
dropped. Limits are refusals rather than truncations: 400,000 entries a scan,
256 MB a file, 8 GB a job, 4 MB a text read, four jobs running and 64 held per
mod.

**Containers.** The host opens the zip family, and a mod *asks* rather than
assumes — it can enumerate what this host can open, and ask about one extension —
so a source whose container this host cannot open is a sentence on screen rather
than a failure halfway through.

**No mod can start a process, and none should.** A mod that can start a program
is a mod that can do anything. Where a source needs an external extractor, the
shape that fits is: the player runs the tool, grants the folder it wrote to, and
an importer walks that folder with the existing generic stages and no new host
surface at all.

## What is proved

The host half, compiled and run directly — 51 checks: the grant policy, a line
added being picked up live, `..` refused in every path argument, scanning a
folder and a zip filtered by glob, extraction landing inside the mod with
archive-relative paths intact, a second run rewriting nothing, another mod being
unable to see a job that is not its own, and undo counting what it took. Against
a real install: **2,390 block models extracted in 962 ms**.

The mod half, the real compiled importer in the real interpreter driven by a
harness answering the same protocol — 20 checks: the install is found, 2,390
models and 1,111 textures are written and **2,390 items land in the catalog**
over 360 `update()` calls in 3.7 s with no frame doing more than polling; a
receipt lands in the ledger; a reference resolves to 24 vertices and 12
triangles, every one wound outwards, wearing its own picture. And with every
grant taken away afterwards, the part still resolves — what was imported is the
mod's own content now.

## The legal framing, honestly

This architecture is the defensible one, and it is not automatically "100%
legal".

What is true: the project ships no third-party assets, the game distributes
none, and everything an import touches is a file already on the player's own
disk, put there by a copy of a game they bought. Nothing is downloaded, nothing
is uploaded, and the output is git-ignored. Format knowledge — how an archive is
laid out, what a field means — is not itself anyone's asset.

What is not settled by that:

- **EULAs differ, and some of them prohibit this.** They are not made irrelevant
  by the extraction running locally. A player may be permitted to do this with
  one game and in breach with another, and this design does not tell them which.
  **Each game's licence governs what you may extract.**
- **Redistribution is the bright line.** The moment an imported asset travels —
  a modpack shared with a friend, or a multiplayer session that sent geometry
  rather than a catalog reference — it is distribution of someone else's work.
  Placement here is already sent as a catalog reference plus a signature and
  never as a mesh, which happens to be exactly right: two peers who both own the
  game agree, and a peer who does not own it fails the signature check rather
  than being sent the asset.
- **Trademark and passing off are separate questions** from copyright.
- **Circumvention is a different statute again.** Nothing here breaks encryption
  or a licence check, and nothing here should ever start to.

What the design keeps doing: never bundle, never fetch, never redistribute;
require an explicit per-folder grant the player types themselves; keep the output
inside the importing mod; and make an import easy to take back. This is a
description of the design's posture and not legal advice.

## What is missing

- **One material per model.** A mesh is one mesh with one material, so a model
  whose faces differ wears the first face's texture on all of them. Submeshes
  are the fix, and the texture path is shaped to follow them.
- ~~**No skinning and no animation.**~~ **Closed in host surface 1.3.0.** A
  reader that parses a skeleton and a sequence table now has somewhere to hand
  them: bone weights on the mesh builder, clips built from keyframes, and a
  playback clock. What is still missing there is root motion, humanoid
  retargeting and blend trees.
- **The host decodes PNG and JPEG** and nothing else, so a source whose textures
  are block-compressed needs the host to learn that format — it cannot be done
  in the interpreter for the arithmetic above.
- **The mesh always gets a collider**, cannot be updated in place, and carries
  no vertex colours, tangents or second UV set.
- **The ledger cannot be corrected**, because catalog entries are append-only
  for a given id and owner.
