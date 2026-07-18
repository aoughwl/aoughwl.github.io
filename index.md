# aoughwl

A **from-scratch reimplementation of the entire Nimony toolchain** — parser,
semantic checker, lowering, and code generators — written *in* Nimony,
self-hosting, and **open at every seam**. It runs Nim/Nimony **identically**, and
runs where the classic compiler can't: **right in your browser**.

[▶ Open the Playground](https://aoughwl.github.io/playground/)
[How this works](/docs/how-it-works)
[GitHub](https://github.com/aoughwl)

---

## Why this exists

The classic Nim/Nimony compiler ships as a **sealed binary** — the stages run
*inside* it, out of reach. aowlmony is the opposite: a **pipeline of separate,
open tools**, with a stable, inspectable IR flowing between every one.

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc  → C / native
    source         parse       semcheck    lower     ├─ aowljs → JavaScript / WASM
                                                      ├─ aowli  → interpret / VM
                                                      └─ aowlts · aowlpy → TS / Python
```

Every seam is **AIF — byte-for-byte Nimony's NIF**. That single fact is the whole
story: each stage is a genuine **drop-in** beside nimony's own
(`nifler` / `nimsem` / `hexer`), you can **read the IR** at any point, **run a
stage on its own**, and the entire pipeline runs **client-side**.
→ **[How this works](/docs/how-it-works)**

## What you get that stock Nimony doesn't

- 🌐 **Runs in the browser** — parse → semcheck → run, fully client-side. **[Try it live →](https://aoughwl.github.io/playground/)**
- 🎯 **Byte-exact parity** — `aowlparser` is proven against `nifler` by a differential harness over the **entire** standard library.
- 🧩 **Many targets** — native **C**, native/faithful **JavaScript**, **WASM**, an **interpreter + bytecode VM**, plus idiomatic **TypeScript** and **Python**.
- 📚 **A fuller stdlib** — a complete networking stack (TLS 1.3, HTTP/1.1 + HTTP/2, WebSocket, HTTP/3) and a typed HTML/CSS layer.
- ⚡ **Instant incremental re-checks** — the checker is warm and fast enough for live, as-you-type editor tooling.

---

## The pipeline — front to back

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
| **interpret / VM** | [aowli](/aowli) | tree-walker **+ bytecode VM**, differentially tested against native. |
| **native C** | [aowlc](/docs/aowlc) | post-hexer `.c.aif` → C, linked with `gcc` — **GC-free**, ARC baked in. |
| **JavaScript** | [aowljs](/docs/aowljs) | typed IR → native JS; near-native speed, readable output. |
| **JS / WASM** | [aowlweb](/docs/aowlweb) | the faithful browser runtime, with an async runtime. |
| **TypeScript** | [aowlts](/docs/aowlts) | idiomatic TypeScript. |
| **Python** | [aowlpy](/docs/aowlpy) | idiomatic Python. |

## Tools & libraries

| Project | What it is |
|:--|:--|
| **[▶ Playground](https://aoughwl.github.io/playground/)** | the whole toolchain in your browser — edit, parse, type-check, run. |
| **[aowl-code](/docs/aowl-code)** | Claude Code plugin + MCP server: compact, structured agent access to the toolchain. |
| **[aowllsp](/docs/aowllsp)** | Language Server + VSCode extension, live as-you-type diagnostics. |
| **[aowlsuggest](/docs/aowlsuggest)** | diagnostics, quick-fixes & editor integration built on `aowlparser`'s `check`. |
| **[net stack](/docs/net-stack)** | `tcp · net · tls · http · compress · serve · ws · requests` — TLS 1.3, dual-stack IPv6, HTTP/2 server, WebSocket, HTTP/3 client. |
| **[web](/docs/web) · [html](/docs/html) · [css](/docs/css)** | a declarative HTML+CSS DSL, a typed HTML5 registry, and an MDN-typed CSS engine. |

---

## The private side

The **lowering (aowlhexer)**, along with the
JavaScript / TypeScript / WASM / Python backend repos, are **kept private for
now** — their **docs are public here**, and access is granted on request (just
ask). The playground moves onto the new sem + hexing shortly.

And this toolchain is the **floor, not the building**. The full aoughwl platform it
was built to carry opens up as the stack matures. Curious? Reach out on
**[Discord](https://discord.gg/nxa3W7w4rJ)** (`timbuktu_guy`).
