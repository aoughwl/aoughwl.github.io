---
title: Titicaca's JavaScript engine
description: The two JavaScript engines inside Titicaca — aowljs-engine (default) and the original tree-walking jsinterp — their realms, and their current limits.
---

# The JavaScript engine

Titicaca can run page scripts on either of two engines, selected per mod build
by an existing toggle:

- **`EngineAowlJs`** (the default): a binding of
  [aowljs-engine](/aowljs-engine), a separate, from-scratch JS engine written
  in Nimony with its own lexer, parser, bytecode interpreter and (currently
  disabled, see below) JIT tier. It is a general-purpose engine that is not
  specific to Titicaca; on several test262-adjacent benchmarks it outruns V8.
- **`EngineAowl`**: the original engine described further down this page —
  `jslex`, `jsparse`, `jsvalue`, `jsregex` and `jsinterp` — kept in place and
  still selectable. Nothing was removed; a mod can switch back to it.
- **`EngineJint`**: an existing third option, unchanged by this work.

The DOM binding (`jsdom`) does not care which engine is underneath. For
`EngineAowlJs` the bridge is a sidecar module, `aowlheap.nim`, which adapts
aowljs-engine's embedding API (its own heap, object model and host-call
convention) to the conventions `jsdom.nim` already expects from the original
engine — host indexers, reflected-attribute accessors, generated event-handler
compilation. `jsdom.nim` itself did not need to change shape to support a
second engine; `aowlheap.nim` is the translation layer.

## What's real and working under EngineAowlJs

Ported and verified against the mod's build/test gates
(`build_mod.exe`, `jsdom_test.exe`, `smoke_test.exe`), not just compiled:

- CSS selector matching: combinators, attribute selectors, pseudo-classes,
  `:not()`.
- The CSS cascade: `getComputedStyle`, `element.style`, specificity,
  `!important`, inheritance.
- DOM core: `createElement`, attributes, `classList`, tree navigation,
  `innerHTML`.
- Events: capture phase, `stopImmediatePropagation`, `once`/`signal`/
  `AbortController`, `composedPath`.
- Shadow DOM and Custom Elements: `attachShadow`, slots, `customElements.define`,
  lifecycle callbacks.
- Real `Promise`/`async`/`await`, implemented in the engine core rather than
  faked on top of synchronous calls — this is the thing the tree-walking
  `jsinterp` engine cannot do (see Known gaps below).
- Fetch and Streams (see [Networking](/docs/titicaca/networking) for how
  `fetch()` actually reaches the network).
- History/Navigation: `pushState`, `popstate`.
- `NodeIterator`, `TreeWalker`, `Range`, `Selection`.
- Canvas 2D: state tracking (current transform, styles, path construction) —
  no rasterizer yet, so nothing is actually drawn to pixels.
- SVG DOM: geometry and attribute access — no path-data (`d` attribute)
  parser yet.
- `contentEditable` / `execCommand` for `bold`, `italic`, `insertText`.
- `SubtleCrypto`, `XPath`, `Sanitizer`, `TrustedTypes`.
- Around sixteen Tier-1 utility interfaces: `Headers`, `URL`, `FormData`,
  `Blob`, `console`, `crypto`, `performance`, timers, `Storage`, base64,
  clipboard, fullscreen, `FontFace`, origin isolation, `URLPattern`.

This is roughly the DOM-tree-free utilities plus the DOM/CSS/Events core plus
several large interfaces from `jsdom.nim`'s surface. It is **not** full parity
with the original engine's WPT standing yet — see
[Limits and roadmap](/docs/titicaca/limits) for what is still missing on this
path (full WASM, Worker threading, WebAudio, MediaSource/EME, full Canvas
rasterization, SVG path data, multi-node-selection editing, and some deep CSS
edge cases).

## The `window === globalThis` fix

