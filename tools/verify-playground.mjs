// verify-playground.mjs - open the real playground in headless Chromium, wait for
// the engine, press Run, and print what the page shows. Point it at two copies of
// the site (e.g. before and after obfuscating the engines) and diff the output.
//
//   node tools/verify-playground.mjs [SITE_ROOT=public] [--debug]
//
// Needs playwright + a chromium: `npx playwright install chromium`.
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { createRequire } from "node:module";

const argv = process.argv.slice(2);
const root = path.resolve(argv.find((a) => !a.startsWith("--")) || "public");
const { chromium } = createRequire(import.meta.url)("playwright");

const TYPES = { ".html": "text/html", ".js": "text/javascript", ".mjs": "text/javascript", ".json": "application/json",
  ".css": "text/css", ".wasm": "application/wasm", ".bin": "application/octet-stream", ".svg": "image/svg+xml" };
const server = http.createServer((req, res) => {
  let rel = decodeURIComponent(req.url.split("?")[0]);
  if (rel.endsWith("/")) rel += "index.html";
  const file = path.join(root, rel);
  if (!file.startsWith(root) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) { res.writeHead(404); res.end(); return; }
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  fs.createReadStream(file).pipe(res);
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const url = `http://127.0.0.1:${server.address().port}/playground/index.html`;

const browser = await chromium.launch();
const page = await browser.newPage();
const errors = [];
page.on("pageerror", (e) => errors.push("pageerror: " + String(e.message).slice(0, 160)));
page.on("console", (m) => { if (m.type() === "error") errors.push("console: " + m.text().slice(0, 160)); });

const t0 = Date.now();
await page.goto(url);
await page.waitForFunction(() => { const b = document.getElementById("runBtn"); return b && !b.disabled; }, null, { timeout: 180000 });
const readyMs = Date.now() - t0;
await page.click("#runBtn");
const initial = await page.textContent("#out");
await page.waitForFunction((was) => document.getElementById("out").textContent !== was, initial, { timeout: 120000 });
await page.waitForTimeout(1500);
const out = (await page.textContent("#out")).trim();
const status = ((await page.textContent("#outStatus").catch(() => "")) || "").trim();
await browser.close();
server.close();

const fold = (s) => s.replace(/\s+/g, " ").replace(/\d+(\.\d+)?\s*ms/g, "<N>ms").slice(0, 400);
console.log(JSON.stringify({ readyMs, out: fold(out), status: fold(status), errors }));
