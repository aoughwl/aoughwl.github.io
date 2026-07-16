---
title: Projects
permalink: /projects
nav_exclude: true
---

# Projects

Every repo in the aoughwl toolchain and its libraries. Each page below is the
canonical docs for its repo; the repo READMEs are short stubs that point here.

| Project | Repo | Status |
|---|---|---|
| [aowlparse](docs/aowlparse) — Nim/Nimony source → `.p.aif` parser (byte-identical to `nifler`) | `aoughwl/aowlparse` | public |
| aowlsem — clean-room semcheck: `.p.aif` → typed `.s.aif` | `aoughwl/aowlsem` | private |
| [aowli](aowli) — two-engine interpreter (tree-walker + bytecode VM) for typed `.s.aif` | `aoughwl/aowli` | private |
| [aowljs](docs/aowljs) — `.s.aif` → native-JavaScript backend | `aoughwl/aowljs` | public |
| [aowljs-js](docs/aowljs) — the hand-written JS bootstrap (seed & differential oracle) | `aoughwl/aowljs-js` | public |
| [aowlc](docs/aowlc) — `.c.aif` → C native backend (ARC baked in, GC-free) | `aoughwl/aowlc` | public |
| [aowlhexer](docs/aowlhexer) — the lowering pass (ARC/closures/exceptions/mono) | `aoughwl/aowlhexer` | private |
| [aowlmony](docs/aowlmony) — the driver: `.nim` → {native \| interpret \| web} over the whole stack | `aoughwl/aowlmony` | public |
| [aowllib](docs/aowllib) — the aowl system module + runtime (strings/seqs/ARC) for native linking | `aoughwl/aowllib` | public · scaffolding |
| [nimony-playground](playground) — browser playground, `aowli` compiled to JS | `aoughwl/nimony-playground` | public |
| [aowlweb](docs/aowlweb) — JS + WASM backends & async runtime | `aoughwl/aowlweb` | private repo · public docs |
| [aowl-code](docs/aowl-code) — Claude Code plugin + MCP server | `aoughwl/aowl-code` | public |
| [nimony-lsp](docs/nimony-lsp) — Language Server + VSCode extension | `aoughwl/nimony-lsp` | public |
| [net stack](docs/net-stack) — `tcp`/`net`/`tls`/`http`/`compress`/`serve`/`ws`/`requests` | `aoughwl/{tcp,net,tls,http,compress,serve,ws,requests}` | public |
| [web](docs/web) — HTML + validated CSS in one nimony block (DSL) | `aoughwl/web` | public |
| [html](docs/html) — typed HTML5 registry + renderer | `aoughwl/html` | public |
| [css](docs/css) — MDN-typed CSS engine (parse + validate) | `aoughwl/css` | public |
| [aowlts](docs/aowlts) — idiomatic TypeScript backend | `aoughwl/aowlts` | early scaffold · private |
| [aowlpy](docs/aowlpy) — idiomatic Python backend | `aoughwl/aowlpy` | early scaffold · private |
| [aowlhl](docs/aowlhl) — shared High-Level IR | `aoughwl/aowlhl` | early scaffold · private |