Porting jsdom's conventions onto a different engine core surfaced a real
correctness bug rather than a porting inconvenience: `window` was not a true
alias of the realm's global object. A top-level `var x = 1` therefore never
appeared as `window.x`, because `var` declarations were landing on an internal
global record that `window` merely delegated reads to, not on the object
identity that `window` itself was. This is now fixed: `window` is the realm's
actual global object, and `window === globalThis` holds in both directions.
It was caught, not assumed, by loading a real page (see below) and watching
inline scripts fail to see their own top-level declarations.

## Real-world test: youtube.com

As a conformance check beyond unit tests, the actual youtube.com front page
was fetched live over a real HTTP connection (200 OK, roughly 889 KB), parsed
into a real DOM (471 nodes), and all 34 of its inline `<script>` blocks were
executed against `EngineAowlJs` with zero errors. This is not a claim that
Titicaca renders YouTube usably — layout, video, and most of the site's
dynamic behaviour are untouched by this test — only that the engine, DOM
binding, and fetch path can take a real, large, unmodified production page's
scripts and run them without throwing.

## The JIT bug

A genuine x86-64 JIT codegen bug exists in aowljs-engine: functions that cross
a specific cumulative call-count hotness threshold (64 calls) get
miscompiled by the baseline-to-optimizing tier transition, corrupting memory.
It is worked around for this embedding by disabling the JIT entirely —
`EngineAowlJs` currently runs interpreter-only inside Titicaca. The bug has
been reported upstream to the aowljs-engine maintainer; it is not specific to
the DOM binding or to Titicaca's usage pattern.

## The original engine (`EngineAowl`)

Five modules: `jslex` (tokens), `jsparse` (syntax tree), `jsvalue` (values and
objects), `jsregex` (regular expressions) and `jsinterp` (the evaluator).
`jsdom` binds the DOM in as host objects. It remains the measured baseline for
the [WPT standing](/docs/titicaca/wpt).

### Design

It is a tree-walking interpreter. That keeps it small and makes it easy to
inspect and patch, at the cost of speed and of a few language features that
need a suspendable stack (see below).

### Realms

Each frame gets its own realm. A script inside an iframe sees that frame's
`window`, `document` and globals, while the built-in intrinsics (`Object`,
`Array`, `Error`...) are shared with the main realm through the prototype chain.
Name lookup resolves against the realm's global at the root of the scope chain,
so an unbound identifier in a frame finds the frame's globals first. This one
change fixed a whole directory of attribute tests, because many of them run the
same checks in an iframe.

### Language features

Implemented: functions and closures, classes, `let`/`const`, destructuring,
spread, template literals, getters and setters, `Proxy`, `Reflect`,
`Object.defineProperties`, symbols, regular expressions and the usual built-ins.
Prototype rules follow the spec, including `__proto__` accessors and the
immutable-prototype behaviour of the global object.

### Host hooks

- `hostIndexer`: lets the DOM expose live indexed access (`list[i]`) on
  collections without copying them into arrays.
- Reflection: one generic accessor pair serves every reflected attribute rather
  than thousands of hand-written getters.
- Event handler attributes are compiled on first use and cloned with the node.

### Known gaps

- **`await` cannot suspend** and **generators are unimplemented**, because a
  tree-walking evaluator lives on the native stack. `EngineAowlJs` does not
  have this limitation — its `Promise`/`async`/`await` is real — which is one
  reason it is now the default.
- **No JIT.** Speed is that of an interpreter.
- **Out of memory is not recoverable.** The runtime's allocator can fail by
  emptying a sequence and carrying on, so a realm that runs out of memory can
  crash on its next index. The runner fences steps, depth and memory to keep
  this out of results.

## Process-level sandboxing

Separately from which engine runs the script, a sandboxed child-process
mechanism (Win32 named pipes plus Job Objects) now exists and can run real
JS/DOM execution with a real timer/event-loop pump. Three concurrent isolated
instances have been run simultaneously without interference. This is the
foundation for running Workers as separate processes rather than in-process
threads (see [Limits and roadmap](/docs/titicaca/limits)); Worker support
itself is not built yet.
