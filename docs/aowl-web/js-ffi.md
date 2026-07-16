---
title: JavaScript FFI and DOM
parent: aowl-web
grand_parent: Backends
nav_order: 4
---

# JavaScript FFI and the DOM

The JS backend lays native Nim data out as byte offsets into one linear
`ArrayBuffer`. A genuine JS value — a string, object, function, or DOM node —
can't live there. `tests/jsbackend/jsffi.nim` is the prototype interop layer that
bridges the two worlds, and the DOM bindings sit on top of it.

> This is the FFI surface exercised by `tffi.nim` and `tdom.nim` in the JS suite.
> It's a prototype: the module's own header calls it that. Everything documented
> here is what those two tests actually run.

> **Where the FFI package lives.** The canonical FFI/DOM library is maintained in
> a separate repo, [`aoughwl/js`](https://github.com/aoughwl/js) — that's the
> package aowl-web's JS DOM examples build on. The copies of `jsffi.nim`,
> `domlib.nim`, and `dom.nim` under `tests/jsbackend/` are **vendored test
> fixtures**: in-tree snapshots so the suite is self-contained, not the source of
> truth. Track `aoughwl/js` for the maintained version.

## The seam: `importc` → a runtime function

An `importc` proc with no body lowers to a plain call of the named runtime-side
function. `runtime.js` provides those functions; `jsffi.nim` wraps them:

```nim
proc rawNumToJs(x: int): int32 {.importc: "_numToJs".}   # calls runtime.js's _numToJs
```

The raw seam deals only in **`int32` handles** — never in an owning wrapper — so
no owning value is ever silently duplicated across the FFI boundary.

## `JsValue`: an owning handle

A JS value lives in a side table inside `runtime.js`; `JsValue` is an opaque,
**GC-integrated** handle to a slot in that table (the generalisation of the
`_fns` proc-pointer table the backend already uses):

```nim
type JsValue* = object
  h: int32
```

Ownership is handled by ARC hooks, so you never release a handle by hand:

- `=destroy` releases the slot (the runtime treats handle `0` as nil → no-op);
- `=copy`/`=dup` allocate a **new** slot to the *same* JS value, so every copy is
  independently owned and there's no double free;
- a moved-from `JsValue` becomes `0` (nil), whose `=destroy` is a no-op.

Transient values — a method result you don't keep, a member-name handle — are
reclaimed at scope exit. `undefined` is the nil handle; both JS `undefined` and
`null` marshal to it. `liveHandles()` returns the live-slot count for leak tests.

## Marshalling

| Nim → JS | JS → Nim |
|---|---|
| `toJs(x: int)` → Number | `toInt(v)` |
| `toJs(x: float)` → Number | `toFloat(v)` |
| `toJs(b: bool)` | `toBool(v)` |
| `toJs(s: string)` → real JS string (UTF-8) | `toStr(v)` / `$v` (`String(v)`) |

`==` on `JsValue` is JS `===`; `isNil` is true for the nil handle.

## Globals, properties, methods, construction

```nim
let m = global("Math")                        # globalThis["Math"]
echo toInt(m.call("max", toJs(3), toJs(7)))   # m.max(3, 7)  → 7

let o = newJsObject()                          # {}
o.set("year", toJs(2026))                      # o.year = 2026
echo toInt(o.get("year"))                      # o.year       → 2026
echo global("JSON").call("stringify", o).toStr # JSON.stringify(o)
```

- `global(name)` — `globalThis[name]`.
- `get`/`set` — `obj[name]` and `obj[name] = val`.
- `call(obj, name, …)` — `obj.name(...)`, overloaded for 0–3 args; `apply`/
  `applyArgs` for any argument count (marshalled through a JS array).
- `newOf(ctorName, …)` — `new globalThis[ctorName](...)`.
- introspection: `jsTypeof(v)`, `hasProp(obj, name)` (`name in obj`),
  `instanceOf(v, ctorName)`.
- JS arrays: `newJsArray()`, `len`, `add` (`push`), `[]`/`[]=`.

(`tffi.nim` runs all of the above against the host's `console`, `Math`, and
`JSON`.)

## Nim procs as JS callbacks

A Nim proc can cross as a JS function — the basis for event handlers:

```nim
type
  JsProc0* = proc() {.nimcall.}
  JsProc1* = proc(ev: JsValue) {.nimcall.}   # a DOM event handler

proc toJs*(p: JsProc0): JsValue
proc toJs*(p: JsProc1): JsValue
```

A `JsProc1`'s `JsValue` argument is valid only for the duration of the call — the
runtime releases the handle when the callback returns, matching the DOM event
contract.

## The DOM binding

Two layers sit on `jsffi`:

- **`domlib.nim`** — *generated* from `@webref/idl` (the WHATWG/W3C IDL) by
  `gen/idl2nim.js`. Each interface (`Node`, `Element`, `Document`,
  `DocumentFragment`, …) is a `JsValue` alias, and interface-typed members are
  typed by name so DOM navigation reads like a real DOM API. Regenerate with the
  command in the file header; don't hand-edit it.
- **`dom.nim`** — the hand-written ergonomic slice the tests import.

`tests/jsbackend/tdom.nim` drives a real WHATWG DOM (jsdom, installed by
`tdom.env.js`) end to end from compiled Nim:

```nim
import dom

let doc = document()
let ul = doc.createElement("ul")
ul.id = "list"
for it in ["alpha", "beta", "gamma"]:
  let li = doc.createElement("li")
  li.textContent = it
  discard ul.appendChild(li)
discard doc.body.appendChild(ul)

let btn = doc.createElement("button")
btn.addEventListener("click", onClick)         # onClick is a Nim proc(ev: JsValue)
discard btn.dispatchEvent(newEvent("click"))
```

That exercises `document`, `createElement`, `id`/`textContent`/`innerHTML`,
`appendChild`, `getElementById`/`querySelector`, `addEventListener`, and
`dispatchEvent` — a Nim click handler firing off a dispatched DOM event and
reading `ev.target.textContent` back.

## Requirements

The DOM tests need `npm install` in `tests/jsbackend` (for jsdom); a bare
checkout without it **skips** those tests rather than failing. Node itself is
required for the whole JS suite — without it the suite is a loud no-op, never a
phantom pass.
