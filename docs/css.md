---
repo: aoughwl/css
---

# css — an MDN-typed CSS engine for nimony / Nim 3.0

`css` parses a whole stylesheet and then *validates* it: every property value against its official MDN value-definition syntax, every math and functional value against its own signature, and every selector against Selectors-4 (with specificity and a source-order cascade resolver on top). It is pure logic — standard library only, **no dependencies, no aoughwl substrate** — so `import css` compiles and runs on plain nimony / Nim 3.0. It is the successor to the Nim-2 `thing-king/css`.

> **Status** — Value, function-argument, selector, cascade and full-stylesheet parsing are complete and MDN-driven (Bootstrap 5.3.3: 5 542 declarations, zero false positives). Gaps: at-rule *bodies* are parsed but their preludes (`@media`/`@supports`/`@keyframes`) are not yet grammar-checked, selector functional arguments (`:nth-child(An+B)`) are only balance-checked, and computed-style inheritance / `@import` resolution are not done.

## Quickstart

```nim
import css

# --- single-value validation, with a readable error -----------------------
validateValue("margin", "0 auto").valid                 # true
validateValue("width",  "clamp(1rem, 2vw, 3rem)").valid # true
validateValue("color",  "rgb(255 0 0 / 50%)").valid     # true
validateValue("width",  "clamp(1rem, 2vw)").error       # "clamp() expects 3 arguments, got 2"
validateValue("color",  "10px").error                   # "at token 1: expected <color>, got '10px'"

# --- selectors, specificity, cascade --------------------------------------
validateSelector("ul > li:nth-child(2n+1)").valid       # true
echo $specificity("a.btn#go")                           # (1,1,1)

# --- parse and validate a whole stylesheet --------------------------------
let sheet = parseStylesheet(readFile("bootstrap.css"))
for rule in sheet.rules:
  for d in rule.decls:
    let r = validateValue(d.prop, d.value)
    if not r.valid:
      echo rule.prelude, " { ", d.prop, ": ", d.value, " }  -- ", r.error

# --- tune the tier: values-only (fast) vs. full (default) -----------------
setLevel(lvValues)   # whole-value grammar match only
setLevel(lvFull)     # + recursive math + strict function-argument grammars
```

## API

`import css` re-exports the four pure modules below (`validator`, `selectors`, `cascade`, `data_load`). The value-definition-syntax parser (`vds`), math validator (`math`), value lexer (`value_lex`), stylesheet parser (`parse`) and the `style X:` DSL (`style`) are imported directly from their submodules.

### Value validation — `css/validator`

| symbol | signature | what it does |
| --- | --- | --- |
| `validateValue` | `proc validateValue(prop, value: string): tuple[valid: bool, error: string]` | Validate `value` against property `prop`'s MDN grammar; returns a readable error on failure. Accepts global keywords (`inherit`/`initial`/`unset`/`revert`), vendor-prefixed properties (uncheckable → accepted), and the `color-adjust` alias. |
| `valueMatches` | `proc valueMatches(prop, value: string): bool` | Boolean form of the above — the whole-value grammar match, no error bookkeeping. |
| `setLevel` | `proc setLevel(l: Level)` | Choose the validation tier (see `Level`). Global, defaults to `lvFull`. |
| `level` | `proc level(): Level` | The current tier. |
| `Level` | `enum lvValues, lvFull` | `lvValues` = whole-value grammar only (the tier peers stop at); `lvFull` = also recursive math + strict function-argument grammars. |

### Selector validation — `css/selectors`

| symbol | signature | what it does |
| --- | --- | --- |
| `validateSelector` | `proc validateSelector(sel: string): tuple[valid: bool, error: string]` | Validate a selector or comma-separated selector list against Selectors-4: type / universal / class / id / attribute / pseudo simple selectors joined by the descendant, child, next-/subsequent-sibling and column combinators. Pseudo names are checked against the MDN data. |
| `selectorValid` | `proc selectorValid(sel: string): bool` | Boolean form of `validateSelector`. |

### Specificity & cascade — `css/cascade`

| symbol | signature | what it does |
| --- | --- | --- |
| `Specificity` | `object` with `a, b, c: int` | The `(a,b,c)` triple — id count; class/attr/pseudo-class count; type/pseudo-element count. |
| `specificity` | `proc specificity(sel: string): Specificity` | Highest specificity across a comma-separated selector list. A functional pseudo's argument is skipped, not recursed into (`:not(.a.b)` counts as one). |
| `` `<` `` | `proc `<`(x, y: Specificity): bool` | Cascade ordering — compare `a`, then `b`, then `c`. |
| `` `==` `` | `proc `==`(x, y: Specificity): bool` | Component-wise equality. |
| `` `$` `` | `proc `$`(s: Specificity): string` | Render as `"(a,b,c)"`. |
| `Decl` | `object` with `selector, property, value: string` | One input declaration for the cascade. |
| `Winner` | `object` with `property, value: string; spec: Specificity; order: int` | The resolved winner for a property. |
| `cascade` | `proc cascade(decls: openArray[Decl]): seq[Winner]` | Resolve declarations to the winning value per property: higher specificity wins; on a tie, later source order wins. |

