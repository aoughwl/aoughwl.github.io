---
repo: aoughwl/jit
---

# jit — an x86-64 JIT backend for Nimony

> ▶️ **[Try `aoughwl/jit` live in the Playground](https://aoughwl.github.io/playground/#clone=aoughwl/jit)** — clones the repo into the in-browser IDE, no install.

`jit` is the machine-code layer of the [aowljs-engine](/docs/aowljs-engine)
JIT, extracted as a library: an x86-64 assembler, W^X executable memory with
calls into and out of generated code, and a linear-scan register allocator.
It has no dependency on any JS value model; import its modules as `jit/[x64asm, jitmem, linscan]`.

[[toc]]

---

## Modules

| module | contents |
|---|---|
| `jit/x64asm` | x86-64 assembler: instructions are encoded as bytes appended to a buffer, with labels and rel32 fixups resolved by `finalize` |
| `jit/jitmem` | executable memory (W^X) and C-ABI calls into / out of generated code |
| `jit/linscan` | linear-scan register assignment over GPRs, XMM registers and spill slots |

---

## x64asm

Two-operand instructions are `op(dst, src)` (Intel order). Memory operands are
`Mem` values built with `mem(base, disp)` or `mem(base, index, scale, disp)`.
GPR operations are 64-bit unless the name says otherwise (`mov32`, `movzx8`,
...). Labels come from `newLabel` / `bindLabel`, and `finalize` patches the
rel32 references. The output is plain position-independent bytes: absolute
addresses (runtime helpers) are embedded with `mov r, imm64` + `call r`, so no
relocation step is needed after copying.

It is modelled on Bali's amd64 assembler (BSD-3-Clause), itself derived from
catnip's x64assembler (MIT), and rewritten for Nimony: no generics over operand
kinds, no exceptions, no raw buffer.

---

## jitmem

Code is written while its pages are read-write, then flipped to read-execute: a
page is never writable and executable at the same time. `install` gives every
function its own run of whole pages, bump-allocated from 64 KiB regions, so
installing new code never makes a page that already holds live code writable
again — generated code may be on the stack while more is compiled.

| | |
|---|---|
| `initJitMemory(regionSize = 65536)`, `install(jm, code): pointer`, `release` | allocate, install, free |
| `jitCall0` … `jitCall4`, `jitCallF1`, `jitCallF2` | call generated code with a fixed C signature |
| `procAddr(p)` | address of a `{.cdecl.}` Nim proc, for calls out of generated code |

Nimony cannot `cast` between `pointer` and proc types, so both directions go
through C (`{.emit.}` + `importc`). Generated code is an ordinary C-ABI
function — SysV on Linux, Win64 on Windows.

---

## Use it

```nim
import jit/[x64asm, jitmem, linscan]

var a = initAssembler()
let done = a.newLabel()
a.movImm(rax, 0)              # sumTo(n) = 1 + ... + n
a.mov(rcx, argRegs[0])
a.test(rcx, rcx)
a.jcc(cLessEq, done)
let top = a.hereLabel()
a.add(rax, rcx)
a.decr(rcx)
a.jcc(cNotEqual, top)
a.bindLabel(done)
a.ret()
doAssert a.finalize()          # false if a referenced label was never bound

var jm = initJitMemory()
let f = jm.install(a.buf)      # nil if pages could not be mapped/protected
echo jitCall1(f, 10)           # 55
jm.release()                   # unmaps everything installed from jm
```

---

## linscan

`linearScan(vals, start, stop, weight, wantX, crosses, gprPool, xmmFirst, loc,
nslots, hint)` assigns each value a location: a general register (`0 ..< 100`),
an XMM register (`100 + n`) or a spill slot (`-(k+1)`). When no register is
free, the value with the least weight per unit of lifetime is spilled; a hint
lets a two-address op take over the register of an operand that dies there.
`loopDepths` and `depthWeight` derive weights from the block layout. `loc` must
be presized to the value count and `vals` sorted by start.

---

## Build / test

```sh
git clone https://github.com/aoughwl/jit
cd jit
nimony c -p:src tests/test_jit.nim   # then run the binary (x86-64 only)
```

---

## Used by

- [aowljs-engine](/docs/aowljs-engine) — its baseline JIT and optimizing tier.
  The engine's build finds this checkout via `AOWL_JIT` (default `../jit`), like
  `AOWL_REGEX` / `AOWL_UNICODE`.
