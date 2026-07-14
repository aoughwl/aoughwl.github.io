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
   │  nifi       (aoughwl/nifi)            Web Worker
   ▼            VM (fast path) ┐
 output          tree-walker   ┘ fallback
```

- **[nifparser](docs/nifparser)** parses your source to the untyped `.p.nif` on
  the main thread — it's the browser-capable replacement for classic Nim's
  native-only `nifler`, and it also feeds the live editor intelligence.
- **nimsem** turns the `.p.nif` into a typed `.s.nif`, resolving every symbol,
  overload, and type. It runs in a Web Worker and reuses a warm, pre-loaded
  stdlib closure, so every check after the first is milliseconds (an ~8.9 MB JS
  bundle plus a pre-semchecked `system`/`syncio`/… closure from an in-memory VFS).
- **[nifi](nifi)** runs the typed `.s.nif`. It tries a **bytecode VM** first and
  falls back to an always-correct **tree-walker** for programs the VM can't yet
  run self-contained — so runs are fast when they can be and correct always.

The two heavy stages run **off the main thread in a Web Worker**. That is what
makes **Stop** work: a runaway loop can't be interrupted cooperatively, but the
worker can be terminated and a fresh one spun up from the HTTP cache. It also
keeps the editor responsive during a live type-check.

## Editor intelligence

The playground is a Monaco editor with a nimony grammar and a real **language
server running in a Web Worker**:

- **Live diagnostics** — syntax errors (nifparser) as you type, type errors
  (nimsem) on a short debounce, shown as squiggles and in a problems list.
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
resizable / re-orientable split, word-wrap, and **shareable links** (the code
travels in the URL hash — static host, no server).

---

The playground's source lives in
[`aoughwl/nimony-playground`](https://github.com/aoughwl/nimony-playground), and
the deployed copy is served from this site at `/playground/`.

[Repo → github.com/aoughwl/nimony-playground](https://github.com/aoughwl/nimony-playground){: .btn .btn-primary }
