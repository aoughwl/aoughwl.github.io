---
title: Titicaca — the Jester web browser
description: Titicaca is the web browser that runs as a Jester mod. Its HTML, CSS and JavaScript engine is written in pure Nimony, with no embedded browser engine underneath.
---

# Titicaca

Titicaca is a web browser that ships as a [Jester](/jester) mod (`aoughwl.web`).
Nothing under it is Chromium, WebKit, Gecko or any other embedded engine: the
HTML parser, the CSS cascade and layout, the DOM and the JavaScript interpreter
are all written in **pure Nimony**, compiled by our own toolchain and run by
[aowli](/aowli) like every other Jester mod. Because it is a mod, it can be
edited and hot-swapped while it is running, and everything it does reaches the
outside world through the same [host surface](/docs/jester/host-surface) as any
other mod.

## Pages

| Page | What is in it |
| --- | --- |
| [Architecture](/docs/titicaca/architecture) | The modules and how a page moves through them |
| [The JavaScript engine](/docs/titicaca/javascript) | Lexer, parser, interpreter, realms, what is and is not implemented |
| [The DOM](/docs/titicaca/dom) | Nodes, events, live collections, reflection, frames |
| [CSS, selectors and layout](/docs/titicaca/css-and-layout) | Syntax, cascade, selectors, boxes |
| [Networking, storage and security](/docs/titicaca/networking) | Fetching, cache, cookies, URLs, what a page is allowed to do |
| [Web Platform Tests](/docs/titicaca/wpt) | The standing, the method, how to run the runner |
| [Limits and roadmap](/docs/titicaca/limits) | What it cannot do yet and what would fix it |
| [Live demo, full page](/titicaca/) | A standalone page outside the docs layout |

## What it is for

The goal is not to out-run a mainstream browser. It is a browser that is
moddable in the same sense the rest of Jester is: a page renderer whose parts
are ordinary mod modules, loaded from data, with no hardcoded dependency on a
particular engine. If you want a different cascade, a different image decoder or
a different script engine, you replace a module, not a fork of a C++ codebase.

It is also a stress test. A browser is the largest single program a Jester mod
can be, and the Web Platform Tests give it an external, unforgiving score. Most
of what got fixed in the interpreter and the host surface in the last months was
found by pointing this mod at a test suite.

## How it is built

- **Pure Nimony.** Every module is ordinary Nimony source; there is no native
  engine linked in.
- **Headless by construction.** The engine modules take text and return trees.
  They do not touch a window, a socket or Unity, which is why the same code runs
  under the command-line test runner.
- **One module per specification.** URL, encoding, CSS Syntax, Selectors, XML,
  HTML each live in their own file and follow their own standard.
- **Measured.** Claims about correctness come from the
  [Web Platform Tests](/docs/titicaca/wpt), not from tests written by the same
  people who wrote the code.

## Status

It renders real pages, runs page scripts and passes about 93.5% of subtests on
the set we track, against 96.2% for Ladybird on the same set. It is a browser you
can use for reading and for testing, not one to bank with. See
[Limits and roadmap](/docs/titicaca/limits) for the honest list of what is
missing.
