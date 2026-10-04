// prove-swap.mjs — settle, by measurement, whether aowli can hot-swap a module
// in a browser build: does the CODE change, and does the STATE survive?
//
//   node tools/session/prove-swap.mjs
//
// This exists because the published claim is that it cannot — that `swapHot`
// "returns success, raises nothing, increments the generation" and goes on
// running the previous body. Everything built on top of a live session depends
// on that claim being wrong, so it gets an experiment rather than an argument.
//
// THE FIXTURE IS BUILT TO SEPARATE THE TWO QUESTIONS. Both generations share a
// module-level `counter`; `tick()` increments it and returns a multiple of it —
// x1 in v1, x100 in v2. So one number answers both:
//
//   tick, tick        -> 1, 2          v1 is running
//   swap to v2
//   tick              -> 300           the code changed (x100) AND the state
//                                      survived (counter went 2 -> 3, not 0 -> 1)
//
// A swap that silently kept the old body returns 3. A swap that reset the module
// returns 100. Only a swap that did both halves returns 300.
import fs from "node:fs";
import path from "node:path";
import vm from "node:vm";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const BUNDLE = path.join(HERE, "..", "..", "public", "playground", "aowli_session.js");
const FIX = path.join(HERE, "fixture");

const latin1 = (p) => fs.readFileSync(p).toString("latin1");

// webvfs frames a sibling module as "<name>\t<len>\n<body>", every byte >= 0x80
// escaped as \xHH, <len> counting the ESCAPED body.
function frame(files) {
  let out = "";
  for (const [name, raw] of files) {
    let body = "";
    for (let i = 0; i < raw.length; i++) {
      const c = raw.charCodeAt(i);
      body += c >= 0x80 ? "\\x" + c.toString(16).padStart(2, "0") : raw[i];
    }
    out += name + "\t" + body.length + "\n" + body;
  }
  return out;
}

// The main module of a generation is the .s.nif that is not `system`.
function generation(dir) {
  const files = fs.readdirSync(dir).filter((f) => f.endsWith(".s.nif"));
  const main = files.find((f) => !f.startsWith("sys"));
  const sibs = [];
  for (const f of fs.readdirSync(dir)) {
    if (f === main) continue;
    if (f.endsWith(".s.nif") || f.endsWith(".s.idx.nif"))
      sibs.push([f, latin1(path.join(dir, f))]);
  }
  return { src: latin1(path.join(dir, main)), mods: frame(sibs), name: main };
}

const v1 = generation(path.join(FIX, "nc_v1"));
const v2 = generation(path.join(FIX, "nc_v2"));
console.log(`v1 ${v1.name} ${v1.src.length}B   v2 ${v2.name} ${v2.src.length}B`);

// aowli's browser build reaches std/os's fileExists/dirExists on a couple of
// guard paths, which compile down to a libc `stat` no JS environment answers.
// In a VFS-only world the truthful answer is ENOENT.
globalThis.stat = globalThis.lstat = globalThis.fstat = () => -1;
globalThis.__sess_src = v1.src;
globalThis.__sess_mods = v1.mods;
globalThis.__sess_in = "";

vm.runInThisContext(fs.readFileSync(BUNDLE, "utf8"), { filename: "aowli_session.js" });
globalThis.main(0, []);
if (!globalThis.__sess_ready) { console.error("FAIL: the seam did not register"); process.exit(1); }

const fails = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
  if (!ok) fails.push(what);
};
const say = () => (globalThis.__sess_err ? " — " + globalThis.__sess_err : "");
const tick = () => { globalThis.__sess_call("tick"); return globalThis.__sess_ret && globalThis.__sess_ret.v; };

globalThis.__sess_boot();
if (!globalThis.__sess_ok) { console.error("FAIL: boot" + say()); process.exit(1); }
console.log(`booted: gen ${globalThis.__sess_gen}, published [${globalThis.__sess_bases}]`);

check("first tick on v1", tick(), 1);
check("second tick on v1", tick(), 2);

// THE SWAP. New bytes go on __sess_src and the seam republishes them over the
// live module itself — the step whose absence was the whole bug.
globalThis.__sess_src = v2.src;
globalThis.__sess_swap();
if (!globalThis.__sess_ok) { console.error("FAIL: swap" + say()); process.exit(1); }
check("generation after the swap", globalThis.__sess_gen, 1);
check("signature drift reported", globalThis.__sess_drift === "" ? "none" : globalThis.__sess_drift, "none");

