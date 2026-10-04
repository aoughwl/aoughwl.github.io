---
title: Titicaca limits and roadmap
description: What Titicaca cannot do yet, and which changes would move the score most.
---

# Limits and roadmap

## What it cannot do

- Generators and suspending `await` under the original engine, `EngineAowl`
  (the interpreter is a tree walker). The newer default engine,
  `EngineAowlJs`, does not share this limit — its `Promise`/`async`/`await` is
  real — but has not yet been measured against the WPT standing tracked on
  the [Web Platform Tests](/docs/titicaca/wpt) page, which still reflects
  `EngineAowl`.
- WASM support (not ported).
- Worker threading. The architecture is decided — process-per-Worker, using
  the sandboxed-child-process mechanism now proven for isolated JS/DOM
  execution — but the Worker interface itself is not built yet.
- WebAudio.
- Full Canvas rasterization: `EngineAowlJs` tracks canvas state (transform,
  styles, path construction) but does not paint pixels.
- SVG path-data parsing: SVG DOM geometry and attributes are bound, but the
  `d` attribute's path-data grammar is not parsed.
- MediaSource/EME DRM. This is a permanent, deliberate exclusion, not a
  todo — see below.
- Multi-node-selection editing (`contentEditable`/`execCommand` cover
  single-range `bold`/`italic`/`insertText`, not arbitrary multi-node
  selections).
- Some deep CSS edge cases remain on the original engine's known list:
  `:focus-visible`, `dir=auto`, named-item access.
- UTF-16 offsets in `CharacterData` methods for non-BMP text.
- A native HTTP/TLS stack: `fetch()` under `EngineAowlJs` does real network
  I/O, but by shelling out to `curl.exe`, not a client built into the mod.
- Speed comparable to a JIT browser: `EngineAowlJs` has a JIT tier, but it is
  currently disabled for this embedding after a real x86-64 codegen bug was
  found (functions crossing a 64-call hotness threshold were miscompiled,
  corrupting memory). Reported upstream; `EngineAowlJs` runs
  interpreter-only until it's fixed.

## DRM: a permanent exclusion, not a gap

Titicaca will not integrate Google's proprietary Widevine CDM, in any
form — not extracted from Chrome, not via the openwv shim, not via a
clean-room reimplementation — for licensing and DMCA reasons. This means
DRM-protected video will not play, including actual YouTube video playback,
even on pages (like youtube.com itself) that otherwise load and run their
scripts correctly under `EngineAowlJs`. Clearkey-only EME, i.e. non-DRM test
content, already works through the existing MSE/FFmpeg pipeline and is
unaffected by this exclusion.

## Levers, biggest first

1. **Re-run the WPT standing against `EngineAowlJs`.** The tracked score on
   the [Web Platform Tests](/docs/titicaca/wpt) page still reflects the
   original engine; the new default engine has real `async`/`await` and a
   substantial DOM/CSS/Events/Shadow-DOM surface but has not been scored the
   same way yet.
2. **Fix the JIT codegen bug** so `EngineAowlJs` can run with its optimizing
   tier enabled instead of interpreter-only.
3. **Binding shape.** A large share of remaining failures are
   interface-conformance tests for objects that exist but lack members, or
   exist without an exposed interface (`Navigator`, `History`, `Storage`,
   `Location`).
4. **Request and Response**, currently the weakest part of URL-adjacent
   tests, and a real HTTP/TLS client to replace the `curl.exe` shell-out.
5. **Worker threading**, building the Worker interface on the
   already-proven sandboxed-process mechanism.
6. **Cross-realm constructors**, for example `DOMParser` reached through a
   frame.
7. **Selectors long tail**, as above.

## What we will not do

We will not stub interfaces for features that do not exist just to raise a
number. Feature detection on real pages would then lie.

## Where the numbers come from

Every claim on this page is checked against the
[Web Platform Tests](/docs/titicaca/wpt). Gaps are ranked by comparing our
per-file pass counts with a reference browser's, not by guessing.
