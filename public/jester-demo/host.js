// host.js - the browser's answer to the Infiniteless host surface.
//
// This is `Runtime/Native/AowliHostBridge.cs` and `Runtime/Unity/UnityApi.cs`
// rewritten against a 2D canvas, the DOM and the keyboard. It implements the
// calls a browser can serve honestly and DECLINES the rest by name, out loud, so
// a run says what it could not do rather than quietly pretending.
//
// The drawing model is why Canvas 2D and not WebGPU: `ScreenPainter` records a
// frame's worth of filled rectangles, single-line text in a box, and images with
// a source sub-rect, then replays them. `fillRect`, `fillText` and `drawImage`
// are those three primitives in the same coordinate space (y down from the
// top-left), so the port is a transcription rather than a design.
"use strict";

export function createHost(canvas, opts = {}) {
  const ctx = canvas.getContext("2d");
  const packs = opts.packs || [];
  const log = opts.log || (() => {});

  let commands = [];
  let painting = false;

  const held = new Set();
  let pressed = new Set();
  const mouseHeld = new Set();
  let mousePressed = new Set();
  let pointerX = 0, pointerY = 0;
  let pointerShown = true, pointerLocked = false;
  let typed = "";
  let lookX = 0, lookY = 0;

  let playing = "";
  const startTime = performance.now();
  let lastFrame = startTime, delta = 0, frames = 0;
  const declined = new Map();
  const made = new Map();

  // The panel stack, transcribed from UnityApi.Stack.
  const Pad = 16, Gap = 8, TitleBar = 48;
  const heights = new Map();
  let open = null, left = 0, top = 0, span = 0, flow = 0;
  const Accent = "rgba(89,158,242,1)";
  const Ink = "rgba(237,242,250,1)";

  const rgba = (r, g, b, a) =>
    "rgba(" + Math.round(r * 255) + "," + Math.round(g * 255) + "," +
    Math.round(b * 255) + "," + a + ")";

  function fill(x, y, w, h, tint) {
    if (painting) throw new Error("Nothing can be drawn while drawing is replayed.");
    commands.push({ kind: 0, x, y, w, h, tint });
  }
  function write(text, x, y, w, h, size, align, tint) {
    if (!text) return;
    if (painting) throw new Error("Nothing can be drawn while drawing is replayed.");
    commands.push({ kind: 1, x, y, w, h, size: Math.max(1, Math.round(size)), align, text, tint });
  }
  const face = (size) => size + 'px ui-sans-serif, system-ui, "Segoe UI", Arial, sans-serif';
  function measure(text, size) {
    if (!text) return 0;
    ctx.font = face(Math.max(1, Math.round(size)));
    return ctx.measureText(text).width;
  }

  function hot(x, y, w, h) {
    if (!pointerShown) return false;
    return pointerX >= x && pointerX <= x + w && pointerY >= y && pointerY <= y + h;
  }
  function panel(x, y, w, h, backdrop) {
    if (backdrop) {
      fill(x, y, w, h, rgba(0.06, 0.07, 0.09, 0.88));
      const line = rgba(0.30, 0.55, 0.85, 0.55);
      fill(x, y, w, 1, line); fill(x, y + h - 1, w, 1, line);
      fill(x, y, 1, h, line); fill(x + w - 1, y, 1, h, line);
    }
    open = null; left = x + Pad; top = y; span = w - Pad * 2; flow = y + Pad;
  }
  function buttonAt(text, x, y, w, h) {
    const over = hot(x, y, w, h);
    fill(x, y, w, h, over ? rgba(0.22, 0.41, 0.63, 0.97) : rgba(0.14, 0.17, 0.22, 0.92));
    fill(x, y, 3, h, Accent);
    write(text, x + 14, y, w - 22, h, 16, 0, Ink);
    return over && mousePressed.has("left");
  }

  function paint() {
    painting = true;
    ctx.fillStyle = "#0b0d12";
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    for (const c of commands) {
      if (c.kind === 0) { ctx.fillStyle = c.tint; ctx.fillRect(c.x, c.y, c.w, c.h); continue; }
      ctx.fillStyle = c.tint;
      ctx.font = face(c.size);
      ctx.textBaseline = "middle";
      const wide = ctx.measureText(c.text).width;
      let x = c.x;
      if (c.align === 1) x = c.x + (c.w - wide) / 2;
      else if (c.align === 2) x = c.x + c.w - wide;
      ctx.fillText(c.text, x, c.y + c.h / 2);
    }
    painting = false;
  }

  const nil = () => ({ k: "n" });
  const int = (v) => ({ k: "i", v: Number(v) | 0 });
  const num = (v) => ({ k: "f", v: Number(v) });
  const bool = (v) => ({ k: "b", v: !!v });
  const str = (v) => ({ k: "s", v: String(v) });
  // `remember`/`save` are overloaded on the VALUE's type and the host must give
  // back the kind the mod declared, so the shape of the initial argument decides
  // the shape of the answer - the same rule ConvertValue follows in C#.
  const like = (sample, v) =>
    typeof sample === "boolean" ? bool(v) :
    typeof sample === "number" ? (Number.isInteger(sample) ? int(v) : num(v)) : str(v);

  const CALLS = {
    infiniteless_log: (a) => { log(String(a[0])); return nil(); },

    infiniteless_screen_size: (a) => num(a[0] === 0 ? canvas.width : canvas.height),
    infiniteless_delta_time: () => num(delta),
    infiniteless_time: () => num((performance.now() - startTime) / 1000),
    infiniteless_render_frames: () => int(frames),

    infiniteless_key_held: (a) => bool(held.has(a[0])),
    infiniteless_key_pressed: (a) => bool(pressed.has(a[0])),
    infiniteless_mouse_held: (a) => bool(mouseHeld.has(a[0])),
    infiniteless_mouse_pressed: (a) => bool(mousePressed.has(a[0])),
    infiniteless_look_delta: (a) => num(a[0] === 0 ? lookX : lookY),
    infiniteless_typed_text: () => { const t = typed; typed = ""; return str(t); },

    infiniteless_pointer_at: (a) => num(a[0] === 0 ? pointerX : pointerY),
    infiniteless_pointer_show: (a) => {
      pointerShown = !!a[0];
      canvas.style.cursor = pointerShown ? "default" : "none";
      return nil();
    },
    infiniteless_pointer_shown: () => bool(pointerShown),
    infiniteless_pointer_hold: (a) => {
      pointerLocked = !!a[0];
      if (pointerLocked) canvas.requestPointerLock && canvas.requestPointerLock();
      else document.exitPointerLock && document.exitPointerLock();
      return nil();
    },
    infiniteless_pointer_held: () => bool(pointerLocked),

    infiniteless_pack_count: () => int(packs.length),
    infiniteless_pack_name: (a) => str(packs[a[0]] ? packs[a[0]].name : ""),
    infiniteless_pack_playing: () => str(playing),
    infiniteless_pack_select: (a) => {
      const pack = packs[a[0]];
      if (pack) { playing = pack.id; log("modpack selected: " + pack.id); }
      if (opts.onSelect) opts.onSelect(pack);
      return nil();
    },

    infiniteless_draw_fill: (a) => {
      fill(a[0], a[1], a[2], a[3], rgba(a[4], a[5], a[6], a[7]));
      return nil();
    },
    infiniteless_draw_text: (a) => {
      write(a[0], a[1], a[2], a[3], a[4], a[5], align(a[6]), rgba(a[7], a[8], a[9], a[10]));
      return nil();
    },
    infiniteless_draw_measure: (a) => num(measure(a[0], a[1])),

    infiniteless_ui_panel: (a) => (panel(a[0], a[1], a[2], a[3], !!a[4]), nil()),
    infiniteless_ui_begin: (a) => {
      const title = a[0] == null ? "" : a[0], width = a[1];
      const tall = heights.has(title) ? heights.get(title) : 240;
      const x = (canvas.width - width) * 0.5;
      const y = Math.max(46, (canvas.height - tall) * 0.5);
      panel(x, y, width, tall, true);
      open = title;
      fill(x, y, width, TitleBar, rgba(0.12, 0.16, 0.23, 0.96));
      fill(x, y + TitleBar - 1, width, 2, Accent);
      write(title, x + Pad, y, width - Pad * 2, TitleBar, 20, 0, rgba(0.97, 0.98, 1, 1));
      flow = y + TitleBar + Pad;
      return nil();
    },
    infiniteless_ui_label: (a) => {
      write(a[0], left, flow, span, 25, 16, 0, Ink);
      flow += 25;
      return nil();
    },
    infiniteless_ui_space: (a) => (flow += a[0], nil()),
    infiniteless_ui_button: (a) => {
      const y = flow; flow += a[1];
      const clicked = buttonAt(a[0], left, y, span, a[1]);
      flow += Gap;
      return bool(clicked);
    },
    infiniteless_ui_button_at: (a) => bool(buttonAt(a[0], a[1], a[2], a[3], a[4])),
    infiniteless_ui_at: (a) => num(a[0] === 0 ? left : a[0] === 1 ? flow : span),
    infiniteless_ui_move: (a) => (left = a[0], flow = a[1], span = a[2], nil()),
    infiniteless_ui_take: (a) => { const y = flow; flow += a[0]; return num(y); },
    infiniteless_ui_hot: (a) => bool(hot(a[0], a[1], a[2], a[3])),
    infiniteless_ui_end: () => {
      if (open !== null) heights.set(open, flow - top + Pad);
      open = null;
      return nil();
    },

    // localStorage is the browser's own per-origin store and is the honest home
    // for `remember`/`save`. What it is NOT is the player's save folder - see
    // docs/WEB.md on what that costs.
    infiniteless_state_get: (a) => {
      let v = null;
      try { v = localStorage.getItem("inf:" + a[0]); } catch (e) {}
      return v === null ? like(a[1], a[1]) : like(a[1], v);
    },
    infiniteless_state_set: (a) => {
      try { localStorage.setItem("inf:" + a[0], String(a[1])); } catch (e) {}
      return like(a[1], a[1]);
    },
  };

  // The SDK spells alignment as a word; the painter wants 0/1/2.
  function align(v) {
    if (typeof v === "number") return v | 0;
    return v === "centre" || v === "center" ? 1 : v === "right" ? 2 : 0;
  }

  function dispatch(name, args) {
    const fn = CALLS[name];
    if (fn) { made.set(name, (made.get(name) || 0) + 1); return fn(args); }
    declined.set(name, (declined.get(name) || 0) + 1);
    return nil();
  }

  function beginFrame() {
    const now = performance.now();
    delta = (now - lastFrame) / 1000;
    lastFrame = now;
    frames += 1;
    commands = [];
  }
  function endFrame() {
    pressed = new Set();
    mousePressed = new Set();
    lookX = 0; lookY = 0;
  }

  // Unity spells its keys with the `Key` enum ("DownArrow", "PageUp", "A"); a
  // DOM KeyboardEvent spells them "ArrowDown"/"PageUp"/"KeyA". The shell reads
  // DownArrow/UpArrow/PageDown/PageUp/Home/End and every mod reads letters, so
  // this is a rule rather than a table of special cases.
  function unityKey(ev) {
    const c = ev.code;
    if (c.indexOf("Arrow") === 0) return c.slice(5) + "Arrow";
    if (c.indexOf("Key") === 0) return c.slice(3);
    return c;
  }
  const MOUSE = ["left", "right", "middle"];
  const SWALLOW = ["ArrowUp", "ArrowDown", "PageUp", "PageDown", "Home", "End", "Space"];

  function attach(target) {
    target = target || window;
    target.addEventListener("keydown", (ev) => {
      const k = unityKey(ev);
      if (!held.has(k)) pressed.add(k);
      held.add(k);
      if (ev.key.length === 1) typed += ev.key;
      if (SWALLOW.indexOf(ev.code) >= 0) ev.preventDefault();
    });
    target.addEventListener("keyup", (ev) => { held.delete(unityKey(ev)); });
    canvas.addEventListener("mousemove", (ev) => {
      const box = canvas.getBoundingClientRect();
      pointerX = (ev.clientX - box.left) * (canvas.width / box.width);
      pointerY = (ev.clientY - box.top) * (canvas.height / box.height);
      lookX += ev.movementX || 0; lookY += ev.movementY || 0;
    });
    canvas.addEventListener("mousedown", (ev) => {
      const b = MOUSE[ev.button] || String(ev.button);
      if (!mouseHeld.has(b)) mousePressed.add(b);
      mouseHeld.add(b);
    });
    target.addEventListener("mouseup", (ev) => {
      mouseHeld.delete(MOUSE[ev.button] || String(ev.button));
    });
  }

  // Synthetic input, for a headless capture that has no mouse: the same edges a
  // real event would have set, consumed by the same frame.
  function press(x, y) { pointerX = x; pointerY = y; mousePressed.add("left"); }
  function key(name) { pressed.add(name); }

  return {
    dispatch, beginFrame, endFrame, paint, attach, press, key,
    get declined() { return declined; },
    get made() { return made; },
    get playing() { return playing; },
    served: Object.keys(CALLS),
  };
}
