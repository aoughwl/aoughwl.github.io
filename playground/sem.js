// sem.js — the client-side SEMANTIC-CHECK seam.
//
// nimsem (nimony's semantic checker) is compiled to JavaScript through the
// nimony-web JS backend into `nimsem.js` (~8.9 MB). It turns an UNTYPED `.p.nif`
// (from nifparser) into a TYPED `.s.nif` that the nifi interpreter can run — the
// missing middle of client-side Tier 2. It runs entirely in-memory over a
// virtual filesystem (memvfs) preloaded with a pre-semchecked stdlib closure
// (assets/nimsem-stdlib.bin, ~0.85 MB: system/syncio/formatfloat).
//
// Contract (mirrors nimsem-web/src/nimony/nimsem_webjs.nim):
//   IN : globalThis.__ns_main   = the main module's `.p.nif` bytes (string)
//        globalThis.__ns_assets = the stdlib closure, framed as repeated
//                                 "<name>\t<byteLen>\n<bytes>" records
//   RUN: (new Function(bundle + "main(0,[]);"))()   // fresh scope per compile
//   OUT: globalThis.__ns_out    = the produced `.s.nif` bytes ("" on failure)
//        globalThis.__ns_diag   = raw reporter text; `<file>(line, col) Kind: msg`
//
// A fresh scope per compile is required (nimony guards module-init, and the
// semcheck lives there). This is invoked on Run, not per keystroke.
(function(){
  const sem = { ready:false, compile:null };
  let bundleText = null, stdlibBlob = null, loadPromise = null;

  // Byte-exact latin1 decode (NIF is a byte stream, never UTF-8).
  function bytesToLatin1(buf){
    const u = new Uint8Array(buf);
    let s = "";
    for(let i = 0; i < u.length; i++) s += String.fromCharCode(u[i]);
    return s;
  }

  function load(){
    if(loadPromise) return loadPromise;
    loadPromise = Promise.all([
      fetch("nimsem.js").then(r=>{ if(!r.ok) throw new Error("nimsem.js HTTP "+r.status); return r.text(); }),
      fetch("assets/nimsem-stdlib.bin").then(r=>{ if(!r.ok) throw new Error("stdlib asset HTTP "+r.status); return r.arrayBuffer(); })
    ]).then(([js, buf])=>{ bundleText = js; stdlibBlob = bytesToLatin1(buf); });
    return loadPromise;
  }

  // Parse nimsem's reporter text into structured markers. Each line looks like
  //   <file>(<line>, <col>) Error: <message>
  // line/col are 1-based (Monaco-ready). Trace/Hint lines are dropped as noise;
  // exact duplicates (nimsem reports some errors twice) are collapsed.
  function parseDiags(raw){
    const out = [], seen = new Set();
    for(const ln of String(raw||"").split("\n")){
      const m = ln.match(/\((\d+),\s*(\d+)\)\s+(Error|Warning|Hint|Trace):?\s*(.*)$/);
      if(!m) continue;
      const kind = m[3].toLowerCase();
      if(kind === "trace" || kind === "hint") continue;
      // Drop CASCADE errors: once a symbol/type is unresolved, sem substitutes
      // an internal `(err …)` node and every downstream mismatch mentions it.
      // Those are noise — one typo shouldn't paint 3 squiggles. The message a
      // user cares about (the root "undeclared identifier: X") never contains
      // the `(err ` marker, so filtering on it keeps exactly the real errors.
      if(/\(err\s/.test(m[4])) continue;
      const key = m[1]+":"+m[2]+":"+m[4];
      if(seen.has(key)) continue;
      seen.add(key);
      out.push({ line:+m[1], col:+m[2], message:m[4].trim(),
                 severity: kind==="warning" ? "warning" : "error" });
    }
    return out;
  }

  // ---- incremental gate -------------------------------------------------
  // nimsem already skips the stdlib every run (it is pre-semchecked into the
  // closure and reused — module-level incremental compilation). This adds the
  // INPUT-level gate: the compilation input is the `.p.nif`, so if it is
  // byte-identical to the last compile — which happens constantly, since most
  // keystrokes (whitespace, comments, edits that re-parse to the same tree)
  // don't change it, and Run fires right after the live checker on the same
  // buffer — we skip the (heavy) recompile entirely and return the cached
  // result. A small LRU keeps the last few distinct inputs warm too.
  const CACHE_MAX = 8;
  const cache = new Map();            // pnif -> { snif, diags }
  let lastHits = 0, lastMisses = 0;

  function cacheGet(pnif){
    if(!cache.has(pnif)) return null;
    const v = cache.get(pnif);        // refresh LRU position
    cache.delete(pnif); cache.set(pnif, v);
    return v;
  }
  function cachePut(pnif, v){
    cache.set(pnif, v);
    while(cache.size > CACHE_MAX) cache.delete(cache.keys().next().value);
  }

  function compileFresh(pnif){
    globalThis.__ns_main   = String(pnif);
    globalThis.__ns_assets = stdlibBlob;
    globalThis.__ns_out    = "";
    globalThis.__ns_diag   = "";
    try{
      (new Function(bundleText + "\nmain(0, []);"))();
    }catch(e){
      // nimsem aborted mid-compile — e.g. it hit an internal quit() (surfacing
      // as the process-shim's "process.exit") while trying to resolve a module
      // that isn't in the bundled stdlib closure. Surface whatever diagnostics
      // it captured; otherwise synthesize a clean one instead of leaking the
      // raw JS error to the user.
      const diags = parseDiags(globalThis.__ns_diag);
      return { snif:"", diags: diags.length ? diags : [{ line:1, col:1, severity:"error",
        message:"this program uses a module or feature not yet supported in the browser sandbox" }] };
    }
    return { snif: globalThis.__ns_out || "", diags: parseDiags(globalThis.__ns_diag) };
  }

  // pnif: the `.p.nif` string (latin1). Returns { snif, diags, cached }.
  function compile(pnif){
    if(!bundleText) throw new Error("nimsem not loaded yet");
    pnif = String(pnif);
    const hit = cacheGet(pnif);
    if(hit){ lastHits++; return { snif:hit.snif, diags:hit.diags, cached:true }; }
    lastMisses++;
    const res = compileFresh(pnif);
    cachePut(pnif, { snif:res.snif, diags:res.diags });
    return { snif:res.snif, diags:res.diags, cached:false };
  }
  // Expose cache stats for the UI (so the incremental behaviour is visible).
  sem.stats = () => ({ hits:lastHits, misses:lastMisses, warm:cache.size });

  sem.compile = compile;
  window.NifiSem = sem;

  load().then(()=>{
    sem.ready = true;
    if(window.__nifiSemReady) window.__nifiSemReady(true);
  }).catch(e=>{
    sem.ready = false;
    if(window.__nifiSemReady) window.__nifiSemReady(false, String(e && e.message || e));
  });
})();
