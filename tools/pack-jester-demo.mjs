// pack-jester-demo.mjs - collect what public/jester-demo/ needs out of a Jester
// checkout. Nothing here compiles or rewrites anything: every `.s.nif` copied is
// a byte-exact artifact `tools/build_mod.exe` published into the mod's
// `.infiniteless/live/`, which is the same file the Unity player loads.
//
//   node tools/pack-jester-demo.mjs <jester-checkout> [out.json]
//
// `<jester-checkout>/variants/` holds the hot-swap set: <name>.nim beside the
// <name>.s.nif that was built from it, so the source shown on the page is the
// source the shipped artifact came from.
import fs from "node:fs";
import path from "node:path";

const root = process.argv[2];
if (!root) { console.error("usage: node tools/pack-jester-demo.mjs <jester-checkout> [out]"); process.exit(2); }
const out = process.argv[3] || "public/jester-demo/payload.json";

const b64 = (p) => fs.readFileSync(p).toString("base64");
const modules = {};                       // shared pool, keyed by artifact name

function collect(modDir) {
  const live = path.join(modDir, ".infiniteless", "live");
  const build = JSON.parse(fs.readFileSync(path.join(modDir, ".infiniteless", "build.json"), "utf8"));
  const names = [];
  for (const name of fs.readdirSync(live).sort()) {
    if (!name.endsWith(".s.nif") && !name.endsWith(".s.idx.nif")) continue;
    if (name === build.artifact) continue;
    if (!(name in modules)) modules[name] = b64(path.join(live, name));
    names.push(name);
  }
  return {
    id: build.mod,
    artifact: build.artifact,
    sha256: build.sha256,
    src: b64(path.join(live, build.artifact)),
    modules: names,
  };
}

const modsRoot = path.join(root, "Assets/StreamingAssets/Mods");
// `animated` says whether the mod's picture changes on its own. A menu does not,
// and the page only spends a frame on it when something happened - see boot.js
// on why a frame is the unit that costs.
const wanted = [
  { id: "infiniteless.shell", animated: false },
  { id: "demo.web", animated: true },
  { id: "example.readout", animated: true },
];
const mods = wanted.map((w) => {
  const m = collect(path.join(modsRoot, w.id));
  m.name = JSON.parse(fs.readFileSync(path.join(modsRoot, w.id, "mod.json"), "utf8")).name;
  m.animated = w.animated;
  return m;
});

// The modpack list the boot shell draws. A browser has no StreamingAssets, so
// what the Unity host discovers by walking a folder is discovered here.
const packRoot = path.join(root, "Assets/StreamingAssets/Modpacks");
const packs = [];
for (const name of fs.readdirSync(packRoot).sort()) {
  const manifest = path.join(packRoot, name, "modpack.json");
  if (!fs.existsSync(manifest)) continue;
  const m = JSON.parse(fs.readFileSync(manifest, "utf8"));
  packs.push({ id: m.id ?? name, name: m.name ?? name });
}

const variants = [];
const varRoot = path.join(root, "variants");
for (const f of fs.readdirSync(varRoot).sort()) {
  if (!f.endsWith(".s.nif")) continue;
  const key = f.slice(0, -".s.nif".length);
  variants.push({
    key,
    title: key.replace(/^[a-z]-/, ""),
    src: b64(path.join(varRoot, f)),
    source: fs.readFileSync(path.join(varRoot, key + ".nim"), "utf8"),
  });
}

const payload = { mods, modules, packs, variants };
fs.mkdirSync(path.dirname(out), { recursive: true });
fs.writeFileSync(out, JSON.stringify(payload));
console.error(`${out}: ${fs.statSync(out).size} bytes, ${mods.length} mods, ` +
  `${Object.keys(modules).length} shared modules, ${variants.length} variants, ${packs.length} modpacks`);
