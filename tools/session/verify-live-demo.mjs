// verify-live-demo.mjs — does a PLAIN program keep its state across an edit?
//
//   node tools/session/verify-live-demo.mjs
//
// Hot-loading is a property of the interpreter this whole page is built on: a
// program can stay running while its code changes underneath it. This gate says
// the playground actually shows that, for a plain program.
//
// `scratch/liveDemo.nim` is the file that shows it and this is the gate that
// says the file is telling the truth. It walks exactly what that file asks the
// reader to do, through the debugger drawer's Live tab (live.js):
//
//   1. Press Go live. The drawer opens on Live, the file runs once, and STATE
//      shows the program's variables read out of the running interpreter.
//   2. Change a proc WITHOUT pressing anything. The clean type-check swaps
//      itself in, HISTORY names the proc it edited, and STATE does not move.
//   3. Type a statement into the drawer's prompt. It is appended to the file and
//      ONLY that line executes, in the NEW version of the proc, against the OLD
//      counter.
//   4. Press the call button beside recap(). It runs against the same state.
//
// Step 3 is the whole claim and the one that cannot be faked: if the session
// had restarted, the counter would read 1 instead of 3. And an edit to a
// DIFFERENT open file must never reach the running program - the guard the
// drawer adds, checked here too.
"use strict";
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
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jx-live-"));
const port = 9640 + (process.pid % 60);
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
const pageErrors = [];
await cmd("Log.enable", {});
await cmd("Page.navigate", { url: site });
if (!await waitFor("!!(window.AowliSession && window.AowliSession.state)")) {
  console.error("the session engine never booted"); process.exit(1);
}
if (!await waitFor("!!(window.AowliParser && window.AowliParser.ready && window.AowliSem && window.AowliSem.ready)")) {
  console.error("the toolchain never finished loading"); process.exit(1);
}

// ---- the file is there, beside helloWorld -----------------------------------
check("scratch ships liveDemo.nim beside helloWorld.nim", await ev(`(() => {
  const p = window.AowliWorkspace.projectByName("scratch");
  if (!p) return "no scratch project";
  return ["helloWorld.nim", "liveDemo.nim"].every(f => p.files.get(f)) ? "yes" : "missing one";
})()`), "yes");

// Open it.
await ev(`(() => { const p = window.AowliWorkspace.projectByName("scratch");
  window.AowliWorkspace.openFile(p.id, "liveDemo.nim", true); })()`);
await new Promise((r) => setTimeout(r, 2500));
check("Live is armed by default", await ev("window.AowliSession.liveMode"), true);
check("...and nothing is running yet", await ev("window.AowliSession.state"), "stopped");
check("the header offers to go live", await ev("document.querySelector('#liveTopBtn .lbl').textContent"), "Go live");

const L = "window.AowliLive";
const lastEv = (k) => ev(`(() => { const e = ${L}.events.filter(e => e.kind === ${JSON.stringify(k)}).pop(); return e ? JSON.stringify(e) : null; })()`).then(x => x ? JSON.parse(x) : null);
const glob = (n) => ev(`(() => { const g = ${L}.globals.find(g => g.n === ${JSON.stringify(n)}); return g ? g.v : null; })()`);

// ---- 1. go live -------------------------------------------------------------
await ev("document.querySelector('#liveTopBtn').click()");
check("Go live stands an interpreter up", await waitFor("window.AowliSession.state !== 'stopped'", 120000), true);
check("...and the drawer opens on its Live tab", await waitFor("window.AowliDebugger.isVisible() && window.AowliDebugger.mode === 'live'", 10000), true);
await waitFor(`${L}.events.some(e => e.kind === "start") && ${L}.globals.length > 0`, 120000);
const start = await lastEv("start");
check("...its top level ran, in one start event", !!(start && start.ok && /counted 1: first[\s\S]*counted 2: second/.test(start.out)), true);
check("...which the drawer calls v1", start && start.vl, "v1");
check("STATE reads hits out of the running program", await glob("hits"), "2");
check("STATE reads seen too", await glob("seen"), "@[first, second]");
check("the header says it is live", await ev("document.querySelector('#liveTopBtn .lbl').textContent"), "Live · v1");
check("Run now means run new lines", await ev("document.querySelector('#runLabel').textContent"), "Run new lines");
await shot("live-1-standing");

