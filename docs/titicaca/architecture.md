---
title: Titicaca architecture
description: The pure-Nimony modules behind Titicaca, the Jester web browser, and how a page flows through them.
---

# Architecture

Titicaca is a set of plain Nimony modules inside one Jester mod. None of the
engine modules depend on Unity, a window or a network: they take text and return
a tree, which is why the same modules run headless under the test runner (see
[Web Platform Tests](/docs/titicaca/wpt)).

## The pipeline

1. **Fetch.** The mod asks the host for bytes over HTTP, with a cache and a
   cookie jar of its own (`webcache`, `webcookie`).
2. **Parse.** `webhtml` builds a DOM from HTML; `webxml` does the same for XML and
   XHTML pages. `weburl` and `webidna` handle URL parsing and internationalised
   host names, `webencoding` the character sets.
3. **Style.** `webcsssyntax` tokenises and parses CSS per the CSS Syntax spec
   (declaration lists, `var()` substitution, unicode ranges). `webselector`
   parses, matches and serialises Selectors Level 4. `webcss` runs the cascade,
   including `@namespace`, nesting and named colours.
4. **Script.** A JavaScript engine: `jslex`, `jsparse`, `jsvalue`, `jsregex`,
   `jsinterp`. It has its own realms, so an iframe's scripts see the iframe's
   globals.
5. **DOM binding.** `jsdom` exposes the DOM to the engine: nodes, events, live
   collections, `getComputedStyle`, `querySelector`. `webreflect` holds the
   generated attribute-reflection tables for HTML elements.
6. **Layout and paint.** `weblayout`, `webtable`, `webgrid`, `webfloat`,
   `webtext`, `webinnertext`, `webimg`, `websvg` and related modules produce
   boxes that the mod draws through Jester's UI library.

## Design rules

- **Pure Nimony.** No C engine linked in; the whole thing is inspectable and
  swappable like any other mod.
- **Spec-shaped modules.** Each module follows one specification, so a test
  failure points at one place.
- **Measured, not assumed.** Correctness claims are numbers from the Web
  Platform Tests, never from self-written tests alone.
