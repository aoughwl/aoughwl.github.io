// triage-mods.mjs — decide which mods a browser can actually serve, by RUNNING
// each one and watching what it asks for.
//
//   node tools/session/triage-mods.mjs            every mod in the registry
//   node tools/session/triage-mods.mjs aoughwl.web  just this one
//   node tools/session/triage-mods.mjs --write     …and record the verdicts
//
// WHY THIS IS NOT A LIST IN A FILE. Which host calls a mod reaches is a CALL
// GRAPH: the mod calls `text()` in the SDK, which calls `jester_draw_text`, and
// no amount of reading the mod's own artifact reveals that. Every static guess
// at "this one probably works" is the brittle-heuristic shape — a hardcoded set
// of ids that goes stale the first time a mod changes what it draws.
//
// So the question is answered the only way it can be answered honestly: load the
// mod in a real browser, let it run, and read the host's own tally of what it
// SERVED and what it had to DECLINE. A mod that drew pixels and declined nothing
// works here. One that declined a family it needs is named, with the family, so
// the gap is a to-do rather than a mystery.
//
// The verdicts are written back into `jester-registry.json` as `browser` and
// `declines`, so the store can tell a visitor what they are about to install.
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { spawn, spawnSync } from "node:child_process";
import os from "node:os";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
// The SITE root, not the playground folder: VitePress copies `public/` to the
// root of the deployed site, so the playground is at `/playground/` there and
// the shell's mod registry names an absolute url under that path. A harness
// rooted at `public/playground` cannot serve its own content set.
const ROOT = path.resolve(HERE, "..", "..", "public");
const REG = path.join(ROOT, "jester-registry.json");
const argv = process.argv.slice(2);
const WRITE = argv.includes("--write");
const ONLY = argv.filter((a) => !a.startsWith("--"));

const TYPES = { ".html": "text/html", ".js": "text/javascript", ".json": "application/json",
                ".css": "text/css", ".bin": "application/octet-stream", ".ico": "image/x-icon",
                ".png": "image/png", ".svg": "image/svg+xml" };
const server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "") || "index.html";
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) {
    res.writeHead(404); res.end("no"); return;
  }
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  res.end(fs.readFileSync(file));
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/playground/index.html`;

const CHROME = process.env.CHROME || "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jx-triage-"));
const port = 9950 + (process.pid % 40);
const chrome = spawn(CHROME, ["--headless=new", "--use-gl=swiftshader",
  "--enable-unsafe-swiftshader", "--no-first-run",
  "--no-default-browser-check", `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`,
  "--window-size=1200,860", "about:blank"], { stdio: "ignore" });

// Killing the spawned chrome is not enough on Windows: `--headless=new` starts a
// browser process that forks renderer and GPU children, and `kill()` reaps only
// the parent. Left alone they accumulate — a session of repeated runs had 101 of
// them alive, and they collide on the debugging ports the next run tries to use,
// which shows up as the mystifying "chrome never opened a debugging port" or a
// page that never boots. Take the whole tree.
function killChrome(child) {
  try { child.kill(); } catch (_) {}
  if (process.platform === "win32" && child.pid) {
    try { spawnSync("taskkill", ["/F", "/T", "/PID", String(child.pid)], { stdio: "ignore" }); } catch (_) {}
  }
}


async function firstPage() {
  for (let i = 0; i < 150; i++) {
    try {
      const list = await (await fetch(`http://127.0.0.1:${port}/json/list`)).json();
      const p = list.find((t) => t.type === "page");
      if (p) return p;
    } catch (_) {}
    await new Promise((r) => setTimeout(r, 100));
  }
  throw new Error("chrome never opened a debugging port");
}
const target = await firstPage();
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
let seq = 0; const waiting = new Map();
ws.onmessage = (ev) => {
  const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); }
};
const cmd = (method, params) => new Promise((r) => { const id = ++seq; waiting.set(id, r); ws.send(JSON.stringify({ id, method, params })); });
const ev = async (expr) => (await cmd("Runtime.evaluate", { expression: expr, returnByValue: true, awaitPromise: true })).result?.result?.value;
async function waitFor(expr, ms = 180000) {
  const until = Date.now() + ms;
  while (Date.now() < until) {
    if (await ev(expr) === true) return true;
    await new Promise((r) => setTimeout(r, 250));
  }
  return false;
}

await cmd("Runtime.enable", {});
await cmd("Page.enable", {});
await cmd("Page.navigate", { url: site });
if (!await waitFor("!!(window.AowliSession && window.AowliSession.state)")) {
  console.error("the session engine never booted"); killChrome(chrome); server.close(); process.exit(1);
}
await ev("document.querySelector('#tabJester').click()");
await ev("document.querySelector('#jxStart').click()");
if (!await waitFor("window.AowliSession.state === 'live'")) {
  // Say WHAT the page got stuck on. "never started" with no detail sent me
  // hunting a payload bug that was really a port collision.
  console.error("the shell never started; state=" + await ev("window.AowliSession && window.AowliSession.state") +
                " status=" + JSON.stringify(await ev("document.querySelector('#jxStatus') && document.querySelector('#jxStatus').textContent")) +
                " log=" + JSON.stringify(String(await ev("document.querySelector('#jxLog') && document.querySelector('#jxLog').textContent")).slice(-300)));
  killChrome(chrome); server.close(); process.exit(1);
}

