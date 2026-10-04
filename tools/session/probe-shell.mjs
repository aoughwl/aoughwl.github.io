// probe-shell.mjs — boot the shell, touch NOTHING, and print what is on screen.
//
//   node tools/session/probe-shell.mjs
//
// A one-shot diagnostic rather than a gate. The reported symptom is that opening
// the panel and pressing Start lands straight in a "Delete …?" confirmation and
// then plays something nobody chose, so the question is what the launcher draws
// and what it asks the host for when it is left completely alone.
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
const TYPES = { ".html": "text/html", ".js": "text/javascript", ".json": "application/json",
                ".css": "text/css", ".bin": "application/octet-stream", ".ico": "image/x-icon",
                ".png": "image/png", ".svg": "image/svg+xml" };
const server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "") || "index.html";
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) { res.writeHead(404); res.end("no"); return; }
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  res.end(fs.readFileSync(file));
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/playground/index.html`;

const CHROME = process.env.CHROME || "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jx-probe-"));
const port = 9910 + (process.pid % 30);
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
    try { const l = await (await fetch(`http://127.0.0.1:${port}/json/list`)).json();
          const p = l.find((t) => t.type === "page"); if (p) return p; } catch (_) {}
    await new Promise((r) => setTimeout(r, 100));
  }
  throw new Error("no debugging port");
}
const target = await firstPage();
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
let seq = 0; const waiting = new Map();
ws.onmessage = (e) => { const m = JSON.parse(e.data); if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); } };
const cmd = (m, p) => new Promise((r) => { const id = ++seq; waiting.set(id, r); ws.send(JSON.stringify({ id, method: m, params: p })); });
const ev = async (x) => (await cmd("Runtime.evaluate", { expression: x, returnByValue: true, awaitPromise: true })).result?.result?.value;
async function waitFor(x, ms = 180000) {
  const until = Date.now() + ms;
  while (Date.now() < until) { if (await ev(x) === true) return true; await new Promise((r) => setTimeout(r, 250)); }
  return false;
}

await cmd("Runtime.enable", {});
await cmd("Page.enable", {});
await cmd("Page.navigate", { url: site });
await waitFor("!!(window.AowliSession && window.AowliSession.state)");
if (process.env.NO_POINTER) await ev("window.__noSyntheticPointer = true");
if (process.env.NO_PACKS) await ev("window.AowliSession.setPacks([])");
await ev("document.querySelector('#tabJester').click()");
await ev("document.querySelector('#jxStart').click()");
await waitFor("window.AowliSession.state === 'live'");

// Ask the shell's own module the enum questions directly.
{
  const call = async (n) => await ev(`window.AowliSession.call(${JSON.stringify(n)}).then(r => r.ret && "v" in r.ret ? r.ret.v : "(" + (r.ret && r.ret.k) + ")")`);
  console.log("\n-- enum, inside the shell's own module --");
  console.log("  ord(None,Delete,Edit,Duplicate) packed: " + await call("dbgOrds") + "   (expect 3210)");
  console.log("  RowNone compared to all four (bitmask): " + await call("dbgEnumProbe") + "   (expect 1)");
  console.log("  each value vs its own literal:          " + await call("dbgRowActionRoundTrip") + "   (expect 1111)");
  console.log("  a FRESH enum declared beside it:        " + await call("dbgFreshOrds") + "   (expect 3210)");
  console.log("  QPhase + MenuKind ordinals:             " + await call("dbgOtherOrds") + "   (expect 210210)");
  // The same two questions in a SMALL mod built the same way (build_mod, against
  // the ModSdk). If this one is right and the launcher is wrong, the pipeline is
  // not the variable.
  await ev(`window.JesterPanel.play("jester.2048")`);
  await new Promise((r) => setTimeout(r, 1500));
  console.log("  [2048] ord(PA,PB,PC,PD) packed:         " + await call("enumOrds") + "   (expect 3210)");
  console.log("  [2048] PA compared to all four:         " + await call("enumMask") + "   (expect 1)");
}

for (const wait of [1200, 2500, 4000]) {
  await new Promise((r) => setTimeout(r, wait === 1200 ? 1200 : 1300));
  const s = await ev("window.AowliSession.stats().then(s => JSON.stringify({texts:s.texts, playing:s.playing, made:s.made, keysAsked:s.keysAsked, keysHit:s.keysHit, mouseAsked:s.mouseAsked, mouseHit:s.mouseHit, packNameArgs:s.packNameArgs, declined:s.declined}))");
  const st = JSON.parse(s || "{}");
  console.log(`\n--- after ~${wait} ms ---`);
  console.log("playing: " + JSON.stringify(st.playing));
  console.log("on screen: " + JSON.stringify(st.texts));
  const mouse = Object.entries(st.made || {}).filter(([k]) => /mouse|pointer/.test(k));
  console.log("mouse/pointer calls: " + JSON.stringify(Object.fromEntries(mouse)));
  console.log("keys asked: " + Object.keys(st.keysAsked || {}).join(", "));
  console.log("keys that HIT: " + JSON.stringify(st.keysHit || {}));
  console.log("DECLINED: " + Object.keys(st.declined || {}).join(", "));
  console.log("pack_name asked for indices: " + JSON.stringify(st.packNameArgs || []));
  console.log("mouse asked: " + JSON.stringify(st.mouseAsked || {}) + "   HIT: " + JSON.stringify(st.mouseHit || {}));
}
console.log("\npanel log:\n" + String(await ev("document.querySelector('#jxLog').textContent")).slice(0, 600));

killChrome(chrome);
server.close();
process.exit(0);
