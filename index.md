---
title: Home
layout: home
nav_order: 0
---

# aoughwl
{: .fs-9 }

Next-gen self-hosted platform for things n stuff — now standing on our own
ground-up reimplementation of the Nim/Nimony toolchain.
{: .fs-6 .fw-300 }

[The stack →](nimony-platform){: .btn .btn-primary .mr-2 }
[Interop: AIF ≡ NIF →](docs/aif){: .btn .mr-2 }
[All projects →](projects){: .btn }

---

## What this is

**aoughwl** (shorthand **aowl**, file extension `.aowl`) is a **from-scratch
reimplementation of the entire Nimony toolchain** — parser, semantic checker,
lowering, and code generators — written *in* Nimony and self-hosting, so the
whole pipeline runs where the classic Nim compiler can't, most notably the
browser. It is **not a fork.** The one fork we keep, `aoughwl/nimony`, is now a
supporting reference — the oracle we validate byte-for-byte against, and where
upstream-portable compiler fixes land — not the headline.

> **How we got here.** The aoughwl substrate was always going to run *on* Nimony.
> We started patching Nimony where it fell short — then rebuilding the pieces from
> scratch, and ours kept coming out better. We didn't set out to replace Nimony.
> We're here now, so we're finishing it.

## Runs Nim/Nimony identically — plus benefits

The stack's intermediate format, **AIF (the Aowl Intermediate Format), is
byte-for-byte Nimony's NIF today.** That is the whole interop story: every stage
is a **drop-in** in the nimony toolchain, and **any Nim or Nimony program is
expected to behave identically in aoughwl** — same semantics, same output — with
benefits stock nimony doesn't give you:

- runs **client-side in the browser** (parse → semcheck → run), through the
  self-hosted toolchain
- **near-instant incremental re-checks** for live editor tooling
- a **fuller, opinionated stdlib** and a complete networking stack
- **alternate backends** — native C, native JavaScript, an interpreter/VM

Full details on the format and the drop-in seams: **[AIF ≡ NIF →](docs/aif)**.

## The stack

```
 .nim / .aowl ──► aifparser ──► aifsem ──► aifhexer ──┬─ aifc  → C / native
    source          parse       semcheck    lower     ├─ aifjs → JavaScript
                                                       └─ aifi  → interpret / VM
```

Every seam is **AIF (≡ NIF)**, so any stage can be swapped in beside nimony's own
(`nifler` / `nimsem` / `hexer`) or run standalone. `aifi` and `aifjs` are what
power the browser **[playground](playground)**.

| Stage | Repo | What it is |
|---|---|---|
| parse | **[aifparser](docs/nifparser)** | Nim/Nimony source → `.p.aif`; byte-identical to `nifler`, self-hosted, browser-ready. |
| semcheck | **aifsem** *(private)* | clean-room `nimsem`: `.p.aif` → typed `.s.aif`. |
| lower | **[aifhexer](docs/aifhexer)** *(private)* | ARC / closures / exceptions / monomorphisation → `.c.aif`. |
| native | **[aifc](docs/nifc)** | post-hexer `.c.aif` → C, linked with `gcc` (GC-free — ARC baked in). |
| web | **[aifjs](docs/nifjs)** + [aifjs-js](docs/nifjs) | typed `.s.aif` → native JavaScript; near-native speed, readable output. |
| run | **[aifi](nifi)** | two-engine interpreter (tree-walker + bytecode VM), differentially tested against native. |
| driver | **[aifmony](docs/aifmony)** | one command: `.nim` → { native \| interpret \| web } over the whole self-owned stack. |
| runtime | **[aiflib](docs/aiflib)** | the aowl system module + runtime (strings / seqs / ARC / GC) the backends link against. |

## Around the stack

| Project | What it is |
|---|---|
| **[nim-code](docs/nim-code)** | Claude Code plugin + MCP server: compact, structured agent access to the Nim/Nimony toolchains. |
| **[nimony-lsp](docs/nimony-lsp)** | Language Server + full VSCode extension; live as-you-type diagnostics. |
| **[net stack](docs/net-stack)** | Eight one-concern repos — `tcp`·`net`·`tls`·`http`·`compress`·`serve`·`ws`·`requests` — TLS 1.3, dual-stack IPv6, HTTP/1.1 + HTTP/2 server, WebSocket, HTTP/3 client, browser-impersonating `requests`. |
| **[web](docs/web)** · **[html](docs/html)** · **[css](docs/css)** | A declarative HTML+CSS DSL, a typed HTML5 registry/renderer, and an MDN-typed CSS engine that validates against the real grammar. |
| **[nimony-ts](docs/nimony-ts)** · **[nimony-py](docs/nimony-py)** · **[nimony-hl](docs/nimony-hl)** | Idiomatic TypeScript / Python backends and the shared High-Level IR that feeds them. |
| **[aoughwl/nimony](nimony)** | The reference fork: the byte-exact oracle, and where upstream-portable compiler fixes and the opinionated stdlib land. |

## The private side

Some of the stack is **intentionally kept private for now** — notably the
semantic checker (**aifsem**) and the lowering (**aifhexer**), along with the
JavaScript / TypeScript / WASM / Python backend repos. Their
**docs live here**, and access is granted on request — just ask and you'll be
added. The **[playground](playground)** will shortly switch over to run entirely
on the new sem + hexing.

And this stack is the *floor*, not the building. The full aoughwl product — the
self-hosted platform this was all built to carry — is an all-in-one system of a
kind nobody else is shipping. We're not showing it yet, and that's on purpose:
what's public here is the toolchain it stands on. It opens up as the stack
matures. Curious? Reach out on Discord (**timbuktu_guy**).
