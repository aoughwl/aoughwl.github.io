---
repo: aoughwl/web
---

# web — HTML + validated CSS in one nimony block

`web` is a declarative DSL that builds a typed HTML tree and, inline, validates every
style declaration against the MDN value grammar, lowering each `style:` block to a single
scoped class. It sits at the top of the presentation stack: the `web:` block is a nimony
compiler plugin that lowers to builder calls over [`html`](https://github.com/aoughwl/html)
(the typed element tree) and [`css`](https://github.com/aoughwl/css) (MDN-grammar
validation). For nimony / Nim 3.0.

> **Status** — Works today for server-side / static output: HTML rendering plus a
> de-duplicated scoped stylesheet with full MDN validation of every declaration. The
> `component` form adds `for`/`if` control flow and runtime text children. No client-side
> reactivity, event binding, or component-parameter passing yet — those are out of scope
> for this release.

## Quickstart

```nim
import web

let page = web:
  box:                       # <div>  (`div` is a nimony keyword — `box` spells it)
    attr:
      id: "hero"
    style:
      color: red
      padding: 10.px 20.px
    h1 "Hello, nimony"
    p "HTML + validated CSS, one block."
    ul:
      li "one"
      li "two"

echo render(page)            # <div id="hero" class="c…"><h1>Hello, nimony</h1>…</div>
echo renderStylesheet()      # .c…{color:red;padding:10px 20px}
for e in styleErrors(): echo e   # declarations that failed MDN validation
```

## The DSL

Inside a `web:` block each line is one of five forms:

| form | example | lowers to |
| --- | --- | --- |
| `tag:` + indented block | `section:` … | an element with those children |
| `tag "text"` (command form) | `h1 "Hi"` | an element with one text child |
| bare string | `"raw text"` | a text node |
| `attr:` block of `name: value` | `attr:` / `id: "x"` | attributes on the enclosing element |
| `style:` block of `prop: value` | `style:` / `color: red` | inline styles → validated → **one scoped class** |

`style:` blocks are the point. Property idents are kebab-cased (`fontSize` → `font-size`);
values are rendered from the node tree — `10.px` → `10px`, `10.px 20.px` → `10px 20px`,
`rgb(1, 2, 3)` → `rgb(1,2,3)`, `pct`/`percent` → `%`. Each concatenated `"prop:value;…"`
block is validated against the MDN value-definition grammar (`clamp()`, `&lt;color&gt;`,
`&lt;length&gt;{1,4}`, function arities, …). Invalid declarations still render, but are
collected in `styleErrors()`. Identical style blocks are content-addressed (FNV-1a) and
share a single scoped class, so `renderStylesheet()` emits each unique rule once, in
first-seen order.

**Keyword tags.** `div` and `object` are reserved words in nimony, so the DSL spells them
`box` and `obj`. Every other element uses its real tag name.

## API

Everything from `html` is re-exported, so `render`, the `HTML`/`HTMLNode` types, and the
element constructors are available without a second import.

### The DSL macros

| symbol | signature | what it does |
| --- | --- | --- |
| `web` | `template web(body: untyped): HTML` | Compiler plugin (`deps/web_plugin`). Lowers the declarative HTML+CSS block into a chained `webFrag()`/`webAdd`/`webEl`/`webChild`/`webAttr`/`webStyle` expression, yielding an `HTML` value. Text children must be compile-time string literals. |
| `component` | `template component(name, body: untyped)` | Compiler plugin (`deps/component_plugin`). Like `web:`, but the block may contain `for`/`if` control flow and its text children may be runtime expressions (`p $i & ". item"`). Lowers to a `proc name(): HTML` that builds the tree over a mutable accumulator; call `name()` to get the `HTML`. Attributes and `style:` values stay compile-time. |

### Output

| symbol | signature | what it does |
| --- | --- | --- |
| `render` | `proc render(n: HTMLNode): string` / `proc render(nodes: seq[HTMLNode]): string` | The HTML string for a node or a whole fragment. Re-exported from `html`; `HTML` is `seq[HTMLNode]`, so `render(page)` renders the top-level `web:` result. |
| `renderStylesheet` | `proc renderStylesheet(): string` | Every unique scoped rule the `style:` blocks compiled to, one `.class{…}` per line, in first-seen order. |
| `styleErrors` | `proc styleErrors(): seq[string]` | The declarations that failed MDN validation, each formatted `"prop: value  — reason"`. Empty when every style validated. |

### Runtime builders (what the plugins chain)

These are the lowering targets the DSL emits; you rarely call them by hand, but they are
public and can be used to assemble a tree programmatically.

| symbol | signature | what it does |
| --- | --- | --- |
| `webEl` | `proc webEl(tag: string): HTMLNode` | A new empty element node for `tag`. |
| `webText` | `proc webText(s: string): HTMLNode` | A text node. |
| `webChild` | `proc webChild(n, c: HTMLNode): HTMLNode` | Appends child `c` to `n`, returns `n` (chainable). |
| `webAttr` | `proc webAttr(n: HTMLNode, name, value: string): HTMLNode` | Sets attribute `name=value` on `n`, returns `n`. |
| `webStyle` | `proc webStyle(n: HTMLNode, decls: string): HTMLNode` | Validates `"prop:value;…"`, lowers it to one content-addressed class, merges that class onto `n` (preserving any existing `class`), records new rules for `renderStylesheet()` and any failures for `styleErrors()`. |
| `webFrag` | `proc webFrag(): HTML` | An empty fragment (`@[]`) — the accumulator a `web:` block grows. |
| `webAdd` | `proc webAdd(f: HTML, n: HTMLNode): HTML` | Appends node `n` to fragment `f`, returns the grown fragment. |

### Re-exported from `html`

The `HTMLNode` object model and its constructors come through `export html`:

| symbol | signature | what it does |
| --- | --- | --- |
| `HTML` | `type HTML = seq[HTMLNode]` | A fragment: the top-level result of a `web:` block. |
| `HTMLNode` | `type HTMLNode = ref object` (variant over `HTMLNodeKind`) | An element (`hnElement`: `tag`, `attrs`, `children`) or a leaf (`hnText`/`hnComment`/`hnRaw`: `text`). |
| `el` | `proc el(tag: string, …): HTMLNode` | Element constructor (three overloads: tag only, tag+children, tag+attrs+children). |
| `text` / `comment` / `rawNode` | `proc(s: string): HTMLNode` | Text, `<!-- … -->`, and verbatim-unescaped nodes. |
| `add` / `setAttr` | `proc add(parent, child: HTMLNode)` / `proc setAttr(node: HTMLNode, name, value: string)` | Mutating tree/attribute helpers. |

## Design notes

- **Validation is compile-adjacent, not blocking.** A bad declaration never stops
  rendering — it is emitted as-is and surfaced through `styleErrors()`, mirroring the
  nimony house style of status-based reporting over exceptions.
- **Content-addressed classes.** The scoped class name is `"c"` + an 8-hex FNV-1a hash of
  the declaration string, so structurally identical `style:` blocks collapse to one rule
  and one class automatically.
- **Two plugins, one surface.** `web:` lowers to a pure nested-expression chain (fast,
  literal-only). `component` lowers each element to a block expression over a mutable
  accumulator inside a generated `proc`, which is what lets a `for` loop append N children
  and lets text children be runtime expressions — the accumulator lives in a non-global
  frame so a half-built tree is never snapshotted.
- **Global rule/error state.** `renderStylesheet()` and `styleErrors()` read process-global
  registries populated as `style:` blocks compile; they accumulate across every `web:`/
  `component` in the module.

## Requirements

- nimony / Nim 3.0 toolchain.
- [`html`](https://github.com/aoughwl/html) — the typed HTML5 element tree (re-exported).
- [`css`](https://github.com/aoughwl/css) — MDN-grammar CSS value validation (`validateValue`).
- [`plugin`](https://github.com/aoughwl/plugin) — the `web:`/`component` blocks are nimony
  compiler plugins authored with it.

All three are declared in `web.nimble`.
