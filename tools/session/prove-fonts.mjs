// prove-fonts.mjs — does the host read a font's REAL family name?
//
//   node tools/session/prove-fonts.mjs
//
// `fonts.nim` lets a mod fetch a font and make it drawable: `cacheFont(name,
// base64)` then `registerFont(name)`. On Windows the family comes from the
// font's own `name` table; a browser's `FontFace` makes you supply it, so this
// host reads the same table rather than guessing.
//
// WHY NOT GUESS FROM THE FILENAME. It is the obvious shortcut and it is wrong
// for exactly the fonts this feature exists to reach. Google ships static faces
// as `Lato-Regular.ttf` — strip `-Regular` and you get `Lato`, which works — but
// ships variable faces as `OpenSans[wdth,wght].ttf`, where the same rule yields
// `OpenSans[wdth,wght]` and a family nothing will ever match. Both are in this
// fixture on purpose: one where guessing happens to work, one where it does not.
//
// The fixture files are real, fetched from google/fonts. If they go missing:
//   curl -sL -o fixture/fonts/Lato-Regular.ttf \
//     https://raw.githubusercontent.com/google/fonts/main/ofl/lato/Lato-Regular.ttf
import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const HERE = path.dirname(fileURLToPath(import.meta.url));
const FONTS = path.join(HERE, "fixture", "fonts");
const HOST = path.join(HERE, "..", "..", "public", "playground", "jester-host.js");

// The host only touches the 2D context for text metrics and fills, so a stub is
// enough to instantiate it outside a browser. Nothing here paints.
const ctx = {
  font: "",
  measureText: (t) => ({ width: String(t).length * 8 }),
  fillRect: () => {}, fillText: () => {}, save: () => {}, restore: () => {},
  beginPath: () => {}, rect: () => {}, clip: () => {},
  getImageData: () => ({ data: new Uint8ClampedArray(4) }),
};
globalThis.self = globalThis;
globalThis.postMessage = () => {};
new Function(fs.readFileSync(HOST, "utf8"))();
const host = globalThis.JesterHost.create(
  { width: 640, height: 480, getContext: () => ctx }, { log: () => {} });

const fails = [];
const check = (what, got, want) => {
  const ok = String(got) === String(want);
  console.log(`${ok ? "  ok  " : "  FAIL"}  ${what}: ${got}${ok ? "" : "  (expected " + want + ")"}`);
  if (!ok) fails.push(what);
};

if (!fs.existsSync(FONTS)) { console.error("no font fixtures at " + FONTS); process.exit(2); }
const files = fs.readdirSync(FONTS).filter((f) => /\.(ttf|otf)$/i.test(f));
check("there are font fixtures to read", files.length > 0, true);

for (const f of files) {
  const bytes = new Uint8Array(fs.readFileSync(path.join(FONTS, f)));
  let family = "";
  try { family = host.familyOf(bytes); } catch (e) { family = "threw: " + (e.message || e); }
  // What a filename-stripping implementation would have produced, for contrast.
  const guess = f.replace(/\.(ttf|otf)$/i, "").replace(/-(Regular|Italic|Bold|Medium)$/i, "");
  console.log(`      ${f}\n        name table -> ${JSON.stringify(family)}\n        filename   -> ${JSON.stringify(guess)}`);
  check(`${f}: a family was read`, family.length > 0, true);
  check(`${f}: it is a plain family name`, /^[\x20-\x7e]+$/.test(family) && !/[\[\]]/.test(family), true);
}

// The specific pair the feature turns on. `OpenSans[wdth,wght].ttf` must read
// as "Open Sans" — the brackets are the whole point.
const variable = files.find((f) => f.includes("["));
if (variable) {
  const fam = host.familyOf(new Uint8Array(fs.readFileSync(path.join(FONTS, variable))));
  check("a VARIABLE font reads as its real family, not its filename", fam, "Open Sans");
}
const staticFace = files.find((f) => /Lato/i.test(f));
if (staticFace) {
  const fam = host.familyOf(new Uint8Array(fs.readFileSync(path.join(FONTS, staticFace))));
  check("a static font reads as its real family", fam, "Lato");
}

console.log(fails.length ? `\nFAILED: ${fails.length}` : "\nPASS: the family comes from the font, not the filename.");
process.exit(fails.length ? 1 : 0);
