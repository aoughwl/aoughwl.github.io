---
repo: aoughwl/web
---

# web — HTML + validated CSS in one nimony block

> ▶️ **[Try `aoughwl/web` live in the Playground](https://aoughwl.github.io/playground/#clone=aoughwl/web)** — clones the repo into the in-browser IDE, no install.

`web` is a declarative DSL that builds a typed HTML tree and, inline, validates every
style declaration against the MDN value grammar, lowering each `style:` block to a single
scoped class. It sits at the top of the presentation stack: the `web:` block is a nimony
compiler plugin that lowers to builder calls over [`html`](https://github.com/aoughwl/html)
(the typed element tree) and [`css`](https://github.com/aoughwl/css) (MDN-grammar
validation). For nimony / Nim 3.0.

> **Status** — Works today for server-side / static output: HTML rendering plus a
> de-duplicated scoped stylesheet with full MDN validation of every declaration.
> `component` takes typed parameters, composes with other components, and styles by
> `Style` VALUE; `for`/`if` control flow and runtime children work in both `web:` and
> `component` blocks. No client-side reactivity or event binding yet — those are out of
> scope for this release.

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

## Components

`component` gives a tree parameters. It lowers to an ordinary `proc … : HTML`, so a
component is called, composed and type-checked like any other procedure — there is no
component runtime, registry, or lifecycle.

```nim
proc defaultTheme(): Style =
  declare("color", "black") & declare("padding", "10px")

component card(title: string):
  input children: HTML                 # a parameter
  input footer: string = "(no footer)" # …with a default
  let theme = defaultTheme()           # ordinary locals — any nimony statement
  let highlight = true

  box:                                 # no marker: the tree is the tail of the body,
    @id "card"                         # starting at the first tree-shaped statement
    h1 title
    children                           # spliced — `children` is HTML, not text
    if highlight:                      # control flow works INSIDE an element, for
      @style theme:                    # directives as well as for children
        color: red                     # overrides the theme, keeps its padding
    for i in 1 ..< 3:
      p $i & ". item"
    small footer

let kids = web:
  p "a spliced child"

let page = card(title = "Hello", children = kids)
echo render(page)
# <div id="card" class="c9fb024aa"><h1>Hello</h1><p>a spliced child</p>
#  <p>1. item</p><p>2. item</p><small>(no footer)</small></div>
echo renderStylesheet()
# .c9fb024aa{color:red;padding:10px}      <- theme's black overridden, padding kept
```

### Forms

| form | meaning |
| --- | --- |
| `input x: T` / `input x: T = d` | a parameter; a default requires this form |
| `component card(x: T):` | parameters in the header — **no defaults** (see below) |
| `@name value` | an attribute; the ident is kebab-cased (`@dataId` → `data-id`) |
| `@name` | a boolean attribute (`@disabled`), rendered bare |
| `@style s` / `@style s:` + block | attach a `Style` value, optionally overridden |
| `@style:` + block | an anonymous inline style |
| `tag "text"` / `tag:` + block | an element |
| anything else | a value — appended according to its **type** |

### Styling is by value

A [`Style`](https://github.com/aoughwl/css) is an ordered set of validated declarations,
merged right-wins by `&`. So `theme & declare("color", "red")` is the theme with one
property replaced and every other property intact, and `@style theme:` with an override
block is exactly that merge. A theme is therefore ordinary data — `defaultTheme()` is just
a proc returning a `Style`, and it can be built, passed as an `input`, and overridden per
element. Literal and computed styles alike are MDN-validated and lowered to one
content-addressed class, so equal styles share a class however they were built.

### Children are typed, not syntactic

Every child is emitted verbatim into `webAppend`, which is overloaded on `string`,
`HTMLNode` and `HTML`. What a child *means* is therefore decided by its type: `h1 title`
renders text and `children` splices a tree, with no syntax distinguishing the two and no
type inspection in the plugin.

### Elements versus components

**A call is an element iff its name is a real HTML tag**, asked of `html`'s element
registry rather than a tag list copied into the DSL. Everything else is a call to a
component, so the two compose with one syntax.

A **bare identifier is never an element**. `title`, `label`, `footer`, `data`, `form`,
`summary`, `time` and `code` are all real tags *and* among the most ordinary parameter
names there are; reading a bare `title` as `<title>` would silently swallow the input of
any component that named one that way. A component whose tree begins with a spliced value
rather than an element marks it with an explicit `web:` block.

### Two constraints worth knowing

A header parameter list **cannot carry a default**: `component card(title: string = "x")`
is parsed as a *call*, and a call argument may not be `name: T = default`. That is a parser
rule, not a style preference, and it is why defaulted inputs live on `input` lines.

A component that accepts children names that input `children`, because a block of children
passed at a call site lowers to a named argument `children = …` (Nim forbids a positional
argument after a named one, so a trailing positional slot would not compose).

There is no `@style when cond:` form — `if cond: @style x` already expresses it, since
control flow inside an element lowers into the same accumulator.

## The DSL

`web:` is the same DSL without the proc wrapper — reach for it when you just want an
`HTML` value in an ordinary variable. Both surfaces are lowered by one engine
(`web/deps/weblower`), so they cannot drift apart.

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
| `web` | `template web(body: untyped): HTML` | Compiler plugin (`deps/web_plugin`). Lowers the declarative HTML+CSS block to an `HTML` value. May contain `for`/`if`/`while` control flow, `@` directives, `Style` values and arbitrary runtime children. |
| `component` | `template component(name, body: untyped)` | Compiler plugin (`deps/component_plugin`). The same DSL wrapped in a generated `proc name(<inputs>): HTML`, so a component takes typed parameters and composes with other components. `input` lines and a header parameter list both become proc parameters. |
| `dumpWeb` | `template dumpWeb(name, body: untyped)` | Debug aid (`deps/dump_plugin`): lowers a block to `echo "<its parse tree>"`, so a DSL shape can be discovered from the parser instead of guessed. |

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
| `webAppend` | `proc webAppend(n: HTMLNode, x: string \| HTMLNode \| HTML): HTMLNode` | Appends a child chosen by **type**: a `string` becomes a text node, an `HTMLNode` is spliced as-is, an `HTML` fragment splices all of its nodes. The lowering target for every child. |
| `webAttr` | `proc webAttr(n: HTMLNode, name, value: string): HTMLNode` | Sets attribute `name=value` on `n`, returns `n`. |
| `webFlag` | `proc webFlag(n: HTMLNode, name: string): HTMLNode` | Sets a boolean attribute (rendered bare, no `="…"`) — what `@disabled` lowers to. |
| `webStyleVal` | `proc webStyleVal(n: HTMLNode, s: Style): HTMLNode` | Attaches a `Style` VALUE — what `@style` lowers to. Routed through `webStyle`, so a computed style gets the same validation, class and dedup as a literal block. |
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
- **Two plugins, ONE engine.** `web:` and `component:` both call `deps/weblower`; the only
  difference is the wrapper (an expression versus a generated `proc`). They are the same
  language by construction rather than by discipline, so a feature added to one cannot go
  missing from the other.
- **The lowering is accumulator-shaped.** Every element becomes a block expression over a
  mutable local (`var e = webEl("div"); e = webAppend(e, …); e`). That is what lets `for`
  and `if` work *inside* an element — for `@` directives as much as for children, since a
  branch is not a special case but the same append statements under the original
  condition. A chained-expression lowering (`webChild(webChild(…))`) can express neither.
  The accumulator lives in a non-global frame, so a half-built tree is never snapshotted.
- **Meaning comes from types, not syntax.** Children are emitted verbatim into the
  overloaded `webAppend`, so the plugin never decides whether a value is text or a tree —
  the type checker does, at the call site, with real diagnostics.
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
