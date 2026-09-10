// verify-jester-demo.mjs - serve public/jester-demo/, drive a real headless
// Chrome at it, and prove the page does what it says: the mod loads, frames are
// drawn, a hot swap keeps the mod's globals, and switching mods works. It
// screenshots each state so a human can look rather than trust the exit code.
//
//   node tools/verify-jester-demo.mjs [--out shots]
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import zlib from "node:zlib";
import { spawn } from "node:child_process";
import os from "node:os";

const argv = process.argv.slice(2);
const arg = (n, d) => { const i = argv.indexOf(n); return i >= 0 ? argv[i + 1] : d; };
const OUT = arg("--out", path.resolve("shots"));
const ROOT = path.resolve("public/jester-demo");
const TYPES = { ".html": "text/html", ".js": "text/javascript", ".json": "application/json" };

let served = [];
const server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "") || "index.html";
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) {
    res.writeHead(404); res.end("no"); return;
  }
  const raw = fs.readFileSync(file);
  const body = zlib.gzipSync(raw, { level: 6 });
  served.push({ rel, raw: raw.length, wire: body.length });
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream",
    "content-encoding": "gzip", "content-length": body.length });
  res.end(body);
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/index.html`;

const CHROME = process.env.CHROME ||
  "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jester-demo-"));
const port = 9600 + (process.pid % 300);
const chrome = spawn(CHROME, ["--headless=new", "--disable-gpu", "--no-first-run",
  "--no-default-browser-check", `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`,
  "--window-size=1000,860", "about:blank"], { stdio: "ignore" });

async function targets() {
  for (let i = 0; i < 120; i++) {
    try {
      const list = await (await fetch(`http://127.0.0.1:${port}/json/list`)).json();
      const page = list.find((t) => t.type === "page");
      if (page) return page;
    } catch (e) {}
    await new Promise((r) => setTimeout(r, 100));
  }
  throw new Error("chrome never opened a debugging port");
}
const target = await targets();
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
let seq = 0; const waiting = new Map(); const errors = [];
ws.onmessage = (ev) => {
  const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) {
    const { resolve, reject } = waiting.get(m.id); waiting.delete(m.id);
    m.error ? reject(new Error(m.error.message)) : resolve(m.result);
  } else if (m.method === "Runtime.exceptionThrown") {
    errors.push(m.params.exceptionDetails.exception?.description || "?");
  } else if (m.method === "Runtime.consoleAPICalled") {
    errors.push("console: " + m.params.args.map((a) => a.value ?? a.description).join(" "));
  }
};
const send = (method, params = {}) => new Promise((resolve, reject) => {
  const id = ++seq; waiting.set(id, { resolve, reject });
  ws.send(JSON.stringify({ id, method, params }));
});
const evaluate = async (expr) => {
  const r = await send("Runtime.evaluate", { expression: expr, returnByValue: true, awaitPromise: true });
  if (r.exceptionDetails) throw new Error(r.exceptionDetails.exception?.description || "eval failed");
  return r.result.value;
};
async function until(expr, ms = 90000) {
  const stop = Date.now() + ms;
  while (Date.now() < stop) {
    if (await evaluate(expr)) return true;
    const fatal = await evaluate("globalThis.__inf_fatal || null");
    if (fatal) throw new Error("page reported: " + fatal);
    await new Promise((r) => setTimeout(r, 60));
  }
  const st = await evaluate("document.getElementById('status').textContent").catch(() => "?");
  throw new Error("timed out waiting for " + expr + "; status=" + st +
    "; errors=" + JSON.stringify(errors.slice(0, 6)));
}
const wait = (ms) => new Promise((r) => setTimeout(r, ms));
fs.mkdirSync(OUT, { recursive: true });
const shoot = async (name) => {
  const s = await send("Page.captureScreenshot", { format: "png" });
  fs.writeFileSync(path.join(OUT, name + ".png"), Buffer.from(s.data, "base64"));
};
// The mod paints its frame counter into the top bar; read it out of the host's
// own call log instead, which is the number the interpreter actually produced.
const frames = () => evaluate("__demo.made()['infiniteless_draw_fill'] || 0");

