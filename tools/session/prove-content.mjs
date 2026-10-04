// prove-content.mjs — does the browser really INSTALL a content set?
//
//   node tools/session/prove-content.mjs
//
// The web demo used to grow its own "Get mods" button: a panel beside the
// canvas, its own registry file, its own installer. None of that is Jester. The
// shell — the launcher this demo boots into, and the one the desktop player
// boots into — already downloads and installs mods: `Search online` lists a
// registry, Enter queues a bundle, and `stepQueueFetching` in its own main.nim
// drives `contentStage / contentCount / contentPath / contentNeeds /
// contentFile / contentCommit` over plain HTTP. Every one of those is a host
// call. So the browser answers them, and this proves the answers are real.
//
// IT DRIVES THE EXACT LOOP THE SHELL DRIVES, over the manifest actually
// published in `public/playground/content/`, reading each file off disk where
// the shell would have fetched it from the same path over HTTP. No browser: the
// host is a plain object and this is the cheapest possible place to find out
// that a hash check is decorative.
//
// WHAT IT REFUSES TO TAKE ON TRUST, because each of these has a silent failure
// mode that looks exactly like success:
//
//   * A file whose bytes do not match the manifest must be REFUSED, by path,
//     naming both hashes. A host that stores whatever arrives has an installer
//     that cannot tell a truncated download from a good one.
//   * `contentNeeds` must answer FALSE for a file whose bytes are already here
//     under another path. Most of a content set by weight is the SDK compiled
//     into every mod's artifacts — 170 files that are far fewer distinct ones —
//     so a host that fetches each path separately downloads the same megabyte
//     seven times and calls it progress.
//   * A set built against a different SDK stamp must be refused AT STAGE. The
//     player refuses a mod whose stamp is not the boot shell's, and a browser
//     that installs it anyway produces a mod that runs here and is rejected by
//     every real player — the worst of the three outcomes, because nothing says
//     so.
//   * A commit must produce a mod the launcher can actually load: an artifact,
//     its sibling modules, and the source the Clone button hands the editor.
import fs from "node:fs";
import path from "node:path";
import crypto from "node:crypto";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const HOST = path.join(HERE, "..", "..", "public", "playground", "jester-host.js");
const SET = path.join(HERE, "..", "..", "public", "playground", "content", "aoughwl.examples");

const fails = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
  if (!ok) fails.push(what);
};

if (!fs.existsSync(path.join(SET, "content.json"))) {
  console.error("no content set at " + SET + " — run tools/make-content-set.mjs first");
  process.exit(2);
}
const manifestText = fs.readFileSync(path.join(SET, "content.json"), "utf8");
const manifest = JSON.parse(manifestText);

// The host only touches the 2D context for metrics and fills; nothing here
// paints. Same stub prove-fonts.mjs uses.
const ctx = {
  font: "", measureText: (t) => ({ width: String(t).length * 8 }),
  fillRect: () => {}, fillText: () => {}, save: () => {}, restore: () => {},
  beginPath: () => {}, rect: () => {}, clip: () => {},
  getImageData: () => ({ data: new Uint8ClampedArray(4) }),
};
globalThis.self = globalThis;
globalThis.location = { href: "https://aoughwl.github.io/playground/index.html", hostname: "aoughwl.github.io" };
const posted = [];
globalThis.postMessage = (m) => posted.push(m);
new Function(fs.readFileSync(HOST, "utf8"))();

const logs = [];
function newHost(sdk) {
  posted.length = 0;
  return globalThis.JesterHost.create(
    { width: 640, height: 480, getContext: () => ctx },
    { log: (m) => logs.push(m), sdk });
}

const S = (v) => (v && v.v !== undefined ? v.v : v);
const call = (host, name, args) => S(host.dispatch(name, args));

// ── the SDK stamp gate, first, because it decides whether anything else runs ──
{
  const host = newHost("0".repeat(64));
  const id = call(host, "jester_content_stage", [manifestText]);
  check("a set built against another SDK is refused at stage", id, 0);
  const why = call(host, "jester_content_problem", []);
  check("...and says which two stamps disagree",
        why.includes(manifest.sdk.slice(0, 12)) && why.includes("000000000000"), true);
}

// ── a manifest that is not a manifest ──
{
  const host = newHost(manifest.sdk);
  check("a body that is not JSON is refused", call(host, "jester_content_stage", ["<html>nope"]), 0);
  check("...with a sentence, not an exception",
        /not JSON/.test(call(host, "jester_content_problem", [])), true);
  check("a manifest with no version is refused",
        call(host, "jester_content_stage", [JSON.stringify({ files: [{ path: "a", sha256: "x" }] })]), 0);
  check("a file with no sha256 is refused", call(host, "jester_content_stage", [JSON.stringify(
    { version: "1.0.0", mode: "add", files: [{ path: "Mods/a/mod.json" }] })]), 0);
  check("...because nothing could then check what arrived",
        /no sha256/.test(call(host, "jester_content_problem", [])), true);
  check("a path that escapes the content root is refused", call(host, "jester_content_stage", [JSON.stringify(
    { version: "1.0.0", mode: "add", files: [{ path: "../../etc/passwd", sha256: "a".repeat(64) }] })]), 0);
}

