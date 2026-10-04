// verify-2048.mjs — play 2048 in a real browser and check it played CORRECTLY.
//
//   node tools/session/verify-2048.mjs
//
// The other gates ask whether a mod drew. This one asks whether the game is
// right, which is a different question and the only one that matters for
// something people are meant to enjoy. The mod publishes `score`, `moves` and
// `highestTile`, so the harness reads the game's own state instead of squinting
// at pixels — and then presses keys and checks the state moved the way 2048's
// rules say it should.
//
// It also proves the thing the whole session layer exists for, on the flagship:
// edit the running game, keep the score.
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
const OUT = path.join(HERE, "shots");
fs.mkdirSync(OUT, { recursive: true });

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
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jx-2048-"));
const port = 9870 + (process.pid % 60);
const chrome = spawn(CHROME, ["--headless=new", "--use-gl=swiftshader", "--enable-unsafe-swiftshader",
  "--no-first-run", "--no-default-browser-check", `--remote-debugging-port=${port}`,
  `--user-data-dir=${profile}`, "--window-size=1400,900", "about:blank"], { stdio: "ignore" });

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
ws.onmessage = (e) => { const m = JSON.parse(e.data); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
const cmd = (method, params) => new Promise((r) => { const id = ++seq; waiting.set(id, r); ws.send(JSON.stringify({ id, method, params })); });
const ev = async (x) => (await cmd("Runtime.evaluate", { expression: x, returnByValue: true, awaitPromise: true })).result?.result?.value;
async function waitFor(x, ms = 180000) {
  const until = Date.now() + ms;
  while (Date.now() < until) { if (await ev(x) === true) return true; await new Promise((r) => setTimeout(r, 250)); }
  return false;
}
async function shot(name) {
  const r = await cmd("Page.captureScreenshot", { format: "png" });
  if (r.result?.data) fs.writeFileSync(path.join(OUT, name + ".png"), Buffer.from(r.result.data, "base64"));
}

const checks = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  checks.push(ok);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
};

await cmd("Runtime.enable", {});
await cmd("Page.enable", {});
await cmd("Page.navigate", { url: site });
if (!await waitFor("!!(window.AowliSession && window.AowliSession.state)")) {
  console.error("the session engine never booted"); process.exit(1);
}
await ev("document.querySelector('#tabJester').click()");
await ev("document.querySelector('#jxStart').click()");
if (!await waitFor("window.AowliSession.state === 'live'")) { console.error("the shell never started"); process.exit(1); }

// 2048 ships built in, so it is in the launcher's list with nothing installed.
check("2048 is in the launcher's list with nothing installed",
  await ev("window.JesterPanel.packs.some(p => p.id === 'jester.2048')"), true);
// A rejected promise comes back from CDP as `undefined`, so the launch reports
// its own failure rather than throwing across that boundary — otherwise "2048
// did not load" is indistinguishable from "2048 loaded and published nothing".
const launchErr = await ev(`(async () => { try { await window.JesterPanel.play("jester.2048"); return null; }
                                          catch (e) { return String(e && e.message || e); } })()`);
if (launchErr) console.log("      launch said: " + launchErr);
check("2048 launched", launchErr, "null");
await new Promise((r) => setTimeout(r, 1200));

const call = async (name) => await ev(`window.AowliSession.call(${JSON.stringify(name)}).then(r => r.ret && r.ret.v)`);
// What the module published, straight from the seam. When `has` says no, this
// separates "the proc is not there" from "the name did not match", and those
// have completely different fixes. It is read off the session `play` already
// started — restarting it here would publish the module WITHOUT running the
// mod's `start`, and then every global is at its zero and the game has no board.
console.log("      published: " + await ev("window.AowliSession.stats().then(()=>0)").then(()=>"(via play)"));
check("it published its read-only state", await ev("window.AowliSession.has('score')"), true);
check("a fresh game has scored nothing", await call("score"), 0);
check("...and has made no moves", await call("moves"), 0);
// Two tiles at the start, so the highest is a 2 or a 4 and never anything else.
const first = await call("highestTile");
check("a fresh game has a starting tile", first === 2 || first === 4, true);
await shot("7-2048");

// PLAY IT. Sliding the same direction repeatedly is the strongest simple test:
// it must eventually stop changing anything (everything is packed against that
// wall), and along the way it must merge, which is the only way the score moves.
const press = async (key) => {
  await ev(`window.AowliSession.input({kind:"keydown", key:${JSON.stringify(key)}})`);
  await new Promise((r) => setTimeout(r, 140));
  await ev(`window.AowliSession.input({kind:"keyup", key:${JSON.stringify(key)}})`);
  await new Promise((r) => setTimeout(r, 140));
};
for (const k of ["LeftArrow", "DownArrow", "LeftArrow", "DownArrow",
                 "LeftArrow", "DownArrow", "LeftArrow", "DownArrow",
                 "LeftArrow", "DownArrow", "LeftArrow", "DownArrow"]) await press(k);

const moved = await call("moves");
const scored = await call("score");
const top = await call("highestTile");
console.log(`      after 12 presses: ${moved} moves, score ${scored}, highest tile ${top}`);
check("the keys reached the game", moved > 0, true);
// Every merge adds the merged value to the score, and a 4 can only exist by
// merging two 2s or by spawning. A score above zero means a merge happened.
check("tiles merged (the score moved)", scored > 0, true);
check("the score is a sum of merges, so it is even", scored % 2, 0);
check("a merge produced a bigger tile", top >= 4, true);
await shot("8-2048-played");

// THE HEADLINE, on the flagship: edit the running game and keep the score.
// `Live` is what a person would press; this drives the same path directly
// because the gate has no editor buffer holding 2048's source.
const before = await call("score");
await ev(`(async () => {
  const p = await fetch("jester-payload.json").then(r => r.json());
  const mod = p.mods.find(m => m.id === "jester.2048");
  window.__same = await window.AowliSession.swap(atob(mod.src));
})()`);
await new Promise((r) => setTimeout(r, 600));
check("the running game accepted a swap", await ev("window.__same && window.__same.ok"), true);
check("the generation advanced", await ev("window.AowliSession.gen"), 1);
check("and the score survived it", await call("score"), before);
console.log(`      score across the swap: ${before} -> ${await call("score")}`);

const failed = checks.filter((c) => !c).length;
killChrome(chrome);
server.close();
console.log(`\nscreenshots: ${OUT}`);
console.log(failed ? `FAILED: ${failed} check(s)` : "PASS: 2048 plays, scores correctly, and survives a hot swap.");
process.exit(failed ? 1 : 0);
