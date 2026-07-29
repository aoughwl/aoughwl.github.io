---
repo: aoughwl/aowli-release
---

# aowli-release — public binaries for the aowli interpreter

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

A prebuilt, **binary-only** distribution of [aowli](../aowli), the typed-AIF
interpreter for Nimony. The source stays private in `aoughwl/aowli`; this repo
ships only the built binaries, hardened for public distribution.

> **Now public** — anyone can access, download, and use it. Issues are welcome:
> [github.com/aoughwl/aowli-release/issues](https://github.com/aoughwl/aowli-release/issues).

[[toc]]

---

## v0.3.2 — correct string/seq slicing & string equality

The current release is **v0.3.2**. It fixes two shipped-runtime correctness bugs
that could make a program silently mis-parse its own data — found while running a
real argument parser under the interpreter:

- **`s[a..b]` / `s[a..<b]` slicing** — the indexer only handled a single integer
  index, so a slice returned just the first element (e.g. `path[0..<8]` yielded
  one character) instead of the substring/subsequence. Slicing now reads the range
  bounds correctly for strings and seqs.
- **string equality across kinds** — a non-string value (a `nil`/default, or a
  mis-sliced char) could compare *equal* to a string when both reduced to the same
  number internally (`nil == "…"` returned `true`). A string is now only ever equal
  to another string.

Verified byte-identical to a native compile on the repro plus a slice sweep; the
full differential corpus stays at **77/77** (no regression on the hot `==` path).

## v0.3.1 — runs the semantic checker (byte-identical to native)

**v0.3.1** carries three root-cause correctness
fixes on top of v0.3.0 — the ones that let aowli run **aowlsem, the Nimony
semantic checker itself**, and produce output **byte-identical to a native
compile** (520/520 tokens on the reference `.p.nif`). That's the milestone: the
interpreter is now correct enough to run a real, compiler-grade program end to
end, so [aowlcode](aowlcode)'s `debug`/`trace` can be pointed at the compiler's
own passes.

What v0.3.1 fixes:

- **Fully-initialised pointer values** — constructing an interior `ptr`
  (`vkPtr`) left the flat-memory view fields (`region` / `foff` / `elemBits` /
  `base`) uninitialised, so a later read saw garbage. Caught with valgrind
  running under mimalloc's Valgrind-tracking build; every `vkPtr` construction
  now sets all fields. This was a genuine memory-safety class, not just a
  cosmetic gap.
- **`seq` append value-copy** — `s.add x` now copies `x` on the way in (the same
  `=copy` envelope semantics v0.3.0 gave assignment), so a later mutation of the
  appended element doesn't alias the source.
- **Content-addressed tag dedup** — `StringView.==` is now gated so NIF tag
  interning deduplicates correctly (surfaced through `borrowCStringUnsafe`);
  content-addressed / `TokenBuf`-style programs compare tags by identity as
  intended.

## v0.3.0 — correctness-complete

**v0.3.0** was the correctness-complete build of aowli. Both engines — the
tree-walker behind `aowli-interp` / `aowli-dbg` and the internal bytecode VM —
reached **zero in-scope divergence across a 423-program differential corpus**
run against the nimony compiler. The engines agree with each other and with
native execution, program for program.

What v0.3.0 closes:

- **Value-copy (`=copy`) semantics** — assigning or binding a value object,
  tuple, or value-array copies the envelope (refs stay shared). `var x = a;
  x.a = 999` no longer mutates `a`.
- **The last OS-boundary gaps** — real host `stat` / `lstat` (correct
  `fileExists` / `dirExists`), pointer identity in `==` / `!=`, `cast[int](ptr)`
  round-tripping through flat memory, and VM argv / stdin seeding.
- **Broad fixes** — float→int conversion, block-expression values,
  cyclic-import init order, a self-nested-iterator hang, and `Table` element
  write-back.

One boundary is **documented, not a gap**: `{.emit.}` literal-C and C FFI aren't
handled by the pure value interpreter — there's no C to execute in the value
model. That's precisely what the **hybrid-native provider** absorbs: the module
in question runs through the real C toolchain as a shared object, while the rest
of the program stays interpreted. It's on the roadmap — not a correctness gap in
the interpreter.

---

## What's in it

Two binaries, each a fully self-contained interpreter over a `.s.aif` (a
Nimony program's typed, post-semcheck AIF):

- **`aowli-interp`** — run a program, or `--trace` it for its execution
  call-tree.
- **`aowli-dbg`** — batch breakpoints: run with `--break:LINE`, dumping every
  hit frame's variables in one pass.

These are the same binaries the [aowlcode](aowlcode) Claude Code plugin's
`trace`/`debug` tools shell out to — a public user of that plugin runs entirely
off this release, never a private aowli checkout.

## Hardening

Before publishing, each build goes through:

- A **licence gate** (fail-closed, checked at module init) — the binary refuses
  to run without a valid licence rather than degrading silently.
- **`strip --strip-all`** — the symbol table is removed entirely.

Both were verified against the shipped binary: the stripped artifact exposes no
aowli source paths and no internal proc/type names.

## Distribution

Shipped as a **GitHub Release**,
[v0.3.1](https://github.com/aoughwl/aowli-release/releases/tag/v0.3.1), with the
binaries as release assets. Each build lists a SHA256 and a VirusTotal-by-hash
link so the asset can be verified independently of trusting the download host.

## Usage

```sh
chmod +x bin/aowli-interp
./bin/aowli-interp <module.s.aif>          # run
./bin/aowli-interp --trace <module.s.aif>  # execution call-tree
./bin/aowli-dbg  --break:29 <module.s.aif> # batch breakpoint, dumps frame vars
```

## Resolution order

Tools built against aowli (notably [aowlcode](aowlcode)'s `trace`/`debug`)
resolve a binary in this order, so a released install never needs source:

```
$AOWLI_BIN_DIR → ~/.aowl/bin → dev ~/aowli/bin
```
