---
title: The browser build's linear memory, and the frame stack that fixed it
description: aowli compiled to JavaScript spent 627 MB of a 1 GiB ceiling in four minutes and then stopped. The arena was a C stack nobody ever popped. A handoff note for whoever moves this into the runtime, where it belongs.
---

# The browser build's linear memory

This is a handoff note. The fix described here is **in the wrong place** — it is
a patch applied over a generated bundle in this repository, and it belongs in
the Leng JS runtime, where aowli and every other embedder would inherit it. What
follows is the diagnosis, the fix, the measurement, and the one case the fix must
refuse, which is the part somebody reimplementing it from the summary would get
wrong.

It is written down because the failure it describes is not specific to Jester.
It is what happens to **any** interpreter compiled through this backend the
moment it stops being a program that runs once and becomes a loop that runs
sixty times a second.

## The symptom

[The demo](/jester-demo/) stopped. Not slowly, not with a leak profile — it ran,
and then a frame raised:

```
RangeError: leng: out of linear memory (allocFixed 12 bytes at 1073741816, ceiling 1073741824)
```

Measured on the Jester tree's own `web/` lane, ticking every animation frame with
nothing throttled: **34.6 seconds, about 430 frames.** On the published page,
which was already ticking at ten frames a second rather than sixty to stretch it,
the same wall was several minutes out. Both are the same wall.

## The diagnosis

The Leng JS runtime backs the whole program with one resizable `ArrayBuffer` and
a single bump pointer, `_brk`. Two allocators share it:

- **`mmap`**, which the ported Nim allocator sits on. This one is honest: freed
  regions go on a free list, `mmap` serves from it first, and adjacent regions
  coalesce. It was made honest deliberately — an earlier no-op `munmap` leaked
  without bound, and the runtime's own comment records that a loop allocating
  *nothing* died of it while native aowli peaked at 4.5 MB.

- **`allocFixed`**, the codegen's storage for value aggregates. Its comment says
  what it is:

  > `allocFixed(n)` is the codegen's own storage for value aggregates (a C-stack
  > model: never freed)

**That comment is the bug, and it is also the fix.** "Never freed" is the right
call for a program with a `main` that runs once and exits, which is exactly what
aowli's own `webtest` is. It is fatal for a *hosted* interpreter, because the
tree-walker allocates its locals — every `takeLocal`, every `evalCaseExpr`
temporary — from that arena on every call. The host calls `update` and `drawGui`
every frame. Nothing in that is a leak in the ordinary sense: no object is
retained, nothing is reachable, there is simply no way for the pointer to go
back down. A gigabyte divided by a few kilobytes a frame is the running time of
the page.

This is why going slower did not help and was never going to. Ten frames a
second spends the same arena as sixty, over more wall time. The page's frame
rate was rationing, not performance tuning.

## The fix

A C-stack model is a thing you can pop. `tools/frame-arena.mjs` exposes a mark
and a release over `_brk`; `boot.js` takes a mark before a per-frame callback and
releases it after.

```js
const at = arenaMark();
globalThis.__inf_call(name);      // update, or drawGui
arenaRelease(at);
```

Two rules make it correct, and both matter.

**1. Only per-frame callbacks are framed.** `start` is not, and neither is the
mod load that precedes it. Whatever a mod sets up in `start` has to outlive the
call, and releasing it would hand that memory out again to the next allocation.
`stop` is not framed either. The frame stack is for calls whose allocations are
dead when the call returns, and only the per-frame ones qualify.

**2. The release refuses itself when the Nim heap grew during the call.**
This is the part that is easy to miss. `mmap` and `allocFixed` share `_brk`, so
a frame that causes the Nim allocator to ask for new pages has those pages
sitting *above* the mark — and they belong to the heap, not to the frame. Winding
`_brk` back past them would hand live heap pages out as fresh arena, which is
memory corruption that would surface somewhere else entirely, later, as
nonsense. So the runtime tracks a high-water mark of everything `mmap` has
carved, and the release is a no-op whenever the mark is below it:

```js
let _mmapHigh = 8;                          // bumped in mmap, never lowered
globalThis.__leng_release = (mark) => {
  if (mark >= _mmapHigh && mark <= _brk) { _brk = mark; return true; }
  return false;                             // the heap grew above the mark: keep it
};
```

A frame that grows the heap simply keeps its arena and the next frame starts from
there. In practice the heap stops growing within the first second and every frame
after that releases cleanly.

## The measurement

`tools/measure-demo-life.mjs` serves the published page, drives a real headless
Chrome at it, and reads the bump pointer directly — `allocFixed(0)` returns the
pointer without allocating, so this is the number itself and not an estimate
from `ArrayBuffer.byteLength`, which only doubles.

Four minutes, same mod, same tick rate, run either side of the patch:

| | linear memory spent | `draw_fill` calls |
|---|---:|---:|
| before | **627 MB** | 3948 |
| after | **7 MB** | 3990 |

```
LIMIT=240000 MOD=demo.web node tools/measure-demo-life.mjs
```

The draw counts are the control: within one percent of each other, so it is the
same work both times and not a page that got quieter. 627 MB in four minutes is
a page that dies in six and a half; 7 MB is a page with no time limit at all. The
demo's gauge still reads the pointer, because a flat line is the evidence.

## What is still broken

**A retired interpreter is never freed.** Loading a different mod builds a fresh
interpreter and abandons the previous one's state, and the frame stack cannot
touch it — that memory was allocated during a load, not during a frame, and by
rule 1 above a load is not framed. It is not framable either: the state is live
right up until the moment it is not, and nothing tells the runtime when that
moment is.

Measured at **about 1.3 MB a load — 25 MB after eighteen**:

```
LOADS=6 node tools/measure-demo-life.mjs
```

That is hundreds of loads from the ceiling rather than a handful, so the page no
longer treats it as a budget. It is a named limitation rather than a silent one,
and the overlay that explains the ceiling is still wired up as a safety net.

## Where this should actually live

In the runtime, not here. `tools/frame-arena.mjs` rewrites a *generated* file:
`web/build.sh` in the engine repository re-emits `aowli-host.js` from the nimony
frontend and the JS backend, and every fresh bundle needs the patch applied
again. That is a workaround with a shelf life.

The mark and the release are nine lines and have no dependency on Jester, on the
host surface, or on anything above the runtime. Moved into the runtime's own
prelude, with the two rules above intact, every embedder gets a frame stack and
nobody else has to find this the hard way.

## A loose end, for whoever picks this up

A second experiment is *not* shipped and is worth finishing. `example.textfield`
— the SDK's real text field, with a caret, selection, undo and a scissor-clipped
line longer than its box — runs in this browser host with **zero declined
calls** once the host answers the scissor, `devicePixelRatio` as the display
scale, the wheel, and a page-local clipboard that writes through and reads back
real `paste` events. Driven with genuine CDP mouse and key events it takes focus
and types correctly, and survives a 150-second soak.

Under *this page's* tick it does not. The field takes focus from the click and
then loses it: **9 `typed_text` calls in 116 frames**, focus gone after about
nine frames, with the pointer still inside the field's rectangle and the mouse
confirmed not held. Under the plain every-frame loop in the engine tree's `web/`
lane, with the identical host and the identical artifact, it is stable.

The difference between those two loops is therefore the clue — this page skips
frames and rate-limits, the other does not — and it is most likely the SDK's
input-edge model meeting a host that does not run a frame for every event. That
is a real finding about on-demand rendering and the edge model, not a browser
quirk, and it is worth having whichever way it resolves.
