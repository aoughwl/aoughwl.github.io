---
repo: aoughwl
---

# aoughwl

The Nim / Nimony compiler is one program. Parsing, type checking, lowering and
code generation are real stages inside it, but the boundaries between them only
exist in memory — you can't hold an intermediate result in your hand, and
swapping a stage means patching the compiler and rebuilding it.

aoughwl is that compiler taken apart. One tool per stage, every boundary a file
on disk you can open, diff, edit and feed back in. Each stage is written from
scratch and then checked against the original by diffing the bytes, because
"close enough" is a claim nobody can check.

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/" target="_self">▶ Open the Playground</a>
</div>

> **Latest — Aug 1, 2026:** went through every tool in
> [aowlcode](/docs/aowlcode) asking one question — what is this verdict actually
> resting on? Eight of them were reporting success for work that had not
> happened. **[Read the update →](/blog)**

---

## A pipeline, not a binary

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc  → C / native
    source         parse       semcheck    lower     ├─ aowljs → JavaScript / WASM
                                                     ├─ aowli  → interpret / VM
                                                     └─ aowlts · aowlpy → TS / Python
```

The IR passing between them is **AIF, which is byte-for-byte Nimony's NIF**.
Because each boundary is a file rather than a private data structure, you can
stop after any stage and read exactly what it produced, run one stage on its
own, or swap ours for Nimony's — `nifler`, `nimsem` and `hexer` speak the same
format, so they mix in either direction. Write your own stage and it drops into
the same slot. The interop contract is written up in **[AIF ≡ NIF](/docs/aif)**.

The parser, checker and interpreter also compile to JavaScript, which is why the
whole front end runs client-side in the playground with nothing installed.

## Things that fall out of building it this way

**A bug that depends on what you name the file.** Byte-identical source compiles
as `multiarg.nim` and fails to link as `vargs.nim`. A lowering-inlined bounds
check carries its own panic-message string, and which module *owns* that string
is decided by a hash of the module name — so under some names it is defined, and
under others it is referenced twice and defined nowhere. Deterministic, 3/3
identical runs. It surfaced because [aowlrt](/docs/aowlrt)'s linker has to
account for every undefined symbol by name, so it noticed one it couldn't
explain instead of handing gcc a mystery.

**The interpreter runs the network stack.** TLS 1.3 handshake, HTTP, WebSocket
frames — interpreted, not handed off to a native library. [aowli](/aowli) is a
tree-walker and a bytecode VM which have to agree with each other *and* with the
native build across a 423-program differential corpus. Zero in-scope divergence
is the bar; anything else is a bug in one of the three.

**A debugger that only runs your program once.** Start it, then pause, step and
inspect the live frame on demand. Value rendering is budgeted and `expand` is
path-addressable, so looking into a deeply nested structure costs what you asked
for rather than a megabyte of dump.

**A formatter that proves it was safe before it writes.**
[aowlfmt](/docs/aowlfmt) re-parses its own output and checks the AIF is
equivalent to what went in. If the reformat changed anything but whitespace,
your file is not touched.

**A test runner that tells you what it skipped.** [aowltest](/docs/aowltest)
skips any test whose transitive input hash is unchanged, then prints the cache
hit rate it actually achieved — because a suite that silently ran nothing looks
exactly like one that passed.

**A sandbox that starts with nothing.** [aowlhost](/docs/aowlhost) runs an aowl
module as a plugin under a capability policy. The default grant is no
capabilities at all, and a denied filesystem call is stopped at the native
boundary rather than trusted to behave.

## How far along it is

The parser is done: byte-exact on the whole compiler tree, 0 crashes and 0 hangs
across four corpora. The checker stands at 498/498 corpus modules byte-exact,
including all of `std/system`. Lowering still runs the reference passes and says
so on the page. The scoreboard, including what is missing and why, is the
**[parity page](/docs/parity)**.

---

## The pipeline

| Stage | Repo | What it is |
|:--|:--|:--|
| **parse** | [aowlparser](/docs/aowlparser) | Nim/Nimony source → `.p.aif`; byte-identical to `nifler`, self-hosted, browser-ready. |
| **semcheck** | [aowlsem](/docs/aowlsem) | `.p.aif` → typed `.s.aif`: symbols, overloads, generic instantiation. |
| **lower** | [aowlhexer](/docs/aowlhexer) *(private)* | `.s.aif` → `.c.aif`: ARC, closures, iterators, exceptions, monomorphisation. |
| **drive** | [Pipeline Driver](/docs/aowlmony) | one command: `.nim` → { native · interpret · web } over the whole stack. |
| **runtime** | [aowlrt](/docs/aowlrt) | strings / seqs / ARC / GC the native + JS backends link against. |
| **HL-IR** | [aowlhl](/docs/aowlhl) | the shared high-level IR that feeds the TypeScript / Python emitters. |

## Targets

| Target | Repo | Notes |
|:--|:--|:--|
| **interpret / VM** | [aowli](/aowli) · [aowli-release](/docs/aowli-release) *(prebuilt binaries)* | tree-walker and bytecode VM, diffed against native; the source is private and the builds come from the [store](/store/aowli). |
| **native C** | [aowlc](/docs/aowlc) | post-hexer `.c.aif` → C, linked with `gcc`. No GC; ARC is baked in. |
| **JavaScript** | [aowljs](/docs/aowljs) | typed IR → native JS; near-native speed, readable output. |
| **JS / WASM** | [aowlweb](/docs/aowlweb) | the faithful browser runtime, with an async runtime. |
| **TypeScript** | [aowlts](/docs/aowlts) | idiomatic TypeScript. |
| **Python** | [aowlpy](/docs/aowlpy) | idiomatic Python. |

## Tools and libraries

| Project | What it is |
|:--|:--|
| **[▶ Playground](https://aoughwl.github.io/playground/)** | the toolchain in your browser — edit, parse, type-check, run. |
| **[aowlcode](/docs/aowlcode)** | Claude Code plugin + MCP server: compact, structured agent access to the toolchain (`trace`/`debug` backed by [aowli-release](/docs/aowli-release)). |
| **[aowllsp](/docs/aowllsp)** | Language Server + VSCode extension: as-you-type diagnostics, type-directed completion. |
| **[aowlsuggest](/docs/aowlsuggest)** | diagnostics, quick-fixes and editor integration built on `aowlparser`'s `check`. |
| **[aowlfmt](/docs/aowlfmt)** | layout formatter that proves it changed nothing but whitespace before writing your file. |
| **[aowltest](/docs/aowltest)** | test runner that skips any test whose transitive input hash is unchanged, and prints the cache hit rate it achieved. |
| **[aowlhost](/docs/aowlhost)** | runs an aowl module as a plugin under a capability policy — default grant is nothing, and a denied filesystem call is halted at the native boundary. |
| **[aowllens](/docs/aiflens)** | reads typed `.s.aif` and emits JSON — decls, outline, members, type-at-position — which is what the LSP runs on. |
| **[net stack](/docs/net-stack)** | `tcp · net · tls · http · compress · serve · ws · requests` — TLS 1.3, dual-stack IPv6, HTTP/2 server, WebSocket, HTTP/3 client. |
| **[LLM stack](/docs/llm-stack)** | [anthropic](/docs/llm-stack/anthropic) · [openai](/docs/llm-stack/openai) — typed clients for the Messages and Chat Completions APIs, each with a headless `-p` CLI. |
| **[web](/docs/web) · [html](/docs/html) · [css](/docs/css)** | a declarative HTML+CSS DSL, a typed HTML5 registry, and an MDN-typed CSS engine. |

---

## What's private, and why

The lowering stage ([aowlhexer](/docs/aowlhexer)) and the JavaScript /
TypeScript / WASM / Python backend repos are private for now. Their docs are
public here and access is granted on request — just ask. The playground moves
onto the new sem and hexing shortly.

The toolchain is groundwork. The larger aoughwl platform it was built for opens
up as the stack matures. Come ask on
**[Discord](https://discord.gg/nxa3W7w4rJ)** (`timbuktu_guy`) — questions about
how any of this works are welcome, and so is arguing with the parity numbers.
