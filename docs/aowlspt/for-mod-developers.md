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

Declare your mod's settings once, in code, next to the handler that reads them.
They are then drawn as **real Tarkov controls** in the **MODS** tab of the
game's own settings screen — your mod gets a subtab — and an edit is persisted
back to your `config.json` and hot-applied where you support that.

```nim
import aowlspt/settings

proc onLoad(): Status =
  loadConfig()
  declareSettings(@[
    floatSetting("opticFovMulti", "Optic FOV multiplier", 1.0,
                 lo = 0.5, hi = 2.0, step = 0.01, category = "FOV",
                 description = "FOV scale while aiming a magnified sight"),
    boolSetting("changeMouseSensitivity", "Scale mouse sensitivity", true,
                category = "Sensitivity"),
    keybindSetting("zoomToggleKey", "Toggle-zoom key", "M",
                   category = "Toggle zoom", implemented = false,
                   description = "Read but not wired yet")])
  Ok
```

The declaration is pure data — a mod that declares a schema and does nothing
else is still a no-op mod. `category` groups rows into sections on your subtab;
`implemented = false` draws the row greyed with your reason next to it, which is
how a half-ported capability stays honest instead of shipping a control that
does nothing.

**If you are coming from BepInEx**, this replaces the `ConfigEntry` /
ConfigurationManager / F12-overlay pattern. There is no overlay and no separate
config window: you declare the schema, and the settings live where a player
already looks for settings. Nine of the mods that ship with aowlspt already use
it.

See [`aowlspt/settings`](/docs/aowlspt/api) for the full surface, and
[Configuration](/docs/aowlspt/configuration) for the player-facing side.

## Debugging a running client

Alongside the simulator there is a **live inspector** — a diagnostics tool that
queries the game client while it is running, so you can ask what a screen
actually contains, or what a value actually is, without a rebuild-and-relaunch
cycle for every question. It is a developer tool and is off unless you turn it
on in `aowlspt-host.json`.

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
