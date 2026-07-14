// worker.js — the off-main-thread half of the playground pipeline.
//
// The two HEAVY stages live here: nimsem (the 8.9 MB semantic checker) and nifi
// (the interpreter). Both are driven by an already-parsed `.p.nif` handed in from
// the main thread (nifparser stays on the main thread — it's ~4 ms and feeds the
// synchronous Monaco/LSP index). Moving these two here is what keeps the editor
// from freezing during a live semcheck, and lets a runaway program be KILLED by
// terminating the worker (the main thread respawns a fresh one).
//
// Protocol (main → worker):
//   { id, type:"sem", pnif }            semcheck only (live diagnostics)
//   { id, type:"run", pnif, stdin }     semcheck (cached) + execute
// Protocol (worker → main):
//   { type:"ready" } | { type:"loaderr", message }
//   { id, ok:true,  ... }  a result           { id, ok:false, message }
//
// Every stage is wrapped so a bundle-level throw (e.g. a missing FFI shim, or a
// process.exit) comes back as a clean message instead of killing the worker.

// --- Node-globals shim (mirrors index.html's) --------------------------------
// The nifi/nimsem bundles were emitted for a Node-ish host and reach for
// `process`/`Buffer`/`global` on their libc-stdio and exit paths. The happy
// path (echo) uses the __nifi_ capture natives; stdlib code that writes via
// fwrite hits process.stdout instead. In a bare worker those are undefined.
(function(){
  var g = self;
  if(!g.global) g.global = g;
  function toStr(s){
    if(typeof s === "string") return s;
    if(s && typeof s.length === "number"){ var r=""; for(var i=0;i<s.length;i++) r+=String.fromCharCode(s[i]&0xff); return r; }
    return s==null ? "" : String(s);
  }
  if(typeof g.Buffer === "undefined")
    g.Buffer = { from:function(x){ return (x instanceof Uint8Array) ? x : Uint8Array.from(x||[]); } };
  if(typeof g.process === "undefined")
    g.process = {
      platform:"browser", argv:[], env:{}, cwd:function(){ return "/"; },
      stdout:{ write:function(s){ g.__nifi_out=(g.__nifi_out||"")+toStr(s); return true; } },
      stderr:{ write:function(s){ g.__nifi_err=(g.__nifi_err||"")+toStr(s); return true; } },
      exit:function(code){ var e=new Error("process.exit("+(code||0)+")"); e.__isExit=true; throw e; }
    };
})();

// --- load + compile-once the two bundles -------------------------------------
let semMain = null, nifiMain = null, stdlibBlob = null;

function bytesToLatin1(buf){
  const u = new Uint8Array(buf); let s = "";
  for(let i = 0; i < u.length; i++) s += String.fromCharCode(u[i]);
  return s;
}

async function boot(){
  const [semJs, nifiJs, asset] = await Promise.all([
    fetch("nimsem.js").then(r=>{ if(!r.ok) throw new Error("nimsem.js HTTP "+r.status); return r.text(); }),
    fetch("nifi.js").then(r=>{ if(!r.ok) throw new Error("nifi.js HTTP "+r.status); return r.text(); }),
    fetch("assets/nimsem-stdlib.bin").then(r=>{ if(!r.ok) throw new Error("stdlib asset HTTP "+r.status); return r.arrayBuffer(); })
  ]);
  stdlibBlob = bytesToLatin1(asset);
  // Compile each bundle ONCE. Invoking the result re-runs its top-level init in
  // a fresh scope (fresh 64 MiB linear memory, fresh module state) per call, so
  // each semcheck / run still starts clean — we just don't re-parse megabytes of
  // JS every time.
  semMain  = new Function(semJs  + "\nmain(0, []);");
  nifiMain = new Function(nifiJs + "\nmain(0, []);");
}

