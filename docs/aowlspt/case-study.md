# Case study — a real program in nimony

aowlspt is the largest program in the aoughwl orbit that is not part of the
toolchain. It is a good case study for the reason case studies are ever useful:
it was written to do a job, the job had hard external constraints nobody chose,
and it is old enough now to have a list of things that went wrong.

[[toc]]

---

## The shape of it

| | |
|---|---:|
| nimony, whole repository | **139,587 lines**, 202 modules |
| C, hand-written, under all of it | **12,855 lines**, 15 headers |
| C# remaining | **one program** — `tools/SptReflect`, which reads .NET assembly metadata |
| documentation in-repo | 13,491 lines of Markdown |
| `aowl test` | **143 checks, 0 errors** (2026-08-19) |

Everything is nimony: three hosts, the HTTP backend, the installer, the release
tool, the build driver, every gate binary, every mod, and a complete Escape From
Tarkov server. `aowl` — the thing that compiles a nimony mod — is itself a
nimony program.

The one C# survivor is honest about why it survives: it reads SPT's assembly
metadata, and the thing it reads is managed.

## What the language was asked to do

Not a script host, and not a compiler. A list of the things this program
actually has to do:

- Load and unload native DLLs at runtime, and tear down their registrations in a
  specific order or corrupt the process.
- Be the callee of a hand-written x64 assembly thunk, on a stack the game owns,
  possibly per entity per frame.
- Run an HTTP server with sixteen workers and a lock per session, speaking zlib
  in both directions and websocket framing.
- Live inside somebody else's game process, under their loader lock, without
  taking it.
- Hold a 39 MiB JSON document and answer dotted-path reads and merging writes
  against it, fast enough that boot is measured in hundreds of milliseconds
  rather than the 54 seconds it once was.
- Cross a C ABI in both directions, in a struct whose layout has to agree with
  what gcc lays out — byte for byte, on pain of reading a length as a pointer.

None of that is a language demo. All of it is ordinary systems work, and the
interesting question is which parts nimony made easy and which it did not.

## What nimony made easy

**The C boundary is cheap enough to put in the right place.** `{.importc,
nodecl.}` against a header-only C file is a one-line declaration, so the C floor
could be drawn exactly where the language stops and nowhere wider. Fifteen
headers, each of which exists for one specific thing nimony does not do:
hand-written assembly, indirect calls through a `pointer`, structs read inside a
per-frame hook, Win32 socket polling, D3D11.

**`{.byref.}` and no hidden allocation make the hot path expressible.** The
per-frame path allocates nothing, and the mod library exposes
`allocationCount` / `allocatedBytes` / `liveBytes` so a mod can *assert* that
about itself rather than believe it. 20,000 typed hook firings: 0 allocations,
0 payload bytes.

**Templates carry the boilerplate without a macro system in the way.**
`exportMod` is a template that emits the three `{.exportc, cdecl.}` symbols the
ABI requires. A mod author never writes an `extern "C"` anything, and never sees
`AowlSlice`.

**Compiling to C means the platform is not an argument.** msys2 ucrt64 gcc, lld,
a `.dll` — the same toolchain the rest of Windows uses, and a debugger that
works.

## What nimony made hard, and what it cost

**No exceptions.** nimony replaces them with error-code plumbing, so every
operation in the mod API returns a `Status` and writes its result through a
`var` parameter. The API is shaped by that all the way down — `dbGet(path,
outText)` rather than `dbGet(path)`. In a plugin ABI this turned out to be the
right shape anyway, since exceptions could not cross the boundary regardless.
It is still the single largest stylistic difference from the Nim it looks like.

**`cast` between `pointer` and `proc` is refused.** This is why
`abi/aowlspt_shim.h` exists at all: 790 lines of C whose entire job is to
perform indirect calls the language will not express. It also has a
knock-on the ABI page describes in full — **a mod cannot null-check a function
pointer in the host block**, which is why every capability test in this system
is a `size` comparison rather than a nil comparison.

**A 16-byte struct return is where mingw and MSVC disagree** about hidden-pointer
handling, and the disagreement corrupts silently rather than failing to link. So
`last_error` writes through an out-parameter instead of returning an
`AowlSlice`. That is a two-ABI problem, not a nimony problem, but it is the kind
of thing a real program discovers.

**`-o:` does not reach an `--app:lib` build.** nimony writes the shared library
into `<modDir>/nimcache/<hash>/` and leaves it there; `aowl build-mod` finds it
and copies it out. *"Without this the compile reports success and the library is
simply absent, which is a much worse failure than a compile error."* The build
tool also deletes the stale output **before** compiling, because
`placeLibrary` treats an existing output as evidence that `-o:` was honoured —
so a leftover from the previous build satisfies that check, the compile reports
success, and **the stale binary ships**.

