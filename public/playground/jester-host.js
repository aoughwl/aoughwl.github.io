// jester-host.js — the Jester host surface, inside a worker, on an OffscreenCanvas.
//
// This is `Runtime/Native/AowliHostBridge.cs` + `Runtime/Unity/UnityApi.cs`
// rewritten against a 2D canvas, transcribed from `jester/web/host.js` with
// three changes that a worker forces and one that the playground wanted:
//
//   * THE CANVAS IS OFFSCREEN. There is no `getBoundingClientRect`, no
//     `style.cursor` and no pointer lock here, so the main thread does the DOM
//     half: it maps a pointer event into canvas space and names a key the way
//     Unity's `Key` enum does, then posts the result. Everything downstream of
//     that is unchanged.
//   * THERE IS NO `localStorage` IN A WORKER. `remember`/`save` therefore read
//     and write an in-memory map that the main thread seeds at attach and
//     persists on change. The mod cannot tell the difference; the page can, and
//     says so.
//   * SELECTING A MODPACK IS A REAL EVENT. `jester_pack_select` in the demo
//     wrote a line to a log and stopped — the shell is a complete launcher whose
//     launch was never wired. Here it is announced to the main thread, which
//     loads that pack's mods into this same session. That is the difference
//     between a menu you can admire and one you can use.
//
// The drawing model is why Canvas 2D and not WebGPU: `ScreenPainter` records a
// frame's worth of filled rectangles, single-line text in a box, and images with
// a source sub-rect, then replays them. `fillRect`, `fillText` and `drawImage`
// are those three primitives in the same coordinate space, so the port is a
// transcription rather than a design.
"use strict";

