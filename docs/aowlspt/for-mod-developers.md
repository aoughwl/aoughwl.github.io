# For mod developers

Mods are native libraries. A mod exports three C functions, is loaded by a host,
and reaches the game or the server through one small C ABI — no BepInEx, no
Harmony, no managed runtime. The ones that ship with aowlspt are written in
nimony.

[[toc]]

## The shortest path to a running mod

```
aowl doctor          # nimony, gcc, lld, the headers, and PATH order
aowl run examples/hello
```

`aowl run` builds the mod and loads it into **`aowlspt-sim`** — a host with no
game and no server behind it. That takes about a second, which is the whole
point: you do not launch Tarkov to find out that your JSON is wrong.

Leave `aowlspt-sim --watch` open and it reloads the library whenever you rebuild
it. (Reload-on-change is the simulator's facility; the backend and the client
host do not watch anything, though all three can unload a mod.)

## What a mod looks like

```nim
import aowlspt
import aowlspt/game

var Player = gameType("EFT.Player")
var world = whenReady("EFT.GameWorld")

proc onUpdate(elapsedMs: int64): Status =
  if world.ready():                      # true once, when the game exists
    info "health " & $Player.get("Health").asFloat()
    discard Player.invoke("Heal", 50)

    discard hookArgs("EFT.Player::ApplyDamage",
      proc (target, args: string): HookResult =
        info "damage: " & args           # the arguments the game passed
        stopWith("0.0"))                 # and the original never runs
  Ok

exportMod(guid = "you.mod", name = "Mod", author = "you", version = "1.0.0",
          sptRange = "*", sides = {sideClient}, onUpdate = onUpdate)
```

Nothing here names a game type at build time. The database is addressed by
dotted path and the game is reached by string target, which is why a point
release that renames types does not break the ABI.

## What a mod can do

A capability a host does not have returns `ErrUnsupported` rather than
misbehaving, so `side()` guards are the normal way to write a mod that ships
everywhere.

- **Backend**: routes, the database (`dbGet`/`dbPatch`, which *merges* and
  creates paths that are not there), the notifier websocket.
- **Client**: `resolve`/`call` on any type and method, live objects as handles,
  fields by name, hooks (`hook`, `hookArgs`, `hookReturn`, and the typed
  variants for the per-frame path), and `aowlspt/fast` for the bind-once path.
- **All three hosts**: logging, events, config, timers, and a persistent store.

## In-game settings

Declare your mod's settings once and the F12 page draws the right control for
each value, persists the edit back to your `config.json`, and hot-applies it
where you support that. See [Configuration](/docs/aowlspt/configuration) for the
player-facing side.

## Publishing a mod

Add it to `registry/mods.json` — that is the index every install reads, and the
lists that select sets of mods are documents in the same file. `aowl-regcheck`
checks the registry against the mods it claims to describe, and `aowl release`
refuses to build unless every mod the registry names has a library staged and
named after its directory.

```
aowl release --mod sway
```

## Reference

| | |
|---|---|
| [The mod API](/docs/aowlspt/api) | The full nimony surface: `aowlspt`, `aowlspt/game`, `aowlspt/server`, `aowlspt/json`, `aowlspt/fast`, `aowlspt/il2cpp`. |
| [The C ABI](/docs/aowlspt/abi) | The contract every host implements, and the decisions behind it. |
| [Architecture](/docs/aowlspt/architecture) | The hosts, where C stops and nimony starts, a request and a hook end to end. |
| [Reaching into IL2CPP](/docs/aowlspt/il2cpp) | What the client host actually does, what each path costs, and what it refuses. |
| [The game server](/docs/aowlspt/emulator) | The Tarkov server, written as a mod on the same public API. |

Worked examples live in `examples/`: `hello` (the plumbing end to end),
`clientprobe` and `highlevel` (reaching into a post-1.0 client, raw and typed),
`backend` and `gameserver` (routes, database, config), and `lesson` — every part
of the API in the order a mod needs it.
