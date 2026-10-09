// playground-drift.mjs — are the two deployed copies of the playground the same?
//
//   node tools/playground-drift.mjs [NIMONY_PLAYGROUND=~/nimony-playground]
//
// The playground ships twice: public/playground/ here, and the aoughwl/nimony-playground
// repo. Every deploy is a per-file `cp`, so a file updated in one and forgotten in the
// other ships silently. Measured 2026-10-09: 24 files differed, 23 of them newer on
// the site, and the repo's checker could not run std/sets. Exit 1 lists every file that
// differs or exists on one side only (ignoring tests/, tools/, node_modules/, .git/).
"use strict";
import fs from "node:fs";
import path from "node:path";
import os from "node:os";
import crypto from "node:crypto";

const here = path.dirname(new URL(import.meta.url).pathname);
const site = path.join(here, "..", "public", "playground");
const repo = path.resolve(process.argv[2] || path.join(os.homedir(), "nimony-playground"));
const SKIP = new Set([".git", "node_modules", "tests", "tools"]);
// The repo is also a site root of its own, so it carries icons and a manifest the
// site serves from its top level instead.
const REPO_ONLY = new Set(["apple-touch-icon.png", "favicon-16.png", "favicon-32.png", "icon-192.png",
  "icon-512.png", "icon-maskable-512.png", "og-image.png", "site.webmanifest",
  // gitignored on the site, so never deployed from here
  "playground-standalone.html"]);

function walk(root) {
  const out = new Map();
  const go = (d) => {
    for (const e of fs.readdirSync(d, { withFileTypes: true })) {
      if (SKIP.has(e.name)) continue;
      const p = path.join(d, e.name);
      if (e.isDirectory()) go(p);
      else out.set(path.relative(root, p), p);
    }
  };
  go(root);
  return out;
}
const sha = (p) => crypto.createHash("sha1").update(fs.readFileSync(p)).digest("hex");

if (!fs.existsSync(repo)) { console.error(`no checkout at ${repo}`); process.exit(2); }
const a = walk(site), b = walk(repo);
let same = 0;
const bad = [];
for (const [k, p] of a) {
  if (REPO_ONLY.has(k)) continue;
  if (!b.has(k)) bad.push(`only site   ${k}`);
  else if (sha(p) !== sha(b.get(k))) {
    const newer = fs.statSync(p).mtimeMs > fs.statSync(b.get(k)).mtimeMs ? "site" : "repo";
    bad.push(`differs     ${k}  (${newer} newer)`);
  } else same++;
}
for (const k of b.keys()) if (!a.has(k) && !REPO_ONLY.has(k)) bad.push(`only repo   ${k}`);
if (same < 20) { console.error(`only ${same} identical files — wrong directories? refusing`); process.exit(2); }
for (const l of bad.sort()) console.log(l);
console.log(`\nplayground-drift: ${same} identical, ${bad.length} not`);
process.exit(bad.length ? 1 : 0);
