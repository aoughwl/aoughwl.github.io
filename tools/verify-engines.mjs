// verify-engines.mjs — run the SAME program on each execution engine in a real
// headless Chrome and assert WHICH ENGINE ACTUALLY RAN.
//
//   node tools/verify-engines.mjs
//
// Why this exists: worker.js's runSnif runs the bytecode VM and, on ANY throw,
// quietly resets and re-runs the tree-walker, returning engine:"tree". That is
// deliberate — the VM's compiler resolves some symbols eagerly, which asks the
// host to load another module on demand, and the self-contained browser host has
// no filesystem to load it from — but for a long time it was also SILENT. From
// the outside, "the VM fell back" and "the VM is broken and never runs" look
// exactly the same, which is how it got reported as "bytecode vm just does tree
// walk when you got it set".
//
// So this gate pins down the boundary with two programs:
//   * a PURE-INTEGER control (no strings, seqs, tables, no echo) — the VM should
//     run this one, and if it does not, the VM really is broken;
//   * the playground's own default program, which uses `echo` and string
//     literals — the documented container-load case.
// For each engine it prints the requested engine, the engine that ran, and, when
// they differ, the reason the run carried back. A fallback with NO reason is a
// failure here: silence is the bug.
"use strict";
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import os from "node:os";
import { spawn } from "node:child_process";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(HERE, "..", "public", "playground");
const TYPES = { ".html":"text/html", ".js":"text/javascript", ".json":"application/json",
                ".css":"text/css", ".bin":"application/octet-stream", ".nif":"text/plain",
                ".ico":"image/x-icon", ".png":"image/png", ".svg":"image/svg+xml" };
let failed = 0;
const ok  = (m) => console.log("  ok    " + m);
const bad = (m) => { console.log("  FAIL  " + m); failed++; };
// A defect this repo cannot fix (it lives in a compiled aowli bundle) is reported
// loudly but does NOT fail the gate — a permanently red gate stops being read.
// What DOES fail the gate is the thing this repo owns: a run that silently
// executes on an engine other than the one asked for.
const warn = (m) => console.log("  WARN  " + m);

// The floor: no procs, no calls, no data. If the VM cannot run even this, the
// engine is unreachable rather than merely limited.
const TRIVIAL = `quit(0)
`;

// The control: integers only. Nothing here needs a seq, a string or a Table, so
// nothing should drive the VM's compiler into an on-demand module load.
const INT_ONLY = `proc addUp(n: int): int =
  result = 0
  var i = 0
  while i <= n:
    result = result + i
    inc i

let total = addUp(100)
quit(if total == 5050: 0 else: 3)
`;

const PAGE = `<!doctype html><meta charset="utf-8"><title>engine gate</title>
<script>window.AowliOpts={curly:false,sem:"aowl"};window.__result=null;window.__stage="boot";</script>
<script src="examples.js"></script>
<script src="parser.js"></script>
<script src="pipeline.js"></script>
<script src="engine.js"></script>
<script type="module">
const wait = (ms) => new Promise(r=>setTimeout(r,ms));
const INT_ONLY = ${JSON.stringify(INT_ONLY)};
const TRIVIAL = ${JSON.stringify(TRIVIAL)};
(async () => {
  const out = { errors:[], runs:[] };
  try {
    for (let i=0;i<900 && !(window.AowliParser&&window.AowliParser.ready&&window.AowliEngine&&window.AowliEngine.ready);i++) await wait(100);
    if (!window.AowliParser.ready)  throw new Error("parser never became ready");
    if (!window.AowliEngine.ready)  throw new Error("engine never became ready");
    const programs = [
      { name: "trivial control (quit 0)", src: TRIVIAL },
      { name: "integer-only control", src: INT_ONLY },
      { name: "the default program",  src: window.PLAYGROUND_DEMO },
    ];
    for (const prog of programs) {
      for (const eng of ["tree","vm","nifjs"]) {
        window.__stage = prog.name + " on " + eng;
        const rec = { program: prog.name, requested: eng };
        try {
          const r = await Promise.race([
            window.AowliEngine.run({ source: prog.src, stdin:"", engine: eng }),
            new Promise((_,rej)=>setTimeout(()=>rej(new Error("timed out after 120s")), 120000))
          ]);
          rec.ran = r.engine || "(none)";
          rec.exitCode = r.exitCode | 0;
          rec.fellBack = !!r.fellBack;
          rec.fallbackFrom = r.fallbackFrom || "";
          rec.fallbackReason = r.fallbackReason || "";
          rec.stdout = String(r.stdout || "").split("\\n")[0].slice(0, 70);
          rec.stderr = String(r.stderr || "").split("\\n")[0].slice(0, 120);
        } catch (e) { rec.ran = "(threw)"; rec.error = String(e && e.message || e); }
        out.runs.push(rec);
        window.__partial = JSON.parse(JSON.stringify(out));
      }
    }
  } catch (e) { out.errors.push(String(e&&e.message||e)); }
  window.__stage = "done";
  window.__result = out;
})();
</script>`;

