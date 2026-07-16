---
title: Documentation
nav_order: 1
has_children: true
permalink: /nimony-platform
---

# Nimony
{: .no_toc }

aoughwl's ground-up reimplementation of the [Nimony](https://github.com/nim-lang/nimony)
toolchain — the NIF-based Nim compiler — in one place: the from-scratch pipeline
(parse → semcheck → lower → run), the standard-library and networking stack, the
web/native backends, the developer tooling, and the reference fork we validate
against. The format is shared — [**AIF ≡ NIF**](docs/aif), byte-for-byte — so
every piece is a drop-in and any Nim/Nimony program behaves identically.
{: .fs-6 .fw-300 }

---

## The sections

| Section | What's inside |
|:--|:--|
| [AIF ≡ NIF](docs/aif) | How aoughwl interops with nimony: the shared byte-compatible format and the drop-in seams. Start here. |
| [NIF Toolchain Alternatives](docs/nif-toolchain-alternatives) | The self-hosted, browser-ready pipeline stages that *are* the reimplementation — the `aifparser` parser and the `aifi` interpreter/VM. |
| [Libraries](libraries) | The Nimony-native standard-library and networking stack (`tcp → net → tls → serve`, `http`, `ws`, `requests`, compression) and more. |
| [Backends](backends) | Alternate code generators — the native C / JavaScript / WebAssembly backends and other target experiments. |
| [Tools](tools) | Developer tooling: the Claude Code plugin + MCP server, the LSP + editor extension, and NIF inspection CLIs. |
| [Fork](nimony) | `aoughwl/nimony` — the reference fork: the byte-exact oracle, and where upstream-portable compiler fixes and the opinionated stdlib land. |
| [Sandbox Playground](playground) | Run and edit Nimony in the browser, compiled client-side through the self-hosted toolchain. |

## Why it hangs together

The through-line is **self-hosting**: each piece is written *in* Nimony and
compiles *through* Nimony, so the entire toolchain — parse, semcheck, lower,
interpret — can be taken places the classic Nim compiler can't go, most notably
the browser. And because the format is [AIF ≡ NIF](docs/aif) — byte-for-byte
nimony's own — the reimplementation isn't a parallel dialect: each stage is a
literal drop-in that reproduces the compiler's own tools while running as an
ordinary Nimony program.
