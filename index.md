---
repo: aoughwl
---

# aoughwl

aoughwl is a rewrite of the Nim / Nimony compiler as a set of separate programs:
a parser, a type checker, a lowering pass, and several code generators. Each one
reads a file and writes a file, so you can stop after any stage and look at what
it produced.

The intermediate format is AIF, which is byte-for-byte Nimony's NIF. That means
our stages and Nimony's can be mixed: `nifler`, `nimsem` and `hexer` read and
write the same files as `aowlparser`, `aowlsem` and `aowlhexer`. We wrote each
stage from scratch and check it against the original by diffing the output
bytes.

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/" target="_self">▶ Open the Playground</a>
</div>

The playground runs the parser, checker and interpreter in your browser, with
nothing to install.

## Status

- **Parser:** byte-exact against `nifler` on the whole compiler tree, with no
  crashes or hangs across four corpora.
- **Type checker:** 924 of 941 corpus cases byte-exact, and `std/system`
  type-checks to within 89 tokens (measured 2026-09-09, on Windows).
- **Lowering:** still runs Nimony's own passes. The page says so.

Everything that is missing, and why, is on the [parity page](/docs/parity).

## Stages

```
 .nim ─► aowlparser ─► aowlsem ─► aowlhexer ─┬─ aowlc   C / native
         parse         typecheck  lower       ├─ aowljs  JavaScript
                                              ├─ aowlweb JavaScript + WASM
                                              ├─ aowli   interpreter
                                              └─ aowlts, aowlpy  TypeScript, Python
```

| Stage | What it does |
|:--|:--|
| [aowlparser](/docs/aowlparser) | Nim source → `.p.nif`. Self-hosted, and runs in a browser. |
| [aowlsem](/docs/aowlsem) | `.p.nif` → typed `.s.nif`: symbols, overloads, generic instantiation. |
| [aowlhexer](/docs/aowlhexer) | `.s.nif` → `.c.nif`: ARC, closures, iterators, exceptions, monomorphisation. Private. |
| [aowlmony](/docs/aowlmony) | The driver. One command from `.nim` to a native binary, an interpreted run, or a web build. |
| [aowlrt](/docs/aowlrt) | The runtime (strings, seqs, ARC) that the C and JS backends link against. |
| [aowlhl](/docs/aowlhl) | A shared high-level IR that feeds the TypeScript and Python emitters. |

## Backends

| Backend | Output |
|:--|:--|
| [aowlc](/docs/aowlc) | C, linked with `gcc`. |
| [aowljs](/docs/aowljs) | JavaScript, close to native speed. |
| [aowlweb](/docs/aowlweb) | JavaScript and WebAssembly over one linear-memory model, with an async runtime. |
| [aowli](/aowli) | A tree-walking interpreter and a bytecode VM, plus a stepping debugger. |
| [aowlts](/docs/aowlts) | TypeScript. |
| [aowlpy](/docs/aowlpy) | Python. |

## Tools

| Tool | What it does |
|:--|:--|
| [aowlup](/docs/aowlup) | Installs and selects the components. |
| [aowlcode](/docs/aowlcode) | Claude Code plugin and MCP server for working on the toolchain. |
| [aowllsp](/docs/aowllsp) | Language server and VS Code extension. |
| [aowlsuggest](/docs/aowlsuggest) | Diagnostics and quick-fixes. |
| [aowlfmt](/docs/aowlfmt) | Formatter. It re-parses its output and leaves your file alone if anything but whitespace changed. |
| [aowltest](/docs/aowltest) | Test runner. It skips tests whose inputs are unchanged and reports the cache hit rate. |
| [aowlhost](/docs/aowlhost) | Runs a module as a plugin with no capabilities unless you grant them. |
| [aowllens](/docs/aiflens) | Reads `.s.nif` and prints JSON: declarations, outline, type at a position. |

Libraries: [net stack](/docs/net-stack) (TCP, TLS 1.3, HTTP, WebSocket),
[LLM clients](/docs/llm-stack), [web / html / css](/docs/web).

## Source and price

**Paid:** aowli, its debugger, and the TypeScript, Python and JavaScript/WASM
backends are one $9.99/month subscription, installed with
`aowlup login YOUR-KEY`. See the [store page](/store/aowli). A second product,
[Jester](/store/jester), is upcoming at $19.99/month.

**Public repos:** `aowlparser`, `aowlmony`, `aowlup`, `aowlrt`, `aowlhl`,
`aowlfmt`, `aowllsp`, `aowlsuggest`, `aiflens`, `aowljs`, `aowlc`.

**Private repos:** `aowlsem`, `aowlhexer`, `aowlhost`, `aowlcode`, `aowltest`,
and the four paid components (`aowli`, `aowlweb`, `aowlts`, `aowlpy`). The docs
for all of them are public.

## Contact

Ask on [Discord](https://discord.gg/nxa3W7w4rJ) (`timbuktu_guy`). Questions
about how something works are welcome, and so is disputing the parity numbers.
