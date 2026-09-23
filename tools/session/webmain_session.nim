## webmain_session.nim — aowli's browser entry for a LIVE SESSION.
##
## Every other browser entry aowli has is one-shot: `webtest/webmain.nim` runs a
## program to completion and prints, and the playground's `aowli.js` /
## `aowli_vm.js` are that entry wrapped in `new Function(...)` — module init IS
## the run, and when it returns there is nothing left to talk to. That model
## cannot hot-swap, because a swap needs an interpreter that is still standing
## between edits.
##
## This entry keeps one. It loads a `.s.nif` as a `HotModule`, holds the `Interp`
## alive on the module level, and exposes the four verbs a live session needs:
## call something, republish the code and keep the state, republish and run only
## what was appended, and stop.
##
## It also carries a host-call boundary wired to JavaScript (`__sess_host`),
## so a program that makes host calls and one that does not run on ONE bundle
## rather than two. A playground program never sets it.
##
## ── THE BUG THIS FILE WAS WRITTEN AGAINST ──────────────────────────────────
##
## The published claim is that aowli's hot swap "does not work in this browser
## build" — that `swapHot` returns success, raises nothing, increments the
## generation, and leaves the interpreter executing the PREVIOUS body. That was
## measured honestly, and the conclusion drawn from it was wrong: the fault was
## never in `swapHot`.
##
## `swapHot` re-reads `hm.path` from the VFS. The seam that was measured
## republished the new bytes with `webvfs.publishMainModule`, whose whole body is
##
##     if not webHas(nif): webPut(nif, src)
##
## It REFUSES TO OVERWRITE — deliberately, so a glue that frames `webmod.s.nif`
## itself keeps its own bytes. So the new artifact was dropped on the floor,
## `swapHot` re-read the OLD file, republished decls identical to the ones
## already live, bumped the generation and returned true. Every symptom follows
## from that, exactly, including the one that looked most damning: a plain
## re-boot of the same bytes DID show the new behaviour, because boot builds a
## fresh VFS.
##
## So a swap here writes through `webPut` directly (see `republish`), and
## `publishMainModule` is used only where it is correct — the first load.
##
## ── THE JS CONTRACT ────────────────────────────────────────────────────────
##   in   __sess_src     the module artifact's bytes, latin1, one char per byte
##        __sess_mods    sibling modules, framed for webvfs
##        __sess_in      stdin for the session
##        __sess_host    optional function(name, args) -> {k, v} | undefined
##                         k: "n" nil | "i" int | "f" float | "b" bool
##                            | "s" string | "x" the host call failed
##                         undefined == "this host does not answer that call",
##                         which is the browser's honest answer for the calls it
##                         cannot serve.
##   out  __sess_boot()      start a session from __sess_src (runs the top level)
##        __sess_load()      start a session WITHOUT running the top level
##        __sess_has(name)   -> __sess_bool
##        __sess_call(name)  -> run one callback; result on __sess_ret
##        __sess_swap()      republish __sess_src over the live module, keeping
##                           every global; initializes only globals that are NEW
##        __sess_append(n)   republish and run ONLY top-level statements >= n
##        __sess_stop()      drop the session
##        __sess_globals()   -> __sess_globs: the program's module-level variables
##                           and their current values, as a JSON array of
##                           {"n": name, "v": rendered value}. A pure read.
##   state
##        __sess_ok          did the last verb succeed
##        __sess_err         "" or why it did not
##        __sess_out         stdout SINCE THE LAST VERB (a delta, not a total)
##        __sess_gen         0 on load, +1 per successful swap
##        __sess_drift       "" or one line per symbol whose SIGNATURE moved
##        __sess_newglobals  globals the last swap had to initialize
##        __sess_bases       what the module published, comma-joined
##        __sess_ranto       after __sess_append: the new statement total
##        __sess_live        is a session standing right now
##        __sess_ready       the seam registered (set once, at module init)

when defined(nimony):
  {.feature: "lenientnils".}

import nifcursors, programs
import values, natives, trace, interp
import webvfs
import jsffi

var
  sink: OutSink = nil
  machine: Interp = nil
  hot: HotModule
  live = false
  hostFailed = false
  ranTo = 0
  lastErr = ""

proc park(name: string; v: JsValue) =
  let g = global("globalThis")
  g.set(name, v)