**The incremental cache does not always survive a source file being added.** The
build fails at link with an undefined string literal, *"which reads like a code
error and is not one"*, so `aowl build-mod` clears `nimcache` and retries once.

**PATH order will kill you with no diagnostic.** A Git-for-Windows `mingw64`
ahead of msys2's `ucrt64` gives gcc a `cc1` that loads the wrong libgcc and
dies silently. And the linker must be lld: nimony's `niflink` passes
`-fuse-ld=lld` on Windows deliberately, because ld.bfd lays out PE TLS in a way
the loader mishandles and nimony's runtime uses native TLS. `aowl doctor` checks
both, and *"every check in it is there because something went wrong once and
pointed somewhere else while it did."*

## A check nobody has seen fail is an opinion

The most transferable thing in this repository is not a technique, it is a
diagnosis. The project has named its own recurring bug species, in those words,
in module headers rather than in a style guide:

> **a check that passes because the thing it checks never happened.**

And the variant:

> a check that passes because the thing it checks **is not the thing that
> happens.**

From which follows the rule:

> **A check that has never failed is a check nobody has read.**
>
> a gate that has only ever been run one way is a gate nobody has seen fail.

That rule is applied, not merely stated. Gate counts in the backlog are
annotated with **how many of them fail against the code they were written for** —
`ws_stall` 15, *"14 and 2 failures against the pre-fix poller"*; `storeguard` 9,
*"2 fail against the store as it was"*; `tickfault` 22, *"9 fail with the
honouring removed"*; `ovsync` 24, *"18 fail against a dead port, with
`silentPolls: 0` as the proof nothing arrived"*. Two test files state that every
check in them was **made to fail on purpose**, and list the mutations built and
run to do it.

Three real instances, because the species is easier to recognise than to
describe:

**1 · The write barrier that was never exercised.** `writePtr` was changed to
route reference stores through IL2CPP's `il2cpp_gc_wbarrier_set_field`.

> The stand-in did not export the barrier, so the binding would have fallen back
> to a plain store and any *"the field was written"* check would have passed
> without exercising it. The mock now exports it **and counts calls**, and the
> gate asserts both the mod's line and the runtime's counter — **one alone
> proves nothing.**

**2 · The static field that read plausibly and wrongly.** Static and instance
field offsets share one space, so a `bindField` that silently accepted a static
would read the wrong bytes and report `ok`. The stand-in now carries
`Player::SpawnCount` (static `Int32`) and `Player::Health` (instance `Single`)
**deliberately at the same offset 16**, and the wrong binding answers
`1091567616` with `ok` true.

> A `bool` flag would read identically whether it was right or wrong; **only the
> compiler can catch this one.**

The fix pushed the distinction into the type system — `bindStaticField` returns
a different type whose readers take no object — asked
`il2cpp_field_get_flags` rather than inferring staticness from an offset, and
runs `il2cpp_runtime_class_init` first *"so that 'zero' cannot mean 'the static
constructor has not run'."*

**3 · The proof nobody ran.** A gate existed, was correct, and was never wired
into `aowl test`.

> `grep -n modrace tools/aowl.nim` finds nothing […] **A proof nobody runs is
> the same as no proof, and this is the second time that sentence has had to be
> written about this item.**

The same failure mode, generalised, is the heading *"wiring, which is where work
goes to be forgotten"* — three separate items that landed and were then not
connected to anything that would notice them breaking.

And the sharpest instance of all is in the fix for the crash on the first real
client. The polling probe crashed because asking was the unsafe act; the
replacement watched `il2cpp_init` for **any** return, and `il2cpp_init` answered
0 — a failure — 100 ms in, and the host believed it and faulted in exactly the
same place.

> The fix and the original bug are the same shape one layer apart […] **a signal
> that fires whether or not the thing happened is not a signal.**

## Numbers that are re-derived rather than remembered

Every count in the backlog's four tables was re-derived on 2026-08-19 by running
the binary or the grep that produces it — and the document says so, and says
what changed. `aowlspt-verify` reports 28 checks; the document used to say *"all
thirty-one checks"*, which was **not a number anybody could reproduce and is
retired rather than corrected**. `hostharness` is counted as 28 verdicts and not
by `grep -c '^ok'`, which answers 31, because three of those lines are the
harness reporting its own staging.

The colophon states the policy:

> Where something could not be verified it is marked as unverified rather than
> dropped; where a claim in one file contradicts another, **both are quoted
> rather than one being chosen**; and where the code has since moved, the old
> claim is struck with the file and line that moved it rather than deleted.

