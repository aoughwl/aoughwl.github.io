// verify-demo-semcheck.mjs — the gate that says the playground's DEFAULT program
// still type-checks cleanly, in a real headless Chrome, on BOTH checkers.
//
//   node tools/verify-demo-semcheck.mjs
//
// Why this exists: `echo`/`inc` live in `system`, and `system` reaches aowlsem
// only as a pre-semchecked record inside `assets/aowlsem-mods.bin`. That asset is
// a LENGTH-FRAMED binary container —
//   <suffix>\t<modname>\t<dep-suffix,…>\t<bytelen>\n<bytes>
// — so a single injected byte desynchronises every frame after it and the walk
// stops dead. Git's autocrlf did exactly that once (nothing marked the asset
// binary), and the whole std surface silently vanished: the demo reported
// "undeclared routine `echo`" with nothing wrong in the code at all. So this gate
// checks BOTH halves — the asset still frames (Node side) and the page still
// checks the demo clean (browser side) — because either can look fine alone while
// the user is staring at red squiggles.
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
                ".ico":"image/x-icon", ".png":"image/png" };
let failed = 0;
const ok  = (m) => console.log("  ok    " + m);
const bad = (m) => { console.log("  FAIL  " + m); failed++; };

// ---- half one: the asset still frames, in Node, with no browser involved ----
// The same frame walk worker.js does (parseModFrames), held latin1 so bytelen is true.
function frameCheck() {
  const p = path.join(ROOT, "assets", "aowlsem-mods.bin");
  if (!fs.existsSync(p)) { bad("assets/aowlsem-mods.bin is missing"); return; }
  const buf = fs.readFileSync(p);
  let txt = ""; for (let i = 0; i < buf.length; i++) txt += String.fromCharCode(buf[i]);
  const names = [];
  let i = 0;
  while (i < txt.length) {
    const nl = txt.indexOf("\n", i); if (nl < 0) break;
    const h = txt.slice(i, nl).split("\t"); if (h.length !== 4) break;
    const n = parseInt(h[3], 10); if (!(n > 0) || nl + 1 + n > txt.length) break;
    names.push(h[1]); i = nl + 1 + n;
  }
  console.log(`  ..    aowlsem-mods.bin: ${buf.length} bytes, ${names.length} record(s) framed, ${i}/${txt.length} bytes consumed`);
  if (i === txt.length && names.length > 1) ok(`every frame reads (${names.join(", ")})`);
  else bad(`frame walk desynchronised after ${names.length} record(s) — the asset is CORRUPT (CRLF translation? truncated fetch?)`);
  if (names.includes("system")) ok("the `system` module record is present");
  else bad("no `system` record — every system symbol will read as undeclared");
  let crlf = 0; for (let k = 1; k < buf.length; k++) if (buf[k] === 10 && buf[k-1] === 13) crlf++;
  if (crlf > 8) console.log(`  ..    ${crlf} CRLF pairs in the asset — the fingerprint of autocrlf mangling`);
}

// ---- half two: the real page, the real worker, the real default program ----
// Which checkers to exercise. aowlsem is the playground's DEFAULT and the one
// this gate is really about; it answers in a few seconds. nimsem boots a 9 MB
// bundle plus a 5 MB pre-checked stdlib closure and, when THAT asset is the
// mangled one, it can stop answering DevTools altogether — so it is opt-in:
//   CHECKERS=aowl,nim node tools/verify-demo-semcheck.mjs
const ONLY = (process.env.CHECKERS || "aowl").split(",").map(s=>s.trim()).filter(Boolean);
const PAGE = `<!doctype html><meta charset="utf-8"><title>demo semcheck gate</title>
<script>window.AowliOpts={curly:false,sem:"aowl"};window.__result=null;window.__stage="boot";</script>
<script src="examples.js"></script>
<script src="parser.js"></script>
<script src="pipeline.js"></script>
<script type="module">
const wait = (ms) => new Promise(r=>setTimeout(r,ms));
(async () => {
  const out = { errors:[] };
  try {
    for (let i=0;i<600 && !(window.AowliParser&&window.AowliParser.ready&&window.AowliPipe&&window.AowliPipe.ready);i++) await wait(100);
    window.__stage="parser+worker ready";
    if (!window.AowliParser.ready) throw new Error("parser never became ready");
    if (!window.AowliPipe.ready)   throw new Error("pipeline/worker never became ready");
    const src  = window.PLAYGROUND_DEMO;
    out.demoChars = src.length;
    const p = window.AowliParser.parseFull(src, "in.nim");
    out.parseDiags = p.diags.map(d=>d.message);
    window.__stage="parsed";
    const only = ${JSON.stringify(ONLY)};
    for (const eng of only) {
      window.__stage="checking with "+eng;
      try {
        const budget = eng === "nim" ? 240000 : 120000;
        const r = await Promise.race([
          window.AowliPipe.sem(p.nif, eng, null),
          new Promise((_,rej)=>setTimeout(()=>rej(new Error("timed out after "+(budget/1000)+"s")), budget))
        ]);
        out[eng] = (r.diags||[]).map(d=>\`\${d.line}:\${d.col} \${d.severity}: \${d.message}\`);
        out[eng+"Snif"] = (r.snif||"").length;
      } catch(e) { out[eng] = ["THREW: " + (e&&e.message||e)]; out[eng+"Snif"] = 0; }
      window.__partial = JSON.parse(JSON.stringify(out));   // readable before the run ends
    }
  } catch (e) { out.errors.push(String(e&&e.message||e)); }
  window.__stage="done";
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
  if (!body) { body = fs.readFileSync(file); MEM.set(file, body); }   // read each asset ONCE
  res.writeHead(200, { "content-type": TYPES[path.extname(file)] || "application/octet-stream" });
  res.end(body);
});
await new Promise(r => server.listen(0, "127.0.0.1", r));
const site = `http://127.0.0.1:${server.address().port}/gate.html`;

