---
title: Home
layout: home
nav_order: 0
---

# aoughwl
{: .fs-9 }

Next-gen self-hosted platform for things n stuff — built on our own fork of
the Nim toolchain.
{: .fs-6 .fw-300 }

[Nimony fork →](nimony){: .btn .btn-primary .mr-2 }
[All projects →](projects){: .btn }

---

## What this is

**[aoughwl/nimony](nimony)** is our opinionated fork of
[Nimony](https://github.com/nim-lang/nimony) — the NIF-based reimplementation of
the Nim compiler. It tracks upstream daily, ships our own compiler fixes and
features on top, and carries a fuller, more opinionated standard library. It is
the **headline** here — everything else on this site is tooling, stdlib, or
backends built around it.

Start with the **[Issues Fixed & Features Added](nimony)** record — the running
ledger of what our tree does that stock upstream nimony does not.

## The projects

| Project | What it is |
|---|---|
| **[nimony](nimony)** | The fork itself: compiler fixes, `.passive`/async features, opinionated stdlib. |
| **[nimony-web](docs/nimony-web)** | JavaScript **and** WebAssembly backends — one linear-memory model, compiled twice. Plus the cooperative async runtime. |
| **[nim-code](docs/nim-code)** | Claude Code plugin + MCP server that mediates agent access to the Nim/Nimony toolchains through compact, structured tools. |
| **[niflens](docs/niflens)** | A NIF lens for tooling — a thin CLI over the compiler's own NIF libraries, emitting compact JSON. |
| **[nimony-lsp](docs/nimony-lsp)** | Language Server Protocol implementation for Nimony, plus a full VSCode extension. |
| **[net stack](docs/net-stack)** | Eight one-concern repos: `tcp`·`net`·`tls`·`http`·`compress`·`serve`·`ws`·`requests` — TLS 1.3, dual-stack IPv6, HTTP/1.1 + HTTP/2 server, WebSocket, HTTP/3 client, and a browser-impersonating `requests`. |
| **[web](docs/web)** · **[html](docs/html)** · **[css](docs/css)** | A declarative HTML+CSS DSL, a typed HTML5 registry/renderer, and an MDN-typed CSS engine that validates against the real grammar. |
| **[nimony-ts](docs/nimony-ts)** · **[nimony-py](docs/nimony-py)** · **[nimony-hl](docs/nimony-hl)** | Idiomatic TypeScript / Python backends and the shared High-Level IR that feeds them. |

## The private side

The official aoughwl product — the self-hosted platform itself — is closed and
private, and will be sold as a monthly per-seat subscription. That is not here
yet; it opens up once nimony is a lot further along. The JavaScript / TypeScript
/ WASM / Python backend repos are private too, but their **docs live here**.
Want access? Reach out on Discord (**timbuktu_guy**).
