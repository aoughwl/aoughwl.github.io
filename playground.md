---
title: Sandbox Playground
parent: Nimony
nav_order: 6
---

# Playground
{: .no_toc }

A browser playground that runs nimony **entirely client-side** — the whole
toolchain (parser, semantic checker, interpreter) is compiled to JavaScript and
runs in your tab. You edit nimony source and it is parsed, type-checked, and
executed live. No backend, no server round-trip; your code never leaves the page.
{: .fs-6 .fw-300 }

[Launch the playground →](/playground/){: .btn .btn-primary .fs-5 }

Live at **[aoughwl.github.io/playground](https://aoughwl.github.io/playground/)**.

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## How it works

Editing a program drives the full nimony pipeline, all in the browser:

```
your source
   │  nifparser  (aoughwl/nifparser)      main thread, ~4 ms
   ▼
 .p.nif  (untyped NIF)
   │  nimsem     (nimony's checker)        Web Worker, warm-cached
   ▼
 .s.nif  (typed NIF)
   │  run engine (you pick)                Web Worker
   ▼   ┌─ Native JS  (nifjs → real JS, JIT-compiled)   near-native speed
 output ├─ Bytecode VM  (nifi)                          faithful, fast
        └─ Tree-walk   (nifi)                           faithful, reference
```

- **[nifparser](docs/nifparser)** parses your source to the untyped `.p.nif` on
  the main thread — it's the browser-capable replacement for classic Nim's
  native-only `nifler`, and it also feeds the live editor intelligence.
- **nimsem** turns the `.p.nif` into a typed `.s.nif`, resolving every symbol,
  overload, and type. It runs in a Web Worker and reuses a warm, pre-loaded
  stdlib closure, so every check after the first is milliseconds (an ~8.9 MB JS
  bundle plus a pre-semchecked `system`/`syncio`/… closure from an in-memory VFS).
- The typed `.s.nif` is executed by an engine you pick from the toolbar
  (persisted across visits):
  - **[Native JS](docs/nifjs)** — `nifjs` transpiles the typed
    NIF to **real JavaScript** (mapping nimony values onto native JS values) and
    lets the browser JIT it: **near-native speed**, and no fixed heap. A program
    using something nifjs doesn't cover yet falls back automatically.
  - **Bytecode VM** — [nifi](nifi) compiles the NIF to bytecode and runs a tight
    dispatch loop. Faithful (exact nimony semantics), fast.
  - **Tree-walk** — [nifi](nifi)'s reference interpreter; walks the typed NIF
    node by node. Slowest, most faithful.

The VM and tree-walk are the **faithful** engines (default: VM); Native JS is the
**fast** one, with the interpreter as its safety net — the run footer names the
engine that actually ran, and says so (and why) if Native JS fell back.

### Engine speed

The same tight arithmetic loop, per iteration:

| engine | per iteration | vs. a hand-written JS loop |
|---|---:|---:|
| native JS (hand-written) | ~2.9 ns | 1× |
| **Native JS (nifjs)** | **~2.1 ns** | **~1× — the emitted loop *is* native JS** |
| Bytecode VM (nifi) | ~39 µs | ~15,000× slower |
| Tree-walk (nifi) | ~61 µs | ~24,000× slower |

nifjs is **~18,000–28,000× faster** than the interpreter, runs **10 million
iterations in ~21 ms** with no out-of-memory (it has no fixed bump heap), and its
output is byte-identical to the interpreter on supported programs. See
**[Native JS backend](docs/nifjs)** for how and why.

The heavy stages run **off the main thread in a Web Worker**. That is what makes
**Stop** work: a runaway loop can't be interrupted cooperatively, but the worker
can be terminated and a fresh one spun up. It also keeps the editor responsive
during a live type-check.

## Editor intelligence

The playground is a Monaco editor with a nimony grammar and a real **language
server running in a Web Worker**:

- **Live diagnostics** — syntax errors (nifparser) as you type, type errors
  (nimsem) on a short debounce, shown as squiggles and in a problems list.
  nifparser emits **structured, recoverable** diagnostics: unlike classic
  `nifler` (which aborts at the first error), it records *every* problem with a
  precise span, severity, and stable code and keeps parsing — so you see all the
  squiggles at once.
- **Hover** types, `⌃Space` **completion**, `F12` **go-to-definition**, and a
  **Symbols** outline panel.

## The NIF inspector

The source pane tabs between your **Source** and the compilation tower it becomes,
so you can watch nimony's intermediate forms directly:

- **Parsed** — the untyped `.p.nif` from nifparser.
- **Typed** — the `.s.nif` from nimsem, with types and symbols resolved.
- **Run** — the **run rung**: the program's *execution* serialized as NIF (from
  nifi's run emitter), the bottom of nifi's content-addressed compilation tower.

Each is rendered with structure-aware highlighting and stays selectable — a copy
is verbatim NIF.

## Also

**stdin** input, a colon ⇄ **curly-brace** block-mode toggle, three themes, a
resizable / re-orientable split, word-wrap, editor **zoom** (Ctrl+scroll /
Ctrl±), and **shareable links** (the code travels in the URL hash — static host,
no server).

There's also an **offline copy** button: it bundles the whole playground —
every script, the compiled engines, the stdlib, and images — into a single
self-contained `.html` you can save and open from a local `file://` with no
server and no network.

---

The playground's source lives in
[`aoughwl/nimony-playground`](https://github.com/aoughwl/nimony-playground), and
the deployed copy is served from this site at `/playground/`.

[Repo → github.com/aoughwl/nimony-playground](https://github.com/aoughwl/nimony-playground){: .btn .btn-primary }