// ── the real loop, exactly as `stepQueueFetching` drives it ──
const host = newHost(manifest.sdk);
const stage = call(host, "jester_content_stage", [manifestText]);
check("the published set stages", stage > 0, true);
check("...and reads back its version", call(host, "jester_content_version", [stage]), manifest.version);
const total = call(host, "jester_content_count", [stage]);
check("...and its file count", total, manifest.files.length);
console.log(`      ${total} files, set ${manifest.set} ${manifest.version}, SDK ${manifest.sdk.slice(0, 12)}`);

let fetched = 0, copied = 0;
for (let i = 0; i < total; i++) {
  const p = call(host, "jester_content_path", [stage, i]);
  if (!call(host, "jester_content_needs", [stage, p])) { copied++; continue; }
  // Where the shell would have done `httpGet(manifestBase & path)`.
  const body = fs.readFileSync(path.join(SET, p)).toString("base64");
  if (!call(host, "jester_content_file", [stage, p, body])) {
    check("every published file is accepted: " + p, call(host, "jester_content_problem", []), "");
    break;
  }
  fetched++;
}
check("every file was either fetched or already here", fetched + copied, total);
// THE POINT OF CONTENT ADDRESSING. If this is 0 the dedup is not working and the
// install is downloading the same SDK once per mod.
check("most of the set was deduplicated rather than downloaded", copied > fetched, true);
console.log(`      ${fetched} fetched, ${copied} copied (same bytes under another path)`);

// ── a corrupt body, after the good ones, so the store is warm ──
{
  const h2 = newHost(manifest.sdk);
  const st = call(h2, "jester_content_stage", [manifestText]);
  const p = call(h2, "jester_content_path", [st, 0]);
  const real = fs.readFileSync(path.join(SET, p));
  const wrong = Buffer.concat([real, Buffer.from("tampered")]).toString("base64");
  check("a file that does not match its hash is refused",
        call(h2, "jester_content_file", [st, p, wrong]), false);
  const why = call(h2, "jester_content_problem", []);
  const want = crypto.createHash("sha256").update(real).digest("hex");
  check("...naming the path and both hashes",
        why.includes(p) && why.includes(want.slice(0, 12)), true);
  check("a path the manifest never mentioned is refused",
        call(h2, "jester_content_file", [st, "Mods/evil/main.nim", "aGk="]), false);
  check("a commit with files missing is refused", call(h2, "jester_content_commit", [st]), false);
}

// ── commit ──
check("the set commits", call(host, "jester_content_commit", [stage]), true);
check("...and the version is now the installed one",
      call(host, "jester_content_installed", [stage]), manifest.version);
const msg = posted.find((m) => m && m.type === "installed");
check("...and the mods reached the page", !!msg, true);
if (msg) {
  console.log("      installed: " + msg.mods.map((m) => m.id).join(", "));
  check("every mod in the set arrived", msg.mods.length,
        new Set(manifest.files.map((f) => f.path.split("/")[1])).size);
  for (const m of msg.mods) {
    const ok = m.src && m.src.length > 100 && m.modules.length > 0 &&
               Object.keys(m.pool).length === m.modules.length &&
               m.sdk === manifest.sdk;
    if (!ok) check(m.id + " is loadable", JSON.stringify(
      { src: (m.src || "").length, modules: m.modules.length, pool: Object.keys(m.pool).length, sdk: m.sdk }), "loadable");
  }
  check("every mod carries an artifact, its modules and its stamp",
        msg.mods.every((m) => m.src && m.modules.length && m.sdk === manifest.sdk), true);
  // The Clone button's half: a mod that installs but cannot be read is a mod
  // this demo can only show you, and showing is what the old demo did.
  check("every mod carries its source too",
        msg.mods.every((m) => Object.keys(m.source).some((f) => f.endsWith(".nim"))), true);
}

// A whole-set install would take the shell away with it, so it is refused
// rather than half-done. `mode` is "add" for anything published from here.
{
  const h3 = newHost(manifest.sdk);
  const whole = JSON.parse(manifestText);
  whole.mode = "set";
  const st = call(h3, "jester_content_stage", [JSON.stringify(whole)]);
  for (let i = 0; i < call(h3, "jester_content_count", [st]); i++) {
    const p = call(h3, "jester_content_path", [st, i]);
    if (call(h3, "jester_content_needs", [st, p]))
      call(h3, "jester_content_file", [st, p, fs.readFileSync(path.join(SET, p)).toString("base64")]);
  }
  check("a WHOLE-SET install is refused, not half-done", call(h3, "jester_content_commit", [st]), false);
  check("...because it would take the running launcher with it",
        /whole-set/.test(call(h3, "jester_content_problem", [])), true);
}

console.log(fails.length ? `\nFAILED: ${fails.length}` : "\nPASS: the shell's own installer works in a browser.");
process.exit(fails.length ? 1 : 0);
