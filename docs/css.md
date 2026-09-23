---
repo: aoughwl/css
---

# css — a CSS engine for nimony / Nim 3.0

> ▶️ **[Try `aoughwl/css` live in the Playground](https://aoughwl.github.io/playground/#clone=aoughwl/css)** — clones the repo into the in-browser IDE, no install.

`css` reads CSS the way a browser does and tells you what it means. It parses a stylesheet, validates every value against its MDN grammar, every selector against Selectors-4 and every at-rule prelude against its own grammar, then runs the cascade over an element tree and gives you computed values: inheritance, `var()`, layers, `@media`, nesting, logical properties, colours and absolute lengths included. Pure logic, standard library only, no dependencies: `import css` compiles and runs on plain nimony / Nim 3.0. Successor to the Nim-2 `thing-king/css`.

**Status.** Everything below is implemented and tested (19 test programs). Bootstrap 5.3.3 lints clean (5 542 declarations, 2 556 selectors, every at-rule); a 129-file corpus of real-world CSS produces only true positives; minified Bootstrap computes byte-identical styles to the original across 16 193 computed values. Not modelled: layout (so `@container` queries evaluate false and percentages of a containing block stay percentages), animations/transitions, shadow trees.

## Quickstart

```nim
import css

# --- values, selectors, at-rules --------------------------------------------
validateValue("width", "clamp(1rem, 2vw, 3rem)").valid     # true
validateValue("width", "clamp(1rem, 2vw)").error           # "clamp() expects 3 arguments, got 2"
validateValue("padding", "-5px").valid                     # false: <length [0,∞]>
validateValue("width", "rgb(0 0 0)").valid                 # false: a colour is not a length
validateSelector("li:nth-child(2n+1 of .item):not(:has(> a))").valid   # true
validateMediaQueryList("(400px <= width < 700px), print").valid        # true
validateMediaQueryList("(min-widht: 600px)").error         # "unknown media feature 'min-widht'"
validateDescriptor("@font-face", "unicode-range", "U+0-7F, U+4??").valid  # true

# --- a whole stylesheet, in context, with line numbers -----------------------
let site = """h1 { color: red; }
@layer theme { .card .title { color: #336699 } }
.card { font-size: 1.25em; }
.card .title { font-size: 2em; }
p { colr: red }
"""
for d in lintStylesheet(site): echo $d
# 5: error: colr is not a known CSS property   [colr: red]

# --- the cascade over a document ----------------------------------------------
let doc = elem("html",
  elem("body.dark",
    elem("div#app.card[style=\"padding: 2px\"]",
      elem("h1.title"), elem("p.lead"))))
let eng = newStyleEngine()                 # a 1280×720 screen, light scheme
eng.addUserAgentDefaults()
eng.addStylesheet(site, oAuthor, "site.css")
let h1 = querySelector(doc, "h1")
let cs = eng.computedStyle(h1)
cs.get("color")          # "rgb(255, 0, 0)" — unlayered beats a layer, whatever the specificity
cs.get("font-size")      # "40px"   (2em of the card's 1.25em of 16px)
cs.get("margin-top")     # "26.8px" (the UA's 0.67em of 40px)
echo eng.why(h1, "color")
# color: red  from h1 (site.css:1)  [author, specificity (0,0,1)]
#   beats #336699  from .card .title (site.css:2) @layer theme  [author, specificity (0,2,0)]

# --- and back out -------------------------------------------------------------
minifyStylesheet("a { color: #ff0000; margin: 0px auto; }")   # "a{color:red;margin:0 auto}"
normalizeColor("hsl(210 50% 40%)")                             # "rgb(51, 102, 153)"
```

Every output above is checked: the block is `tests/tquickstart.nim`.

`import css` re-exports every module below. The command-line probe `css/tools/probe.sh` answers one question from the shell: `probe.sh color "10px"`, `probe.sh -s "a:hover > b"`, `probe.sh -f site.css`, `probe.sh -m "a { color: #ff0000 }"`.

## Validation

### Values — `css/validator`

The MDN value-definition grammars are compiled once into a node arena and matched with a memoised single-pass matcher (no exponential backtracking); a failure reports the farthest token reached and what was expected there.

| symbol | what it does |
| --- | --- |
| `validateValue(prop, value): tuple[valid: bool, error: string]` | Match `value` against the property's grammar. Accepts the CSS-wide keywords, `!important`, custom properties (any tokens), vendor-prefixed properties and keywords, `var()`/`env()` (a top-level substitution makes the value unknowable, so it is accepted). Property names are case-insensitive. |
| `valueMatches(prop, value): bool` | The same without error bookkeeping. |
| `validateAgainst(syntax, value)` / `matchesSyntax(syntax, value)` | Match against any value-definition syntax: `validateAgainst("<length> \| auto", "10px")`. CSS-wide keywords are not implicitly allowed. |
| `validateDescriptor(atRule, name, value)` | An at-rule descriptor (`@font-face src`, `@counter-style system`, `@property syntax`, `@page size`, …) against its MDN descriptor grammar; `!important` is an error there. |
| `setLevel(lvValues \| lvFull)` / `level()` | `lvValues`: whole-value grammar only. `lvFull` (default): also recursive math-function checking and function-argument grammars. |

What the matcher checks beyond "the tokens fit the grammar":

- **Typed function slots.** A numeric slot takes only the math and substitution functions; a `<rgb()>` slot takes only the functions its syntax defines; an inline `name( arg )` has its arguments matched on the spot (`fit-content(red)` fails).
- **Numeric ranges** from the grammar: `<length [0,∞]>` rejects `padding: -5px` (a `calc()` is left alone — CSS clamps it).
- **Literal tokens** (`'['`, `']'`, `'+'`), so `grid-template-columns: [full-start] 1fr` matches.
- **`<custom-ident>`** excludes the CSS-wide keywords and `default`; **unicode-range** tokens (`U+0-7F`, `U+4??`); **escapes** in identifiers.
- Math functions (`calc`, `min`, `max`, `clamp`, `round`, `mod`, trig, …) are validated by a recursive-descent checker over the calc grammar with exact arity messages (`css/math`).

**Data.** Everything is driven by the MDN tables in `css/data/*.json`, flattened by `css/tools/gen_data.nim` into std/json-free blobs in `css/data.nim`. `gen_data` also carries a small, asserted patch layer for spec facts MDN's data lacks (`attr()` in `<content-list>`, 32 current length units such as `lh`, `svh`, `dvh`, `cqw`); each patch fails the generator once MDN catches up. `css/data_load` exposes the tables: `isProperty`, `propertySyntax`, `isSyntax`, `syntaxOf`, `isType`, `isUnit`, `unitDimension`, `isAtRule`, `isPseudoClass`, `isPseudoElement`, `isFunctionalPseudoClass/Element`, `isDescriptor`, `descriptorSyntax`, `isInherited`, `rawInitialValue`, `isShorthand`, `longhandsOf`.

### Selectors — `css/selectors`

A real Selectors-4 parser producing an AST (`SelectorList` / `Complex` / `Compound` / `Simple`), shared by validation, specificity and matching so the three never disagree.

| symbol | what it does |
| --- | --- |
| `validateSelector(sel)` / `selectorValid(sel)` | Validate a selector list. |
| `validateNestedSelector(sel)` | For a nested rule (CSS Nesting): items may start with a combinator (`> .x`) and use `&`. |
| `parseSelector(sel, relative = false): tuple[ok, list, error]` | The AST. |
| `normalizeSelector(sel)` / `renderList(list)` | The canonical spelling (`[type=text]` → `[type="text"]`, `odd` → `2n+1`). |

Checked: all five combinators; namespaces (`ns|E`, `*|*`, `|E`, `[ns|a]`); CSS escapes (`.a\:b`, `#\31 0`); `&`; An+B for the `:nth-*` family including `of S`; `:not`/`:is`/`:where` (forgiving)/`:has` (relative; no nested `:has`, no pseudo-elements) as real selector lists; `::slotted()`/`:host()`/`:host-context()` compounds; `::part`, `::highlight`, `:state`, `:dir(ltr|rtl)`, `:lang()` ranges, `::view-transition-*`; pseudo names against MDN; bare vs functional (`:hover()` and a bare `:not` are errors); nothing but pseudos after a pseudo-element; `#1a` is not an id; `[data-x=1]` needs quotes. Browser-prefixed pseudos are accepted with any balanced argument.

### At-rules — `css/atrules`

| symbol | grammar |
| --- | --- |
| `validateMediaQueryList(s)` | Media Queries 4/5: types with `not`/`only`, `and`/`or`/`not` conditions, feature names, value types (length, ratio, resolution, integer, keywords), `min-`/`max-` only on range features, range syntax `(400px <= width < 700px)`. |
| `validateSupportsCondition(s)` | `not`/`and`/`or` over declarations, `selector()` (validated), `font-tech()`, `font-format()`. |
| `validateContainerCondition(s)` | `[<name>]? <query>`: size features, `style()` (values validated), `scroll-state()`. |
| `validateImportPrelude(s)` | `url \| string`, `layer` / `layer(name)`, `supports(…)`, media list. |
| `validateLayerName`, `validateKeyframesName`, `validateKeyframeSelector`, `validatePageSelectorList`, `validateNamespacePrelude`, `validateScopePrelude` | The rest. |
| `validateAtRulePrelude(keyword, prelude, hasBlock)` | Dispatch on the keyword; also knows which at-rules are statements and which need blocks, `@charset`'s exact form, reserved counter-style names, and unknown at-rules. |

### Whole stylesheets — `css/lint`, `css/parse`

`lintStylesheet(src): seq[Diagnostic]` (and `lintSheet(parsed)`) reports every problem in source order: `Diagnostic` has `line`, `severity` (`sevError` / `sevWarning`), `message` and `context`; `$d` prints `12: error: … [context]`. What a block may contain depends on where it is: properties in style rules (and CSS Nesting's nested rules and group rules), descriptors in `@font-face`/`@counter-style`/`@property`/`@font-palette-values`/`@view-transition`, keyframe blocks (never `!important`) in `@keyframes`, properties + page descriptors + margin rules in `@page`. It also checks `@font-face`'s required descriptors, `@property` (syntax/inherits required; `initial-value` must match the registered syntax and be computationally independent), `@counter-style` system requirements, `@charset`/`@import`/`@namespace` ordering and top-level-only at-rules, every prelude, and what the parser had to recover from.

`parseStylesheet(src): ParsedSheet` survives real CSS (comments, strings, `url(data:…)`, `[attr="{"]`, escapes, `!important`, custom properties whose values hold `{}` blocks, nested at-rules, CDO/CDC). A `ParsedRule` has `prelude`, `isAtRule`, `atKeyword`, `atPrelude`, `hasBlock`, `decls`, `children` and `line`; a `Declaration` has `prop`, `value`, `important`, `line`; `ParsedSheet.problems` lists unclosed blocks, stray `}`, declarations without `:` and unterminated comments. `parseDeclarations(src)` parses a `style` attribute.

## The engine

### Documents and matching — `css/dom`, `css/match`

`Element` is the smallest document the engine needs: `tag`, `attrs`, `children`, `parent`, `text`, and dynamic `states` (`setState(el, "hover")`). Build trees by hand or with `elem("li#x.item[data-k=\"v\"]", children…)`, whose spec is parsed by the selector parser. Helpers: `getAttr`, `hasAttr`, `setAttr`, `id`, `classes`, `hasClass`, `addClass`, `appendChild`, `index`, `siblings`, `root`, `descendants`, `withText`.

`matches(el, sel, parent = "")`, `matchesList(el, list)`, `querySelectorAll(root, sel)`, `querySelector`, `closest` run the AST right to left: every combinator but `||`; attribute operators with `i`/`s`; `:not`/`:is`/`:where`; `:has` with relative selectors; all structural pseudo-classes including `:nth-child(An+B of S)`; `:lang()`/`:dir()` from the ancestor chain; form state from attributes (`:checked`, `:disabled`, `:required`, `:read-only`, `:placeholder-shown`, `:link`, …); `:scope`; `:focus-within`; `&` against a parent rule; everything else as a state.

### Media and feature queries — `css/media`

`MediaEnv` describes the device (`mediaType`, `width`, `height`, `resolution`, `fontSize`, `colorScheme`, `reducedMotion`, `contrast`, `forcedColors`, `hover`, `pointer`, `colorGamut`, `displayMode`, `scripting`, …); `defaultEnv()` is a 1280×720 desktop. `evalMediaQueryList(s, env)` answers a query list (an ill-formed query is `not all` without poisoning the list; the Compat Standard's `-webkit-device-pixel-ratio` works). `evalSupports(s)` answers `@supports` from this library's own validator.

### Shorthands — `css/shorthand`

`expandShorthand(prop, value): tuple[ok, longhands]` sets every longhand a shorthand covers (omitted parts reset to initial): four-sided boxes, pairs (logical margins/paddings/insets, `gap`, `overflow`, `place-*`), any-order groups (border sides, `outline`, `text-decoration`, `list-style`, `columns`, …), `border` (12 longhands + `border-image` reset), `border-radius` with `/`, `flex`'s special forms, `font` (with the longhands it resets), grid lines with the omitted-line rules, `transition`/`animation` lists, multi-layer `background`, `container`. `shorthandLonghands(prop)`, `initialValue(prop)` (MDN's initial values, re-validated so its prose sentinels never leak out), `components(value)`.

### Cascade and computed values — `css/computed`

| symbol | what it does |
| --- | --- |
| `newStyleEngine(env = defaultEnv())` | An engine; `eng.env` may be changed at any time. |
| `addStylesheet(eng, src, origin = oAuthor, name = "")` / `addSheet` | Add a sheet in `oUserAgent`, `oUser` or `oAuthor` origin. |
| `addUserAgentDefaults(eng)` | HTML's user-agent sheet (display, margins, headings, lists, tables, `[dir]`). |
| `computedStyle(eng, el, pseudo = "")` | The element's computed style (or its `::before`/`::after`/… part). |
| `computeTree(eng, root)` | Every element's computed style, each computed once. |
| `get(cs, prop)` / `has(cs, prop)` | A computed value (logical properties answer through their physical counterpart; a shorthand answers when its longhands agree). |
| `why(eng, el, prop)` | Which declaration won, from which sheet and line, in which layer and origin, with what specificity, and what it beat. |
| `physicalOf(prop, writingMode, direction)` | The physical property a logical one maps to. |

What goes in: style rules with CSS Nesting resolved to `:is(parent)` (which is also nesting's specificity), `@media` (evaluated at compute time), `@supports`, `@layer` (named, nested, anonymous, ordering statements), `@scope` (roots, limits, `:scope`), `@property` registrations, the `style` attribute, and pseudo-element rules. The cascade is Cascade 5: origin and importance, element-attached, layers (reversed for `!important`), specificity, per-declaration order; logical and physical properties are one property for the cascade, mapped by the element's `writing-mode` and `direction`. Computing: custom properties first, `var()` with fallbacks and cycle detection; `inherit`/`initial`/`unset`/`revert`/`revert-layer`; a value invalid after substitution is `unset`; inheritance; lengths in em/rem/ex/ch/%(font-size)/pt/pc/in/cm/mm/Q/viewport units and the font-size keywords become px; times compute to seconds; numbers are canonical; colours serialise as `getComputedStyle` reports them (`rgb()`/`rgba()`, `currentcolor` resolved).

Rules are indexed by their rightmost compound, and media answers, substituted-value validation and shorthand expansions are memoised: all of Bootstrap over a 362-element document computes in about 180 ms (0.5 ms per element).

### `@import` — `css/imports`

`resolveImports(src, url, loader): ImportResult` inlines every `@import` through your `Loader` (`proc (url: string): tuple[ok: bool, css: string]`), wrapped as the import scoped it (`@media` › `@supports` › `@layer`), resolving relative URLs (`resolveUrl`), breaking and reporting cycles, dropping imported `@charset`, and reporting unloadable files and `@import`s placed after other rules. `parseImport(prelude)` takes one apart.

### Colours — `css/color`

`parseColor(s): tuple[ok, color]` reads the 148 named colours, system colours, hex, `rgb`/`rgba`/`hsl`/`hsla` (legacy and modern syntax, `none`, `/ alpha`), `hwb`, `lab`/`lch`/`oklab`/`oklch`, `color()` in every predefined space and `color-mix()` (rectangular and polar spaces), converting to sRGB. `serializeColor`, `normalizeColor`, `toHex`, `namedColors`, `relativeLuminance`, `contrastRatio` (WCAG), `mixColors`.

### Printing — `css/serialize`

`renderSheet(parsed)` pretty-prints. `minifyStylesheet(src)` removes comments (not `/*! licences */`), whitespace, final semicolons and empty rules, shortens numbers, colours and zero lengths only where the result still validates (never in `flex` or times), tightens selectors only when they re-parse to the same selector, and copies custom properties verbatim. Bootstrap 5.3.3 minifies to 83% and computes identically.

## Smaller pieces

- **Specificity — `css/cascade`.** `specificity(sel)` (from the AST: `:is`/`:not`/`:has` take their argument's, `:where` nothing, `:nth-child(… of S)` adds `S`, legacy `:before` is an element), `ofComplex`, `ofList`, comparison and `$`. `cascade(decls)` is the simple resolver for `(selector, property, value, important)` lists without a document.
- **`Style` values — `css/styleval`, `css/stylesheet`.** `declare`, `styleOf("a:b;c:d")`, `&` (right wins), `cssText`, `errors`; an authored `Stylesheet` of selector → `Style` with `rule`, `render`, `errors`, and a process-wide installed sheet.
- **The `style X:` DSL — `css/style` (needs [`plugin`](https://github.com/aoughwl/plugin)).** `style "name": prop: value` blocks lowered by a compiler plugin to validated, content-addressed classes: `styleOne`, `classOf`, `renderStylesheet`, `styleErrors`, `whyStyle`. The only part of the package with a dependency.
- **`css/aifsheet`.** Validate a sheet through the error-recovering `aowlparser` CSS dialect instead of `css/parse` (needs that repo).

## Design notes

- **Data-driven.** Grammars, units, pseudo names, descriptors, inheritance, initial values and shorthands all come from MDN's JSON. Track a spec change by dropping in new data and re-running `gen_data`.
- **Non-raising throughout.** nimony house style: no raising string slices, status via `tuple[valid, error]`.
- **One AST, three uses.** Validation, specificity and matching run on the same selector tree; the cascade's nesting and `@scope` handling are AST rewrites on it.
- **Checked against itself.** The minifier's test computes styles for the original and the minified sheet and demands identical results; `tbootstrap` fails on any false positive; the at-rule, lint, selector and matcher tests carry negative controls for every positive.

## Requirements

- **nimony toolchain / Nim 3.0.** `import css` needs only the standard library.
- **[`plugin`](https://github.com/aoughwl/plugin)** — only for the `css/style` DSL.
- **Generator only:** `css/tools/gen_data` runs under regular Nim to rebuild `css/data.nim`.
- **Tests:** `tests/run.sh [name…]` builds and runs each `tests/t*.nim`.
