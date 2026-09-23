---
title: Titicaca's DOM
description: How Titicaca implements nodes, events, live collections, attribute reflection and frames.
---

# The DOM

`jsdom` is the layer between the HTML tree and the JavaScript engine.

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

## Not implemented on purpose

Interfaces for features that do not exist here (canvas, workers, event sources)
are not exposed. A page that feature-detects them gets the truth. See
[Limits and roadmap](/docs/titicaca/limits).
