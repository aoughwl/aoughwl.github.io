## A live look at Minecraft's own font, on a plain dark screen, so a person can
## judge it.
##
## Everything drawn here comes out of the player's own copy of Minecraft:
## `aoughwl.minecraft` extracts `assets/minecraft/textures/font/ascii.png`,
## publishes it as `font/ascii`, and answers `minecraft.gui font` with the cell
## size and the 256 rightmost-opaque-column measurements. Nothing here ships a
## font, and nothing here substitutes one: with no granted Minecraft the screen
## says so in the host's own font and every assertion below stays absent, which
## is the honest failure and is what makes this a test.
##
## ## Why the rule is a copy and not an import
##
## `mcuifont.nim` and `mcuicore.nim` beside this file are **verbatim copies** of
## the two modules of the same name in `aoughwl.mcui`. The point of this screen
## is to show what the real interface really draws, so it must run the real
## interface's arithmetic - but a `dependencies` entry on `aoughwl.mcui` would
## load that mod, and it draws Minecraft's title screen unconditionally, over
## this one. A copy a `diff` proves identical was the only way to have both. If
## they ever differ, this test is lying and the diff says so:
##
##     diff Assets/StreamingAssets/Mods/aoughwl.fonttest/mcuifont.nim \
##          Assets/StreamingAssets/Mods/aoughwl.mcui/mcuifont.nim
##
## ## What is on the screen
##
## Top to bottom: the whole printable ASCII range at two sizes, a pangram at
## four integer scales with rules under each, digits and punctuation, pairs a
## kerned font would close up, the sixteen vanilla colours with the game's own
## shadow rule applied to each, a line of raw section-sign formatting codes,
## accented Latin, CJK, the same runs again in the host's font for comparison,
## a very large run for looking at the sampling, the shadow beside the same run
## without one, and the sheet itself at 1:1 and eight of its cells at four times
## the nominal size.

import jester
import textures
import services
import mcuicore
import mcuifont

const
  Provider = "aoughwl.minecraft"
  GuiService = "minecraft.gui"
  FontSheet = 128.0
    ## The sheet in *nominal* pixels: sixteen cells of eight. Every source
    ## rectangle `layout` answers with is in that same nominal space, whatever
    ## the file really measures, so a 512x512 font pack needs no special case.
    ## This is `aoughwl.mcui`'s constant, spelled the same way.
  Ascent = 7.0
    ## Where the baseline sits inside the eight-pixel cell, as
    ## `assets/minecraft/font/include/default.json` declares it for
    ## `font/ascii.png`. Nothing in this pipeline reads that file - see the
    ## report - so it is written here in order to draw the rule the glyphs
    ## ought to be sitting on and let a person see whether they are.

var
  advances: seq[int] = @[]
  fontCell = 8
  asked = false
  told = false
  frames = 0

proc say(text: string) = log("[fonttest] " & text)

# ---------------------------------------------------------------------------
# Asking the importer for the measurements. The same few lines `aoughwl.mcui`
# uses, because it is the same seam.

proc numbers(text: string): seq[int] =
  result = @[]
  var value = 0
  var sign = 1
  var digits = false
  var i = 0
  while i <= text.len:
    if i == text.len or text[i] == ' ':
      if digits: result.add value * sign
      value = 0
      sign = 1
      digits = false
    elif text[i] == '-':
      sign = -1
    elif text[i] >= '0' and text[i] <= '9':
      value = value * 10 + (int(text[i]) - int('0'))
      digits = true
    inc i

proc askFont() =
  if asked: return
  if not serves(GuiService): return
  let line = callService(GuiService, "font")
  if line.len == 0: return
  let read = numbers(line)
  if read.len < 3: return
  asked = true
  fontCell = read[0]
  var columns: seq[int] = @[]
  var i = 2
  while i < read.len:
    columns.add read[i]
    inc i
  advances = advancesFromColumns(columns, fontCell)
  say("the sheet is " & $fontCell & " picture pixels a cell; " &
      $advances.len & " advances measured")

# ---------------------------------------------------------------------------
# Drawing
#
# Everything below takes SCREEN pixels and a scale - how many screen pixels one
# interface pixel is worth - because the whole point of this screen is to put
# several scales beside each other.

proc rule(x, y, w: float; r, g, b: float) =
  fill(x, y, w, 1.0, r, g, b, 1.0)

