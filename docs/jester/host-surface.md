# The host surface

Jester means to ship **one** player build that never needs updating: the Unity
API wrapped as host calls, mod load and unload, and the boot shell. Everything
else is a mod, forever.

That promise holds exactly as far as the host's API surface reaches. Every
capability a future mod needs and cannot reach is another host build the author
has to ship and every player has to install. So this page answers three
questions: what can a mod do today, what can it not, and what is the finite list
of work between here and a surface worth freezing.

Everything counted here was counted by a command. The effort figures are the
only numbers that are not measured, and they are marked as estimates.

[[toc]]

## The surface as it exists

**220 host calls.** The C# dispatch and the mod-side declarations agree exactly:
there is no bridge case without a wrapper, and no wrapper without a case.
Dispatch is one switch for the core (129 calls), falling through to four
prefix-owned tables — networking (31), importing (28), HTTP (17) and content
updates (15). No mod declares an `importc` of its own, so there is no path by
which a mod reaches a name the host does not answer.

### By area, measured

| area | calls | what it is |
|---|---:|---|
| networking | 31 | transport, peers, worlds, part placement, message events |
| importing | 28 | finding a game the player owns, scanning and extracting from it |
| voice | 17 | microphone, devices, push-to-talk, VAD |
| HTTP | 17 | prepared requests, allowlist policy, async polling |
| content updates | 15 | staging, hashing and committing a content set |
| screen UI | 11 | one panel stack, labels, buttons, hit testing |
| model bytes | 11 | reading files as bytes or text for a format-reader mod |
| collections | 11 | the catalog substrate mods build data on |
| transforms | 11 | set and get position, rotation, scale, parent, active, forward |
| meshes | 8 | vertex, uv, normal, triangle and quad building |
| Unity reflection | 8 | get, set, call, and their handle variants |
| parts | 6 | spawn, and the provider protocol a format reader answers on |
| pointer | 5 | lock, show, position |
| character | 5 | controller create, move, grounded, touched, velocity |
| input | 5 | keys, three mouse buttons, look delta, typed text |
| modpacks | 4 | list, name, select, playing |
| drawing | 4 | fill, text, image, measure |
| aiming | 4 | one ray, its hit, point and distance |
| rigidbodies | 3 | add with mass, freeze, set velocity |
| state | 2 | remember and save over scalars |
| the rest | 14 | log, time, delta, screen size, camera create, component add and get, primitives, surfaces, textures, mod folder, destroy |

Above the 220 the SDK adds **511 exported procs across 20 modules** — vectors,
colours, an event iterator, a catalog DSL, a settings model, a character
controller. Those cost nothing at the boundary; they are aowlmony written
over the same 220 calls, and they are the part that can change without a host build.

## The escape hatch, and its exact shape

Five of the calls are general reflection, and they change the honest answer to
"what can a mod reach" far more than their count suggests: two add or find any
`Component` by assembly-qualified type name, two read and write any public
instance property or field, and one invokes any public instance method.

So a mod can add a `Light` and set its intensity, range, colour and type with no
host change at all. That is real reach. Its walls are just as real:

1. **Scalars only.** The boundary carries `long`, `double`, `bool`, `string`,
   enums by name or ordinal, `Color` as `#rrggbbaa`, `System.Type` as a name,
   and object handles. **Nothing else.** A property returning `Vector3`,
   `Quaternion`, `Bounds`, `Matrix4x4`, `Ray`, an array, or any Unity struct
   module throws rather than returning.
2. **Instance methods only.** Every Unity static is unreachable:
   `Physics.Raycast`, `Physics.OverlapSphere`, `Object.Instantiate`,
   `Resources.Load`, `AudioClip.Create`, `SceneManager.*`, `Time.*`,
   `Application.*`, `Mathf.*`, `NavMesh.CalculatePath`.
3. **No constructors.** The only things a mod can bring into existence are a
   GameObject, a primitive, a camera, a component on an existing object, and a
   mesh. It cannot construct a `Mesh`, `Material`, `Texture2D`, `AnimationClip`,
   `AudioClip`, `RenderTexture` or `Sprite`.

Rules 2 and 3 are why "just add an `Animator` by reflection" does not solve
animation: `Animator.Play("fire")` is an instance method with a string argument
and would dispatch fine, but the controller it needs cannot be constructed or
loaded by any call in the surface.

## The audit, by domain

*Reachable* = a plausible mod can do it today. *Partly* = it can do a useful
subset and the missing part is named. *Not* = there is no path.

**Transforms and hierarchy — reachable.** Position, Euler rotation, scale,
world-preserving parent, active, destroy, world position and forward. Missing
and cheap: quaternion rotation, so a mod cannot compose rotations without gimbal
risk; local versus world; right and up; sibling index; find-by-name. None of it
blocks a mod; several are irritating.

