// boot.js - the browser's RuntimeBootstrap.
//
// Unity's `RuntimeBootstrap` finds the mods on disk, loads one through the
// native interpreter, registers the host callback and then ticks update every
// frame. This does exactly that, with fetch where there was a filesystem and
// requestAnimationFrame where there was Unity's player loop.
//
// Two things it adds over the version in the engine repo's `web/`, because the
// page around it is a demonstration rather than a spike:
//
//   load(id)   load a DIFFERENT mod into the running page. A fresh interpreter,
//              the way switching modpacks is on the desktop.
//   swap(src)  republish new bytes over the LIVE module through `__inf_swap`,
//              which is aowli's `swapHot` with `runInit = false` - the same call
//              `infiniteless_runtime_swap` makes in NativeHost/aowli_host.nim.
//              The code changes and the globals do not.
"use strict";
import { createHost } from "./host.js";

// webvfs frames a sibling module as "<name>\t<len>\n<body>", every byte >= 0x80
// escaped as \xHH, <len> counting the ESCAPED body. Keeping the payload base64
// and framing here means the bytes on the wire are the artifact's own.
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

export async function boot(canvas, ui) {
  const say = (m) => ui.status && ui.status(m);

  say("fetching artifacts");
  const payload = await (await fetch("payload.json")).json();

  const host = createHost(canvas, {
    packs: payload.packs,
    log: (m) => ui.log && ui.log(m),
    onSelect: (pack) => ui.log && ui.log("modpack selected: " + (pack ? pack.id : "?")),
  });
  host.attach(window);
  let offscreen = false;
  for (const ev of ["mousemove", "mousedown", "wheel"]) canvas.addEventListener(ev, () => touch());
  window.addEventListener("keydown", () => touch());
  if (globalThis.IntersectionObserver) {
    new IntersectionObserver((es) => { offscreen = !es[0].isIntersecting; })
      .observe(canvas);
  }
  globalThis.__inf_host = (name, args) => host.dispatch(name, args);

  // aowli's browser build reaches std/os's `fileExists` / `dirExists` /
  // `getLastModificationTime` on a couple of guard paths, and those compile down
  // to a libc `stat` the JS environment has no answer for. In a browser the
  // truthful answer is that the file is not there - every artifact this page
  // loads comes out of aowli's in-memory VFS, not out of a filesystem - so these
  // report failure the way `stat` reports ENOENT. TEMPORARY: it belongs in
  // aowli's own jsenv.js, and this page is where the gap showed up.
  globalThis.stat = globalThis.lstat = globalThis.fstat = () => -1;

  say("loading the interpreter");
  await new Promise((resolve, reject) => {
    const s = document.createElement("script");
    s.src = "aowli-host.js";
    s.onload = resolve;
    s.onerror = () => reject(new Error("aowli-host.js failed to load"));
    document.head.appendChild(s);
  });

  // The bundle's generated entry runs every module's init, which is what
  // registers __inf_boot/__inf_has/__inf_call/__inf_swap on globalThis.
  globalThis.main(0, []);
  if (!globalThis.__inf_ready) throw new Error("the interpreter did not register its seam");

  let running = false, current = null, missing = new Set();

  // THE FRAME STACK. `tools/frame-arena.mjs` exposes a mark and a release over
  // the bundle's bump pointer; taking a mark before a per-frame callback and
  // releasing it after gives `allocFixed` the stack discipline its own comment
  // says it models, and is the whole reason this page no longer has a budget.
  //
  // `framed` is false for `start` and `stop`: whatever a mod sets up in `start`
  // has to outlive the call, and releasing it would hand that memory out again.
  // The release also refuses itself whenever the Nim heap grew above the mark
  // during the call - see the tool.
  const arenaMark = globalThis.__leng_mark, arenaRelease = globalThis.__leng_release;
  const callback = (name, framed) => {
    globalThis.__inf_has(name);
    if (!globalThis.__inf_bool) { missing.add(name); return; }
    const at = framed && arenaMark ? arenaMark() : -1;
    globalThis.__inf_call(name);
    if (globalThis.__inf_err) ui.log && ui.log("[" + name + "] " + globalThis.__inf_err);
    if (at >= 0) arenaRelease(at);
  };

  function load(id) {
    const mod = payload.mods.find((m) => m.id === id);
    if (!mod) throw new Error("no such mod: " + id);
    if (running) callback("stop");
    globalThis.__inf_mods = frame(mod.modules, payload.modules);
    globalThis.__inf_src = atob(mod.src);
    globalThis.__inf_boot();
    if (globalThis.__inf_err) throw new Error(globalThis.__inf_err);
    missing = new Set();
    current = mod;
    running = true;
    animated = mod.animated === true;
    touch();
    callback("start");
    ui.loaded && ui.loaded(mod, globalThis.__inf_bases, globalThis.__inf_gen);
    say(mod.id + " loaded - artifact " + mod.artifact + ", sha256 " + mod.sha256.slice(0, 12));
    return mod;
  }

  // `swap` is aowli's `swapHot` with `runInit = false`: republish new code over
  // the live module and leave the globals alone. It is what the native host does
  // and it is wired up here, but IT DOES NOT WORK IN THIS BROWSER BUILD - the
  // generation counter goes up, no error is raised, and the interpreter keeps
  // executing the previous body. Measured with `tools/_probe`-style hooks on
  // `__inf_host`: after swapping to a build whose only difference is the string
  // it draws, the OLD string is still what arrives at the host. A plain
  // `__inf_boot` of the same bytes draws the new one, so the artifact, the VFS
  // and the payload are all fine and the fault is inside `swapHot`.
  //
  // So the page does not use it. It is kept, unwired, because the day it starts
  // working is a one-line change here.
  function swap(b64src) {
    if (!running) throw new Error("nothing is loaded to swap");
    globalThis.__inf_src = atob(b64src);
    globalThis.__inf_swap();
    if (!globalThis.__inf_ok) throw new Error(globalThis.__inf_err || "the swap was refused");
    touch();
    return globalThis.__inf_gen;
  }

  // What the page uses instead: load a DIFFERENT BUILD of the mod that is
  // already loaded, into a fresh interpreter. The code changes and interpreter
  // globals reset - but `remember`/`save` state does not, because it lives in
  // the host rather than in interpreter memory, which is the half of "reload the
  // code, keep the data" a browser can honestly show.
  function loadBuild(b64src) {
    if (!current) throw new Error("nothing is loaded");
    if (running) callback("stop");
    globalThis.__inf_mods = frame(current.modules, payload.modules);
    globalThis.__inf_src = atob(b64src);
    globalThis.__inf_boot();
    if (globalThis.__inf_err) throw new Error(globalThis.__inf_err);
    running = true;
    animated = current.animated === true;
    touch();
    callback("start");
  }

  function unload() {
    if (!running) return;
    callback("stop");
    animated = false;
    touch();
    running = false;
    current = null;
  }

  // THE TICK USED TO BE THROTTLED TO 10 fps, AND THAT WAS NOT A PERFORMANCE
  // DECISION: `allocFixed` is the codegen's storage for value aggregates and the
  // runtime never rewound it, so a page had a fixed budget of interpreted work
  // - about a gigabyte - and every frame spent some. Going slower freed nothing;
  // it only stretched the time before the ceiling arrived.
  //
  // The frame stack above ended that. Measured on this page, same mod, same four
  // minutes: 627 MB spent before, 7 MB after. So the default is 60 now, and the
  // throttle is a control rather than a rationing scheme.
  //
  // `allocFixed(0)` returns the current bump pointer without allocating
  // anything, which is how `used()` below reads linear memory exactly rather
  // than guessing from `ArrayBuffer.byteLength` (which only doubles).
  let hz = 60, last = 0, paused = false;
  // Two ways to spend a frame. Neither is about memory any more - a frame that
  // would be identical to the last one is simply work nobody asked for.
  //   ANIMATED  the mod's picture changes on its own, so every tick is a frame.
  //   ON DEMAND the mod only redraws when something happened - a key, the
  //             pointer, a click, a load, a swap. The boot shell is a menu: a
  //             frame that would be identical to the last one buys nothing and
  //             costs the same as any other.
  // `host.paint()` replays the LAST recorded frame either way, so a canvas that
  // is not ticking is not a blank canvas.
  let animated = false, dirty = 2, idleAt = 0;
  const IDLE_MS = 20000;
  const touch = () => { dirty = 2; idleAt = performance.now() + IDLE_MS; };
  const CEILING = 1 << 30;
  const used = () => (typeof globalThis.allocFixed === "function" ? globalThis.allocFixed(0) : 0);
  let dead = false;

  function tick(now) {
    requestAnimationFrame(tick);
    if (dead) return;
    if (paused || document.hidden || offscreen) return;
    // An animated mod goes to sleep when nobody has touched the page for a
    // while. The picture stays; an idle tab stops interpreting.
    const asleep = animated && idleAt > 0 && now > idleAt;
    if (asleep && ui.asleep) ui.asleep(true);
    if (!(animated && !asleep) && dirty <= 0) return;
    if (now - last < 1000 / hz) return;
    last = now;
    if (dirty > 0) dirty -= 1;
    try {
      host.beginFrame();
      if (running) { callback("update", true); callback("drawGui", true); }
      host.paint();
      host.endFrame();
    } catch (e) {
      dead = true;
      running = false;
      ui.exhausted && ui.exhausted(String(e.message));
    }
  }
  requestAnimationFrame(tick);

  return {
    payload, host, load, swap, loadBuild, unload, used,
    ceiling: CEILING,
    get dead() { return dead; },
    get hz() { return hz; },
    set hz(v) { hz = v; },
    get paused() { return paused; },
    set paused(v) { paused = v; touch(); },
    get animated() { return animated; },
    get asleep() { return animated && idleAt > 0 && performance.now() > idleAt; },
    wake: touch,
    get running() { return running; },
    get current() { return current; },
    missing: () => [...missing],
    declined: () => Object.fromEntries(host.declined),
    made: () => Object.fromEntries(host.made),
    press: (x, y) => host.press(x, y),
    key: (k) => host.key(k),
  };
}
