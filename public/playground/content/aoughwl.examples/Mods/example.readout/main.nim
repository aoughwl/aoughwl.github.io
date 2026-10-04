## Example: HUD Readout
##
## Drawing happens in update(), not drawGui(): OnGUI never runs without a game
## view, so anything drawn from drawGui() is invisible to a headless capture.
## A frame's drawing is whatever was asked for during it, and no longer.

import jester
import vec        # Rect, topRow, under, inset
import color      # Color
import draw       # fill, writeIn, AlignLeft, AlignRight
import input      # screen()

const
  Ink = Color(r: 0.05, g: 0.06, b: 0.08, a: 0.82)
  Rule = Color(r: 0.35, g: 0.75, b: 0.95, a: 0.9)
  Text = Color(r: 0.92, g: 0.94, b: 0.96, a: 1.0)

var
  alive = 0.0
  visits = 0'i64

proc start() =
  # remember/save is the only state that outlives a modpack switch, and it
  # reaches disk under Saves/default/state/example.readout.json.
  visits = remember("visits", 0'i64) + 1
  save("visits", visits)
  log("example.readout: visit " & $visits)

proc update() =
  alive = alive + deltaTime()

  let bar = screen().topRow(26.0)
  fill(bar, Ink)
  fill(bar.under(25.0), Rule)
  let inside = bar.inset(8.0)
  writeIn("example.readout", inside, 13.0, AlignLeft, Text)
  writeIn("visit " & $visits & "   up " & $int(alive) & "s", inside, 13.0,
    AlignRight, Text)
