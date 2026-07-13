---
title: Configuration
parent: nifparser
grand_parent: NIF Toolchain Alternatives
nav_order: 4
---

# Configuration
{: .no_toc }

Every option below is **off / neutral by default**, so a plain
`nifparser p in.nim` produces output byte-identical to native `nifler`. The flags
exist for editors, linters, and non-Nim-standard sources; none of them can change
the NIF a default run emits.

```
usage: nifparser [OPTIONS] p <in.nim> [out.p.nif]
```

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## `--curly` — brace block bodies

Lets a `{ … }` block body stand in **anywhere** a `:` body is accepted, and the
two styles may be mixed freely:

```nim
if c { echo a } else: echo b       # brace + colon in one statement
while x { dec x; use x }            # `;`-separated statements inside a brace
```

A block `{` is disambiguated from a set literal by context — it must follow an
operand (`if c {`) or a bodiless-block keyword (`else {`, `try {`, `block {`,
`finally {`, `defer {`) — so a set in the head (`if {1} == x { … }`) is not
mistaken for the body. This is a nifparser extension; native nifler has no
equivalent, so output stays nifler-compatible only while it is off.

## Indentation & whitespace policy

Nim's layout is column-based, and classic Nim is **spaces-only** — its lexer
hard-errors on a tab in indentation. nifparser keeps that as the default but can
relax it for sources that use tabs, and can validate indentation for tooling.

### `--tabs:MODE` — what may indent a line

| mode | meaning |
|:--|:--|
| `spaces` *(default)* | Spaces only, the classic-Nim stance. A stray `\t` advances a single column, exactly as before. |
| `tabs` | Tabs are allowed for indentation; each `\t` advances `--tab-width` columns. |
| `both` | Tabs **or** spaces are accepted; a line whose *leading* whitespace mixes the two is reported (non-fatal) on stderr, keeping Nim's "mixing is suspect" stance as a warning rather than a hard error. |

### `--tab-width:N` — columns per tab

How many columns a `\t` advances when tabs are permitted (default **8**, the
classic editor/Nim tab stop). It scales the `indent`/`col` coordinates recorded on
tab-indented lines. Because the off-side rule is a **relative** column comparison,
the parse *structure* is identical regardless of the width — so a tab-indented
file parsed with `--tabs:tabs --tab-width:8` yields the same structural NIF as its
8-space-indented equivalent. The width only affects the absolute coordinates.
Ignored under `--tabs:spaces`.

### `--indent-width:N` — advisory indentation check

Default **0** (disabled). When `N > 0`, a first-on-line token whose indentation
column is not a multiple of `N` is reported on stderr. This is a **diagnostic
only** — it never alters the recorded indent, so parsing is untouched (the
off-side rule stays relative). It exists so a tooling front end can flag
inconsistent indentation without a separate lint pass; it cannot, by design,
change the emitted NIF.

## Worked example

```sh
# default — nifler-compatible, spaces only
nifparser p mod.nim mod.p.nif

# accept a tab-indented file (8-column tabs), same tree as the space version
nifparser --tabs:tabs --tab-width:8 p tabbed.nim tabbed.p.nif

# accept either, and warn on lines that mix tabs and spaces
nifparser --tabs:both p mixed.nim mixed.p.nif

# validate that every indent step is a multiple of 2 columns (diagnostic only)
nifparser --indent-width:2 p mod.nim mod.p.nif

# brace blocks plus tab indentation, mixed freely
nifparser --curly --tabs:tabs p editor_dialect.nim out.p.nif
```

## Design note: nothing here touches the wire format

These options deliberately affect only **input acceptance** and **diagnostics**,
never the emitted NIF (except `--curly`, which only *adds* accepted syntax that
maps onto the exact same block nodes). That keeps nifparser's core contract intact:
its default output is, and remains, byte-for-byte native `nifler`.