proc jsText(v: JsValue): string =
  ## `toStr` builds its result with `newString(n)` + a raw byte write, and a
  ## string built that way compares UNEQUAL to an identical string at length >= 6
  ## in this backend (docs/WEB.md, "the one interpreter bug this found"). Copying
  ## through `add` yields a string `==` agrees with.
  result = ""
  let s = toStr(v)
  for i in 0 ..< s.len: result.add s[i]

proc sameText(a, b: string): bool =
  ## Compare two strings WITHOUT `==`.
  ##
  ## This backend's `==` answers FALSE for two identical strings at length >= 6
  ## when one of them was built by `newString(n)` plus a raw byte write — the bug
  ## `jsText` above exists to route around. Every string that arrives from JS is
  ## built that way, including the one `jsTypeof` hands back.
  ##
  ## MEASURED, not theorised: `jsTypeof(ret) == "undefined"` (nine characters)
  ## read false for a genuinely undefined value, so the guard below fell through
  ## and the seam read `ret["k"]` off `undefined` — "Cannot read properties of
  ## undefined (reading 'k')", which stopped the session. A host that returns
  ## `{k:"n"}` for a declined call never hits it; the moment a host declines
  ## honestly with `undefined`, it fires.
  if a.len != b.len: return false
  for i in 0 ..< a.len:
    if a[i] != b[i]: return false
  true

proc drain() =
  ## Park stdout/stderr as a DELTA and clear the buffers.
  ##
  ## `webmain_host.nim` parks `sink.outBuf` whole on every call and lets the
  ## caller re-read a string that only ever grows. That is fine for a mod whose
  ## host redraws from scratch each frame; it is wrong for a session, which is
  ## open for as long as someone is editing and whose console wants what happened
  ## SINCE the last verb. A total would also be re-marshalled across the JS
  ## boundary in full on every single frame.
  if sink == nil:
    park("__sess_out", toJs(""))
    park("__sess_stderr", toJs(""))
    return
  park("__sess_out", toJs(sink.outBuf))
  sink.outBuf = ""
  ## STDERR IS DRAINED TOO, AND KEPT.
  ##
  ## It used to be read only by `raised()`, which meant it was surfaced only for
  ## a RAISE — and the interpreter's other way of stopping is a HALT, which is
  ## not one. A mod that aborted produced "the machine has HALTED (exit code 1)
  ## ... See its stderr for the reason" on every later callback, and the reason
  ## itself was sitting in a buffer nobody ever read. That is the worst shape a
  ## failure can take: a message that names where the answer is, from a seam that
  ## then throws the answer away.
  lastErr = sink.errBuf
  sink.errBuf = ""
  park("__sess_stderr", toJs(lastErr))

proc failWith(msg: string) =
  park("__sess_ok", toJs(false))
  park("__sess_err", toJs(msg))

proc succeed() =
  park("__sess_ok", toJs(true))
  park("__sess_err", toJs(""))

proc raised(): bool =
  ## Did the last entry into interpreted code raise? Clears it if so, and parks
  ## the interpreter's own error text, which is the only thing that names the
  ## line.
  if machine == nil: return false
  if hotRaised(machine):
    hotClearRaise(machine)
    var msg = lastErr
    if sink != nil and sink.errBuf.len > 0:
      msg = msg & sink.errBuf
      sink.errBuf = ""
    failWith(msg)
    return true
  false

