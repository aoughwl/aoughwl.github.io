// engine.js — the client-side execution seam.
//
// The nimony interpreter `nifi` is compiled to JavaScript by aoughwl/nimony-web
// (bundle: nifi.js). We drive it exactly like the Node harness does, but in-tab:
//
//   IN : globalThis.__nifi_src  = the .s.nif bytes (byte-exact string)
//   RUN: (new Function(bundle + "main(0,[]);"))()      // fresh scope per run
//   OUT: globalThis.__nifi_out / __nifi_err / __nifi_exit
//
// A fresh `new Function` scope per run is deliberate: the bundle has top-level
// declarations that can't be redeclared in one global scope, and a fresh scope
// also gives each run clean interpreter state.
//
// Tier 1 (today): runs an example's PRE-COMPILED .s.nif — fully client-side,
// no backend. Tier 2 (frontend ported to JS) will compile whatever is in the
// editor; then window.NifiCore.compileAndRun takes over transparently.
(function(){
  const engine = { ready:false, tier:1, run:null };
  let bundleText = null;

  async function loadBundle(){
    if(bundleText) return bundleText;
    const r = await fetch("nifi.js");
    if(!r.ok) throw new Error("failed to load interpreter (nifi.js): HTTP " + r.status);
    bundleText = await r.text();
    return bundleText;
  }

  // Byte-exact fetch: .s.nif is a NIF byte stream; decode 1:1 (latin1), never UTF-8.
  async function fetchSnifBytes(name){
    const r = await fetch("assets/snif/" + name);
    if(!r.ok) throw new Error("missing bytecode asset: " + name + " (HTTP " + r.status + ")");
    const buf = new Uint8Array(await r.arrayBuffer());
    let s = "";
    for(let i = 0; i < buf.length; i++) s += String.fromCharCode(buf[i]);
    return s;
  }

  function runSnif(bytes){
    globalThis.__nifi_src = bytes;
    globalThis.__nifi_out = ""; globalThis.__nifi_err = ""; globalThis.__nifi_exit = 0;
    (new Function(bundleText + "\nmain(0, []);"))();
    return {
      stdout: globalThis.__nifi_out || "",
      stderr: globalThis.__nifi_err || "",
      exitCode: globalThis.__nifi_exit | 0
    };
  }
  // Tier 2: compile the editor buffer live and run it —
  //   source → nifparser (.p.nif) → nimsem (.s.nif) → nifi (run)
  // all client-side. Returns the same {stdout,stderr,exitCode} shape as runSnif.
  function compileAndRun(source){
    if(!(window.NifiParser && window.NifiParser.ready))
      return { stdout:"", stderr:"parser still loading…", exitCode:1 };
    if(!(window.NifiSem && window.NifiSem.ready))
      return { stdout:"", stderr:"semantic checker still loading…", exitCode:1 };
    // 1. parse → .p.nif (also yields syntax diagnostics, surfaced elsewhere)
    const { nif, diags: synDiags } = window.NifiParser.parseFull(source, "in.nim");
    if(synDiags && synDiags.length)
      return { stdout:"", stderr:"syntax error: "+synDiags[0].message+
        " (line "+synDiags[0].line+")", exitCode:1 };
    // 2. semcheck → typed .s.nif (+ semantic diagnostics)
    const { snif, diags } = window.NifiSem.compile(nif);
    if(!snif){
      const msg = (diags && diags.length)
        ? diags.map(d=>"  "+d.line+":"+d.col+"  "+d.message).join("\n")
        : "the program did not type-check.";
      return { stdout:"", stderr:"semantic error:\n"+msg, exitCode:1, diags };
    }
    // 3. run the typed .s.nif
    const res = runSnif(snif);
    res.diags = diags;
    return res;
  }
  // Exposed so index.html / future glue can call the interpreter directly.
  window.NifiCore = { runSnif, compileAndRun };

  async function run(req){
    await loadBundle();
    // Tier 2 hook: when the frontend is ported, compile the editor buffer live.
    if(window.NifiCore && typeof window.NifiCore.compileAndRun === "function")
      return window.NifiCore.compileAndRun(req.source);
    const ex = req.example;
    if(!ex || !ex.snif)
      return { stdout:"", stderr:"This example has no pre-compiled bytecode yet.", exitCode:1 };
    return runSnif(await fetchSnifBytes(ex.snif));
  }

  engine.run = run;
  window.NifiEngine = engine;

  loadBundle().then(() => {
    engine.ready = true;
    if(window.__nifiEngineReady) window.__nifiEngineReady(true);
    if(window.__nifiLspStatus) window.__nifiLspStatus("off");
  }).catch(e => {
    engine.ready = false;
    if(window.__nifiEngineReady) window.__nifiEngineReady(false, String(e && e.message || e));
  });
})();
