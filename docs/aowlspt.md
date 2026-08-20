---
repo: savannt/aowlspt
---

# aowlspt — a game modding platform, written in aowl

A modding pipeline for post-1.0 **Escape From Tarkov**, in aowl/nimony, front to
back: a native client host injected into the game, a backend server, an in-game
overlay, one C ABI, one build command — and a from-scratch Tarkov server
emulator written *as a mod on top of it*, using nothing a mod cannot use.

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

> **Private repo, public docs.** The code lives at `savannt/aowlspt` and is
> private. The build is **[$39, with a perpetual licence](/store/aowlspt)** —
> every update, three machines, and the mods. Questions first: Discord
> **timbuktu_guy**.

[[toc]]

---

## Why it is on this site

Every other page here documents a piece of the toolchain. This one documents
something the toolchain *built* — and it is the largest such thing, so it is
also the most direct answer available to "can you write a real program in
nimony." The numbers, measured 2026-08-19:

| | |
|---|---:|
| nimony source in the repository | **139,587 lines** across **202 modules** |
| of which: mods | 68,209 lines, 119 modules |
| of which: tooling (`aowl` and the gate binaries) | 34,194 lines, 24 modules |
| of which: hosts + backend + the mod library | 23,090 lines |
| header-only C, hand-written, under all of it | **12,855 lines** across 15 headers |
| documentation in the repository | 13,491 lines of Markdown |
| `aowl test`, end to end on a quiet tree | **143 checks, 0 errors** |

Every host, the backend, the installer, the build tool, the release tool, every
gate binary and every mod is nimony. **One C# program is left** —
`tools/SptReflect`, which reads SPT's assembly metadata and is managed because
the thing it reads is.

The case for reading it as a case study is on its [own page](aowlspt/case-study):
what the language made easy, what it made hard, what broke, and — the part that
matters most — the long list of things this project says it has **not** proven.

## What it is

Post-1.0 Tarkov changed the client's scripting backend. Pre-1.0 clients are
**Mono**: `Assembly-CSharp.dll` is an ordinary .NET assembly, BepInEx loads into
the Mono runtime, and Harmony patches methods by name. Post-1.0 clients are
**IL2CPP** — no managed assemblies at all, only `GameAssembly.dll` and
`global-metadata.dat`. Nothing built for one loads into the other, and the whole
existing modding ecosystem is built for the one that is gone.

The usual answer is to roll the client backwards to a pre-1.0 build. aowlspt's
installer refuses to do that, and `--force` does not enable it. So it does the
other thing: it hosts mods in the post-1.0 client directly, as a native DLL
driving IL2CPP's own exported C API, with no BepInEx, no Il2CppInterop, no
generated proxy assemblies and no second runtime in the process.

That decision is what shapes everything else. There is no managed layer to hide
in, so the reach into the game is **native x64 inline detours** and a **bound
method-pointer fast path** — and the price of every one of those is measured
rather than asserted.

## Map

| Page | Covers |
|---|---|
| [Architecture](aowlspt/architecture) | **Start here.** Three hosts, one ABI; how a mod is loaded, ticked and unloaded; where C stops and nimony starts. |
| [The C ABI](aowlspt/abi) | `abi/aowlspt_abi.h` — revision 5. The three exported symbols, `AowlHostApi`, `AowlModApi`, the size-watermark versioning rule, and the five design rules behind it. |
| [The mod API](aowlspt/api) | The nimony surface every mod imports: `aowlspt`, `aowlspt/game`, `aowlspt/server`, `aowlspt/json`, `aowlspt/fast`, `aowlspt/il2cpp`. The full reference. |
| [Reaching into IL2CPP](aowlspt/il2cpp) | The detour engine, the typed patch frame, the fast path — with the measured cost of each — and the import-table patch that got a real client to boot. |
| [The emulator](aowlspt/emulator) | A Tarkov server written as a mod. What it serves, what it refuses, and the generated coverage table that keeps both honest. |
| [Case study](aowlspt/case-study) | What this proves about nimony, the gate culture behind the numbers, and everything it does **not** prove. |

## The gate

```
aowl test
```

**143 checks, 0 errors**, measured end to end on a quiet tree on 2026-08-19 —
with `aowl.exe` rebuilt first, which matters, because the gate does not rebuild
itself and an earlier run that day silently used a binary predating every phase
it was meant to exercise.

Each of those checks is a named external step. Underneath them sit the suites,
each reporting its own count, each with a loopback port of its own so that none
of them can pass against a server somebody already had running:

| suite | checks | what it drives |
|---|---:|---|
| `soak`, 24 closed play cycles | 915 | the emulator over a long session, checked by invariant |
| `emutest` | 577 | the emulator through the client's boot sequence, against a fixture database |
| `livectl` | 213 | a mod disabled and re-enabled while the backend is serving |
| `realtest` | 168 (1 skipped) | the emulator against a **39.40 MiB** database imported from a real SPT install |
| `fuzzwire` | 152 | what the server does when the client is hostile |
| `sain` selftest | 124 | the rewritten bot decision layer, with no Tarkov under it |
| `framelen` | 102 | hostile `Content-Length` framing |
| `modclient` | 90 | the manager reading the client host's ledger |
| `firstrun` | 64 | a synthetic vanilla client → install → importdb → verify → boot → restart |
| `pttguard` | 62 | Path To Tarkov's graph against the real database |
| `wstest` | 62 | the notifier websocket: does a push reach the session |
| `hostharness` | 28 verdicts | the client host against a stand-in IL2CPP runtime |
| `ovsync` | 24 | the client host's poll actually reaching the backend |
| `tickfault` | 22 | a mod whose `on_update` fails |
| `ws_stall` | 15 | a websocket peer that stops reading |
| `aowl-coverage --check` | 12 | the coverage document against the code |
| `detour_race` | 11 | a patch installed under live callers |
| `storeguard` | 9 | a reader holding a key across a commit |

Two of those rows are worth more than their size. `hostharness` is counted as
**28 verdicts** and not by `grep -c '^ok'`, which answers 31 — three of those
lines are the harness reporting its own staging before it has read a line of the
host's log. And `storeguard`'s 9 is annotated with the fact that **2 of them
fail against the store as it was**, because a handle that never sees a change is
trivially never torn. That annotation is the house style, and it is the subject
of [the case study](aowlspt/case-study#a-check-nobody-has-seen-fail-is-an-opinion).

## The honest part, up front

> **`aowl test` runs the client host against `tests/mockil2cpp`, a stand-in that
> exports the same C API as `GameAssembly.dll`.** Resolve, call-with-arguments,
> live objects, fields and patching are all exercised for real against it. What
> that cannot establish is that BSG's implementation behaves identically. Every
> performance figure on these pages is measured against that stand-in.

Until 2026-08-19 the most repeated sentence in the repository was *"Nothing in
this repository has ever run against BSG's client. Not once."* — it appears at
the top of seven documents, all ten mod READMEs, the overlay README and the
module header of every client-side mod.

That sentence is now **partly** stale, and the correction is small and worth
stating precisely rather than rounding up. On 2026-08-19 a real post-1.0 client
was launched with the host injected. It got past BSG's own BattlEye service
check, the host reached `il2cpp_init`, and the game **crashed** — with a stack
in `Player.log` naming the exact frames. The crash was diagnosed and the cause
fixed the same day.

So: contact was established, and one bug that only a real client could have
produced was found and closed. **The game has not been shown to boot and play.**
The fifteen questions the backlog says one real session would settle are still
fifteen questions. Both halves of that are on the [case study](aowlspt/case-study#what-is-not-proven).
