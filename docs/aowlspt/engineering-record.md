# The engineering record

*Internals. Nothing on this page is needed to install or play aowlspt — start at
[Installation](/docs/aowlspt/installation) for that.*

This page is the material that used to sit on the aowlspt front page: what the
project is made of, the gate that runs over it, and what the automated tests do
and do not establish.

[[toc]]

---

## Why it is on this site

Every other page in these docs documents a piece of the toolchain. aowlspt is
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

The case for reading it as a case study is on its
[own page](/docs/aowlspt/case-study): what the language made easy, what it made
hard, what broke, and the long list of things this project says it has **not**
proven.

## Why the design is what it is

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
rather than asserted. See [Reaching into IL2CPP](/docs/aowlspt/il2cpp).

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
| `soak`, 24 closed play cycles | 915 | the game server over a long session, checked by invariant |
| `emutest` | 577 | the game server through the client's boot sequence, against a fixture database |
| `livectl` | 213 | a mod disabled and re-enabled while the backend is serving |
| `realtest` | 168 (1 skipped) | the server against a **39.40 MiB** database imported from a real SPT install |
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
of
[the case study](/docs/aowlspt/case-study#a-check-nobody-has-seen-fail-is-an-opinion).

## What the gate does not settle

> **`aowl test` runs the client host against `tests/mockil2cpp`, a stand-in that
> exports the same C API as `GameAssembly.dll`.** Resolve, call-with-arguments,
> live objects, fields and patching are all exercised for real against it. What
> that cannot establish is that BSG's implementation behaves identically. Every
> performance figure on these pages is measured against that stand-in — the real
> boxed/bound ratio is expected to be **larger** than the published table, not
> smaller.

That gap is closed by launching the game rather than by adding tests, and it
has been: the system now installs onto a real post-1.0 client, boots it, and
plays offline raids. What each test suite is still worth is exactly what it
says on its row — an invariant checked cheaply, on every build, before anyone
launches anything.

Historical note, because it appears throughout older material in the
repository: until 2026-08-19 the most repeated sentence in the project was
*"Nothing in this repository has ever run against BSG's client. Not once."* It
appeared at the top of seven documents, all ten mod READMEs, the overlay README
and the module header of every client-side mod. **That sentence is no longer
true**, and wherever it still survives it is stale text, not a current claim.
