---
title: Sandbox Playground
parent: Nimony
nav_order: 6
---

# Playground
{: .no_toc }

A browser playground that runs nimony **entirely client-side**. The
[nifi](nifi) interpreter is compiled to JavaScript — via the nimony JS backend
([nimony-web](docs/nimony-web)) — into a single ~1.6 MB `nifi.js` bundle. No
backend, no server round-trip: pick an example and it runs the precompiled typed
NIF right in your browser.
{: .fs-6 .fw-300 }

[Launch the playground →](/playground/){: .btn .btn-primary .fs-5 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## How it works

The playground is a Monaco editor two-pane UI — source on one side, output on
the other — with a nimony syntax grammar. There is **no backend**: the
[nifi](nifi) interpreter itself is compiled to JS and shipped as a static asset,
so running a program is a local call, not a network request. What executes in
the browser is the same typed `.s.nif` the native backend would consume,
precompiled ahead of time.

## Examples

It ships starter examples you can run and edit:

- **Hello** — the smallest program.
- **Fibonacci** — recursion.
- **FizzBuzz** — control flow and modulo.
- **Collatz** — iteration to a fixed point.

## Roadmap: Tier 1 / 2 / 3

- **Tier 1** — runs precompiled `.s.nif` client-side.
- **Tier 2 (live now)** — the whole compiler front-to-back runs in your browser.
  Edit any program and it is **parsed** ([nifparser](docs/nifparser) → `.p.nif`),
  **type-checked** (`nimsem` → typed `.s.nif`) and **executed** ([nifi](nifi))
  entirely in the tab. Syntax errors appear as you type; type errors appear on a
  short debounce; pressing Run compiles and runs whatever is in the editor. The
  chain `source → nifparser → nimsem → nifi` is fully wired — no backend, no
  stub. nimsem ships as an ~8.9 MB JS bundle plus a ~0.85 MB pre-semchecked
  stdlib closure (system/syncio/formatfloat) served from an in-memory VFS.
- **Tier 3 (planned)** — move the compile chain into a Web Worker and add
  incremental recompilation so large edits stay instant.

---

[Repo → github.com/aoughwl/nimony-playground](https://github.com/aoughwl/nimony-playground){: .btn .btn-primary }
