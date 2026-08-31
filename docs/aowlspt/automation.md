# Automation

Driving the client without a human at the keyboard — launching it, navigating
its menus, entering and leaving a raid, proving that something happened, and
acting inside a raid.

::: warning This page has two halves, and they are at different maturities
The **existing automation surface** below is shipped and in daily use. The
**declarative automation library** and the **input actuation layer** are being
built right now; this page states what has landed and marks the rest UNKNOWN
rather than describing an intended design as though it existed.
:::

## Why automation exists here

The scarcest resource in this project is the human's attention. A change to
host code costs a build, a deploy, a launch, and — without automation — a
person watching a screen and reporting what they saw. That loop ran at roughly
ten minutes per single bit of information, and only if the needed log line had
been predicted in advance.

Everything below exists to collapse that loop.

## The existing surface

### The live inspector — asking the running client a question

The lowest-cost tool in the project. It queries the running client in
**seconds**, with no rebuild and no restart.

Commands are written to `aowlspt-inspect.txt` beside the host DLL; answers land
in `aowlspt-inspect-out.txt` and in the host log. The trigger is a **content
change**, so re-running an identical batch requires bumping a serial line.

| Area | Verbs |
| --- | --- |
| Memory | `read` / `write EXPR TYPE` (`i8`..`i64`, `u8`..`u64`, `f32`, `f64`, `ptr`, `bool`, `str`, `klass`) |
| Hierarchy | `roots`, `parent`, `children`, `tree`, `find`, `find more` |
| By displayed text | `findtext SUBSTR [ROOT] [BUDGET] [all]`, `findtext more` |
| Inspection | `dump`, `fields`, `component`, `rect`, `label`, `canvas`, `image` |
| Action | `click`, `invoke`, `call TARGET SIG [ARGS]`, `open`, `tab` |
| Session | `state`, `where`, `anchors`, `targets`, `help`, `echo` |
| Control flow | `let NAME EXPR`, `wait N`, `until EXPR [FRAMES]`, `allow write` |

Two flags gate it, in `aowlspt-host.json`: `liveInspector` for read-only access,
and `liveInspectorWrite` — **plus an `allow write` line inside the batch** —
for anything that writes or calls into game code.

::: tip `roots` is how you reach anything
The live UI lives in `DontDestroyOnLoad`, which `SceneManager` excludes by
design. See [Traps](./pitfalls#the-live-ui-is-not-in-any-scene-scenemanager-lists).
:::

Both `find` and `findtext` report **which** happened — `searched EXHAUSTIVELY`
versus `STOPPED EARLY` — because STOPPED EARLY is not proof a name is absent.
That is the [INCONCLUSIVE verdict](./method#three-outcomes-never-two) surfaced
in a tool.

### The scripted tools

| Tool | What it does |
| --- | --- |
| `tools/harness.py` | Launches the client and captures its log, with no human involved. |
| `tools/entergame.py` | Drives from launch to the main menu. |
| `tools/enterraid.py` | Drives from the main menu into an offline raid. |
| `tools/acceptance.py` | Replays a set of assertions against the live client — one command instead of fifteen minutes of manual checking. |
| `tools/inspector.py` | Programmatic access to the inspector channel, rather than hand-editing the command file. |
| `tools/toolcheck.py` | Replays recorded inspector cases against the live client, to catch the tool itself lying. |
| `tools/doctor.py` | Reports the state of the world — processes, deployed build, flags, index freshness, fault budget. |
| `tools/autoraid.ps1` | PowerShell entry point for the auto-raid loop. |

### The host-side automation flags

These drive the client from inside the host, without an external script. Full
detail, with defaults and read sites, is in the
[host flags reference](./reference/host-flags).

| Flag | Effect |
| --- | --- |
| `uxAutoRaid` | Automatically enter a raid after reaching the menu. |
| `autoRaidMap` | Which map `uxAutoRaid` selects. |
| `uxNativeRaid` | Native raid entry rather than driving the UI. |
| `uxNativeRaidDrive` | Drive the native raid-start path. |
| `uxSkipModeScreen` | Skip the mode selector on the way in. |
| `forceOfflinePractice` | Force offline practice mode. **Defaults on** — one of the `readBoolKeyDef` flags that `tools/hostcfg.py` misreports. |

### The one signal that means "in a raid"

The **raid-phase latch**. A raid-*entry* log line is not proof of raid *state* —
entry can be logged and the raid then fail to start. Any automation that waits
for a raid must read the latch.

## The declarative automation library

::: info Status: UNDER CONSTRUCTION — nothing has landed as of this writing
A declarative Nimony scripting and gear-minting layer is being built. No
commits exist on `feat-automation-lib` beyond its branch point, so this section
deliberately documents **nothing**: describing an intended API as though it
shipped is exactly the failure this documentation is built to avoid.

When it lands, this section will document its script grammar, its gear-minting
verbs, its failure modes, and its verdict lines — generated from source where
the shape allows.
:::

## In-raid input actuation

::: info Status: UNDER CONSTRUCTION — nothing has landed as of this writing
A layer for actuating input inside a raid — as distinct from the menu
navigation the inspector already does — is being built in parallel. It is not
yet present in the tree.
:::

## Rules for anything automated here

These are not stylistic. Each is written against an incident.

**Drive off state, never off a fixed sleep.** Ask the client where it is with
`state` / `until`, rather than sleeping and hoping. Timings that worked once
have failed on a slower load every time they have been relied upon.

**Beware the false crash.** The client takes **over 60 seconds** to reach
profile-select and then waits indefinitely for a human. A process check at 20
seconds reads "gone" because it has not spawned yet, and an idle game is
indistinguishable from a hung one. Before declaring a crash: wait 90 seconds or
more, confirm the host log actually **stopped progressing**, and read the
client's own logs.

**An inactive control is not pressable.** Pressing one returns success and does
nothing. Check `activeInHierarchy` before pressing, and treat a hit on an
inactive node as [INCONCLUSIVE](./method#three-outcomes-never-two).

**Never take a screenshot to find something out.** It is the most expensive
action available, and the inspector exists to replace it. Reserve screen capture
for questions that are genuinely visual and that no field read can answer — and
say why.

**Deployment is serialised through one place.** Automation builds, verifies, and
reports an artifact path. It does not deploy and it does not start or stop the
game: a human may be playing, several agents may be building concurrently, and
every deploy must verify markers first.
