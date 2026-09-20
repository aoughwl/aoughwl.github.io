// run-jester-host.mjs - drive public/jester-demo/aowli-host.js under node the way
// public/jester-demo/boot.js does, without a browser: load the script, run its
// generated main (which registers the __inf_* seam), boot the first mod from
// payload.json, call its `start` and a few frames of `frame`/`update`, and record
// every call the mod makes into the host. Prints one JSON line: seam state, the
// error (if any), and a hash of the recorded host calls, so two builds of the
// script can be compared.
//
//   node tools/run-jester-host.mjs [path/to/aowli-host.js] [--mod ID]
"use strict";
import fs from "node:fs";
import vm from "node:vm";
import crypto from "node:crypto";

const argv = process.argv.slice(2);
const modAt = argv.indexOf("--mod");
const WANT = modAt >= 0 ? argv[modAt + 1] : null;
const file = argv.find((a, i) => !a.startsWith("--") && i !== modAt + 1) || "public/jester-demo/aowli-host.js";
const payload = JSON.parse(fs.readFileSync("public/jester-demo/payload.json", "utf8"));

function frame(names, pool) {
  let out = "";
  for (const name of [...names].sort()) {
    const raw = Buffer.from(pool[name], "base64").toString("latin1");
    let body = "";
    for (let i = 0; i < raw.length; i++) {
      const c = raw.charCodeAt(i);
      body += c >= 0x80 ? "\\x" + c.toString(16).padStart(2, "0") : raw[i];
    }
    out += name + "\t" + body.length + "\n" + body;
  }
  return out;
}

const g = globalThis;
g.window = g; g.self = g;
g.stat = g.lstat = g.fstat = () => -1;       // boot.js's ENOENT shim
const calls = [];
// The real host answers anything it does not implement with nil() = { k: "n" },
// so a mod can always read a reply's `.k`.
g.__inf_host = (name, args) => { calls.push(name + ":" + JSON.stringify(args)); return { k: "n" }; };
const realExit = process.exit;
process.exit = (c) => { throw new Error("process.exit(" + (c || 0) + ")"); };
const write = process.stdout.write.bind(process.stdout);
process.stdout.write = () => true;            // the bundle's own stdout is noise here

let error = "", seam = false, booted = false, frames = 0;
try {
  vm.runInThisContext(fs.readFileSync(file, "latin1"), { filename: file });
  g.main(0, []);
  seam = !!g.__inf_ready && ["__inf_boot", "__inf_has", "__inf_call", "__inf_swap"].every((n) => typeof g[n] === "function");
  const mod = payload.mods.find((m) => !WANT || m.id === WANT) || payload.mods[0];
  g.__inf_mods = frame(mod.modules, payload.modules);
  g.__inf_src = Buffer.from(mod.src, "base64").toString("latin1");
  g.__inf_boot();
  if (g.__inf_err) throw new Error("boot: " + g.__inf_err);
  booted = true;
  for (const name of ["start", "frame", "frame", "frame"]) {
    g.__inf_has(name);
    if (!g.__inf_bool) continue;
    g.__inf_call(name);
    if (g.__inf_err) throw new Error(name + ": " + g.__inf_err);
    if (name === "frame") frames++;
  }
} catch (e) {
  error = String((e && e.message) || e).split("\n")[0].slice(0, 200);
}
process.exit = realExit;
const digest = crypto.createHash("sha256").update(calls.join("\n")).digest("hex").slice(0, 16);
fs.writeSync(1, JSON.stringify({ seam, booted, frames, hostCalls: calls.length, hostCallHash: digest, error }) + "\n");
