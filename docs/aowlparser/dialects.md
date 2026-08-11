---
repo: aoughwl/aowlparser
---

# Dialects — one core, nine byte-exact front ends

aowlparser began as a Nim front end. The parsing core underneath it,
`src/aowlparse/`, is now a small library for building **byte-exact source → AIF**
front ends, and the formats in the repo are its users rather than demos: each is
a first-class parser validated on a real corpus.

[[toc]]

---

## The dialects

| dialect | command | validated on |
|:--|:--|:--|
| `nim-parsed` | `aowlparser p` | 172 corpus programs + the full Nim stdlib, against the `nifler` oracle |
| `css-parsed` | `aowlparser css` | bootstrap ×2 + the doxygen suite, 543KB |
| `html-parsed` | `aowlparser html` | 150 diverse real pages |
| `py-parsed` | `aowlparser py` | every `.py` on the dev machine — 2,885 files, 8s |
| `js-parsed` | `aowlparser js` | 11,556 `.js`, 557MB, 100s |
| `json-parsed` | `aowlparser json` | every `.json` — 4,326 files |
| `vds-parsed` | `aowlparser vds` | 1,224 MDN grammar strings |
| `md-parsed` | `aowlparser md` | every `.md` — 5,920 files, 6s |
| `yaml-parsed` | `aowlparser yaml` | every `.yaml`/`.yml` — 2,112 files, 0.4s — **and** the official yaml-test-suite, 402 cases |
| `cfg-parsed` | `aowlparser cfg` | every `.cfg`/`.ini` — 1,070 files |

```sh
aowlparser auto file.yml     # dialect from the extension
aowlparser dialects          # every dialect and its node vocabulary
aowlparser render out.aif    # AIF back to source, dispatching on the header
```

Adding a dialect is one row in `src/dialects.nim`: the CLI's command list,
`auto` dispatch and `render` all read the registry, so a dialect cannot exist in
one place and be missing from another.

## One declaration, both directions

A dialect declares each tag once — **text / punct / struct / opaque** — and both
the parser and the single shared renderer read that declaration. Writing a
renderer per dialect let it disagree with its parser about whether a byte is
emitted, which is exactly the bug class a byte-exact gate exists to catch. Here
the disagreement is not merely caught, it is unrepresentable.

`undeclaredTags` closes the other door: an undeclared tag would render as
nothing, so forgetting to declare a node is a silent byte loss. The gate names
it instead.

## The hazard every document dialect shares

**Content that is not markup.** Each of these formats embeds a region whose
bytes look like structure and are not:

- HTML — `<script>` and `<style>` raw text
- Markdown — fenced code, which can contain `# heading` and `- list`
- YAML — a block scalar (`script: |`), whose indented lines routinely read as
  `- items`, `key: values` and `# comments`
- YAML again, smaller — a multi-line flow collection, and a `#` inside a quoted
  scalar

Reading any of those as structure produces a tree that is nonsense **while
staying perfectly byte-exact**, so the round-trip cannot tell the two apart.
That is why every dialect carries shape assertions, and why they concentrate
precisely here.

## `cfg-parsed`

The ini family as it actually appears on disk, which here means Nim's `nim.cfg`
dialect above all: `[sections]`, `key = value`, switches (`--path:"$lib"`,
`-d:release`), bracketed keys (`warning[SmallLshouldNotBeUsed] = off`),
`@if`/`@end` conditionals, `#`/`;` comments.

Its hazard is not embedded content but **ambiguity**: one directory holds
`--path:"x"`, `path = "x"` and `[Package]`, and guessing wrong still round-trips
byte-for-byte because every byte survives whichever node it lands in. The shape
assertions are therefore about WHICH node a line became — the only thing a byte
comparison cannot see.

## `yaml-parsed`

Block structure: documents, mappings, sequences, indentation nesting, comments,
block scalars, and flow collections parsed rather than swallowed — `{a: 1}` is
an `entry` exactly as `a: 1` is, so a consumer asking "what are the mapping
entries?" gets the same answer whichever syntax the document used.

Deliberately **not** modelled, and named as such in the gate rather than quietly
counted as agreement: an explicit `? key`, and a collection used as a key
(`{a: 1}: v`). Anchors and aliases are preserved as text, not resolved — this is
a concrete-syntax dialect, not a YAML loader.

See [Outside oracles](testing#outside-oracles) for what the yaml-test-suite
found that the byte-exact round-trip could not.
