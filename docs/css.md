---
title: css
grand_parent: Documentation
parent: Builtin Libraries
nav_order: 4
---

# css — an MDN-typed CSS engine for nimony
{: .no_toc }

Parse a whole stylesheet, then validate every value against its official grammar,
every function against its own signature, and every selector against Selectors-4.
Pure logic, standard library only, **no dependencies**. Successor to the Nim-2
[thing-king/css](https://github.com/thing-king/css). For nimony / Nim 3.0.

[Repo → github.com/aoughwl/css](https://github.com/aoughwl/css){: .btn .btn-primary }

```nim
import css

validateValue("margin", "0 auto").valid                     # true
validateValue("width",  "clamp(1rem, 2vw, 3rem)").valid     # true
validateValue("color",  "rgb(255 0 0 / 50%)").valid         # true

validateValue("width",  "clamp(1rem, 2vw)").error   # "clamp() expects 3 arguments, got 2"
validateValue("color",  "rgb(1, 2)").error          # "invalid arguments to rgb(): …"
validateValue("color",  "10px").error               # "at token 1: expected <color>, got '10px'"

validateSelector("ul > li:nth-child(2n+1)").valid           # true
$specificity("a.btn#go")                                    # (1,1,1)
```

## What makes it complete

Most CSS tools **parse** but do not **validate against the grammar**. The few that
do (css-tree, the W3C validator) stop at flat value matching. This engine goes the
whole way:

- **Every property value** matched against its MDN value-definition syntax
  (`<length-percentage>{1,4} | auto`, `<'border-radius'>`, `||`, `&&`, `#{n}`, …).
- **Math functions checked recursively** — the self-nesting
  `clamp(calc(…), min(…), max(…))` grammar, exact arity, precise errors.
- **Every function** (`rgb`/`hsl`/gradients/transforms/…) matched against its own
  signature — wrong arity, wrong argument types, unknown functions.
- **Selectors** validated against Selectors-4 (specificity + cascade too).
- **Real-world CSS** — `var()`/`env()` substitution, vendor prefixes,
  `url(data:…)`, comments, `!important` — handled the way browsers do.

Everything is **driven by the MDN data** in `css/data/*.json`: track a spec change
by dropping in fresh JSON and re-running `css/tools/gen_data`; trim the data to
constrain which CSS a project is allowed to use.

Pairs with [html](html) for typed markup and [web](web) for the combined DSL.