// --- nimsem: .p.nif -> .s.nif + diagnostics ----------------------------------
function parseDiags(raw){
  const out = [], seen = new Set();
  for(const ln of String(raw||"").split("\n")){
    const m = ln.match(/\((\d+),\s*(\d+)\)\s+(Error|Warning|Hint|Trace):?\s*(.*)$/);
    if(!m) continue;
    const kind = m[3].toLowerCase();
    if(kind === "trace" || kind === "hint") continue;
    if(/\(err\s/.test(m[4])) continue;               // drop cascade noise
    const key = m[1]+":"+m[2]+":"+m[4];
    if(seen.has(key)) continue; seen.add(key);
    out.push({ line:+m[1], col:+m[2], message:m[4].trim(),
               severity: kind==="warning" ? "warning" : "error" });
  }
  return out;
}

// input-level incremental gate: the compile input is the .p.nif, so a byte-equal
// pnif (whitespace/comment edits, or Run right after the live checker) returns
// the cached result. Small LRU keeps the last few distinct inputs warm.
const CACHE_MAX = 8;
const cache = new Map();
function cacheGet(k){ if(!cache.has(k)) return null; const v=cache.get(k); cache.delete(k); cache.set(k,v); return v; }
function cachePut(k,v){ cache.set(k,v); while(cache.size>CACHE_MAX) cache.delete(cache.keys().next().value); }

function semFresh(pnif){
  globalThis.__ns_main   = String(pnif);
  globalThis.__ns_assets = stdlibBlob;
  globalThis.__ns_out    = "";
  globalThis.__ns_diag   = "";
  try{
    semMain();
  }catch(e){
    const diags = parseDiags(globalThis.__ns_diag);
    return { snif:"", diags: diags.length ? diags : [{ line:1, col:1, severity:"error",
      message:"this program uses a module or feature not yet supported in the browser sandbox" }] };
  }
  return { snif: globalThis.__ns_out || "", diags: parseDiags(globalThis.__ns_diag) };
}

function semCompile(pnif){
  pnif = String(pnif);
  const hit = cacheGet(pnif);
  if(hit) return { snif:hit.snif, diags:hit.diags, cached:true };
  const res = semFresh(pnif);
  cachePut(pnif, { snif:res.snif, diags:res.diags });
  return { snif:res.snif, diags:res.diags, cached:false };
}

// --- nifi: run a typed .s.nif ------------------------------------------------
function runSnif(snif, stdin){
  globalThis.__nifi_in  = stdin || "";
  globalThis.__nifi_src = snif;
  globalThis.__nifi_out = ""; globalThis.__nifi_err = ""; globalThis.__nifi_exit = 0;
  nifiMain();
  return { stdout: globalThis.__nifi_out || "", stderr: globalThis.__nifi_err || "",
           exitCode: globalThis.__nifi_exit | 0 };
}

// --- message loop ------------------------------------------------------------
self.onmessage = (ev) => {
  const msg = ev.data || {};
  const id = msg.id;
  try{
    if(msg.type === "sem"){
      const { snif, diags, cached } = semCompile(msg.pnif);
      self.postMessage({ id, ok:true, snif, diags, cached });
      return;
    }
    if(msg.type === "run"){
      const { snif, diags } = semCompile(msg.pnif);
      if(!snif){ self.postMessage({ id, ok:true, ranSem:true, snif:"", diags }); return; }
      let res;
      try{
        res = runSnif(snif, msg.stdin);
      }catch(e){
        // an exit() thrown mid-run, or a bundle-level crash (e.g. a missing FFI
        // shim). Surface it as stderr with whatever was printed so far, rather
        // than letting the worker die.
        const emsg = (e && e.__isExit) ? "" : ("runtime error: " + (e && e.message || e));
        res = { stdout: globalThis.__nifi_out || "", stderr: (globalThis.__nifi_err || "") + emsg,
                exitCode: (e && e.__isExit) ? (parseInt(String(e.message).replace(/\D/g,""),10)||0) : 1 };
      }
      res.diags = diags;
      self.postMessage(Object.assign({ id, ok:true }, res));
      return;
    }
    self.postMessage({ id, ok:false, message:"unknown request: "+msg.type });
  }catch(e){
    self.postMessage({ id, ok:false, message: String(e && e.message || e) });
  }
};

boot().then(()=> self.postMessage({ type:"ready" }))
      .catch(e=> self.postMessage({ type:"loaderr", message: String(e && e.message || e) }));