## One run of the bitmap font. `x`, `y` are the top-left of the line box in
## screen pixels; the glyphs sit in a cell eight interface pixels tall and the
## baseline is `Ascent` interface pixels down from `y`.
proc run(text: string; x, y, scale: float; r, g, b: float; shadow = true) =
  if advances.len == 0: return
  if not settable(text): return
  let glyphs = layout(text, advances, 0.0, 0.0)
  var pass = 0
  if not shadow: pass = 1
  while pass < 2:
    var rr = r
    var gg = g
    var bb = b
    var slide = 0.0
    if pass == 0:
      # The game's shadow: one INTERFACE pixel down and right - which is
      # `scale` screen pixels - at (c & 0xFC) >> 2 of the colour.
      slide = scale
      rr = shadowLevel(r)
      gg = shadowLevel(g)
      bb = shadowLevel(b)
    var i = 0
    while i < glyphs.len:
      let one = glyphs[i]
      inc i
      drawPicture(Provider, "font/ascii",
        x + one.dest.x * scale + slide, y + one.dest.y * scale + slide,
        one.dest.w * scale, one.dest.h * scale,
        one.src.x / FontSheet, one.src.y / FontSheet,
        (one.src.x + one.src.w) / FontSheet,
        (one.src.y + one.src.h) / FontSheet,
        rr, gg, bb, 1.0)
    inc pass

## The same run in the host's own font at the same nominal size, so the two can
## be compared where the bitmap sheet cannot answer at all.
proc hostRun(text: string; x, y, scale: float; r, g, b: float) =
  writeIn(text, x, y - scale, screenWidth() - x, 9.0 * scale, 9.0 * scale,
    "left", r, g, b, 1.0)

## A row of text with the three rules a person needs to judge it: the top of the
## line box, the baseline the sheet declares, and the top of the next line.
proc ruledRun(text: string; x, y, scale: float; r, g, b: float) =
  var w = float(measure(text, advances)) * scale + scale * 2.0
  if w < 1.0: w = 1.0
  rule(x, y, w, 0.22, 0.26, 0.34)
  rule(x, y + Ascent * scale, w, 0.50, 0.22, 0.22)
  rule(x, y + 9.0 * scale, w, 0.18, 0.32, 0.20)
  run(text, x, y, scale, r, g, b)

## A tick every eight interface pixels, which is one nominal cell. A run of
## narrow letters that ends well short of these ticks is the advance rule
## working; a run that lands on every eighth tick is a fixed-width font, which
## is what this is not.
proc ruler(x, y, scale: float; count: int) =
  var i = 0
  while i <= count:
    fill(x + float(i) * 8.0 * scale, y, 1.0, 6.0, 0.30, 0.34, 0.42, 1.0)
    inc i

const
  Ascii1 = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO"
  Ascii2 = "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
  Pangram = "The quick brown fox jumps over the lazy dog."
  Half1 = "The quick brown fox"
  Half2 = "jumps over"
  Digits = "0123456789 .,;:!?'\"()[]{}<>@#$%^&*-+=/\\|~`_"
  Kerny = "AV To Ta WA Yo ff il 11 ..."
  # A UTF-8 section sign is two bytes, both over 126, so this run cannot be set
  # in the sheet at all - which is the finding rather than the bug.
  Section = "\xC2\xA7aGreen \xC2\xA7cRed \xC2\xA79Blue \xC2\xA7eYellow \xC2\xA7lBold \xC2\xA7oItalic"
  Accented = "\xC3\x84\xC3\x96\xC3\x9C \xC3\xA1\xC3\xA9\xC3\xAD\xC3\xB3\xC3\xBA \xC3\xB1 \xC3\xA7 \xC3\x9F \xC2\xB0 \xC2\xB1"
  Cjk = "\xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E \xE4\xB8\xAD\xE6\x96\x87 \xED\x95\x9C\xEA\xB5\xAD\xEC\x96\xB4"

## The sixteen vanilla colours, in the order of the codes 0-9a-f, as
## `ChatFormatting` declares them. Written down here because nothing in the
## pipeline reads a colour code at all - see the report - so this row is what a
## coloured line WOULD look like if anything parsed one.
proc colourAt(i: int): seq[float] =
  case i
  of 0: @[0.0, 0.0, 0.0]
  of 1: @[0.0, 0.0, 0.667]
  of 2: @[0.0, 0.667, 0.0]
  of 3: @[0.0, 0.667, 0.667]
  of 4: @[0.667, 0.0, 0.0]
  of 5: @[0.667, 0.0, 0.667]
  of 6: @[1.0, 0.667, 0.0]
  of 7: @[0.667, 0.667, 0.667]
  of 8: @[0.333, 0.333, 0.333]
  of 9: @[0.333, 0.333, 1.0]
  of 10: @[0.333, 1.0, 0.333]
  of 11: @[0.333, 1.0, 1.0]
  of 12: @[1.0, 0.333, 0.333]
  of 13: @[1.0, 0.333, 1.0]
  of 14: @[1.0, 1.0, 0.333]
  else: @[1.0, 1.0, 1.0]

