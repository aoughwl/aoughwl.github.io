---
title: Documentation
nav_order: 1
has_children: true
permalink: /documentation
---

# Documentation
{: .no_toc }

Reference for the aoughwl toolchain, libraries, and tooling — terse and factual,
tested against the code. For the *why* — how the stack was built and the calls we
made — see **[Engineering Notes](engineering-notes)**.
{: .fs-6 .fw-300 }

---

| Section | What's inside |
|:--|:--|
| [AIF ≡ NIF](docs/aif) | The interop contract with Nimony: one shared byte-compatible format, drop-in seams. **Start here.** |
| [Toolchain](docs/nif-toolchain-alternatives) | The from-scratch pipeline — `aifparser` (parse), `aifsem` (semcheck), `aifhexer` (lower), `aifc` / `aifjs` (backends), `aifi` (interpret/VM), `aifmony` (driver), `aiflib` (runtime). |
| [Libraries](libraries) | The stdlib-grade packages: the net stack (`tcp → net → tls → serve`, `http`, `ws`, `requests`, `compress`) and the `web` / `html` / `css` layer. |
| [Backends](backends) | Alternate code generators — the JavaScript / WebAssembly, TypeScript, and Python backends, plus the shared High-Level IR. |
| [Tools](tools) | The Claude Code plugin + MCP server, the LSP + VSCode extension, and NIF inspection CLIs. |
| [Playground](playground) | Run and edit in the browser, compiled client-side through the self-hosted toolchain. |

## Why it hangs together

Every piece is written *in* Nimony and compiles *through* Nimony, and every
artifact it passes is [AIF ≡ NIF](docs/aif) — byte-for-byte nimony's own format.
So the toolchain isn't a parallel dialect: each stage is a literal drop-in for
its nimony counterpart, reproducing the compiler's own tools while running as an
ordinary Nimony program — including in the browser, where the classic Nim
compiler can't go.
