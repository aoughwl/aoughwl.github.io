# Getting started

From nothing to a mod that runs, and what goes wrong on the way.
[The mod API](/docs/jester/mod-api) is the reference for what a mod can call;
this is the other half.

[[toc]]

## What a mod actually is

Three things, and no more.

**A folder** under the game's `Mods` directory. The folder name is not
load-bearing; the `id` inside `mod.json` is.

**`mod.json`.** The only required field is `id`. The id is also the folder your
saved state lands in and the provider name stamped on every catalog row you
contribute, so pick it once.

```json
{
  "id": "my.mod",
  "name": "My Mod",
  "version": "0.1.0",
  "kind": "Experience",
  "entry": "main.nim",
  "host": "^1.0.0",
  "dependencies": [
    { "id": "infiniteless.parts", "version": "^0.1.0" }
  ]
}
```

**`main.nim`.** Up to four top-level procs, each taking nothing and returning
nothing. Any you leave out are simply skipped — the runtime asks the interpreter
whether the name exists before it calls it.

```nim
import infiniteless

proc start() = discard      # once, when the mod loads
proc update() = discard     # every frame
proc drawGui() = discard    # every GUI pass
proc stop() = discard       # once, when it unloads
```

A **modpack** is a fourth thing, but it belongs to the *game*, not the mod: it
names a shell and a list of mods, and it is what the boot menu offers. Without
one your mod is discovered and never loaded.

```json
{
  "id": "my.mod",
  "name": "My Mod",
  "shell": "infiniteless.shell",
  "mods": ["my.mod"]
}
```

::: tip The `infiniteless` namespace
The engine was called Infiniteless before it was called Jester, and the rename
has not reached the code: the SDK umbrella module is still `infiniteless` and
the mods that ship still carry `infiniteless.*` ids. Those are the spellings you
type today.
:::

## The shortest path

One command writes the manifest, the source, the modpack, and then builds it:

```powershell
tools\new_mod.exe my.mod --name "My Mod" --template hud
```

There are four templates — `basic | hud | spawn | character` — and each is one
lesson: a cube that turns, a bar of text, a key that spawns from a catalog, a
player that walks. All four are also checked in as mods to read and copy. In the
Unity editor the same thing is a menu item, which runs the same tool rather than
carrying a second copy of the templates.

## Build it, or it does not exist

```powershell
tools\build_mod.exe Mods\my.mod
```

Roughly thirteen seconds cold; about a tenth of a second when nothing changed,
because the cache is keyed on content.

**A mod with no build receipt cannot be loaded at all.** Discovery reads the
receipt and returns nothing without it, so an unbuilt mod is not a mod that
misbehaves — it is a mod that never appears. That is why the scaffolder builds
what it writes instead of leaving you a folder.

In the editor you do this once. A file watcher rebuilds every `.nim` under the
mods folder and under the SDK while Play mode runs, and the runtime polls each
active mod's artifact and hot-swaps it in place. Mod-level `var`s keep their
values across a swap and `start()` is not called again.

### Every mod must be built against the same SDK

Editing anything in the SDK means rebuilding every mod:

```powershell
tools\build_mod.exe --all
```

About two seconds when nothing changed. Discovery refuses the whole built set
when the SDK stamps in the receipts disagree, and says which mods were built
against which.

The reason it refuses loudly is worth knowing, because it explains a whole class
of silent failure. Every mod compiles its own copy of the SDK, and every copy
lands under the same module id; the interpreter keeps one program table for the
process, so **whichever mod loads first imposes its SDK on all the others**. A
proc the others expect then simply does not exist, and the interpreter abandons
that mod's `start()` mid-procedure with no exception and nothing in the log. The
build stamps a hash of the whole SDK tree into each receipt precisely so that
this is a sentence at discovery instead of a mystery at runtime.

## Run it without Unity

You do not need the editor to find out whether a mod works. A harness loads the
mod's built artifact into the real interpreter through the same C ABI Unity
uses, answers every host call with a made-up value, and prints what happened:

```
--- start -> 0
    example.spin started
    host calls: infiniteless_primitive_create, infiniteless_set_position,
                infiniteless_set_color, infiniteless_camera_create,
                infiniteless_set_position, infiniteless_log
--- update -> 0
    host calls: infiniteless_delta_time, infiniteless_set_rotation
```

The host-call list is the point. It answers the only question worth asking when
something does not appear: **did the call reach the host at all?** A mod whose
drawing is missing from that list drew nothing, whatever its source says.

## A mod, start to finish

```nim
import infiniteless
import entities   # the Shape enum: shape(Plane, ...)
import input      # the Key enum: pressed(E)
import vec        # Vec3, Rect
import color      # Color, rgb()

const Parts = "example.press.parts"

var
  eye: Entity
  dropped = 0

proc start() =
  let ground = shape(Plane, "Ground")
  ground.scale(vec3(4.0, 1.0, 4.0))
  ground.color(rgb(0.24, 0.30, 0.22))

  eye = camera("Eye")
  eye.position(vec3(0.0, 3.0, -6.0))
  eye.rotation(vec3(15.0, 0.0, 0.0))

  createCatalog(Parts, "infiniteless.part", "Things example.press can drop")
  addToCatalog(Parts, "ball", "builtin://sphere")
  addToCatalog(Parts, "box", "builtin://cube")

  log("example.press: E drops a ball, R drops a box")

proc drop(item: string) =
  let thing = spawnPart(Parts, item, vec3(0.0, 6.0, 0.0))
  thing.physics(1.0)
  dropped = dropped + 1
  log("dropped " & item & " (" & $dropped & " so far)")

proc update() =
  if pressed(E): drop("ball")
  if pressed(R): drop("box")
```

Five things in there are not obvious.

