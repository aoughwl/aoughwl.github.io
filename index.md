---
repo: aoughwl
---

# aoughwl

aoughwl is a rewrite of the Nim / Nimony toolchain — parser, semantic checker,
lowering, code generators — done from scratch, in Nimony, and held to one
standard: **the output should match the original byte for byte**. Every stage is
diffed against the real compiler's own output, so "close enough" never counts.
It self-hosts, every stage is a separate tool, and the whole front end runs in a
browser. → **[See how close we are](/docs/parity)**

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/" target="_self">▶ Open the Playground</a>
</div>

> **Latest — Jul 27, 2026:** a **progressive debugger** for aowli — run it once,
> then pause, step, and inspect the live frame on demand, with budgeted value
> rendering and path-addressable `expand`. **[Read the update →](/blog)**

---

## A pipeline, not a binary

The stock Nim / Nimony compiler is one program. Parsing, checking, lowering and
code generation are real stages with real boundaries, but those boundaries only
exist in memory: you can't hold an intermediate result, and swapping a stage
means patching and rebuilding the compiler.

aowlmony splits the same job into one tool per stage, with a textual IR passing
between them:

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc  → C / native
    source         parse       semcheck    lower     ├─ aowljs → JavaScript / WASM
                                                      ├─ aowli  → interpret / VM
                                                      └─ aowlts · aowlpy → TS / Python
```

That IR is **AIF, which is byte-for-byte Nimony's NIF**. Because each boundary is
a file rather than a private data structure:

- **You can read it.** Stop after any stage and look at exactly what it produced.
- **You can run one stage alone.** `aowlparser` parses. `aowli` interprets. Each
  takes its own input and writes its own output.
- **You can substitute a stage.** Ours and Nimony's own (`nifler` / `nimsem` /
  `hexer`) speak the same format, so they mix — or you write your own.
- **It runs in places a compiled binary doesn't.** Parser, checker and
  interpreter all compile to JavaScript and run client-side.

The programs behave the same either way. The difference is what you can get at
while they compile. The interop contract is written up in
**[AIF ≡ NIF](/docs/aif)**.

## What this gives you over stock Nimony

- **It runs in the browser.** Parse, check and run, entirely client-side.
  **[Try it →](https://aoughwl.github.io/playground/)**
- **Byte-exact parity, measured.** `aowlparser` is diffed against `nifler` across
  the whole standard library.
- **More targets.** C, native and faithful JavaScript, WASM, an interpreter and a
  bytecode VM, plus TypeScript and Python.
- **A bigger stdlib.** A full networking stack — TLS 1.3, HTTP/1.1 and HTTP/2,
  WebSocket, HTTP/3 — and a typed HTML/CSS layer.
- **Fast re-checks.** The checker stays warm, which is what makes as-you-type
  editor tooling possible.

---

## The pipeline

| Stage | Repo | What it is |
|:--|:--|:--|
| **parse** | [aowlparser](/docs/aowlparser) | Nim/Nimony source → `.p.aif`; byte-identical to `nifler`, self-hosted, browser-ready. |
| **semcheck** | [aowlsem](/docs/aowlsem) | `.p.aif` → typed `.s.aif`: symbols, overloads, generic instantiation. |
| **lower** | [aowlhexer](/docs/aowlhexer) *(private)* | `.s.aif` → `.c.aif`: ARC, closures, iterators, exceptions, monomorphisation. |
| **drive** | [Pipeline Driver](/docs/aowlmony) | one command: `.nim` → { native · interpret · web } over the whole stack. |
| **runtime** | [aowllib](/docs/aowllib) | strings / seqs / ARC / GC the native + JS backends link against. |
| **HL-IR** | [aowlhl](/docs/aowlhl) | the shared high-level IR that feeds the TypeScript / Python emitters. |

## Targets

| Target | Repo | Notes |
|:--|:--|:--|
| **interpret / VM** | [aowli](/aowli) · [aowli-release](/docs/aowli-release) *(public binaries)* | tree-walker and bytecode VM, diffed against native; source is private, the binaries are not. |
| **native C** | [aowlc](/docs/aowlc) | post-hexer `.c.aif` → C, linked with `gcc`. No GC; ARC is baked in. |
| **JavaScript** | [aowljs](/docs/aowljs) | typed IR → native JS; near-native speed, readable output. |
| **JS / WASM** | [aowlweb](/docs/aowlweb) | the faithful browser runtime, with an async runtime. |
| **TypeScript** | [aowlts](/docs/aowlts) | idiomatic TypeScript. |
| **Python** | [aowlpy](/docs/aowlpy) | idiomatic Python. |

## Tools and libraries

| Project | What it is |
|:--|:--|
| **[▶ Playground](https://aoughwl.github.io/playground/)** | the toolchain in your browser — edit, parse, type-check, run. |
| **[aowlcode](/docs/aowlcode)** | Claude Code plugin + MCP server: compact, structured agent access to the toolchain (`trace`/`debug` backed by the public [aowli-release](/aowli-release)). |
| **[aowllsp](/docs/aowllsp)** | Language Server + VSCode extension: as-you-type diagnostics, type-directed completion. |
| **[aowlsuggest](/docs/aowlsuggest)** | diagnostics, quick-fixes and editor integration built on `aowlparser`'s `check`. |
| **[aowlfmt](/docs/aowlfmt)** | layout formatter that proves it changed nothing but whitespace before writing your file. |
| **[aowltest](/docs/aowltest)** | test runner that skips any test whose transitive input hash is unchanged, and prints the cache hit rate it achieved. |
| **[aowlhost](/docs/aowlhost)** | runs an aowl module as a plugin under a capability policy — default grant is nothing, and a denied filesystem call is halted at the native boundary. |
| **[aowllens](/docs/aiflens)** | reads typed `.s.nif` and emits JSON — decls, outline, members, type-at-position — which is what the LSP runs on. |
| **[net stack](/docs/net-stack)** | `tcp · net · tls · http · compress · serve · ws · requests` — TLS 1.3, dual-stack IPv6, HTTP/2 server, WebSocket, HTTP/3 client. |
| **[web](/docs/web) · [html](/docs/html) · [css](/docs/css)** | a declarative HTML+CSS DSL, a typed HTML5 registry, and an MDN-typed CSS engine. |

---

## What's private, and why

The lowering stage ([aowlhexer](/docs/aowlhexer)) and the
JavaScript / TypeScript / WASM / Python backend repos are private for now. Their
docs are public here and access is granted on request — just ask. The playground
moves onto the new sem and hexing shortly.

The toolchain is groundwork. The larger aoughwl platform it was built for opens
up as the stack matures. Ask on **[Discord](https://discord.gg/nxa3W7w4rJ)**
(`timbuktu_guy`).
