// prove-vm.mjs — does the Bytecode VM actually run programs, or only claim to?
//
//   node tools/session/prove-vm.mjs
//
// The playground offers three engines and the Bytecode VM is the DEFAULT. For a
// long time it was not an engine at all: every program aborted with
//
//     [Assertion Failure] expected 'index' tag
//
// and `worker.js` quietly re-ran it on the tree-walker, so the footer said
// "tree-walk — the Bytecode VM fell back" and the answers were right. A default
// that never once did its job, reported in a sentence nobody could act on.
//
// TWO CAUSES, IN SERIES, and the second only visible once the first was fixed:
//
//  1. `public/playground/aowli_vm.js` predated `webvfs.publishMainModule`. A NIF
//     module elides its own module suffix and `nifreader` re-appends
//     `thisModule`, so every main-module symbol reads back as `main.0.webmod` —
//     a module nobody put in the VFS. The tree-walker never notices (it resolves
//     the main module's decls from the tree it is walking); the VM's eager
//     `compileModule` reaches `programs.tryLoadSym` and `readIndex` asserts.
//     Fixed by rebuilding: `WEBMAIN=webmain_vm OUT=.../aowli_vm.js bash
//     tools/session/build.sh`.
//
//  2. With that gone the VM ran a program and produced NO output and exit 0 —
//     worse than aborting, because nothing said so. It needs the SIBLING
//     MODULES: `compileModule` reaches `write.0.syn1lfpjv` before a single
//     instruction runs, while the tree-walker gets to `echo` through a native
//     and never needs syncio's artifact. `worker.js` frames them for the VM now.
//
// WHAT WAS ALMOST CONCLUDED, and was wrong: that (2) was a defect in
// `compiler.nim` / `vm.nim`. The native `bin/aowli-vm` ran the browser's exact
// `.s.nif` correctly on the first try, which settled it in one command — the VM
// was never the problem, its inputs were. Reach for the native binary before
// blaming the engine.
//
// So this gate asserts what the footer could not: the VM RAN, it did not fall
// back, and it agrees with the reference engine character for character.
import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const DIR = path.join(HERE, "..", "..", "public", "playground");

globalThis.self = globalThis;
globalThis.location = { href: "file:///" };
globalThis.importScripts = () => {};
const posts = [];
globalThis.postMessage = (m) => posts.push(m);
globalThis.fetch = async (u) => {
  const f = path.join(DIR, String(u).split("?")[0]);
  if (!fs.existsSync(f)) return { ok: false, status: 404 };
  const b = fs.readFileSync(f);
  return { ok: true, status: 200, text: async () => b.toString("utf8"),
           arrayBuffer: async () => b.buffer.slice(b.byteOffset, b.byteOffset + b.byteLength) };
};
new Function(fs.readFileSync(path.join(DIR, "worker.js"), "utf8"))();
const onmsg = globalThis.onmessage;
const send = (msg) => new Promise((res) => {
  const n = posts.length;
  Promise.resolve(onmsg({ data: msg })).then(async () => {
    for (let i = 0; i < 4800; i++) {
      const hit = posts.slice(n).find((p) => p.id === msg.id || p.type === "ready" || p.type === "loaderr");
      if (hit) return res(hit);
      await new Promise((r) => setTimeout(r, 50));
    }
    res({ timeout: true });
  });
});

const fails = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
  if (!ok) fails.push(what);
};

// The bundle carries the fix, or nothing below can pass. Named separately so a
// stale bundle says so in one line instead of as five mysterious failures.
const vmText = fs.readFileSync(path.join(DIR, "aowli_vm.js"), "utf8");
check("the VM bundle carries publishMainModule", vmText.includes("publishMainModule"), true);

const ready = await send({ type: "init", assets: null });
if (ready.type !== "ready") { console.error("the worker never booted"); process.exit(2); }

const pmain = new Function(fs.readFileSync(path.join(DIR, "nifparser.js"), "utf8") + "\nmain(0, []);");
function parse(src) {
  globalThis.__np_src = src; globalThis.__np_file = "in.nim"; globalThis.__np_curly = "";
  globalThis.__np_style = ""; globalThis.__np_out = ""; globalThis.__np_diag = "[]";
  pmain();
  return globalThis.__np_out;
}

// Small programs, each reaching something different: stdlib output, a loop with
// accumulated state, a proc call, string building, and `quit` (which is a
// control-flow escape the VM has to honour, not just an exit code to copy).
const PROGRAMS = {
  "echo and arithmetic": `import std/syncio\nvar n = 0\nfor i in 1 .. 5:\n  n = n + i\n  echo "i=", i\necho "total=", n\n`,
  "a proc and recursion": `import std/syncio\nproc fib(n: int): int =\n  if n < 2: return n\n  return fib(n - 1) + fib(n - 2)\nfor i in 0 .. 10:\n  echo fib(i)\n`,
  "strings and seqs": `import std/syncio\nvar xs: seq[string] = @[]\nfor i in 1 .. 4:\n  xs.add "row " & $i\nfor x in xs: echo x\n`,
  "quit mid-program": `import std/syncio\necho "before"\nquit 3\necho "never"\n`,
};

let slowest = 0;
for (const [name, src] of Object.entries(PROGRAMS)) {
  const pnif = parse(src);
  const t0 = Date.now();
  const vm = await send({ id: 100 + slowest, type: "run", pnif, stdin: "", engine: "vm", semEngine: "aowl", multi: null });
  const ms = Date.now() - t0;
  slowest = Math.max(slowest, ms);
  const t1 = Date.now();
  const tree = await send({ id: 200 + slowest, type: "run", pnif, stdin: "", engine: "tree", semEngine: "aowl", multi: null });
  const treeMs = Date.now() - t1;

  console.log(`  — ${name} (VM ${ms} ms, tree-walk ${treeMs} ms)`);
  check(`   the VM ran it (no fallback)`, !vm.fellBack, true);
  if (vm.fellBack) console.log("      it said: " + String(vm.fallbackReason || "").slice(0, 140));
  check(`   it is the VM that answered`, vm.engine, "vm");
  check(`   stdout matches the tree-walker`, JSON.stringify(vm.stdout), JSON.stringify(tree.stdout));
  check(`   exit code matches`, vm.exitCode, tree.exitCode);
  check(`   and it is not empty`, (vm.stdout || "").length > 0, true);
}

// Framing the std closure for every VM run is real work; it is worth knowing
// what it costs rather than discovering it as "the playground got slow".
console.log(`      slowest VM run, including the semcheck and ~790 KB of framed modules: ${slowest} ms`);

console.log(fails.length ? `\nFAILED: ${fails.length}` : "\nPASS: the Bytecode VM runs programs and agrees with the reference engine.");
process.exit(fails.length ? 1 : 0);
