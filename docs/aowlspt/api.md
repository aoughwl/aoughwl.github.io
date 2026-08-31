# The mod API

::: tip The complete, generated reference is [here](./reference/api)
This page is the **orientation**: what the modules are for and how they fit
together, written for someone who has not opened the source. It is hand-written,
so treat any specific number on it as indicative.

Every exported symbol — signature, doc comment and the `file:line` it came from
— lives in **[the generated API reference](./reference/api)**, extracted from
`aowl/src/aowlspt/*.nim` by `tools/gendocs.py`. Where the two disagree, the
generated pages are the ones to believe: they were read out of the source, not
typed by hand.
:::

The nimony surface a mod is written against. `aowl/src/aowlspt.nim` is 1,493
lines and is what `import aowlspt` gives you: the ABI, made ordinary. The
submodules sit on top of it and none of them reaches around it.

| module | lines | for |
|---|---:|---|
| `aowlspt` | 1,493 | everything — logging, config, routes, events, timers, `call`, `patch`, the store, the typed frame, `exportMod` |
| `aowlspt/game` | 913 | the client-side high-level API: types, live objects, hooks |
| `aowlspt/server` | 778 | the backend-side high-level API: routes, the database, config, JSON building |
| `aowlspt/settings` | 232 | declaring the config keys a mod has, so the MODS tab can draw them |
| `aowlspt/json` | 690 | reading and editing a document without rebuilding it |
| `aowlspt/fast` | 1,370 | the per-frame path: bind once, then call |
| `aowlspt/il2cpp` | 754 | the binding to the IL2CPP runtime's own C API |
| `aowlspt/abi` | 294 | the raw types and status constants, re-exported by `aowlspt` |
| `aowlspt/sync` | 93 | the mod-side lock |

[[toc]]

---

## The smallest whole mod

```nim
import aowlspt

proc onLoad(): Status =
  success "hello from " & hostName()
  Ok

exportMod(guid = "you.hello", name = "Hello", author = "you",
          version = "1.0.0", sptRange = "*",
          sides = {sideServer, sideClient, sideSim},
          onLoad = onLoad)
```

`exportMod` goes **last** in the module — the handlers have to be declared
before they are named. Unsupplied hooks default to no-ops rather than to nil, so
the host never has a null function pointer to guard against.

## Core types

| symbol | definition | |
|---|---|---|
| `Status` | `int32` | `Ok` is 0; every failure is negative |
| `Handle` | `uint64` | an opaque host-side object; `0` is null |
| `Side` | `enum sideServer = 1, sideClient, sideSim` | which host you are in |
| `LogLevel` | `enum llTrace, llDebug, llInfo, llSuccess, llWarn, llError` | |
| `RouteKind` | `enum rkStatic, rkDynamic` | |
| `PatchKind` | `enum pkPrefix, pkPostfix, pkFinalizer` | |
| `ModFlag` | `enum mfHotReloadable, mfThreadSafe` | `ModFlags = set[ModFlag]` |
| `ArgKind` | `enum akNone, akInt, akFloat, akDouble, akObject, akValue, akBigValue, akVoid, akStack, akUnknown` | what one slot of a typed frame is, decided once at registration |

Status constants: `Ok`, `ErrGeneric`, `ErrAbi`, `ErrNotFound`, `ErrBadArg`,
`ErrDecode`, `ErrUnsupported`, `ErrWrongThread`, `ErrDisposed`, `ErrModFault`,
`ErrConfigParse`.

## `aowlspt` — the base module

### Who am I, and where

