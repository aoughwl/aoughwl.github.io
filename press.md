---
title: Press kit
description: A short description of aoughwl, the numbers behind it with their sources, logos, and how to get in touch.
---

# Press kit

## In one sentence

aoughwl is a software stack built from scratch in Nimony: a compiler
toolchain, a JavaScript engine, a browser engine and a game platform, each
checked against the established tool it replaces.

## In one paragraph

aoughwl rebuilds the layers that programs run on, in one language, and
publishes how close each layer is to the reference it replaces. Its compiler
toolchain parses, type-checks and compiles Nimony (the next-generation Nim
compiler) and is diffed byte for byte against Nimony's own passes. Its
JavaScript engine, written from scratch with a bytecode interpreter, a baseline
JIT and an optimizing tier, passes 53,593 of 53,595 test262 conformance tests.
Its runtime puts that engine and a Nimony interpreter on one heap with one
garbage collector. Jester, its game platform, runs every part of a game as a
mod that can be edited while the game is running. Most of it can be tried in a
browser at aoughwl.github.io.

## Numbers, with where they come from

| Claim | Figure | Source |
|:--|:--|:--|
| JavaScript conformance | 53,593 / 53,595 test262 | [aowljs-engine](/docs/aowljs-engine) |
| JavaScript speed | 1.99 s total vs V8 1.29 s, 16 benchmarks | [aowljs-engine](/docs/aowljs-engine) |
| Browser conformance | about 93.5% of Web Platform Tests subtests on the tracked directories (Ladybird: 96.2%) | [Titicaca and WPT](/docs/titicaca/wpt) |
| Compiler parser | byte-identical to Nimony's on all 184 files of the compiler source | [Parity](/docs/parity) |
| Type checker | byte-identical on 924 of 941 test cases | [Parity](/docs/parity) |
| Interpreter | identical output to native on 460 / 460 runnable programs | [engine](/engine) |
| Fresh install | 181 s from an empty Linux home to a running native binary | [Get started](/start) |

Every figure has a date on the page it links to. How they are measured is on
[How we test](/docs/method).

## Logos

| | |
|:--|:--|
| ![aoughwl logo, dark text](/assets/aoughwl-logo-black.png) | [aoughwl-logo-black.png](/assets/aoughwl-logo-black.png), for light backgrounds |
| <span style="background:#0a0a0b;padding:8px;display:inline-block">![aoughwl logo, light text](/assets/aoughwl-logo-white.png)</span> | [aoughwl-logo-white.png](/assets/aoughwl-logo-white.png), for dark backgrounds |
| ![aoughwl social card](/og-image.png) | [og-image.png](/og-image.png), 1200 × 630 |

The name is written in lowercase: **aoughwl**.

## Contact

[Discord](https://discord.gg/nxa3W7w4rJ), user `timbuktu_guy`, or an issue on
any [GitHub repository](https://github.com/aoughwl).