const CHROME = process.env.CHROME || "C:/Program Files/Google/Chrome/Application/chrome.exe";
const profile = fs.mkdtempSync(path.join(os.tmpdir(), "demosem-"));
const port = 9500 + (process.pid % 200);
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
console.error("  ..    [stage] waiting for chrome debugging port");
const target = await firstPage();
console.error("  ..    [stage] chrome page attached");
const ws = new WebSocket(target.webSocketDebuggerUrl);
await new Promise((r,j)=>{ ws.onopen=r; ws.onerror=j; });
let seq=0; const waiting=new Map(); const pageErrors=[];
ws.onmessage = (ev) => { const m = JSON.parse(ev.data);
  if (m.id && waiting.has(m.id)) { waiting.get(m.id)(m); waiting.delete(m.id); return; }
  if (m.method === "Runtime.exceptionThrown")
    pageErrors.push(m.params.exceptionDetails.exception?.description || m.params.exceptionDetails.text); };
ws.onclose = (e) => { console.error("  ..    [stage] DevTools socket closed (code " + (e&&e.code) + ") — the renderer went away"); };
const cmd = (method,params)=>new Promise(r=>{ const id=++seq;
  const t = setTimeout(()=>{ if (waiting.delete(id)) r(null); }, 120000);   // never wedge on a busy renderer
  waiting.set(id, (m)=>{ clearTimeout(t); r(m); });
  ws.send(JSON.stringify({id,method,params})); });
const evaluate = async (e)=> (await cmd("Runtime.evaluate",{expression:e,returnByValue:true,awaitPromise:true}))?.result?.result?.value;

console.log("== asset integrity ==");
frameCheck();

await cmd("Runtime.enable",{}); await cmd("Page.enable",{});
await cmd("Page.navigate",{url:site});
console.error("  ..    [stage] navigated to " + site);
let r = null, partial = null;
const t0 = Date.now();
while (Date.now() - t0 < 600000) {                       // 10 min ceiling; the bundles are ~30 MB
  r = await evaluate("window.__result"); if (r) break;
  partial = (await evaluate("window.__partial")) || partial;
  const st = await evaluate("window.__stage");
  console.error(`  ..    [stage] ${Math.round((Date.now()-t0)/1000)}s: ${st == null ? "(renderer busy)" : st}`);
  await new Promise(x=>setTimeout(x,3000));
}

console.log("\n== the default program (window.PLAYGROUND_DEMO), checked in a real browser ==");
if (!r && partial) { console.log("  ..    the run was cut short; reporting the partial verdict");
  r = partial; }
if (!r) { bad("the page never produced a result"); }
else {
  for (const e of r.errors||[]) bad("page: " + e);
  if ((r.parseDiags||[]).length) { bad("the PARSER reported diagnostics on the default program:");
    for (const d of r.parseDiags) console.log("        " + d); }
  else ok("parses clean");
  for (const eng of ONLY) {
    const label = eng === "aowl" ? "aowlsem (default)" : "nimsem";
    const ds = r[eng] || ["(never ran)"];
    const errs = ds.filter(d => !/ warning: /.test(d));
    if (!errs.length) ok(`${label}: clean, ${r[eng+"Snif"]} bytes of .s.nif`);
    else { bad(`${label}: ${errs.length} diagnostic(s) on the DEFAULT program`);
           for (const d of errs.slice(0,12)) console.log("        " + d);
           if (errs.length > 12) console.log(`        … and ${errs.length-12} more`); }
  }
}
for (const e of pageErrors) console.log("  ..    page error: " + String(e).split("\n")[0]);

try { chrome.kill(); } catch(_){}
server.close();
console.log(failed ? `\nFAILED: ${failed} check(s)` : "\nPASS: the default program type-checks clean on both checkers.");
process.exit(failed ? 1 : 0);