| symbol | signature | what it does |
|---|---|---|
| `side` | `proc (): Side` | which host loaded this mod. The one guard every portable mod uses. |
| `hostName` | `proc (): string` | e.g. `"aowlspt-backend"` |
| `hostVersion` | `proc (): string` | |
| `sptVersion` | `proc (): string` | empty on the sim |
| `gameVersion` | `proc (): string` | the EFT build; empty server-side |
| `modDir` | `proc (): string` | absolute path to this mod's own directory |
| `dataDir` | `proc (): string` | writable scratch owned by this mod |
| `nowMs` | `proc (): int64` | |
| `lastError` | `proc (): string` | text of the last failure on this thread. Every non-OK status is paired with one. |
| `hostReady` | `proc (): bool` | |
| `hostApiSize` | `proc (): int` | the **watermark** — what a capability test reads |
| `expectedApiSize` | `proc (): int` | `sizeof(HostApi)` on the mod's side |

### Logging

| symbol | signature |
|---|---|
| `log` | `proc (level: LogLevel; message: string)` |
| `trace` `debug` `info` `success` `warn` `error` | `proc (m: string)` |

### Configuration

| symbol | signature | what it does |
|---|---|---|
| `configGet` | `proc (key: string; outText: var string): Status` | `ErrNotFound` means "absent, use your default"; `ErrConfigParse` means the **file** is broken and no key in it is real |
| `configSet` | `proc (key: string; valueJson: string): Status` | |

### Routes, events, timers

| symbol | signature | what it does |
|---|---|---|
| `route` | `proc (url: string; kind: RouteKind; handler: RouteHandler): Status` | backend and sim only |
| `on` | `proc (event: string; handler: EventHandler): Status` | subscribe |
| `emit` | `proc (event: string; payload: string = ""): Status` | |
| `after` | `proc (delayMs: int; handler: TickHandler): Status` | one shot |
| `every` | `proc (intervalMs: int; handler: TickHandler): Status` | repeating |
| `onMainThread` | `proc (handler: TickHandler): Status` | run once on the host's main thread |
| `everyMain` | `proc (intervalMs: int; handler: TickHandler): Status` | |
| `stopMainRepeats` | `proc (): int` | |
| `scheduledSlots` | `proc (): int` | |
| `registeredRoutes` / `registeredEvents` / `registeredPatches` / `registeredTypedPatches` | `proc (): int` | what this mod currently holds |

> `onMainThread` **on the client is conditional and says which it gave you.**
> There is no API that hands a native DLL Unity's player loop, so the host
> detours a method Unity runs every frame and drains the queue from inside it.
> If none of its candidates binds, it warns at boot and falls back to its own
> thread. Ask with `call("aowlspt.host::main_thread")`; `bound` is true only
> once the hook has actually fired.

### The database (backend / sim)

| symbol | signature | what it does |
|---|---|---|
| `dbGet` | `proc (path: string; outText: var string): Status` | dotted path |
| `dbPatch` | `proc (path: string; patchJson: string): Status` | **merges**, and **creates a path that is not there** |

`dbPatch` merging rather than replacing is the difference between a mod system
and a pile of mods that happen to coexist: two mods editing sibling fields of
the same item do not clobber each other. And creating an absent path is what
lets a content mod — a new location, a new bot type, a table of its own —
express what it is doing instead of carrying a workaround.

### Reflection (client)

| symbol | signature | what it does |
|---|---|---|
| `call` | `proc (target, argsJson: string; outText: var string): Status` | `"Namespace.Type::Method"` |
| `resolve` | `proc (typeName: string; outHandle: var Handle): Status` | |
| `release` | `proc (h: Handle)` | |

### Patching (client)

| symbol | signature |
|---|---|
| `patch` | `proc (target: string; kind: PatchKind; handler: PatchHandler; withArgs = false): Status` |
| `patchTyped` | `proc (target: string; kind: PatchKind; handler: TypedPatchHandler): Status` |
| `patchContinue` | `func (): PatchResult` |
| `patchReplace` | `func (json: string): PatchResult` |
| `typedPatchesReady` | `proc (): bool` — the revision-4 capability test |

### The store (all hosts, revision 2)

| symbol | signature |
|---|---|
| `storeReady` | `proc (): bool` |
| `storeGet` | `proc (key: string; outText: var string): Status` |
| `storeSet` | `proc (key, value: string): Status` |
| `storeList` | `proc (prefix: string; outJson: var string): Status` |

