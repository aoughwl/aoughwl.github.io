// jester-surface.mjs - regenerate the host-call breakdown on
// docs/jester/host-surface.md out of a Jester checkout's own C# dispatch.
//
//   node tools/jester-surface.mjs ~/Documents/infiniteless-next          # print
//   node tools/jester-surface.mjs ~/Documents/infiniteless-next --write  # patch
//
// WHY THIS EXISTS. The breakdown on that page was hand-maintained and it went
// from 220 host calls to 433 without a single edit -- it roughly doubled while
// the prose stood still. A number a person retypes is a number that drifts, and
// a *table* of numbers drifts faster, because nobody wants to re-add a column.
// So the counts here are read out of `AowliHostBridge.Dispatch` the same way
// the engine's own `CLAIMS.tsv` reads them: the prefix-owned families are
// discovered from the bridge's `XHostCalls.Prefix` references rather than from
// a list carried here, so a family nobody told this script about is still
// counted the day it appears.
//
// What is NOT derived is the one-line description of each area, and the mapping
// from a core call's name to an area. Those are editorial and they live in the
// two tables below. Following web/triage.mjs in the engine repository, this
// script REFUSES to print anything while any call falls outside them: an
// unlabelled call must be labelled, not silently dropped into "the rest".
//
// The generated block is committed, so building the public site needs no Jester
// checkout. Re-run this after a host surface change; `npm run claims` is what
// notices that you did not.
import fs from "node:fs";
import path from "node:path";

const root = process.argv[2];
const write = process.argv.includes("--write");
if (!root) {
  console.error("usage: node tools/jester-surface.mjs <jester-checkout> [--write]");
  process.exit(2);
}

const RT = path.join(root, "Packages", "com.infiniteless.runtime", "Runtime");
const BRIDGE = path.join(RT, "Native", "AowliHostBridge.cs");
const read = (p) => fs.readFileSync(p, "utf8");
const uniq = (a) => [...new Set(a)].sort();

// ---- the families, discovered ---------------------------------------------
// One line of one-line descriptions, keyed by prefix. A family with no entry
// stops the script rather than appearing unexplained.
const FAMILY_NOTE = {
  infiniteless_desktop_: "file dialogs, the tray, one copy at a time, argv, dropped files, menus, global keys, and the host's own window rescue",
  infiniteless_audio_: "WAV decode, clips, speakers, one-shots, 3D falloff, named volume buses",
  infiniteless_network_: "transport, peers, worlds, part placement, message events",
  infiniteless_anim_: "skeletons and bone weights, clips built from parsed keyframes, playback, crossfade, layers, one joint",
  infiniteless_window_: "frame, transparency, corners, on top, click-through, place, size, drag",
  infiniteless_import_: "finding a game the player owns, scanning it, extracting from it, reading back what it wrote",
  infiniteless_http_: "prepared requests, allowlist policy, async polling",
  infiniteless_text_: "clipboard, IME composition and its caret, key-repeat and double-click timings",
  infiniteless_content_: "staging, hashing and committing a content set",
  infiniteless_render_: "frame-rate cap, on-demand interval, idle-when-quiet, wake, frame count",
  infiniteless_display_: "dots per inch, the scale factor, and whether it just changed",
};

// ---- the core switch, bucketed --------------------------------------------
// [area, one-line note, predicate]. First match wins; order matters. A core
// call matching nothing stops the script.
const p = (...names) => (n) => names.includes(n);
const pre = (s) => (n) => n.startsWith(s);
const CORE_AREAS = [
  ["voice", "microphone, devices, push-to-talk, VAD", pre("infiniteless_voice_")],
  ["collections", "the catalog substrate mods build data on, and which catalogs exist at all", pre("infiniteless_collection_")],
  ["model bytes", "reading a file as bytes or text for a format-reader mod, and letting one go", pre("infiniteless_model_")],
  ["screen UI", "one panel stack, labels, buttons, hit testing", pre("infiniteless_ui_")],
  ["Unity reflection", "get, set and call over any public instance member, plus add/find a component by type name", (n) => n.startsWith("infiniteless_unity_") || n.startsWith("infiniteless_component_")],
  ["input", "the whole keyboard, three mouse buttons, the wheel, look delta, typed text, screen size", (n) => n.startsWith("infiniteless_mouse_") || n.startsWith("infiniteless_key_") || p("infiniteless_look_delta", "infiniteless_typed_text", "infiniteless_screen_size")(n)],
  ["transforms and hierarchy", "position, rotation, scale, parent, active, forward, create, destroy", p("infiniteless_set_position", "infiniteless_set_rotation", "infiniteless_set_scale", "infiniteless_set_parent", "infiniteless_set_active", "infiniteless_get_position", "infiniteless_get_forward", "infiniteless_game_object_create", "infiniteless_destroy")],
  ["meshes", "vertex, uv, normal, triangle and quad building, with and without weights", pre("infiniteless_mesh_")],
  ["services", "one mod asking another a named question and getting text back", pre("infiniteless_service_")],
  ["drawing", "fill, text, image, measure, and the scissor the recording carries", (n) => n.startsWith("infiniteless_draw_") || p("infiniteless_image_present")(n)],
  ["parts", "spawn, and the provider protocol a format reader answers on", pre("infiniteless_part_")],
  ["materials and surfaces", "a tint, and four texture slots fed from encoded image bytes", p("infiniteless_set_color", "infiniteless_get_color", "infiniteless_set_surface", "infiniteless_get_surface", "infiniteless_surface_texture")],
  ["pointer", "lock, show, position", pre("infiniteless_pointer_")],
  ["character", "controller create, move, grounded, touched, velocity", pre("infiniteless_body_")],
  ["the player's view", "where the eye is, where it faces, and the crosshair ray", pre("infiniteless_eye_")],
  ["modpacks", "list, name, select, playing", pre("infiniteless_pack_")],
  ["aiming", "one ray, its hit, point and distance", (n) => n === "infiniteless_aim" || n.startsWith("infiniteless_aim_")],
  ["rigidbodies", "add with mass, freeze, set velocity", pre("infiniteless_physics_")],
  ["state", "remember and save over scalars", pre("infiniteless_state_")],
  ["the rest", "log, time, delta, camera create, primitives, the mod's own folder, one import read", p("infiniteless_log", "infiniteless_time", "infiniteless_delta_time", "infiniteless_camera_create", "infiniteless_primitive_create", "infiniteless_mod_folder", "infiniteless_import_read_bytes")],
];

