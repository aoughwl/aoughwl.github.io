---
title: Titicaca CSS, selectors and layout
description: How Titicaca tokenises CSS, matches selectors, runs the cascade and lays out boxes.
---

# CSS, selectors and layout

## CSS Syntax

`webcsssyntax` implements the CSS Syntax tokenizer and parsing algorithms:
declaration lists, `!important`, `var()` substitution with the spec's comment
serialisation, and `<urange>`. Style sheets are cut into rules by the syntax
rules themselves (respecting strings, comments and nested blocks), and comments
are kept in selector text as the standard requires. The results surface in
`style` objects, `rule.style` and `@font-face`.

## Selectors

`webselector` is a Selectors Level 4 parser, matcher and serialiser. It backs
`querySelector`, `querySelectorAll`, `matches`, `closest`, CSSOM `selectorText`
and the cascade itself, so there is one implementation of what a selector means.
It covers combinators, attribute selectors with case flags, namespaces, the
structural and logical pseudo-classes and `:has`.

## The cascade

`webcss` collects rules from author and user-agent sheets, orders them by origin,
importance, specificity and source order, and computes values. Supported
extras include `@namespace` (namespace columns are carried through matching),
CSS nesting, custom properties and the full set of 148 named colours.
`getComputedStyle` runs the cascade itself rather than reading a cache, so it is
always current.

## Layout

Boxes come from `weblayout`, with specialised modules for text (`webtext`),
floats (`webfloat`), tables (`webtable`), grid (`webgrid`), transforms
(`webmatrix`), images (`webimg`) and SVG (`websvg`). `webinnertext` implements
the `innerText` algorithm, which depends on layout-visible whitespace rules.

## Drawing

Boxes are drawn through Jester's UI library, so they inherit its fonts, its
clipping and its input model.

## Where the score is lowest

Selectors is the weakest of the tracked areas: the long tail is `:focus-visible`,
`dir=auto` and named-item access. See [Web Platform Tests](/docs/titicaca/wpt).