const after = tick();
check("tick after the swap (code changed AND state kept)", after, 300);
if (after === 3) console.log("       ^ 3 means the OLD body is still running — the swap lied.");
if (after === 100) console.log("       ^ 100 means the module was RE-INITIALIZED — state was lost.");

// A second swap, back to v1, proves the first was not a one-off and that a
// module can be swapped repeatedly without the state drifting.
globalThis.__sess_src = v1.src;
globalThis.__sess_swap();
check("generation after swapping back", globalThis.__sess_gen, 2);
check("tick after swapping back to v1", tick(), 4);

globalThis.__sess_stop();
check("session stopped", globalThis.__sess_live, false);


// ── DRIFT ──────────────────────────────────────────────────────────────────
// v3 changes tick's ARITY: `tick(): int` becomes `tick(n: int): int`. A live
// caller compiled against the old shape now binds the wrong thing, and swapHot
// is the one place both generations are in hand at once, so it is the one place
// that can say so. This is the signal the editor draws on the declaration.
console.log("\n-- signature drift --");
const v3 = generation(path.join(FIX, "nc_v3"));
globalThis.__sess_src = v1.src; globalThis.__sess_mods = v1.mods;
globalThis.__sess_boot();
tick(); 
globalThis.__sess_src = v3.src;
globalThis.__sess_swap();
check("swap with a changed arity still succeeds", globalThis.__sess_ok, true);
const drift = String(globalThis.__sess_drift || "");
check("drift names the moved symbol", /tick/.test(drift) ? "yes" : "no  [" + drift + "]", "yes");
console.log("       " + drift.replace(/\n/g, "\n       "));
globalThis.__sess_stop();

// ── APPEND (the REPL shape) ────────────────────────────────────────────────
// swapHot's two modes are both wrong for a prompt: runInit=false never
// initializes a global the new generation ADDED, and runInit=true re-runs every
// earlier statement's side effects. swapHotAppend runs the TAIL only.
//
// The fixture separates those. a1's top level ends `n = n + 1`; a2 appends a
// second one. Between them we call bump(), which adds 50 — state that only
// survives if the earlier statements are NOT re-run.
//
//   load (no top level) -> append(0) runs it all      n = 1
//   bump()                                            n = 51
//   append a2's tail only                             n = 52
//
// A full re-run answers 2 instead: `var n = 0` would run again and erase bump.
console.log("\n-- append (REPL) --");
const a1 = generation(path.join(FIX, "nc_a1"));
const a2 = generation(path.join(FIX, "nc_a2"));
const read = () => { globalThis.__sess_call("read"); return globalThis.__sess_ret && globalThis.__sess_ret.v; };
globalThis.__sess_src = a1.src; globalThis.__sess_mods = a1.mods;
globalThis.__sess_load();                       // a session with NOTHING run yet
check("load without running the top level", globalThis.__sess_ok, true);
// A module loaded WITHOUT its top level has published its procs but not run a
// single statement. The globals' cells exist and hold their zero, so `read()` is
// callable and answers 0 — the value `n` has before `n = n + 1` ever runs.
//
// This check used to assert it answered NOTHING, and passed, because the seam
// was loading a previous session's module out of the VFS instead of this one
// (`publishMainModule` refuses to overwrite). A test that documents the shape of
// a bug is worse than no test, so it now states what the fixed seam does.
read();
check("a proc is callable before the top level ran", globalThis.__sess_ok, true);
check("...and an uninitialized global reads as its zero", globalThis.__sess_ret.v, 0);
globalThis.__sess_append(0);                    // run the whole top level
if (!globalThis.__sess_ok) console.log("   append(0) said: " + globalThis.__sess_err);
check("n after the top level ran", read(), 1);
globalThis.__sess_call("bump");
check("n after bump()", read(), 51);
globalThis.__sess_src = a2.src;
globalThis.__sess_append(-1);                   // -1 = continue from where we got to
if (!globalThis.__sess_ok) console.log("   append(-1) said: " + globalThis.__sess_err);
const appended = read();
check("n after appending ONE statement", appended, 52);
if (appended === 2) console.log("       ^ 2 means the whole top level re-ran — bump()'s 50 was erased.");
globalThis.__sess_stop();

console.log(fails.length ? `\nFAILED: ${fails.length} check(s)` : "\nPASS: the hot swap changes the code and keeps the state.");
process.exit(fails.length ? 1 : 0);