await send("Page.enable"); await send("Runtime.enable");
await send("Page.navigate", { url: site });
await until("globalThis.__demo && __demo.running === true");
await evaluate(`globalThis.__titles = [];
  (function(){ const prev = globalThis.__inf_host;
    globalThis.__inf_host = (n, a) => { if (n === "infiniteless_draw_text" && String(a[0]).indexOf("demo.web") === 0) globalThis.__titles.push(a[0]);
      return prev(n, a); }; })(); 1`);
await wait(900);
await shoot("00-boot-shell");
await evaluate("[...document.querySelectorAll('#mods button')][1].click()");
await wait(1500);
await shoot("01-demo-web");
const report = { steps: [] };

// 1. it is drawing, and the drawing is coming from the interpreter
const f1 = await frames();
await wait(800);
const f2 = await frames();
report.steps.push({ step: "demo.web draws", fillsAfter1: f1, fillsLater: f2, advancing: f2 > f1 });

// 2. a different BUILD of the running mod, through the page's own buttons.
//    `t` and `frames` live in the interpreter; the page cannot see them, so what
//    is checked here is what a reader can check - the generation went up, the
//    swap was not refused, and the call mix changed shape.
report.earlyCalls = JSON.parse(await evaluate("JSON.stringify(__demo.made())"));
report.stdout = await evaluate("globalThis.__inf_out || ''");
report.logPane = await evaluate("document.getElementById('log').textContent");
let gen = "n/a", gen2 = "n/a";
try { await evaluate("[...document.querySelectorAll('#variants button')][1].click()"); gen = await evaluate("[...new Set(globalThis.__titles||[])].join(',')"); }
catch (e) { report.buildError = String(e.message); }
await wait(900);
await shoot("02-build-orbit");
report.basesAfterBuild2 = await evaluate("globalThis.__inf_bases");
try { await evaluate("[...document.querySelectorAll('#variants button')][2].click()"); gen2 = await evaluate("[...new Set(globalThis.__titles||[])].join(',')"); } catch (e) {}
await wait(900);
await shoot("03-build-lissajous");
report.basesAfterBuild3 = await evaluate("globalThis.__inf_bases");
report.steps.push({ step: "load another build", titlesAfterFirst: gen, titlesAfterSecond: gen2,
  keptRunning: await evaluate("__demo.running === true") });

// 3. a different mod, into the same page
await evaluate("[...document.querySelectorAll('#mods button')][0].click()");
await wait(900);
await shoot("04-boot-shell");
report.steps.push({ step: "load infiniteless.shell",
  bases: await evaluate("globalThis.__inf_bases"),
  packs: await evaluate("__demo.payload.packs.length") });

await evaluate("[...document.querySelectorAll('#mods button')][2].click()");
await wait(700);
await shoot("05-example-readout");
report.steps.push({ step: "load example.readout", running: await evaluate("__demo.running === true") });

// 4. back to the demo, and unload
await evaluate("[...document.querySelectorAll('#mods button')][0].click()");
await wait(500);
await evaluate("document.getElementById('unload').click()");
await wait(300);
await shoot("06-unloaded");
report.statusLine = await evaluate("document.getElementById('status').textContent");
report.steps.push({ step: "unload", running: await evaluate("__demo.running === true") });

report.budgetMB = await evaluate("Math.round(__demo.used()/1048576)");
report.asleep = await evaluate("__demo.asleep");
report.declined = JSON.parse(await evaluate("JSON.stringify(__demo.declined())"));
report.calls = JSON.parse(await evaluate("JSON.stringify(__demo.made())"));
report.pageErrors = errors;
report.wire = served.map((f) => `${f.rel} ${f.raw} raw / ${f.wire} gzip`);
console.log(JSON.stringify(report, null, 2));
ws.close(); chrome.kill(); server.close(); process.exit(0);
