---
repo: aoughwl
title: aoughwl
description: A software stack built from scratch in Nimony — a compiler toolchain, a JavaScript engine, a browser engine and a game platform — each part checked against the reference it replaces.
---

# aoughwl

**A software stack built from scratch, in one language.** aoughwl is a
compiler toolchain, a runtime, a browser engine and a game platform, all
written in [Nimony](https://github.com/nim-lang/nimony), the next-generation
Nim compiler. Each part is checked against the established tool it replaces,
and the score is published, including where we fall short.

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/" target="_self">▶ Try it in your browser</a>
<a href="/start">Get started in 5 minutes</a>
<a href="/jester">Jester, the game platform</a>
</div>

The playground runs the parser, the type checker and the interpreter in your
browser tab. Nothing to install, and your code never leaves the page.

## What is here

| | What it is | Where it stands |
|:--|:--|:--|
| **[Compiler toolchain](/docs/aowlmony)** | A parser, a type checker, a lowering pass and code generators for C, JavaScript, TypeScript and Python. One command, `aowlmony run`, takes a `.nim` file to a running native program. | Parser byte-identical to the reference on the whole compiler source. Type checker byte-identical on 924 of 941 test cases. |
| **[engine](/engine)** | The runtime: our JavaScript engine and our Nimony interpreter in one process, on one heap, collected by one garbage collector. | In development. Both engines run in one binary with one GC pass, verifier clean. |
| **[aowljs-engine](/docs/aowljs-engine)** | A JavaScript engine with a bytecode interpreter, a baseline JIT and an optimizing tier. | Passes 53,593 of 53,595 test262 tests. Optimizing tier within 1.6× of V8 on our benchmarks. |
| **[Jester](/jester)** | A game platform where the whole game is mods, and mods can be edited while the game runs. Its apps include [Titicaca](/docs/titicaca), a browser engine written from scratch, and a [Minecraft](/docs/minecraft) client. | Upcoming. Titicaca passes about 93.5% of the [Web Platform Tests](/docs/titicaca/wpt) subtests it tracks; Ladybird passes 96.2% of the same set. |
| **[Libraries](/docs/net-stack)** | TCP, TLS 1.3, HTTP, WebSocket, a [CSS engine](/docs/css), typed HTML, LLM API clients, an ES2025 [regex](/docs/regex) engine, [Unicode 17](/docs/unicode) data, an x86-64 [JIT backend](/docs/jit). | Public and usable today. |

## How we measure

Every stage that replaces an existing tool is run on the same input as that
tool, and the outputs are compared byte for byte. A stage counts as done when
the diff is empty, not when the output looks right. The
[parity page](/docs/parity) is the scoreboard, with the misses listed next to
the passes.

| Stage | Compared against | Result |
|:--|:--|:--|
| Parser, [aowlparser](/docs/aowlparser) | Nimony's `nifler` | byte-identical on all 184 files of the compiler source |
| Type checker, [aowlsem](/docs/aowlsem) | Nimony's `nimsem` | byte-identical on 924 of 941 corpus cases |
| JavaScript, [aowljs-engine](/docs/aowljs-engine) | test262 | 53,593 / 53,595 |
| Nimony interpreter, inside [engine](/engine) | native compile and run | 460 / 460 runnable corpus programs, identical output |

## Start here

- **Never seen it before?** [Get started in 5 minutes](/start): run a program in
  the browser, then install the toolchain on Linux.
- **Want the architecture?** Read [the AIF format](/docs/aif), then follow a
  program through [the stages](#the-stages).
- **Here for the games?** Read about [Jester](/jester).
- **Want to know what is missing?** The [parity page](/docs/parity) lists it.

## The stages

```
 .nim ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc   C, then a native binary
         parse         type-check lower       ├─ aowljs  JavaScript
                                              ├─ aowlweb JavaScript + WebAssembly
                                              ├─ engine  interpret, with a debugger
                                              └─ aowlts, aowlpy  TypeScript, Python
```

Each stage is a separate program that reads a file and writes a file, so you
can stop after any stage and look at what it produced. The files between stages
are AIF, which is byte-for-byte Nimony's NIF format. Our stages and Nimony's
can therefore be mixed freely, and that is how each one is tested.

| Stage | What it does |
|:--|:--|
| [aowlparser](/docs/aowlparser) | Nim source → `.p.nif`. Self-hosted, and runs in a browser. |
| [aowlsem](/docs/aowlsem) | `.p.nif` → typed `.s.nif`: symbols, overloads, generic instantiation. |
| [aowlhexer](/docs/aowlhexer) | `.s.nif` → `.c.nif`: ARC, closures, iterators, exceptions. |
| [aowlmony](/docs/aowlmony) | The driver. One command from `.nim` to a native binary, an interpreted run, or a web build. |
| [aowlup](/docs/aowlup) | Installs the toolchain and switches between our stages and Nimony's. |

## Free and paid

**Free and open:** the parser, the driver, the toolchain manager, the C
backend, the editor tooling, and every library. Public repositories:
`aowlparser`, `aowlhexer`, `aowlmony`, `aowlup`, `aowlc`, `aowlrt`, `aowlhl`, `aowlfmt`,
`aowllsp`, `aowlsuggest`, `aiflens`, the net stack, `css`, `html`, `web`, `jit`,
`regex`, `unicode`.

**Private source, public docs:** `aowlsem`, `aowljs`, `engine`,
`aowljs-engine`, and the paid backends.

**Paid:** the interpreter with its debugger, and the TypeScript, Python and
JavaScript/WebAssembly backends, as one subscription. See the
[store](/store/).

## Contact

Ask on [Discord](https://discord.gg/nxa3W7w4rJ) (`timbuktu_guy`). Questions
about how something works are welcome, and so is disputing a number on this
site.
