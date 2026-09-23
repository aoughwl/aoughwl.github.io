---
title: Titicaca limits and roadmap
description: What Titicaca cannot do yet, and which changes would move the score most.
---

# Limits and roadmap

## What it cannot do

- Generators and suspending `await` (the interpreter is a tree walker).
- Canvas, workers, event sources, WebSocket, WebRTC, service workers.
- Full `Request` / `Response` and the streams built on them.
- Complete Selectors coverage: `:focus-visible`, `dir=auto` and named-item access.
- UTF-16 offsets in `CharacterData` methods for non-BMP text.
- Speed comparable to a JIT browser.

## Levers, biggest first

1. **A bytecode VM for the script engine**: it would add generators and
   suspending `await`, and is faster than walking the tree.
2. **Binding shape.** A large share of remaining failures are interface-conformance
   tests for objects that exist but lack members, or exist without an exposed
   interface (`Navigator`, `History`, `Storage`, `Location`).
3. **Request and Response**, currently the weakest part of URL-adjacent tests.
4. **Cross-realm constructors**, for example `DOMParser` reached through a frame.
5. **Selectors long tail**, as above.

## What we will not do

We will not stub interfaces for features that do not exist just to raise a
number. Feature detection on real pages would then lie.

## Where the numbers come from

Every claim on this page is checked against the
[Web Platform Tests](/docs/titicaca/wpt). Gaps are ranked by comparing our
per-file pass counts with a reference browser's, not by guessing.
