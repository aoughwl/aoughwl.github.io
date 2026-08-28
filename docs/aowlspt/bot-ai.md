# Bot AI

**Bot AI** is the mod that replaces Tarkov's stock enemy behaviour: layered
decisions, per-bot personalities, real cover use, searching that looks like
searching, and squads that behave like squads. To the player it is one thing —
one entry in the mod list, one tab in the settings screen. Underneath it is a
family: a decision driver with three policy layers folded into it, each of which
began life as a separate mod and none of which ships as one.

[[toc]]

---

## One mod, one tab, a nested family

Every other bot mod on the scene is a mod of its own. Here they are one, and the
registry says so: the parent is `aowl.sain`, named **Bot AI**, and its layers
declare `parent: aowl.sain`, so the settings screen draws them as sub-pages
under a single Bot AI tab rather than as four competing entries.

| piece | registry id | what it is | where it shows |
|---|---|---|---|
| **Bot AI** | `aowl.sain` | the per-bot decision driver — the brain each AI thinks with | its own tab |
| **Population** | `aowl.morebots` | how many bots a map runs, and the bot-type/faction API other mods register against | `Bot AI › Population` |
| **Waypoints** | `aowl.waypoints` | the patrol graph the movement layer walks between fights | folds in under Bot AI |
| **ORBIT** | — folded, no id | where on the map bots *want* to be, and how a squad encircles | folded in two places (below) |

`aowl.morebots` and `aowl.waypoints` are marked `internal` in the registry: they
are not strays and not separate products, so the mod manager keeps them off the
player list while still keying deploy verification and the selection store off
their guids. ORBIT is not in the registry at all, because it is not a binary you
load — it is behaviour compiled into the two mods that already ship.

## How the layers fold together

The design started as four SPT mods that each did their own thing. Ported
straight across they would be four things fighting over the same bot objects,
four offset tables to invalidate on every Tarkov update, and four places a bad
read kills the client. Folded, they are **one guarded driver reading a single
shared GameWorld gate, with the others as policy layers over it** — which is the
whole reason to do it this way rather than shipping four racing ports.

```
                         Bot AI  (aowl.sain)
              the driver: decide → actuate, at 10 Hz, per bot
                                  │
   ┌──────────────┬──────────────┼──────────────┬──────────────┐
   │              │              │              │              │
Population      Waypoints       ORBIT          ORBIT         botnav
(morebots)    (patrol graph)  (per-bot flank) (map policy)  (shared API)
how many /    where to        core/flank.nim  emu/orbit.nim  the channel
where they    patrol between   — the squad     — where on the the driver and
spawn         fights           encircle order  map to want    waypoints share
```

**Bot AI is the driver.** `core/decide.nim` runs one priority cascade — self-care
above squad above solo combat — and emits three simultaneous outputs per bot at
10 Hz. Everything else is a layer that feeds or steers that loop.

**Population decides how many and where.** It raises a map's bot cap, per-zone
limit and scav-wave slots from a stock baseline, and it is the bot-type and
faction API that mods like Black Division register against. It loads before the
driver, so the driver is deciding for the bots Population put on the map.

**Waypoints supplies the patrol graph.** Ten maps of patrol geometry — zones and
patrol routes — served from the backend, so a bot with nothing to fight has
somewhere to walk that is not a straight line to the nearest wall. The driver's
movement layer walks that graph; Waypoints is the data behind it.

**ORBIT is folded in two places, and is a standalone mod in neither.** ORBIT's
idea is that bots should have somewhere on the map they *want* to be, and that a
squad should converge on a target from more than one angle. Post-1.0 that splits
cleanly along the thread boundary:

- **the map-level half** — *where on this map should bots want to be* — is a
  server-side spawn and AI policy in `mods/tarkov/emu/orbit.nim`. It re-derives
  ORBIT's cell grid, anchor and coverage roll from `db.json`, which the backend
  already owns, instead of from a scene scan the client cannot do.
- **the per-bot half** — *how does this bot encircle right now* — is the flank
  order the driver issues in `mods/sain/core/flank.nim`: step off the direct
  bearing by a fixed radius, on the side the bot is already displaced towards and
  *away from the nearest squadmate*, so two bots of a squad go opposite ways. A
  pincer that falls out of one dot product, with no communication at all.

The two halves talk over **`botnav`**, the navigation channel Bot AI and
Waypoints share: the map policy publishes where bots should orbit, the driver
turns that into a destination per bot, and the game's own pathing takes it from
there.

