---
title: html
parent: Builtin Libraries
nav_order: 3
---

# html — typed HTML5 for nimony
{: .no_toc }

A registry of every HTML5 element and its attributes (void / deprecated /
experimental markers), plus a document-tree builder and a correct, escaping,
void-aware renderer. Pure logic, standard library only, **no dependencies**. For
nimony / Nim 3.0.

[Repo → github.com/aoughwl/html](https://github.com/aoughwl/html){: .btn .btn-primary }

```nim
import html

isElement("section")       # true
isVoidElement("br")        # true
isAttribute("a", "href")   # true
isAttribute("div", "href") # false   (href is not valid on <div>)

echo $el("a", @[attr("href", "/x?a=1&b=2")], @[text("go & see <it>")])
# <a href="/x?a=1&amp;b=2">go &amp; see &lt;it&gt;</a>
```

## Two halves

**A registry**, driven by a baked HTML5 table:

| proc | result |
|---|---|
| `isElement(name)` | is `name` a known HTML element (case-insensitive) |
| `isVoidElement(name)` | void element — no children, no closing tag (`<br>`, `<img>`, …) |
| `isDeprecated(name)` | obsolete element (`<center>`, `<font>`, `<marquee>`, …) |
| `isExperimental(name)` | not yet baseline (`<fencedframe>`, …) |
| `isGlobalAttribute(attr)` | global attribute, incl. `data-*` / `aria-*` / `on*` families |
| `isAttribute(element, attr)` | valid on that element (global **or** element-specific) |
| `elementAttributes(element)` | the element-specific attributes declared for it |

**A document tree** — `HTMLNode` (element / text / comment / raw) and `HTML` (a
sequence of them) with a builder (`el`, `attr`, `text`) and an escaping,
void-aware renderer (`$`).

Pairs with [css](css) for validation and [web](web) for the combined DSL.
