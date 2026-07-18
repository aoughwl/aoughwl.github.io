---
repo: aoughwl/aowlfmt
---

# aowlfmt — verified layout formatter

A source formatter for Nim / aowl that **proves it changed nothing but layout**
before it will touch your file. Written in **nimony**, like the rest of the
stack, and built on **[aowlparser](aowlparser)** — it never reimplements the
lexer or parser, it uses the parser as an oracle.

<div class="hero-actions">
<a href="/docs/aowlparser">Parser → aowlparser</a>
</div>

[[toc]]

---

## Why it exists

A formatter that can silently change what your program *means* is worse than no
formatter at all. Most formatters rely on the author's care and a good test
suite to avoid that. aowlfmt replaces care with a **mechanical proof**.

It normalises the boring things — trailing whitespace, runs of blank lines, the
final newline, `CRLF → LF`, optionally leading-indent tabs → spaces — and then,
for every file it would change, checks:

```
normalize(AIF(original)) == normalize(AIF(formatted))   ⇒  safe to write
```

That is: it asks [aowlparser](aowlparser) for the **AIF** (its typed
syntax-tree serialisation) of both the original and the candidate output, strips
the per-node position info that layout legitimately moves, and compares. If the
two differ — or the input didn't parse to begin with — the reformat is
**rejected** and the file is left byte-for-byte unchanged.

This is the same discipline [aowlsuggest](aowlsuggest) uses for quick-fixes:
*consume aowlparser, verify against it, never reparse.*

## The gate earns its keep

Trailing whitespace looks trivial to strip — until it's *inside a triple-quoted
string*, where it's significant. Strip it there and you've changed the program.
aowlfmt's gate catches exactly that case: the AIF differs, the reformat is
refused, the file is untouched. No special-casing in the rules; the proof covers
it for free.

Proven over the same 599-file valid corpus the rest of the stack tests against
(the nimony compiler + nimony stdlib + the full upstream Nim stdlib): every
reformat preserved program structure and every one is idempotent — **0
corrupted, 0 non-idempotent.**

## Using it

```sh
aowlfmt <file>...            # print formatted text to stdout
aowlfmt <file>... --write    # rewrite in place (only when changed AND proven safe)
aowlfmt <file>... --check    # exit 1 if anything isn't already formatted (CI)
aowlfmt --stdin              # format stdin → stdout
```

The **[aowllsp](aowllsp)** server wires `textDocument/formatting` straight to
`aowlfmt --stdin`, so "format document" in the editor inherits the same
can't-corrupt-your-buffer guarantee.

## What's deliberately not here yet

Token-level spacing (around operators, after commas) needs aowlparser to expose
its **token stream**, so the formatter never has to guess where a string or
comment begins. Until that seam exists, aowlfmt stays a layout normaliser — one
that is provably safe rather than a pretty-printer that is merely usually right.
