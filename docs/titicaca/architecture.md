---
title: Titicaca architecture
description: The pure-Nimony modules behind Titicaca, the Jester web browser, and how a page flows through them.
---

# Architecture

Titicaca is a set of plain Nimony modules inside one Jester mod. The engine
modules take text and return a tree; only the mod's entry point talks to the
host, which is how the same code runs both inside Jester and under the test
runner.

## The pipeline

1. **Fetch.** The mod asks the host for bytes over HTTP. It keeps its own cache
   and cookie jar (`webcache`, `webcookie`).
2. **Decode.** `webencoding` turns bytes into text using the character set from
   the response, a `<meta>` tag or a byte-order mark.
3. **Parse.** `webhtml` builds a DOM from HTML. `webxml` parses and serialises XML,
   and pages served as XHTML take that path. `weburl` and `webidna` parse URLs and
   internationalised host names.
4. **Style.** `webcsssyntax` tokenises CSS. `webselector` parses, matches and
   serialises selectors. `webcss` runs the cascade and computes styles.
5. **Script.** `jslex`, `jsparse`, `jsvalue`, `jsregex` and `jsinterp` make up the
   JavaScript engine. `jsdom` binds the DOM into it and `webreflect` supplies the
   generated attribute-reflection tables.
6. **Layout.** `weblayout`, `webtext`, `webfloat`, `webtable`, `webgrid`,
   `webinnertext`, `webimg` and `websvg` turn styled nodes into boxes.
7. **Paint and input.** The mod draws boxes through Jester's UI library and feeds
   pointer and keyboard events back into the DOM as real events.

## Module map

| Area | Modules |
| --- | --- |
| Entry, chrome | `main`, `webmenu`, `webform` |
| Networking, storage | `webcache`, `webcookie` |
| Text and URLs | `weburl`, `webidna`, `webidnadata`, `webencoding`, `webtext` |
| Markup | `webhtml`, `webxml`, `webmd` |
| Styling | `webcsssyntax`, `webselector`, `websel`, `webcss` |
| Script | `jslex`, `jsparse`, `jsvalue`, `jsregex`, `jsinterp`, `jsdom`, `webreflect` |
| Layout and media | `weblayout`, `webfloat`, `webtable`, `webgrid`, `webmatrix`, `webinnertext`, `webimg`, `websvg` |

## Design rules

- **Pure Nimony.** The whole thing is inspectable and swappable like any mod.
- **Spec-shaped modules.** A test failure points at one specification and so at
  one file.
- **Generated where the spec is a table.** Attribute reflection and event
  handler maps are generated from WebIDL rather than typed by hand, so they stay
  exactly as long as the standard says.
- **No lying features.** An interface is exposed only when the feature behind it
  exists. A page that feature-detects a canvas or a worker must not be told yes
  by a stub.
- **The runner is the referee.** Anything that cannot be exercised by the test
  runner is treated as unproven.

## Memory model

The engine runs on Nimony without a garbage collector, so memory discipline is
part of the design: environments captured by a call are released when the call
returns, and the test runner runs every test in its own process under a hard
memory cap. See [Web Platform Tests](/docs/titicaca/wpt) for the containment.
