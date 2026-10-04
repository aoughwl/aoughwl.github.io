// prove-enum.mjs — do a mod's OWN enum literals have their real ordinals?
//
//   node tools/session/prove-enum.mjs
//
// THE BUG THIS GUARDS. `runtime.publishFieldDecls` published `fld`/`gfld` — an
// object's fields — but not `efld`, an enum's. Its own comment explains the
// asymmetry it exists to remove: a MAIN-MODULE symbol carries an empty module
// suffix (`PA.0.`, one dot), the embedded `.index` only records two-dot symbols,
// so `tryLoadSym` answers `LacksModuleName`. That is exactly as true of an enum
// field as of an object field, and enum fields were left out.
//
// What it cost: `evalSym`'s enum branch reads the ordinal out of the `efld`
// decl, and with no decl to find it falls through to its last resort, `vNil()`.
// Every enum literal in the module then evaluates to NIL — so `ord(X)` is 0 for
// all of them, and `valueEquals` compares two nils through its `asInt` fallback
// and answers 0 == 0, TRUE. One value equals EVERY literal, and `case` takes its
// first arm.
//
// In the launcher that meant `drawRow` returning `RowNone` while the caller ran
// the `RowDelete` arm: a delete confirmation on every row, every frame, with
// nothing clicked — and because that dialog gates the key handling, the shell
// could not launch anything at all.
//
// WHY THE FIXTURE IS A REAL MOD. Small modules did not reproduce it: a
// hand-written enum in a two-module program resolves fine. It took a mod with
// the SDK's closure behind it, which is why this gate loads `jester.2048`'s
// actual published artifacts rather than something written for the occasion. If
// this file ever needs regenerating: copy a built mod's `.jester/live/*.s.nif`
// and `*.s.idx.nif` into `fixture/nc_2048/`.
import fs from "node:fs";
import path from "node:path";
import vm from "node:vm";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const BUNDLE = path.join(HERE, "..", "..", "public", "playground", "aowli_session.js");
const FIX = path.join(HERE, "fixture", "nc_2048");
const latin1 = (p) => fs.readFileSync(p).toString("latin1");

if (!fs.existsSync(FIX)) {
  console.error("no fixture at " + FIX + " — see the header for how to regenerate it");
  process.exit(2);
}
const files = fs.readdirSync(FIX);
const main = files.find((f) => /^jes3xle96\.s\.nif$/.test(f));
if (!main) { console.error("the 2048 artifact is not in the fixture"); process.exit(2); }

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
const call = (n) => { globalThis.__sess_call(n); const r = globalThis.__sess_ret; return r && "v" in r ? r.v : "(" + (r && r.k) + ")"; };

globalThis.__sess_boot();
check("the mod loaded", globalThis.__sess_ok, true);

// THE FIXTURE IS A FROZEN SNAPSHOT that still carries the probe procs this bug
// was found with — `enumOrds` packs ord(PA..PD) as one number and `enumMask`
// compares the zeroth value against all four. They were removed from the live
// mod once the cause was known; keeping them here means the gate asserts the
// ordinals themselves rather than something downstream of them.
check("ord(PA,PB,PC,PD) packed", call("enumOrds"), 3210);
check("the zeroth value equals ONLY itself", call("enumMask"), 1);

// And the mod still works as a mod, so a future "fix" cannot pass this by
// breaking loading.
check("the mod answers with real state", call("score"), 0);
check("...and its highest tile is a number", typeof call("highestTile"), "number");

console.log(fails.length ? `\nFAILED: ${fails.length}` : "\nPASS: a mod's enum-backed state resolves.");
process.exit(fails.length ? 1 : 0);
