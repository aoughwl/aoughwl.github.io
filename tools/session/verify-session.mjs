// verify-session.mjs — drive a real headless Chrome at the live-session layer
// and prove it end to end: worker boot, start, call, swap, drift, append, stop.
//
//   node tools/session/verify-session.mjs
//
// `prove-swap.mjs` already settles the INTERPRETER question in Node. What it
// cannot reach is everything this page added around it — a second Worker, the
// postMessage protocol, `session.js`'s state machine, the queued-swap rule. That
// plumbing is where a working interpreter still produces a broken page, so it
// gets its own gate, in the environment it actually runs in.
//
// The fixtures are the same two generations: tick() returns counter*1, then
// counter*100, so one number proves the code changed AND the state survived.
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { spawn, spawnSync } from "node:child_process";
import os from "node:os";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
// This gate serves its OWN page at `/` and the bundles beside it, so it is
// rooted at the playground folder rather than the site root.
const ROOT = path.resolve(HERE, "..", "..", "public", "playground");
const FIX = path.join(HERE, "fixture");
const TYPES = { ".html": "text/html", ".js": "text/javascript", ".json": "application/json",
                ".css": "text/css", ".bin": "application/octet-stream", ".nif": "text/plain" };

const b64 = (p) => fs.readFileSync(p).toString("base64");
const mainOf = (dir) => path.join(dir, fs.readdirSync(dir).find((f) => f.endsWith(".s.nif") && !f.startsWith("sys")));

// The page under test: the session layer, nothing else. It reports every step on
// `window.__result` so the driver reads a verdict rather than scraping a screen.
const PAGE = `<!doctype html><meta charset="utf-8"><title>session gate</title>
<script>
window.__log = [];
window.__result = null;
const say = (m) => { window.__log.push(m); };
</script>
<script src="session.js"></script>
<script type="module">
const latin1 = (b64) => atob(b64);
const V1 = latin1(${JSON.stringify(b64(mainOf(path.join(FIX, "nc_v1"))))});
const V2 = latin1(${JSON.stringify(b64(mainOf(path.join(FIX, "nc_v2"))))});
const V3 = latin1(${JSON.stringify(b64(mainOf(path.join(FIX, "nc_v3"))))});

const S = window.AowliSession;
const steps = [];
const check = (what, got, want) => steps.push({ what, got: String(got), want: String(want), ok: String(got) === String(want) });

(async () => {
  try {
    await S.whenReady();
    check("worker reports ready", S.state, "stopped");

    // fromBuffer says the EDITOR owns this session, which is what offer
    // requires before it republishes anything into it. Without it a live swap
    // could load whatever file happened to be open over a mod the editor never
    // compiled — which is what happened the day Live became the default, and
    // it took the shell apart within a second of the page settling. A gate for
    // offer has to claim that ownership the way the editor does.
    // (No backticks here: this whole page is a template literal.)
    let r = await S.start(V1, { runInit: false, fromBuffer: true });
    check("start", r.ok, true);
    check("state is live", S.state, "live");
    check("published tick", /tick/.test(r.bases || ""), true);

    const tick = async () => (await S.call("tick")).ret.v;
    check("first tick", await tick(), 1);
    check("second tick", await tick(), 2);

    r = await S.swap(V2);
    check("swap ok", r.ok, true);
    check("generation", S.gen, 1);
    check("tick after swap (code changed AND state kept)", await tick(), 300);

    // Live mode: offering the same bytes must NOT burn a generation, and
    // offering new ones must swap without anybody calling swap() by hand.
    S.setLive(true);
    S.offer(V2);
    await new Promise((r) => setTimeout(r, 120));
    check("offering identical bytes does not swap", S.gen, 1);
    S.offer(V1);
    await new Promise((r) => setTimeout(r, 250));
    check("offering new bytes swaps in Live mode", S.gen, 2);
    check("tick after the live swap", await tick(), 4);
    S.setLive(false);

    // Drift: v3 changes tick's arity. The swap still succeeds; what matters is
    // that the page is TOLD which symbol moved.
    r = await S.swap(V3);
    check("swap with changed arity succeeds", r.ok, true);
    check("drift is reported", /tick/.test(r.drift || ""), true);

    r = await S.stop();
    check("stopped", S.state, "stopped");
  } catch (e) {
    steps.push({ what: "threw", got: String(e && e.message || e), want: "no throw", ok: false });
  }
  window.__result = steps;
})();
</script>`;

let server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "");
  if (rel === "" || rel === "gate.html") {
    res.writeHead(200, { "content-type": "text/html" }); res.end(PAGE); return;
  }
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) {
    res.writeHead(404); res.end("no"); return;
  }
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  res.end(fs.readFileSync(file));
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/gate.html`;

const CHROME = process.env.CHROME || "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "sess-gate-"));
const port = 9700 + (process.pid % 200);
const chrome = spawn(CHROME, ["--headless=new", "--disable-gpu", "--no-first-run",
  "--no-default-browser-check", `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`,
  "--window-size=1000,800", "about:blank"], { stdio: "ignore" });

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
let seq = 0; const waiting = new Map(); const consoleErrors = [];
ws.onmessage = (ev) => {
  const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); return; }
  if (m.method === "Runtime.exceptionThrown")
    consoleErrors.push(m.params.exceptionDetails.exception?.description || m.params.exceptionDetails.text);
};
const cmd = (method, params) => new Promise((r) => { const id = ++seq; waiting.set(id, r); ws.send(JSON.stringify({ id, method, params })); });
const evaluate = async (expr) => (await cmd("Runtime.evaluate", { expression: expr, returnByValue: true, awaitPromise: true })).result?.result?.value;

await cmd("Runtime.enable", {});
await cmd("Page.enable", {});
await cmd("Page.navigate", { url: site });

let steps = null;
for (let i = 0; i < 900; i++) {                       // the bundle is 9.5 MB; give it time
  steps = await evaluate("window.__result");
  if (steps) break;
  await new Promise((r) => setTimeout(r, 200));
}

let failed = 0;
if (!steps) {
  console.error("FAIL: the page never produced a result (engine never booted?)");
  failed = 1;
} else {
  for (const s of steps) {
    console.log(`${s.ok ? "  ok  " : "  FAIL"}  ${s.what}: ${s.got}${s.ok ? "" : "  (expected " + s.want + ")"}`);
    if (!s.ok) failed++;
  }
}
for (const e of consoleErrors) console.error("  page error: " + String(e).split("\n")[0]);

killChrome(chrome);
server.close();
console.log(failed ? `\nFAILED: ${failed} check(s)` : "\nPASS: the live session works in a browser.");
process.exit(failed ? 1 : 0);