**Rendering — partly reachable.** A mesh can be built from vertices, normals,
UVs, triangles or quads — one submesh, one material, always lit, always with a
collider attached. Materials get a tint and four texture slots fed from encoded
image bytes. Cameras take any scalar property by reflection, which is adequate.
Lighting works through `component_add` plus scalar properties — undocumented and
undiscoverable, which is its own kind of gap. **Not reachable:** custom shaders,
arbitrary shader properties, material property blocks, render queue, vertex
colours, tangents, a second UV set, submeshes, bone weights, declining the
collider, updating a mesh in place, post-processing, render textures, command
buffers.

**Physics — partly reachable.** One ray from a transform, along a chosen
direction, against a layer mask, nearest hit, triggers ignored, own root
skipped. Rigidbody add with mass, kinematic on and off, set linear velocity. A
character controller with create, move, grounded, touched sides and velocity.
**Not reachable:** all-hits enumeration, shape casts, overlap queries, the hit
**normal**, forces, torque, impulses, drag, constraints, joints, collision and
trigger callbacks, the layer collision matrix, gravity, manual stepping.

**Animation — not reachable.** There is no `Animator`, `Animation`,
`AnimationClip` or `SkinnedMeshRenderer` anywhere in the host. Nothing in the
surface can construct a controller or a clip, supply bone weights to a mesh, or
drive a transform hierarchy from keyframes. **This is the largest hole**, and it
is self-evidently one: a shipped reader already parses a game's bone and
sequence tables and then says, in its own header, that a skinned model comes out
in its reference pose because the bone weights have nowhere to go.

**Audio — not reachable.** An `AudioSource` can be added by reflection and
played, but there is no way to obtain a clip: the constructors are static and no
host call decodes audio bytes. Voice chat is a separate system — it is comms,
not game audio.

**Input — partly reachable.** The whole keyboard by name, held and pressed
edges; three mouse buttons; position; look delta; typed text; screen size;
pointer lock and visibility. **Not reachable:** the scroll wheel, mouse buttons
4 and 5, gamepads entirely, touch, and any rebindable action map.

**UI and drawing — partly reachable.** Three primitives, recorded and replayed
when a camera renders so they also work headlessly: a filled rect, text in a box
with three alignments, and an image with a source sub-rect — plus measurement
and a small panel stack. Clipping, scrolling, nesting and drag-and-drop are
*not* host features; [the UI library](/docs/jester/ui) implements them in mod
code by cropping rectangles itself, which is exactly what the image call's
source rect exists for. Two things mod code cannot recover: **glyph-level
clipping**, so a scrolling list cannot show a half-row, and **the scroll wheel**.

**Navigation — not reachable.** No NavMesh baking, and an agent is unusable
because its API is `Vector3`-shaped and the path query is static. Bot AI must
implement its own pathfinding over geometry it generated — which for a mod that
built the world itself is quite reasonable, and for a mod driving bots around an
imported map is not.

**Particles — not reachable.** A particle system can be added but is configured
entirely through struct-valued module properties, which the scalar boundary
rejects. A mod can fake particles today with many small meshes.

**Time — reachable.** Delta and clock. Missing: fixed delta, time scale, frame
count, realtime since startup. Small and cheap.

**Scenes — not reachable, and probably correct.** A world here is built by mods
at runtime; there is no evidence any mod wants scene loading.

**Networking — reachable**, and the most complete domain in the surface. See
[networking](/docs/jester/networking).

**Persistence — partly reachable.** Four scalar types per mod, debounced to
disk, profile-scoped, surviving a hot swap, with a reserved key that tells a mod
whether its values came back. **Only scalars** — a grid inventory must serialise
itself into a string, which works but has no size guidance and no binary path.

**Assets and resource loading — reachable, and well designed.** The host owns no
formats: a mod claims a file extension, is called back with the bytes, and
answers with geometry plus up to four texture maps. The gaps here are the mesh
gaps above — one material, no skinning — and not loading gaps. See
[importers](/docs/jester/importers).

## Ranked gaps

Ranked by whether a mod being written *right now* is blocked. Effort figures are
**estimates**, in engineer-days, and nothing below has been prototyped.

