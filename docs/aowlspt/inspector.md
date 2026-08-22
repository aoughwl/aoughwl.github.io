# The live inspector

A command channel into a **running** Escape From Tarkov client. You write a
batch of commands to a file next to the host DLL; the answers appear in another
file and in the host log, seconds later, with no rebuild and no restart.

[[toc]]

---

## What it replaces

Before it existed, asking the live game one question cost an edit, a rebuild, a
deploy, a launch, and roughly **90 seconds** to reach the menu. At the end you
learned exactly **one** thing: the thing somebody had predicted in advance by
writing a log line for it. An answer that was not in a line written beforehand
was not learned at all, and the whole cost was paid again.

The build half of that is measurable:

| | time |
|---|---|
| full build, cold | **18m25s** |
| full build, warm | **4m27s** |
| `aowl build host` (the single named target) | **48s** — 23x |

The launch and the human sitting in front of it were the larger half. The loop
is now about **2.5 minutes**, and none of it is a person's attention.

## The constraint that shapes it

Post-1.0 Tarkov is IL2CPP, and on this build **reflection is dead**.
`il2cpp_object_get_class`, `il2cpp_class_get_name`, `il2cpp_value_box` and field
iteration all fault. **You cannot ask an object what it is.** What works is a
short list: raw field reads and writes at static offsets, direct calls at a
static RVA, and `il2cpp_string_new`. See
[Reaching into IL2CPP](/docs/aowlspt/il2cpp) for the rest of that surface.

There is therefore no object browser to write, because there is nothing to
enumerate. What can be built is a pointer walker with a very good safety story,
and a vocabulary for moving between objects without ever asking a name.

## Wiring

The command channel is a **file** beside the DLL, `aowlspt-inspect.txt`, polled
by the host's existing tick loop. Answers land in `aowlspt-inspect-out.txt` and
in the host log. No new socket, no new thread, no port to collide with, nothing
left listening. A file is also the only channel scriptable from a shell with no
UI — which is the working situation: a human at the keyboard of the game, an
agent driving it from outside.

Execution has to be on Unity's **main thread**, because managed access is. It
gets there by **riding an existing detour** on `EFT.UI.PreloaderUI::Update` — the
same one the F3 overlay and the menu-label feature use — by aliasing its slot.
Two detours on one function is a bug, not a pattern: the second overwrites the
first's trampoline. So there is exactly one detour, and the dispatcher calls
every rider whose slot matches. The host's place in the system is on the
[Architecture](/docs/aowlspt/architecture) page.

## The grammar

```
read/write EXPR TYPE     i8..i64 u8..u64 f32 f64 ptr bool str klass
parent EXPR [N]   children EXPR   tree EXPR [DEPTH]   find NAME [ROOT]
component EXPR TypeName   rect EXPR   label EXPR   fields EXPR [N]
call TARGET SIG [ARGS]    click EXPR / invoke EXPR    allow write
let NAME EXPR   wait N   until EXPR [FRAMES]
EXPR = $anchor | 0xhex ( +0xNN | @0xNN )*   '+' moves, '@' DEREFERENCES
```

`+` is pointer arithmetic; `@` is a dereference. **Every `@` is a place the
process can die**, which is what the next section is about.

## The safety discipline

- **Every hop goes through a readability guard.** Never a faulting dereference
  used as a probe — you check, then you read.
- **A breadcrumb is written before every dereference**, so a caught fault reports
  the **last hop attempted** and the pointer it was given. "It crashed somewhere"
  is not a diagnostic.
- **One SEH guard per command**, never nested — the guard is not re-entrant — and
  per *command* rather than per *batch*, so a bad address on line 3 does not take
  lines 4 through 20 with it.
- Every loop capped, every output capped.
- Writes need **two** switches: a host flag *and* an `allow write` line in the
  batch itself.
- It self-disables after N faults.

## What it cannot do

It cannot **name a type**. `klass` reports the raw `Il2CppClass*` and nothing
else. Two objects with the same klass pointer are the same type — genuinely
useful — but *which* type has to come from offline metadata.

It cannot **enumerate fields**. `fields` classifies each 8-byte slot by what the
bytes look like, and says in its own output that it is guessing.

Both limits are printed rather than smoothed over, for the reason in
[Refusing beats guessing](#refusing-beats-guessing).

## Findings

Each of these previously cost a full rebuild cycle to learn.

### EFT's buttons are not `Button`s

They are `DefaultUIButton`, which is **not** a `UnityEngine.UI.Button`. Proven
live rather than assumed: `GetComponent("Button")` and `GetComponent("Selectable")`
both return NULL on one, while `GetComponent("MonoBehaviour")` returns it — and
the same probe confirms Unity's string overload *does* match base type names, so
the NULLs mean what they look like.

The real click event is `OnClick`, a UnityEvent at **+0x120**. At **+0x100** sits
`_iconContainer`, a GameObject — and +0x100 is exactly the slot
`UnityEngine.UI.Button` uses for `m_OnClick`. A Button-shaped "invoke" therefore
calls `UnityEvent::Invoke` on a GameObject, and the batch leaves through its
guard.

### A false positive you can hear

Calling `ButtonFeedback::OnPointerClick` **plays the click sound** and does
nothing else. Audible, immediate, and indistinguishable from a successful press.

### Names lie; read the displayed text

The UI object named `CharacterSlotView_pvp` is labelled **"PvE"**. Selecting by
object name selects the wrong thing; you have to read the text a player sees.

### A caught fault is not free

The guard keeps the game alive, but it unwinds the *whole* guarded body —
statements after the faulting call never run. A settings page cloned itself on
every visit because a `renderedFor` assignment two statements past a fault never
executed. From a later read, **"did not persist" and "never executed" look
identical**. A log line placed immediately after the statement tells them apart
in one build.

## Refusing beats guessing

The inspector's own defects were found by using it, and every one was the same
species: **a confidently wrong answer**.

A failed `component` lookup left the *previous* batch's pointer bound. The next
command duly pressed the wrong object and printed a complete, coherent, entirely
fictional field map of a Button that does not exist. Nothing about the output
looked wrong.

`label` on a Transform answered `text = ""`. That reads as "the label is empty."
It is not an answer at all — it is a lookup that did not apply, formatted as a
measurement.

The fix in both cases was the same:

- A failed lookup **unbinds** the anchor rather than leaving a stale one.
- Feeding a GameObject to a walker that wants a Transform is **refused**. It used
  to fault, and worse, could read a plausible `childCount` and invent a hierarchy
  of wrong children without faulting at all.
- `find` reports whether it `searched EXHAUSTIVELY` or `STOPPED EARLY`, because
  "not found" and "ran out of budget" are different facts.
- `state` explains *why* an anchor is null instead of printing null and leaving
  you to guess.

> For an instrument, a crash is a bad afternoon; a wrong answer delivered
> plausibly is a wrong model of the system that you then build on for a week.
> Most of the engineering here is not in the reads — it is in making every
> failure path announce itself.

## Driving, not just asking

Once the client can be asked questions cheaply, it can be *driven* cheaply. The
same channel takes the game from a cold launch to the main menu with no human
present — and selects a game mode by the text a player sees on the slot, rather
than by the object name, because the inspector established that the object name
is lying.