proc jsHostCall(context: int64; name: string; args: seq[Value];
    handled: var bool): Value {.nimcall.} =
  ## The host boundary: it refuses to marshal anything that is not a scalar,
  ## exactly as the native bridge does, so a call that is awkward here is
  ## awkward there too.
  ##
  ## A session with no `__sess_host` (every playground program) never reaches
  ## past the nil test, and aowli then reports the call unported by its own
  ## route rather than through a half-built boundary.
  result = vNil()
  let hostFn = global("__sess_host")
  if isNil(hostFn):
    return
  let arr = newJsArray()
  for i in 0 ..< args.len:
    let value = args[i]
    case value.kind
    of vkInt, vkUInt, vkChar, vkEnum:
      arr.add(toJs(int(asInt(value))))
    of vkFloat:
      arr.add(toJs(value.fval))
    of vkBool:
      arr.add(toJs(value.bval))
    of vkString:
      arr.add(toJs(value.sval))
    of vkNil:
      ## A NIL ARGUMENT IS "NOTHING", NOT "UNSUPPORTED".
      ##
      ## `bridgeHostCall` in NativeHost/aowli_host.nim refuses `vkNil` along with
      ## seqs and objects, and this seam copied that. It is wrong for nil, and it
      ## showed up as a chain rather than as a bug in any one place:
      ##
      ##   a browser host has no font family -> it declines the font call
      ##   -> the program receives NOTHING back and carries it
      ##   -> that nothing arrives as the first argument to a draw call
      ##   -> the bridge refuses the WHOLE CALL as "unsupported value"
      ##
      ## So a mod that merely asked for something the host lacks stops drawing
      ## entirely, and the message names `draw_text` — a call the host serves
      ## perfectly well — instead of the font call that was actually missing.
      ## Measured on `aoughwl.grid`: a blank canvas and three of those a frame.
      ##
      ## Nil is representable here (JS has two spellings of it) and every host
      ## call that can receive one already has to cope with an absent value, so
      ## it is passed through as `null` and the HOST decides. `draw_text` with no
      ## text draws nothing, which is the truthful outcome.
      ##
      ## The C ABI has the same gap and it is not fixed from here: `HostValue`
      ## has an `hvNil` kind that `bridgeHostCall` never produces for an
      ## ARGUMENT, only for a return.
      ## `jsffi` has no null constructor, and `global(name)` interns whatever
      ## `globalThis[name]` holds — so a global the host defines as `null` is one.
      ## If nothing defined it the lookup yields `undefined`, which is the same
      ## answer for every purpose a host call has, so this cannot fail open.
      arr.add(global("__sess_null"))
    else:
      hostFailed = true
      failWith("unsupported value passed to host API '" & name & "'")
      handled = true
      return
  let ret = call(global("globalThis"), "__sess_host", toJs(name), arr)
  if isNil(ret) or sameText(jsTypeof(ret), "undefined"):
    return                                  # declined; aowli reports it unported
  handled = true
  let kind = jsText(get(ret, "k"))
  if kind == "i": result = vInt(int64(toInt(get(ret, "v"))))
  elif kind == "f": result = vFloat(toFloat(get(ret, "v")))
  elif kind == "b": result = vBool(toBool(get(ret, "v")))
  elif kind == "s": result = vStr(jsText(get(ret, "v")))
  elif kind == "x":
    hostFailed = true
    failWith("host API '" & name & "' failed")
  else: result = vNil()

proc modulePath(): string =
  WebDir & "/" & MainModuleName & ".s.nif"

proc republish(src: string) =
  ## Put NEW BYTES where `swapHot` will re-read them. Not
  ## `publishMainModule` — see the header: that one refuses to overwrite, and
  ## routing a swap through it is the whole of the "hot swap is broken in the
  ## browser" story.
  webPut(modulePath(), src)

proc parkModuleFacts() =
  park("__sess_gen", toJs(hot.generation))
  park("__sess_newglobals", toJs(hot.newGlobals))
  var names = ""
  for i in 0 ..< hot.bases.len:
    if i > 0: names.add ","
    names.add hot.bases[i]
  park("__sess_bases", toJs(names))
  ## DRIFT IS THE POINT, not a footnote. `swapHot` records one entry per symbol
  ## whose published signature moved under a live caller, and arms the call side
  ## so a call binding a definitely-wrong-typed value raises instead of answering
  ## plausibly and wrongly. A host that never reads this has a hot reload that
  ## "mysteriously breaks"; one that does can say which declaration did it.
  var d = ""
  for i in 0 ..< hot.drift.len:
    if i > 0: d.add "\n"
    d.add hot.drift[i]
  park("__sess_drift", toJs(d))

