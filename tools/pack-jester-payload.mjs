// pack-jester-payload.mjs — collect what public/playground/jester-payload.json
// needs out of a Jester checkout.
//
//   node tools/pack-jester-payload.mjs <jester-checkout> [out.json]
//   node tools/pack-jester-payload.mjs <jester-checkout> --list
//
// NOTHING HERE COMPILES OR REWRITES ANYTHING. Every `.s.nif` copied is a
// byte-exact artifact `tools/build_mod.exe` published into the mod's
// `.jester/live/`, which is the same file the Unity player loads. That is the
// claim the whole demo rests on, so this tool is deliberately incapable of
// producing anything else: it reads, base64s, and writes.
//
// WHICH MODS GO IN. Not a hardcoded list of ids — those go stale the moment a
// mod is renamed, and this repo has already been through one rename. A mod is a
// candidate when it is BUILT (its `.jester/build.json` names an artifact that is
// actually on disk) and its build is CURRENT for the SDK the checkout has. Which
// of those a browser can actually serve is not knowable by reading: it depends
// on which host calls the mod reaches at runtime, through the SDK, which is a
// call graph rather than a string. So that question is answered by RUNNING them
// — `tools/session/triage-mods.mjs` loads each one in a real browser and records
// what the host had to decline. This tool packs; that one judges.
import fs from "node:fs";
import path from "node:path";

const root = process.argv[2];
if (!root) {
  console.error("usage: node tools/pack-jester-payload.mjs <jester-checkout> [out.json|--list]");
  process.exit(2);
}
const arg3 = process.argv[3] || "public/playground/jester-payload.json";
const LIST_ONLY = arg3 === "--list";
const out = LIST_ONLY ? null : arg3;

// Only these mods are packed by default. The list is a SIZE decision, not a
// capability one: the full 69 built mods carry ~40 MB of artifacts and a demo
// that makes a visitor wait for all of it is a worse demo. `--all` overrides.
const WANT = process.argv.includes("--all") ? null : new Set([
  "aoughwl.shell",      // the launcher the desktop player boots into
  "example.hello",
  "example.counter",
  "example.press",
  "example.readout",
  "example.escape",
  "example.filer",
  "aoughwl.fonttest",
  "aoughwl.grid",
  "aoughwl.web",        // a web browser, as a mod, inside a web page
  "jester.2048",
]);

const modsRoot = path.join(root, "Assets/StreamingAssets/Mods");
if (!fs.existsSync(modsRoot)) { console.error("no Mods/ under " + root); process.exit(2); }

const b64 = (p) => fs.readFileSync(p).toString("base64");
const modules = {};                       // shared pool, keyed by artifact name

function collect(modDir, id) {
  const buildFile = path.join(modDir, ".jester", "build.json");
  if (!fs.existsSync(buildFile)) return null;
  const build = JSON.parse(fs.readFileSync(buildFile, "utf8"));
  const live = path.join(modDir, ".jester", "live");
  if (!build.artifact || !fs.existsSync(path.join(live, build.artifact))) return null;

  const names = [];
  for (const name of fs.readdirSync(live).sort()) {
    // `.s.nif` is the typed module the interpreter loads; `.s.idx.nif` is the
    // sidecar index `programs.load` reads unconditionally. The `.p.`/`.x.`/`.dce.`
    // artifacts are earlier rungs of the same tower and nothing loads them here.
    if (!name.endsWith(".s.nif") && !name.endsWith(".s.idx.nif")) continue;
    if (name === build.artifact) continue;
    if (!(name in modules)) modules[name] = b64(path.join(live, name));
    names.push(name);
  }

  let manifest = {};
  try { manifest = JSON.parse(fs.readFileSync(path.join(modDir, "mod.json"), "utf8")); } catch (_) {}

  // THE SOURCE SHIPS WITH THE MOD. The artifact proves the demo runs the real
  // thing; the source is what makes it a demo of a MODDABLE engine rather than a
  // video of one. With it the page can drop a mod into the editor's explorer,
  // which is the natural first move — read the launcher you are looking at,
  // change it, and watch the change land in the running program.
  //
  // `.meta` files are Unity's, not the mod's, and nothing here reads them.
  const source = {};
  for (const f of fs.readdirSync(modDir)) {
    if (f.endsWith(".meta")) continue;
    const full = path.join(modDir, f);
    if (!fs.statSync(full).isFile()) continue;
    if (!/\.(nim|json|md)$/i.test(f)) continue;
    source[f] = fs.readFileSync(full, "utf8");
  }

  return {
    id: build.mod || id,
    name: manifest.name || build.mod || id,
    blurb: manifest.description || "",
    artifact: build.artifact,
    sha256: build.sha256,
    src: b64(path.join(live, build.artifact)),
    modules: names,
    source,
    // The SDK stamp this artifact was built against. The player REFUSES a mod
    // whose stamp differs from the one the boot shell carries, so this is the
    // one field that says whether the demo is shipping what the player would
    // actually load. See the check after packing.
    sdk: build.sdk || "",
    // Whether the mod's picture changes on its own. Unknown until it runs, so it
    // starts true (spend frames) and `triage-mods.mjs` writes the real answer.
    animated: true,
  };
}

