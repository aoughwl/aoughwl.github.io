# The emulator

`mods/tarkov` is an Escape From Tarkov server — profiles, the static tables,
traders and trading, the inventory, quests with their conditions actually
evaluated, the hideout and its production queue, raids and their generated loot,
bots, scavs, skills, the flea market, mail with redeemable attachments,
insurance — and it is **a mod**. 22,223 lines of nimony across 38 modules,
importing `aowlspt`, `aowlspt/server` and `aowlspt/json`, and nothing else.

**There is no private door into the host.**

[[toc]]

---

## Why it is a mod

> A plugin API is only as good as the largest thing anyone has written with it.

That is the whole argument, and the constraint is what makes it work: every gap
found while writing the server was closed **in the API** rather than worked
around in the mod. The repository keeps the list:

| Found writing | Closed by |
|---|---|
| profiles must survive a restart | `save` / `load` / `savedKeys`, on ABI revision 2 |
| every route reads a request body | `aowlspt/json` — `field`, `each`, `count` |
| every route writes one back | `arr`, `objOf`, `envelope`, `failure` |
| a profile must keep fields the mod does not model | `Doc` / `List` member-wise editing |
| one mod tells another a raid ended | `broadcast` / `onEvent`, now delivered |
| a sweep must run whether or not a request arrives | `everyMs`, off the request threads |
| a config value read one way on one host and another on another | `ConfigValue.asText`, unquoting on every host |
| a mod that adds a table the database has never held | `dbWrite` creating a path instead of refusing |

It is also why the mod API is sized the way it is. `RouteCapacity` is 1024, and
the comment beside it names `mods/tarkov` as *"the high-water mark in this
repository"* — the design constant comes from the largest real consumer, not
from a guess.

## An endpoint

```nim
proc onKeepAlive(url, body, session: string): string =
  var o = obj()
  put(o, "msg", "OK")
  put(o, "utc_time", nowSeconds())
  result = envelope(o)

discard serve("/client/game/keepalive", onKeepAlive)
```

`envelope` is the client's own wrapper — `{"err":0,"errmsg":null,"data":…}` —
and every route goes out through it. Route registration happens in one place, in
the order the client calls them: *"reading this list top to bottom is reading
the client's boot sequence."*

## Coverage, generated rather than claimed

The gap list is derived from `reference/` — a metadata dump of SPT's own public
API surface, produced by `tools/SptReflect`, the one C# program in the project.
Every request the Tarkov client can make reaches one method on one `Callbacks`
class, so the method list is the complete demand side: **226 methods**, of which
15 are that server's own plumbing, leaving **211 client-facing operations**.

| | operations | |
|---|---:|---|
| served, and shaped against the reference DTO | **129** | a route or an item-event arm of its own |
| served, deliberately empty or flattened | **21** | answered by a stock stub, and named individually |
| not served | **61** | 404s; the client retries or does without |
| client-facing operations | **211** | |

**Those three numbers are generated.** `tools/coverage.nim` computes them by
reading `docs/coverage-rows.json` and `mods/tarkov/tarkov.nim` itself, writes
them into the document between explicit markers, and `aowl test` runs
`aowl-coverage --check`, which fails if they are stale. Nobody edits them.

The history of that decision is the interesting part. The hand-joined passes
before the generator existed read 127/24/60, then 122/25/64, 119/26/66,
117/27/67 and 107/28/76. The generator's first run moved the split by three
operations, **and every one of them was a correction rather than a change to the
emulator** — two callbacks with no row at all, one that nothing in the code
bound. A document cannot see its own subject; a program reading both can.

## The database

`aowl importdb --from D:\SPT` converts an SPT installation into the database the
emulator reads:

| | |
|---|---:|
| item templates | 4,673 |
| traders | 12 |
| quests | 558 |
| maps | 19 |
| size | **39.40 MiB** (41,313,127 bytes) |

The imported database is **never in a release**: it is BSG's data by way of
SPT's, and it is produced locally from your own install.

Loose loot is opt-in, and the reason is a good example of a refusal being
re-checked rather than inherited. `--loose all` produces a 587.49 MiB database,
and one request to `/client/locations` against a backend on it used to return a
**560 MB body**. The document's stated cause was the storage layer; when that
was measured, the storage layer had already been fixed (a `db_patch` of an
existing value went from 171 ms to 6.1 ms) and the real cause was the route
splicing the `locations` subtree in verbatim. The route was rewritten, and the
absence is now asserted rather than assumed: a self-check runs the builder over
a fixture that deliberately carries `looseLoot` and a `staticAmmo` table, and
fails the load if either appears in the body.

## The gates over it

| gate | checks | against |
|---|---:|---|
| `emutest` | **577** | `tests/fixtures/emu-full.json`, driven through the client's boot sequence and a restart |
| `realtest` | **168** (1 skipped) | the 39.40 MiB database imported from a real SPT install |
| `soak` | **915** | 24 closed play cycles, checked by invariant |
| `fuzzwire` | **152** | input no client would send |
| `framelen` | **102** | hostile `Content-Length` framing |
| `wstest` | **62** | the notifier websocket — does a push reach the session |
| `pttguard` | **62** | Path To Tarkov's graph against the real database |

`realtest` is skipped rather than failed when no imported database is present,
which is the right behaviour and also the sort of thing this project makes a
point of saying out loud.

## What it refuses

`docs/EMULATOR-REFUSALS.md` is a document of things the emulator does **not**
do, each with the reason, and each re-checked against the imported database
rather than against the last person who wrote it down. The standing instruction
in the backlog is blunt about why that matters:

> Before scheduling anything here, grep `build/db/db.json` for the table the row
> claims to need. A gap gets written down once, with a reason, and the reason is
> never re-checked against the data — so the sentence outlives the fact and a
> feature stays unbuilt for months behind it. **The cost of being wrong in this
> direction is invisible, which is why it keeps happening.**

Nine refusals were retired in one pass on that basis, having rested on a claim
about missing data that the data contradicted.

What is genuinely missing is content and multiplayer: group matchmaking and
friends, the SPT launcher's own routes, trader clothing, cultist recipes. And
one concurrency window is documented rather than closed — two writers on the
same item-event counter can still both read, both pass, and both write:
*"**that narrows the window and does not close it.**"*
