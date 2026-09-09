# The UI library

The host draws three things: a filled rectangle, text in a box, and an image
with a source sub-rect. Everything else on the screen — windows, scrolling
lists, grids, drag and drop — is a **mod**, and this is that mod.

It is a library: it spawns nothing, draws nothing of its own, and declares no
catalogs. A mod depends on it in `mod.json` and then `import ui`.

[[toc]]

| module | what it is | import it when |
| --- | --- | --- |
| `ui_floor` | the floor: clip, paint, id stack, pointer state machine, drag and drop | you are writing a widget |
| `ui` | the builder: layout, grid, panel, button, list, scroll, slot, tile | always — it exports `ui_floor` |
| `ui_dsl` | block forms, as templates | you want `screen:` blocks |

The layering is the SDK's own: sugar is opt-in, and a mod that does not want it
never pays for it. These are templates rather than macros, so importing the DSL
costs one module rather than the thirty-odd `std/macros` drags in.

## The frame

A frame is exactly one `beginFrame()` … `endFrame()`, and every press, click,
drag and drop is derived from the two pointer facts those two calls see.

```nim
import ui

proc drawGui() =
  beginFrame()
  panel(rect(80.0, 80.0, 420.0, 300.0))
  var side = column(rect(92.0, 92.0, 396.0, 276.0))
  heading(side.take(26.0), "STASH")
  if button("sort", side.take(30.0), "Sort"): sortEverything()
  endFrame()
```

`beginFrame(at, down, area)` **takes** the pointer facts rather than reading
them. That is the seam the whole library turns on: it is how a mod drives its
interface from a gamepad, from a cursor a peer is moving, or — as the tests do —
from a script with no mouse and no screen anywhere.

`mute(true)` runs a frame's layout and hit testing with the drawing turned off.
That is a sizing pass — lay a panel out, ask how tall it came to, draw it for
real at that height — and it is what lets a headless check drive a real screen
with no host at all.

## The floor

**Clipping.** The host has no scissor rectangle, so it is arithmetic.
`pushClip(r)` crops everything until `popClip()`, and crops hit testing with it,
so a row scrolled out of sight cannot be clicked.

- a rectangle is cropped exactly;
- a picture is cropped, and the part of the picture that shows is cropped with
  it, so an icon at the edge of a list is cut off rather than squashed;
- a line of text is drawn only when its whole row fits. There is no way to draw
  half a glyph, so `fitted(text, width, size)` is how a caller shortens a line
  instead.

**Ids.** A widget is told apart by its name and by the names it is nested under.
`pushId("bag")` in front of `touch("slot3", r)` is `bag/slot3`, so the same list
drawn twice on one screen is two lists. The stack is frame-scoped.

**Painting.** `paint(rect, colour)`, `paint(text, within, size, align, colour)`,
`paintImage(file, within, tint)`, `border(rect, thickness, colour)`. Colours and
sizes come from a style value, and `restyle(look)` replaces the whole set —
there is no theme registry and no engine-side skin.

**The pointer.** `touch(name, rect)` is the whole input state machine and
answers four things:

| | |
| --- | --- |
| `hot` | the pointer is over it and nothing drawn later has taken the pointer |
| `grabbed` | the button went down on it, this frame |
| `held` | it went down on it and has not come up |
| `clicked` | it went down on it and came up on it, this frame |

Whichever widget claims the pointer last in a frame is the topmost one, and it
learns so on the next frame — so a panel drawn over a list takes the click
without anything having to know about layers. While a press is held, only the
widget it landed on hears about it.

## Drag and drop

A drag is a press that moved. A threshold in pixels is what separates a click
from a drag, and a press is one or the other and never both.

```nim
let held = tile("bandage", box, "Bandage", carry("item", "bandage", 1))
let here = slot("cell4", cellAt(bag, 1, 1), "item")
if here.dropped: put(here.load.id, 1, 1)
ghost(captionOf(carried().id))     # last in the frame, so it is on top
```

A `Carry` is a kind, an id and a count — the vocabulary a catalog already speaks
— plus where in the source rectangle the pointer took hold and how big the thing
was, so the ghost does not jump and is the size of the hole it left.

