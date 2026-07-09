---
title: Architecture
parent: nimony-web
grand_parent: Nimony Backends
nav_order: 3
---

# Architecture

The top-level [README](../README.md) states the one idea: a WebAssembly module
and a fast JavaScript runtime are the *same machine described twice* — a single
byte-addressable linear memory where a pointer is an integer offset. This page is
how that idea is factored into modules.

## One layout engine, two instruction selectors

Everything above the memory-touching instruction is computed once, in
`src/jslayout.nim`. It answers two questions about any Leng type:

- `typeLayout(t) -> (size, align)` — the C-ABI size and alignment.
- `objectFields(t) -> seq[FieldInfo]` — each field's **byte offset** and type.

Neither the C nor the LLVM backend computes these (both defer struct layout to
their toolchains), but a linear-memory target must: an object *is* a byte offset
and a layout. `jslayout` derives them from the Leng type grammar using the
platform C ABI (natural alignment, LLVM datalayout). It emits no code — it's a
pure query — and both backends call it and get identical offsets. `AccessKind`
tells codegen which load/store width a scalar field needs; aggregates have none
(they're copied whole).

That shared engine is why the WebAssembly backend was *additive* rather than a
second implementation. Once the layout is fixed, each backend only differs in the
instruction that touches memory:

| operation | JavaScript | WebAssembly |
|---|---|---|
| load i32 at `p` | `HEAP32[p >> 2]` | `i32.load` |
| store i32 | `HEAP32[p >> 2] = v` | `i32.store` |
| copy an aggregate | `HEAPU8.copyWithin(...)` | `memory.copy` |

`PtrSize` is 4: the target is a `--bits:32` platform, so `int`/`uint` are a JS
`Number` / WASM `i32` and pointers are 4-byte offsets; only `int64`/`uint64`
become a JS `BigInt` / WASM `i64`.

## Builder / serializer split

Each backend is split the way a serious codegen usually is — a **builder** that
turns the Leng IR into a model, and a **serializer** that turns the model into
bytes or text. Text is produced in exactly one place per backend.

```
JS:    jscodegen.nim  ──build──▶  jsnif tree  ──emit──▶  .js text
WASM:  wasmcodegen.nim ──build──▶  WasmModule  ──encode──▶  .wasm bytes
```

### JavaScript: `jscodegen` → `jsnif`

`jscodegen.nim` walks the Leng IR and builds a **NIF tree of JS constructs** —
not a string. `jsnif.nim` defines that tree (a `JsTag` enum + a `JsBuilder` over
a `TokenBuf`) and a `emit` printer that is the *only* place JS text appears.
Because emission is a tree walk, parenthesization and indentation are the
printer's job — the builder never reasons about operator precedence, and a
peephole optimizer could run on the tree before printing. (This is the shape Araq
specified on PR #2043: build JS as a NIF tree with a dedicated enum, then a tiny
`jsnif → js` emitter.)

### WebAssembly: `wasmcodegen` → `wasmenc`

`wasmcodegen.nim` selects instructions and builds a `WasmModule`. `wasmenc.nim`
is the counterpart of `jsnif`'s printer: the *only* place that knows how a
`.wasm` is spelled on the wire — LEB128, section framing, opcode bytes. It has
**no knowledge of Leng** (it's a pure `WasmModule -> bytes` encoder), so it can
be unit-tested against a hand-built module and reused by any front end.
Instruction *selection* lives entirely in `wasmcodegen`; `wasmenc` is the low,
mechanical layer.

## What the two backends consume from nimony

nimony-web owns `jslayout` and everything downstream of it. It consumes from the
sibling nimony checkout, via `--path` in `src/nim.cfg`, the infrastructure it
does **not** fork:

- the **type navigator** (`typenav`) — resolving and walking Leng types;
- the **module loader** (`nifmodules`) — `getDeclOrNil`, `MainModule`;
- the **name mangler** and NIF primitives (`nifcore`, `nifcoreparse`, `nifcdecl`).

So nimony-web builds against nimony *master* — it uses only stock nimony NIF APIs and
none of a feature branch's `src/lib` internals.

## The pipeline, end to end

```
nim source
   │  nimony c --bits:32 --define:nimNativeAlloc
   ▼
<module>.c.nif          the lowered Leng IR, one per module, written by hexer
   │                    just before the C backend would run
   ├── nim-js  <mod>.c.nif <mod>.js       jscodegen → jsnif → text
   │      │
   │      ▼
   │   nim-js-link  →  bundle.js               runtime.js + per-module .js + entry
   │
   └── nim-wasm <mod>.c.nif <mod>.wasm    wasmcodegen → wasmenc → bytes
          │      (--program adds the C main + its closure)
          ▼
       node driver.js <mod>.wasm          instantiate; host imports fill stdio
```

`--define:nimNativeAlloc` compiles the stdlib against Nim's own ported allocator
(`system/alloc.nim`) over the runtime's `mmap`/`munmap`, instead of the mimalloc
C binding — the libc-free config the web targets want. The trailing 32-bit C link
fails on a 64-bit host, which is expected and ignored: the `.c.nif` nimony-web
consumes is emitted *before* the C backend runs, so the signal of a real error is
simply that no `.c.nif` was produced.

## Where each file sits

| File | Layer |
|---|---|
| `src/jslayout.nim` | layout engine — shared, emits no code |
| `src/jscodegen.nim` | JS: Leng IR → `jsnif` tree (builder) |
| `src/jsnif.nim` | JS: the tree model + the only JS-text emitter (serializer) |
| `src/nim-js.nim` | JS: entry point `.c.nif` → `.js` |
| `src/nim-js-link.nim` | JS: bundle per-module `.js` + runtime into one file |
| `src/wasmcodegen.nim` | WASM: Leng IR → `WasmModule` (builder + instruction selection) |
| `src/wasmenc.nim` | WASM: `WasmModule` → bytes (serializer, Leng-agnostic) |
| `src/nim-wasm.nim` | WASM: entry point `.c.nif` → `.wasm` |