const registry = JSON.parse(fs.readFileSync(REG, "utf8"));
const wanted = registry.mods.filter((m) => !ONLY.length || ONLY.includes(m.id));
console.log(`triaging ${wanted.length} mod(s)\n`);

const CEILING = 1 << 30;   // aowli's browser heap, the runtime's own number

const familyOf = (call) => {
  const p = String(call).split("_");
  return p.length > 2 ? p[1] : p[1] || call;
};

for (const entry of wanted) {
  process.stdout.write(entry.id.padEnd(24));
  // Install (if it is not already) and play it. Each mod gets a FRESH host tally
  // by re-attaching is not possible — the canvas transfers once — so the tally is
  // read before and after and the difference is this mod's.
  const before = await ev("window.AowliSession.stats().then(s => JSON.stringify({made:s.made, declined:s.declined}))");
  const b = JSON.parse(before || "{}");
  // The evaluation reports its OWN failure rather than throwing across the CDP
  // boundary, where a rejected promise comes back as `undefined` and a mod that
  // never loaded looks exactly like a mod that drew nothing.
  const err = await ev(`(async () => {
    try {
      if (!window.JesterPanel.packs.some(p => p.id === ${JSON.stringify(entry.id)}))
        await window.JesterStore.install(${JSON.stringify(entry.url)});
      await window.JesterPanel.play(${JSON.stringify(entry.id)});
      return null;
    } catch (e) { return String(e && e.message || e); }
  })()`);
  // Wake it and let it draw. `jester.app` ends `openApp` with
  // `idleWhenQuiet()`, so an application redraws when something HAPPENS — a
  // mod poked by nothing at all is entitled to draw nothing, and judging it
  // for that would be judging the harness. A pointer move is the smallest
  // honest poke.
  await new Promise((r) => setTimeout(r, 700));
  for (let i = 0; i < 4; i++) {
    await ev(`window.AowliSession.input({kind:"move", x:${120 + i * 60}, y:${90 + i * 40}, dx:6, dy:4})`);
    await new Promise((r) => setTimeout(r, 400));
  }
  await new Promise((r) => setTimeout(r, 600));
  const after = JSON.parse(await ev("window.AowliSession.stats().then(s => JSON.stringify({made:s.made, declined:s.declined, probe:s.probe, live:s.playing}))") || "{}");

  const delta = (now, then) => {
    const out = {};
    for (const [k, v] of Object.entries(now || {})) {
      const d = v - ((then || {})[k] || 0);
      if (d > 0) out[k] = d;
    }
    return out;
  };
  const made = delta(after.made, b.made);
  const declined = delta(after.declined, b.declined);
  const drew = Object.keys(made).some((k) => /_draw_|_ui_/.test(k));
  const lit = after.probe ? after.probe.lit / Math.max(1, after.probe.total) : 0;
  const families = [...new Set(Object.keys(declined).map(familyOf))];
  const heapBytes = await ev("window.AowliSession.heap");

  // The verdict. "works" is not "it loaded": it has to have DRAWN, and the
  // surface has to show it.
  //
  // `toobig` is its own answer rather than a kind of failure. aowli's browser
  // heap is a fixed 1 GiB linear buffer with no collector, and a mod carrying a
  // layout engine can want more than all of it — `aoughwl.web` reaches the
  // ceiling with nothing else loaded. That is not the mod being broken and it is
  // not the host declining anything; it is a size limit, and calling it "draws
  // nothing" would send someone looking for a drawing bug that is not there.
  const oom = heapBytes >= CEILING * 0.95;
  const verdict = oom ? "toobig"
    : err ? "error"
    : (drew && lit > 0.02) ? (families.length ? "partial" : "works")
    : "blank";
  entry.browser = verdict;
  entry.declines = families;

  if (process.env.TRIAGE_DEBUG) {
    console.log("\n      state=" + await ev("window.AowliSession.state") +
                " gen=" + await ev("window.AowliSession.gen") +
                " where=" + JSON.stringify(await ev("document.querySelector('#jxWhere').textContent")));
    console.log("      probe: " + JSON.stringify(after.probe));
    console.log("      made: " + JSON.stringify(made));
    console.log("      log: " + String(await ev("document.querySelector('#jxLog').textContent")).slice(-400));
  }
  const mb = (heapBytes / (1024 * 1024)).toFixed(0);
  const pct = (lit * 100).toFixed(0) + "%";
  console.log(`${verdict.padEnd(8)} surface ${pct.padStart(4)}  heap ${String(mb).padStart(4)} MB` +
    (families.length ? `   declines: ${families.join(", ")}` : "") +
    (err ? `   ${err.slice(0, 80)}` : ""));

  // Nothing is played between mods: `start` already resets the surface, and
  // bouncing through another mod first only adds a load whose own idling could
  // be mistaken for the next mod's.
  await ev("window.AowliSession.setPlaying('')");
}

if (WRITE) {
  fs.writeFileSync(REG, JSON.stringify(registry, null, 2));
  console.log(`\nwrote verdicts into ${path.relative(process.cwd(), REG)}`);
} else {
  console.log("\n(run with --write to record these in the registry)");
}

killChrome(chrome);
server.close();
process.exit(0);