`dropZone(name, rect, accepts)` answers nothing at all while no drag is live.
The target under the pointer is the one that claimed it last, which resolves
overlapping targets the same way overlapping widgets are resolved.

Two ways to hear about a drop, and both are needed:

- **at the target**, on the frame the button comes up. This is what moves the
  thing.
- **`landing()` for everyone else**, on the frame after. It carries the load and
  the name of the target, and the target is empty when it landed on nothing —
  which is the only way a source hears that its thing was dropped on the floor.
  Cancelling a drag announces a landing on nothing too, so undo has one path.

## The builder

Layout is arithmetic on rectangles, never a call into the host's panel stack.
That stack is one column, cannot nest and cannot be cropped, so a window with a
scrolling list in it cannot be written on it.

```nim
var down = column(area, 6.0)      # or across(area)
let title = down.take(26.0)       # claim 26 of it
down.skip(8.0)
let body = rest(down)             # what is left
panelHeight = taken(down).height  # what was handed out
let three = share(row, 3, 6.0)    # even pieces
```

A `Grid` is square cells in rows and columns, which is what an inventory is:

```nim
let bag = grid(vec2(60.0, 130.0), 8, 6, 44.0, 2.0)
cellAt(bag, 2, 1)                 # one cell
span(bag, 0, 2, 4, 1)             # a four-wide rifle
cellUnder(bag, pointerAt())       # where a drop landed
fits(bag, 5, 4, 4, 1)             # would it still be on the grid
```

Widgets: `panel`, `label`, `heading`, `hint`, `button`, `toggle`, `slot`,
`tile`, `ghost`. Regions: `beginScroll`/`endScroll`, and
`beginList`/`rowAt`/`endList` — a scrolling list that only draws the rows you
can see, so a bag with two thousand things in it costs the twenty on the screen.

## Blocks

```nim
import ui_dsl

screen:
  panel(box)
  inside "stash":
    scrolling view, "rows", box, 900.0:
      var down = column(view.content)
      label(down.take(24.0), "row one")
```

`screen`, `screenAt`, `cropped`, `inside`, `scrolling`, `listing`. Each is
exactly the pair of `ui` calls it replaces, with the closing one impossible to
forget.

## How it is proved

A test loads the built mod into the real interpreter behind a host callback that
answers the pointer, the mouse button, the screen and the three drawing calls,
and records every rectangle and every run of text asked for. Then it scripts a
mouse across `drawGui()` frame by frame and asks the mod, out loud, where its
things ended up.

Two things run: the mod's own `start()`, which drives 68 assertions through the
state machine with drawing muted and no host call but `log` — a press is not a
click, a click comes up where it went down, a press that wandered off is not a
click, the widget drawn later takes the pointer, the same name in two scopes is
two widgets, a clip crops hit testing, a drag needs movement, a payload
survives, a drop lands on the topmost target, a refused drop changes nothing, a
cancelled drag lands on nothing — and then a real drag between two bags, through
`drawGui()`, reading the pointer exactly as it does in the game.

A screenshot can show a panel. It cannot show that a press became a click, that
a click did not become a drag, or that a drop landed on the right target, which
is why the test is the evidence and a picture would not be.

## The one host call this needed

There was no way to put a picture on the screen: a filled rectangle and text in
a box were the whole of the drawing surface, and an inventory of icons cannot be
written out of coloured rectangles.

The image call names a file in the calling mod's own folder — the same way a
texture does — and the host decodes it once and frees it when the mod unloads.
Its `u`/`v` window says which part of the picture goes in the box, in 0..1 with
0 at the top: the whole of it by default, a tile of a sprite sheet when it is
less, and the part that survived a clip when the caller has cropped the box.
That is how an icon is cropped instead of squashed.

## What mod code cannot recover

Two things, and both are host gaps rather than design choices:

- **the scroll wheel.** There is no host call for it, so a scroll region is
  driven by a scrollbar or by keys.
- **glyph-level clipping.** Text is dropped by whole lines, so a scrolling list
  cannot show a half-row.

Line and polygon drawing, rotated text, and any font other than the built-in one
are missing too.
