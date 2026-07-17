---
title: AIF ≡ NIF
permalink: /docs/aif
parent: Engineering Notes
nav_order: 2
nav_exclude: true
---

# AIF ≡ NIF — how aoughwl interops with Nimony
{: .no_toc }

aoughwl is a ground-up reimplementation of the Nimony toolchain. The reason it
drops straight into the existing nimony world — and the reason **any Nim or
Nimony program is expected to behave identically in aoughwl** — is one deliberate
decision about the intermediate format.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The one decision

**AIF — the Aowl Intermediate Format — is byte-for-byte Nimony's NIF today.**

NIF is nimony's persistent, homoiconic S-expression IR: the `.p` (parsed),
`.s` (semchecked), and `.c` (lowered) artifacts the compiler passes between its
stages. AIF is the same bytes. The rebrand is an identity — a statement that the
aoughwl stack *owns* this format now and will steer it — not a divergence in the
wire format. Where you'd read `.p.nif` / `.s.nif` / `.c.nif`, aoughwl writes
`.p.aif` / `.s.aif` / `.c.aif`, and they are interchangeable.

Because the bytes match, each aoughwl stage is a **drop-in** for its nimony
counterpart:

| nimony stage | aoughwl stage | seam |
|---|---|---|
| `nifler` (parse) | **aowlparser** | `source → .p.aif` |
| `nimsem` (semcheck) | **aowlsem** | `.p.aif → .s.aif` |
| `hexer` (lower) | **aowlhexer** | `.s.aif → .c.aif` |

You can run an all-aoughwl pipeline, an all-nimony pipeline, or **any mix** —
`nifler → aowlsem → hexer`, `aowlparser → nimsem → aowlhexer`, and so on. The seams
don't care which side produced the artifact.

## What "behaves identically" means

The contract is **observable-behaviour equivalence**: a program compiled and run
through aoughwl produces the same result as the same program through stock
nimony. We hold ourselves to it two ways:

- **Byte-exactness where it's testable.** `aowlparser`'s output is byte-for-byte
  `nifler`'s across the whole nimony standard library and corpus (bar one header
  line it stamps with its own `(.vendor "aowlparser")` identity, which the
  differential harness neutralizes). The parse artifact you feed the rest of the
  pipeline is *the same file* nimony would have produced.
- **Differential execution.** `aowli` (the interpreter/VM) and the native/JS
  backends are checked against nimony's own compile-and-run over its test corpus.
  Same inputs, same outputs, or it's a bug.

The oracle is nimony's own toolchain: we keep a byte-exact reference build to diff
against, so any drift from identical behaviour shows up the moment it appears.

## What you get on top

Identical behaviour is the floor. Because the stack is written *in* Nimony and
self-hosts over a format it owns, it also gives you what stock nimony can't:

- **Runs in the browser.** Parser, semcheck, and execution all compile to
  JavaScript, so the full pipeline runs client-side — see the
  [playground](../playground).
- **Native and web backends.** [`aowlc`](aowlc) emits C (GC-free — ARC is baked
  into the lowered `.c.aif`); [`aowljs`](aowljs) emits readable, near-native
  JavaScript.
- **Fast incremental re-checks** for live editor tooling, and a fuller,
  opinionated stdlib and networking stack.

## Status & privacy

The parse front-end ([aowlparser](aowlparser)), the interpreter ([aowli](../aowli)),
and the native/JS backends ([aowlc](aowlc), [aowljs](aowljs)) are public. The
**semantic checker (aowlsem)** and the **lowering (aowlhexer)** are
**intentionally kept private for now** — their docs live on this site, and
access is granted on request (ask on Discord, **timbuktu_guy**, and you'll be
added). The [playground](../playground) moves onto the new sem + hexing shortly.
