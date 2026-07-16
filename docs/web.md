---
title: web
grand_parent: Documentation
parent: Libraries
nav_order: 2
---

# web — HTML + validated CSS in one nimony block
{: .no_toc }

A declarative DSL for nimony / Nim 3.0 that builds a typed HTML tree and, inline,
validates every style declaration against the MDN grammar and lowers each `style:`
block to a single scoped class. It sits on top of [html](html) and [css](css).

[Repo → github.com/aoughwl/web](https://github.com/aoughwl/web){: .btn .btn-primary }

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

## The DSL

Inside a `web:` block, each line is one of:

| form | lowers to |
|---|---|
| `tag:` + an indented block | an element with those children |
| `tag "text"` (command form) | an element with a single text child |
| `"a bare string"` | a text node |
| `attr:` block of `name: value` | attributes on the enclosing element |
| `style:` block of `prop: value` | inline styles → **validated** via [css](css) → one scoped class |

Styles are checked against the MDN grammar at build time: anything that fails shows
up in `styleErrors()`, and valid blocks are de-duplicated into scoped classes
emitted by `renderStylesheet()`. The tree itself is the typed [html](html) model, so
the output is correctly escaped and void-aware.
