---
title: web / html / css
parent: Projects
nav_order: 6
---

# web · html · css — the frontend stdlib
{: .no_toc }

Three composable frontend libraries for nimony / Nim 3.0: a typed HTML5 registry
and renderer, an MDN-typed CSS engine, and a declarative DSL that fuses them with
validated inline styles. Pure logic, standard library only, **no dependencies**.

<details open markdown="block"><summary>Contents</summary>{: .text-delta }
- TOC
{:toc}
</details>

---

## `html` — typed HTML5
[Repo → aoughwl/html](https://github.com/aoughwl/html){: .btn }

A registry of every HTML5 element and its attributes (with void / deprecated /
experimental markers), plus a document-tree builder and a correct, escaping,
void-aware renderer.

```nim
import html

isElement("section")            # true
isVoidElement("br")             # true
isAttribute("a", "href")        # true
isAttribute("div", "href")      # false  (href is not valid on <div>)

echo $el("a", @[attr("href", "/x?a=1&b=2")], @[text("go & see <it>")])
# <a href="/x?a=1&amp;b=2">go &amp; see &lt;it&gt;</a>
```

A **registry** (`isElement`, `isVoidElement`, `isDeprecated`, `isExperimental`,
`isGlobalAttribute`, `isAttribute`, `elementAttributes`) driven by a baked HTML5
table, plus a **document tree** (`HTMLNode` = element / text / comment / raw) with
a builder and an escaping renderer.

## `css` — MDN-typed CSS engine
[Repo → aoughwl/css](https://github.com/aoughwl/css){: .btn }

Parse a whole stylesheet, then validate every value against its official grammar,
every function against its own signature, and every selector against Selectors-4.
Successor to the Nim-2 `thing-king/css`.

```nim
import css

validateValue("margin", "0 auto").valid                     # true
validateValue("width",  "clamp(1rem, 2vw, 3rem)").valid     # true
validateValue("color",  "rgb(255 0 0 / 50%)").valid         # true
validateValue("width",  "clamp(1rem, 2vw)").error   # "clamp() expects 3 arguments, got 2"

validateSelector("ul > li:nth-child(2n+1)").valid           # true
$specificity("a.btn#go")                                    # (1,1,1)
```

Where most CSS tools **parse** but don't **validate against the grammar**, this one
goes the whole way — every property value matched against its MDN value-definition
syntax, math functions checked recursively (the self-nesting `clamp(calc(…), …)`
grammar), every function matched against its signature, selectors against
Selectors-4 (with specificity + cascade), and real-world CSS (`var()`/`env()`,
vendor prefixes, `url(data:…)`, `!important`) handled the way browsers do.
Everything is **driven by the MDN data** in `css/data/*.json` — track a spec change
by dropping in fresh JSON; trim the data to constrain which CSS a project may use.

## `web` — HTML + validated CSS in one block
[Repo → aoughwl/web](https://github.com/aoughwl/web){: .btn }

A declarative DSL that builds a typed HTML tree and, inline, validates every style
declaration against the MDN grammar and lowers each `style:` block to a single
scoped class.

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

echo render(page)
# <div id="hero" class="cc9ece13d"><h1>Hello, nimony</h1>…</div>
echo renderStylesheet()
# .cc9ece13d{color:red;padding:10px 20px}
for e in styleErrors(): echo e   # declarations that failed MDN validation
```

Inside a `web:` block each line is a `tag:` block, a `tag "text"` command, a bare
string (text node), an `attr:` block, or a `style:` block — the last **validated**
via `css` and lowered to one scoped class. `web` sits on top of `html` and `css`;
full DSL reference in the [repo README](https://github.com/aoughwl/web).