**You need a camera.** Nothing in the world is visible without one. The host
does keep a camera of its own, but its culling mask is zero and it clears
nothing: it exists only so there is always a surface to draw menus over.
`camera("Eye")` hands back the *component* handle, not the GameObject, which the
transform calls accept either way.

**A dependency is what makes a catalog kind exist.** The `infiniteless.part`
kind is declared by the parts mod and by nothing else. Leave it out of
`mod.json` and `createCatalog` throws "Unknown collection type" and `start()`
never finishes. The character mod is the same, except that it fails *quietly*:
`configure` finds nothing, every key stays unbound, and the character stands
still instead of complaining.

**`drop` is used before it is defined, and that is fine.** This toolchain does
not need a forward declaration.

**Import the modules you use.** `import infiniteless` gets you the floor —
`shape("cube")`, `position(e, x, y, z)`, eleven positional floats to draw a
rectangle. The domain spellings live in separate SDK modules and each is an
ordinary import. See [the mod API](/docs/jester/mod-api) for the list.

**Prefer `update()` to `drawGui()` for drawing.** Drawing calls are recorded and
replayed when a camera renders, so either works — but Unity's `OnGUI` never runs
without a game view, so `drawGui()` is never called in batch mode and nothing
drawn there survives a headless capture.

## The hazard: names the interpreter takes away from you

This is the section that costs people the most time.

The interpreter implements a set of names as natives and dispatches on the
**basename alone**. Some of those are *gated* — if the first argument is one of
the interpreter's own containers the native fires, and otherwise your body runs.
The ungated ones are claimed no matter what your proc's signature is, and
nothing tells you.

Measured in the real interpreter, on a plain `object` receiver:

| A proc named | What happens |
| --- | --- |
| `open`, `close`, `high` | your body runs |
| `pop`, `del`, `len`, `add`, `cmp`, `find`, `count` | your body runs — gated on the receiver |
| **`low`** | **native wins: returns 0, your body never runs, no error** |
| **`shrink`** | **your body never runs; execution continues as if it had** |
| **`quit`**, **`readLine`** | **the callback ends there, and the mod slot is dead from then on** |
| **`write`** | **no host call at all; the argument goes to a stdout buffer nothing reads** |
| **`items`** (iterator) | **the builtin runs; on a distinct string it yields characters** |
| **`$` on an enum** | **the builtin wins; your overload is ignored, silently** |

`quit` is the worst of them. A mod that defines `proc quit(m: Menu)` logs the
line before the call, never logs the line after it, and from that moment **every
callback on that slot runs nothing and returns success**. Nothing reaches the
console, the session sees no failure to report, and the mod is not quarantined,
because as far as the runtime can tell it is working perfectly.

The practical rule: **do not name a mod proc `quit`, `write`, `low`, `shrink`,
`readLine`, `substr`, or `$` on an enum.** Say `closeMenu`, `writeAt`, `lowest`,
`name(kind)` — which is exactly what the SDK does, and now you know why.

The general form is what makes this a section rather than a footnote: **when a
mod stops halfway through a proc, look for a name collision before you look at
your logic**, and confirm it with the headless runner — the host-call list ends
exactly where the mod did.

## A failed host call does not stop your mod

It hands back a nil that pretends to be a value. Measured with the host
deliberately refusing the call:

| Declared return | What the mod sees |
| --- | --- |
| `bool` | `if b` takes the false branch, but `b == true` and `b == false` are **both false** |
| `int64` | `i + 1` is `1`, `i < 1` is true, but `i == 0` is **false** |
| `float64` | `f * 2.0` is `0.0` and `f == 0.0` is true |
| `string` | `t.len` is `0`, `t & "x"` is `"x"`, but `t == ""` is **false** |

So `if not connected()` reads correctly and `if name == ""` reads backwards.
**Prefer `.len == 0` to `== ""`**, and prefer truthiness to equality. The
failure surfaces only when the callback returns, and the message names the
*last* call that failed, not the first.

## Things that will bite otherwise

- The four procs must be spelled `start`, `update`, `drawGui`, `stop`, take no
  parameters, and return nothing. A misspelling is not an error; the proc is
  just never called.
- A mod-level `var` survives a hot swap but not a modpack switch.
  `remember` / `save` survives both, and reaches disk.
- A state key is type-locked after first use. Reading it back as another type
  throws and tells you to rename it.
- `import std/macros` takes a mod from 3 modules and 2.4 MB to 35 and 7.3 MB,
  and its semantic pass from about a second to over a minute. Templates are
  free; macros are not.
- Definite initialization is enforced: a local `var hits: seq[Hit]` must be
  `= @[]`. A module-level one is exempt.
- An `iterator` that calls anything with a side effect — any host call, any read
  of a global — must be marked `{.sideEffect.}` or it will not compile.
- `.raises` procs must be called inside a `try`. `strutils.parseInt` is one;
  `parseFloat` does not exist in this `strutils` at all, and the default
  exception type is `ErrorCode`, not `ValueError`.
- `$` on a `char` needs `import std/strutils`. `bind` is a reserved word.
- **A mod cannot import another mod.** The builder puts three things on the
  module path: the standard library, the mod's own folder, and the SDK. Sibling
  modules inside your own mod are fine; another mod's are not. Mods compose
  through [catalogs](/docs/jester/catalogs), which carry data and not code.
- **An `Entity` handle cannot cross a mod boundary.** Passing one to another mod
  — through a catalog, a network message, anything — gives that mod a value it
  can only throw on. It is a real safety property, and it is also a real limit.
- If a mod fails to build for something that is plainly not about its own
  source, rebuild with `--no-cache`. A build verdict is cached, and an
  environmental failure — two compiles racing over one cache path — is cached
  with it and replays forever.