self.JesterHost = {
  create(canvas, opts = {}) {
    const ctx = canvas.getContext("2d");
    const log = opts.log || (() => {});
    let packs = opts.packs || [];

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
    // One frame's worth of wheel. Consumed by `endFrame` exactly like `pressed`,
    // because a wheel turn is an edge and not a state.
    let wheelDelta = 0;

    let playing = "";
    const startTime = performance.now();
    let lastFrame = startTime, delta = 0, frames = 0;
    const declined = new Map();
    const made = new Map();
    const keysAsked = new Map();
    const keysHit = new Map();
    const mouseAsked = new Map();
    const mouseHit = new Map();
    const packNameArgs = new Set();
    const store = new Map(opts.store || []);
    // In-flight and completed HTTP requests, keyed by the id `prepare` handed the
    // mod. Released explicitly by the mod, exactly as the SDK's contract says.
    const http = new Map();
    let httpSeq = 0, httpProblem = "";

    // ON-DEMAND vs ANIMATED. A menu redraws only when something happened; a game
    // redraws every tick. `dirty` is a small countdown rather than a flag
    // because a single event usually needs two frames to settle (the frame that
    // observes the press, and the frame that shows what it did).
    let dirty = 2;
    const touch = () => { dirty = 2; };

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
    function write(text, x, y, w, h, size, align, tint, slot) {
      if (!text) return;
      if (painting) throw new Error("Nothing can be drawn while drawing is replayed.");
      commands.push({ kind: 1, x, y, w, h, size: Math.max(1, Math.round(size)),
                      align, text, tint, slot: slot | 0 });
    }
    // ── FONT SLOTS ───────────────────────────────────────────────────────────
    //
    // Drawing picks a face by INTEGER SLOT, not by name: `FontBody = 0` is body
    // copy ("Segoe UI") and `FontHeader = 1` is headings ("Segoe UI Semibold"),
    // with a third named installation-wide by `fonts.txt`. Both
    // `jester_draw_text` and `jester_draw_measure` carry that slot — text as its
    // twelfth argument, measure as its third.
    //
    // This host ignored BOTH, so every heading rendered in the body face and the
    // measurement agreed with the wrong one. That is the same defect the Unity
    // side just fixed: the line breaker and the painter have to agree about
    // weight, or bold text is laid out at one width and drawn at another.
    //
    // A browser has no `fonts.txt`, so the slots map onto CSS weights of one
    // stack — which is what "Segoe UI" vs "Segoe UI Semibold" IS.
    const STACK = 'ui-sans-serif, system-ui, "Segoe UI", Arial, sans-serif';
    const faces = [
      { weight: 400, family: STACK },   // 0 FontBody
      { weight: 600, family: STACK },   // 1 FontHeader
      { weight: 900, family: STACK },   // 2 the third face fonts.txt names
    ];
    const face = (size, slot) => {
      const f = faces[slot | 0] || faces[0];
      return f.weight + " " + Math.max(1, Math.round(size)) + "px " + f.family;
    };
    function measure(text, size, slot) {
      if (!text) return 0;
      ctx.font = face(size, slot);
      return ctx.measureText(text).width;
    }

    // Is this family actually available to render with? Measure a probe string
    // against two different fallbacks; a family that resolves changes BOTH
    // widths, while a name the machine does not have leaves each fallback
    // measuring itself. Two fallbacks rather than one because a family that
    // happens to match the metrics of one of them would otherwise read absent.
    function familyAvailable(name) {
      const probe = "MMMWWWiiilll0123gjpqy";
      const at = 72;
      const clean = String(name).replace(/["\\]/g, "");
      for (const fallback of ["monospace", "serif"]) {
        ctx.font = at + "px " + fallback;
        const base = ctx.measureText(probe).width;
        ctx.font = at + 'px "' + clean + '", ' + fallback;
        if (Math.abs(ctx.measureText(probe).width - base) > 0.5) return true;
      }
      return false;
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
      write(text, x + 14, y, w - 22, h, 16, 0, Ink, 0);
      return over && mousePressed.has("left");
    }

    function paint() {
      // A FRAME THAT DREW NOTHING KEEPS THE LAST PICTURE. It does not clear.
      //
      // `jester.app`'s `openApp` ends with `idleWhenQuiet()`: an application
      // redraws when something happened and otherwise does not, which is the
      // whole point of an idle policy. So a quiet frame records ZERO commands —
      // and a painter that clears first and then replays nothing turns "nothing
      // changed" into "everything disappeared".
      //
      // Measured: every app mod in the registry came up, drew its first frames
      // (188 fills, 40 texts), went quiet, and read back as a blank canvas —
      // `commands: 0, frames: 98`. It looked like seven broken mods and was one
      // broken painter.
      if (!commands.length) return;
      painting = true;
      ctx.fillStyle = "#0b0d12";
      ctx.fillRect(0, 0, canvas.width, canvas.height);
      // A mod that pushes a clip and never pops it (because it raised partway
      // through a frame) must not leave the context clipped for every frame
      // after. `depth` counts what this replay opened so the end can close it.
      let depth = 0;
      for (const c of commands) {
        if (c.kind === 0) { ctx.fillStyle = c.tint; ctx.fillRect(c.x, c.y, c.w, c.h); continue; }
        if (c.kind === 2) {
          ctx.save();
          ctx.beginPath();
          ctx.rect(c.x, c.y, c.w, c.h);
          ctx.clip();
          depth++;
          continue;
        }
        if (c.kind === 3) { if (depth > 0) { ctx.restore(); depth--; } continue; }
        ctx.fillStyle = c.tint;
        ctx.font = face(c.size, c.slot);
        ctx.textBaseline = "middle";
        const wide = ctx.measureText(c.text).width;
        let x = c.x;
        if (c.align === 1) x = c.x + (c.w - wide) / 2;
        else if (c.align === 2) x = c.x + c.w - wide;
        ctx.fillText(c.text, x, c.y + c.h / 2);
      }
      while (depth > 0) { ctx.restore(); depth--; }
      painting = false;
    }

    const nil = () => ({ k: "n" });
    const int = (v) => ({ k: "i", v: Number(v) | 0 });
    const num = (v) => ({ k: "f", v: Number(v) });
    const bool = (v) => ({ k: "b", v: !!v });
    const str = (v) => ({ k: "s", v: String(v) });
    // `remember`/`save` are overloaded on the VALUE's type and the host must give
    // back the kind the mod declared, so the shape of the initial argument
    // decides the shape of the answer — the same rule ConvertValue follows in C#.
    const like = (sample, v) =>
      typeof sample === "boolean" ? bool(v === true || v === "true") :
      typeof sample === "number" ? (Number.isInteger(sample) ? int(v) : num(v)) : str(v);

    // Read a remembered value, or the mod's own fallback when nothing is stored.
    // The store holds strings (it is mirrored to localStorage by the page), so a
    // typed read parses; an unparseable value falls back rather than handing the
    // mod a NaN it never asked for.
    const remembered = (key, fallback, parse) => {
      const k = String(key);
      if (!store.has(k)) return fallback;
      const parsed = parse(store.get(k));
      return (typeof parsed === "number" && !Number.isFinite(parsed)) ? fallback : parsed;
    };
    const persist = (key, text) => {
      store.set(String(key), text);
      self.postMessage({ type: "persist", key: String(key), value: text });
    };

    // ── THE FONT CACHE AND REGISTRATION ──────────────────────────────────────
    //
    // `fonts.nim` lets a mod fetch a font and make it drawable without shipping
    // the file or asking anyone to install anything: `cacheFont(name, base64)`
    // then `registerFont(name)`. On Windows that is `AddFontResourceEx(...,
    // FR_PRIVATE)` — the family exists for THIS PROCESS and for nothing else.
    // A browser's `FontFace` has exactly that lifetime, which is why this maps
    // over so cleanly: added to this worker's font set, gone when it ends,
    // visible to no other page.
    //
    // THE FAMILY NAME IS READ FROM THE FONT, NOT FROM THE FILENAME. Windows
    // takes it from the font's own `name` table and this does the same, because
    // the filename is not a reliable source: Google ships variable fonts as
    // `OpenSans[wdth,wght].ttf`, so stripping a `-Regular` suffix gets you
    // `OpenSans[wdth,wght]` and a family nothing will ever match. Reading the
    // table costs thirty lines and is exact for every file, fixed or variable.
    const fontCache = new Map();          // name -> Uint8Array
    let fontProblem = "";

    // Cache-name rule, transcribed from `fonts.nim`: letters, digits, `.`, `-`,
    // `_`, ending `.ttf` or `.otf`. Refused outright rather than renamed,
    // because a silently renamed entry is one nothing can find again.
    const cacheNameOk = (n) => /^[A-Za-z0-9._-]+\.(ttf|otf)$/i.test(n);

    // The sfnt `name` table: nameID 16 (typographic family) if present, else 1
    // (family). Both encodings appear in the wild — platformID 3 is UTF-16BE,
    // platformID 1 is single-byte — so both are decoded rather than assumed.
    function familyFromFont(bytes) {
      const dv = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
      const u16 = (o) => dv.getUint16(o), u32 = (o) => dv.getUint32(o);
      let base = 0;
      if (u32(0) === 0x74746366) base = u32(12);          // 'ttcf': first font
      const numTables = u16(base + 4);
      let nameOff = 0;
      for (let i = 0; i < numTables; i++) {
        const rec = base + 12 + i * 16;
        const tag = String.fromCharCode(bytes[rec], bytes[rec + 1], bytes[rec + 2], bytes[rec + 3]);
        if (tag === "name") { nameOff = u32(rec + 8); break; }
      }
      if (!nameOff) return "";
      const count = u16(nameOff + 2), strOff = nameOff + u16(nameOff + 4);
      let best = "";
      for (let i = 0; i < count; i++) {
        const r = nameOff + 6 + i * 12;
        const platform = u16(r), nameId = u16(r + 6);
        if (nameId !== 1 && nameId !== 16) continue;
        const len = u16(r + 8), off = strOff + u16(r + 10);
        if (off + len > bytes.length) continue;
        let out = "";
        if (platform === 3) {
          for (let k = 0; k + 1 < len; k += 2) out += String.fromCharCode(dv.getUint16(off + k));
        } else {
          for (let k = 0; k < len; k++) out += String.fromCharCode(bytes[off + k]);
        }
        out = out.replace(/\0/g, "").trim();
        if (!out) continue;
        if (nameId === 16) return out;                    // typographic wins outright
        if (!best) best = out;
      }
      return best;
    }

    // ── INSTALLING CONTENT (the `jester_content_*` family) ──────────────────
    //
    // THIS IS WHY THERE IS NO "GET MODS" BUTTON ANY MORE. The demo grew one —
    // a panel beside the canvas with its own registry, its own installer and
    // its own idea of what an installed mod is — and every bit of that was a
    // second implementation of something the shell already does. `Search
    // online` in the launcher lists a registry, Enter queues a bundle, and
    // `stepQueueFetching` in the shell's own `main.nim` drives exactly the
    // calls below over plain HTTP. They are host calls, and host calls are the
    // one thing a browser can answer. So it answers them, and installing a mod
    // on this page is now the same code, in the same UI, as installing one on
    // the desktop — a confirm dialog that lists the mods, a progress row, a
    // dedup count, all of it the shell's.
    //
    // WHAT "INSTALLED" MEANS HERE. On the desktop a commit renames whole
    // folders into the content root and the engine's discovery poll notices. A
    // page has no content root, so a commit assembles each mod out of the files
    // it just verified — `.jester/build.json` for the receipt, `.jester/live/*`
    // for the artifacts, `mod.json` for the name, `*.nim` for the source the
    // Clone button hands to the editor — and posts it to the panel, which adds
    // it to the launcher's list. Same input, same check, same result: a mod the
    // shell can play.
    //
    // WHAT IS REAL AND WHAT IS NOT. The manifest parse, the per-file sha256,
    // the SDK-stamp refusal and the content-addressed dedup are all real and
    // all enforced here — a file whose bytes do not hash to what the manifest
    // promised is refused by path, with both hashes, exactly as
    // `ContentStage.Take` does. What is NOT real is durability: this install
    // lives in the worker's memory for the session. Saying so is the honest
    // version; pretending a page has a disk is not.
    let contentProblem = "";
    let installedVersion = "";
    // Content-addressed, because most of a content set by weight is the SDK
    // compiled into every mod's artifacts — 170 files that are 25 distinct
    // ones. `contentNeeds` answers off this map, so the second mod's copy of a
    // shared module is never downloaded, which is what makes the shell's
    // progress row say "141 copied, 29 fetched" rather than fetching 8.6 MB.
    const blobs = new Map();          // sha256 -> Uint8Array
    const installedFiles = new Map(); // path -> sha256
    const stages = new Map();
    let stageSeq = 0;

    // SHA-256, synchronously. `crypto.subtle.digest` is a promise and
    // `contentFile` is not: the SDK call returns a bool the mod branches on in
    // the same frame. Deferring the answer would mean lying about it now and
    // discovering the lie later, which for "did the bytes I was sent match the
    // hash I was promised" is the one place a maybe is worthless.
    const SHA_K = new Uint32Array([
      0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
      0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
      0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
      0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
      0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
      0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
      0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
      0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2]);
    function sha256Hex(bytes) {
      const rotr = (x, n) => (x >>> n) | (x << (32 - n));
      const len = bytes.length, padded = (len + 9 + 63) & ~63;
      const m = new Uint8Array(padded);
      m.set(bytes);
      m[len] = 0x80;
      const dv = new DataView(m.buffer);
      dv.setUint32(padded - 8, Math.floor(len / 536870912));   // (len * 8) >> 32
      dv.setUint32(padded - 4, (len << 3) >>> 0);
      const h = new Uint32Array([0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                                 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19]);
      const w = new Uint32Array(64);
      for (let i = 0; i < padded; i += 64) {
        for (let t = 0; t < 16; t++) w[t] = dv.getUint32(i + t * 4);
        for (let t = 16; t < 64; t++) {
          const a15 = w[t - 15], a2 = w[t - 2];
          const s0 = rotr(a15, 7) ^ rotr(a15, 18) ^ (a15 >>> 3);
          const s1 = rotr(a2, 17) ^ rotr(a2, 19) ^ (a2 >>> 10);
          w[t] = (w[t - 16] + s0 + w[t - 7] + s1) >>> 0;
        }
        let a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], hh = h[7];
        for (let t = 0; t < 64; t++) {
          const S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
          const t1 = (hh + S1 + ((e & f) ^ (~e & g)) + SHA_K[t] + w[t]) >>> 0;
          const S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
          const t2 = (S0 + ((a & b) ^ (a & c) ^ (b & c))) >>> 0;
          hh = g; g = f; f = e; e = (d + t1) >>> 0;
          d = c; c = b; b = a; a = (t1 + t2) >>> 0;
        }
        h[0] = (h[0] + a) >>> 0; h[1] = (h[1] + b) >>> 0; h[2] = (h[2] + c) >>> 0; h[3] = (h[3] + d) >>> 0;
        h[4] = (h[4] + e) >>> 0; h[5] = (h[5] + f) >>> 0; h[6] = (h[6] + g) >>> 0; h[7] = (h[7] + hh) >>> 0;
      }
      let out = "";
      for (let i = 0; i < 8; i++) out += h[i].toString(16).padStart(8, "0");
      return out;
    }

    const b64ToBytes = (s) => {
      const bin = atob(String(s || ""));
      const out = new Uint8Array(bin.length);
      for (let i = 0; i < bin.length; i++) out[i] = bin.charCodeAt(i);
      return out;
    };
    const bytesToB64 = (b) => {
      let s = "";
      for (let i = 0; i < b.length; i += 0x8000)
        s += String.fromCharCode.apply(null, b.subarray(i, i + 0x8000));
      return btoa(s);
    };
    const bytesToText = (b) => new TextDecoder().decode(b);

    // Turn the files a commit verified into the mods the launcher lists. The
    // shape is the payload's — see `tools/pack-jester-payload.mjs`, which builds
    // the same object from the same files on disk. One producer's output being
    // another's is the point: an installed mod is not a second class of mod.
    function modsFromFiles(paths) {
      const byMod = new Map();
      for (const p of paths) {
        const m = /^Mods\/([^/]+)\/(.+)$/.exec(p);
        if (!m) continue;
        if (!byMod.has(m[1])) byMod.set(m[1], new Map());
        byMod.get(m[1]).set(m[2], blobs.get(installedFiles.get(p)));
      }
      const out = [];
      for (const [id, files] of byMod) {
        const receipt = files.get(".jester/build.json");
        if (!receipt) continue;
        let build = {};
        try { build = JSON.parse(bytesToText(receipt)); } catch (_) { continue; }
        const artifact = build.artifact || "";
        const live = ".jester/live/";
        const pool = {}, modules = [];
        let src = "";
        for (const [rel, bytes] of files) {
          if (!rel.startsWith(live)) continue;
          const name = rel.slice(live.length);
          if (name === artifact) { src = bytesToB64(bytes); continue; }
          if (!name.endsWith(".s.nif") && !name.endsWith(".s.idx.nif")) continue;
          pool[name] = bytesToB64(bytes);
          modules.push(name);
        }
        if (!src) continue;
        let manifest = {};
        try { manifest = JSON.parse(bytesToText(files.get("mod.json"))); } catch (_) {}
        const source = {};
        for (const [rel, bytes] of files)
          if (!rel.startsWith(".jester/") && /\.(nim|json|md)$/i.test(rel))
            source[rel] = bytesToText(bytes);
        out.push({ id: build.mod || id, name: manifest.name || id,
                   blurb: manifest.description || "", artifact, sha256: build.sha256 || "",
                   src, modules, pool, source, sdk: build.sdk || "", animated: true });
      }
      return out;
    }

    // A URL FOR THE PUBLISHED SITE, SERVED FROM THIS CHECKOUT WHEN THERE IS ONE.
    //
    // The shell's mod registry names absolute urls, because the shell is the
    // desktop player's launcher too and a relative url means nothing there. But
    // an absolute url pointing at the published site is the one thing a local
    // checkout must NOT fetch: you would edit the content set here, reload, and
    // still be testing what is deployed. So when the page is being served from
    // a loopback address — and only then — a request for this project's own
    // published hosts is answered from the origin actually serving the page.
    //
    // Deliberately narrow: two known hosts, loopback only, same path. It is not
    // a proxy and it cannot redirect anything to a third party.
    const OWN_HOSTS = ["aoughwl.github.io", "aoughwl.com", "www.aoughwl.com"];
    function localMirror(url) {
      try {
        const here = new URL(self.location.href);
        if (!/^(localhost|127\.0\.0\.1|\[::1\])$/.test(here.hostname)) return url;
        const u = new URL(url, here);
        if (!OWN_HOSTS.includes(u.hostname)) return url;
        return new URL(u.pathname + u.search, here).href;
      } catch (_) { return url; }
    }

    const CALLS = {
      jester_log: (a) => { log(String(a[0])); return nil(); },

      jester_screen_size: (a) => num(a[0] === 0 ? canvas.width : canvas.height),
      jester_delta_time: () => num(delta),
      jester_time: () => num((performance.now() - startTime) / 1000),
      jester_render_frames: () => int(frames),

      jester_key_held: (a) => bool(held.has(a[0])),
      // WHICH NAMES THE MOD ASKS FOR, and which of them ever answered true. A
      // mod resolves a key BY NAME ("DownArrow", "Enter"), and the browser
      // spells the same key differently ("ArrowDown"); when those disagree the
      // mod polls happily forever and simply never acts, which looks exactly
      // like a mod that ignores the keyboard. Recording both sides turns that
      // into one line of evidence.
      jester_key_pressed: (a) => {
        const name = String(a[0]);
        const hit = pressed.has(name);
        keysAsked.set(name, (keysAsked.get(name) || 0) + 1);
        if (hit) keysHit.set(name, (keysHit.get(name) || 0) + 1);
        return bool(hit);
      },
      jester_mouse_held: (a) => bool(mouseHeld.has(a[0])),
      // Same reasoning as `key_pressed`: record the NAME asked for and whether
      // it answered true. A mod spells a button `LeftButton` and the browser
      // spells it `left`; when those disagree the mod polls forever and never
      // acts, and when something answers true that should not, this is the only
      // place that says so.
      jester_mouse_pressed: (a) => {
        const name = String(a[0]);
        const hit = mousePressed.has(name);
        mouseAsked.set(name, (mouseAsked.get(name) || 0) + 1);
        if (hit) mouseHit.set(name, (mouseHit.get(name) || 0) + 1);
        return bool(hit);
      },
      jester_look_delta: (a) => num(a[0] === 0 ? lookX : lookY),

      // THE WHEEL, AND WHY IT IS NOT OPTIONAL.
      //
      // This was the ONE call the shell asked for that this host did not serve,
      // and a declined call answers nil — which is not `0.0`. The shell reads
      // it as
      //
      //     let scrolled = wheel()
      //     if scrolled != 0.0: …
      //
      // so a nil answer is a wheel that is spinning on EVERY FRAME, forever. It
      // scrolled the list continuously and, with the Ctrl+wheel zoom on the same
      // reading, wound the interface up to 165%. Serving it costs four lines.
      //
      // The lesson is bigger than the wheel: a numeric host call that gets
      // declined does not read as zero, it reads as garbage, and the mod then
      // behaves as though something happened. That is why `triage-mods.mjs`
      // records declines per mod by name — they are not cosmetic.
      jester_mouse_wheel: () => { const w = wheelDelta; return num(w); },
      jester_typed_text: () => { const t = typed; typed = ""; return str(t); },

      jester_pointer_at: (a) => num(a[0] === 0 ? pointerX : pointerY),
      jester_pointer_show: (a) => {
        pointerShown = !!a[0];
        self.postMessage({ type: "cursor", shown: pointerShown });
        return nil();
      },
      jester_pointer_shown: () => bool(pointerShown),
      jester_pointer_hold: (a) => {
        pointerLocked = !!a[0];
        self.postMessage({ type: "pointerlock", locked: pointerLocked });
        return nil();
      },
      jester_pointer_held: () => bool(pointerLocked),

      jester_pack_count: () => int(packs.length),
      // Record WHICH index was asked for. `drawDeleteConfirm` calls
      // `modpackName(pendingDelete)` every frame it is up, so the set of indices
      // this host is asked about is a direct read of that variable from outside
      // the mod — including whether it is the -1 that means "no dialog".
      jester_pack_name: (a) => {
        packNameArgs.add(Number(a[0]));
        return str(packs[a[0]] ? packs[a[0]].name : "");
      },
      jester_pack_playing: () => str(playing),
      // THE LAUNCH. The shell hands us an index; the page turns that into a set
      // of mods and starts them in this session. `playing` is set optimistically
      // so the shell's own `handBack()` bookkeeping reads true immediately, the
      // way it does on the desktop where Session.Activate is synchronous.
      jester_pack_select: (a) => {
        const pack = packs[a[0]];
        if (pack) {
          playing = pack.id;
          self.postMessage({ type: "play", pack });
        }
        return nil();
      },

      jester_draw_fill: (a) => {
        fill(a[0], a[1], a[2], a[3], rgba(a[4], a[5], a[6], a[7]));
        return nil();
      },
      // The font slot is the LAST argument of draw_text (twelfth) and the THIRD
      // of draw_measure. Both were dropped here; both are honoured now, so the
      // width a mod lays out with is the width it draws at.
      jester_draw_text: (a) => {
        write(a[0], a[1], a[2], a[3], a[4], a[5], align(a[6]),
              rgba(a[7], a[8], a[9], a[10]), a[11]);
        return nil();
      },
      jester_draw_measure: (a) => num(measure(a[0], a[1], a[2])),

      // A FAMILY NAME IN, A SLOT OUT — and -1 when there is no such face.
      //
      // Slots 0-2 are fixed, so nothing a mod asks for at runtime can change
      // what another mod already draws in; a new name appends from 3 up. The
      // -1 matters: the caller is choosing between a page's stated family and
      // its own default, and can only make that choice if failure is
      // distinguishable from success. Falling back to slot 0 silently would
      // take the decision away and look identical to having honoured it.
      //
      // A browser is unusually well placed for this — CSS can name any family
      // and the canvas can measure whether it resolved — so unlike the desktop
      // this answer is real rather than a promise about a lookup elsewhere.
      jester_draw_font: (a) => {
        const name = String(a[0] || "").trim();
        if (!name) return int(-1);
        for (let i = 0; i < faces.length; i++)
          if (faces[i].name && faces[i].name.toLowerCase() === name.toLowerCase()) return int(i);
        if (!familyAvailable(name)) return int(-1);
        faces.push({ weight: 400, family: '"' + name.replace(/["\\]/g, "") + '", ' + STACK, name });
        return int(faces.length - 1);
      },

      // CLIPPING IS REAL, not a no-op. The shell's list SCROLLS, and a scrolling
      // list that does not clip draws its rows straight through the bar above and
      // the footer below. Canvas 2D has exactly this as `save`/`clip`/`restore`,
      // so it records as two more command kinds and replays in the same pass.
      jester_draw_clip_push: (a) => {
        commands.push({ kind: 2, x: a[0], y: a[1], w: a[2], h: a[3] });
        return nil();
      },
      jester_draw_clip_pop: () => { commands.push({ kind: 3 }); return nil(); },

      // Honest answers for what a browser has none of. `imagePresent` is the
      // SDK's own "is this texture loaded yet" question and false is true here —
      // nothing has been loaded, because this host serves no images.
      jester_image_present: () => bool(false),
      jester_image_width: () => int(0),
      jester_image_height: () => int(0),
      jester_draw_image: () => nil(),
      jester_window_cursor_set: () => nil(),
      jester_host_version: () => str("browser"),

      jester_ui_panel: (a) => (panel(a[0], a[1], a[2], a[3], !!a[4]), nil()),
      jester_ui_begin: (a) => {
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
      jester_ui_label: (a) => {
        write(a[0], left, flow, span, 25, 16, 0, Ink);
        flow += 25;
        return nil();
      },
      jester_ui_space: (a) => (flow += a[0], nil()),
      jester_ui_button: (a) => {
        const y = flow; flow += a[1];
        const clicked = buttonAt(a[0], left, y, span, a[1]);
        flow += Gap;
        return bool(clicked);
      },
      jester_ui_button_at: (a) => bool(buttonAt(a[0], a[1], a[2], a[3], a[4])),
      jester_ui_at: (a) => num(a[0] === 0 ? left : a[0] === 1 ? flow : span),
      jester_ui_move: (a) => (left = a[0], flow = a[1], span = a[2], nil()),
      jester_ui_take: (a) => { const y = flow; flow += a[0]; return num(y); },
      jester_ui_hot: (a) => bool(hot(a[0], a[1], a[2], a[3])),
      jester_ui_end: () => {
        if (open !== null) heights.set(open, flow - top + Pad);
        open = null;
        return nil();
      },

      // THE WINDOW FAMILY, ANSWERED HONESTLY RATHER THAN DECLINED.
      //
      // `ModSdk/window.nim` shapes the player's OS window — frameless, rounded,
      // always-on-top, click-through — and it is explicit that this is "Windows
      // players only, and never a lie": in the Unity editor every call does
      // nothing, on macOS and Linux there is nothing to find, and a mod is told
      // to "ask `windowAvailable()` once and `windowProblem()` for the sentence
      // to show; nothing throws and nothing pretends it worked."
      //
      // A browser tab is exactly that situation, so the SDK's own designed
      // answer is the right one. DECLINING these instead is what broke the
      // shell: it asks `windowAvailable()` during start, a declined call is
      // reported unported, and the launcher never got to draw. Answering false
      // costs two lines and puts the mod on the path its author already wrote
      // for a host with no window to give.
      jester_window_available: () => bool(false),
      jester_window_problem: () => str("This is a browser tab, not an OS window — " +
        "the page owns its frame, so nothing here can move, reshape or un-decorate it."),
      jester_window_mode: () => int(0),
      jester_window_framed: () => bool(true),
      jester_window_transparent: () => bool(false),
      jester_window_corners: () => int(0),
      jester_window_top: () => bool(false),
      jester_window_through: () => bool(false),
      jester_window_at: () => int(0),
      jester_window_clear: () => nil(),
      jester_window_center: () => nil(),
      jester_window_close: () => nil(),
      jester_window_drag: () => nil(),
      jester_window_minimise: () => nil(),
      jester_window_restore: () => nil(),
      jester_window_windowed: () => nil(),
      jester_window_mode_set: () => nil(),
      jester_window_mode_native: () => nil(),
      jester_window_frame_set: () => nil(),
      jester_window_transparent_set: () => nil(),
      jester_window_corners_set: () => nil(),
      jester_window_top_set: () => nil(),
      jester_window_through_set: () => nil(),
      jester_window_move: () => nil(),
      jester_window_size: () => nil(),
      jester_window_size_live: () => nil(),

      // THE HTTP FAMILY, SERVED BY `fetch`.
      //
      // The SDK's shape is prepare -> header/body/timeout -> send -> poll
      // `done` -> read status/body/headers -> release, which is a non-blocking
      // model precisely so a mod can ask for something and keep drawing. That is
      // `fetch` plus a table of pending requests, almost exactly.
      //
      // WHAT IS DIFFERENT HERE, AND IS NOT HIDDEN: a page can only reach hosts
      // that send CORS headers. That is not a limit this host invented and it is
      // not one it can route around — no proxy, because a proxy would mean this
      // demo silently sending the user's requests through someone else's server.
      // So a blocked host fails the way it really failed, and `httpProblem()`
      // says CORS rather than something vaguer.
      jester_http_available: () => bool(true),
      // `allowed` is the SDK's pre-flight question. Answering "yes" to
      // everything and letting the send fail is the honest shape: whether a host
      // permits this origin is not knowable without asking it.
      jester_http_allowed: (a) => bool(/^https?:\/\//i.test(String(a[0] || ""))),
      jester_http_prepare: (a) => {
        const id = ++httpSeq;
        http.set(id, { method: String(a[0] || "GET").toUpperCase(), url: String(a[1] || ""),
                       headers: {}, body: null, timeout: 30000, state: "new",
                       status: 0, text: "", bytes: null, resHeaders: {}, error: "" });
        return int(id);
      },
      jester_http_header: (a) => {
        const r = http.get(a[0]); if (!r) return bool(false);
        r.headers[String(a[1])] = String(a[2]);
        return bool(true);
      },
      jester_http_body: (a) => {
        const r = http.get(a[0]); if (!r) return bool(false);
        r.body = String(a[1]);
        if (a[2]) r.headers["content-type"] = String(a[2]);
        return bool(true);
      },
      jester_http_timeout: (a) => {
        const r = http.get(a[0]); if (!r) return bool(false);
        r.timeout = Math.max(1, Number(a[1]) | 0);
        return bool(true);
      },
      jester_http_send: (a) => {
        const r = http.get(a[0]);
        if (!r || r.state !== "new") return bool(false);
        r.state = "flight";
        const ctl = typeof AbortController !== "undefined" ? new AbortController() : null;
        const timer = setTimeout(() => { if (ctl) ctl.abort(); }, r.timeout);
        fetch(localMirror(r.url), { method: r.method, headers: r.headers,
                       body: r.body == null ? undefined : r.body,
                       signal: ctl ? ctl.signal : undefined })
          .then(async (res) => {
            clearTimeout(timer);
            r.status = res.status;
            res.headers.forEach((v, k) => { r.resHeaders[k.toLowerCase()] = v; });
            // Keep BYTES, not just text: `response_base64` exists so a mod can
            // read an image, and decoding those through a string would corrupt
            // them. The text view is derived, and only for what is textual.
            const buf = await res.arrayBuffer();
            r.bytes = new Uint8Array(buf);
            let s = "";
            for (let i = 0; i < r.bytes.length; i++) s += String.fromCharCode(r.bytes[i]);
            r.text = s;
            r.state = "done";
            touch();
          })
          .catch((e) => {
            clearTimeout(timer);
            const msg = String(e && e.name === "AbortError" ? "timed out after " + r.timeout + " ms"
              : (e && e.message) || e);
            r.error = /Failed to fetch|NetworkError|load failed/i.test(msg)
              ? "could not reach " + r.url + " — a page can only fetch from hosts that send " +
                "CORS headers, and this one did not (or is offline)."
              : msg;
            httpProblem = r.error;
            r.state = "done";
            touch();
          });
        return bool(true);
      },
      jester_http_problem: () => str(httpProblem),
      jester_http_done: (a) => bool((http.get(a[0]) || {}).state === "done"),
      jester_http_status: (a) => int((http.get(a[0]) || {}).status || 0),
      // The body is read from an OFFSET so a mod can take a long document in
      // pieces rather than marshalling megabytes across the boundary at once.
      jester_http_response_body: (a) => {
        const r = http.get(a[0]); if (!r) return str("");
        return str(r.text.slice(Number(a[1]) | 0));
      },
      jester_http_response_length: (a) => int(((http.get(a[0]) || {}).text || "").length),
      jester_http_response_base64: (a) => {
        const r = http.get(a[0]);
        if (!r || !r.bytes) return str("");
        let s = "";
        for (let i = 0; i < r.bytes.length; i++) s += String.fromCharCode(r.bytes[i]);
        return str(btoa(s));
      },
      jester_http_response_header: (a) => {
        const r = http.get(a[0]); if (!r) return str("");
        return str(r.resHeaders[String(a[1]).toLowerCase()] || "");
      },
      jester_http_error: (a) => str((http.get(a[0]) || {}).error || ""),
      jester_http_release: (a) => { http.delete(a[0]); return nil(); },
      // ── the content family; see the block above CALLS for what it is for ──
      jester_content_available: () => bool(true),
      jester_content_root: () => str("this page (installed content lives in the session)"),
      jester_content_installed: () => str(installedVersion),
      jester_content_problem: () => str(contentProblem),

      // Open, or re-open, the staging area for the set this manifest describes.
      // Re-opening the same version keeps what is already downloaded — which is
      // free here, because the blobs are content-addressed and shared.
      jester_content_stage: (a) => {
        let manifest;
        try { manifest = JSON.parse(String(a[0] || "")); }
        catch (e) { contentProblem = "the content manifest is not JSON: " + (e.message || e); return int(0); }
        if (!manifest || typeof manifest !== "object") { contentProblem = "the content manifest is not an object."; return int(0); }
        if (!manifest.version) { contentProblem = "The content manifest has no version."; return int(0); }
        const files = Array.isArray(manifest.files) ? manifest.files : [];
        if (!files.length) { contentProblem = `Content set ${manifest.version} installs nothing.`; return int(0); }
        for (const f of files) {
          if (!f || !f.path) { contentProblem = `Content set ${manifest.version} lists a file with no path.`; return int(0); }
          if (!/^[0-9a-f]{64}$/i.test(String(f.sha256 || ""))) {
            contentProblem = `'${f.path}' has no sha256, so nothing could check what arrived.`;
            return int(0);
          }
          // A path that escapes the content root is the one thing a manifest
          // must never be able to do, and it is cheap to refuse.
          if (f.path.startsWith("/") || f.path.includes("..") || /^[a-z]:/i.test(f.path)) {
            contentProblem = `'${f.path}' is not a path inside the content root.`;
            return int(0);
          }
          f.sha256 = String(f.sha256).toLowerCase();
        }
        // THE SDK STAMP DECIDES WHETHER THIS SET CAN JOIN THIS ONE. Every mod
        // compiles the SDK into its own artifacts under one module id, so a
        // tree that disagrees is a tree where whichever mod loads first breaks
        // the others. `opts.sdk` is the stamp the page's own built-in mods were
        // built against — the same comparison `ContentStage.VerifySdk` makes
        // against the installed tree, refused here for the same reason and NOT
        // left to be discovered as a blank canvas later.
        if (opts.sdk && manifest.sdk && manifest.sdk !== opts.sdk) {
          contentProblem = `Content set ${manifest.version} was built against SDK ` +
            `${String(manifest.sdk).slice(0, 12)}, and this page is on ` +
            `${String(opts.sdk).slice(0, 12)}.`;
          return int(0);
        }
        const id = ++stageSeq;
        stages.set(id, { manifest, files });
        contentProblem = "";
        return int(id);
      },
      jester_content_version: (a) => str((stages.get(a[0]) || { manifest: {} }).manifest.version || ""),
      jester_content_host: (a) => str((stages.get(a[0]) || { manifest: {} }).manifest.host || "*"),
      jester_content_notes: (a) => str((stages.get(a[0]) || { manifest: {} }).manifest.notes || ""),
      jester_content_count: (a) => int(((stages.get(a[0]) || {}).files || []).length),
      jester_content_path: (a) => {
        const f = ((stages.get(a[0]) || {}).files || [])[a[1]];
        return str(f ? f.path : "");
      },
      jester_content_hash: (a) => {
        const f = ((stages.get(a[0]) || {}).files || [])[a[1]];
        return str(f ? f.sha256 : "");
      },
      // False means "it is already here" — staged from a previous attempt, or
      // already installed with the same bytes, or carried by ANOTHER file in
      // this same set that happens to hash the same. That last one is the
      // common case and the reason this is content-addressed.
      jester_content_needs: (a) => {
        const s = stages.get(a[0]); if (!s) return bool(false);
        const want = String(a[1] || "");
        const f = s.files.find((x) => x.path === want);
        return bool(!!f && !blobs.has(f.sha256));
      },
      jester_content_file: (a) => {
        const s = stages.get(a[0]);
        if (!s) { contentProblem = "there is no such staging area."; return bool(false); }
        const want = String(a[1] || "");
        const f = s.files.find((x) => x.path === want);
        if (!f) {
          contentProblem = `Content set ${s.manifest.version} does not contain '${want}', ` +
                           "so there is nowhere to put it.";
          return bool(false);
        }
        let bytes;
        try { bytes = b64ToBytes(a[2]); }
        catch (e) { contentProblem = `'${want}' did not arrive as valid base64.`; return bool(false); }
        const got = sha256Hex(bytes);
        if (got !== f.sha256) {
          contentProblem = `'${want}' hashes to ${got.slice(0, 12)} and the manifest promised ` +
                           `${f.sha256.slice(0, 12)}. Nothing was written.`;
          return bool(false);
        }
        blobs.set(got, bytes);
        contentProblem = "";
        return bool(true);
      },
      // Install it: everything the manifest promised must be present and
      // correct. `mode: "add"` joins what is here; a whole set would replace it,
      // and this host refuses that rather than quietly doing half of it — the
      // shell is itself content, and a set that does not mention the shell would
      // be a set that takes away the launcher the player is standing in.
      jester_content_commit: (a) => {
        const s = stages.get(a[0]);
        if (!s) { contentProblem = "there is no such staging area."; return bool(false); }
        if (s.manifest.mode && s.manifest.mode !== "add") {
          contentProblem = `Content set ${s.manifest.version} is a whole-set install, and this ` +
                           "page can only add to what it is already running.";
          return bool(false);
        }
        const missing = s.files.filter((f) => !blobs.has(f.sha256));
        if (missing.length) {
          contentProblem = `${missing.length} file(s) never arrived, starting with '${missing[0].path}'.`;
          return bool(false);
        }
        for (const f of s.files) installedFiles.set(f.path, f.sha256);
        const mods = modsFromFiles(s.files.map((f) => f.path));
        if (!mods.length) {
          contentProblem = `Content set ${s.manifest.version} carries no mod this page can load.`;
          return bool(false);
        }
        installedVersion = s.manifest.version;
        stages.delete(a[0]);
        contentProblem = "";
        // The panel adds them to the launcher's list, which is the browser's
        // version of the engine's discovery poll noticing a swapped folder.
        self.postMessage({ type: "installed", mods, version: installedVersion });
        log("installed content set " + installedVersion + ": " +
            mods.map((m) => m.id).join(", "));
        return bool(true);
      },
      jester_content_abort: (a) => { stages.delete(a[0]); return nil(); },

      jester_http_in_flight: () => {
        let n = 0;
        for (const r of http.values()) if (r.state === "flight") n++;
        return int(n);
      },

      // A worker has no `localStorage`, so this is an in-memory map that the
      // page seeds at attach and persists on every write. Which means it behaves
      // exactly like the demo's localStorage did — including surviving a mod
      // swap, which is the half of "reload the code, keep the data" that lives
      // OUTSIDE interpreter memory and is worth showing on its own.
      // THE TYPED FORMS ARE THE RELIABLE ONES, and the SDK now has them.
      //
      // `remember`/`save` are overloaded on the value's TYPE, and the untyped
      // `jester_state_get` cannot recover which overload was meant — the host
      // has to guess from the shape of the sample. That guess is wrong for a
      // float whose value happens to be integral: `remember("scale", 1.0)` asks
      // for a float64 and `Number.isInteger(1.0)` is true, so the answer came
      // back an int. The C# bridge has the same hazard and its own comment
      // admits the rule is "the shape of the initial argument decides".
      //
      // `..._integer` / `..._number` / `..._boolean` carry the kind in the CALL,
      // so there is nothing to infer. The untyped pair stays for text and for
      // artifacts built before these existed.
      jester_font_cache_write: (a) => {
        const name = String(a[0] || "");
        if (!cacheNameOk(name)) {
          fontProblem = "'" + name + "' is not a usable cache name: letters, digits, " +
                        "'.', '-', '_' only, ending .ttf or .otf";
          return bool(false);
        }
        try {
          const bin = atob(String(a[1] || ""));
          const bytes = new Uint8Array(bin.length);
          for (let i = 0; i < bin.length; i++) bytes[i] = bin.charCodeAt(i);
          fontCache.set(name, bytes);
          fontProblem = "";
          return bool(true);
        } catch (e) {
          fontProblem = "the body was not valid base64";
          return bool(false);
        }
      },
      jester_font_cache_exists: (a) => bool(fontCache.has(String(a[0] || ""))),
      jester_font_register_problem: () => str(fontProblem),
      jester_font_register: (a) => {
        const name = String(a[0] || "");
        const bytes = fontCache.get(name);
        if (!bytes) { fontProblem = "'" + name + "' is not cached yet"; return bool(false); }
        if (typeof FontFace === "undefined" || !self.fonts) {
          fontProblem = "this browser will not let a worker register a font";
          return bool(false);
        }
        let family = "";
        try { family = familyFromFont(bytes); }
        catch (e) { fontProblem = "could not read the font's name table: " + (e.message || e); return bool(false); }
        if (!family) { fontProblem = "the file declares no family name"; return bool(false); }
        try {
          // `load()` is async and the SDK call is not, so the face is added
          // immediately and the load is left in flight. That matches the
          // Windows contract: registering is "the loading half, not a promise
          // about the lookup half" — a mod asks `fontNamed` afterwards, and
          // that answer is measured rather than assumed.
          const ff = new FontFace(family, bytes.buffer);
          self.fonts.add(ff);
          ff.load().then(() => { touch(); }).catch(() => {});
          fontProblem = "";
          log("registered font family '" + family + "' from " + name);
          return bool(true);
        } catch (e) {
          fontProblem = "this host's loader refused the file: " + (e.message || e);
          return bool(false);
        }
      },

      jester_state_get: (a) => {
        const v = store.has(String(a[0])) ? store.get(String(a[0])) : null;
        return v === null ? like(a[1], a[1]) : like(a[1], v);
      },
      jester_state_set: (a) => {
        store.set(String(a[0]), String(a[1]));
        self.postMessage({ type: "persist", key: String(a[0]), value: String(a[1]) });
        return like(a[1], a[1]);
      },
      jester_state_get_integer: (a) => int(remembered(a[0], a[1], (s) => parseInt(s, 10))),
      jester_state_get_number: (a) => num(remembered(a[0], a[1], parseFloat)),
      jester_state_get_boolean: (a) => bool(remembered(a[0], a[1], (s) => s === "true" || s === "1")),
      jester_state_set_integer: (a) => { persist(a[0], String(a[1] | 0)); return int(a[1]); },
      jester_state_set_number: (a) => { persist(a[0], String(Number(a[1]))); return num(a[1]); },
      jester_state_set_boolean: (a) => { persist(a[0], a[1] ? "true" : "false"); return bool(a[1]); },
    };

    // The SDK spells alignment as a word; the painter wants 0/1/2.
    function align(v) {
      if (typeof v === "number") return v | 0;
      return v === "centre" || v === "center" ? 1 : v === "right" ? 2 : 0;
    }

    // THE PREFIX IS THE PRODUCT NAME, AND THE PRODUCT HAS BEEN RENAMED. Every
    // host call is spelled `<product>_<call>`, and that product went from
    // `infiniteless` to `jester`. Artifacts built before the rename are still
    // byte-valid, still load, and still ask for `infiniteless_draw_text` — so a
    // table keyed on one spelling silently declines every mod built under the
    // other, which is what the first run of this panel did: the shell booted,
    // drew nothing, and raised.
    //
    // So the boundary matches on THE CALL, not on the prefix: everything after
    // the first underscore. That is a rule about the shape of a host-call name
    // rather than a list of the two names we happen to have today, so the next
    // rename costs nothing here.
    function resolve(name) {
      const direct = CALLS[name];
      if (direct) return direct;
      const under = name.indexOf("_");
      return under > 0 ? CALLS["jester_" + name.slice(under + 1)] : undefined;
    }

    // A CALL THIS HOST DOES NOT SERVE ANSWERS NIL, AND IS RECORDED BY NAME.
    //
    // The seam's contract says `undefined` means "this host does not answer that
    // call", and aowli then reports it unported — which HALTS the machine. That
    // is the right behaviour for a host that is supposed to be complete, and the
    // wrong one for a browser, which is missing whole families by construction
    // (there is no scene, no physics, no GPU here). Measured: the shell asks
    // `windowAvailable()` and `imagePresent()` during start, and a single
    // declined call ended the run with "the machine has HALTED (exit code 1)"
    // before a pixel was drawn.
    //
    // So an unknown call answers nil and the run CONTINUES — but it is counted,
    // by name, and the page prints those names. The rule this codebase actually
    // holds to is "a run says what it could not do rather than quietly
    // pretending", and a named, surfaced decline satisfies it; halting on the
    // first one does not, because a host that stops cannot report anything else
    // it would also have been unable to do.
    //
    // Where a truthful ANSWER exists, it is given instead of nil: the window
    // family reports no window, the image family reports nothing loaded. Those
    // are in CALLS above, and they are better than nil because the SDK has a
    // documented path for exactly that answer.
    function dispatch(name, args) {
      const fn = resolve(name);
      if (fn) { made.set(name, (made.get(name) || 0) + 1); return fn(args); }
      if (!declined.has(name)) log("this browser host has no answer for " + name + " — it returns nothing.");
      declined.set(name, (declined.get(name) || 0) + 1);
      return nil();
    }

    function beginFrame() {
      const now = performance.now();
      delta = (now - lastFrame) / 1000;
      lastFrame = now;
      frames += 1;
      commands = [];
      if (dirty > 0) dirty -= 1;
    }
    function endFrame() {
      pressed = new Set();
      mousePressed = new Set();
      lookX = 0; lookY = 0;
      wheelDelta = 0;
    }

    // Input arrives already normalized: the main thread owns the DOM, so it maps
    // a pointer into canvas space and names a key the way Unity's `Key` enum
    // does. Every event marks the surface dirty, which is what makes an
    // on-demand mod (a menu) redraw when — and only when — something happened.
    function input(ev) {
      touch();
      switch (ev.kind) {
        case "keydown":
          if (!held.has(ev.key)) pressed.add(ev.key);
          held.add(ev.key);
          if (ev.text) typed += ev.text;
          break;
        case "keyup": held.delete(ev.key); break;
        case "move":
          pointerX = ev.x; pointerY = ev.y;
          lookX += ev.dx || 0; lookY += ev.dy || 0;
          break;
        case "down":
          if (!mouseHeld.has(ev.button)) mousePressed.add(ev.button);
          mouseHeld.add(ev.button);
          break;
        case "up": mouseHeld.delete(ev.button); break;
        // A browser reports wheel movement in pixels and the SDK expects the
        // small per-click value a mouse reports (the shell's own comment says a
        // real click reads 0.01 to 0.03 there, and that it therefore moves a
        // fixed number of rows per EVENT rather than scaling by the magnitude).
        // So the sign and the fact of the turn are what matter.
        case "wheel": wheelDelta += ev.dy > 0 ? -0.02 : ev.dy < 0 ? 0.02 : 0; break;
      }
    }

    // Synthetic input, for a headless capture that has no mouse: the same edges
    // a real event would have set, consumed by the same frame.
    function press(x, y) { touch(); pointerX = x; pointerY = y; mousePressed.add("left"); }
    function key(name) { touch(); pressed.add(name); }

    return {
      dispatch, beginFrame, endFrame, paint, input, press, key, touch,
      animated: false,
      dirty: () => dirty > 0,
      // WHAT IS ACTUALLY ON THE SURFACE. `made.jester_draw_text` proves the mod
      // ASKED to draw; it does not prove anything reached the canvas, and those
      // are different failures with the same symptom — a blank rectangle. This
      // counts the commands the last frame recorded and samples the pixels that
      // came out of replaying them, so a gate can tell "the mod drew nothing"
      // from "the mod drew and the canvas never showed it".
      // WHAT THE SCREEN SAYS, as strings. A pixel count proves something was
      // drawn; it cannot tell a launcher from a "Delete this?" confirmation. The
      // painter already has every run of text for the last frame, so handing
      // them back costs nothing and lets a headless gate assert on the actual
      // words — which is the difference between "the shell rendered" and "the
      // shell rendered the thing it was supposed to".
      texts() {
        const out = [];
        for (const c of commands) if (c.kind === 1 && c.text) out.push(c.text);
        return out;
      },
      // THE SAME WORDS, WITH THE BOX THEY WERE DRAWN IN. `texts()` answers "did
      // the shell render the thing it was supposed to"; this answers "where do I
      // click to use it". A headless gate that can only assert on strings can
      // watch the launcher but not drive it, which is how the install path went
      // untested for as long as it did — there was no way to reach "Search
      // online" from outside. Every control in this UI is a label inside a
      // rectangle, so the label's rectangle is the control.
      textBoxes() {
        const out = [];
        for (const c of commands)
          if (c.kind === 1 && c.text)
            out.push({ text: c.text, x: c.x, y: c.y, w: c.w, h: c.h, size: c.size });
        return out;
      },
      probe() {
        let lit = 0, total = 0;
        try {
          const w = canvas.width, h = canvas.height;
          const data = ctx.getImageData(0, 0, w, h).data;
          for (let i = 0; i < data.length; i += 4 * 97) {     // a sparse sample
            total++;
            // Anything that is not the backdrop `#0b0d12`.
            if (Math.abs(data[i] - 0x0b) > 6 || Math.abs(data[i + 1] - 0x0d) > 6 ||
                Math.abs(data[i + 2] - 0x12) > 6) lit++;
          }
        } catch (e) { return { error: String(e && e.message || e) }; }
        return { commands: commands.length, frames, lit, total, size: canvas.width + "x" + canvas.height };
      },
      setPacks: (p) => { packs = p || []; touch(); },
      setPlaying: (id) => { playing = String(id || ""); touch(); },
      // A NEW MOD STARTS FROM A CLEAN SURFACE. Now that a quiet frame keeps the
      // last picture, the picture has to be thrown away deliberately somewhere —
      // and loading a different mod is that somewhere. Without this, a mod that
      // idles before its first draw shows the PREVIOUS mod's screen, which is
      // the most confusing possible failure: the right title bar over the wrong
      // game.
      reset: () => {
        commands = [];
        frames = 0;
        painting = true;
        ctx.fillStyle = "#0b0d12";
        ctx.fillRect(0, 0, canvas.width, canvas.height);
        painting = false;
        touch();
      },
      detach: () => { commands = []; },
      get declined() { return declined; },
      get made() { return made; },
      get keysAsked() { return keysAsked; },
      get keysHit() { return keysHit; },
      get mouseAsked() { return mouseAsked; },
      get mouseHit() { return mouseHit; },
      get packNameArgs() { return [...packNameArgs]; },
      // Exposed for `prove-fonts.mjs`: the name-table read is the part most
      // likely to be wrong for a font nobody tried, and it is pure, so it is
      // worth being able to test against real files without a browser.
      familyOf: (bytes) => familyFromFont(bytes),
      get playing() { return playing; },
      served: Object.keys(CALLS),
    };
  },
};