| # | gap | what it blocks | est. days |
|---|---|---|---:|
| 1 | **Skinned meshes and animation playback** | imported weapons and characters. The reader already has the bones and the sequences; there is no skinned renderer, no bone weights on the mesh calls, no clip construction, no playback clock. Impossible, not merely awkward | 8–12 |
| 2 | **Mouse wheel** | the UI library's scroll regions. One host call | 0.25 |
| 3 | **Glyph-level clipping (a scissor rect)** | a scrolling list that shows a partial row; today whole rows vanish | 1–2 |
| 4 | **Submeshes and several materials** | multi-material imported models, and chunked worlds that want separate opaque, cutout and translucent passes | 2–3 |
| 5 | **Declining the collider, and updating a mesh in place** | world import at scale: every chunk pays for a collider whether it wants one or not, and a changed chunk must be rebuilt as a whole new object | 1–2 |
| 6 | **Hit normal, multi-hit, shape casts, overlap queries** | bot AI (line of sight, cover, proximity) and any weapon wanting a surface normal | 2–3 |
| 7 | **Trigger and collision callbacks** | pickup volumes, trigger zones, anything event-driven rather than polled | 2–3 |
| 8 | **Audio** | the first shot fired makes it urgent: decode bytes to a clip, play at a point, one-shot and looping, volume and rolloff | 3–5 |
| 9 | **Quaternion rotation** | anything composing rotations. Euler-only is a correctness hazard rather than a wall | 0.5 |
| 10 | **Time scale, fixed delta, frame count** | slow motion, deterministic ticks | 0.25 |
| 11 | **Gamepad input** | nothing today; a shooter eventually | 1–2 |
| 12 | **Particles** | muzzle flash, blood, sparks. Fakeable with meshes today | 3–4 |
| 13 | **Navigation** | bots on an imported map | 4–6, or never if pathfinding stays a mod |
| 14 | **Custom shaders and material properties** | nothing today. Worth exposing *before* the freeze, because after it nobody can add it | 2–3 |
| 15 | **Binary or bulk state** | a scale problem, not a wall | 1 |

**Distance to a freezable host.** Items 1–10 are what the named mods actually
need, and total **20–33 estimated engineer-days**. Items 11–15 are the "do it
before the door closes" set, another 11–16. None of it is research; all of it is
plumbing along a boundary that already exists and is already exactly consistent
between its two sides. The honest reading is four to eight weeks, dominated by
item 1. The real risk is not any single item — it is freezing before something
like item 14 has been thought about.

## The host contract

For "it will always work with any mod" to be a fact rather than a hope, three
things must be true. A mod must say what it needs. The host must check that at
discovery, not fail somewhere inside a callback. And the SDK-stamp rule must not
turn a single mod update into a broken tree.

### Where the version lives

In `mod.json`, beside the dependency ranges it already carries, because that
file is the mod's declaration of what it needs and it is read at discovery,
before anything loads:

```json
{
  "id": "example.hello",
  "version": "0.1.0",
  "host": "^1.0.0",
  "dependencies": [ { "id": "infiniteless.parts", "version": "^0.1.0" } ]
}
```

Not in the built artifact. The artifact is the compiler's output and its
identity is a content hash; the requirement is authorial intent, and belongs
with the author's other declarations.

The host declares one semantic version for its call surface: **patch** for a bug
fixed behind an unchanged signature, **minor** for calls added — old mods keep
working, so `^1.0.0` accepts `1.7.2` — and **major** for a call removed or its
meaning changed. That last is the number the freeze is about; after the freeze
it should never move again. An absent or empty `host` means no constraint, so
every mod written before the rule keeps loading.

A mod that asks for more than this host has fails **at discovery**, as a named
failure saying which mod, what it asked for, and what this host is — the same
channel that already reports a bad manifest or a missing artifact, and which the
boot shell already renders. It does not load, so it cannot reach a call that is
not there and abandon `start()` mid-procedure with nothing in the log. That is
the entire point: a crash somewhere inside a callback becomes a sentence the
player can act on.

**This is implemented.** The field, the check, and the failure message.

### The SDK stamp, and why a frozen host makes it worse

Every mod compiles the shared SDK into its own artifact under one module id, and
the interpreter keeps a single program table, so whichever mod loads first
imposes *its* copy of the SDK on all the others. The current rule is a strict
majority vote over a content hash of the SDK tree carried in each mod's build
receipt. The minority is left unbuilt; with no majority, nothing is trusted.

A majority vote is the right answer for a development tree that is rebuilt
whole. It is the **wrong** answer for a shipped world, for two reasons: the
stamp is a content hash, so it changes when a doc comment changes — it can say
"different", it can never say "incompatible"; and under auto-updating mods the
majority is whatever most mods happened to update to last, so shipping one
updated mod into a set of nine leaves the updated one silently not loading,
while updating five of nine flips the majority and stops the other four. The
failure moves around with the update schedule, which is exactly the thing a
frozen host is promising will never happen.

**The design** is to replace the vote with a fixed reference: the host stamps
into itself, at build time, the SDK hash it was built alongside, and publishes a
small set of stamps it accepts. Then a mod is refused **by name, against the
host**, not against its siblings, and the refusal is stable — it depends only on
the mod and the host, so a mod that loads today loads tomorrow no matter which
of its neighbours updated. That composes cleanly with the `host` field: `host`
is the author's statement of what they need, the SDK stamp is the builder's
record of what they compiled against, and the host checks both against constants
it carries. Neither can be affected by another mod.

**This half is designed and not built.** It needs a build-time generator, and
the majority vote is not hurting anyone in a tree that is rebuilt whole. The
better long-term answer is for the SDK to gain its own semantic version, so that
a hash stops being the compatibility question at all.
