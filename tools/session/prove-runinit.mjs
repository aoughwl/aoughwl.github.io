// prove-runinit.mjs — does starting a session RUN THE MODULE'S TOP LEVEL?
//
//   node tools/session/prove-runinit.mjs
//
// This exists because the answer decides how every mod behaves and the failure
// is silent. A module's top level is not just `main`; it is every module-level
// INITIALIZER. A mod that declares `pendingDelete = -1` and is loaded without
// its top level gets 0 instead, and `0 >= 0` is "a confirmation dialog is open".
// Nothing raises, nothing is declined, and the mod simply behaves as though a
// user did something they did not.
//
// The `a1` fixture's top level ends with `n = n + 1`, so `read()` answers 1 when
// the top level ran and 0 when it did not. One number, no ambiguity.
import fs from "node:fs";
import path from "node:path";
import vm from "node:vm";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const BUNDLE = path.join(HERE, "..", "..", "public", "playground", "aowli_session.js");
const FIXNAME = process.env.FIXTURE || "nc_a1";
const FIX = path.join(HERE, "fixture", FIXNAME);
const latin1 = (p) => fs.readFileSync(p).toString("latin1");

const files = fs.readdirSync(FIX);
// The main module is the one named after the entry file, not merely "not sys":
// a fixture with its own imports has several non-`sys` modules and picking the
// wrong one loads a dependency as the program.
const MAINPREFIX = process.env.MAINPREFIX || "";
const main = files.find((f) => f.endsWith(".s.nif") && !f.startsWith("sys") &&
                               (!MAINPREFIX || f.startsWith(MAINPREFIX)))
          || files.find((f) => f.endsWith(".s.nif") && !f.startsWith("sys"));
let mods = "";
for (const f of files) {
  if (f === main) continue;
  if (!f.endsWith(".s.nif") && !f.endsWith(".s.idx.nif")) continue;
  const raw = latin1(path.join(FIX, f));
  let b = "";
  for (let i = 0; i < raw.length; i++) {
    const c = raw.charCodeAt(i);
    b += c >= 0x80 ? "\\x" + c.toString(16).padStart(2, "0") : raw[i];
  }
  mods += f + "\t" + b.length + "\n" + b;
}

globalThis.stat = globalThis.lstat = globalThis.fstat = () => -1;
globalThis.__sess_null = null;
globalThis.__sess_src = latin1(path.join(FIX, main));
globalThis.__sess_mods = mods;
globalThis.__sess_in = "";
vm.runInThisContext(fs.readFileSync(BUNDLE, "utf8"), { filename: "aowli_session.js" });
globalThis.main(0, []);

const fails = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
  if (!ok) fails.push(what);
};
const read = () => { globalThis.__sess_call("read"); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };

globalThis.__sess_boot();                 // runInit = true — what a mod gets
check("boot succeeded", globalThis.__sess_ok, true);

if (FIXNAME.indexOf("nc_scale") === 0 || FIXNAME === "nc_twomod" || FIXNAME === "nc_sdkenum" || FIXNAME === "nc_staged" || FIXNAME === "nc_modlive" || FIXNAME === "nc_2048" || FIXNAME === "nc_bisect") {
  // Does a module's SIZE break enum literal ordinals? The launcher reads every
  // literal as 0; a small module does not.
  const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };
  const ordsName = (FIXNAME === "nc_sdkenum" || FIXNAME === "nc_staged" || FIXNAME === "nc_modlive" || FIXNAME === "nc_2048" || FIXNAME === "nc_bisect") ? "enumOrds" : "ords";
  const maskName = (FIXNAME === "nc_sdkenum" || FIXNAME === "nc_staged" || FIXNAME === "nc_modlive" || FIXNAME === "nc_2048" || FIXNAME === "nc_bisect") ? "enumMask" : "eqMask";
  check("ordinals packed", call(ordsName), 3210);
  check("first value compared to all four (bitmask)", call(maskName), 1);
} else if (FIXNAME === "nc_enumeq") {
  // ENUM EQUALITY. The launcher compares one value against two different
  // literals in the same frame and both answer true, which is how it opens a
  // delete confirmation nobody asked for.
  const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; const v = r && "v" in r ? r.v : null; return v; };
  check("ord of the value under test", call("ordValue"), 0);
  check("ord of ActDelete", call("ordDelete"), 1);
  check("value == ActNone  (true)", call("isNone"), true);
  check("value == ActDelete (FALSE)", call("isDelete"), false);
  check("value == ActEdit   (FALSE)", call("isEdit"), false);
  check("value != ActNone   (FALSE)", call("notNone"), false);
  check("via a local: == ActDelete (FALSE)", call("localIsDelete"), false);
  check("via a local: != ActNone   (FALSE)", call("localNotNone"), false);
} else if (FIXNAME === "nc_enumlast") {
  // The launcher's exact `case` shape: every value has its own `of`, there is no
  // `else`, and the ZEROTH value's branch is written LAST. Each of these must
  // answer 0, because the value under test IS the zeroth.
  const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };
  check("zeroth branch written FIRST", call("firstBranch"), 0);
  check("zeroth branch written LAST", call("lastBranch"), 0);
  check("zeroth branch LAST, case on the call", call("lastBranchOnCall"), 0);
} else if (FIXNAME === "nc_enumcase") {
  // A `case` over an enum RETURNED FROM A CALL. The shell behaves as though the
  // zeroth value (the one the case does not list) lands in the FIRST `of`
  // branch instead of `else` — which is why its launcher opened a delete
  // confirmation on every row, every frame, with nothing clicked.
  const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };
  check("the value really is the zeroth (ord 0)", call("ordOfDecide"), 0);
  check("case over a CALL picks else (99)", call("viaCall"), 99);
  check("case over a LOCAL picks else (99)", call("viaLocal"), 99);
} else if (FIXNAME === "nc_bigvars") {
  // A REAL MOD'S var block is long and mixed, and the shell behaves as though
  // one of its `= -1` globals is 0. If a big block initialises unevenly, every
  // mod that guards on `x < 0` is quietly broken.
  const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };
  check("the first -1 in the block", call("firstNeg"), -1);
  check("one in the middle", call("midNeg"), -1);
  check("the last one", call("lastNeg"), -1);
  check("ALL forty read as -1", call("negCount"), 40);
} else {
  check("__sess_boot RUNS the top level", read(), 1);
  globalThis.__sess_stop();
  globalThis.__sess_load();               // runInit = false — the REPL's shape
  check("load succeeded", globalThis.__sess_ok, true);
  check("__sess_load does NOT run the top level", read(), 0);
}

console.log(fails.length ? `\nFAILED: ${fails.length}` : "\nPASS: boot runs the top level, load does not.");
process.exit(fails.length ? 1 : 0);
