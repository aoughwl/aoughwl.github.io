# Architecture

A **mod** is a native `.dll` that exports three C functions. A **host** is
whatever loads it. Both sides are nimony; the seam between them is C, and it is
one header.

[[toc]]

---

## Three hosts, one contract

```
                       abi/aowlspt_abi.h
                     the one contract, C only
                               |
        +----------------------+----------------------+
        |                      |                      |
  aowlspt-backend      Aowlspt.Host.Il2Cpp      aowlspt-sim
  (nimony process)     (nimony DLL, injected)   (nimony, no game)
        |                      |                      |
   routes, db,          resolve/call, hooks,      routes, db, store,
   store, events        fast path, store          events; refuses the rest
        |                      |
  mods/tarkov            mods/sway, fov,
  mods/manager           classicmovement,
  (server side)          sain, perf, ...
                         (client side)

  the game client  <--HTTP, zlib both ways-->  aowlspt-backend
```

|  | `aowlspt-backend` | `Aowlspt.Host.Il2Cpp` | `aowlspt-sim` |
|---|---|---|---|
| where it lives | its own process | injected into `EscapeFromTarkov.exe` | its own process |
| `route_register`, `db_get` / `db_patch` | yes | `ErrUnsupported` | yes (`--db`) |
| `resolve` | `ErrUnsupported` | yes, by name, against IL2CPP | a name, no runtime behind it |
| `call` | `ErrUnsupported` | yes, by name, against IL2CPP | canned from `--stubs`, else refused |
| `patch` / `patch_typed` | `ErrUnsupported` | yes, x64 inline detour | `ErrUnsupported` |
| `handle_pointer` / `handle_pin` | filled, refusing | yes | filled, refusing |
| `notify_push` | yes | — | — |
| `store_get` / `_set` / `_list` | yes | yes | yes |
| events, timers, config, log | yes | yes | yes |
| reload one mod on a file change | no | no | yes (`--watch`) |
| unload one mod live | yes | yes | yes |
| `AowlHostApi.size` watermark | rev 5 (224) | rev 4 (216) | rev 4 (216) |

**The backend cannot reflect and cannot patch** — there is no managed runtime
and no compiled game code in its process to reflect into or detour. **The client
host cannot serve routes or read the database** — those are the server's.
Neither is a gap waiting to be filled; each is the honest answer for that
process, and each returns `AOWLSPT_ERR_UNSUPPORTED` rather than misbehaving. A
`side()` guard is the ordinary way to write a mod that ships everywhere.

`aowlspt-sim` exists so that the edit loop is a second rather than several
minutes:

```
aowl run examples/hello
```

Leave `aowlspt-sim --watch` open, edit, save, rebuild — the running mod is
unloaded and the new binary loaded in its place, without restarting the
simulator. It loads mods through the same `host/common/modhost.nim` the other
two use and answers `store_*` out of the same `host/common/modstore.nim` the
backend writes profiles with, so a mod that persists anything can be simulated
at all.

## The size watermark, and why a mod must not read the revision

The row a mod reads is `AowlHostApi.size`, **not** `AowlHostInfo.abi_revision`.
The revision field is `AOWLSPT_ABI_REVISION` from the header the host was
compiled with, and is therefore 5 on all three hosts. `size` answers the
question a mod is actually asking: *how much of this struct did you fill*.

`aowl_hostapi_new` (`abi/aowlspt_shim.h`) builds the block for every nimony host
and reports the revision-2 size — 192, the last boundary every host can honour
with nothing but its own process. Each host then arms only the part it owns, and
the two real hosts own disjoint parts:

- the client host calls `aowl_hostapi_arm_live` then `aowl_hostapi_arm_typed`
  (`abi/aowlspt_live.h`, which only it includes) to publish `handle_pointer`,
  `handle_pin` and `patch_typed` for real, ending at **216**;
- the backend calls `aowl_hostapi_arm_notify` (`abi/aowlspt_notify.h`, which
  only it includes) to publish `notify_push` — and because it must raise `size`
  past three entries it *cannot* honour, it installs refusing stubs for those
  three first, ending at **224**.

In all three the ordering is the invariant: **the pointers go in first and
`size` rises last**, so the watermark is never larger than the part of the
struct that has been filled. And because the gaps are filled with refusals
rather than nulls, a capability test means *"there is a function here that will
answer"* and never *"the answer is yes"* — which is all a null check could ever
have established either.

## Where C stops and nimony starts

Almost everything is nimony. C appears in exactly the places nimony cannot
reach, and each of those is one header under `abi/` — **12,855 lines across 15
headers**, against 138,170 lines of nimony.

