# Installation

From the Tarkov install your official launcher maintains to a modded one you can
play, in five steps.

[[toc]]

## Before you start

- A **post-1.0** Escape From Tarkov install (1.0.0 or later). Pre-1.0 clients
  are Mono and are not supported; they cannot be made supported. See the
  [FAQ](/docs/aowlspt/faq).
- **An SPT install**, to import the game's item/trader/quest/map data from.
  Without it the server runs and the game is empty.
- About **1 GB** free on the same volume as your Tarkov install. Not 78 GB — the
  asset bundles are hard linked, not copied.
- **Windows.** No .NET runtime, no PowerShell, no Python needed to install.

**Your existing install is only ever read.** Everything is built in a second
directory. If any of this goes wrong, delete that directory; the install your
launcher maintains is untouched and still updatable.

From an extracted `aowlspt-<version>.zip` the tools are in `install\` and the
payload is already built. Commands below are written that way; if you are
building from a source tree the tools are in `installer\build\` and there is one
extra step (see *Building the payload yourself*, below).

## 1. Check your client

```
install\aowlspt-install.exe detect
```

```
  root      D:\Games\Tarkov
  version   1.1.0.46777
  backend   IL2CPP
  suitable  yes — this is a post-1.0 client
```

Write the **version** down. `detect` searches the usual places; pass a path if
your install is somewhere unusual.

## 2. Preview, then install

```
install\aowlspt-install.exe plan ^
    --source D:\Games\Tarkov --target D:\Aowlspt --payload payload
```

`plan` prints the client it found, the payload it loaded, every objection it
has, and the list of steps — and does nothing. That list is not an approximation
of what `install` does; it is the same list, executed.

```
install\aowlspt-install.exe install ^
    --source D:\Games\Tarkov --target D:\Aowlspt --payload payload
```

`--target` must be a new directory beside the source — not inside it. It asks
once; `--yes` skips the question.

This takes seconds, because the ~77 GB of asset bundles nothing ever writes to
are hard linked. Everything a patcher could plausibly rewrite is copied even so.
`--copy` turns linking off entirely.

What lands in `D:\Aowlspt`:

```
D:\Aowlspt\
  EscapeFromTarkov.exe          copied
  EscapeFromTarkov_Data\        mostly hard linked
  aowlspt\                      everything this project owns
    aowlspt-launch.exe          what you start
    aowlspt-backend.exe         the server
    aowlspt-host-il2cpp.dll     the host that goes into the client
    backend.json                where the client looks for the backend
    mods\<name>\<name>.dll      each mod, with its config.json and data\
    registry\mods.json
  aowlspt-install.txt           what was created, for uninstall
```

BattlEye and `ConsistencyInfo` are deliberately not carried across.

Useful flags:

| flag | what it does |
|---|---|
| `--list ID` | picks the mod list a fresh install starts with. Default `aowl.list.vanillaplus` (the feel mods); `aowl.list.raidnight` turns the bot population up and adds the AI and faction mods. |
| `--overlay` | rewrites only the payload into a target that already has a client. |
| `--dry-run` | prints every step and executes none. |
| `--copy` | copy instead of hard linking. |

## 3. Import the game's data

**Not optional, and not part of the installer.** Everything above produces a
complete, verifiable, *empty* server: it answers every route the client asks and
has no items, traders, quests or maps in any of them.

```
install\aowl-importdb.exe --from D:\SPT --out D:\Aowlspt\aowlspt
```

About three seconds and 39 MiB later there is a `db.json` where the backend
looks for it. **`--out` is the `aowlspt\` directory inside the install, not the
install root** — one level up and the server comes up on its fallbacks with
nothing saying why. The SPT install is opened read-only.

## 4. Verify

```
install\aowlspt-verify.exe --root D:\Aowlspt
```

It checks the client is post-1.0 and IL2CPP, that the host, launcher and backend
are present, that **every mod directory actually holds a library**, that the
registry went in — and then starts the backend on a spare port, asks it the
first questions the client asks, and stops it again.

The check count moves as mods are added, so read the failures and the warnings
rather than the number. **The warnings are the interesting part**: a missing
`db.json` is a warning, not an error — the install is not broken and there is no
game in it, and those are two different sentences.

## 5. Play

```
D:\Aowlspt\aowlspt\aowlspt-launch.exe
```

→ [Getting started](/docs/aowlspt/getting-started) for what happens next.

## Building the payload yourself

If you have a source tree rather than a release archive, build the payload
before step 2:

```
installer\build\aowl.exe build
installer\build\aowl.exe payload
copy installer\payload\payload.json.template installer\payload\payload.json
```

Then set `targetTarkovVersion` in `payload.json` to the version `detect`
printed. `payload.json` is per-machine and is not in the repository.

**Read the exit codes.** `aowl build` exits 1 if any mod fails to compile, and
`aowl payload` refuses to stage a mod with no library, or a payload missing the
client host, the backend or the launcher.

## Adding mods to an install you already have

Install again with a payload containing only `aowlspt/` and no `--source`. It
becomes an overlay that owns only what it added, and nothing re-links forty
thousand files.

## Uninstalling

```
install\aowlspt-install.exe uninstall --target D:\Aowlspt
```

It is driven by the manifest the install wrote, so it removes exactly what was
created. Your original install was never touched.
