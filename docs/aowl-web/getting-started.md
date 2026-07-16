---
title: Getting started
parent: aowl-web
grand_parent: Backends
nav_order: 1
---

# Getting started

aowl-web gives Nim two web targets: **JavaScript** (`nim-js`) and **WebAssembly**
(`nim-wasm`). Both are out-of-tree codegen plugins for
[nimony](https://github.com/nim-lang/nimony), the Nim 3.0 compiler. They read the
lowered *Leng* IR nimony emits just before its C backend (`<module>.c.nif`) and
produce a `.js` or `.wasm` instead of C.

Below: an empty directory to `echo "hello world"` running under Node on both
backends.

## Prerequisites

- **Nim** (2.x) — only to *build* the plugins. Check with `nim --version`.
- **A built nimony checkout** sitting next to aowl-web — aowl-web consumes nimony's
  type navigator, module loader, and name mangler through `--path`, and drives
  its frontend to produce the `.c.nif`.
- **Node.js** — both backends run their artifacts under Node (WASM uses Node's
  built-in `WebAssembly` engine; the JS DOM tests also want `npm install`).

### 1. Clone the two repos side by side

The relative `--path` in `src/nim.cfg` assumes aowl-web and nimony are siblings:

```
git clone https://github.com/nim-lang/nimony
git clone https://github.com/aoughwl/aowl-web
```

You should end up with:

```
<workspace>/
  nimony/     built: bin/ has nimony, nimsem, hexer, nifler, nifmake, lengc
  aowl-web/     this repo
```

### 2. Build nimony

Follow nimony's own README to build its frontend. In short:

```
cd nimony
nim c -o:bin/hastur src/hastur.nim
./bin/hastur build all          # inits the mimalloc submodule itself
```

That populates `nimony/bin/` with `nimony` and the rest of the toolchain.

### 3. Build the aowl-web plugins

From the aowl-web checkout:

```
cd ../aowl-web
nim c src/nim-js.nim            # -> bin/nim-js   (.c.nif -> .js)
nim c src/nim-wasm.nim          # -> bin/nim-wasm (.c.nif -> .wasm)
nim c src/nim-js-link.nim            # -> bin/nim-js-link   (bundle per-module .js)
```

## Hello world — JavaScript

Create `hello.nim`:

```nim
import std/syncio

echo "hello world"
echo 42
echo 100 + 23
```

The pipeline is: nimony frontend → `.c.nif` per module → `nim-js` per module →
concatenate with the runtime → run under Node.

```sh
# 1. Frontend + hexer -> lowered Leng IR (one .c.nif per module) in ./nc
#    --bits:32 is required: the web target is a 32-bit platform, so `int` is a
#    JS Number and only int64/uint64 become BigInt.
#    The trailing 32-bit C link fails on a 64-bit host — that's expected and
#    harmless: the .c.nif we want is written by hexer BEFORE the C backend runs.
../nimony/bin/nimony c --bits:32 --define:nimNativeAlloc \
  --nimcache:nc hello.nim

# 2. Each module's .c.nif -> a .js artifact.
for f in nc/*/*.c.nif; do
  ../aowl-web/bin/nim-js "$f" "${f%.c.nif}.js"
done

# 3. Bundle: the runtime first, then every module artifact, then the entry call.
#    (This is nim-js-link's job from a link manifest; done by hand here.)
cat tests/jsbackend/runtime.js nc/*/*.js > bundle.js
echo 'main(0, []);' >> bundle.js

# 4. Run it.
node bundle.js
```

Expected output:

```
hello world
42
123
```

> `runtime.js` supplies the primitives that can't be expressed in Nim — the
> allocator's `mmap`, `memcpy`, and stdio — over the one shared `ArrayBuffer`.
> `nim-js-link` (built above) automates steps 2–3 from the compiler's link manifest;
> the manual `cat` is only to show what it does.

## Hello world — WebAssembly

Same frontend step; a different codegen and a tiny Node driver that instantiates
the module and supplies the C stdio imports.

```sh
# 1. Same frontend step -> .c.nif.
../nimony/bin/nimony c --bits:32 --define:nimNativeAlloc \
  --nimcache:nc hello.nim

# 2. The MAIN module's .c.nif -> a .wasm. --program emits the C `main` entry
#    and its whole closure so the module is runnable on its own.
../aowl-web/bin/nim-wasm nc/hello/hello.c.nif hello.wasm --program

# 3. Run it under a driver that provides fwrite/fputc/fprintf host imports.
node driver.js hello.wasm
```

A minimal `driver.js` (the suite's `techo.js` is the reference version):

```js
"use strict";
const fs = require("fs");
const bytes = fs.readFileSync(process.argv[2]);
const memory = new WebAssembly.Memory({ initial: 16 });
const U8 = () => new Uint8Array(memory.buffer);
const env = { memory };
env.fwrite = (ptr, size, n) => {
  process.stdout.write(Buffer.from(U8().subarray(ptr, ptr + size * n)));
  return n;
};
env.fputc = (ch) => { process.stdout.write(Buffer.from([ch & 0xff])); return ch; };
const mod = new WebAssembly.Module(bytes);
// Stub any host import the module declares but the driver doesn't fill.
for (const imp of WebAssembly.Module.imports(mod))
  if (imp.kind === "function" && !(imp.name in env)) env[imp.name] = () => 0;
new WebAssembly.Instance(mod, { env }).exports.main(0, 0, 0);
```

Expected output:

```
hello world
42
123
```

> The WASM module imports the C stdio primitives (`fwrite`/`fputc`/`fprintf`) and
> the driver fulfils them — the same seam `runtime.js` fills for JS. String
> literals are materialized from WASM data segments; integers are formatted
> through `fprintf`.

## Running the test suites

The suites are the fastest way to see everything working. Each suite directory is
a `setup.nim` custom runner; the repo entry point drives both through nimony's
`hastur`:

```sh
nim c -r tests/tester.nim
```

To iterate on one suite without hastur, run its runner directly:

```sh
cd tests/wasmbackend && nim r setup.nim --dir:.
cd tests/jsbackend   && npm install && nim r setup.nim --dir:.   # jsdom for DOM tests
```

Add `--overwrite` to regenerate the `.output` goldens. See
[capabilities.md](capabilities.md) for exactly what each backend supports today.