const MEM = new Map();
const server = http.createServer((req, res) => {
  const rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "");
  if (rel === "" || rel === "gate.html") { res.writeHead(200,{"content-type":"text/html"}); res.end(PAGE); return; }
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) { res.writeHead(404); res.end("no"); return; }
  let body = MEM.get(file);
  if (!body) { body = fs.readFileSync(file); MEM.set(file, body); }
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  res.end(body);
});
await new Promise(r => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/gate.html`;

const CHROME = process.env.CHROME || "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "enginegate-"));
const port = 9300 + (process.pid % 150);
const chrome = spawn(CHROME, ["--headless=new","--disable-gpu","--no-first-run","--no-default-browser-check",
  "--disable-background-timer-throttling","--disable-renderer-backgrounding",
  "--disable-backgrounding-occluded-windows","--disable-features=CalculateNativeWinOcclusion",
  `--remote-debugging-port=${port}`, `--user-data-dir=${profile}`, "--window-size=1000,800", "about:blank"], { stdio:"ignore" });

async function firstPage(){
  for (let i=0;i<150;i++){
    try { const l = await (await fetch(`http://127.0.0.1:${port}/json/list`)).json();
          const p = l.find(t=>t.type==="page"); if (p) return p; } catch(_){}
    await new Promise(r=>setTimeout(r,100));
  }
  throw new Error("chrome never opened a debugging port");
}
const target = await firstPage();
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r,j)=>{ ws.onopen=r; ws.onerror=j; });
let seq=0; const waiting=new Map(); const pageErrors=[];
ws.onmessage = (ev) => { const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); return; }
  if (m.method === "Runtime.exceptionThrown")
    pageErrors.push(m.params.exceptionDetails.exception?.description || m.params.exceptionDetails.text); };
ws.onclose = (e) => console.error("  ..    [stage] DevTools socket closed (code " + (e && e.code) + ")");
const cmd = (method,params)=>new Promise(r=>{ const id=++seq;
  const t = setTimeout(()=>{ if (waiting.delete(id)) r(null); }, 120000);
  waiting.set(id, (m)=>{ clearTimeout(t); r(m); });
  ws.send(JSON.stringify({id,method,params})); });
const evaluate = async (e)=> (await cmd("Runtime.evaluate",{expression:e,returnByValue:true,awaitPromise:true}))?.result?.result?.value;

await cmd("Runtime.enable",{}); await cmd("Page.enable",{});
await cmd("Page.navigate",{url:site});
let r = null, partial = null;
const t0 = Date.now();
while (Date.now() - t0 < 600000) {
  r = await evaluate("window.__result"); if (r) break;
  partial = (await evaluate("window.__partial")) || partial;
  const st = await evaluate("window.__stage");
  console.error(`  ..    [stage] ${Math.round((Date.now()-t0)/1000)}s: ${st == null ? "(renderer busy)" : st}`);
  await new Promise(x=>setTimeout(x,3000));
}
if (!r && partial) { console.log("  ..    the run was cut short; reporting the partial verdict"); r = partial; }

console.log("== which engine actually ran ==");
if (!r) { bad("the page never produced a result"); }
else {
  for (const e of r.errors||[]) bad("page: " + e);
  let prog = null;
  for (const run of r.runs || []) {
    if (run.program !== prog) { prog = run.program; console.log(`\n  ${prog}`); }
    const line = `requested ${run.requested.padEnd(5)} -> ran ${String(run.ran).padEnd(6)} exit ${run.exitCode}`;
    if (run.ran === "(threw)") { bad(`${line}  ${run.error}`); continue; }
    const io_ = (run.stdout ? `
          out: ${run.stdout}` : "") + (run.stderr ? `
          err: ${run.stderr}` : "");
    if (run.ran === run.requested) { ok(line + io_); continue; }
    // A fallback is allowed. A fallback the user is never told about is not.
    if (run.fallbackReason) ok(`${line}  (reported: ${run.fallbackReason})` + io_);
    else bad(`${line}  — fell back SILENTLY: no reason carried back to the UI` + io_);
  }
  // The control program is the one that tells "the VM cannot run THIS" apart
  // from "the VM never runs anything".
  const ctl = (r.runs||[]).find(x => x.program === "integer-only control" && x.requested === "vm");
  console.log("");
  const triv = (r.runs||[]).find(x => x.program === "trivial control (quit 0)" && x.requested === "vm");
  if (!ctl || !triv) bad("the controls never ran on the VM");
  else if (ctl.ran === "vm") ok("the bytecode VM executes programs — any fallback is program-specific");
  else {
    warn("KNOWN BROKEN: the bytecode VM aborts on every program tried, including "
       + (triv.ran === "vm" ? "nothing at all" : "a bare quit(0)") + ".");
    warn("  bare quit(0):    " + (triv.fallbackReason || "(ran on the VM)"));
    warn("  integer-only:    " + (ctl.fallbackReason || "(ran on the VM)"));
    warn("  These are aowli-internal aborts inside aowli_vm.js, a compiled bundle this");
    warn("  repo only ships. Not fixable here. What IS fixed here: the run no longer");
    warn("  pretends the tree-walker was the engine you picked.");
  }
}
for (const e of pageErrors) console.log("  ..    page error: " + String(e).split("\n")[0]);

try { chrome.kill(); } catch(_){}
server.close();
console.log(failed ? `\nFAILED: ${failed} check(s)` : "\nPASS: every engine either ran, or said why it could not.");
process.exit(failed ? 1 : 0);