// ---- 2. change a proc, press NOTHING ----------------------------------------
// The word in the echo is what changes, so the next line that runs proves which
// version of `note` executed.
// THE FILE AND THE EDITOR TOGETHER, and never `openFile` to apply an edit.
//
// `openFile` FLUSHES the editor into the file before it loads it, so writing the
// file and then opening it writes the editor's older text straight back over
// what was just written. Setting both, with the editor last, leaves them
// agreeing whichever way the flush goes.
await ev(`(() => {
  const w = window.AowliWorkspace, p = w.projectByName("scratch");
  const text = w.readFile(p.id, "liveDemo.nim").replace('"  counted "', '"  TALLIED "');
  w.writeFile(p.id, "liveDemo.nim", text);
  window.AowliEditor.setValue(text);
})()`);
check("editing alone swaps into the running interpreter",
      await waitFor(`${L}.events.some(e => e.kind === "swap" && e.ok)`, 120000), true);
const swap = await lastEv("swap");
check("...HISTORY names exactly the proc that was edited", swap && JSON.stringify(swap.changes.edited), '["note"]');
check("...as v2", swap && swap.vl, "v2");
await waitFor(`${L}.globals.length > 0`, 5000);
check("...and STATE did not move", await glob("hits"), "2");
check("PROCS marks note as edited", await ev(`!!document.querySelector('[data-proc="note"] .lv-tag.edit')`), true);

// ---- 3. a statement from the prompt -----------------------------------------
await ev(`(() => { const i = document.querySelector('[data-lv="con"]'); i.value = 'note "third"';
  i.dispatchEvent(new KeyboardEvent("keydown", { key: "Enter", bubbles: true })); })()`);
await waitFor(`${L}.events.some(e => e.kind === "append")`, 120000);
const app = await lastEv("append");
console.log("      the prompt ran: " + JSON.stringify(app && app.out));
// THE CLAIM. `3` can only come from the counter that was already there, and
// `TALLIED` can only come from the proc that was edited after it started. One
// line carries both halves.
check("only the typed line ran, against the state that was already there", !!(app && app.ok && /TALLIED 3: third/.test(app.out)), true);
check("...and it did not re-run the lines above it", !!(app && /first|second/.test(app.out)), false);
check("...it ran exactly one statement", app && app.ran, 1);
check("...and the file now ends with it", await ev(`/note "third"\\n$/.test(window.AowliEditor.getValue())`), true);
await waitFor(`${L}.globals.some(g => g.n === "hits" && g.v === "3")`, 5000);
check("STATE shows the counter moved", await glob("hits"), "3");

// ---- 4. call a proc ---------------------------------------------------------
await ev(`document.querySelector('[data-call="recap"]').click()`);
await waitFor(`${L}.events.some(e => e.kind === "call")`, 60000);
const call = await lastEv("call");
check("the call button ran recap() against the live state", !!(call && call.ok && /so far: 3 item\(s\)[\s\S]*third/.test(call.out)), true);
await shot("live-2-appended");

// ---- another file's edits never reach it ------------------------------------
const genBefore = await ev("window.AowliSession.gen");
await ev(`(() => { const w = window.AowliWorkspace, p = w.projectByName("scratch"); w.openFile(p.id, "helloWorld.nim", true); })()`);
await new Promise((r) => setTimeout(r, 1500));
await ev(`window.AowliEditor.setValue(window.AowliEditor.getValue() + "\\necho 1\\n")`);
await new Promise((r) => setTimeout(r, 4000));
check("an edit to another file does not swap into the running program", await ev("window.AowliSession.gen"), genBefore);
check("...and Run goes back to meaning Run", await ev("document.querySelector('#runLabel').textContent"), "Run");
await ev(`(() => { const w = window.AowliWorkspace, p = w.projectByName("scratch"); w.openFile(p.id, "liveDemo.nim", true); })()`);
await new Promise((r) => setTimeout(r, 1000));

// ---- and it can be put away --------------------------------------------------
await ev(`document.querySelector('[data-lv="stop"]').click()`);
await waitFor("window.AowliSession.state === 'stopped'", 10000);
check("Stop drops the session", await ev("window.AowliSession.state"), "stopped");
check("...and the header offers to go live again", await ev("document.querySelector('#liveTopBtn .lbl').textContent"), "Go live");

const failed = checks.filter((c) => !c).length;
killChrome(chrome);
server.close();
console.log(failed ? `\nFAILED: ${failed} check(s)` : "\nPASS: a plain program keeps its state across an edit, and the Live tab shows it.");
process.exit(failed ? 1 : 0);
