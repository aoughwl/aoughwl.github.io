---
title: The manual
---

# The manual — aowlspt's own documents

::: danger This section is an archive
aowlspt is finished. It was folded into **[Jester](/docs/jester)**, and nothing
here is maintained. It is kept because the work is precise and the answers were
expensive to get.
:::

The 63 documents below are the aowlspt repository's own `docs/` directory,
published as it stands. They are not tutorials. They were written by and for
people with the checkout open — an ABI reference, RVA tables resolved offline
against a specific build, coverage audits, boot-flow maps, decision records —
and they say what was measured, with the instrument that measured it, rather
than what would read well.

The pages above this one, starting at
[Installation](/docs/aowlspt/installation), are the reader-facing account of the
same system. **Start there.** Come here when you want the working notes behind a
sentence on one of those pages.

::: tip Reading these
- Each page names its source file and links to it on GitHub. Paths in the prose
  — `abi/aowlspt_net.h`, `mods/tarkov/tarkov.nim` — are links to the real file.
- A handful of documents cite other documents that were **held back from
  publication**. Those references go nowhere; that is deliberate.
- Several pages describe designs that were never built, or work that was
  switched off before 1.0. Every one of those carries a banner saying so.
- Where a page here and a page above disagree, check the dates. These were
  written as the work happened; the reader-facing pages were written after.
- The repository is [aoughwl/aowlspt](https://github.com/aoughwl/aowlspt), under the
  [PolyForm Noncommercial License 1.0.0](https://github.com/aoughwl/aowlspt/blob/main/LICENSE).
:::

## The system

| | |
|---|---|
| [The shape of aowlspt](./architecture) |  |
| [The C ABI](./abi) |  |
| [The wire format](./wire) |  |
| [Mod-to-mod capabilities](./capabilities) | How one mod offers a named service and another mod finds and calls it, server-side, without either one knowing the other exists. |
| [Three gaps in the mod API](./api-gaps) | Three features `mods/pathtotarkov` wanted and the mod API could not express, each written up as a fix with its cost. |

## The client host — IL2CPP

| | |
|---|---|
| [The post-1.0 client host](./il2cpp) | Predates the token-gate discovery |
| [Decrypting global-metadata.dat](./metadata-decrypt) |  |
| [The interaction layer](./interaction-layer-map) | The complete map of the seam where the host touches the running client — the layer every crash of early September came out of. |
| [The client boot flow](./boot-flow-map) |  |
| [Getting past character-select](./autoenter) | Who answers Tarkov's character/mode screen when the game starts — the host, natively, rather than the launcher driving the UI. |
| [Actuating the local player](./player-actuation) |  |
| [Starting an offline raid natively](./native-raid-start) |  |
| [Native menu-screen navigation](./native-screen-nav) |  |

## Offline recon — RVA and screen maps

| | |
|---|---|
| [The main-menu UI map](./ui-map) |  |
| [The settings screen map](./settings-ui-map) |  |
| [The auto-raid flows](./autoraid-map) |  |
| [The reload / magazine-load path](./ammo-loading-map) |  |
| [The post-processing map](./native-postfx-map) | Map only — nothing implements it |
| [FOV — static RVAs](./fov-rva) |  |
| [SAIN driver — the RVA table](./sain-rva) | The byte-verified static address table that let the bot driver stop resolving game methods by name at runtime. |
| [Voice — offline IL2CPP archaeology](./voice-rva) |  |
| [The audio path, resolved offline](./audioray-rva) | The second half of the raytraced-audio track: the addresses in the client's own audio path that a computed occlusion gain… |

## The backend and the emulator

| | |
|---|---|
| [The backend](./backend) |  |
| [The emulator](./emulator) |  |
| [Emulator coverage](./emulator-coverage) | The gap list for the emulator: every operation the real client can ask for, and whether this backend answers it. |
| [Every refusal, re-audited](./emulator-refusals) | Every place the emulator deliberately declines to answer, taken back to the database and re-checked to see whether the reason… |
| [Importing a real database](./importdb) |  |
| [The pre-1.0 database against post-1.0](./post1-data-delta) |  |
| [Loot configuration](./loot-config) |  |
| [The backend, made fast](./perf-server) |  |

## Writing mods

| | |
|---|---|
| [Writing a mod](./modding) |  |
| [Getting a new mod to stay loaded](./mod-enable-path) |  |
| [Changing the mod set while everything runs](./modmanager) |  |
| [Mod Settings API — design](./mod-settings-api) | Design only — never built |
| [What a mod may do on the load path](./mod-perf) | The budget for what a mod may do while the game is loading, with the measurement behind each rule. |
| [What a client-side call costs](./perf) |  |
| [Debugging a native mod](./debugging) |  |
| [The in-game debug overlay](./debug-overlay) |  |

## UI and settings

| | |
|---|---|
| [In-game settings and the config schema](./settings) | Partly superseded |
| [The settings UI API](./ui-api) |  |
| [UIHOOKS — subscribe to a screen](./uihooks) |  |
| [Native Unity UI from a mod](./native-ui) |  |
| [nativetabs — one declarative call](./nativetabs) |  |
| [Native settings controls](./native-controls) |  |
| [Shelved: native in-game settings](./shelved-native-settings) | Why the in-game settings work was switched off before 1.0, and exactly what is left to finish if anyone picks it up. |

## Bots

| | |
|---|---|
| [Bot navigation — IL2CPP recon](./botnav) |  |
| [SPT 4.1.5 bot control](./spt415-bot-control) | A separate study: driving bot spawns in a stock, pre-1.0 SPT 4.1.5 install from the same backend. Different client, different… |
| [Squad-shared objectives](./bot-ai-objectives) | A design for giving a bot squad one shared objective instead of per-bot goals. Never built. |

## Automation and the inspector

| | |
|---|---|
| [The automation library](./automation-library) | Superseded by the API reference |
| [The automation library — API reference](./automation-api) | The current shape of the library |
| [The live inspector — verb reference](./inspector-verbs) |  |
| [The live inspector as a product](./inspector-product) |  |
| [Headless and unattended running](./headless) | Whether the game client can be run without a screen or a person — asked, measured, and answered no, with what is possible instead. |

## Graphics and content

| | |
|---|---|
| [DLSS on this install](./dlss) | One machine, one day |
| [DLSS-NR on this install](./dlssnr) | One machine, one day |
| [Ripping and re-importing the maps](./map-rip-and-reimport) | Research, not a pipeline anyone ran here |
| [Importing all maps into one Unity scene](./unity-map-import) | Research, not a pipeline anyone ran here |
| [Port plan — ammo loading animations](./port-ammo-loading-animations) | A port plan |

## Shipping it

| | |
|---|---|
| [Installing](./install) |  |
| [Distribution — the final build](./distribution) | Design pass |
| [Beta distribution and IP protection](./beta-distribution) | The design for a free public beta and the licence gate behind it. |
| [1.0 release readiness](./release-readiness) | A read-only audit of what was and was not ready at 1.0. Nothing was built or run in this pass; that is the point of it. |

## The record

| | |
|---|---|
| [Backlog — everything not done](./backlog) | The unfinished list, frozen |

---

Every page here is one file in [`docs/`](https://github.com/aoughwl/aowlspt/tree/main/docs). If a page you
expected is missing, it was withheld rather than lost.
