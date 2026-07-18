---
repo: aoughwl/html
---

# html — typed HTML5 for nimony

A registry of every HTML5 element and its attributes (with void / deprecated /
experimental markers), plus a document-tree builder and a correct, escaping,
void-aware renderer. Pure logic for nimony / Nim 3.0 — standard library only,
**no dependencies**. It sits under `web` alongside `css`: `html` answers "what is
valid HTML" and builds the tree, `css` validates styles, and `web` composes both.

> **Status** — Stable and self-contained. Covers the full HTML5 element/attribute
> table and a complete build-and-render pipeline out to a string. It is
> output-only: there is no HTML *parser* (no string &rarr; `HTMLNode`), and
> validity queries are advisory — the renderer never rejects an invalid tag or
> attribute.

## Quickstart

```nim
import html

# --- registry: ask the baked HTML5 table ---
echo isElement("section")           # true
echo isVoidElement("br")            # true
echo isDeprecated("marquee")        # true
echo isExperimental("fencedframe")  # true
echo isAttribute("a", "href")       # true
echo isAttribute("div", "data-x")   # true  (data-* / aria-* / on* are global)
echo isAttribute("div", "href")     # false (href is not valid on <div>)

# --- document tree: build and render ---
let page = el("section", @[attr("id", "main")], @[
  el("h1", @[text("Welcome")]),
  el("p",  @[text("hello & <world>")]),
  el("input", @[attr("type", "checkbox"), flag("checked")], @[]),
])

echo $page
# <section id="main"><h1>Welcome</h1><p>hello &amp; &lt;world&gt;</p><input type="checkbox" checked></section>
```

## API

The umbrella module `html` re-exports everything from `html/registry` and
`html/nodes`; `import html` is all a caller needs.

### Registry — element metadata

Backed by a baked HTML5 table (142 elements) parsed once at import time. All
lookups are case-insensitive.

| symbol | signature | what it does |
| --- | --- | --- |
| `isElement` | `proc isElement(name: string): bool` | Is `name` a known HTML5 element. |
| `isVoidElement` | `proc isVoidElement(name: string): bool` | Void element — no children, no closing tag (`br`, `img`, `hr`, …). |
| `isDeprecated` | `proc isDeprecated(name: string): bool` | Obsolete / deprecated element (`center`, `font`, `marquee`, …). |
| `isExperimental` | `proc isExperimental(name: string): bool` | Not yet baseline (`fencedframe`, …). |

### Registry — attribute metadata

| symbol | signature | what it does |
| --- | --- | --- |
| `isGlobalAttribute` | `proc isGlobalAttribute(attr: string): bool` | Attribute valid on any element — the 33 named globals (`id`, `class`, `style`, …) plus the open-ended `data-*`, `aria-*` and `on*` event-handler families. |
| `isAttribute` | `proc isAttribute(element, attr: string): bool` | Is `attr` valid on `element` — true for any global, or an attribute listed for that specific element. Unknown elements accept only globals. |
| `elementAttributes` | `proc elementAttributes(element: string): seq[string]` | The element-specific attributes declared for `element` (excludes globals). |

The parsed tables are also exported for direct inspection:

| symbol | signature | what it does |
| --- | --- | --- |
| `elements` | `let elements: Table[string, string]` | tag &rarr; flag string (`v` void / `d` deprecated / `x` experimental, combined). |
| `globalAttrs` | `let globalAttrs: Table[string, string]` | global-attribute name &rarr; `""` (membership set). |
| `elementAttrs` | `let elementAttrs: Table[string, string]` | tag &rarr; comma-separated element-specific attribute list. |

### Document tree — types

| symbol | signature | what it does |
| --- | --- | --- |
| `HTMLNodeKind` | `enum hnElement, hnText, hnComment, hnRaw` | The four node kinds. |
| `Attr` | `object name, value: string; boolean: bool` | An attribute; `boolean` marks a bare flag attribute (`disabled`). |
| `HTMLNode` | `ref object` (variant over `HTMLNodeKind`) | Element (`tag`, `attrs`, `children`) or a text / comment / raw node (`text`). |
| `HTML` | `seq[HTMLNode]` | A document or fragment — a sequence of nodes. |

### Document tree — builders

| symbol | signature | what it does |
| --- | --- | --- |
| `el` | `proc el(tag: string, attrs: seq[Attr], children: seq[HTMLNode]): HTMLNode` | Element with attributes and children. |
| `el` | `proc el(tag: string, children: seq[HTMLNode]): HTMLNode` | Element with children, no attributes. |
| `el` | `proc el(tag: string): HTMLNode` | Empty element. |
| `text` | `proc text(s: string): HTMLNode` | An escaped text run. |
| `comment` | `proc comment(s: string): HTMLNode` | A comment node (`<!-- … -->`). |
| `rawNode` | `proc rawNode(s: string): HTMLNode` | Verbatim markup, emitted unescaped. |
| `attr` | `proc attr(name, value: string): Attr` | A `name="value"` attribute. |
| `flag` | `proc flag(name: string): Attr` | A boolean attribute, rendered bare when present. |

### Document tree — mutation

| symbol | signature | what it does |
| --- | --- | --- |
| `add` | `proc add(parent: HTMLNode, child: HTMLNode)` | Append a child to an element node (no-op on non-elements). |
| `setAttr` | `proc setAttr(node: HTMLNode, name, value: string)` | Set / replace an attribute on an element node (no-op on non-elements). |

### Rendering & escaping

| symbol | signature | what it does |
| --- | --- | --- |
| `render` | `proc render(n: HTMLNode): string` | Render a node to an HTML string. |
| `render` | `proc render(nodes: seq[HTMLNode]): string` | Render a fragment (sequence of nodes). |
| `$` | ``proc `$`(n: HTMLNode): string`` | Alias for `render(n)`. |
| `treeRepr` | `proc treeRepr(n: HTMLNode): string` | An indented structural view of the tree, for debugging. |
| `escapeText` | `proc escapeText(s: string): string` | Escape text content — `&`, `<`, `>`. |
| `escapeAttr` | `proc escapeAttr(s: string): string` | Escape an attribute value — `&`, `<`, `>`, `"`. |

## Design notes

- **Baked table, no JSON.** The HTML5 data lives in `html/data.nim` as three
  tab/newline blobs — `elementBlob` (tag &rarr; `v`/`d`/`x` flags),
  `globalAttrBlob` (global-attribute membership set) and `elementAttrBlob`
  (tag &rarr; attribute list). `html/registry` walks them one character at a time
  and builds the lookup tables once at import time — no `std/json`, no raising
  string ops. The blobs are hand-maintained; there is no code generator.
- **Advisory, not enforcing.** `isElement` / `isAttribute` are for callers (a DSL,
  a linter, `web`) to consult. The renderer itself never validates — it will
  happily emit an unknown tag or a bogus attribute. The one place registry data
  reaches the renderer is `isVoidElement`, which suppresses children and the
  closing tag.
- **Correct escaping by context.** Text nodes escape `& < >`; attribute values
  additionally escape `"`. `rawNode` is the deliberate escape hatch for
  pre-rendered markup, and boolean attributes (`flag`) render bare.
- **Output-only.** The library builds and renders HTML; it does not parse HTML in.
  There is no `HTMLNode`-from-string path.

## Requirements

- nimony / Nim 3.0 toolchain. Standard library only (`std/tables`); no third-party
  dependencies, no C FFI, no build step — put the repo on the import path and
  `import html`.
- Pairs with `css` (MDN-typed CSS validation); together they back the `web` DSL.
