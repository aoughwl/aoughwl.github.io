# Projects

Every repo in the aoughwl toolchain and its libraries. Each page below is the
canonical docs for its repo; the repo READMEs are short stubs that point here.

| Project | Repo | Status |
|---|---|---|
| [aowlparser](docs/aowlparser) — Nim/Nimony source → `.p.aif` parser (byte-identical to `nifler`) | `aoughwl/aowlparser` | public |
| [aowlsem](docs/aowlsem) — semantic analysis: `.p.aif` → typed `.s.aif` (symbols, overloads, generics) | `aoughwl/aowlsem` | public |
| [aowli](aowli) — two-engine interpreter (tree-walker + bytecode VM) for typed `.s.aif` | `aoughwl/aowli` | private |
| [aowli-release](docs/aowli-release) — prebuilt, binary-only distribution of aowli (`aowli-interp`, `aowli-dbg`) | `aoughwl/aowli-release` | private |
| [aowljs](docs/aowljs) — `.s.aif` → native-JavaScript backend | `aoughwl/aowljs` | public |
| [aowljs-js](docs/aowljs) — the hand-written JS bootstrap (seed & differential oracle) | `aoughwl/aowljs-js` | public |
| [aowlc](docs/aowlc) — `.c.aif` → C native backend (ARC baked in, GC-free) | `aoughwl/aowlc` | public |
| [aowlhexer](docs/aowlhexer) — the lowering pass (ARC/closures/exceptions/mono) | `aoughwl/aowlhexer` | private |
| [aowlmony](docs/aowlmony) — the driver: `.nim` → {native \| interpret \| web} over the whole stack | `aoughwl/aowlmony` | public |
| [aowlrt](docs/aowlrt) — the aowl system module + runtime (strings/seqs/ARC) for native linking | `aoughwl/aowlrt` | public · scaffolding |
| [nimony-playground](playground) — browser playground, `aowli` compiled to JS | `aoughwl/nimony-playground` | public |
| [aowlweb](docs/aowlweb) — JS + WASM backends & async runtime | `aoughwl/aowlweb` | private repo · public docs |
| [aowlcode](docs/aowlcode) — Claude Code plugin + MCP server (renamed from `nim-code`) | `aoughwl/aowlcode` | public |
| [aowllsp](docs/aowllsp) — Language Server (nimony rewrite): diagnostics + type-directed completion | `aoughwl/aowllsp` | public |
| [aowlsuggest](docs/aowlsuggest) — diagnostics, quick-fixes & lint layer over `aowlparser`'s `check` | `aoughwl/aowlsuggest` | public |
| [aowlfmt](docs/aowlfmt) — verified layout formatter (proves it changed nothing but whitespace) | `aoughwl/aowlfmt` | public |
| [aowltest](docs/aowltest) — content-addressed test runner: skips a test whose transitive input hash is unchanged | `aoughwl/aowltest` | public |
| [aowlhost](docs/aowlhost) — runs an aowl module as a plugin under a capability policy (no-IO by default) | `aoughwl/aowlhost` | public |
| [aowllens](docs/aiflens) — NIF lens: typed `.s.nif` → JSON (decls/outline/members/typeat) for tooling | `aoughwl/aowllens` | public |
| [net stack](docs/net-stack) — `tcp`/`net`/`tls`/`http`/`compress`/`serve`/`ws`/`requests` | `aoughwl/{tcp,net,tls,http,compress,serve,ws,requests}` | public |
| [web](docs/web) — HTML + validated CSS in one nimony block (DSL) | `aoughwl/web` | public |
| [html](docs/html) — typed HTML5 registry + renderer | `aoughwl/html` | public |
| [css](docs/css) — MDN-typed CSS engine (parse + validate) | `aoughwl/css` | public |
| [aowlts](docs/aowlts) — idiomatic TypeScript backend | `aoughwl/aowlts` | early scaffold · private |
| [aowlpy](docs/aowlpy) — idiomatic Python backend | `aoughwl/aowlpy` | early scaffold · private |
| [aowlhl](docs/aowlhl) — shared High-Level IR | `aoughwl/aowlhl` | early scaffold · private |
| [aowlabi](docs/aowlabi) — shared value-representation / ABI truth (layout, heap-block spec, marshal matrix) | `aoughwl/aowlabi` | private |