### Stylesheet parsing — `css/parse`

| symbol | signature | what it does |
| --- | --- | --- |
| `parseStylesheet` | `proc parseStylesheet(src: string): Stylesheet` | Parse a whole stylesheet into a tree of rules + declarations. Survives real CSS: comments, strings, `url(data:…;base64,…)`, `[attr="{"]`, `!important`, custom properties, and nested at-rules. Non-raising throughout. |
| `Stylesheet` | `object` with `rules: seq[Rule]` | The parsed sheet. |
| `Rule` | `object` with `prelude: string; isAtRule: bool; atKeyword: string; decls: seq[Declaration]; children: seq[Rule]` | A style rule or at-rule: `prelude` is the selector list or at-rule head, `atKeyword` is e.g. `"media"`/`"font-face"` (empty for a style rule), `children` are nested rules. |
| `Declaration` | `object` with `prop, value: string; important: bool` | One `prop: value` pair; `important` is set when `!important` was present. |

### Value-definition syntax — `css/vds`

The MDN grammar parser. Turns a value-definition string such as `` <length-percentage>{1,4} [ / <length-percentage>{1,4} ]? `` into a `VNode` tree that the matcher walks. Combinator precedence, loosest to tightest: `` | `` &lt; `` || `` &lt; `` && `` &lt; juxtaposition.

| symbol | signature | what it does |
| --- | --- | --- |
| `parseSyntax` | `proc parseSyntax(src: string): VNode` | Parse a value-definition-syntax string into a grammar AST. |
| `render` | `proc render(n: VNode): string` | Render a `VNode` grammar tree back to its value-definition-syntax string. |
| `VNode` | `ref object` (variant over `NodeKind`) | Grammar AST node: carries `mult`, `lo`/`hi`, and a kind-specific payload (`text`, `name`, `fname`+`arg`, or `comb`+`kids`). |
| `NodeKind` | `enum nkKeyword, nkLiteral, nkType, nkProp, nkFunc, nkList` | Node kinds — literal keyword, literal token (`/` `,`), `&lt;type&gt;`, `&lt;'prop'&gt;` reference, `name( arg )`, or a combinator list. |
| `Comb` | `enum cbSeq, cbOr, cbAny, cbAll` | The four combinators: juxtaposition, `` | ``, `` || ``, `` && ``. |
| `Mult` | `enum mkOne, mkOpt, mkStar, mkPlus, mkHash, mkRange, mkHashRange` | Postfix multipliers: none, `?`, `*`, `+`, `#`, `{m,n}`, `#{m,n}`. |
| `HugeN` | `const HugeN = 1000000` | Stand-in for ∞ in `{m,}` and unbounded ranges. |

### Math-function validation — `css/math`

Recursive-descent validator over the CSS Values-4 calc grammar, mirroring the self-nesting `` &lt;calc-sum&gt; `` → `` &lt;calc-product&gt; `` → `` &lt;calc-value&gt; `` structure exactly; it accepts every well-formed nesting and pinpoints the first malformed token.

| symbol | signature | what it does |
| --- | --- | --- |
| `isMathFunc` | `proc isMathFunc(name: string): bool` | Whether `name` is a known CSS math function (`calc`, `min`, `max`, `clamp`, `abs`, `sign`, `sqrt`, `exp`, `hypot`, `mod`, `rem`, `round`, `log`, `pow`, `atan2`, trig, …). |
| `validateMathFunc` | `proc validateMathFunc(name, args: string): tuple[valid: bool, error: string]` | Validate one math call's argument string against its exact arity and the recursive calc grammar (constants `e`/`pi`/`infinity`/`nan`, `round()` rounding strategy, nested math). |
| `validateFunctionsIn` | `proc validateFunctionsIn(value: string): tuple[valid: bool, error: string]` | Validate every function embedded anywhere in a value string. |

### Value lexer — `css/value_lex`

| symbol | signature | what it does |
| --- | --- | --- |
| `lexValue` | `proc lexValue(s: string): seq[VTok]` | Tokenize a concrete CSS value; nested functions collapse to one opaque `vtFunc` token whose raw argument string is kept in `args`. |
| `VTok` | `object` with `kind: VTokKind; text, num, args: string` | A value token. |
| `VTokKind` | `enum vtIdent, vtNumber, vtDimension, vtPercent, vtString, vtHash, vtFunc, vtComma, vtSlash, vtDelim` | Value token kinds. |