### Addresses and pins (client, revision 3)

| symbol | signature | what it does |
|---|---|---|
| `livePointersReady` | `proc (): bool` | |
| `pointerOf` | `proc (h: Handle; outAddress: var uint64): Status` | **8 ns**, against 1112 for the boxed property read it replaces |
| `pinHandle` | `proc (h: Handle; outPinned: var Handle): Status` | keeps an object alive at the stated cost |

### Notifications (backend, revision 5)

| symbol | signature |
|---|---|
| `notifyReady` | `proc (): bool` |
| `notifyPush` | `proc (session: string; ...): Status` — a push down that session's notifier websocket |

### The typed patch frame

The revision-4 hook is handed a borrowed view of the saved registers instead of
a JSON payload. `PatchFrame` is read field-wise through these:

| symbol | signature | what it does |
|---|---|---|
| `frameLive` | `proc (f: PatchFrame): bool` | is this frame still the one you were called for |
| `frameSerial` | `proc (f: PatchFrame): uint32` | |
| `frameSize` / `expectedFrameSize` | `proc (...): int` | the same watermark discipline as `HostApi` |
| `argCount` | `proc (f: PatchFrame): int` | |
| `kindOf` / `retKindOf` | `proc (f: PatchFrame; i: int): ArgKind` | decided once, at registration |
| `framePostfix` / `frameStatic` | `proc (f: PatchFrame): bool` | |
| `selfPointer` | `proc (f: PatchFrame): uint64` | |
| `argInt` / `argFloat` / `argPointer` | `proc (f: PatchFrame; i: int; ok: var bool): T` | the `ok` out-parameter is not optional — a slot that is not what you asked for says so |
| `resultInt` / `resultFloat` / `resultPointer` | `proc (f: PatchFrame; ok: var bool): T` | postfix only |
| `setResultInt` / `setResultFloat` / `setResultPointer` / `setResultVoid` | `proc (f: PatchFrame; v: T): bool` | |
| `frameContinue` / `frameReplace` | `func (): TypedResult` | |
| `frameWhy` / `frameWhyText` | `proc (): int` / `proc (): string` | why the last read refused |

### Exporting a mod

```nim
template exportMod*(guid, name, author, version, sptRange: string;
                    sides: set[Side];
                    onLoad:    proc (): Status = noopLoad;
                    onUpdate:  proc (elapsedMs: int64): Status = noopUpdate;
                    onUnload:  proc (): Status = noopUnload;
                    stateSave: proc (): string = noopStateSave;
                    stateLoad: proc (state: string): Status = noopStateLoad;
                    flags: ModFlags = {})
```

