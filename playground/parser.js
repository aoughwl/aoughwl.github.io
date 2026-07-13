// parser.js — the client-side FRONTEND seam.
//
// nifparser (aoughwl/nifparser) is a pure-nimony Nim→NIF parser, compiled to
// JavaScript through the nimony-web JS backend into a single ~725 KB bundle
// (nifparser.js). It reproduces classic `nifler`'s `.p.nif` output byte-for-byte
// but — unlike nifler, which is classic-Nim only — it runs in the browser. This
// is the parser half of Tier 2 (live client-side compilation).
//
// Interface contract (a JS mirror of nifparser/src/webmain.nim):
//   IN : globalThis.__np_src   = the Nim source text (a string)
//        globalThis.__np_file  = relative path baked into NIF line-info suffixes
//        globalThis.__np_curly = "1" to also accept `{ … }` block bodies
//                                (experimental curly-brace mode), "" for classic
//                                indent-only parsing
//   RUN: (new Function(bundle + "main(0,[]);"))()   // fresh scope per parse
//   OUT: globalThis.__np_out   = the produced `.p.nif` bytes (a string)
//        globalThis.__np_diag  = JSON array of syntactic diagnostics:
//                                [{line:1-based, col:0-based, message}]
//
// A fresh `new Function` scope per parse is deliberate and required: nimony's
// generated `main` guards module-init so it runs exactly once — the parse lives
// in that init, so re-invoking a cached `main` would NOT re-parse. Re-evaluating
// the bundle is ~8 ms, which is why parsing is debounced off keystrokes below.
(function(){
  // Global curly toggle: callers that pass no `opts` follow whatever this is set
  // to (the UI flips window.NifiOpts.curly). Initialize defensively in case this
  // file loads before whoever else owns the object.
  window.NifiOpts = window.NifiOpts || { curly:false };

  const parser = { ready:false, parse:null };
  let bundleText = null, loadPromise = null;

  function loadBundle(){
    if(loadPromise) return loadPromise;
    loadPromise = fetch("nifparser.js").then(r=>{
      if(!r.ok) throw new Error("failed to load parser (nifparser.js): HTTP "+r.status);
      return r.text();
    }).then(t=>{ bundleText = t; return t; });
    return loadPromise;
  }

  // Synchronous once the bundle is loaded. Returns the `.p.nif` string, or throws.
  // `opts.curly` (optional) forces curly mode; omitting it follows window.NifiOpts.
  function parseSync(source, file, opts){
    if(!bundleText) throw new Error("parser not loaded yet");
    // __np_curly: "1" enables experimental `{ … }` block bodies, "" = indent-only.
    const curly = opts && ("curly" in opts) ? !!opts.curly : !!(window.NifiOpts && window.NifiOpts.curly);
    globalThis.__np_src  = String(source);
    globalThis.__np_file = file || "in.nim";
    globalThis.__np_curly = curly ? "1" : "";
    globalThis.__np_out  = "";
    (new Function(bundleText + "\nmain(0, []);"))();
    return globalThis.__np_out || "";
  }

  // Full result: { nif, diags }. `diags` are the parser's own coordinates
  // (line 1-based, col 0-based); the caller shifts col to Monaco's 1-based.
  // `opts.curly` (optional) forces curly mode; omitting it follows window.NifiOpts.
  function parseFull(source, file, opts){
    if(!bundleText) throw new Error("parser not loaded yet");
    // __np_curly: "1" enables experimental `{ … }` block bodies, "" = indent-only.
    const curly = opts && ("curly" in opts) ? !!opts.curly : !!(window.NifiOpts && window.NifiOpts.curly);
    globalThis.__np_src  = String(source);
    globalThis.__np_file = file || "in.nim";
    globalThis.__np_curly = curly ? "1" : "";
    globalThis.__np_out  = "";
    globalThis.__np_diag = "[]";
    (new Function(bundleText + "\nmain(0, []);"))();
    let diags = [];
    try{ diags = JSON.parse(globalThis.__np_diag || "[]"); }catch(_){ diags = []; }
    return { nif: globalThis.__np_out || "", diags };
  }

  parser.parse = parseSync;
  parser.parseFull = parseFull;
  window.NifiParser = parser;

  loadBundle().then(()=>{
    parser.ready = true;
    if(window.__nifiParserReady) window.__nifiParserReady(true);
  }).catch(e=>{
    parser.ready = false;
    if(window.__nifiParserReady) window.__nifiParserReady(false, String(e && e.message || e));
  });
})();