### MDN data tables — `css/data_load`

Lookup tables parsed once at import time from the baked blobs in `css/data.nim`. The exported `Table[string, string]` values `cssProperties`, `cssSyntaxes`, `cssTypes`, `cssUnits`, `cssAtRules`, `cssPseudoClasses`, `cssPseudoElements` are also available directly.

| symbol | signature | what it does |
| --- | --- | --- |
| `isProperty` | `proc isProperty(name: string): bool` | Is `name` a known CSS property? |
| `propertySyntax` | `proc propertySyntax(name: string): string` | The property's MDN value-definition syntax (`""` if unknown). |
| `isSyntax` | `proc isSyntax(name: string): bool` | Is `name` a named syntax (e.g. `length-percentage`)? |
| `syntaxOf` | `proc syntaxOf(name: string): string` | The named syntax's definition (`""` if unknown). |
| `isType` | `proc isType(name: string): bool` | Is `name` a basic data type (e.g. `color`, `length`)? |
| `isUnit` | `proc isUnit(name: string): bool` | Is `name` a known unit? |
| `unitDimension` | `proc unitDimension(name: string): string` | The unit's dimension bucket (`length`/`angle`/`time`/…). |
| `isAtRule` | `proc isAtRule(name: string): bool` | Is `name` a known at-rule (no `@`)? |
| `isPseudoClass` / `isPseudoElement` | `proc (name: string): bool` | Known pseudo-class / pseudo-element name (no `:`/`::`). |
| `isFunctionalPseudoClass` / `isFunctionalPseudoElement` | `proc (name: string): bool` | Whether that pseudo takes a `(…)` argument. |

### The `style X:` DSL — `css/style` (needs `plugin`)

A component-style DSL that lowers each declaration to a validated, content-addressed rule. This is the substrate-free public build: it keeps the exact surface of the aoughwl version but stores styles in a plain table. It is the **one** part of the package that pulls a dependency — the [`plugin`](https://github.com/aoughwl/plugin) nimony plugin-authoring runtime — and only for the block macro. Plain `import css` validation needs nothing but the standard library.

| symbol | signature | what it does |
| --- | --- | --- |
| `style` | `template style(name: string, body: untyped)` | The `style "name": prop: value` block. A compiler plugin (`deps/style_plugin`) lowers each line to a `styleOne` call. |
| `styleOne` | `proc styleOne(component, prop, value: string)` | Register one declaration: validate against the MDN grammar, then store deduped by content under a stable class name. |
| `classOf` | `proc classOf(prop, value: string): string` | The stable, content-derived class name (`c` + FNV-1a hex) for a declaration. |
| `renderStylesheet` | `proc renderStylesheet(): string` | Emit every registered declaration as a single-declaration CSS rule. |
| `styleErrors` | `proc styleErrors(): seq[string]` | The declarations that failed MDN validation. |
| `whyStyle` | `proc whyStyle(component, prop, value: string): string` | Explain a component's style — which class it maps to and whether it is valid per the MDN grammar. |

## Design notes

- **Data-driven.** Everything hangs off the MDN tables in `css/data/*.json` (properties, syntaxes, types, units, at-rules, pseudo-classes, pseudo-elements). Track a spec change by dropping in fresh JSON and re-running the generator; trim the data to constrain which CSS a project is allowed to use.
- **std/json-free at runtime.** The generator `css/tools/gen_data` (run under regular Nim) flattens the JSON into compact tab/newline blobs in `css/data.nim`; the shipped library parses them with a tiny hand-rolled splitter, so no shipped module depends on `std/json` — keeping nimony compiles cheap.
- **Non-raising throughout.** nimony house style: the parser, selector validator and blob loader char-walk and build substrings by hand rather than use raising string slices; validation reports status via `tuple[valid, error]` rather than exceptions.
- **Pay for what you check.** `setLevel` trades coverage for speed (`lvValues` vs. `lvFull`); function/math checking is skipped for any value containing no functions, and error-message bookkeeping is skipped on the success path.
- **Real-world tolerance.** `var()`/`env()` substitution, vendor prefixes, `url(data:…)`, comments and `!important` are handled the way browsers do; unknown vendor-prefixed properties are accepted rather than flagged.

## Requirements

- **nimony toolchain / Nim 3.0.** Pure validation (`import css`) needs only the standard library — no C FFI, no other repos.
- **[`plugin`](https://github.com/aoughwl/plugin)** — required *only* for the `css/style` DSL block macro (declared in `css.nimble`). Everything else is dependency-free.
- **Generator only:** `css/tools/gen_data` runs under regular Nim (`std/json`, `std/os`, `std/strutils`, …) to rebuild `css/data.nim` from `css/data/*.json`; it is a build tool, not a runtime dependency.
