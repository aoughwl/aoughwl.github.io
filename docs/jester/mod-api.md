# The mod API

What a mod can call, and the shape the calls come in. The engine-side view of
the same boundary — what is reachable at all and what is not — is
[the host surface](/docs/jester/host-surface).

[[toc]]

## Three layers

Each layer is allowed to know about the one below it and nothing else.

**Layer 0, the floor.** The raw `importc` declarations and their handle casts.
One scalar per slot, an axis index for anything wider, a cursor plus readers for
anything that is a sequence. That is the seam's shape, and it is the right shape
for the seam: the interpreter marshals nil, integer, number, boolean and string
across the C ABI and refuses everything else. Nobody writes to the floor by hand.

**Layer 1, the public API.** Plain procs and small value types. No templates, no
macros, no compile-time anything. It reads like the domain —
`eye.position() + eye.forward() * 3.0`, `for ev in networkEvents()`,
`case ev.kind of Placed:` — and it is what the docs and every mod are written
against. Every Layer-1 proc is a few Layer-0 calls in a trench coat: the vector
never crosses the boundary, the event object is assembled from the same five
string reads the loop used to make.

**Layer 2, sugar.** Templates only. Block forms for the declarative cases: a
menu, a panel, a mesh, a catalog. Never the only way to do something; always
exactly the Layer-1 calls a mod would otherwise write. Macros are out — they
cost a mod thirty-odd extra modules and take its semantic pass from about a
second to over a minute.

The test for whether something belongs in Layer 1 is whether a mod author would
ever want to write the Layer-0 form. `positionX(e)` fails that test; a mod only
ever wants the three together. `held("LeftShift")` fails it; the key set is
closed and the compiler could have said `LeftShfit` is not a key.
`networkNext()` fails it; no mod ever wants the cursor, it wants the events.

## The modules

**771 exported procs across 28 modules**, all of it aowlmony written over the
same 433 host calls. It costs nothing at the boundary, and it is the part that can
change without a host build.

