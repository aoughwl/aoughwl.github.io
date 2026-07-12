---
title: Playground
nav_order: 8
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

- **Tier 1 (today)** — runs precompiled `.s.nif` client-side. Pick an example, it
  runs in the browser.
- **Tier 2 (in progress)** — port the parse + semcheck frontend to JS so edits
  recompile live. Both halves are now de-risked: a from-scratch, browser-capable
  parser — [nifparser](nifparser) — parses all five example programs
  byte-identical to the native compiler, and semcheck (`nimsem`) translates to JS
  with zero unsupported constructs. What remains is wiring the chain
  `source → nifparser → nimsem → nifi` behind the browser stub.
- **Tier 3 (planned)** — LSP diagnostics in a Web Worker.

The seams for the later tiers are already stubbed: `NifiCore.compileAndRun` and
`setDiagnostics` exist and are wired in, waiting for the frontend and diagnostics
to land behind them.

---

[Repo → github.com/aoughwl/nimony-playground](https://github.com/aoughwl/nimony-playground){: .btn .btn-primary }
