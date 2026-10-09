---
title: FAQ
description: What aoughwl is, what Nimony is, what you can use today, what is free and what is paid, and how the numbers on this site are measured.
---

# FAQ

[[toc]]

## What is aoughwl?

A software stack written from scratch in one language,
[Nimony](https://github.com/nim-lang/nimony). It has four parts:

- a **compiler toolchain** for Nimony itself (parser, type checker, lowering,
  and backends for C, JavaScript, TypeScript and Python);
- a **runtime**, [engine](/engine), that runs JavaScript and Nimony in one
  process on one heap;
- a **browser engine**, [Titicaca](/docs/titicaca);
- a **game platform**, [Jester](/jester), where the whole game is mods that can
  be edited while it runs.

## What is Nimony, and how is it related to Nim?

Nimony is the compiler being built as the next generation of
[Nim](https://nim-lang.org): Python-like syntax, static types, compiled to
native code through C. Its compiler passes talk to each other through NIF, a
plain-text tree format. aoughwl's toolchain reads and writes the same files
byte for byte (we call the format AIF), so our passes and Nimony's can be
mixed in one build.

## Why rewrite a compiler that already exists?

To own every layer the rest of the stack runs on. The interpreter, the
JavaScript engine and Jester's live code reloading all need things a stock
compiler does not offer: stopping after any pass, running the typed program
directly, moving code between interpreted and native while it runs. Writing
each pass ourselves, and diffing it against Nimony's, means we can add those
without forking someone else's design.

## Can I use it today?

Yes, two ways:

- **In the browser**, with nothing to install: the
  [playground](https://aoughwl.github.io/playground/) parses, type-checks and
  runs your code in the tab.
- **On Linux**: [Get started in 5 minutes](/start) takes a clean machine to a
  running native binary in about three minutes.

The libraries ([net stack](/docs/net-stack), [css](/docs/css),
[regex](/docs/regex), [unicode](/docs/unicode), [jit](/docs/jit)) are usable
on their own from any Nimony project. [engine](/engine), Jester and Titicaca
are not released yet.

## What is free and what is paid?

Free, MIT-licensed and on GitHub: the parser, the lowering pass, the C backend,
the driver (`aowlmony`), the toolchain manager (`aowlup`), and libraries such
as regex, unicode and jit.

Paid, as one $9.99/month subscription: the interpreter and its debugger, and
the TypeScript, Python and JavaScript/WebAssembly backends. Jester will be
$19.99/month. See the [store](/store/).

Some source is private with public documentation, including the type checker
(`aowlsem`), the JavaScript engine and `engine`.

## How are the numbers on this site measured?

Each stage that replaces an existing tool is run on the same input as that
tool, and the output files are compared byte for byte. A stage passes a case
only when the diff is empty. Conformance numbers for the JavaScript engine and
the browser come from the standard suites: test262, html5lib and the WHATWG
URL tests. Every figure has a date, and the [parity page](/docs/parity) lists
the failures next to the passes.

If a number on this site is wrong or out of date, say so on
[Discord](https://discord.gg/nxa3W7w4rJ); it is the most useful report you can
send.

## Which platforms are supported?

The toolchain installs on Linux x86-64 with glibc 2.34 or newer. On Windows,
use WSL. On macOS, use the playground for now. Jester's player runs on
Windows.

## What happened to aowli?

aowli was the interpreter. It is archived, and its two execution engines (a
tree-walker and a bytecode VM) continue inside [engine](/engine), where they
share a heap and a garbage collector with the JavaScript engine. The
[old aowli pages](/aowli) are kept as a record.

## Who makes this, and how do I get in touch?

aoughwl is a small independent project. Ask anything on
[Discord](https://discord.gg/nxa3W7w4rJ) (`timbuktu_guy`), or open an issue on
the relevant [GitHub repository](https://github.com/aoughwl).
