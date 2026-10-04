## Example: Files and Tray
##
## The rest of what a desktop application is. `example.desktop` is the window;
## this is everything that happens around it - one copy only, a native file
## dialog that does not stop the game, a tray icon with a real context menu and
## a notification, files dropped onto the window, a real popup menu, and a key
## that works while the game is not even in front.
##
## Read the panel: every line of it is a live host answer, so what this mod
## prints is what the host actually did rather than what it was asked to do.
##
## In the editor most of this is refused and says so - the window it would put a
## tray icon beside is the editor's own. The file dialog does work in the editor,
## and so do the command line and the working directory.

import jester
import vec
import color
import draw
import input
import window
import render
import desktop

const
  Width = 520.0
  Height = 380.0
  Header = 38.0
  Panel = Color(r: 0.09, g: 0.10, b: 0.13, a: 0.92)
  Bar = Color(r: 0.13, g: 0.15, b: 0.19, a: 0.98)
  Rule = Color(r: 0.35, g: 0.75, b: 0.95, a: 0.95)
  Ink = Color(r: 0.93, g: 0.95, b: 0.97, a: 1.0)
  Dim = Color(r: 0.58, g: 0.63, b: 0.70, a: 1.0)
  Hot = Color(r: 0.85, g: 0.30, b: 0.32, a: 1.0)

var
  note = ""
  lastFile = "(nothing yet)"
  lastDrop = "(nothing yet)"
  lastKey = "(nothing yet)"
  trayNote = "(nothing yet)"
  alone = true
  probing = false
  since = 0.0
  age = 0.0

proc rowAt(top: float64; all: Rect): Rect =
  rect(18.0, top, all.width - 36.0, 20.0)

proc start() =
  # Before anything else: if another copy is already running it has just been
  # handed this one's command line and working directory, and this one has no
  # business opening a second window.
  alone = onlyInstance("example.filer")
  if not alone:
    log("example.filer: another copy is already running; it was handed " &
        $argCount() & " arguments and this copy is closing.")
    windowClose()
    return

  appWindow(rect(0.0, 0.0, Width, Height), "Files and Tray")
  windowClear(Color(r: 0.05, g: 0.06, b: 0.08, a: 1.0))
  idleWhenQuiet()

  note = desktopProblem()


  trayMenuItem("open", "Open a file...")
  trayMenuItem("show", "Show the window")
  trayMenuSeparator()
  trayMenuItem("shut", "Quit")

  menuItem("open", "File/Open...\tCtrl+O")
  menuItem("save", "File/Save as...")
  menuSeparator("File")
  menuItem("shut", "File/Quit")
  menuItem("about", "Help/About")

  # Every one of these is the platform's own answer, not a hope: Shell_NotifyIcon
  # said whether the icon went up, DragAcceptFiles said whether the window will
  # take a drop, RegisterHotKey said whether anything else already owns the
  # combination. A mod that discarded them would have no way to tell a working
  # tray from a silent one, and neither would anybody reading the log.
  let trayUp = tray("Jester - Files and Tray")
  let dropsOn = acceptDroppedFiles(true)
  let keyOn = globalKey("summon", "Ctrl+Alt+J")
  log("example.filer: tray=" & $trayUp & " showing=" & $trayShowing() &
      " drops=" & $dropsOn & " hotkey=" & $keyOn &
      " supports: dialogs=" & $desktopSupports("dialogs") &
      " tray=" & $desktopSupports("tray") & " paths=" & $desktopSupports("paths") &
      " nonsense=" & $desktopSupports("nonsense"))

  log("example.filer: desktop available = " & $desktopAvailable() & " " & note &
      " | launched from " & workingFolder() & " with " & $argCount() & " arguments")

  # A run nobody is watching, for proving the claim that a modal OS dialog does
  # not stop the render loop. The heartbeat below is the evidence.
  probing = argCount() > 0 and arg(0) == "--probe"
  if probing:
    # Continuous, so the frame count in the heartbeat means something. An idling
    # app draws five frames a second and a stopped one draws five a second too,
    # near enough that nobody could tell them apart from a log.
    drawContinuously()
    log("example.filer: probing - a file dialog will open in three seconds")

proc pickUpWhatHappened() =
  ## Everything this family answers is a queue, and a queue is read until it is
  ## empty - one drop of five files is five reads, not one.
  while droppedFiles() > 0:
    let dropped = nextDroppedFile()
    lastDrop = fileName(dropped) & "  (" & fileExtension(dropped) & ", " & $fileSize(dropped) & " bytes)"
    redraw()

  let key = globalKeyFired()
  if key.len > 0:
    lastKey = key
    raiseWindow()
    discard notify("Jester", "Summoned by Ctrl+Alt+J", InfoNote)
    redraw()

  var event = nextTrayEvent()
  while event != NothingHappened:
    if event == TrayDoubleClicked:
      restoreFromTray()
    if event == TrayMenuChosen:
      trayNote = trayChoice()
      if trayChoice() == "open": discard askOpenFile("Open", "All files|*.*")
      if trayChoice() == "show": restoreFromTray()
      if trayChoice() == "shut": windowClose()
    event = nextTrayEvent()
    redraw()

  let picked = menuChoice()
  if picked == "open": discard askOpenFile("Open", "Text|*.txt;*.md|All files|*.*")
  if picked == "save": discard askSaveFile("Save as", "Text|*.txt", "untitled.txt")
  if picked == "shut": windowClose()
  if picked == "about":
    discard notify("Files and Tray", "An Jester mod being an application.", InfoNote)

  # The dialog runs beside the game, so this is a poll and not a wait.
  if chosenReady() and not choosing():
    if chooseCancelled(): lastFile = "(cancelled)"
    elif chosenCount() > 0:
      let picked = chosenFile()
      lastFile = fileName(picked) & "  (" & $fileSize(picked) & " bytes)"
      if desktopSupports("paths"): log("example.filer: chosen at " & filePath(picked))
    redraw()

