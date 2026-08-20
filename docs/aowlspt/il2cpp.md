# Reaching into IL2CPP

There is no managed layer to hide in. Everything on this page is what replaces
one, and every price is measured rather than asserted.

[[toc]]

---

## What changed at Tarkov 1.0

| | pre-1.0 | post-1.0 |
|---|---|---|
| scripting backend | Mono | **IL2CPP** |
| managed assemblies | `EscapeFromTarkov_Data/Managed/Assembly-CSharp.dll` | none |
| what is there instead | — | `GameAssembly.dll`, `il2cpp_data/Metadata/global-metadata.dat` |
| mod loader | BepInEx 5 | — |
| patching | Harmony, by method name | — |

> That is not a version bump; it removes the thing every existing client mod
> loads into.

This repository used to carry a Mono BepInEx plugin host. It could not load into
a post-1.0 client and no flag changed that, so it is gone.

BepInEx 6's IL2CPP branch was considered and rejected: it brings *"a second
runtime, a code-generation step per game update, and a marshalling layer — to
arrive back at 'call a method by name', which is what the mod wanted in the
first place."*

What is left is the runtime's own C API. Unity's IL2CPP runtime exports it from
`GameAssembly.dll` by name, unmangled — **242 functions** on the client
`tools/il2cppprobe.nim` was run against. `aowlspt/il2cpp` binds **62** of them,
of which **9** are marked `Essential` and a missing one is named at boot rather
than discovered as a fault later.

## Getting the host into the process

`aowlspt-launch` starts the game **suspended**, `LoadLibrary`s the host DLL into
it, and resumes. There is no proxy-DLL trick and nothing is renamed.

A C constructor starts the boot thread, because constructors run under the
loader lock, where almost everything deadlocks. Two things must nevertheless
happen *in the constructor itself*, and both are single-pointer writes into one
module's import table.

### Getting a real client to boot

Post-1.0 `EscapeFromTarkov.exe` will not start unless the BattlEye service is
running. **That is not BattlEye refusing** — it is BSG's own code, in a modified
`UnityPlayer.dll`, and it is checked before Unity brings IL2CPP up. The evidence
is in the binary:

```
BEService
The required BattlEye service does not exist.
The required BattlEye service is not running.
.?AV?$_Fake_no_copy_callable_adapter@P8BattlEyeService@Guard@BSG@@...
```

and in its import table, which stock Unity does not have:

```
ADVAPI32.dll  OpenSCManagerA, OpenServiceA,
              QueryServiceStatusEx, CloseServiceHandle
```

