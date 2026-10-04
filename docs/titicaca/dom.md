---
title: Titicaca's DOM
description: How Titicaca implements nodes, events, live collections, attribute reflection and frames.
---

# The DOM

`jsdom` is the layer between the HTML tree and the JavaScript engine. It binds
the same way regardless of which engine is underneath — the original
tree-walking `jsinterp`, or the newer `aowljs-engine`-backed `EngineAowlJs`,
now the default (see [The JavaScript engine](/docs/titicaca/javascript)). For
`EngineAowlJs`, a sidecar module (`aowlheap.nim`) adapts that engine's
embedding API to the host-indexer and reflected-attribute conventions
described below, so this page describes the DOM contract both engines share,
not a per-engine feature.

## Nodes and trees

The full node hierarchy is implemented: documents, elements, text, comments,
document fragments, doctypes and processing instructions, with the standard
mutation methods, `Range`-free tree operations, `cloneNode`, `importNode`,
`adoptNode` and `normalize`. Cloning wires inline event handlers on the copy.

## Events

Dispatch follows the standard: capture, target and bubble phases, `stopPropagation`
and `stopImmediatePropagation`, `once`, `passive` (defaulting to passive for the
listener types the spec names), `AbortSignal` removal and legacy `webkit` aliases.
Activation behaviour is implemented for the elements that have it (form submit and
reset, links, `summary`, `label`), acting on the nearest activatable ancestor
only.

## Live collections

`getElementsByTagName`, `childNodes`, `document.images`, `forms`, `links` and
friends return live collections. `DOMTokenList` supports indexed access through
the engine's indexer hook, and `length` is a prototype getter so own-key
enumeration is correct.

## Reflection

HTML attribute reflection (`el.href`, `el.tabIndex`, `el.hidden`, ...) is
generated from WebIDL into `webreflect`. One accessor pair, parameterised by
row, serves every reflected property, so adding an element is a table change.

## Frames

An `<iframe>` loads a real document. Frame documents get their own cascade, their
own realm and their own base URL, and fire their own `load` event, which the
parent's `load` waits for. XML frames parse as XML.

## Parsing and serialisation

`DOMParser`, `XMLSerializer`, `innerHTML`, `outerHTML` and `insertAdjacentHTML`
share the HTML and XML parsers. `<base href>` sets the document base URL, and the
document's `characterSet` reflects the decoded encoding.

## Shadow DOM and Custom Elements

Under `EngineAowlJs`, `attachShadow`, slots, `customElements.define` and the
custom-element lifecycle callbacks (`connectedCallback` and friends) are
implemented and exercised by the mod's test gates. This is new work this
session, ported alongside the rest of the DOM/CSS/Events core onto the
`aowljs-engine` binding; it is not yet re-verified against the WPT standing
tracked on the [Web Platform Tests](/docs/titicaca/wpt) page, which still
reflects the original engine.

## Not implemented on purpose

Interfaces for features that do not exist here are not exposed. A page that
feature-detects them gets the truth. Canvas exposes state tracking only — no
rasterizer, so nothing is actually painted. SVG exposes DOM geometry and
attributes only — no path-data (`d` attribute) parser. Workers and event
sources are not exposed yet. See [Limits and roadmap](/docs/titicaca/limits).
