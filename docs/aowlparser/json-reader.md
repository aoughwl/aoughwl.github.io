---
repo: aoughwl/aowlparser
---

# `jsonfast` — the JSON reader

Every dialect in aowlparser keeps **every byte**, because a rewriting front end
must. That is the wrong shape for *reading* a large document, so
`src/jsonfast.nim` is the opposite trade: throw the whitespace away and go fast.

[[toc]]

---

## Measured

Best of 30, DOM-building, parse-only, on real documents:

| reader | 9.9MB catalog | 1.5MB source index | 1.3MB protocol |
|:--|--:|--:|--:|
| **jsonfast** (one-off) | **1377 MB/s** | **2065 MB/s** | **1442 MB/s** |
| **jsonfast** (reused parser) | **1480 MB/s** | **2163 MB/s** | **1489 MB/s** |
| V8 `JSON.parse` (node 25) | 617 | 766 | 559 |
| CPython `json` (C accelerated) | 217 | 274 | 296 |
| `aowljson` (ref tree) | 166 | 331 | 194 |

`tests/json/bench.sh` runs that table on your machine. That is **2.2–2.8× V8
and 5.0–7.9× CPython**, in the GB/s range on every shape.

Both numbers are shown because they answer different questions. A one-off parse
allocates and zeroes a fresh tape; a server parsing a stream of documents reuses
one parser (`newJsonDoc` + `parseInto`) and pays that once. simdjson reports the
reused figure, so it is here — beside the cold one, so neither is hidden.

**It is still not a simdjson clone.** simdjson builds a two-stage SIMD
structural index over the entire document before parsing anything: a different
architecture, not a tuning gap.

## Where the speed comes from

- **A flat tape, not a tree of refs.** One 16-byte entry per value in one `seq`:
  no allocation per value, no pointer chase. A container stores the index one
  past its last descendant, so skipping a 10MB sub-object is `i = node.next`.
- **Zero-copy strings, lazy numbers.** A string is an offset and a length until
  someone asks for it; a number is its lexeme until someone wants its value.
  Most values in a large document are never read at all.
- **No recursion.** Depth is an explicit bounded stack, so `[[[[…]]]]` is a
  named error rather than the stack overflow recursive-descent JSON parsers are
  famous for — and that one is chosen by attackers on purpose.
- **A pre-sized tape.** Growing by doubling copies the whole tape each time; on
  10MB that was 9% of total runtime spent in `memcpy` before the parse had
  learned anything.
- **A jump table for the parser state**, worth another 2%: an if-chain makes
  every token pay, and whichever order you choose penalises one document shape.
- **A hand-grown tape instead of `seq.add`** — worth **+43%**, and the reason
  profiling beat intuition. nimony's `seq.add` asks the allocator about the
  block on every append: 26% of all instructions were mimalloc bookkeeping,
  about 390 instructions per value for what should be a 16-byte store.
- **SIMD scanning** (`src/jsonfast_simd.c`) for the two loops that consume
  nearly every byte — whitespace, and the run to a string's next `"`, `\` or
  control character — sixteen bytes at a time. +7% on the object-heavy catalog,
  **+67%** on the string-heavy index.

### The C file, and why it is there

This is the one part of aowlparser that is not pure nimony. nimony rejects
`addr s[i]`, so neither SIMD nor the word-at-a-time trick that approximates it
can be written in the language today — filed as an aowlsem requirement rather
than accepted as a design choice.

The C functions are **pure scanners**: they find the next interesting byte and
return its offset. Every grammar decision stays in the nimony source, so the C
file cannot disagree with the parser about JSON — it can only be wrong about
where the next quote is, and 494k prefix comparisons would say so. `-d:jfPure`
compiles the scalar loops instead: slower, identical answers, and the gate is
run both ways.

Two optimisations that did **not** pay, recorded because a plausible-sounding
one that loses is worth more than a guess. A byte-classification TABLE for "is
this whitespace / does this end a string", replacing the compare chains, cost
12% — the compares were already cheap and the table added a load. A parallel
`is the open container an object` stack, meant to avoid re-reading the container's tape node, cost 6% (the
node is written recently enough to still be in cache, so the miss it avoided was
not happening). And `var s = src` — the obvious spelling — memcpy'd the whole
document before parsing a byte of it.

## Correctness is measured, not asserted

A reader has no round-trip to hide behind: it discards whitespace by design, so
byte-exactness cannot check it at all. What can is an outside implementation.
`tests/json/tfast.nim` holds jsonfast to CPython's `json` module on:

- **every `.json` file on the dev machine — 10,029 of them**, compared on value
  counts per kind, an FNV digest of every decoded string, and the exact sum of
  every integer;
- **494,323 sampled PREFIXES** of those files, compared on accept/reject.

602,466 checks, all agreeing.

The prefixes are the important half. A corpus of valid documents only proves a
reader is permissive *enough*; a prefix is malformed in a different way each
time, and accept/reject agreement over half a million of them is what catches
the dangerous direction — **accepting what is not JSON**.

Strictness is RFC 8259, which is *stricter than CPython*: `NaN` and `Infinity`
are not JSON, so the oracle is configured to reject them rather than letting the
reader inherit CPython's extension. Two things the gate learned to say out loud:
files that are **not UTF-8** (neither side is truth there), and files that
**changed on disk mid-run** — a real machine's `.json` is full of live state,
and one such file rewrote itself during a sweep and made a correct parser look
wrong by two integers.

## Using it

```nim
import jsonfast

let doc = parse(src)
if not ok(doc):
  echo doc.err, " at offset ", doc.errPos      # errors are values, never raised

let v = view(doc)
echo v{"user"}{"name"}.str("")                 # chain-safe, allocation-free
echo v{"tags"}.at(0).str("")
for tag in v{"tags"}.items: echo tag.str("")
for k, val in v.pairs: echo k.str(""), " = ", val.num(0)
```

A missing key yields an invalid view, and every accessor returns its default for
one — so a chain through absent data cannot fault and allocates nothing on the
way.

### With `aowljson`

```nim
import jsonfast_aowljson
var err = ""
let v = parseJsonFast(src, err)     # drop-in for aowljson.parseJson
```

**The drop-in is not the fast path, and the docs should say so.** Building a
`ref`-per-value tree with a string copy per value costs roughly six times the
parse itself, so `parseJsonFast` lands near `aowljson.parseJson` however fast the
scanner is. If you want the throughput above, stay on the tape and use views.

Building the tree did surface a real defect in `aowljson`, since fixed there:
`[]=` rescans every existing key, making a parser that uses it quadratic in
object width *and* silently collapsing the duplicate keys a faithful reader must
keep. `addPair` is the parser's door.