const found = [], missing = [];
for (const dir of fs.readdirSync(modsRoot).sort()) {
  if (WANT && !WANT.has(dir)) continue;
  const full = path.join(modsRoot, dir);
  if (!fs.statSync(full).isDirectory()) continue;
  const m = collect(full, dir);
  if (m) found.push(m); else missing.push(dir);
}
if (WANT) for (const w of WANT) if (!found.some((m) => m.id === w) && !missing.includes(w)) missing.push(w + " (no such mod)");

// ── DO THE ARTIFACTS AGREE WITH EACH OTHER, AND WITH THE PLAYER? ───────────
//
// The whole demo rests on "these are the bytes the desktop player loads", and
// until now nothing checked it. The SDK stamp is deliberately ONE value shared
// by every mod: the host refuses any mod whose stamp differs from the boot
// shell's, because otherwise whichever loaded first would impose its SDK on all
// the others. So a payload with two stamps in it is a payload the player would
// refuse half of.
//
// This is not hypothetical. On 2026-09-20 a single edit under `ModSdk/` moved
// the stamp four times in one evening, and for most of it the demo was shipping
// artifacts no player would accept — invisible here, because the browser host
// does not enforce the stamp. A mixed payload is therefore SILENT in a browser
// and fatal on the desktop, which is exactly the kind of drift a packer should
// refuse to ship quietly.
//
// `--require-sdk <hash>` pins it to a known-good value (the one the player was
// built against); with no pin it only demands internal agreement.
function checkStamps(mods) {
  const byStamp = new Map();
  for (const m of mods) {
    const k = m.sdk || "(none recorded)";
    if (!byStamp.has(k)) byStamp.set(k, []);
    byStamp.get(k).push(m.id);
  }
  const pinAt = process.argv.indexOf("--require-sdk");
  const pin = pinAt >= 0 ? process.argv[pinAt + 1] : null;

  if (byStamp.size === 1 && !pin) {
    console.error(`  SDK stamp: ${[...byStamp.keys()][0].slice(0, 12)} (all ${mods.length} agree)`);
    return true;
  }
  if (byStamp.size > 1) {
    console.error("\n  !! MIXED SDK STAMPS — the player would refuse some of these:");
    for (const [stamp, ids] of byStamp)
      console.error(`     ${stamp.slice(0, 12)}  ${ids.join(", ")}`);
    console.error("     Rebuild every packed mod against one SDK before shipping this.\n");
    return false;
  }
  const only = [...byStamp.keys()][0];
  if (pin && !only.startsWith(pin)) {
    console.error(`\n  !! SDK stamp ${only.slice(0, 12)} does not match the pinned ${pin}`);
    console.error("     Either the mods or the player is out of date.\n");
    return false;
  }
  console.error(`  SDK stamp: ${only.slice(0, 12)} (all ${mods.length} agree, matches the pin)`);
  return true;
}

