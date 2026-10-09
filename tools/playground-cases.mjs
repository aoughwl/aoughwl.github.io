// playground-cases.mjs — run every program in tools/playground-cases/ through the
// REAL playground page (headless Chromium, default engine and checker) and compare
// what the page prints with tools/playground-cases/expected.tsv.
//
//   node tools/playground-cases.mjs [SITE_ROOT=public]
//
// Needs playwright + a chromium (`npm i playwright && npx playwright install
// chromium`, anywhere node can resolve it).
//
// Why: the playground is the first thing a visitor runs, and its engines are
// BROWSER builds of the interpreter — native gates do not see them. On
// 2026-10-09 this set found a VM that printed 0 for `"a,b,c".split(',').len`,
// a std/sets assertion, a 1M-iteration loop that ran out of memory, and a Native
// JS fallback that printed nothing — none of which any other gate could see.
//
// Status column: `ok` must match and exit 0; `error` must be refused with exactly
// that diagnostic; `known-bad` is expected to FAIL today and is
// reported, not counted — and if one starts PASSING the run says so, so the list
// cannot go stale in the comfortable direction.
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { createRequire } from "node:module";

const here = path.dirname(new URL(import.meta.url).pathname);
const root = path.resolve(process.argv[2] || path.join(here, "..", "public"));
const casesDir = path.join(here, "playground-cases");
const { chromium } = createRequire(import.meta.url)("playwright");

const rows = fs.readFileSync(path.join(casesDir, "expected.tsv"), "utf8")
  .split("\n").filter((l) => l.trim() && !l.startsWith("#"))
  .map((l) => { const [name, want, status] = l.split("\t"); return { name, want, status: status || "ok" }; });
if (rows.length < 10) { console.error(`only ${rows.length} cases listed — refusing (floor 10)`); process.exit(2); }

const TYPES = { ".html": "text/html", ".js": "text/javascript", ".json": "application/json", ".css": "text/css",
  ".wasm": "application/wasm", ".bin": "application/octet-stream", ".svg": "image/svg+xml" };
const server = http.createServer((req, res) => {
  let rel = decodeURIComponent(req.url.split("?")[0]);
  if (rel.endsWith("/")) rel += "index.html";
  const f = path.join(root, rel);
  if (!f.startsWith(root) || !fs.existsSync(f) || fs.statSync(f).isDirectory()) { res.writeHead(404); res.end(); return; }
  res.writeHead(200, { "content-type": TYPES[path.extname(f)] || "application/octet-stream" });
  fs.createReadStream(f).pipe(res);
});
await new Promise((r) => server.listen(0, "127.0.0.1", r));
const base = `http://127.0.0.1:${server.address().port}/playground/index.html`;
const b64url = (s) => Buffer.from(s, "utf8").toString("base64").replace(/\+/g, "-").replace(/\//g, "_").replace(/=+$/, "");

const browser = await chromium.launch();
let pass = 0, fail = 0, knownBad = 0, nowPassing = 0;
for (const row of rows) {
  const src = fs.readFileSync(path.join(casesDir, row.name + ".nim"), "utf8");
  const page = await browser.newPage();
  let got = "";
  try {
    await page.goto(base + "#c=" + b64url(src));
    await page.waitForFunction(() => { const x = document.getElementById("runBtn"); return x && !x.disabled; }, null, { timeout: 180000 });
    const before = await page.textContent("#out");
    await page.click("#runBtn");
    await page.waitForFunction((w) => document.getElementById("out").textContent !== w, before, { timeout: 120000 });
    await page.waitForTimeout(1500);
    got = (await page.textContent("#out")).replace(/\s+/g, " ").trim();
  } catch (e) { got = "HARNESS: " + String(e.message || e).split("\n")[0]; }
  await page.close();
  // the program's own output is everything before the run footer "— exit N · …"
  const out = got.replace(/^.*?ran on Native JS instead\.\s*/, "").split(" — exit ")[0].trim();
  // `error` rows assert the page REFUSES the program with that diagnostic: a
  // check that reported an error used to run anyway (`echo undefinedThing`
  // printed "nil"), so a program the checker rejects must not produce output.
  const ok = row.status === "error"
    ? out === row.want && !/ — exit 0 /.test(got)
    : out === row.want && / — exit 0 /.test(got);
  if (row.status === "known-bad") {
    if (ok) { nowPassing++; console.log(`NOW PASSES ${row.name}  (listed known-bad; change its status to ok)`); }
    else { knownBad++; console.log(`known-bad  ${row.name}  got: ${got.slice(0, 120)}`); }
  } else if (ok) { pass++; console.log(`ok         ${row.name}`); }
  else { fail++; console.log(`FAIL       ${row.name}\n           want: ${row.want}\n           got:  ${got.slice(0, 200)}`); }
}
await browser.close(); server.close();
const scored = rows.filter((r) => r.status !== "known-bad").length;
console.log(`\nplayground-cases: ${pass}/${scored} ok, ${fail} failed, ${knownBad} known-bad, ${nowPassing} known-bad now passing`);
process.exit(fail || nowPassing ? 1 : 0);