It emits `aowlspt_abi_version`, `aowlspt_describe` and `aowlspt_init` — the
three exports the [ABI](abi#the-three-exports) names — and nothing else.

---

## `aowlspt/game` — the client-side high-level API

Reflection made ordinary: a `GameType` is a named type that resolves lazily, a
`GameObj` is a live handle, and both take the same `invoke`/`get`/`set`.

```nim
import aowlspt
import aowlspt/game

var Player = gameType("EFT.Player")
var world  = whenReady("EFT.GameWorld")

proc onUpdate(elapsedMs: int64): Status =
  if world.ready():                      # true once, when the game exists
    info "health " & $Player.get("Health").asFloat()
    discard Player.invoke("Heal", 50)
  Ok
```

### Values and results

| symbol | signature | what it does |
|---|---|---|
| `v` | `proc (x: int \| float \| bool \| string): Value` | one overload per scalar |
| `argsJson` | `proc (args: openArray[Value]): string` | |
| `CallResult` | object | every call answers one |
| `failed` | `proc (r: CallResult): bool` | |
| `asText` / `asInt` / `asFloat` / `asBool` | `proc (r: CallResult; default = ...): T` | defaults rather than exceptions |
| `isNull` | `proc (r: CallResult): bool` | |

### Types

| symbol | signature | what it does |
|---|---|---|
| `gameType` | `template (typeName: string): GameType` | declare a named type; nothing is resolved yet |
| `resolveNow` / `available` | `proc (t: var GameType): bool` | resolve, and say whether it worked |
| `invoke` | `proc (t: var GameType; member: string; ...): CallResult` | overloads for 0–3 `Value`s and for bare `int` / `float` / `string` / `bool` |
| `get` / `set` | `proc (t: var GameType; property: string; ...): CallResult` | properties |
| `field` / `setField` | `proc (t: var GameType; name: string; ...): CallResult` | fields |
| `instanceOf` | `proc (t: var GameType; property = "Instance"): GameObj` | the singleton pattern, once |
| `whenReady` | `template (typeName: string): WhenReady` | |
| `ready` | `proc (w: var WhenReady): bool` | **true once**, when the type appears |

### Live objects

| symbol | signature | what it does |
|---|---|---|
| `asObject` / `isObject` | `proc (r: CallResult): GameObj` / `bool` | a reference return is a handle |
| `noObject` | `proc (): GameObj` | |
| `invoke` / `get` / `set` / `field` / `setField` | `proc (o: GameObj; ...)` | the same shapes as `GameType` |
| `child` | `proc (o: GameObj; property: string): GameObj` | chain without unpacking |
| `alive` | `proc (o: GameObj): bool` | |
| `release` | `proc (o: GameObj)` | |

### Hooks

| symbol | signature | what it does |
|---|---|---|
| `hook` | `proc (target: string; handler: HookHandler): Status` | the plain prefix |
| `hookArgs` | `proc (target: string; handler: ArgHookHandler): Status` | the arguments too — **up to four**; the fifth onward is omitted rather than guessed |
| `hookReturn` | `proc (target: string; handler: ArgHookHandler; withArgs = ...): Status` | the postfix |
| `hookTyped` | `proc (target: string; handler: TypedPatchHandler): Status` | the per-frame path |
| `hookReturnTyped` | `proc (target: string; handler: TypedPatchHandler): Status` | |
| `carryOn` | `func (): HookResult` | let the original run |
| `stopWith` | `func (json: string): HookResult` | suppress it, and answer this instead |
| `stopVoid` | `func (): HookResult` | suppress a `void` method |
| `replaceResult` / `keepResult` | `func (...): HookResult` | postfix |
| `thisHandle` / `thisPointer` / `hookResult` / `memberRaw` / `handleIn` | `proc (payload: string): ...` | reading the JSON payload without a parser |

`stopWith` is checked against the method's declared return type; a replacement
that does not match is refused rather than written into the game's registers.

---

## `aowlspt/server` — the backend-side high-level API

```nim
import aowlspt
import aowlspt/server

proc onStatus(url, body, session: string): string =
  var o = obj()
  put(o, "ok", true)
  put(o, "session", session)
  result = done(o).text

proc onItem(url, body, session: string): string =
  let id = pathAfter(url, "/aowlspt/item/")
  if id.len == 0: return errJson("no item id in " & url)
  let weight = dbRead("templates.items." & id & "._props.Weight")
  if not weight.ok: return errJson("no such item: " & id)
  var o = obj()
  put(o, "ok", true)
  put(o, "weight", weight.asFloat())
  result = done(o).text

proc onLoad(): Status =
  # `!= sideClient`, not `== sideServer`, and the difference is the whole
  # example working or silently not: the sim presents as `sim`.
  if side() == sideClient:
    info "this mod serves; there is no HTTP server inside the game"
    return Ok
  discard serve("/aowlspt/status", onStatus)
  discard servePrefix("/aowlspt/item/", onItem)
  Ok
```

That comment is copied verbatim from `examples/gameserver`, and it is there
because the guard was written the other way round first: under `aowlspt-sim` the
mod registered **no routes and wrote nothing to the database**, the gate
exercised two lines and reported ok, *because a run that does nothing exits
zero*. `examples/hello` had the identical bug, and the simulator now carries a
bespoke "no route registered for…" message whose only job is to explain the
resulting confusion — which is how you can tell it has happened to people.

### Routing

| symbol | signature | what it does |
|---|---|---|
| `serve` | `proc (url: string; handler: Handler): Status` | exact match |
| `servePrefix` | `proc (prefix: string; handler: Handler): Status` | most of the client's real endpoints are shaped this way |
| `pathAfter` | `proc (url, prefix: string): string` | the id out of the path |

### The database

| symbol | signature | what it does |
|---|---|---|
| `dbRead` | `proc (path: string): DbValue` | |
| `asText` / `asInt` / `asFloat` | `proc (v: DbValue; default = ...): T` | |
| `dbWrite` | `proc (path: string; patch: Json \| JsonObject \| JsonArray \| string): Status` | merges |
| `dbKeys` | `proc (path: string; into: var seq[string]): Status` | the key list without the values — **230 bytes instead of 12.5 MB** |
| `dbKeysOrRead` | `proc (path: string; into: var seq[string]; scanned: var bool): Status` | `dbKeys` where the host has it, a scan where it does not, and it tells you which |
| `dbKeysReady` | `proc (): bool` | |

### Configuration

| symbol | signature |
|---|---|
| `setting` | `proc (key: string): ConfigValue` |
| `asText` / `asInt` / `asFloat` / `asBool` | `proc (c: ConfigValue; default = ...): T` |
| `configFaulted` | `proc (): bool` — the file is broken, not the key |

### Building JSON without a DOM

| symbol | signature |
|---|---|
| `obj` / `arr` | `proc (): JsonObject` / `JsonArray` |
| `put` | `proc (o: var JsonObject; key: string; value: Json \| string \| int \| float \| bool \| JsonObject \| JsonArray)` |
| `add` | `proc (a: var JsonArray; value: ...)` — the same set |
| `done` | `proc (o: JsonObject): Json` / `proc (a: JsonArray): Json` |
| `jstr` / `jint` / `jfloat` / `jbool` / `jnull` / `raw` | `proc (...): Json` |
| `objOf` | `proc (key: string; value: ...): JsonObject` — the one-field case |
| `emptyArray` / `emptyObject` | `proc (): Json` |
| `escapeText` | `proc (s: string): string` |
| `okJson` / `errJson` | `proc (...): string` |

### The client's envelope

Every route the emulator answers goes out as `{"err":0,"errmsg":null,"data":…}`.

| symbol | signature |
|---|---|
| `envelope` | `proc (data: Json \| string \| JsonObject \| JsonArray): string` |
| `envelopeNull` | `proc (): string` |
| `failure` | `proc (code: int; message: string): string` |

### Persistence, events, timers

| symbol | signature |
|---|---|
| `save` | `proc (key: string; value: Json \| string \| JsonObject): Status` |
| `load` | `proc (key: string): Stored` |
| `saved` | `proc (key: string): bool` |
| `savedKeys` | `proc (prefix = ""): seq[string]` |
| `broadcast` | `proc (name: string; payload: ...): Status` |
| `onEvent` | `proc (name: string; handler: EventHandler): Status` |
| `afterMs` / `everyMs` | `proc (ms: int; handler: TickHandler): Status` |

---

## `aowlspt/settings` — declaring what your config keys are

A `config.json` says what a value *is*, never what it *means*. This module is
where a mod says the rest once — the type, the range, the human label, whether
the key is actually wired to anything — so the **MODS** tab in Tarkov's own
settings screen can draw the right native control for it and write an edit back
to the same file the mod already reads.

```nim
import aowlspt/settings

declareSettings(@[
  floatSetting("opticFovMulti", "Optic FOV multiplier", 1.0,
               lo = 0.5, hi = 2.0, step = 0.01, category = "FOV",
               description = "FOV scale while aiming a magnified sight"),
  boolSetting("changeMouseSensitivity", "Scale mouse sensitivity", true,
              category = "Sensitivity"),
  enumSetting("quality", "Texture quality", "high", @["low", "medium", "high"]),
  keybindSetting("zoomToggleKey", "Toggle-zoom key", "M",
                 category = "Toggle zoom", implemented = false,
                 description = "Read but not wired yet")])
```

One builder per control:

| builder | control drawn |
|---|---|
| `boolSetting(key, label, default)` | a toggle |
| `intSetting(key, label, default, lo, hi, step)` | a stepped slider |
| `floatSetting(key, label, default, lo, hi, step)` | a slider |
| `enumSetting(key, label, default, options)` | a dropdown |
| `stringSetting(key, label, default)` | a text field |
| `keybindSetting(key, label, default)` | a key-capture box |

Every builder takes the same optional trailing arguments: `category` (the
section the row groups under on your subtab), `description` (one sentence of
help), and `implemented` (`false` draws the row greyed with the reason, for a
key that is carried but not yet acted on).

| | |
|---|---|
| `declareSettings(settings)` | register the schema. Call it from `onLoad`. |
| `declaredSettings()` | what this mod declared |
| `declaredSchemaJson()` / `schemaJson(settings)` | the schema as the UI fetches it |
| `applySetting(key, valueJson)` | apply one edit, persisting through `config.json` |
| `applySettingFromBody(body)` | the same, from the JSON body of an edit request |

The declaration is pure data and never touches the runtime, so a mod that
declares a schema and does nothing else is still a no-op mod. This is the
replacement for the BepInEx `ConfigEntry` / ConfigurationManager pattern; nine
of the shipped mods already use it.

---

## `aowlspt/json` — reading a document without rebuilding it

A cursor over the text, not a parse into objects. `JsonRef` is a found-or-not
view; `Doc` and `List` are editable.

| symbol | signature | what it does |
|---|---|---|
| `whole` | `proc (text: string): JsonRef` | |
| `field` | `proc (j: JsonRef \| text: string; path: string): JsonRef` | dotted path |
| `child` / `at` | `proc (j: JsonRef; key: string \| index: int): JsonRef` | |
| `exists` / `isNull` / `isText` / `isObject` / `isArray` | `proc (j: JsonRef): bool` | |
| `asText` / `asInt` / `asFloat` / `asBool` | `proc (j: JsonRef; default = ...): T` | |
| `count` / `keys` / `each` / `members` | `proc (j: JsonRef): ...` | |
| `raw` | `proc (j: JsonRef): string` | the untouched source text |
| `notFound` | `func (): JsonRef` | |
| `parseObject` / `newDoc` | `proc (...): Doc` | |
| `has` / `get` / `getRaw` | `proc (d: Doc; name: string): ...` | |
| `setRaw` / `setText` / `setNumber` / `setBool` / `remove` | `proc (d: var Doc; ...)` | |
| `text` | `proc (d: Doc): string` / `proc (l: List): string` | back to a document |
| `parseArray` / `newList` | `proc (...): List` | |
| `len` / `at` / `add` / `replaceAt` / `removeAt` | `proc (l: ...; ...)` | |
| `quoted` / `escapeText` | `proc (s: string): string` | |

---

## `aowlspt/fast` — bind once, then call

The per-frame path. A binding costs **1–9 µs**, almost all of it `findClass`
walking every loaded assembly; a bound call then costs **~10 ns** and a bound
field read **1.87 ns**. That is the whole argument for binding once: it costs
about as much as a hundred bound calls, and then it costs nothing.

| symbol | signature | what it does |
|---|---|---|
| `bindMethod` | `proc (rt: Il2Cpp; owner, member: string; argc: int): Binding` | by name |
| `bindMethodAs` | `proc (rt: Il2Cpp; owner, member: string; ...): Binding` | with a declared shape |
| `bindInClass` / `bindOnObject` | `proc (rt: Il2Cpp; ...): Binding` | takes the class off an instance — reaches a **generic instantiation**, which has no name to look up |
| `bindRaw` | `proc (rt: Il2Cpp; cls: Il2CppClass; owner, member: string; ...): Binding` | the `Vector3`-shaped cases |
| `callVoid` / `callInt` / `callInt32` / `callBool` / `callPtr` / `callFloat` | `proc (b: Binding; self: Il2CppPtr; a: var Args): T` | |
| `callShapedPtr` / `callShapedVoid` / `callShapedFloat` | `proc (b: Binding; a: var ShapedArgs): T` | |
| `noArgs` / `reset` / `addInt` / `addBool` / `addFloat` / `addPtr` | `proc (a: var Args; ...)` | `MaxArgs* = 4`, `MaxSlots* = 5` (including `this`) |
| `argsI` / `argsF` / `argsP` / `argsII` / `argsFF` | `proc (...): Args` | the common shapes, inline |
| `bindField` / `bindStaticField` | `proc (rt: Il2Cpp; owner, fieldName: string): FieldBinding` | |
| `readInt` / `readInt32` / `readBool` / `readFloat` / `readPtr` | `proc (f: FieldBinding; obj: Il2CppPtr): T` | cached offset, direct load |
| `writeInt` / `writeBool` / `writeFloat` / `writePtr` | `proc (f: FieldBinding; obj: Il2CppPtr; v: T)` | `writePtr` routes reference stores **through IL2CPP's write barrier** |
| `writePtrRaw` | `proc (f: FieldBinding; obj: Il2CppPtr; v: Il2CppPtr)` | the deliberate opt-out, and the only pointer store offered for statics |
| `barrierReady` | `proc (f: FieldBinding): bool` | says which one you are getting |
| `classifyType` / `classifyClass` / `classifyDeclared` / `describe` | `proc (...): FastKind` | |
| `perfCounter` / `perfFreq` / `nanosBetween` | `proc (...): int64` | |
| `allocationCount` / `allocatedBytes` / `liveBytes` / `allocProbeOk` | `proc (): int64` / `bool` | a mod can assert its own per-frame path allocates nothing |

`bindMethod` **refuses** doubles, five-or-more arguments and arrays, rather than
binding them wrongly. It no longer refuses enums.

---

## `aowlspt/il2cpp` — the runtime's own C API

`openIl2Cpp` resolves **62 named entries** (`NumEntries`) out of
`GameAssembly.dll`, of which **9 are `Essential`** and a missing one is named
rather than discovered later:

| symbol | signature |
|---|---|
| `openIl2Cpp` | `proc (path: string = ""): Il2Cpp` |
| `has` | `proc (rt: Il2Cpp; e: Entry): bool` |
| `missingEssential` | `proc (rt: Il2Cpp): seq[string]` |
| `findClass` / `classFromName` / `classFromType` | `proc (...): Il2CppClass` |
| `findMethod` / `findField` / `findProperty` | `proc (...)` |
| `nextMethod` / `nextField` / `nextProperty` | iterator-shaped enumeration |
| `invoke` | `proc (rt: Il2Cpp; m: Il2CppMethod; obj: Il2CppObject; ...)` |
| `methodPointer` / `methodFlags` / `methodIsStatic` / `methodParamCount` | |
| `fieldOffset` / `fieldFlags` / `fieldIsStatic` / `staticFieldData` | |
| `newString` / `readString` / `readCString` | |
| `valueBox` / `objectUnbox` / `objectNew` / `objectClass` | |
| `gcHandleNew` / `gcHandleTarget` / `gcHandleFree` | |
| `threadAttach` / `threadDetach` / `threadCurrent` | |
| `writeBarrier` / `hasWriteBarrier` / `writeBarrierFn` | |
| `boxHeaderBytes` / `valueWidth` / `classInstanceSize` / `classIsValueType` | |

The README reports **242 exported functions** on the post-1.0 client
`tools/il2cppprobe.nim` was run against. 62 is what aowlspt binds of them.