| Module | What it is |
| --- | --- |
| `infiniteless` | the floor, plus a wrapper per host call. Everything below is built on it |
| `vec` | `Vec3`, `Vec2`, `Rect`, `Contact`, operators, transform reads and writes |
| `color` | `Color`, `Surface`, hex parsing, colour on an entity |
| `entities` | the `Shape` enum, `shape()`, `empty()`, `useShape()` |
| `input` | the `Key` enum (110 names), `MouseButton`, `held`/`pressed`, pointer, screen |
| `draw` | `Align`, `fill`/`outline`/`writeAt`/`writeIn` over `Rect` and `Color`; the panel stack as `cursor()`/`row()`/`columns()` |
| `draw_dsl` | Layer 2: `menu` / `panel` / `overlay` / `mesh` block forms |
| `catalogs`, `catalogs_dsl` | [catalogs](/docs/jester/catalogs): kinds, entries, lookup, and their block forms |
| `parts` | `PartRequest`, `vertex`/`normal`/`uv`/`triangle`/`quad` |
| `textures` | naming an image on a surface, and inside a model request |
| `network`, `events` | `Peer`, session, the typed event iterator, `Placement` |
| `shell` | `Modpack`, `modpacks()`, `play()`, `playing()` |
| `voice` | microphone, devices, push-to-talk, VAD |
| `http` | the async [HTTP](#http) submit/poll/read/release model |
| `importing` | the generic half of an [importer](/docs/jester/importers): locate, scan, extract, plan, ledger |
| `content` | the content-update channel a self-updating mod drives |
| `settings` | a settings schema declared as catalog rows, and one screen that draws all of them |
| `character` | the character controller, which is an SDK module and not a host feature |
| `animation` | skeletons, bone weights, clips built from keyframes, playback, layers, one joint |
| `sound` | clips decoded or built sample by sample, one-shots, looping speakers, positional playback, volume buses |
| `text` | the clipboard, the input method and its caret, and the three timings a person's own settings decide |
| `window` | the mod's own window: frame, transparency, on top, click-through, place, size, drag |
| `render` | how often any of it is drawn: frame-rate cap, on-demand interval, idle-when-quiet, wake |
| `display` | dots per inch, the scale factor a layout multiplies by, and whether it just changed |
| `desktop` | file dialogs, the tray, one copy at a time, argv, dropped files, menus, global keys |
| `services` | `provideService` / `callService` / `serves`: one mod asking another a named question |

## Lifecycle

Four top-level procs, each taking nothing and returning nothing. A missing one
is skipped.

| Proc | When it runs |
| --- | --- |
| `start()` | once, immediately after the mod's artifact is loaded. Throwing here aborts the activation unless the mod is optional |
| `update()` | every frame, for every active mod, in dependency order |
| `drawGui()` | every GUI pass. Drawing works, but never runs headless — draw from `update()` if you want to prove it |
| `stop()` | once, before the slot is dropped |

### Activation is transactional

Loading a modpack stages every mod first. If a mod something depends on fails to
load, or its `start()` raises, the staged mods are stopped in reverse and the
previously running set stays live and untouched. Only after the load completes
does the old set get stopped, also in reverse.

A mod nothing requires — one reached only through an optional dependency — is
allowed to fail on its own. Its lifetime is disposed, the failure is reported,
and the rest of the pack activates without it.

### Owners, and what a stale handle does

Every mod instance is identified by an owner: mod id plus a generation counter
that increments on each successful activation. Unity objects, catalog entries,
HTTP requests, import jobs and handles are all tagged with it, so a handle from
a previous generation — or from another mod — throws rather than touching a live
object.

### A failing mod does not take the session with it

`update()` and `drawGui()` are called through a guard. A throw is caught, the
mod is left loaded, the rest of the pack keeps running, and the failure is
announced once rather than every frame. After five consecutive failures in the
same phase the mod is quarantined: that phase stops being called at all. The two
phases are tracked separately, so a mod whose `drawGui` is broken still gets
`update()`. A hot reload clears the quarantine.

### Hot swap, and what survives it

Two reload paths exist and they are not the same thing.

- **Artifact hot swap.** The runtime polls each active mod's built artifact and
  swaps when its timestamp advances. The live code is replaced in place and the
  interpreter's globals are kept — a mod-level `var` retains its value. The
  owner does not change, so Unity handles, catalog entries and `remember` state
  stay valid, and `start()` is not called again. A swap requested while the mod
  is inside a callback is refused and retried next frame.
- **Modpack switch.** A full reactivation. Every mod is torn down and reloaded
  at a new generation. Globals are lost, Unity objects the mod owned are
  destroyed, and its catalog entries are removed.

`remember` / `save` state is keyed by mod id, not by generation, so it survives
both — and, because it is written to disk, the session as well.

### Cleanup is automatic

Every Unity object a mod creates is registered against its lifetime and
destroyed when the mod stops, in reverse creation order. Objects the mod merely
*received* — from reflection, or from another call — are borrowed: the handle is
dropped and the object is not destroyed. Catalog entries, catalog kinds, HTTP
requests, import jobs, decoded textures and cached geometry owned by the
generation go the same way. A mod does not need to clean up after itself in
`stop()`.

## Entities and the world

`Entity` is a distinct 64-bit handle, not a pointer. Handle id `0` means
nothing: `nothing()`, `isNothing()` and `isSame()` are pure mod-side code over
the integer, with no host call.

| Call | Effect |
| --- | --- |
| `empty(name)` / `shape(kind: Shape, called = "")` | a bare GameObject, or one of six primitives |
| `camera(name)` | a new object with a `Camera`; returns the **component** handle |
| `addComponent(e, typeName)` / `component(e, typeName)` | add or find any `Component` by assembly-qualified name |
| `position(e): Vec3` / `position(e, at: Vec3)` | world position. An enabled `CharacterController` is cycled off and on around the write, so teleporting one sticks |
| `rotation(e, turn: Vec3)` / `scale(e, by: Vec3)` | Euler degrees; local scale. **Neither has a reader** |
| `forward(e): Vec3` | world forward |
| `attach(child, parent; keepPlace = true)` | reparent |
| `active(e, value)` / `destroy(e)` | as they read |

Transform calls accept either a GameObject or a Component handle; the
component's transform is used.

### Colour and surface

```nim
crate.color(rgb(0.8, 0.3, 0.1))
crate.surface(metal = 0.2, gloss = 0.6)
let painted = crate.color()          # reads what is actually drawn
```

Colour paints every renderer under the entity, children included, and an alpha
below one switches the material to blended rendering, so see-through actually is
see-through. Properties are looked up by name so both render pipelines are
covered.

A renderer's material is a shared asset, so the first call replaces it with a
copy owned by the calling mod's lifetime and later calls reuse that copy.
Neither call silently does nothing: if the entity draws nothing, or its shaders
have no colour, metal or gloss property, it throws. Reading takes no copy —
whatever is being drawn answers, whether this mod painted it or it arrived that
way — and reading throws on the same two cases writing throws on, so a zero
always means the surface really is at zero.

Images are named, never pushed: `crate.texture("Images/crate_diff.png")`, plus
`bumps`, `shine` and `glow` for the other three maps. The path is relative to
the calling mod's own folder and may not leave it. **No pixels cross the
boundary in either direction, ever**, and the reason is arithmetic rather than
taste: a crossing costs about 4 µs and an interpreter operation about 0.6 µs, so
a 1024×512 PNG is milliseconds for the host and seconds to tens of seconds for a
mod. A mod-side image decoder is not a slow path; it is not a path.

### Physics and bodies

The host used to ship a first-person controller. It no longer does. What is left
is the part a mod cannot write for itself: a capsule the world pushes back on,
and the reads that say what happened to it.

| Call | Effect |
| --- | --- |
| `body(name, height, radius)` | a `CharacterController` and nothing else — no camera, no eye. Centred at half its height, so the point you place is its feet |
| `move(e, by: Vec3)` | one collision sweep by that offset. A displacement, not a velocity: multiply by `deltaTime()` yourself |
| `grounded(e)` / `contact(e): Contact` | what the last `move` ran into: ground, wall, ceiling, any |
| `velocity(e): Vec3` | what the last sweep actually achieved — the movement the world allowed, not the one you asked for |
| `physics(e; mass = 1.0)` | convex-ifies child mesh colliders, finds or adds a `Rigidbody`, clears kinematic |
| `freeze(e; value = true)` / `push(e, velocity: Vec3)` | kinematic on/off; assign linear velocity. `push` is **not** an impulse |
| `aim(e; maxDistance = 60.0; layers = -1): Hit` | one ray. `aim(e, along: Vec3, ...)` names the direction instead of using the entity's forward |

The sweep is the only report a mod gets of running into anything, so its result
is kept until that body moves again. There are still no collision or trigger
callbacks anywhere: this says what a body was stopped *by*, not what touched it.

`aim` is `RaycastAll` with triggers ignored, the aiming entity's own root
discarded, and the nearest remaining hit kept. Its `Hit` resolves to a handle
only for objects the calling mod owns — the point and distance are still valid
otherwise. That is a deliberate ownership boundary, and it does mean a mod
cannot pick up another mod's props.

### Input and the pointer

`held(k: Key)` and `pressed(k: Key)` over a 110-name enum, the same three for
`MouseButton`, plus `clicked`. `look(): Vec2` is raw mouse delta since the last
frame — an input read, not a camera call; nothing turns until a mod turns it.

The pointer belongs to the player, and when they get it back is a mod's
decision. `lockPointer()` holds it in the middle of the window and hides it;
`freePointer()` gives it back. A mod that holds the pointer and is then unloaded
does not leave it held: the hold is recorded against the mod that took it.
`typed()` is what the player typed since it was last asked, printable characters
only — backspace and the rest are keys.

## Drawing

Four calls, and everything on the screen is made out of them in mod code.

```nim
fill(rect(20.0, 20.0, 200.0, 32.0), rgb(0.1, 0.1, 0.1, 0.8))
writeIn("HEALTH", within = rect(24.0, 24.0, 192.0, 24.0), size = 16.0,
        align = AlignCentre, c = White)
let w = textSize("HEALTH", 16.0)
```

Coordinates are points with `0,0` at the top left. Drawing calls are **recorded
rather than drawn**, and replayed when a camera renders. Two things follow: a
mod may draw from `update()` as readily as from `drawGui()` — a frame's drawing
is whatever was asked for during it, so a mod that stops asking stops being
drawn — and drawing shows up in a headless capture, which Unity's `OnGUI` does
not. Only the repaint pass is recorded, so a menu drawn from `drawGui()` is
drawn once rather than three times over and a button is clicked once rather than
once per pass.

A small panel stack lives in the host — `openMenu`/`openPanel`, `label`,
`button`, `row`, `cursor`, `hovering`, `closeMenu` — and it is one column that
cannot nest and cannot be cropped. Anything more is
[the UI library](/docs/jester/ui), which is mod code.

Everything above the three primitives is mod-side code: headings, hints, borders,
toggles, sliders and text fields are all `fill` and `writeIn` and a cursor. A
mod that wants a different-looking toggle, or a colour picker, or a scrollbar,
writes one the same way.

## Persistent state

```nim
let visits = remember("visits", 0'i64) + 1
save("visits", visits)
```

Four scalar types — `string`, `int64`, `float64`, `bool` — keyed by mod id, so
values survive both hot swap and modpack reactivation. A key is type-locked
after first use: reading or writing it as a different type throws and tells you
to rename it.

It reaches disk as one JSON file per mod under the save profile. Writes are
debounced two seconds and coalesced, so a mod calling `save` from `update()`
costs one write rather than one per frame. A write is staged to a sibling file,
flushed, and renamed over the live one, so a reader sees the whole previous save
or the whole next one and never half of one. Pending changes are forced out on
modpack switch, teardown, hot reload, focus loss and quit.

Nothing about saving is allowed to reach the mod as an exception. A file that
will not read is complained about and the mod starts fresh; a file that will not
parse is moved aside first; a write that fails stays dirty and is retried. One
reserved key answers whether this mod's values came back from a save:

```nim
if not remember("infiniteless.restored", false):
  buildStarterWorld()
```

## The character controller is a mod

Walking around is game design, so it does not live in the host. It lives in an
SDK module and a shipped mod, and between them they are the worked example of
what catalogs are for.

```nim
import infiniteless
import character

var player = newCharacter()

proc start() =
  player.configure("character.controls", "character.movement")
  player.place("Player", vec3(0.0, 1.0, 0.0))

proc update() =
  player.step()
```

`Character` is one object and the procs that drive it. Every constant is a
field: which keys move it, how fast it goes, how tall it is, how hard it falls,
whether it has an eye at all. A character you never configure stands still.

`step()` is one frame of everything, in order: turn with the mouse; note whether
the body is grounded; stick to the ground rather than letting gravity accumulate
while standing; take a jump if one was asked for recently enough and the ground
was left recently enough; apply gravity; read the movement keys, normalising a
diagonal; pick walk or run speed; blend horizontal speed toward the wanted one
at ground or air acceleration; sweep by `deltaTime()`; and drop any upward speed
that ended against a ceiling, so a jump under a low roof stops there instead of
scraping along it. `step(turning = false)` leaves the mouse look out, which is
what a mod wants while a menu is open.

Jump is asked for as a *height*, not a speed. The eye is a plain camera rather
than a child of the body, which is what keeps the body's forward vector flat and
unit-length for the movement maths.

The shipped character mod is a schema and an opinion and nothing else: it
declares two kinds that know nothing about characters — a named action with a
key, and a named number — and fills one catalog of each. Forty-eight lines, no
logic. A mod that likes the scheme except for one key publishes that one key; a
mod that wants none of it declares its own catalogs of the same two kinds and
passes those names instead. Neither has to fork anything.

## HTTP

A mod cannot open a socket, start a process or block a frame, so the host does
the fetching and a mod asks how it went: submit, poll, read, release. Everything
a mod reads is a copy made under a lock, and nothing that lives on the I/O
thread is ever handed to the interpreter.

```nim
import http

var page = httpGet("http://127.0.0.1:8080/hello")

proc update() =
  if page > 0 and httpDone(page):
    if httpError(page) == "":
      log($httpStatus(page) & ": " & httpBody(page))
    else:
      log("failed: " & httpError(page))
    httpRelease(page)
    page = 0
```

The response body is readable while still in flight, so a streaming answer is
read as it comes: keep the length you saw and ask for the rest from that offset.
Redirects are **not** followed — a redirect is a second request to a host nobody
checked — so the mod sees the 3xx and its `Location` header and decides.

Limits are refusals, never truncations: 8 requests in flight per mod, 64 held,
8 MB request and response bodies, a 0.25 s–600 s timeout window, and finished
results reaped after two minutes. The response limit is checked against the
claimed `Content-Length` first, so a server answering with a four-billion-byte
claim costs the headers and nothing else.

**Policy: who a mod may talk to.** A game that lets any mod talk to any server is
a game that exfiltrates. Loopback is always allowed. Everything else is refused
by name, with a sentence the mod can show: which host, that loopback is the
default, and which file to edit. **The player widens it, not the mod** — one
host per line in a file beside the saves, re-read live so the list can change
without leaving Play mode. A manifest cannot grant itself a host.

## The Unity reflection escape hatch

Six procs let a mod read, write and call public members of any Unity object it
holds a handle to.

```nim
let paintwork = ground.component("UnityEngine.MeshRenderer, UnityEngine.CoreModule")
paintwork.set("shadowCastingMode", "Off")
let surface = paintwork.unityEntity("sharedMaterial")
surface.set("color", "#ff8800")
```

This is real reach: a mod can add a `Light` and set its intensity, range, colour
and type with no host change at all. Its walls are just as real, and they are
worth knowing before you plan around it.

- **Handles are the only way in.** No find-by-name, no scene traversal, no
  static access. A mod can reach only objects it created, objects a call handed
  back, or objects returned from reflection on something it already holds.
- **Handles are owner- and generation-checked.** A handle from another mod or an
  older generation is rejected as stale, as is one whose object was destroyed.
- **Public instance members only.** No private members, no statics, no
  constructors, no generic methods. Every Unity static is therefore unreachable:
  `Physics.Raycast`, `Object.Instantiate`, `Resources.Load`, `AudioClip.Create`,
  `SceneManager.*`, `Mathf.*`.
- **Overloads resolve by arity plus successful conversion**, first match wins,
  and at most one argument can be passed.
- **Value marshalling is a closed set.** In and out: string, int64, float64,
  bool, enums by name or ordinal, entity handles, `Color` as `#rrggbbaa`, and
  `System.Type` as an assembly-qualified name. Anything else — a `Vector3`, a
  `Quaternion`, an array, a Unity struct module — throws. This is the sharpest
  edge of the hatch, and the reason position and forward have dedicated calls.
- **Failures are contained.** Anything thrown is logged and turned into a
  failure status, which aborts the current callback rather than the process.

What is *not* limited: `addComponent` resolves any assembly-qualified type with
no allowlist, so a mod can attach any `Component` in any loaded assembly and
then reflect over it. The protection model is "you can only touch objects you
were handed", not "you can only touch a vetted API".

## Known limits

Stated plainly, because planning around them is cheaper than discovering them.

- **One mod cannot import another.** Shared mod-side code has exactly one home,
  the SDK, and adding to it is a change to the engine's package rather than a
  mod anybody can publish. This is why the character controller is an SDK module
  and not a module inside the character mod, and it is why a mod-side library
  ecosystem cannot exist yet.
- **An entity handle cannot cross a mod boundary.** Two mods cannot cooperate on
  one object at all: no picking up another mod's props, no building tool that
  works on parts a different mod spawned. Together with the import limit, mods
  compose through published *data* or not at all.
- **No rotation or scale readers**, and reflection cannot return a `Vector3` or
  a `Quaternion` either. Rotation composition is Euler-only, which is a
  correctness hazard rather than a wall.
- **No root motion, humanoid retargeting or blend trees.** Skinning, clips and
  playback landed in surface 1.3.0 and a clip a mod builds is a legacy clip, so
  Mecanim's own graph is still out of reach.
- **No compressed audio, streaming, effects or reverb.** Decoding, clips,
  speakers and buses landed in 1.4.0; what is above them did not. Voice chat is
  comms, not game audio.
- **A mod cannot see another mod fail.** The failure record exists and the
  runtime prints it, but nothing reaches a mod, so a shell cannot show which
  mods are broken or offer to reload them.
- **Binary network payloads are unreachable from mods.** They can be observed
  and not read.
- **Everything runs on the engine thread.** Load, swap, unload and every
  callback are refused off it, so a mod cannot do background work; the async
  shapes — HTTP, imports — are the host doing the waiting and the mod polling.
- **The build path is Windows-first.**