# ---------------------------------------------------------------------------
# What it measured, in the shape `expect state` reads

proc countGlyphs(): int =
  result = 0
  var c = 33
  while c <= 126:
    if advanceOf(advances, c) > 1: inc result
    inc c

proc tellAll() =
  if told or advances.len == 0: return
  told = true
  log("[assert] fonttest.ready=yes")
  log("[assert] fonttest.cell=" & $fontCell)
  log("[assert] fonttest.advances=" & $advances.len)
  log("[assert] fonttest.glyphs=" & $countGlyphs())
  log("[assert] fonttest.lineheight=" & $LineHeight)
  log("[assert] fonttest.width.pangram=" & $measure(Pangram, advances))
  log("[assert] fonttest.width.ascii=" & $measure(Ascii1 & Ascii2, advances))
  log("[assert] fonttest.advance.space=" & $advanceOf(advances, 32))
  log("[assert] fonttest.advance.i=" & $advanceOf(advances, 105))
  log("[assert] fonttest.advance.A=" & $advanceOf(advances, 65))
  log("[assert] fonttest.advance.W=" & $advanceOf(advances, 87))
  if hasPicture(Provider, "font/ascii"):
    log("[assert] fonttest.sheet=yes")
  else:
    log("[assert] fonttest.sheet=no")
  if settable(Ascii1 & Ascii2):
    log("[assert] fonttest.settable.ascii=yes")
  else:
    log("[assert] fonttest.settable.ascii=no")
  if settable(Section):
    log("[assert] fonttest.settable.section=yes")
  else:
    log("[assert] fonttest.settable.section=no")
  if settable(Accented):
    log("[assert] fonttest.settable.accented=yes")
  else:
    log("[assert] fonttest.settable.accented=no")
  if settable(Cjk):
    log("[assert] fonttest.settable.cjk=yes")
  else:
    log("[assert] fonttest.settable.cjk=no")

# ---------------------------------------------------------------------------

proc start() =
  say("waiting for " & GuiService & " to answer for the font")

proc update() =
  inc frames
  askFont()
  tellAll()

## The screen this lays out on.
##
## 640x480 is what a headless editor gives, and 1280x720 is what a person's
## window gives; the difference matters more than it looks, because a capture
## taken at a different shape than the game view is STRETCHED to it - which
## smears the glyphs on its own and would be blamed on the font. So nothing
## here is written in absolute numbers against one size: the whole sheet of
## samples is laid out in a 640 by 480 design and multiplied by whichever of
## the two axes has less room, and `tools/playtest.exe` is worth running with
## `-width 640 -height 480` on the Unity command line to get a capture with no
## stretch in it at all.
const
  DesignW = 640.0
  DesignH = 480.0

var k = 1.0   ## design pixels to screen pixels

proc dx(v: float): float = v * k
proc dy(v: float): float = v * k

proc small(text: string; x, y: float) =
  writeIn(text, dx(x), dy(y), screenWidth() - dx(x), dy(11.0), dy(9.0), "left",
    0.44, 0.49, 0.60, 1.0)

