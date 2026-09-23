// grow-fixed-arena.mjs — let `allocFixed` grow the heap, like `mmap` already does.
//
//   node tools/grow-fixed-arena.mjs [dir]      # default public/playground
//
// WHAT WENT WRONG. The Leng JS runtime at the top of every bundle has two
// allocators sharing one bump pointer `_brk`. Its own comment describes the
// arrangement:
//
//     Rather than eagerly reserving a huge buffer on every page load, we start
//     at 256 MiB and GROW ON DEMAND (in `mmap` below) up to a 1 GiB ceiling
//
// "in `mmap` below" is the whole bug. `mmap` grows the resizable buffer when a
// request runs past the end; `allocFixed`, the other allocator on the same
// pointer, does not — it bumps `_brk` and writes, with no bounds check at all.
// So the arena climbs straight through the 256 MiB initial size and the next
// write lands past the end of the DataView:
//
//     RangeError: Offset is outside the bounds of the DataView
//         at Object.setU32 ... at nimStrWasMoved ... at tok ...
//
// Nothing in that message says "out of memory", and nothing says which limit was
// hit, which is why it read as a parser bug for as long as it did.
//
// WHY IT SURFACED NOW. `allocFixed` is the codegen's storage for value
// aggregates — "a C-stack model: never freed" — so a parse spends roughly 3 KB
// of it per BYTE of source and never gives any back. The playground's own demo
// is under 1 KB and never came close. Cloning a real mod into the editor did:
// `aoughwl.shell`'s `main.nim` is 115 KB, and parsing it wants a few hundred
// megabytes of arena. Measured: ~30 KB of source is where 256 MiB runs out.
//
// WHAT THIS DOES, and what it does not. It makes `allocFixed` grow the buffer
// exactly the way `mmap` does, which moves the wall from 256 MiB to the 1 GiB
// ceiling — roughly 30 KB of source to a few hundred. That is enough for every
// mod in this repo and it is NOT a fix for the underlying shape: a C-stack that
// is never popped is still a C-stack that is never popped. The real fix is the
// one `tools/frame-arena.mjs` applies to the session bundle — a mark before a
// call and a release after it — and it belongs in the Leng runtime, where every
// embedder would get it rather than each page patching its own copy.
//
// THE FIX IS ALREADY UPSTREAM; THESE BUNDLES PREDATE IT. `aowli_session.js`,
// the one rebuilt most recently, carries a `_growTo`-and-raise `allocFixed`
// straight from the Leng runtime — which is exactly where it belongs. So this
// brings fifteen older bundles into line until each is rebuilt, and steps over
// any bundle that already has it.
//
// Idempotent, and a patch rather than an edit because these bundles are
// generated: re-emitting one loses any change made inside it. Run it again after
// a fresh build.
import fs from "node:fs";
import path from "node:path";

const dir = process.argv[2] || "public/playground";
const MARK = "// --- allocFixed grows the heap (tools/grow-fixed-arena.mjs) ---";

// The exact line every bundle's prelude carries. Matching the whole thing rather
// than a loose regex is deliberate: a prelude that has changed shape is one this
// patch has not been read against, and silently patching it would be worse than
// not patching it.
const OLD = "function allocFixed(n){ const p=(_brk+7)&~7; _brk=p+n; _u8.fill(0,p,p+n); return p; }";
const NEW = `${MARK}
// WAS: function allocFixed(n){ const p=(_brk+7)&~7; _brk=p+n; _u8.fill(0,p,p+n); return p; }
// ...which bumped past the end of a 256 MiB buffer without ever growing it. See
// tools/grow-fixed-arena.mjs. Same doubling rule as \`mmap\`, and the same
// ceiling; past that it raises, because a silent overwrite of someone else's
// memory is the one outcome worse than an error.
function allocFixed(n){
  const p=(_brk+7)&~7, need=p+n;
  if(need > _ab.byteLength){
    if(!_ab.resizable || need > _HEAPMAX)
      throw new RangeError("out of linear memory: allocFixed wanted " + need +
        " bytes of the " + _HEAPMAX + "-byte arena. This is the codegen's value-aggregate " +
        "arena, which is never freed, so a big enough input exhausts it however large it is.");
    let want=_ab.byteLength;
    while(want < need) want *= 2;
    if(want > _HEAPMAX) want = _HEAPMAX;
    _ab.resize(want);
  }
  _brk=need; _u8.fill(0,p,need); return p;
}
${MARK.replace("---", "--- end")}`;

let patched = 0, already = 0, unknown = [];
for (const name of fs.readdirSync(dir).sort()) {
  if (!name.endsWith(".js")) continue;
  const file = path.join(dir, name);
  const text = fs.readFileSync(file, "utf8");
  if (text.includes(MARK)) { already++; continue; }
  if (!text.includes("function allocFixed(")) continue;   // not a Leng bundle
  // A NEWER BUNDLE ALREADY HAS THIS. `aowli_session.js`, the most recently
  // rebuilt one, carries a `_growTo` + raise version of `allocFixed` straight
  // from the Leng runtime — which is where this belongs and evidently where it
  // landed. So the fix is upstream and the bundles below simply predate it;
  // rebuild one and this tool steps over it.
  const fixed = /function allocFixed\(n\)\{[\s\S]{0,600}?(_growTo|RangeError)/.test(text);
  if (fixed) { already++; continue; }
  if (!text.includes(OLD)) { unknown.push(name); continue; }
  fs.writeFileSync(file, text.replace(OLD, NEW));
  console.log("  " + name + ": allocFixed grows the heap now");
  patched++;
}
if (unknown.length)
  console.error("  !! an allocFixed this patch was not read against, in: " + unknown.join(", ") +
                " — read the prelude before patching these.");
console.log(`patched ${patched}` + (already ? `, ${already} already had it` : "") +
            (unknown.length ? `, ${unknown.length} NOT patched` : ""));
process.exit(unknown.length ? 1 : 0);