proc startSession(runInit: bool) =
  installWebVfs()
  loadWebModules(toStr(global("__sess_mods")))
  let src = toStr(global("__sess_src"))
  ## THE SAME NO-OVERWRITE TRAP, ON THE LOAD PATH. `publishMainModule` writes
  ## the module and its synthesized empty index only when they are ABSENT — and
  ## the VFS is a module-level table that outlives a session, because
  ## `installWebVfs` rebinds the relays without clearing the store. So the first
  ## mod a worker loads publishes `/w/webmod.s.nif`, and every mod after it is
  ## silently dropped and the FIRST one is loaded again.
  ##
  ## It is invisible from the outside: the load succeeds, the callbacks are all
  ## there, the picture is a real mod drawing. Measured — starting 2048 and
  ## asking what the module published came back with `handBack`, `playPack`,
  ## `drawModsBar` and a `jes1zlvow` suffix, which is the SHELL. Every launch
  ## from the menu had been re-running the launcher.
  ##
  ## So: let `publishMainModule` create the index (that is the part only it
  ## knows how to synthesize), then overwrite the module with the bytes this
  ## session was actually given.
  publishMainModule(src)
  republish(src)
  setupProgramForTesting(WebDir, MainModuleName, ".s.nif")
  sink = newOutSink()
  sink.hostContext = 0
  sink.hostCall = jsHostCall
  sink.inBuf = toStr(global("__sess_in"))
  sink.inPos = 0
  sink.inLoaded = true
  machine = newInterp(sink, newTrace(tmOff))
  machine.enableAbortTrack()
  hostFailed = false
  live = false
  ranTo = 0
  lastErr = ""
  hot = loadHot(machine, modulePath(), runInit)
  drain()
  if hostFailed: return
  if hotRaised(machine):
    hotClearRaise(machine)
    var msg = lastErr
    if sink != nil and sink.errBuf.len > 0:
      msg = msg & sink.errBuf
      sink.errBuf = ""
    failWith("the program raised while loading: " & msg)
    park("__sess_live", toJs(false))
    return
  live = true
  park("__sess_live", toJs(true))
  parkModuleFacts()
  succeed()

proc bootImpl() {.nimcall.} =
  ## Start a session and RUN the top level, which is what a script means by
  ## "Run" and what initializes a mod's module-level state.
  startSession(true)

proc loadImpl() {.nimcall.} =
  ## Start a session WITHOUT running the top level. The REPL shape: publish,
  ## then `append` runs the statements from the first one on.
  startSession(false)

proc hasImpl(name: JsValue) {.nimcall.} =
  if not live:
    park("__sess_bool", toJs(false))
  else:
    park("__sess_bool", toJs(hasHot(hot, jsText(name))))

proc parkReturn(v: Value) =
  ## Marshal a callback's return value back out, in the same shape the host
  ## sends values IN. A session that can only produce stdout cannot answer
  ## `fib(30)` from a REPL prompt.
  let obj = newJsObject()
  case v.kind
  of vkInt, vkUInt, vkChar, vkEnum:
    obj.set("k", toJs("i")); obj.set("v", toJs(int(asInt(v))))
  of vkFloat:
    obj.set("k", toJs("f")); obj.set("v", toJs(v.fval))
  of vkBool:
    obj.set("k", toJs("b")); obj.set("v", toJs(v.bval))
  of vkString:
    obj.set("k", toJs("s")); obj.set("v", toJs(v.sval))
  else:
    obj.set("k", toJs("n"))
  park("__sess_ret", obj)

proc clearReturn() =
  ## A call that does not complete must not leave the PREVIOUS call's answer
  ## sitting on `__sess_ret`. Found by the fixture: reading a module-level global
  ## before its initializer has run raises, `callImpl` returned early, and the
  ## caller read a stale value from two calls ago as though it were the answer.
  ## A stale plausible number is worse than no number.
  let obj = newJsObject()
  obj.set("k", toJs("n"))
  park("__sess_ret", obj)

proc callImpl(name: JsValue) {.nimcall.} =
  clearReturn()
  if not live:
    failWith("no session is running")
    return
  succeed()
  hostFailed = false
  let args: seq[Value] = @[]
  let v = callHot(machine, hot, jsText(name), args)
  drain()
  if hostFailed: return
  if raised(): return
  parkReturn(v)

proc swapImpl() {.nimcall.} =
  ## THE VERB THIS FILE EXISTS FOR. Republish `__sess_src` over the live module
  ## and keep every global; `swapHot` initializes only the globals the new
  ## version INTRODUCED, so adding a `var` mid-session works and does not
  ## silently read as a default.
  if not live:
    failWith("no session is running")
    return
  ## `swapHot` refuses — changing nothing — while an interpreted frame is on the
  ## stack, because the previous generation's buffers are freed there. That is a
  ## SCHEDULING rule, not a failure: the caller retries at a frame boundary. Say
  ## so precisely, because a swap that silently never lands is the failure mode a
  ## user hits on their first `while true`.
  if not hotSafe(machine):
    failWith("inside a call — the swap will land at the next frame boundary")
    return
  republish(toStr(global("__sess_src")))
  hostFailed = false
  if not swapHot(machine, hot):
    failWith("the swap was refused: the program is inside a call")
    return
  drain()
  if hostFailed: return
  if raised(): return
  parkModuleFacts()
  succeed()

