// jester-panel.js — Jester as a panel, next to Output and Symbols.
//
// A script's output is a stream of text, which is what the Output panel is. A
// mod's output is a SURFACE PLUS A CLOCK: a canvas, and a per-frame callback
// something outside has to drive. That is the entire difference, and it is all
// this file adds — the session, the swapping, the editor and the compiler are
// the playground's and are untouched.
//
// WHAT THIS PANEL OWES THE USER, in the order they meet it:
//
//   1. It boots into THE SHELL, which is the mod the desktop player starts in —
//      a real launcher that groups, pages, hit-tests and plays a modpack. The
//      browser demo has always drawn it and never let it launch anything:
//      `jester_pack_select` wrote a line to a log and stopped. Here selecting a
//      pack loads that pack's mods into the same session, which is what the
//      desktop does.
//   2. THERE IS ALWAYS A WAY BACK. Esc, and a Shell button that appears the
//      moment something is playing. Note these are TWO different "backs" and are
//      deliberately not merged: going back to the shell is a GAME action (the
//      shell's own `handBack()`), while stopping the session is a TOOL action.
//      One button that sometimes quits a game and sometimes kills an interpreter
//      would be a bad button.
//   3. YOU CAN RUN THE FILE YOU ARE EDITING. `Run my mod` compiles the active
//      buffer through the same pipeline the Run button uses and boots it as the
//      mod. With Live armed, editing it then hot-swaps into the running game —
//      which is the headline claim of the whole project, on a web page, on the
//      same artifacts the desktop player loads.
"use strict";
(function () {
  const $ = (s) => document.querySelector(s);
  let booted = false, payload = null, shellId = null;
  let packs = [];                 // what the shell lists, and what each one plays
  let playing = null;             // the pack currently loaded, or null for the shell
  let canvasSent = false;
  // Mods installed before the panel was ever opened (the store restores what a
  // previous visit kept as soon as the page loads, which is usually earlier).
  let preinstalled = [];

  const el = {};
  function grab() {
    el.canvas = $("#jxCanvas"); el.idle = $("#jxIdle"); el.log = $("#jxLog");
    el.back = $("#jxBack"); el.where = $("#jxWhere"); el.gen = $("#jxGen");
    el.stop = $("#jxStop"); el.start = $("#jxStart"); el.mine = $("#jxRunMine");
    el.status = $("#jxStatus"); el.hint = $("#jxHint");
    el.clone = $("#jxClone");
  }

  // IS THE FILE ON SCREEN A JESTER MOD? A mod reaches the engine through the
  // SDK and every one of them opens by importing it, so the absence of that
  // import is a definite answer and a cheap one. ONE function, used by both the
  // button's state and the boot path, so the two can never disagree about it.
  const MOD_IMPORT = /^\s*import\s+[^\n]*\bjester\b/m;
  const isModSource = (src) => MOD_IMPORT.test(String(src || ""));

  const NOT_A_MOD =
    "This project is not a Jester application — it does not `import jester`, so " +
    "there is nothing here for the engine to call. Press “Clone its source” " +
    "for a real mod to start from.";
  const RUN_MINE_TIP = "Run the file you are editing as a mod, instead of the shell";

  // SAY IT BEFORE THE CLICK, NOT AFTER IT. This used to be a live button that
  // compiled your hello-world, loaded it, found no callbacks and sat there
  // showing nothing — which reads as the panel being broken rather than as the
  // file not being a mod. Refusing up front, with the reason in the tooltip, is
  // the same answer delivered where it is useful.
  //
  // It carries `off` and `aria-disabled` rather than the `disabled` attribute on
  // purpose: a disabled <button> fires no mouse events in any browser, so the
  // tooltip that explains the refusal would never appear.
  function refreshMine() {
    if (!el.mine) return;
    let src = "";
    try { src = (window.AowliEditor && window.AowliEditor.getValue()) || ""; } catch (_) {}
    const ok = isModSource(src);
    el.mine.classList.toggle("off", !ok);
    el.mine.setAttribute("aria-disabled", String(!ok));
    el.mine.setAttribute("data-tip", ok ? RUN_MINE_TIP : NOT_A_MOD);
  }

  function say(msg, cls) {
    if (!el.log) return;
    const line = document.createElement("div");
    if (cls) line.className = cls;
    line.textContent = msg;
    el.log.appendChild(line);
    while (el.log.childNodes.length > 200) el.log.removeChild(el.log.firstChild);
    el.log.scrollTop = el.log.scrollHeight;
  }
  const status = (m) => { if (el.status) el.status.textContent = m || ""; };

  // ---- where the big demo assets come from ----------------------------------
  // On the published site the payload and the SDK are NOT static files sitting
  // next to this script — copying the folder would otherwise be "Jester, free".
  // They are served by the licence Worker, which hands them only to a page
  // loaded from one of our own origins and only under a short-lived ticket. On a
  // loopback dev server they are read straight off disk, so `vitepress dev`
  // needs no Worker in the loop. This is a bar against rehosting, not a wall:
  // anything a browser can load, a scripted browser can too.
  const DEMO_API = (() => {
    try {
      return /(^|\.)aoughwl\.com$/.test(self.location.hostname)
        ? "/api/v1" : "https://aoughwl.com/api/v1";
    } catch (_) { return "https://aoughwl.com/api/v1"; }
  })();
  const DEMO_IS_LOOPBACK = (() => {
    try { return /^(localhost|127\.0\.0\.1|\[::1\])$/.test(self.location.hostname); }
    catch (_) { return false; }
  })();

  async function fetchDemoAsset(kind, localPath) {
    if (DEMO_IS_LOOPBACK) {
      // Dev: the files still live beside the playground (gitignored), so the
      // edit→reload loop has no network hop.
      try { const r = await fetch(localPath); if (r.ok) return r; } catch (_) {}
    }
    const tk = await fetch(DEMO_API + "/demo/ticket", { credentials: "omit" });
    if (!tk.ok) throw new Error("demo/ticket HTTP " + tk.status);
    const { ticket } = await tk.json();
    const r = await fetch(DEMO_API + "/demo/asset/" + kind + "?t=" + encodeURIComponent(ticket),
                          { credentials: "omit" });
    if (!r.ok) throw new Error("demo/asset/" + kind + " HTTP " + r.status);
    return r;
  }

  // ---- the payload ----------------------------------------------------------
  // Byte-exact `.s.nif` artifacts, the same ones the Unity player loads. A
  // browser has no StreamingAssets, so what the desktop host discovers by
  // walking a folder is discovered here by reading this file.
  async function ensurePayload() {
    if (payload) return payload;
    status("fetching the mods…");
    const r = await fetchDemoAsset("payload", "jester-payload.json");
    payload = await r.json();
    // THE MODPACK LIST IS DERIVED FROM WHAT IS ACTUALLY LOADABLE, never from the
    // 35 names the desktop repository happens to ship. A launcher that lists
    // packs it cannot play is the same defect as a demo that draws a menu it
    // cannot launch — one layer up. Every row here plays.
    shellId = (payload.mods.find((m) => /shell/.test(m.id)) || payload.mods[0]).id;
    packs = payload.mods.filter((m) => m.id !== shellId)
      .map((m) => ({ id: m.id, name: m.name, mod: m.id }));
    // Anything the store restored before the panel was opened joins the list now.
    for (const mod of preinstalled.splice(0)) window.JesterPanel.register(mod);
    return payload;
  }

  const modById = (id) => payload.mods.find((m) => m.id === id);

  // webvfs frames a sibling module as "<name>\t<len>\n<body>", every byte >= 0x80
  // escaped as \xHH, <len> counting the ESCAPED body. Keeping the payload base64
  // and framing here means the bytes that reach the interpreter are the
  // artifact's own.
  function frame(names, pool) {
    let out = "";
    for (const name of [...names].sort()) {
      const raw = atob(pool[name]);
      let body = "";
      for (let i = 0; i < raw.length; i++) {
        const c = raw.charCodeAt(i);
        body += c >= 0x80 ? "\\x" + c.toString(16).padStart(2, "0") : raw[i];
      }
      out += name + "\t" + body.length + "\n" + body;
    }
    return out;
  }

  // ---- input ----------------------------------------------------------------
  // The worker owns the interpreter and the canvas; the main thread owns the
  // DOM. So the DOM half happens here — mapping a pointer into canvas space and
  // naming a key the way Unity's `Key` enum does — and the result is posted.
  function unityKey(ev) {
    const c = ev.code || "";
    if (c.indexOf("Arrow") === 0) return c.slice(5) + "Arrow";
    if (c.indexOf("Key") === 0) return c.slice(3);
    return c;
  }
  const MOUSE = ["left", "right", "middle"];
  const SWALLOW = ["ArrowUp", "ArrowDown", "ArrowLeft", "ArrowRight", "PageUp", "PageDown", "Home", "End", "Space"];

  // The WINDOW-level listeners are registered once for the life of the page;
  // the CANVAS-level ones are re-registered every time the element is replaced
  // (see `recycleWorker`). Keeping that distinction is not tidiness: without it
  // a recycle stacks another Escape handler and another mouseup on the window,
  // and after three mod switches one keypress goes back to the shell three
  // times.
  let globalInputWired = false;

  function wireInput() {
    const S = window.AowliSession, c = el.canvas;
    c.addEventListener("mousedown", (ev) => {
      c.focus();
      S.input({ kind: "down", button: MOUSE[ev.button] || String(ev.button) });
    });
    c.addEventListener("mousemove", (ev) => {
      const box = c.getBoundingClientRect();
      S.input({
        kind: "move",
        x: (ev.clientX - box.left) * (c.width / box.width),
        y: (ev.clientY - box.top) * (c.height / box.height),
        dx: ev.movementX || 0, dy: ev.movementY || 0,
      });
    });
    // Keys go only to a FOCUSED canvas. The page is an editor: swallowing the
    // arrow keys globally would break typing everywhere else.
    c.addEventListener("keydown", (ev) => {
      S.input({ kind: "keydown", key: unityKey(ev), text: ev.key.length === 1 ? ev.key : "" });
      if (SWALLOW.indexOf(ev.code) >= 0) ev.preventDefault();
    });
    c.addEventListener("keyup", (ev) => S.input({ kind: "keyup", key: unityKey(ev) }));
    // Scrolling the launcher's list is the wheel's job; the page must not also
    // scroll behind it, so the event is claimed.
    c.addEventListener("wheel", (ev) => { ev.preventDefault(); S.input({ kind: "wheel", dy: ev.deltaY }); }, { passive: false });

    if (globalInputWired) return;
    globalInputWired = true;
    window.addEventListener("mouseup", (ev) =>
      S.input({ kind: "up", button: MOUSE[ev.button] || String(ev.button) }));

    // ESCAPE IS LISTENED FOR ON THE WINDOW, not on the canvas.
    //
    // "There is always a way back" cannot depend on the canvas holding focus,
    // and it will not: clicking the log, a toolbar button, or anything the mod
    // itself does with the pointer can move focus, and then the one key that
    // gets a player out of a mod goes to whatever has it instead. Measured — the
    // gate pressed Escape while something was playing and nothing happened.
    //
    // It is scoped rather than global: it acts only while the Jester panel is
    // the visible tab AND something is actually playing, so Escape keeps its
    // ordinary meaning everywhere else on a page that is mostly an editor.
    // AND IT MUST STOP THERE. The page already binds Escape, in the capture
    // phase, to HIDE THE OUTPUT PANE — the pane this panel lives in. Both
    // handlers ran: Escape went back to the shell and then hid the panel it had
    // just gone back to, which is how a passing gate still produced a screenshot
    // with no Jester panel in it.
    //
    // This listener is on `window`, so its capture turn comes first; claiming
    // the event with `stopImmediatePropagation` is what makes "back to the
    // shell" and "hide the output" one key with two meanings instead of two
    // meanings fighting. Escape keeps hiding the pane whenever nothing is
    // playing, which is every other moment on this page.
    window.addEventListener("keydown", (ev) => {
      if (ev.key !== "Escape" || !playing) return;
      const view = document.querySelector("#viewJester");
      if (!view || !view.classList.contains("active")) return;
      ev.preventDefault();
      ev.stopPropagation();
      ev.stopImmediatePropagation();
      backToShell();
    }, true);
  }

  // ---- loading a mod into the live session ----------------------------------
  // RECYCLE THE WORKER WHEN THE HEAP IS CROWDED.
  //
  // aowli never frees a retired interpreter, so every mod loaded costs the
  // worker's 1 GiB permanently — measured, the fifth mod in a session dies with
  // "out of linear memory". Terminating the worker hands the whole gigabyte
  // back, and the bundle is in the HTTP cache, so the price is a pause rather
  // than a reload.
  //
  // The canvas has to be replaced along with it: `transferControlToOffscreen`
  // may be called only once per element and the old worker still owns the old
  // one. So a fresh element takes its place, keeping the id, the size and the
  // listeners — which is also why `wireInput` is idempotent by construction
  // (it only ever binds to `el.canvas`).
  async function recycleWorker() {
    const S = window.AowliSession;
    const old = el.canvas;
    const fresh = document.createElement("canvas");
    fresh.id = old.id;
    fresh.width = old.width;
    fresh.height = old.height;
    fresh.tabIndex = old.tabIndex;
    fresh.className = old.className;
    old.parentNode.replaceChild(fresh, old);
    el.canvas = fresh;

    await S.recycle();
    const off = fresh.transferControlToOffscreen();
    await S.attach(off, packs, storeEntries(), payload.sdk);
    wireInput();
    say("the interpreter's heap was filling up, so this session got a fresh one — " +
        "aowli does not free a retired interpreter yet.", "warn");
  }

  function storeEntries() {
    const out = [];
    try {
      for (let i = 0; i < localStorage.length; i++) {
        const k = localStorage.key(i);
        if (k && k.indexOf("jester:") === 0) out.push([k.slice(7), localStorage.getItem(k)]);
      }
    } catch (_) {}
    return out;
  }

  async function loadMod(id, opts = {}) {
    const S = window.AowliSession;
    const mod = modById(id);
    if (!mod) throw new Error("no such mod: " + id);
    if (canvasSent && S.crowded) await recycleWorker();
    // `stop` is a mod's own chance to put back what it changed. Giving it that
    // chance is the difference between switching mods and leaking whatever the
    // previous one was holding open.
    if (S.running && await S.has("stop")) await S.call("stop");
    const r = await S.start(atob(mod.src), {
      mods: frame(mod.modules, payload.modules),
      // RUN THE TOP LEVEL. This said `runInit: false` on the reasoning that a mod
      // has no `main` — it has start/update/drawGui — and that was wrong in a way
      // that produced spectacular nonsense.
      //
      // A module's top level is not just `main`; it is every module-level
      // INITIALIZER. The shell declares `pendingDelete = -1` and `launching = -1`
      // there, and skipping the top level leaves both at their zero. `0 >= 0`, so
      // the launcher came up already showing `Delete "Hello"?` for pack 0 and
      // immediately launched pack 0, with nobody having touched anything —
      // measured: no keys polled, no mouse presses, and both of those on screen
      // at once.
      //
      // The desktop host has always been right here: `loadHot(machine, p)` takes
      // the default `runInit = true`. This now matches it. The top level runs,
      // THEN `start()` is called — which is the mod lifecycle, in order.
      runInit: true,
      mode: "jester",
      // A BUILT ARTIFACT, not the buffer. See `fromBuffer` in session.js: Live
      // must not republish whatever file happens to be open over a mod the
      // editor never compiled. `Run my mod` is what hands the session over.
      fromBuffer: false,
    });
    if (!r.ok) throw new Error(r.err || "the mod did not load");
    S.setAnimated(mod.animated === true);
    if (await S.has("start")) await S.call("start");
    // TELL THE NEW MOD WHERE THE POINTER IS.
    //
    // `jester.app` ends `openApp` with `idleWhenQuiet()`: an application draws
    // when something HAPPENS and otherwise does not. On the desktop something
    // always has — there is a real pointer at a real position before the mod
    // even starts. A canvas that has never seen a `mousemove` gives the mod
    // nothing to react to, so it correctly draws nothing, and a visitor who
    // just launched a game sees an empty rectangle until they happen to move
    // the mouse over it.
    //
    // One synthetic move at the centre is not a lie: there IS a pointer, and
    // this is where it is until it moves.
    S.input({ kind: "move", x: el.canvas.width / 2, y: el.canvas.height / 2, dx: 0, dy: 0 });
    playing = opts.playing || null;
    render();
    say((opts.label || mod.name) + " — artifact " + mod.artifact +
        ", sha256 " + String(mod.sha256 || "").slice(0, 12));
    return mod;
  }

  async function backToShell() {
    if (!booted || !playing) return;
    status("");
    try {
      // CLEAR "PLAYING" BEFORE THE SHELL STARTS, NOT AFTER.
      //
      // The shell's `start()` opens with:
      //
      //     if playingModpack().len > 0: return
      //     tookWindow = true
      //
      // …because every modpack names the shell as ITS shell, so `start()` runs
      // again for each project launched from here, and the launcher must not
      // seize the window back from the game it just started. A generation that
      // loses that race stops asking for good: `update` and `drawGui` both
      // return on `tookWindow` alone.
      //
      // So coming back while the host still reports the old pack as playing
      // gives a shell that loads cleanly, reports itself live, and draws
      // NOTHING — which is exactly what "the Shell button clears the screen and
      // nothing happens" is. The order matters and it is the whole fix;
      // postMessage is FIFO, so posting this first is enough to land it before
      // `start` runs.
      window.AowliSession.setPlaying("");
      await loadMod(shellId, { label: "the shell" });
    } catch (e) { say(String(e.message || e), "bad"); }
  }

  function render() {
    if (!el.where) return;
    const S = window.AowliSession;
    const on = S.running;
    el.idle.hidden = on;
    el.back.hidden = !playing;
    el.stop.hidden = !on;
    el.where.textContent = !on ? "not running"
      : playing ? ("playing " + playing) : "shell";
    el.gen.textContent = on ? ("v" + (S.gen + 1) + (S.liveMode ? " · live" : "")) : "";
  }

  // ---- boot -----------------------------------------------------------------
  async function boot(what) {
    const S = window.AowliSession;
    try {
      el.start.disabled = el.mine.disabled = true;
      await S.whenReady();
      await ensurePayload();

      if (!canvasSent) {
        // One canvas, transferred once. After this the main thread cannot draw
        // to it at all — which is the point: `update` -> a host call -> a filled
        // rectangle all happen on the worker with no message in between. A mod
        // makes hundreds of host calls a frame, and marshalling those per call
        // is the one design that certainly does not work.
        if (!el.canvas.transferControlToOffscreen)
          throw new Error("this browser has no OffscreenCanvas, which the Jester panel needs");
        const off = el.canvas.transferControlToOffscreen();
        await S.attach(off, packs, storeEntries(), payload.sdk);
        canvasSent = true;
        wireInput();
      } else {
        S.setPacks && S.setPacks(packs);
      }

      booted = true;
      if (what === "mine") await bootActiveBuffer();
      else { await loadMod(shellId, { label: "the shell" }); status(""); }
      el.canvas.focus();
    } catch (e) {
      status(String(e && e.message || e));
      say(String(e && e.message || e), "bad");
    } finally {
      el.start.disabled = el.mine.disabled = false;
      render();
    }
  }

  // ---- clone a mod's source into the explorer -------------------------------
  // The artifact proves the page runs the real thing; the SOURCE is what makes
  // this a demo of a moddable engine rather than a video of one. Cloning drops
  // the mod's actual files into the workspace, where they open in the editor
  // like any other project — and from there `Run my mod` plus Live is the whole
  // loop: read the launcher, change it, watch the change land.
  // ---- the SDK, mounted so a cloned mod can be READ ------------------------
  //
  // `import jester` names a module that lives in the engine, not in the mod, so
  // a cloned mod used to land in the explorer with every single import
  // underlined undeclared. The artifact carries the SDK compiled in, so the mod
  // RAN perfectly well — it just could not be read or changed, which is a
  // strange state for a demo whose claim is that you can do both.
  //
  // The SDK's source ships beside the payload (see `packSdkSource` in
  // tools/pack-jester-payload.mjs) and is mounted here, once, as a read-only
  // project. The playground's own multi-module semcheck then resolves a bare
  // `import draw` against it by basename — the same way the desktop toolchain
  // resolves it — so nothing had to be taught a new rule.
  //
  // Read-only because it is not yours: changing the SDK changes its stamp, and
  // the player refuses every mod built against a stamp that is not the boot
  // shell's. Editing it here would type-check and then mean nothing.
  let sdkMounted = null;
  function mountSdk() {
    if (sdkMounted) return sdkMounted;
    sdkMounted = fetchDemoAsset("sdk", "assets/jester-sdk.json")
      .then((r) => r.json())
      .then((j) => {
        const ws = window.AowliWorkspace;
        if (!ws || !ws.addProject) return null;
        const already = ws.projectByName && ws.projectByName("jester-sdk");
        if (already) return already;
        const proj = ws.addProject({
          name: "jester-sdk",
          // NOT `kind: "std"`. The multi-module builder skips std projects on
          // purpose (the stdlib is served from a pre-checked closure and must
          // never be parsed per keystroke), and a skipped SDK is an SDK whose
          // symbols do not resolve — which is the bug this exists to fix.
          kind: "sdk",
          readonly: true,
          open: true,
          files: j.files,
        });
        say("mounted the Jester SDK (" + Object.keys(j.files).length +
            " modules) read-only, so a cloned mod's imports point at real source " +
            "you can open and read.");
        // SAY WHAT DOES NOT WORK YET, HERE, RATHER THAN LETTING IT BE DISCOVERED
        // AS A CONFUSING SENTENCE LATER. The playground's multi-module checker
        // cannot finish a workspace this size — the SDK closure alone is ten
        // modules and several hundred KB of `.p.nif` — and when it gives up, the
        // page falls back to a single-module check whose message is
        // "the checker couldn't process this program", which reads as a mistake
        // in YOUR file. It is not. Measured outside the browser too, and against
        // an unpatched bundle, so it is the checker and not this page.
        //
        // The mod still RUNS: `Run my mod` compiles the active buffer, and a
        // single-file mod checks fine. What is not reliable yet is type
        // diagnostics for a mod that imports several SDK modules.
        say("note: type-checking a mod against the whole SDK is more than the " +
            "browser's multi-module checker can finish yet — if it says it " +
            "“couldn’t process this program”, that is its limit and not your file.",
            "warn");
        return proj;
      })
      .catch((e) => { sdkMounted = null; say("could not mount the SDK: " + (e.message || e), "warn"); return null; });
    return sdkMounted;
  }

  async function cloneSource(id) {
    await ensurePayload();
    const mod = modById(id) || modById(shellId);
    if (!mod) throw new Error("nothing to clone");
    if (!mod.source || !Object.keys(mod.source).length)
      throw new Error(mod.name + " did not ship its source");
    const ws = window.AowliWorkspace;
    if (!ws || !ws.addProject) throw new Error("the explorer is not available");
    // Before the mod, so its imports resolve the first time it is checked rather
    // than after a second keystroke.
    await mountSdk();
    const proj = ws.addProject({
      name: mod.id,
      kind: "mod",
      files: mod.source,
    });
    const entry = mod.source["main.nim"] ? "main.nim" : Object.keys(mod.source)[0];
    ws.openFile(proj.id, entry, true);
    say("cloned " + mod.id + " into the explorer — " +
        Object.keys(mod.source).join(", ") + ". Press Run my mod to hand the " +
        "session over to your copy; after that every clean type-check swaps " +
        "straight into it.");
    return proj;
  }

  // Compile the buffer the user is editing and boot IT as the mod. This is the
  // path that makes the panel more than a viewer: with Live armed, every clean
  // type-check from here on republishes itself into the running game.
  async function bootActiveBuffer() {
    const S = window.AowliSession;
    status("type-checking your mod…");
    const src = window.AowliEditor.getValue();
    // SAY WHAT IS WRONG BEFORE COMPILING IT.
    //
    // Pressing "Run my mod" on the playground's default hello-world used to
    // compile it, load it, find no callbacks and sit there showing nothing —
    // which reads as the panel being broken rather than as the file not being a
    // mod. A mod reaches the engine through the SDK, and every one of them opens
    // by importing it, so the absence of that import is a definite answer and a
    // cheap one.
    if (!isModSource(src)) throw new Error(NOT_A_MOD);
    const { nif } = window.AowliParser.parseFull(src, "in.nim");
    const { snif, diags } = await window.AowliSem.compile(nif, undefined, src);
    if (!snif) {
      const n = (diags || []).length;
      throw new Error(n ? (n + " error" + (n === 1 ? "" : "s") + " — fix them and press Run my mod again")
                        : "this file did not type-check");
    }
    if (S.running && await S.has("stop")) await S.call("stop");
    // Same rule as `loadMod`: the top level carries the mod's initializers.
    const r = await S.start(snif, { runInit: true, mode: "jester", fromBuffer: true });
    if (!r.ok) throw new Error(r.err || "the mod did not load");
    S.setAnimated(true);
    if (await S.has("start")) await S.call("start");
    playing = null;
    status("");
    say("your buffer is the mod now — published [" + (r.bases || "") + "]");
    if (!S.liveMode) say("tip: turn on \"Apply edits as you type\" in the debugger's Live tab and your edits swap straight into it.", "warn");
  }

  // ---- wiring ---------------------------------------------------------------
  function init() {
    grab();
    if (!el.canvas) return;
    const S = window.AowliSession;
    if (!S) return;

    el.clone.addEventListener("click", async () => {
      el.clone.disabled = true;
      // Clone whatever is on screen: the mod being played, or the launcher.
      const want = playing || shellId;
      try { await cloneSource(want); status(""); }
      catch (e) { status(String(e.message || e)); say(String(e.message || e), "bad"); }
      el.clone.disabled = false;
    });
    el.start.addEventListener("click", () => boot("shell"));
    el.mine.addEventListener("click", () => {
      if (el.mine.classList.contains("off")) return;
      boot("mine");
    });
    // Keep it honest as the buffer changes and as the explorer switches files.
    if (window.AowliEditor && window.AowliEditor.onChange) window.AowliEditor.onChange(refreshMine);
    if (window.AowliWorkspace && window.AowliWorkspace.onActiveFileChange)
      window.AowliWorkspace.onActiveFileChange(refreshMine);
    refreshMine();
    el.back.addEventListener("click", backToShell);
    el.stop.addEventListener("click", async () => {
      if (S.running && await S.has("stop")) await S.call("stop");
      await S.stop();
      playing = null;
      render();
      say("session stopped — the host is still here, drawing nothing.");
    });

    S.on("state", render);
    S.on("log", (e) => say(e.text, e.bad ? "bad" : e.warn ? "warn" : ""));

    // THE SHELL FINISHED AN INSTALL. Everything up to this point happened
    // inside the mod: it listed a registry, fetched a manifest, asked the host
    // which files it still needed, fetched those over HTTP and handed each one
    // back to be hashed. All the page does now is put the result in the
    // launcher's list, which is what the engine's discovery poll does on the
    // desktop when a commit swaps a folder into place.
    S.on("installed", (m) => {
      for (const mod of m.mods) window.JesterPanel.register(mod);
      say("installed content set " + m.version + ": " +
          m.mods.map((x) => x.id).join(", ") + " — they are in the shell's list now.");
    });

    // THE LAUNCH. The shell picked a modpack; load what that pack plays. This is
    // the call the browser demo never wired, and the reason its menu was a
    // picture of a launcher rather than one.
    S.on("play", async (pack) => {
      const target = packs.find((p) => p.id === pack.id) || pack;
      say("modpack selected: " + pack.id);
      try {
        await loadMod(target.mod || target.id, { playing: pack.id, label: pack.name });
        status("");
      } catch (e) { say("could not play " + pack.id + ": " + (e.message || e), "bad"); }
    });

    render();
  }

  window.JesterPanel = {
    shown() { if (!el.canvas) init(); refreshMine(); render(); },
    boot,
    cloneSource,
    // Exposed so the mod registry (jester-store.js) can add an installed mod to
    // what the shell lists without this file knowing where mods come from.
    // An installed mod joins the payload's pool and the launcher's list, so the
    // shell lists it exactly as it lists a built-in one — there is no second
    // class of mod here. Called both by a fresh install and, on load, for
    // everything installed in an earlier visit.
    //
    // It works before the payload has been fetched too: the panel may never have
    // been opened. Those are held and merged when `ensurePayload` runs.
    register(mod) {
      if (!payload) { preinstalled.push(mod); return true; }
      if (!payload.mods.some((m) => m.id === mod.id)) payload.mods.push(mod);
      Object.assign(payload.modules, mod.pool || {});
      if (!packs.some((p) => p.id === mod.id))
        packs.push({ id: mod.id, name: mod.name || mod.id, mod: mod.id });
      if (window.AowliSession.setPacks) window.AowliSession.setPacks(packs);
      return true;
    },
    unregister(id) {
      preinstalled = preinstalled.filter((m) => m.id !== id);
      if (payload) payload.mods = payload.mods.filter((m) => m.id !== id);
      packs = packs.filter((p) => p.id !== id);
      if (window.AowliSession.setPacks) window.AowliSession.setPacks(packs);
      return true;
    },
    get packs() { return packs; },
    // Play a pack by id, without going through the shell's own menu. The store
    // uses it so a mod you just installed can be started from the list you
    // installed it in, and the gate uses it to prove a fetched mod runs.
    async play(id) {
      const target = packs.find((p) => p.id === id);
      if (!target) throw new Error("nothing installed under " + id);
      await loadMod(target.mod || target.id, { playing: target.id, label: target.name });
      window.AowliSession.setPlaying(target.id);
      return true;
    },
  };

  if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", init);
  else init();
})();