// ── THE SDK'S SOURCE, SO A CLONED MOD TYPE-CHECKS ──────────────────────────
//
// Cloning a mod into the explorer put its real `.nim` files there and every one
// of their imports came back undeclared, because `import jester` names a module
// that lives in the ENGINE, not in the mod. The artifact carries the SDK
// compiled in, so the mod RAN fine — it just could not be read, which is a
// strange thing for a demo whose whole point is that you can read and change
// what you are looking at.
//
// So the SDK's source ships too, as one file of path -> text, and the panel
// mounts it as a read-only project the moment anything is cloned. The
// playground's existing multi-module semcheck resolves a bare `import draw`
// against any open project by basename, which is exactly how the desktop
// toolchain resolves it, so nothing new had to be taught to resolve anything.
//
// Mounted ON CLONE and not at boot, deliberately: `buildMulti` switches the
// whole session from aowlsem to nimsem as soon as a second user module exists,
// and a visitor typing a hello-world should not silently change checkers.
function packSdkSource() {
  const sdkRoot = path.join(root, "Packages/com.aoughwl.jester/ModSdk");
  if (!fs.existsSync(sdkRoot)) { console.error("  no ModSdk/ under " + root + " — cloned mods will not resolve their imports"); return; }
  const files = {};
  let bytes = 0;
  for (const f of fs.readdirSync(sdkRoot).sort()) {
    if (!f.endsWith(".nim")) continue;
    const text = fs.readFileSync(path.join(sdkRoot, f), "utf8");
    files[f] = text;
    bytes += text.length;
  }
  const dest = path.join(path.dirname(out), "assets", "jester-sdk.json");
  fs.mkdirSync(path.dirname(dest), { recursive: true });
  fs.writeFileSync(dest, JSON.stringify({ files, built: new Date().toISOString().slice(0, 10) }));
  console.error(`  assets/jester-sdk.json: ${Object.keys(files).length} SDK modules, ${(bytes / 1024).toFixed(0)} KB`);
}

if (LIST_ONLY) {
  for (const m of found) console.log(`${m.id}\t${m.artifact}\t${m.modules.length} modules`);
  if (missing.length) console.log("\nnot packed (not built): " + missing.join(", "));
  process.exit(0);
}

// WHAT SHIPS IN THE PAGE, AND WHAT IS INSTALLED.
//
// Everything used to ship at once, which made the payload the cost of opening
// the page at all — and made "install a mod" a thing the demo talked about
// rather than did. So the page carries only what it needs to be useful with
// nothing installed (the launcher, and enough to play), and every other mod is
// published as its OWN bundle that the store fetches on demand.
//
// A bundle is self-contained: it carries its artifact AND the sibling modules
// that artifact needs, because a mod installed from somewhere else cannot assume
// this page already holds them.
const BUILTIN = new Set([
  "aoughwl.shell",      // the launcher: without it there is nothing to boot into
  "jester.2048",        // something to actually PLAY, with nothing installed yet
  "example.hello",
]);
const builtin = found.filter((m) => BUILTIN.has(m.id));
const installable = found.filter((m) => !BUILTIN.has(m.id));

// The shared pool for the page's own payload holds only what the built-in mods
// reference; anything else would be weight nobody asked for.
const keep = {};
for (const m of builtin) for (const n of m.modules) keep[n] = modules[n];

const stampsAgree = checkStamps(found);
const payload = { mods: builtin, modules: keep,
                  sdk: (found[0] && found[0].sdk) || "",
                  built: new Date().toISOString().slice(0, 10) };
fs.mkdirSync(path.dirname(out), { recursive: true });
fs.writeFileSync(out, JSON.stringify(payload));
const mb = (n) => (n / (1024 * 1024)).toFixed(1);
console.error(`${out}: ${mb(fs.statSync(out).size)} MB, ${builtin.length} built-in mods`);

// EVERYTHING ELSE IS PUBLISHED AS A CONTENT SET, NOT AS A BUNDLE FOR A PANEL.
//
// This used to write one `mods/<id>.json` per installable mod plus a
// `jester-registry.json`, which a "Get mods" panel beside the canvas fetched
// and installed itself. That panel is gone: the shell ALREADY downloads and
// installs mods — `Search online`, a confirm dialog that lists what is about to
// arrive, a progress row, sha256 per file — and a second installer next to it
// was a second answer to a question Jester had already answered. See
// `tools/make-content-set.mjs`, which publishes the same mods at their real
// repo paths behind a `content.json` the shell fetches over plain HTTP, and the
// `jester_content_*` family in `public/playground/jester-host.js`, which
// answers the calls that drive it.
//
// So this tool now packs ONLY what the page carries with nothing installed.
packSdkSource();

if (installable.length)
  console.error(`  ${installable.length} more mod(s) are published as a content set — ` +
                `run tools/make-content-set.mjs for those`);

// A mixed payload is a real defect, so it is an exit code and not just a line of
// output — a packer run from a script must be able to stop on it.
if (!stampsAgree) process.exit(3);
