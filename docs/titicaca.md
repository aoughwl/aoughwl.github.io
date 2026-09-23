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

- [Architecture](/docs/titicaca/architecture): the modules and how a page moves through them.
- [Web Platform Tests](/docs/titicaca/wpt): where it stands against the standard suite, and how to run it.
- [Live demo, full page](/titicaca/): a standalone page, outside the docs layout.

## What it is for

The goal is not to out-run a mainstream browser. It is to have a browser that is
moddable in the same sense the rest of Jester is: a page renderer whose parts
are ordinary mod modules, loaded from data, with no hardcoded dependency on a
particular engine.

## Status

It renders real pages, runs page scripts, and is measured against the
[Web Platform Tests](/docs/titicaca/wpt). On the subset we track it sits at about
93.5% of subtests, against 96.2% for Ladybird on the same set.
