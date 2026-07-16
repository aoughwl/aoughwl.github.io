---
title: Browser & JavaScript
parent: aowlparser
grand_parent: Compiler Pipeline
nav_order: 7
---

# Browser & JavaScript
{: .no_toc }

aowlparser compiles to JavaScript and runs client-side, which is what lets the
[playground](../../playground) parse code in the browser tab with no backend. The
machine contract: the globals the JS bundle reads and writes, how the bundle is
built, and the editor diagnostics layer.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The `globalThis` contract

The browser entry (`webmain.nim`) runs as module-init: set the input globals,
evaluate the bundle, then read the outputs off `globalThis`. No filesystem, no
stdout.

**Inputs**

| Global | Type | Meaning |
|:--|:--|:--|
| `__np_src` | string | the Nim source to parse (empty ⇒ parses empty) |
| `__np_file` | string | path baked into line-info suffixes; **defaults to `in.nim`** when empty |
| `__np_curly` | string | any **non-empty** value (e.g. `"1"`) enables experimental `{ … }` block bodies; empty/absent = classic indent-only |

**Outputs**

| Global | Type | Meaning |
|:--|:--|:--|
| `__np_out` | string | the produced `.p.nif` bytes |
| `__np_diag` | string | JSON array of syntactic diagnostics |

Each diagnostic is `{"line": L, "col": C, "message": "…"}` with **line 1-based and
col 0-based** (the JS glue shifts col to Monaco's 1-based convention). A fresh
bundle scope per parse is required — nimony's generated `main` guards module-init
to run once, and the parse lives in that init — so callers re-evaluate the bundle
(cheap: ~8 ms) rather than re-invoking a cached `main`.

## How the bundle is built

`aowlparser.js` is produced by `webtest_build.sh` in three stages:

1. **Frontend** — `nimony c --bits:32 --define:nimNativeAlloc` compiles
   `src/webmain.nim` (plus the parser sources and the jsffi shim) into `.c.nif`
   modules. The 32-bit native C link failure at the end is expected and harmless;
   the `.c.nif` artifacts are what matter.
2. **`nim_js`** — [aowlweb](../aowlweb)'s JS backend turns each `.c.nif`
   into a `.js` module.
3. **Bundle** — an `awk` pass floats every module's two-phase const sections
   (`__NIMJS_CONST_ALLOC` / `_FILL`) ahead of the code (curing cross-module TDZ),
   prepends the shared `runtime.js` (the linear-memory allocator), and
   concatenates everything into `aowlparser.js`.

## Editor diagnostics (`webdiag.nim`)

The core parser is deliberately **lenient** — it skips unknown bytes and keeps
going, so it can round-trip messy real-world source. Live editor squiggles need
the opposite, so a separate web-only module (`webdiag.nim`, kept out of the
byte-synced core files) supplies them without forking the lexer.

Its diagnostics are **purely syntactic** — lexer-level and bracket-balance. The
recursive-descent parser itself emits no diagnostics, so a malformed but
bracket-balanced construct produces NIF with no complaint; genuine type/semantic
errors surface later, from `nimsem`.

- **`lexDiags(src)`** — a second lexer pass that reports **unterminated literals
  and comments**: unclosed `"…"`, triple `"""…"""`, raw `r"…"`, char `'…'`, and
  unclosed `#[ … ]#` / `##[ … ]##` block comments (depth-tracked). It correctly
  steps over backquoted identifiers and numeric `'`-suffixes so they aren't
  mis-flagged.
- **`bracketDiags(toks)`** — a stack scan over the token list flagging
  `unmatched closing '…'`, `mismatched bracket: '…' opened at L:C closed by '…'`,
  and `unclosed '…'` at EOF, across the `()` / `[]` / `{}` families.
- **`tokenizeD(src)`** — returns the core tokens paired with `lexDiags`.

The browser entry composes them: `lexDiags` first, then `bracketDiags` over the
tokens, serialized into `__np_diag`.

---

For the format these bundles produce, see [The .p.nif format](output-format); for
the CLI equivalents of the `__np_*` inputs, see [Configuration](configuration).