// ---- read the dispatch -----------------------------------------------------
const bridge = read(BRIDGE);

const core = uniq(
  [...bridge.matchAll(/case "(infiniteless_[a-z0-9_]+)"/g)].map((m) => m[1])
);

const classes = uniq(
  [...bridge.matchAll(/([A-Za-z]+HostCalls)\.Prefix/g)].map((m) => m[1])
);

function findFile(dir, name) {
  for (const e of fs.readdirSync(dir, { withFileTypes: true })) {
    const full = path.join(dir, e.name);
    if (e.isDirectory()) { const hit = findFile(full, name); if (hit) return hit; }
    else if (e.name === name) return full;
  }
  return null;
}

const families = [];
for (const cls of classes) {
  const file = findFile(RT, cls + ".cs");
  if (!file) { console.error(`no source for ${cls}`); process.exit(2); }
  const src = read(file);
  const prefix = src.match(/Prefix = "(infiniteless_[a-z0-9_]+)"/)?.[1];
  if (!prefix) { console.error(`${cls} declares no Prefix`); process.exit(2); }
  const calls = uniq([...src.matchAll(/case Prefix \+ "([a-z0-9_]+)"/g)].map((m) => prefix + m[1]));
  families.push({ prefix, cls, calls });
}

const unexplained = families.filter((f) => !FAMILY_NOTE[f.prefix]).map((f) => f.prefix);
if (unexplained.length) {
  console.error("These prefix families are in the dispatch and have no note in this script:");
  for (const u of unexplained) console.error("  " + u);
  console.error("Describe them in FAMILY_NOTE. Refusing to print a table with a blank row.");
  process.exit(2);
}

const buckets = new Map(CORE_AREAS.map(([a]) => [a, []]));
const orphans = [];
for (const name of core) {
  const hit = CORE_AREAS.find(([, , test]) => test(name));
  if (!hit) orphans.push(name); else buckets.get(hit[0]).push(name);
}
if (orphans.length) {
  console.error("These core dispatch calls fall in no area:");
  for (const o of orphans) console.error("  " + o);
  console.error("Give each one an area in CORE_AREAS. Refusing to print a partial table.");
  process.exit(2);
}

const familyTotal = families.reduce((n, f) => n + f.calls.length, 0);
const total = familyTotal + core.length;

// ---- render ----------------------------------------------------------------
const sorted = [...families].sort((a, b) => b.calls.length - a.calls.length || a.prefix.localeCompare(b.prefix));
const coreRows = CORE_AREAS
  .map(([area, note]) => ({ area, note, n: buckets.get(area).length }))
  .filter((r) => r.n > 0)
  .sort((a, b) => (a.area === "the rest" ? 1 : b.area === "the rest" ? -1 : b.n - a.n || a.area.localeCompare(b.area)));

const L = [];
L.push(`**${total} host calls**, of which ${familyTotal} live in ${families.length} prefix-owned tables the`);
L.push(`dispatch falls through to, and ${core.length} are inline \`case\` labels in the switch itself.`);
L.push("");
L.push("| family | calls | what it is |");
L.push("|---|---:|---|");
for (const f of sorted) L.push(`| \`${f.prefix}\` | ${f.calls.length} | ${FAMILY_NOTE[f.prefix]} |`);
L.push(`| **the core switch** | **${core.length}** | broken out below |`);
L.push(`| **total** | **${total}** | |`);
L.push("");
L.push(`The ${core.length} in the core switch, by area:`);
L.push("");
L.push("| area | calls | what it is |");
L.push("|---|---:|---|");
for (const r of coreRows) L.push(`| ${r.area} | ${r.n} | ${r.note} |`);
L.push(`| **total** | **${core.length}** | |`);

const block = L.join("\n");
const BEGIN = "<!-- surface:begin breakdown -- generated by tools/jester-surface.mjs, do not edit -->";
const END = "<!-- surface:end breakdown -->";

if (!write) { console.log(block); process.exit(0); }

const page = "docs/jester/host-surface.md";
const text = read(page);
const i = text.indexOf(BEGIN), j = text.indexOf(END);
if (i < 0 || j < 0) { console.error(`${page} has no surface:begin/end markers`); process.exit(2); }
fs.writeFileSync(page, text.slice(0, i) + BEGIN + "\n" + block + "\n" + text.slice(j), "utf8");
console.error(`wrote ${page}: ${total} host calls in ${families.length} families + ${core.length} core`);
