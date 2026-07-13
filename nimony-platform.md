---
title: Nimony
nav_order: 1
has_children: true
permalink: /nimony-platform
---

# Nimony
{: .no_toc }

Everything aoughwl builds on and around [Nimony](https://github.com/nim-lang/nimony)
— the NIF-based reimplementation of the Nim compiler — in one place: the fork, the
standard-library and networking stack, the web backends, the developer tooling, and
the from-scratch NIF toolchain that runs the whole pipeline in the browser.
{: .fs-6 .fw-300 }

---

## The sections

| Section | What's inside |
|:--|:--|
| [Fork](nimony) | `aoughwl/nimony` — the opinionated fork that tracks upstream daily, plus its divergences from `nim-lang/nimony`. |
| [Libraries](libraries) | The Nimony-native standard-library and networking stack (`tcp → net → tls → serve`, `http`, `ws`, `requests`, compression) and more. |
| [Backends](backends) | Alternate code generators — the JavaScript / WebAssembly backends and other target experiments. |
| [Tools](tools) | Developer tooling: the Claude Code plugin + MCP server, the LSP + editor extension, and NIF inspection CLIs. |
| [NIF Toolchain Alternatives](docs/nif-toolchain-alternatives) | Self-hosted, browser-ready reimplementations of the compiler pipeline stages — the `nifparser` parser and the `nifi` interpreter/VM. |
| [Sandbox Playground](playground) | Run and edit Nimony in the browser, compiled client-side through the self-hosted toolchain. |

## Why it hangs together

The through-line is **self-hosting**: each piece is written *in* Nimony and
compiles *through* Nimony, so the entire toolchain — parse, semcheck, interpret —
can be taken places the classic Nim compiler can't go, most notably the browser.
The [NIF Toolchain Alternatives](docs/nif-toolchain-alternatives) are where that
promise is cashed out: a parser and an interpreter that reproduce the compiler's
own tools byte-for-byte while running as ordinary Nimony programs.
