## Example: The Window Escape
##
## A deliberately hostile mod, and the only way to prove the escape is real.
##
## Every frame this mod asks for a window that is frameless, per-pixel
## transparent, always on top, clicked through, and parked in the far corner of
## the desktop where almost none of it is visible. That is not a bug in the mod;
## it is what a half-written application mod does by accident, and what a
## malicious one would do on purpose. Nothing about it is illegal - each of those
## calls exists because an application legitimately wants it - and together they
## are a player who cannot click on, move, see or close their own game.
##
## Unloading the mod would give the window back. The mod is not unloading.
##
## So the host watches for `rescueKeys()` itself, outside every mod, and takes
## the window back: decorated, opaque, not on top, not clicked through, on
## screen. While it holds it, every one of the shaping calls below is refused
## and `windowProblem()` says why - which is what stops this mod from simply
## putting it all back on the next frame. Pressing the same keys again hands the
## window back to the mod; so does reloading the mod.
##
## Once a second this mod writes what the window actually is, next to what it
## asked for. That line is the proof: run the player, press the keys, and read
## the log.

import jester
import vec
import color
import input
import draw
import window
import render
import desktop

const
  Ink = Color(r: 0.95, g: 0.93, b: 0.90, a: 1.0)
  Warn = Color(r: 0.95, g: 0.45, b: 0.25, a: 1.0)
  Panel = Color(r: 0.10, g: 0.06, b: 0.06, a: 0.90)

var
  since = 0.0
  told = 0

proc misbehave() =
  ## Everything a mod may do to a window, at once, every frame.
  windowFrame(false)
  windowTransparent(true)
  windowClear(Clear)
  windowOnTop(true)
  windowClickThrough(true)
  windowMove(int(desktopSize().x) - 60, int(desktopSize().y) - 60)

proc start() =
  appWindow(rect(0.0, 0.0, 380.0, 200.0), "Escape")
  misbehave()
  drawContinuously()
  log("example.escape: the window is now frameless, transparent, on top, " &
      "click-through and off the corner of the desktop. " &
      "Press " & rescueKeys() & " to take it back.")

proc update() =
  misbehave()

  since = since + deltaTime()
  if since >= 1.0:
    since = 0.0
    told = told + 1
    # What the window actually is, not what was asked for. The two disagree
    # exactly when the host has taken it back.
    log("example.escape: framed=" & $windowFramed() &
        " through=" & $windowClickThrough() &
        " ontop=" & $windowOnTop() &
        " transparent=" & $windowTransparent() &
        " at=" & $int(windowAt().x) & "," & $int(windowAt().y) &
        " rescues=" & $rescues() &
        " problem=" & windowProblem())

  let all = screen()
  fill(all, Panel)
  writeIn("this mod is misbehaving on purpose",
          rect(16.0, 16.0, all.width - 32.0, 22.0), 14.0, AlignLeft, Ink)
  writeIn(rescueKeys() & " takes the window back",
          rect(16.0, 46.0, all.width - 32.0, 22.0), 14.0, AlignLeft, Warn)
  writeIn("rescued " & $rescues() & " times",
          rect(16.0, 76.0, all.width - 32.0, 22.0), 13.0, AlignLeft, Ink)