Two lessons are recorded from the same day. The first: **a document cannot see
its own subject** — the fix for that class is not more prose, it is
`tools/coverage.nim` writing the coverage table between markers and a gate that
fails when it is stale. The second is about refusals:

> A gap gets written down once, with a reason, and the reason is never
> re-checked against the data — so the sentence outlives the fact and a feature
> stays unbuilt for months behind it. **The cost of being wrong in this
> direction is invisible, which is why it keeps happening.**

Nine refusals were retired in one pass on that basis. They had rested on a claim
about missing data that the data contradicted.

## What is not proven

This is the part that makes it a case study rather than a pitch.

Until 2026-08-19, the most repeated sentence in the repository was:

> **Nothing in this repository has ever run against BSG's client. Not once.**

It appeared at the top of seven documents, all ten mod READMEs, the overlay
README, and the module header of every client-side mod. **That sentence is no
longer true**, and wherever it still survives in older material it is stale
text rather than a current claim.

Contact was made on 2026-08-19: a real post-1.0 client launched with the host
injected, past BSG's own BattlEye service check — the import-table patch
described on [the IL2CPP page](il2cpp#getting-a-real-client-to-boot) — reaching
`il2cpp_init` and then crashing, twice, with a `Player.log` stack naming the
frames both times. Both crashes were diagnosed and fixed the same day, and both
were bugs that only a real client could have produced.

Since then the system has been taken the rest of the way: it installs onto a
real post-1.0 client, boots it to the menu, and plays populated offline raids
with loot, bots, bosses, death and extraction. The interesting question stopped
being *"does it run"* and became the ordinary one — which parts are playtested
and which are inferred.

These remain open, in the project's own words:

- Where a claim rests only on `tests/mockil2cpp`, it rests on a stand-in:
  *"what none of them can prove is that BSG's implementation of the same C API
  behaves identically."*
- Every performance figure on these pages is measured against `tests/mockil2cpp`,
  a stand-in — and the real boxed/bound ratio is expected to be **larger** than
  the published table, not smaller.
- *"`onUnload` itself has never been exercised against a runtime."* Whether a
  detour comes back out cleanly on unload is *"the failure mode this whole
  design is arranged around, and the one with the least evidence behind it"* — a
  detour that failed to come out is a game jumping into a freed DLL.
- *"Thread safety is inferred, not tested."*
- *"a thread created after the enumeration is not parked, and the 64-retry
  give-up path has never executed, so its fallback […] is correct by inspection
  and not by test."*
- A rate the docs used to quote — *"~1 in 140,000 calls"* — **is not
  reproducible and is withdrawn.**
- The physics model behind `mods/sway` sets out a full argument for its default
  integration law and then says: *"That is an argument, not a measurement."* The
  boolean in question is worth a factor of sixty at 60 fps.
- *"Until this is decided, the registry is metadata only and no mod is
  distributable through it."*
- Nothing carries a mod's state across a reload yet. The `mfHotReloadable` flag
  is declared, plumbed, and called by no host.
- `aowlspt-verify` does not check for `db.json`: *"'it serves' and 'there is a
  game in it' are different claims and this tool only makes the first."*

The backlog splits all of this the useful way, which is not "tested /
untested" but **what a playtest settles and what it does not**. Items that a
single real session answers — whether a name exists in the shipped build,
whether a knob survived stripping, whether a panel draws — are answered by
playing, and the mods print their own binding reports a minute into a raid so
that the answer arrives without anyone reading source. Items that a session
cannot answer — thread safety, a give-up path that has never executed, whether a
detour comes back out cleanly under every unload order — stay in the second
bucket until something exercises them on purpose.

> **The house rule that produced this list is the only part worth copying: a
> check nobody has seen fail is an opinion, and a claim nobody has re-derived is
> a memory.**

## What it demonstrates

Narrowly: nimony compiles to a native Windows DLL that can be injected into a
commercial game, called from hand-written assembly on the game's own stack, and
measured at single-digit nanoseconds on its hot path — and can, in the same
repository and the same language, run an HTTP server that answers a hundred
routes off a 39 MiB document.

More usefully: the friction was where a systems language's friction usually is —
the FFI edge cases, the two competing Windows ABIs, the build tool's handling of
`--app:lib`, the linker — and **not** in expressing the program. The things that
went wrong went wrong in the places a C or C++ project would also have had them.
That is a duller claim than "nimony is fast", and it is the one worth making.

The rest of the argument is the list above it. A project that publishes the
questions it cannot yet answer is making a smaller claim than one that does
not, and a checkable one.
