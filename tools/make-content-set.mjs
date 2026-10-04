// make-content-set.mjs — publish a Jester CONTENT SET the shell can install.
//
//   node tools/make-content-set.mjs <jester-checkout> [out-dir]
//
// WHY THIS EXISTS. The demo used to grow its own "Get mods" button: a panel
// beside the canvas, its own registry file, its own installer, its own idea of
// what an installed mod is. None of that is Jester. The shell — the launcher
// this demo boots into, the same one the desktop player boots into — ALREADY
// downloads and installs mods: `Search online` lists a registry, Enter queues a
// bundle, and `stepQueueFetching` drives `contentStage / contentNeeds /
// contentFile / contentCommit` over plain HTTP. Every one of those is a host
// call, and a host call is something a browser can answer. So the browser
// answers them (see the `jester_content_*` family in jester-host.js) and the
// bolted-on panel is gone: installing a mod in the web demo is now the same
// code path, in the same UI, as installing one on the desktop.
//
// WHAT A CONTENT SET IS, exactly. `Runtime/Core/ContentUpdate.cs` defines it and
// `tools/release.exe content` writes one; this is the same shape for a SUBSET,
// published at its files' real paths the way `aoughwl/minecraft` commits its
// tree. A manifest names a version, the SDK stamp every mod in it was built
// against, and one entry per file: `path`, `sha256`, `size`. There is no url —
// the shell fetches `dirOf(manifestUrl) & path`, so the layout under this
// directory IS the contract.
//
// `mode: "add"` and not the default `"set"`: a whole set means "this is the
// entire content of the install, and a folder I do not mention is a folder the
// commit takes away", which for a handful of example mods would mean deleting
// the shell that is running. An addition joins what is already there. See
// `ContentManifest` and docs/MODPACKS.md.
//
// WHICH FILES. Mirrors `collectMod` in tools/release.nim, because a browser that
// installs a different file list from the player is a demo of something else:
//   - everything in the mod folder that is not `.jester/` and not `*.meta`
//   - `.jester/build.json` (the receipt: artifact name, sha256, SDK stamp)
//   - `.jester/live/*.s.nif` and `*.s.idx.nif` (what the interpreter loads)
import fs from "node:fs";
import path from "node:path";
import crypto from "node:crypto";

const root = process.argv[2];
if (!root) {
  console.error("usage: node tools/make-content-set.mjs <jester-checkout> [out-dir]");
  process.exit(2);
}
const outDir = process.argv[3] || "public/playground/content/aoughwl.examples";

// The mods this set offers. Deliberately the ones the page does NOT ship
// built-in: a store that offers you what you already have is a store with
// nothing in it. `tools/pack-jester-payload.mjs` owns the other half of this
// split and its BUILTIN set is the complement of this one.
const WANT = new Set([
  "example.counter", "example.press", "example.readout", "example.escape",
  "example.filer", "aoughwl.fonttest", "aoughwl.grid",
]);

const modsRoot = path.join(root, "Assets/StreamingAssets/Mods");
if (!fs.existsSync(modsRoot)) { console.error("no Mods/ under " + root); process.exit(2); }

const sha256 = (buf) => crypto.createHash("sha256").update(buf).digest("hex");

// One mod's shippable files, as [relative-path-inside-the-mod, absolute-source].
function shippable(dir, prefix = "") {
  const out = [];
  for (const name of fs.readdirSync(dir).sort()) {
    const full = path.join(dir, name);
    const rel = prefix + name;
    if (fs.statSync(full).isDirectory()) {
      // Unity's own "not part of the project" mark, and every importer's output.
      if (name.toLowerCase() === "imported" || name.endsWith("~")) continue;
      out.push(...shippable(full, rel + "/"));
      continue;
    }
    if (rel.endsWith(".meta")) continue;
    if (rel.startsWith(".jester/")) {
      if (rel === ".jester/build.json") { out.push([rel, full]); continue; }
      if (rel.startsWith(".jester/live/") &&
          (rel.endsWith(".s.nif") || rel.endsWith(".s.idx.nif"))) out.push([rel, full]);
      continue;
    }
    out.push([rel, full]);
  }
  return out;
}

const files = [], stamps = new Map();
let copied = 0, bytes = 0;
fs.rmSync(outDir, { recursive: true, force: true });

for (const id of [...WANT].sort()) {
  const dir = path.join(modsRoot, id);
  if (!fs.existsSync(dir)) { console.error("  no such mod: " + id); process.exit(2); }
  const receipt = path.join(dir, ".jester", "build.json");
  if (!fs.existsSync(receipt)) { console.error(`  ${id} is not built (no build.json)`); process.exit(2); }
  const build = JSON.parse(fs.readFileSync(receipt, "utf8"));
  stamps.set(build.sdk || "(none)", (stamps.get(build.sdk || "(none)") || []).concat(id));

  for (const [rel, src] of shippable(dir)) {
    const buf = fs.readFileSync(src);
    const p = "Mods/" + id + "/" + rel;
    const dest = path.join(outDir, p);
    fs.mkdirSync(path.dirname(dest), { recursive: true });
    fs.writeFileSync(dest, buf);
    files.push({ path: p, sha256: sha256(buf), size: buf.length });
    copied++; bytes += buf.length;
  }
}

// ONE SDK STAMP OR NOTHING. `ContentStage.VerifySdk` refuses a set whose mods
// disagree, and so does the browser host — because every mod compiles the SDK
// into its own artifacts under one module id, and whichever loads first would
// impose its own on all the others. Catching it here means catching it before
// anyone downloads 30 MB to be told no.
if (stamps.size !== 1) {
  console.error("\n  !! MIXED SDK STAMPS — this set would be refused on commit:");
  for (const [s, ids] of stamps) console.error(`     ${s.slice(0, 12)}  ${ids.join(", ")}`);
  process.exit(3);
}
const sdk = [...stamps.keys()][0];

const pinAt = process.argv.indexOf("--require-sdk");
if (pinAt >= 0 && !sdk.startsWith(process.argv[pinAt + 1])) {
  console.error(`\n  !! SDK stamp ${sdk.slice(0, 12)} does not match the pinned ${process.argv[pinAt + 1]}`);
  process.exit(3);
}

const manifest = {
  format: 1,
  set: path.basename(outDir),
  // A version, because `ContentStage` parses it as a semantic version and names
  // the staging area after it — and because re-opening the same version is what
  // makes a half-finished download resume instead of restart.
  version: "1.0." + files.length,
  host: "*",
  sdk,
  notes: `${WANT.size} example mods, built from source in this repo.`,
  mode: "add",
  files,
  remove: [],
};
fs.writeFileSync(path.join(outDir, "content.json"), JSON.stringify(manifest, null, 2) + "\n");
console.error(`${outDir}/content.json: ${WANT.size} mods, ${copied} files, ` +
              `${(bytes / (1024 * 1024)).toFixed(1)} MB, SDK ${sdk.slice(0, 12)}`);
