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
| [Compiler Pipeline](docs/compiler-pipeline) | The front half — `aowlparse` (parse), `aowlsem` (semcheck), `aowlhexer` (lower), `aowlmony` (driver), `aowllib` (runtime). |
| [Builtin Libraries](libraries) | The stdlib-grade packages: the net stack (`tcp → net → tls → serve`, `http`, `ws`, `requests`, `compress`) and the `web` / `html` / `css` layer. |
| [Backends](backends) | Every way to run or emit a program — native C (`aowlc`), native and faithful JavaScript (`aowljs`, `aowl-web`), WebAssembly, the interpreter (`aowli`), and idiomatic TypeScript / Python. |
| [Tools](tools) | The Claude Code plugin + MCP server, the LSP + VSCode extension, and NIF inspection CLIs. |

## Why it hangs together

Every piece is written *in* Nimony and compiles *through* Nimony, and every
artifact it passes is [AIF ≡ NIF](docs/aif) — byte-for-byte nimony's own format.
So the toolchain isn't a parallel dialect: each stage is a literal drop-in for
its nimony counterpart, reproducing the compiler's own tools while running as an
ordinary Nimony program — including in the browser, where the classic Nim
compiler can't go.