proc heartbeat() =
  ## The evidence for the one design decision in this family that could have gone
  ## the other way: a native file dialog runs beside the game rather than inside
  ## the host call. If this line keeps appearing, with the frame count climbing,
  ## while `choosing` is true, then update() is still being called and frames are
  ## still being drawn with a modal OS dialog on the screen. If the dialog were
  ## opened on the main thread this line would simply stop until it closed.
  age = age + deltaTime()
  since = since + deltaTime()
  if since < 1.0: return
  since = 0.0
  log("example.filer: alive at " & $int(age) & "s, frame " & $framesDrawn() &
      ", choosing=" & $choosing() & ", done=" & $chosenReady())
  if probing and age >= 3.0 and not choosing() and not chosenReady():
    log("example.filer: asking for a file - started=" &
        $askOpenFile("Probe: pick anything", "All files|*.*"))

proc update() =
  if not alone: return
  heartbeat()
  pickUpWhatHappened()

  let all = screen()
  windowDragBy(rect(0.0, 0.0, all.width - Header, Header))
  fill(all, Panel)
  fill(rect(0.0, 0.0, all.width, Header), Bar)
  fill(rect(0.0, Header - 1.0, all.width, 1.0), Rule)
  writeIn("Files and Tray", rect(14.0, 0.0, 260.0, Header), 14.0, AlignLeft, Ink)

  let shut = rect(all.width - Header, 0.0, Header, Header)
  if hovering(shut): fill(shut, Hot)
  writeIn("x", shut, 15.0, AlignCentre, Ink)
  if hovering(shut) and clicked(LeftButton): windowClose()

  let hide = rect(all.width - Header * 2.0, 0.0, Header, Header)
  if hovering(hide): fill(hide, Rule)
  writeIn("_", hide, 15.0, AlignCentre, Ink)
  if hovering(hide) and clicked(LeftButton): discard minimizeToTray()

  let menu = rect(0.0, Header, 90.0, 26.0)
  if hovering(menu): fill(menu, Bar)
  writeIn("  Menu", menu, 13.0, AlignLeft, Ink)
  # A real menu, opened from a button this mod drew itself. A frameless window
  # has nowhere to put a menu bar, so the bar is not what an app wants - the
  # same menu as a popup is.
  if hovering(menu) and clicked(LeftButton): discard popupMenu(vec2(4.0, Header + 26.0))

  let open = rect(100.0, Header, 150.0, 26.0)
  if hovering(open): fill(open, Bar)
  writeIn("  Open a file...", open, 13.0, AlignLeft, Ink)
  if hovering(open) and clicked(LeftButton):
    discard askOpenFile("Open", "Text|*.txt;*.md|Images|*.png;*.jpg|All files|*.*")

  var top = Header + 44.0
  writeIn("chosen file    " & lastFile, rowAt(top, all), 13.0, AlignLeft, Ink)
  top = top + 24.0
  writeIn("dropped file   " & lastDrop, rowAt(top, all), 13.0, AlignLeft, Ink)
  top = top + 24.0
  writeIn("global key     " & lastKey & "   (Ctrl+Alt+J)", rowAt(top, all), 13.0, AlignLeft, Ink)
  top = top + 24.0
  writeIn("tray choice    " & trayNote, rowAt(top, all), 13.0, AlignLeft, Ink)
  top = top + 24.0
  writeIn("tray icon      " & $trayShowing() & "   in tray " & $inTray(),
          rowAt(top, all), 13.0, AlignLeft, Dim)
  top = top + 24.0
  writeIn("only copy      " & $primaryInstance() & "   waiting " & $launchesWaiting(),
          rowAt(top, all), 13.0, AlignLeft, Dim)
  top = top + 24.0
  writeIn("started in     " & workingFolder(), rowAt(top, all), 12.0, AlignLeft, Dim)
  top = top + 22.0
  writeIn("program        " & programPath(), rowAt(top, all), 12.0, AlignLeft, Dim)
  top = top + 26.0
  if choosing():
    writeIn("a file dialog is open - and this window is still drawing",
            rowAt(top, all), 13.0, AlignLeft, Rule)
  elif note.len > 0:
    writeIn(note, rowAt(top, all), 12.0, AlignLeft, Dim)
  else:
    writeIn("drop a file on this window - " & rescueKeys() & " takes the window back",
            rowAt(top, all), 12.0, AlignLeft, Dim)

  # A second launch of the same program: take its arguments and come forward.
  if launchesWaiting() > 0:
    log("example.filer: another launch arrived: " & nextLaunch())
    raiseWindow()
    redraw()

  if held(LeftButton) or choosing(): redraw()
