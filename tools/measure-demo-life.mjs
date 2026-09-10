// How long can the browser build run one mod before its 1 GiB linear memory is
// full? Load the page, leave it alone, and report the wall time and the frame
// count at the moment the interpreter stops.
"use strict";
import http from "node:http"; import fs from "node:fs"; import path from "node:path";
import { spawn } from "node:child_process"; import os from "node:os";
const ROOT = path.resolve("public/jester-demo");
const server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "") || "index.html";
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file)) { res.writeHead(404); res.end(); return; }
  res.writeHead(200, { "content-type": rel.endsWith(".json") ? "application/json"
    : rel.endsWith(".js") ? "text/javascript" : "text/html" });
  res.end(fs.readFileSync(file));
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/index.html` + (process.env.MOD ? "?mod=" + process.env.MOD : "");
const CHROME = process.env.CHROME ||
  "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "jd-life-"));
const port = 9900 + (process.pid % 90);
const chrome = spawn(CHROME, ["--headless=new", "--disable-gpu", "--no-first-run",
  `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`, "about:blank"], { stdio: "ignore" });
let target;
for (let i = 0; i < 120 && !target; i++) {
  try { target = (await (await fetch(`http://127.0.0.1:${port}/json/list`)).json()).find((t) => t.type === "page"); } catch (e) {}
  if (!target) await new Promise((r) => setTimeout(r, 100));
}
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
let seq = 0; const waiting = new Map(); let dead = null;
ws.onmessage = (ev) => {
  const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) { const w = waiting.get(m.id); waiting.delete(m.id);
    m.error ? w.reject(new Error(m.error.message)) : w.resolve(m.result); }
  else if (m.method === "Runtime.exceptionThrown" && !dead)
    dead = m.params.exceptionDetails.exception?.description || "?";
};
const send = (method, params = {}) => new Promise((resolve, reject) => {
  const id = ++seq; waiting.set(id, { resolve, reject }); ws.send(JSON.stringify({ id, method, params })); });
const ev = async (e) => (await send("Runtime.evaluate", { expression: e, returnByValue: true, awaitPromise: true })).result?.value;
await send("Page.enable"); await send("Runtime.enable");
await send("Page.navigate", { url: site });
while (!(await ev("globalThis.__demo && __demo.running === true"))) await new Promise((r) => setTimeout(r, 100));
const t0 = Date.now();
const LIMIT = Number(process.env.LIMIT || 300000);
while (!dead && Date.now() - t0 < LIMIT) {
  await new Promise((r) => setTimeout(r, 1000));
  if (await ev("!!globalThis.__inf_fatal || (globalThis.__demo && __demo.dead)")) break;
}
const fills = await ev("__demo.made()['infiniteless_draw_fill'] || 0");
const usedMB = await ev("Math.round(__demo.used()/1048576)");
const hz = await ev("__demo.hz");
console.log(JSON.stringify({ seconds: ((Date.now() - t0) / 1000).toFixed(1), fills, usedMB, hz,
  died: dead ? dead.split("\n")[0] : null }, null, 2));
ws.close(); chrome.kill(); server.close(); process.exit(0);
