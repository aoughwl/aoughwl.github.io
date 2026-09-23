// libm-shims.mjs — fill the libm/libc gaps the JS-backend prelude leaves open.
//
//   node tools/libm-shims.mjs [dir]        # default public/playground
//
// WHAT WENT WRONG. `nifparser.js` — the PARSER, which every keystroke in the
// playground runs — calls `fpclassify` and compares the answer against
// `FP_NORMAL`, `FP_SUBNORMAL`, `FP_ZERO`, `FP_INFINITE` and `FP_NAN`. None of
// those exist in the generated bundle. The prelude says so itself, in a comment
// that has been right there the whole time:
//
//     Uncommon libm entries not covered here (erf/gamma/frexp/fpclassify) are
//     simply never referenced unless a program calls them.
//
// A program does, and "uncommon" is the wrong word for both of the ones that
// bit:
//
//   * `fpclassify` is reached from `std/math`'s `classify`, which `addFloatLit`
//     calls — so **parsing any file containing a float literal** threw
//     `ReferenceError: fpclassify is not defined` and took the whole parse with
//     it.
//   * `strtod` is what `parseFloat` lowers to, so any program that reads a
//     float at runtime reaches it. `ModSdk/character.nim` — a plain module with
//     a few constants — died on it.
//
// It went unnoticed because the playground's own demo has no floats in it. It
// surfaced the moment a real mod was cloned into the editor, where `1.65` and
// `30.0` are on nearly every line. Neither error reads as "this file has a
// float in it" in any way, which is why this is worth a tool and a comment
// rather than a one-line patch.
//
// THE FIX IS ALREADY UPSTREAM AND THESE BUNDLES PREDATE IT. `aowlsem.js` and
// `aowli_session.js` — the two rebuilt most recently — carry their own
// `fpclassify` with these exact constants and these exact semantics, under a
// comment about float32 subnormals. So the nim_js prelude was fixed and the
// older bundles simply have not been re-emitted; this brings them into line
// until each is. Rebuild one and this tool steps over it, because it skips any
// bundle that already defines what it calls.
//
// Idempotent, and a patch rather than an edit because these bundles are
// generated: re-emitting one loses any change made inside it. Run it again
// after a fresh build. A re-run REPLACES an older version of the block rather
// than refusing — the first version shipped without `strtod`.
import fs from "node:fs";
import path from "node:path";

const dir = process.argv[2] || "public/playground";
const MARK = "// --- libm/libc shims v2 (tools/libm-shims.mjs) ---";
const END = "// --- libm/libc shims v2 --- end ---";
// Any block this tool has ever written, so a re-run REPLACES it rather than
// stacking a second one. v1 spelled its end marker "--- end libm ..." and v2
// spells it "libm/libc shims v2 --- end"; both open the same way, so anchor
// on that opening and take everything through the next line naming this tool.
const ANY = /^\/\/ --- libm[^\n]*\(tools\/libm-shims\.mjs\) ---\n[\s\S]*?^\/\/ --- (?:end )?libm[^\n]*\n/m;

// The C constants are implementation-defined and nothing outside this block
// ever sees them: the generated code only compares `fpclassify`'s answer
// against these same names. glibc's numbering, which is also what the two
// rebuilt bundles use, so a mixed page cannot disagree with itself.
const SHIM = `${MARK}
// See tools/libm-shims.mjs. The generated code calls these and the prelude in
// this (older) bundle defines none of them.
const FP_NAN = 0, FP_INFINITE = 1, FP_ZERO = 2, FP_SUBNORMAL = 3, FP_NORMAL = 4;
const DBL_MIN = 2.2250738585072014e-308;
function fpclassify(x) {
  x = Number(x);
  if (Number.isNaN(x)) return FP_NAN;
  if (x === Infinity || x === -Infinity) return FP_INFINITE;
  if (x === 0) return FP_ZERO;                        // covers -0 too
  return Math.abs(x) < DBL_MIN ? FP_SUBNORMAL : FP_NORMAL;
}
const fpclassifyf = fpclassify;

// \`strtod\` is what nimony's \`parseFloat\` lowers to. C contract: parse the
// longest numeric prefix of the NUL-terminated string, write where parsing
// stopped through \`endPtr\`, and answer 0 when nothing converted.
function strtod(p, endPtr) {
  p = Number(p);
  let s = "";
  for (let i = p; i - p < 1024 && _u8[i] !== 0; i++) s += String.fromCharCode(_u8[i]);
  const m = /^[ \\t\\n\\r\\f\\v]*[+-]?(Infinity|inf|nan|(?:\\d+\\.?\\d*|\\.\\d+)(?:[eE][+-]?\\d+)?)/i.exec(s);
  if (endPtr) mem.setI32(endPtr, p + (m ? m[0].length : 0));
  if (!m) return 0;
  const v = parseFloat(m[0].replace(/^[\\s]*/, ""));
  return Number.isNaN(v) ? (/nan/i.test(m[0]) ? NaN : 0) : v;
}
const strtof = strtod;

// frexp/ldexp split a float into mantissa and exponent. The C signature writes
// the exponent through a pointer, and the lowered code passes one, so this
// takes an address and goes through \`mem\` like every other out-parameter here.
function frexp(x, expPtr) {
  if (x === 0 || !Number.isFinite(x)) { if (expPtr) mem.setI32(expPtr, 0); return x; }
  let ex = Math.ceil(Math.log2(Math.abs(x)));
  let m = x / Math.pow(2, ex);
  // log2 rounding can land the mantissa just outside [0.5, 1); nudge it back.
  while (Math.abs(m) >= 1) { m /= 2; ex++; }
  while (Math.abs(m) < 0.5) { m *= 2; ex--; }
  if (expPtr) mem.setI32(expPtr, ex);
  return m;
}
const frexpf = frexp;
function ldexp(x, e) { return x * Math.pow(2, e); }
const ldexpf = ldexp;
${END}
`;

const WANT = /\b(fpclassify|frexp|ldexp|strtod|strtof)\s*\(/;
const HAS = /function\s+(fpclassify|frexp|ldexp|strtod|strtof)\s*\(/;

let patched = 0, current = 0, replaced = 0;
for (const name of fs.readdirSync(dir).sort()) {
  if (!name.endsWith(".js")) continue;
  const file = path.join(dir, name);
  let text = fs.readFileSync(file, "utf8");
  if (text.includes(MARK)) { current++; continue; }
  // Strip an older version of this block first, so what is left is the bundle
  // as it was built and the tests below judge it, not the last patch.
  const had = ANY.test(text);
  if (had) text = text.replace(ANY, "");
  // A hand-written file in this directory must never be touched, and a rebuilt
  // bundle that already carries its own shims is left alone.
  if (!WANT.test(text) || HAS.test(text)) {
    if (had) { fs.writeFileSync(file, text); replaced++; }   // drop the stale block
    continue;
  }
  // A bundle is only ever run as one `new Function(text)` body, so the top of
  // the text is the top of that scope.
  fs.writeFileSync(file, SHIM + text);
  console.log(`  ${name}: ${had ? "re-" : ""}shimmed (${SHIM.length} bytes)`);
  patched++;
}
console.log(`${patched} patched` + (current ? `, ${current} already current` : "") +
            (replaced ? `, ${replaced} stale block(s) dropped` : ""));