## Why the decision loop reaches bots the way it does

Post-1.0 Escape From Tarkov is IL2CPP. There is no BepInEx to load into, no
Harmony to patch, and no managed assembly to reflect over — and on this build,
resolving a game name and then *calling, binding or patching it* by name is fatal
the moment it is used, not at load. So Bot AI does not reach the game that way.

The driver reads its bots through a **single shared GameWorld gate** the host
already fills, and reads their state at **field offsets measured offline** — each
read guarded so a stale offset comes back as a zero rather than a crash. Where it
must actuate — move, sprint, look, shoot — it calls the game's real methods at
**byte-verified static addresses**, the one path that is unaffected by the
by-name hazard. A binding it cannot verify is *refused*, with a reason in the
log and a defaulted value, never a wrong number pushed into a live raid.

That is also the second reason the family is one mod. One shared gate, one offset
table, one guarded reader — not four of each. A Tarkov update moves offsets once,
and one mod re-measures them; four ports would each break, separately, in four
ways. The depth of how the host reaches into IL2CPP, the guard pattern and the
calling convention are in
[Reaching into IL2CPP](/docs/aowlspt/il2cpp) and
[Architecture](/docs/aowlspt/architecture).

## What the driver actually decides

The decision loop is a from-scratch rewrite of the design SAIN
(Solarint, maintained by ArchangelWTF) established for pre-1.0 Tarkov — the
design, against a native ABI, not a translation of the C#. What it drives:

- **Layered decisions.** Self-care over squad over solo combat, one cascade,
  three simultaneous outputs — a movement goal, an aim goal, and a fire decision.
- **Per-bot personality.** Eight personalities resolved once at spawn into a flat
  set of thresholds, so the ladder then compares plain numbers.
- **Difficulty as perception.** Difficulty moves acquisition rate, reaction delay,
  hearing acuity and how long a target must be seen — not the behaviour itself.
- **Search that looks like searching.** A state machine over a last-known place:
  go there, look around, push in the direction they went, guess the flank, sweep
  the uncertainty circle, give up. The circle *widens with age*, so an old
  contact is searched, not pointed at.
- **Awareness, not omniscience.** A clear line of sight is not instant knowledge.
  Awareness ramps with distance, angle and motion and bleeds away when the line
  is lost, so the frame you clear a doorway thirty bots do not all know at once.
- **Suppression as a quantity.** An accumulator with two thresholds — merely
  suppressed, versus pinned — held for a minimum dwell, rather than a bool that
  clears the instant fire stops.
- **Cover use.** Scoring, dwell hysteresis, path-failure counting, and an
  in/near/far banding, fed by a raycast sampler that runs on Unity's thread and
  merges its answers back into each bot's cover set a tick later.
- **Squads.** Help, regroup, spread out, hold, suppress, surround, bounding
  retreat — read over the table of every bot in the raid the scheduler already
  keeps, partitioned into real groups by one cheap pointer comparison.

Bot AI is deliberately honest about which of these depend on a game signal it can
already read versus one it cannot yet reach — the central bet of the rewrite is
that a model of its own, actuated through a few reliable calls, outlives a client
patch better than one leaning on twenty guessed member names. The mod prints a
binding report once at load; that report is the thing to read before drawing any
conclusion about behaviour in a given raid.

## Configuration

Everything is one settings surface, folded under the single **Bot AI** tab in
Tarkov's own settings screen and edited while the game runs:

| surface | what it exposes |
|---|---|
| **Bot AI** | difficulty, aggression, hearing and vision acuity, personality mix, cover and search behaviour |
| **Bot AI › Population** | how many bots a map runs — overall cap, per-zone limit, scav-wave slots |
| patrol behaviour | how bots move between fights, over the Waypoints patrol graph |

Edits persist back to each layer's `config.json` the same way every other mod's
do. The full story of the settings pages, where each file lives, and how a change
made in-game reaches the running mod is on
[Configuration](/docs/aowlspt/configuration).

## Where to go next

| | |
|---|---|
| [Mods](/docs/aowlspt/mods) | Bot AI beside every other mod that ships, and the mod lists that turn the bots up. |
| [Configuration](/docs/aowlspt/configuration) | The in-game settings pages and the `config.json` behind them. |
| [Reaching into IL2CPP](/docs/aowlspt/il2cpp) | Why by-name is fatal, and the byte-verified path the driver uses instead. |
| [Architecture](/docs/aowlspt/architecture) | The hosts, the guard pattern, and the shared GameWorld gate. |