proc drawGui() =
  # A plain dark background, and nothing else on the screen.
  fill(0.0, 0.0, screenWidth(), screenHeight(), 0.055, 0.058, 0.070, 1.0)
  k = screenWidth() / DesignW
  if screenHeight() / DesignH < k: k = screenHeight() / DesignH

  let ok = advances.len > 0
  var head = "aoughwl.fonttest - no font sheet has answered yet"
  if ok:
    head = "aoughwl.fonttest - Minecraft font/ascii, " & $fontCell &
      "px cells, " & $countGlyphs() & " glyphs, line height " & $LineHeight
  writeIn(head, dx(6.0), dy(1.0), screenWidth(), dy(13.0), dy(11.0), "left",
    0.66, 0.70, 0.80, 1.0)

  if not ok:
    writeIn("Nothing has answered " & GuiService & " for the font sheet. No " &
      "substitute font is drawn on purpose: this screen is empty exactly " &
      "when the import did not reach textures/font/ascii.png.",
      dx(6.0), dy(30.0), screenWidth() - dx(12.0), dy(60.0), dy(12.0), "left",
      0.85, 0.55, 0.45, 1.0)
    return

  let x0 = 8.0

  # -- the whole printable range, at 1 and at 2 ------------------------------
  small("printable ASCII 32-126 at scale 1, over a tick every nominal cell",
    x0, 14.0)
  ruler(dx(x0), dy(24.0), k, 48)
  run(Ascii1, dx(x0), dy(30.0), k, 1.0, 1.0, 1.0)
  run(Ascii2, dx(x0), dy(40.0), k, 1.0, 1.0, 1.0)
  small("the same range at scale 2", x0, 52.0)
  run(Ascii1, dx(x0), dy(62.0), k * 2.0, 1.0, 1.0, 1.0)
  run(Ascii2, dx(x0), dy(82.0), k * 2.0, 1.0, 1.0, 1.0)

  # -- a pangram at four scales, on rules ------------------------------------
  small("a pangram at scales 1, 2, 3, 4 - line-box top (blue), baseline at " &
    "ascent 7 (red), next line at +9 (green)", x0, 102.0)
  ruledRun(Pangram, dx(x0), dy(114.0), k, 1.0, 1.0, 1.0)
  ruledRun(Pangram, dx(x0), dy(126.0), k * 2.0, 1.0, 1.0, 1.0)
  ruledRun(Half1, dx(x0), dy(148.0), k * 3.0, 1.0, 1.0, 1.0)
  ruledRun(Half2, dx(x0), dy(180.0), k * 4.0, 1.0, 1.0, 1.0)

  # -- digits, punctuation, and the pairs a kerned font would close up -------
  small("digits and punctuation at scale 2", x0, 216.0)
  run(Digits, dx(x0), dy(226.0), k * 2.0, 1.0, 1.0, 1.0)
  small("pairs a kerned font would close up, at scale 3", x0, 246.0)
  run(Kerny, dx(x0), dy(256.0), k * 3.0, 1.0, 1.0, 1.0)

  # -- the sixteen colours, each with its own shadow --------------------------
  small("the sixteen vanilla colours, drawn by hand - nothing in this " &
    "pipeline parses a section-sign code", x0, 286.0)
  var c = 0
  while c < 16:
    let col = colourAt(c)
    run("Colour" & $c, dx(x0 + float(c mod 6) * 78.0),
      dy(298.0 + float(c div 6) * 12.0), k, col[0], col[1], col[2])
    inc c

  # -- what the sheet cannot set ---------------------------------------------
  small("raw section-sign codes, accents, CJK: all unsettable, so the sheet " &
    "draws nothing and the host font (orange) is the fallback", x0, 336.0)
  run(Section, dx(x0), dy(350.0), k, 1.0, 1.0, 1.0)
  hostRun(Section, dx(x0), dy(350.0), k, 0.92, 0.62, 0.42)
  run(Accented, dx(x0), dy(362.0), k, 1.0, 1.0, 1.0)
  hostRun(Accented, dx(x0), dy(362.0), k, 0.92, 0.62, 0.42)
  run(Cjk, dx(x0), dy(374.0), k, 1.0, 1.0, 1.0)
  hostRun(Cjk, dx(x0), dy(374.0), k, 0.92, 0.62, 0.42)

  # -- very large, for the sampling, and the shadow beside itself ------------
  small("scale 6 - point-filtered like Minecraft, or blurred? - then the " &
    "same run without and with the one-pixel shadow", x0, 392.0)
  run("Ag1", dx(x0), dy(406.0), k * 6.0, 1.0, 1.0, 1.0)
  run("Shad", dx(140.0), dy(406.0), k * 4.0, 1.0, 1.0, 1.0, false)
  run("Shad", dx(260.0), dy(406.0), k * 4.0, 1.0, 1.0, 1.0)
  small("a fractional scale 2.5, which lands glyphs off whole pixels",
    x0, 452.0)
  run(Pangram, dx(x0), dy(462.0), k * 2.5, 1.0, 1.0, 1.0)

  # -- the sheet itself -------------------------------------------------------
  small("font/ascii, 1:1", 505.0, 140.0)
  fill(dx(504.0), dy(150.0), dx(130.0), dy(130.0), 0.14, 0.15, 0.18, 1.0)
  drawPicture(Provider, "font/ascii", dx(505.0), dy(151.0), dx(128.0),
    dy(128.0), 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0)
  small("cells @A-W at 4x", 505.0, 288.0)
  fill(dx(504.0), dy(298.0), dx(130.0), dy(66.0), 0.14, 0.15, 0.18, 1.0)
  drawPicture(Provider, "font/ascii", dx(505.0), dy(299.0), dx(128.0),
    dy(64.0), 0.25, 0.25, 0.5, 0.375, 1.0, 1.0, 1.0, 1.0)

proc stop() =
  discard