proc appendImpl(fromStmt: JsValue) {.nimcall.} =
  ## THE REPL SHAPE. `swapHot`'s two modes are both wrong for a prompt:
  ## `runInit = false` never initializes a global the new generation ADDED, and
  ## `runInit = true` re-runs every earlier statement's side effects. Running the
  ## TAIL alone initializes exactly the new declarations and executes exactly the
  ## new statements, while every earlier module-level `var` keeps the value it
  ## already had.
  if not live:
    failWith("no session is running")
    return
  if not hotSafe(machine):
    failWith("inside a call — retry at the next frame boundary")
    return
  republish(toStr(global("__sess_src")))
  hostFailed = false
  var upto = ranTo
  let already = int(toInt(fromStmt))
  if already >= 0: upto = already
  var newTotal = upto
  if not swapHotAppend(machine, hot, upto, newTotal):
    failWith("the append was refused: the program is inside a call")
    return
  ranTo = newTotal
  park("__sess_ranto", toJs(ranTo))
  drain()
  if hostFailed: return
  if raised(): return
  parkModuleFacts()
  succeed()

proc stopImpl() {.nimcall.} =
  ## Drop the session. The interpreter's own memory is not handed back — the
  ## browser build's storage for value aggregates is a bump pointer — so this is
  ## about the SEAM's state, not about reclaiming a heap. A caller that wants the
  ## memory back reloads the page, and the page should say so rather than imply
  ## a free that did not happen.
  live = false
  machine = nil
  sink = nil
  ranTo = 0
  park("__sess_live", toJs(false))
  park("__sess_gen", toJs(0))
  park("__sess_out", toJs(""))
  succeed()

proc jsonStr(s: string): string =
  ## Quote `s` as a JSON string. Values come from `renderValueReadable`, which
  ## can hold quotes, backslashes and control bytes (a `seq[string]` renders
  ## with its own quotes), so every one of those is escaped.
  result = "\""
  for ch in s:
    case ch
    of '"': result.add "\\\""
    of '\\': result.add "\\\\"
    of '\n': result.add "\\n"
    of '\r': result.add "\\r"
    of '\t': result.add "\\t"
    else:
      if ord(ch) < 0x20:
        const hex = "0123456789abcdef"
        result.add "\\u00"
        result.add hex[ord(ch) shr 4]
        result.add hex[ord(ch) and 15]
      else:
        result.add ch
  result.add "\""

proc globalsImpl() {.nimcall.} =
  ## THE STATE A SWAP KEEPS, made visible. A hot swap's whole claim is that the
  ## program's data survives a code change; a page that can only show stdout
  ## asks the user to take that on faith. This reads every module-level variable
  ## of the running program straight out of the interpreter's global frame -
  ## no evaluation, so it is safe between any two verbs and cannot disturb what
  ## it reports.
  if not live:
    park("__sess_globs", toJs("[]"))
    return
  var js = "["
  var first = true
  for g in hotGlobals(machine, hot):
    if not first: js.add ","
    first = false
    js.add "{\"n\":"
    js.add jsonStr(g.name)
    js.add ",\"v\":"
    js.add jsonStr(g.value)
    js.add "}"
  js.add "]"
  park("__sess_globs", toJs(js))

proc register() =
  let g = global("globalThis")
  let b: JsProc0 = bootImpl
  let l: JsProc0 = loadImpl
  let h: JsProc1 = hasImpl
  let c: JsProc1 = callImpl
  let s: JsProc0 = swapImpl
  let a: JsProc1 = appendImpl
  let x: JsProc0 = stopImpl
  let gl: JsProc0 = globalsImpl
  g.set("__sess_boot", toJs(b))
  g.set("__sess_load", toJs(l))
  g.set("__sess_has", toJs(h))
  g.set("__sess_call", toJs(c))
  g.set("__sess_swap", toJs(s))
  g.set("__sess_append", toJs(a))
  g.set("__sess_stop", toJs(x))
  g.set("__sess_globals", toJs(gl))
  g.set("__sess_live", toJs(false))
  g.set("__sess_gen", toJs(0))
  g.set("__sess_ready", toJs(true))

register()
