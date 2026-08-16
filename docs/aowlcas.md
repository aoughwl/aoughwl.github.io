---
repo: aoughwl/aowlcas
---

# aowlcas — the content-addressed store

> The keystone: a compiler is a pure memoized function over a content-addressed
> graph, and packages, backends, build caches and editors are **views** over
> that graph rather than separate machinery with separate bugs.

[[toc]]

---

## Why a store, and why underneath everything else

Run a compiler twice on the same inputs and you are owed the same answer, so the
second run should be a lookup rather than a compile. That is true at every level
of a toolchain, and today each level solves it separately: the build cache has
one story, the package store another, the artifact cache a third. Three
mechanisms, three sets of bugs, and no way to share an answer between them — or
between machines.

`aowlcas` is the one mechanism underneath.

```
   bytes ──put──►  address                 address ──get──►  bytes
                   (a promise about content, not a place)

   key   ──memo──► what that computation produced
```

Two kinds of thing live here, and the difference matters:

| | what it is | can it be lost? |
|---|---|---|
| **blob** | immutable content, named by its own hash | only if nothing names it |
| **memo** | a recorded answer — a claim about a computation | yes: recomputable by definition |

A build cache is memos keyed on a manifest. A package store is blobs plus roots.
A tower of run/rung edges is memos whose values name other addresses.

## Where it sits in the plan

This is the **storage** rung and only that: it changes identity and caching, not
meaning. That is exactly why it can be introduced underneath a byte-identical
toolchain at zero semantic risk — the order the roadmap has always argued for.
Diverge storage first; diverge semantics much later, deliberately, with its own
gates.

## Two properties worth stating

**A write is atomic.** Content goes to a temporary file and is then renamed. The
common case in a shared store is two processes writing *the same* blob at once —
identical content is precisely what such a store collects — and without the
rename a reader can see a half-written file whose name claims it is complete.
That failure is silent, and it is a wrong answer rather than a crash.

**`verify` can fail, and the gate proves it.** The whole value of a content
address is that it can be checked, and a check nobody has ever seen fail is not
yet a check. The suite corrupts a blob on purpose and requires the verifier to
catch it and name it.

## Using it

```sh
aowlcas put file.txt         # → an address
aowlcas get <address>        # → the bytes, byte for byte
aowlcas verify               # re-hash every blob: does it still match its name?
aowlcas root <address> why   # keep this: name a reason
aowlcas gc --yes             # drop what no root names (dry run without --yes)
aowlcas stat                 # where the store is, how big, what schema
```

The store lives at `$AOWLCAS_HOME`, else `$AOWL_HOME/cas`, else `~/.aowl/cas`.
A `SCHEMA` stamp is checked before anything is read: a store whose layout this
build does not understand is **refused**, not half-read.

## What is deliberately not here yet

Written down because a store that quietly does less than it appears to is the
failure mode this project exists to remove.

- **Structured nodes.** A blob is opaque bytes. Until a typed node —
  `(kind, inputs, outputs)` — exists, GC keeps a root *itself* and cannot follow
  edges it has no way to see. Stated in the code and asserted as the shallow
  behaviour it is, rather than left to be discovered when a collector silently
  drops something.
- **Definition granularity.** The prize is memoizing per definition rather than
  per module. Note the compiler already cuts at the right seam one level down:
  a module's index checksum covers an interface-only projection, so editing a
  private proc body does not invalidate importers. That is correct and must not
  be rebuilt — `aowlcas` extends the same idea upward.
- **A remote.** Content addressing is what makes a shared cache possible; it is
  not itself one.
- **A client.** Wiring the driver's build cache through the store is the next
  rung, and its acceptance test is *the same corpus, the same artifacts, no
  behaviour change* — storage divergence must carry no semantic risk.
