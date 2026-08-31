# Traps and hard-won facts

Each entry below cost real time to establish and has been rediscovered at least
once. They share a shape: **the failure mode is a plausible wrong answer, not an
error.** A crash is cheap. A confidently wrong value is expensive.

## IL2CPP

### Reflection is token-gated, not dead

Post-1.0 Escape From Tarkov is stock IL2CPP with a **gated export ABI**. Forty
of the 241 `il2cpp_*` exports take an extra trailing argument that is never
passed by ordinary callers — a pointer to 32 bytes — and `memcmp` it before
doing anything.

On mismatch they do **not** return `NULL`. They return a **uniform random
non-zero `uint64`** drawn from a per-thread MT19937-64.

That is the whole trap. A nil check passes, because the value is non-zero. The
first dereference kills the client. Twenty of the gates are static (expected
bytes live in `.rdata`); eighteen are nonce-derived through the exported
`il2cpp_nonce(apiId)`.

::: danger Never write "reflection is dead"
It is not, and the phrase has been copied into comments and refusal messages
where it then misleads. Say the export is **token-gated** and that its failure
mode is a plausible random value.
:::

**What works today:** raw static-offset field reads and writes, direct calls at
a byte-verified static RVA, and `il2cpp_string_new`. A direct RVA call bypasses
the export ABI entirely, so no gate affects it.

### Two exports that were documented wrong

Both of these were once written down as fact and are false:

- `il2cpp_object_get_class` does **not** fault on a bad pointer. It is
  `mov rax,[rcx]; ret` — so a bad pointer yields a plausible number, silently.
  That is worse than a fault.
- `il2cpp_value_box` is intact and ungated.

### `ForceMeshUpdate` resolves to a stub shared by 6,438 methods

Resolving `ForceMeshUpdate` lands on `0x628110`, which is `C2 00 00` — `ret 0`.

That is **not that method's own code**. It is this build's universal empty-body
stub, and **6,438 methods share it**. A stub that passes a signature check is
the worst possible case: the resolution succeeds, the call returns cleanly, and
nothing happens.

### 28.3% of by-name lookups land on a shared RVA

6,261 RVAs have more than one owner.

*Calling* a shared address is fine — it is correct code for the receiver you
pass. **Detouring one is a write with unbounded blast radius**, because it fires
for every method that shares the address.

Sharedness is **three-state**, never two:

| Result | Meaning |
| --- | --- |
| `shared` | More than one method resolves here. Do not detour by name. |
| `unique` | Exactly one owner. |
| `unknown` | The address is not in the methodPointers histogram at all — a live ASLR address, a typo, or a non-code RVA. |

`unknown` is a **refusal**, not "probably safe". A previous implementation
derived this from a histogram with a `.get(rva, 1)` default, which made every
unknown address read back as "1 owner, safe to detour".

### Field offsets are three-state too

A field offset is a real offset, `--` for a constant (no storage), or
**`GENERIC` / `GENERIC-NO-LAYOUT`** for an uninstantiated generic definition.

IL2CPP writes an **all-zero** `fieldOffsets` array for the 1,569 generic
definitions, because the layout depends on the type arguments and is built at
run time. Tools once printed `0x0` for every field of `List\`1` — a fabricated
offset that reads the object header.

Instantiated generic layouts (`List<int>`) are **not reachable offline**: all
33,464 `Il2CppGenericClass` entries are present but every `cached_class` in the
file is null. Take such a layout from a live object or a verified header, and
say that it is borrowed.

### Two detours on one function

The second overwrites the first's trampoline, silently killing the first. If a
function is already detoured, ride the existing detour as a drain.

Verify prologues against the **startup snapshot**, never against live memory —
verifying after another feature has patched the function reads the trampoline
and self-rejects.

## Unity

### Fake null: readability is not liveness

A destroyed `UnityEngine.Object` is not a null pointer. The managed wrapper
survives with its native side torn out, so the pointer reads back fine and the
object is dead.

**Readability is not liveness.** And worse: **type confusion beats both
guards** — a readable, live pointer to the *wrong kind of object* passes a null
check and a liveness check and then has the wrong layout imposed on it. A
component lookup that fails while leaving a stale handle bound has produced a
complete and entirely fictional field map of an object that does not exist.

### An inactive node is not pressable

Pressing a control on an inactive node **returns success and does nothing**.
Any search used to find something to press must check
`GameObject::get_activeInHierarchy` and report it, or the caller will read a
successful no-op as a working feature.

### The live UI is not in any scene `SceneManager` lists

It lives in `DontDestroyOnLoad`, which `sceneCount` / `GetSceneAt` exclude by
design. All the listed scenes report `rootCount=0` **truthfully**. A search that
walks only the listed scenes will report a name as "NOT PRESENT" when it is
merely unreachable.

## Tooling

### Client-side mods cannot serve HTTP

`serve()` inside the game process registers into nothing. There is no listener
in the client, so the call succeeds and no port is ever opened. Anything that
must answer a request belongs in the backend.

### PowerShell marker checking produces false absents

`[Text.Encoding]::ASCII` maps **every byte ≥ 0x80 to `?`**, so any marker
containing one will not be found — a false ABSENT, reported as a missing
feature.

`[Text.Encoding]::Latin1` is not the fix on PowerShell 5.1: it evaluates to
`$null`, because **PowerShell returns `$null` for a missing static property
instead of throwing.** The check then silently compares against nothing.

Use `tools/markers.py`.

### A missing string may be INCONCLUSIVE, not MISSING

Nimony stores each `&`-concatenated string fragment as a **separate rodata
entry**. A long literal built by concatenation legitimately may not appear
contiguously in the built binary.

Failing to find it is therefore **INCONCLUSIVE**, not proof the feature was
dropped.

### The raid-phase latch is the only trustworthy "deployed" signal

A raid-**entry** log line is not proof of raid **state**. Entry can be logged
and the raid then fail to start; the line stays in the log either way. The raid
phase latch is the signal to read.

## The shape they share

In every case above, the wrong path returns something that *looks like* an
answer:

- a random non-zero pointer instead of `NULL`
- a stub that returns cleanly instead of a missing symbol
- `0x0` instead of "this type has no layout yet"
- a fake-null object that reads back fine
- `$null` instead of a thrown error
- a successful press that pressed nothing

This is why [the measurement discipline](./method) insists on asserting a
property of the finished state, and on **INCONCLUSIVE** as a first-class
verdict.
