// run-aowli-bundle.mjs - run one of the browser aowli bundles (aowli.js,
// aowli_vm.js, aowli_dbg.js) under node the way public/playground/worker.js
// does, so a bundle can be checked without a browser: same globalThis.__aowli_*
// input/output channels, same `new Function(text + "\nmain(0, []);")` entry.
//
//   node tools/run-aowli-bundle.mjs BUNDLE.js MAIN.s.nif [MODDIR] [--runs N]
//
// MODDIR holds the dependency `.s.nif` files (framed "<stem>\t<len>\n<bytes>",
// exactly as the worker frames them). Prints stdout, stderr, exit code and the
// median run time, so the same command can be pointed at two builds of a bundle
// and the results diffed.
"use strict";
import fs from "node:fs";
import path from "node:path";

const argv = process.argv.slice(2);
const runsAt = argv.indexOf("--runs");
const RUNS = runsAt >= 0 ? +argv[runsAt + 1] : 5;
const pos = argv.filter((a, i) => a !== "--runs" && !(runsAt >= 0 && i === runsAt + 1));
const [bundle, main, modDir] = pos;
if (!bundle || !main) { console.error("usage: run-aowli-bundle.mjs BUNDLE.js MAIN.s.nif [MODDIR] [--runs N]"); process.exit(2); }

const text = fs.readFileSync(bundle, "latin1");
const snif = fs.readFileSync(main, "latin1");
let mods = "";
if (modDir) {
  for (const f of fs.readdirSync(modDir).sort()) {
    if (!f.endsWith(".s.nif")) continue;
    const body = fs.readFileSync(path.join(modDir, f), "latin1");
    mods += f.slice(0, -".s.nif".length) + "\t" + body.length + "\n" + body;
  }
}

// The worker's Node-globals shim, minus the parts node already has.
globalThis.self = globalThis;
globalThis.global = globalThis;
const realExit = process.exit;
process.exit = (code) => { const e = new Error("process.exit(" + (code || 0) + ")"); e.__isExit = true; throw e; };
const sink = (key) => (s) => { globalThis[key] = (globalThis[key] || "") + (typeof s === "string" ? s : Buffer.from(s).toString("latin1")); return true; };
process.stdout.write = sink("__aowli_out");
process.stderr.write = sink("__aowli_err");

const compiled = new Function(text + "\nmain(0, []);");
const times = [];
let last;
for (let i = 0; i < RUNS; i++) {
  globalThis.__aowli_in = "";
  globalThis.__aowli_src = snif;
  globalThis.__aowli_mods = mods;
  globalThis.__aowli_out = "";
  globalThis.__aowli_err = "";
  globalThis.__aowli_exit = 0;
  globalThis.__aowli_dbg = "";
  const t0 = process.hrtime.bigint();
  let thrown = "";
  try { compiled(); } catch (e) { thrown = e && e.__isExit ? String(e.message) : String((e && e.stack) || e).split("\n")[0]; }
  const t1 = process.hrtime.bigint();
  times.push(Number(t1 - t0) / 1e6);
  last = { out: globalThis.__aowli_out, err: globalThis.__aowli_err, exit: globalThis.__aowli_exit | 0, thrown, dbg: globalThis.__aowli_dbg };
}
times.sort((a, b) => a - b);
process.exit = realExit;
// fd 1 directly: process.stdout.write is the capture sink above.
fs.writeSync(1, JSON.stringify({ ...last, medianMs: +times[Math.floor(times.length / 2)].toFixed(1), runs: RUNS }) + "\n");