`BSG::Guard::BattlEyeService` opens the service manager, opens `BEService`, asks
for its status, and refuses to continue unless it reads `SERVICE_RUNNING`. Both
of its failure messages were observed on 2026-08-19: *"does not exist"* against
a target with no `BattlEye\` directory, and *"is not running"* once the
directory was copied in.

`abi/aowlspt_beguard.h` answers that one question, for that one caller. It
patches four entries in **`UnityPlayer.dll`'s import table** and hands back a
`SERVICE_STATUS_PROCESS` whose `dwCurrentState` is `SERVICE_RUNNING` — and only
when the service being asked about is named `BEService`.

**Why the import table and not the function**, in the header's own words:

> Patching `QueryServiceStatusEx` itself would change the answer for every
> caller in the process. Patching `UnityPlayer.dll`'s IAT changes it for
> `UnityPlayer.dll` alone […] And this has to run in the constructor, under the
> loader lock, which rules out the detour engine and rules out `GetProcAddress`.
> `QueryServiceStatusEx` is a *forwarded* export on modern Windows — advapi32
> forwards it to sechost.dll — and resolving a forwarder can make the loader map
> a module, which under its own lock is a deadlock.

Reading an already-mapped PE's import descriptors and writing one pointer
through `VirtualProtect` touches the loader not at all. And it has to be the
constructor rather than the boot thread because the injector waits for
`LoadLibrary` to return before it resumes the game's main thread — the boot
thread does not start until the loader lock is released, which is a race with
that resume, *"and the guard would win it."*

There is **no configuration switch**, and the reasoning generalises well beyond
this file:

> The condition is its own switch. If the client in front of it does not import
> those symbols into `UnityPlayer.dll` — any Unity build that is not BSG's —
> there is nothing to patch and nothing is patched. **Arming is evidence that
> the guard is there.**

Nothing is logged from the constructor, because the host's log does not exist
yet. Seven counters record what happened and `aowlhost.nim` reports them once
there is somewhere to report to — and they keep four outcomes deliberately
uncollapsed, because *"the module present with the imports and nothing patched
is a failure, and it is the one that must not look like the other two, because
the symptom is the game refusing to start with no explanation anywhere."*

On scope, the header is direct: the modded client plays against a backend on
`127.0.0.1` and never contacts BSG, so *"there is no live service being deceived
here — the alternative to this file is not 'BattlEye protects something', it is
'the game does not start'."* BattlEye is never installed, never started and
never loaded. The project's own installer will not carry BattlEye across and its
launcher will not start it, and its README says plainly that pointing a modded
client at the live service is a decision with consequences for your account that
these tools will neither prevent nor assist.

### Knowing when the runtime is actually up

The second constructor-time patch is the more instructive one, because it is a
bug that was found *by* the first real client and fixed the same day.

The host is injected into a suspended process and must wait for the game to
build its runtime before it can resolve a single type. The obvious way to wait
is to poll: is `GameAssembly.dll` loaded, and does `il2cpp_domain_get` return a
domain yet?

That is what `waitForIl2Cpp` did, and on the first real client **it crashed the
game**. From `Player.log`, 2026-08-19:

```
0x00007FFD822A5639 (GameAssembly)        mono_class_has_parent
0x00007FFE13555DA5 (aowlspt-host-il2cpp) domainGet
0x00007FFE1354135A (aowlspt-host-il2cpp) waitForIl2Cpp
0x00007FFE1354E40C (aowlspt-host-il2cpp) aowlspt_nim_host_main
```

The module is mapped and its exports resolvable long before `il2cpp_init` has
run, and `il2cpp_domain_get` in that window does not politely return NULL — it
reads a global that has not been written yet and faults inside the runtime. The
old comment knew the first half of this and drew the wrong conclusion: that
asking is safe as long as you are willing to be told no. **Asking is the unsafe
act.** There is no answer that can be polled for, because the question is what
crashes.

`UnityPlayer.dll` does not import `il2cpp_init`; it looks it up with
`GetProcAddress`. So the fix replaces `GetProcAddress` in `UnityPlayer.dll`'s
import table — and only there — and watches what is asked for. When UnityPlayer
asks for `il2cpp_init` (or `il2cpp_init_utf16`; both are exported and which one
a build calls is not knowable from outside) it is handed a wrapper that calls
through and records **a successful return** — not that the runtime was asked to
initialise, and not merely that the call came back.

That distinction cost a second crash to learn:

> On the first real client this watched for any return at all, and `il2cpp_init`
> answered 0 — a failure — 100 ms into the process. The host believed it, asked
> for the domain, and faulted in precisely the place the polling version had.
> The fix and the original bug are the same shape one layer apart, which is
> worth saying plainly here: **a signal that fires whether or not the thing
> happened is not a signal.**

Detouring `il2cpp_init` in `GameAssembly.dll` was the deterministic alternative
and cannot be armed in the constructor: that DLL is loaded dynamically and is
not mapped yet — `EscapeFromTarkov.exe` imports only `UnityPlayer.dll` and
`KERNEL32.dll`. Arming it later means racing the very next call, with no upper
bound on how badly that can lose. Watching the lookup has no race at all: the
pointer is in place before the game runs an instruction, and UnityPlayer cannot
call what it has not yet looked up.

## The detour engine

`abi/aowlspt_detour.h`, 1,885 lines: a length decoder, a trampoline builder, one
shared assembly thunk, and **256 hook slots** (`AOWL_MAX_HOOKS`).

The patch is a 14-byte absolute jump:

```
FF 25 00 00 00 00        jmp qword ptr [rip+0]
<8-byte destination>
```

The obvious encoding, `mov rax, imm64 ; jmp rax`, is two bytes shorter and wrong
in a way that is invisible until it is not. The trampoline ends with this jump,
immediately after the stolen instructions — and a stolen prologue very often
leaves a value in RAX the rest of the function still needs. `void f(void) {
counter++; }` compiles to `mov eax,[rip+x] ; add eax,1 ; mov [rip+x],eax`, the
first twelve bytes of which get stolen, so a `mov rax` jump-back would overwrite
the incremented value with its own jump target and store a pointer fragment into
the counter. The `e9` rel32 form is smaller still and reaches only ±2 GB, which
a DLL loaded far from the game image cannot rely on. **This form reaches
anywhere, touches no register, and costs two bytes.**

Fourteen bytes is not an atomic store, so installing a patch is not atomic
either: a thread entering the function mid-write executes the head of the new
jump followed by the tail of an instruction that is no longer there. That is not
a rare window — `tests/detour_race` counted **over a thousand faults in a
three-second run** with six threads calling the target. So the engine stops the
world for the fourteen bytes. The alternative (a five-byte `jmp rel32` to an
island holding the real fourteen) needs an island within ±2 GB, needs five
stealable bytes rather than fourteen, and quietly changes the decoder's
contract.

The per-hook stub is two instructions — `mov r11, <site>` then `jmp [rip+0]` to
the one common thunk — and that shape closed the last race the generation
counter could not. A firing used to be told nothing but a slot number, baked
into one of sixteen fixed thunks, and had to look the rest up in slot-indexed
tables; a thread preempted between the jump landing and those loads read them
after the slot had been released **and re-claimed**, with trampoline and
generation agreeing with each other because they both belonged to the new
occupant.

> `AOWL_MAX_HOOKS` was 16 because that was how many `aowl_thunk_N` macro
> expansions fitted on a screen — never a budget. With one shared thunk, a slot
> is 25 bytes, so 256 slots is 6.4 KB of BSS and nothing at all on the firing
> path. `hostharness --churn 120` had stopped with thirteen slots left.

## What each path costs

Measured by `perfbench` against `tests/mockil2cpp`, msys2 ucrt64 gcc 15.2.0,
re-derived 2026-08-18. **These are stand-in numbers**, and the real boxed/bound
ratio is expected to be *larger* than this table, not smaller, because the
stand-in's `il2cpp_runtime_invoke` is cheaper than the real one.

| operation | ns/op | × fastest |
|---|---:|---:|
| boxed call, type resolved by name (host `call`) | 1103.6 | 590 |
| boxed call, class in hand | 951.5 | 509 |
| `il2cpp_runtime_invoke` alone, arguments prebuilt | 42.9 | 23 |
| **fast call, static, 2 int args → int** | **10.07** | 5.4 |
| **fast call, instance, 1 float arg → float** | **8.40** | 4.5 |
| **fast call, instance, no args, void** | **5.95** | 3.2 |
| field via property getter, boxed invoke | 42.6 | 22.8 |
| field via host `@Name` path (JSON out) | 381.7 | 204 |
| **field via cached offset, direct load** | **1.87** | 1.00 |
| bound call, unpatched | 3.47 | 1.85 |
| prefix hook, JSON arguments | 626.5 | 335 |
| **prefix hook, typed frame** | **23.08** | 12.3 |
| postfix hook, JSON result and arguments | 1101.7 | 589 |
| postfix hook, JSON + replacement | 1524.9 | 815 |
| **postfix hook, typed frame** | **24.11** | 12.9 |
| **postfix hook, typed frame + replacement** | **36.70** | 19.6 |

Binding costs, from the same run: a field binding 1–7 µs, a method binding
3–9 µs, almost all of it `findClass` walking every loaded assembly —
**280 ns of every named call**. That is the whole argument for binding once: it
costs about as much as a hundred bound calls, and then it costs nothing.

Two numbers moved between runs of the same code on a newer compiler — the boxed
call by name was 1235 and is 1104; `field via host @Name path` was 305 and is
382. Neither changed for a reason anybody intended, *"which is the argument for
re-running the table rather than remembering it."*

### What the numbers decide

| | |
|---|---|
| `pointerOf(handle)` — the address behind a handle | **8 ns** |
| the boxed property read it replaces | 1112 ns |
| a bound call with a postfix that only *watches* the return | 443 ns |
| the same postfix reading arguments and replacing the result | 2320 ns |
| **the same hook on the typed path** | **80 ns** |

A hook that wants anything from the object it fired for should take the address
and use its own bindings, not call back through the handle. And at 2.3 µs, forty
bots at 60 fps is **5.5 ms a frame** — *"which is not a patch, it is a
stutter"* — where the typed path is 190 µs.

The typed path is also allocation-free: **0 allocations and 0 payload bytes over
20,000 firings**, against 20,000 allocations and 780,000 payload bytes for the
same hook on the JSON path. `aowlspt/fast` exposes `allocationCount`,
`allocatedBytes` and `liveBytes` so a mod can assert that about *itself*.

> The fast-path gate is the second-cheapest thing in `aowl test` and is named
> separately in the docs for one reason: **a performance claim that is not
> re-checked is a performance claim that quietly stops being true.**

## The registration tables, and why they do not lock

`RouteCapacity`, `EventCapacity`, `PatchCapacity` and `TypedPatchCapacity` are
each 1024, and the tables are **reserved to full capacity on first use and never
grow**. The firing path reads them with no lock at all.

Both halves are load-bearing. A growing `seq` *moves*, and a detour indexing the
old buffer reads a closure out of freed memory. A lock was measured and
rejected: the typed patch prefix is 21.8 ns and the postfix 23.4 ns end to end,
and an uncontended `EnterCriticalSection`/`LeaveCriticalSection` pair is 25–27 ns
on the same machine — **guarding the firing would cost more than the whole
path**.

The other obvious fix, a rule that mods may only register during `on_load`, was
rejected on a different ground: *"a rule that the shipped examples cannot follow
is not a rule."* `examples/clientprobe` waits three seconds for EFT's assemblies
before it can `patch` anything.

## The overlay

Post-1.0 there is no `MonoBehaviour` to attach and no managed UI to call, so the
mod panel is drawn by hand from a detour on `IDXGISwapChain::Present` — the same
place Steam and Discord draw. `abi/aowlspt_overlay.h` is 4,619 lines of
header-only C and D3D11. Insert toggles it.

Whether it draws, and whether it steals input, is one of the fifteen open
questions: a wndproc subclass cannot intercept `GetAsyncKeyState`, DirectInput
or `GetRawInputBuffer`, and if Tarkov polls that way then input reaches the game
while the panel is open. The overlay README carries the only explicit
*(unverified)* marking in it.
