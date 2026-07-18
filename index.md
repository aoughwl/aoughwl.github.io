# aoughwl

A **from-scratch reimplementation of the entire Nim / Nimony toolchain** —
parser, semantic checker, lowering, code generators — with one audacious goal:
**byte-for-byte identical output** to the originals. Not a fork,
not a wrapper; every stage is rewritten and held to the real compiler's exact
bytes by a differential harness. It's written *in* Nimony, self-hosting, **open at
every seam**, and runs where the classic compiler can't — **right in your
browser**. → **[See how close we are](/docs/parity)**

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/">▶ Open the Playground</a>
<a href="https://github.com/aoughwl" target="_blank" rel="noopener">GitHub</a>
</div>

---

## Not one binary — a pipeline you can see through

The classic Nim / Nimony toolchain reaches you as a **built compiler**: parsing,
semantic checking, lowering, and code generation all happen *inside* one program.
Real, well-defined stages — but internal. The intermediate results live in memory,
the pass boundaries aren't something you can hold, and swapping a stage means
patching and rebuilding the compiler. It works, but it's a black box.

aowlmony breaks the same job into **independent tools, one per stage**, with a
stable, textual IR flowing between every one:

```
 .nim / .aowl ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc  → C / native
    source         parse       semcheck    lower     ├─ aowljs → JavaScript / WASM
                                                      ├─ aowli  → interpret / VM
                                                      └─ aowlts · aowlpy → TS / Python
```

The IR at every seam is **AIF — byte-for-byte Nimony's NIF**. Because the seams
are a real format on disk, not a private in-memory structure, things fall out a
sealed binary can't give you:

- **Inspect anything** — stop after any stage and read exactly what it produced; the IR is text, nothing hidden between passes.
- **Run a stage on its own** — `aowlparser` parses, `aowli` interprets; each is a tool you invoke by itself, on its own input.
- **Swap a stage** — every stage speaks the same AIF (≡ NIF), so drop one of ours in *beside* nimony's own (`nifler` / `nimsem` / `hexer`), or replace it with your own, without touching the rest.
- **Runs where a packed binary can't** — most notably the **browser**: parser, checker, and interpreter compile to JavaScript and run client-side.

Same programs, same output — Nim and Nimony code behaves identically — but the
machine that produces it is open at every joint instead of sealed shut. The
interop contract is written up in **[AIF ≡ NIF](/docs/aif)**.

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
| **[aowllsp](/docs/aowllsp)** | Language Server + VSCode extension, live as-you-type diagnostics and type-directed completion. |
| **[aowlsuggest](/docs/aowlsuggest)** | diagnostics, quick-fixes & editor integration built on `aowlparser`'s `check`. |
| **[aowlfmt](/docs/aowlfmt)** | verified layout formatter — proves it changed nothing but whitespace before it touches your file. |
| **[aowllens](/docs/aiflens)** | NIF lens: reads typed `.s.nif` artifacts and emits JSON (decls, outline, members, type-at-position) that powers the LSP. |
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