| header | lines | what it is, and why it is C |
|---|---:|---|
| `aowlspt_abi.h` | 677 | the contract itself — C because it is the thing two languages have to agree on |
| `aowlspt_shim.h` | 790 | the indirect calls nimony cannot express; it refuses to `cast` between a `pointer` and a `proc` |
| `aowlspt_fast.h` | 471 | **189 call trampolines**. Calling an IL2CPP-compiled method directly is a function-pointer call *with the right type*, and C needs that type at compile time while a mod only knows it at bind time — so the space is enumerated. On Win64 a parameter's type only decides which register file it lands in, which collapses to two kinds per slot, five slots, three return forms. |
| `aowlspt_detour.h` | 1,885 | the x64 inline-detour engine: a length decoder, a trampoline, and **one** assembly thunk shared by all 256 hook slots. Hand-written assembly is not something nimony emits. |
| `aowlspt_frame.h` | 645 | the typed patch frame — a struct rather than accessor function pointers, because it is read inside a method the game may run per entity per frame |
| `aowlspt_net.h` | 2,479 | the backend's sockets: `WSAPoll`, the connection table, zlib, the per-session lock table, websocket frame boundaries. The websocket *handshake* is not here — that is SHA-1 and base64, which nimony ships. |
| `aowlspt_overlay.h` | 4,619 | the in-game panel, drawn from a detour on `IDXGISwapChain::Present`. Header-only C, D3D11. |
| `aowlspt_inject.h` | 306 | starting the game suspended, `LoadLibrary` in the remote process, resuming |
| `aowlspt_iat.h` · `aowlspt_beguard.h` | 161 · 225 | reading an already-mapped PE's import descriptors, and the one use of it — see [Reaching into IL2CPP](il2cpp#getting-a-real-client-to-boot) |
| `aowlspt_live.h` · `aowlspt_notify.h` · `aowlspt_hostboot.h` · `aowlspt_lock.h` · `aowlspt_il2cppready.h` | 139 · 104 · 73 · 82 · 199 | arming the late `AowlHostApi` entries, `DllMain` and the boot thread, the process lock, the runtime-present probe |

That table is the honest shape of "written in nimony": a systems program with a
hand-written C floor, where every plank in that floor exists because of a
specific thing the language does not do.

## A mod's life

```
LoadLibrary
  ├─ aowlspt_abi_version()   → uint32. The cheapest possible probe. A major
  │                            mismatch is refused here, without running mod code.
  ├─ aowlspt_describe(&info) → guid, name, author, version, spt_range, sides,
  │                            flags. Called before init, so it must not depend
  │                            on host services.
  └─ aowlspt_init(host, &api)→ the mod stores `host` and hands back its
                               on_load / on_update / on_unload
  on_load()                    once the host is ready to serve
  on_update(elapsed_ms)        periodic tick
  ...
  on_unload()                  the mod stops its own threads. It deregisters
                               nothing — the host drops every registration itself.
  teardown                     routes, subscriptions, timers, detours
  FreeLibrary
```

The ordering at the end is the whole of the danger. A route still in the table
after the library is freed is a call into unmapped memory on the next request —
so `unloadOne` **refuses outright** unless a teardown has been registered, and
all three hosts register one before they load a single mod.

That is what live mod control is built on: `mods/manager` speaks a control
protocol over the event channel to `host/common/modcontrol.nim`, so a mod can be
enabled or disabled **while the server is serving**, and on the client while the
game is running. `aowl test` proves the server half every run — `livectl`
disables a mod on a live backend, checks its routes are gone from the router
while the mods beside it keep answering, enables it again, and checks the mod
that came back is a fresh instance.

The client half — whether a detour comes back out cleanly on unload — is named
in the backlog as *"the failure mode this whole design is arranged around, and
the one with the least evidence behind it."*

## The server

`aowlspt-backend` is a poller and sixteen workers with a lock per session
(`abi/aowlspt_net.h`). It speaks the client's wire framing — **every request
body arrives through a zlib stream**, because the real client always compresses
— which has a practical consequence worth knowing before you try to debug one:

> `curl` will not work, and it is not obvious why. A plain JSON body fails to
> inflate *before any router is consulted*, and what comes back is a 200 with a
> body the caller cannot read: a malformed request that presents as a broken
> mod.

`aowlprobe` speaks the protocol instead. The backend also accepts an *unframed*
request deliberately, because the tools people debug with do not compress and
refusing them would make the server untestable by hand.

One detail that cost time to find, and that the docs now name: the session id
must be a 24-character hex MongoId or the request is rejected before any route
sees it — so a malformed id is never reported as some mod's bug.

## The store

`host/common/modstore.nim` is the per-mod persistent key/value store — ABI
revision 2, available on all three hosts. Atomic and write-through: a commit
costs **476 µs**. `aowl test` kills the writer mid-commit (`storecrash`) and
demands a whole value back, and `storeguard` holds a reader across a commit.

## Ports

Loopback only, everywhere, and there is no flag to change that. `aowlspt-backend`
defaults to 6969 — the port SPT's own server uses, which is why. Every gate in
`aowl test` gets a port of its own (6974–6982) so that none of them can pass
against a server somebody already had running, and so that two of them cannot
collide when the suite is run twice at once.

## Building

`aowl` is itself a nimony program: the thing that compiles a nimony mod is
written in the language it compiles.

```
aowl doctor      # nimony, ucrt64 gcc, lld, the ABI headers, and PATH order
aowl build       # the hosts, the backend, the tools
aowl build-mod examples/gameserver
aowl run examples/hello        # build + load into aowlspt-sim
aowl test        # 143 checks
aowl payload     # stage what you built
aowl release     # dist/aowlspt-<version>-<date>.zip + .sha256
```

`aowl doctor` checks PATH order specifically, and that check is worth the whole
command on its own: a Git-for-Windows `mingw64` ahead of msys2 `ucrt64` gives
gcc a `cc1` that loads the wrong libgcc and **dies with no diagnostic at all**.
Every check in `doctor` is there because something went wrong once and pointed
somewhere else while it did.

Releases are byte-identical across runs — stored entries, fixed timestamps,
sorted names, no build time inside — so two people building the same tree can
compare hashes. The archive is then reopened and verified from its own central
directory: the shape is checked against the file, not against the list the
writer was handed.
