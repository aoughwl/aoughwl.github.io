# Catalogs

The only cross-mod channel there is. Mods cannot import each other and cannot
pass handles to each other, so everything one mod publishes for another to use
goes through a catalog — which carries data, and never code.

[[toc]]

## The three roles

A catalog **kind** is a schema declared by one mod. A **catalog** is a named
list of that kind, created by a second mod. **Items** in a catalog can be
contributed by any mod, and each item remembers who contributed it.

```nim
# mod A — declares that a kind exists
defineCatalogKind("infiniteless.part", "text",
  "Anything that can be placed in the world and has a visual asset.")

# mod B — creates a catalog of that kind
createCatalog("props", "infiniteless.part", "Things to build with")

# mod C — fills it, knowing nothing about A or B beyond two strings
addToCatalog("props", "block", "builtin://cube")
```

None of the three knows the others' names, types, or load order. Nothing is
registered centrally and nothing is edited to add content. Removing mod C
removes exactly mod C's entries.

A kind carries one value type — `text`, `integer`, `number`, `boolean` or
`entity` — and `addToCatalog` type-checks against it. The declaring mod owns the
kind: a different mod calling `defineCatalogKind` with the same id is rejected.

## Ownership is the whole safety story

The bridge passes the *calling* mod as the owner of every entry, which is what
makes cross-mod contribution work and what makes it safe.

| Property | How |
| --- | --- |
| A claim is scoped to the mod that made it | every entry records its owner |
| A claim is reaped when that mod unloads | entries and kinds owned by the generation are removed |
| Two mods claiming one key is reported, not guessed | a lookup that finds two providers refuses and names them |
| An unclaimed key is refused, naming what is claimed | the error lists the registered ones |

The `(id, owner)` pair must be unique within a catalog. The same mod cannot
register the same item id twice; two different mods **can**, and both entries
are kept. That is not a loophole, it is the extension mechanism — see
*Later entries win*, below.

## Reading one

```nim
let props = named("props")
for item in props.entries():
  log(item.id & " from " & item.provider & " = " & item.text())

let one = props.find("block")
if one.exists():
  discard spawnPart("props", one.id, vec3(0.0, 3.0, 0.0))
```

The iterator is `entries`, not `items`: `items` is a name the interpreter
implements as a native and would take from you silently. Entries come back in
registration order.

**Asking a catalog nobody has created yet returns nothing rather than failing.**
In a system with no load order that is the ordinary state of a catalog before
its owner arrives, so it is not an error condition.

## Generations

Catalogs and kinds are versioned lists. A new generation of the owning mod
pushes a new entry that shadows the previous one; if that generation fails and
is unloaded, its version is removed and the older one becomes visible again.
That is what makes a failed reload non-destructive to content.

## Later entries win

A consumer that walks a catalog in registration order and assigns as it goes
gets last-writer-wins for free. Because `(id, owner)` is what must be unique, a
second mod adding `jump` to somebody else's controls catalog does not collide
with the first — both entries are kept, and the newcomer's, being later, wins.

So a mod that likes an existing scheme except for one key publishes that one
key. A mod that wants none of it declares its own catalogs of the same kinds and
passes those names instead. Neither has to fork anything, and neither has to
know the other exists.

## Worked example: the character controller

The shipped character mod declares two kinds that know nothing about characters:

```nim
defineCatalogKind("infiniteless.binding", "text",
  "A named action and the key that performs it.")
defineCatalogKind("infiniteless.setting", "number",
  "A named number that tunes how something behaves.")
```

Then it fills one catalog of each — WASD, space and left shift in
`character.controls`; the fourteen numbers a character has in
`character.movement`. That is the whole mod: forty-eight lines, no logic.

A consumer reads the scheme by name and never names its provider:

```nim
player.configure("character.controls", "character.movement")
```

## Worked example: schemes and formats

The parts system is built out of two catalogs and nothing else. The host knows
no schemes and no formats of its own, and it does not keep a register of them
either. A claim is a catalog item like any other: the item id is the scheme or
the file extension, the value is the name of the proc that answers, and the item
already knows which mod contributed it.

| Catalog | Kind | Item | Value |
| --- | --- | --- | --- |
| `infiniteless.schemes` | `infiniteless.scheme` (text) | `builtin` | `resolveBuiltin` |
| `infiniteless.formats` | `infiniteless.format` (text) | `.obj` | `readModel` |

Both kinds are declared by the SDK, not by the engine. `provideScheme` and
`provideModelFormat` declare the kind and create the catalog only if no mod has
yet, then add one item — and "only if no mod has yet" is *asked*, not assumed, so
the first provider to load owns the catalog and every provider after it just
adds to it.

The only thing the engine holds about either catalog is its name. It never
creates them, never declares their kinds, and never reads their values as
anything but a proc name to call. See [importers](/docs/jester/importers) for
what happens on the other side of that call.

## Facets: more than one field per id

A catalog holds one kind of value, so a definition with a name, a number and a
tag list is not one catalog. It is a base catalog of names plus one *facet*
catalog per field, all keyed by the same id, with the facet's catalog id being
the base's plus a suffix.

That is a spelling rule rather than a feature, which is the point: a mod that
never calls the builder still puts its numbers where a reader looks. The
inventory library uses it for items and containers:

| facet catalog | kind | value | default |
| --- | --- | --- | --- |
| `<base>.stack` | `infiniteless.item.stack` | integer | 1 — never stacks |
| `<base>.bulk` | `infiniteless.item.bulk` | number | 1.0 |
| `<base>.weight` | `infiniteless.item.weight` | number | 0.0 |
| `<base>.shape` | `infiniteless.item.shape` | text | `""` |
| `<base>.tags` | `infiniteless.item.tags` | text | `""` |

`shape` is an opaque token — `"2x3"`, `"pistol"`, anything — that the library
carries and never reads, because a shape only means something to whoever draws
it. `tags` are the only thing a container filters on. Containers get the
matching treatment: slots, capacity, load, accepts, rejects, with every limit
below zero meaning no limit.

The mod that declares the kinds is the first to call for them in a session and
every later call is a no-op, so a content mod may declare defensively rather
than depend on load order.

## Signatures

`catalogSignature(catalog)` hashes a catalog's kind and every item in it — id,
contributing mod and value — sorted, so load order is not mistaken for
disagreement.

That is what makes [multiplayer](/docs/jester/networking) and saved worlds work
without shipping geometry. Every peer builds a part itself out of its own copy
of the catalog, so two peers whose catalogs are not the same catalog would
quietly show two different worlds. The signature is how that stops being quiet:
a placement from a peer whose signature does not match is refused with both
shapes named, and a receiving peer can ask whether the placer's catalog was its
own.

## What is not there

- **Entity-kind catalogs are half-built.** The kind parses, but there is no
  `Entity` overload to fill one with and no reader to get one back, so it can
  only be used as raw integers — and an entity handle cannot cross a mod
  boundary anyway.
- **Entries are append-only for a given `(id, owner)`.** Re-registering the same
  item id from the same mod inside one generation is refused, so a catalog
  cannot be corrected in place; the way to change an entry today is a new
  generation of the mod that owns it.
- **Spawning is interpreted by the engine**, not by the kind's owner. A kind's
  declaring mod cannot decide what it means to place one of its things.
