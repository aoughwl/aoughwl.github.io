// frame-arena.mjs - give aowli-host.js's linear memory a frame stack.
//
//   node tools/frame-arena.mjs public/jester-demo/aowli-host.js
//
// WHY. The Leng JS runtime at the top of the bundle has two allocators sharing
// one bump pointer `_brk`: `mmap`, which the Nim allocator sits on and which
// frees through a free list, and `allocFixed`, which is the codegen's storage
// for value aggregates and, in the runtime's own words, "a C-stack model: never
// freed". Never freed is correct for a program that runs `main` once and exits -
// aowli's own webtest - and fatal for a host that calls `update` and `drawGui`
// sixty times a second: the interpreter allocates locals from `allocFixed` on
// every call, so the arena climbs monotonically and the page dies with
// "out of linear memory" against the 1 GiB ceiling. Measured before this patch:
// 34.6 seconds, about 430 frames.
//
// WHAT. A C-stack model is exactly a thing you can pop. This exposes a mark and
// a release, and boot.js takes a mark before a per-frame callback and releases
// it after. The release is refused whenever `mmap` has handed out a region above
// the mark, because those regions outlive the frame and `_brk` must not fall
// back through them - so a frame that grows the Nim heap simply keeps its
// arena, and the next one starts from there.
//
// This is a patch rather than an edit because aowli-host.js is generated: it is
// re-emitted by web/build.sh in the Jester tree and any change made in the file
// itself would be lost. Run it again after every fresh bundle; running it twice
// on the same bundle is a no-op.
//
// The place this belongs in the end is the Leng JS runtime itself, where every
// embedder would get it. It lives here because this page is where the ceiling
// was being hit.
import fs from "node:fs";

const file = process.argv[2] || "web/aowli-host.js";
let src = fs.readFileSync(file, "utf8");

if (src.includes("__leng_mark")) {
  console.error(file + ": already patched");
  process.exit(0);
}

const anchor = "let _brk = 8;                                   // offset 0 reserved as nil";
if (!src.includes(anchor)) throw new Error("the runtime prelude is not the one this patch was written against");
src = src.replace(anchor, anchor + `
// The high-water mark of anything mmap has handed out. A frame release may not
// take _brk below this: those pages belong to the Nim heap and outlive the call.
let _mmapHigh = 8;
globalThis.__leng_mark = () => _brk;
globalThis.__leng_release = (mark) => {
  if (mark >= _mmapHigh && mark <= _brk) { _brk = mark; return true; }
  return false;
};
globalThis.__leng_brk = () => _brk;`);

// The `_brk = end;` inside mmap - the second of the two, allocFixed being the
// first - is the only place a region that outlives a frame is carved.
const mmapAt = src.indexOf("function mmap(");
if (mmapAt < 0) throw new Error("no mmap in the runtime prelude");
const bump = src.indexOf("  _brk = end;", mmapAt);
if (bump < 0) throw new Error("mmap does not bump _brk the way this patch expects");
src = src.slice(0, bump) + "  _brk = end;\n  if (end > _mmapHigh) _mmapHigh = end;" +
  src.slice(bump + "  _brk = end;".length);

fs.writeFileSync(file, src);
console.error(file + ": frame arena installed");
