# The C ABI

`abi/aowlspt_abi.h`, 677 lines. **Version 1, revision 5.** Every host and every
mod is nimony; this is the only place either of them speaks C, and it exists so
that neither side's language leaks through.

[[toc]]

---

## Five rules

Each one names a failure it prevents.

1. **C only.** No C++, no name mangling, no exceptions across the boundary.
   Every cross-boundary function is `cdecl` and returns a status code.
2. **One allocator, the host's.** Two separately linked modules need not share a
   CRT heap. A buffer allocated on one side and freed on the other is a crash in
   some unrelated place, later, under load.
3. **Borrowed in, owned out.** An `AowlSlice` argument is valid for that call
   only; to hand data back you fill an `AowlBuffer` from the host allocator and
   the receiver frees it.
4. **Additive versioning.** Every struct carries its own `size` first. Fields
   are appended, never inserted or reordered, and a peer checks `size` before
   touching anything added later.
5. **No SPT types in the header.** SPT renames types between point releases; a
   bridge that names fifty of them breaks every release. This one names **none**
   of them — the database is addressed by dotted path and the game is reached by
   string target through `call`. What churns underneath is data, not a header.

Rule 5 is the load-bearing one for a project that has to survive somebody else's
release cadence, and it is why the header is 677 lines rather than seven
thousand.

## The primitive types

| type | definition | notes |
|---|---|---|
| `AowlSlice` | `{ const uint8_t* ptr; int32_t len; }` | Borrowed, non-owning. `ptr` may be `NULL` iff `len` is 0. UTF-8, **not** required to be NUL-terminated. Valid for the duration of the call only. |
| `AowlBuffer` | `{ uint8_t* ptr; int32_t len; }` | Owned. The receiver frees it with the host allocator. A zeroed `AowlBuffer` is the valid "nothing returned" value. |
| `AowlHandle` | `uint64_t` | Opaque reference to a host-side object. `0` is `AOWLSPT_NULL_HANDLE`. Released with `handle_release`. |
| `AowlStatus` | `int32_t` | `0` is OK; every failure is negative. |

## Status codes

| code | | means |
|---|---:|---|
| `AOWLSPT_OK` | 0 | |
| `AOWLSPT_ERR_GENERIC` | −1 | unclassified; see `last_error` |
| `AOWLSPT_ERR_ABI` | −2 | version / struct-size mismatch |
| `AOWLSPT_ERR_NOT_FOUND` | −3 | no such route, key, service, member |
| `AOWLSPT_ERR_BAD_ARG` | −4 | null or malformed argument |
| `AOWLSPT_ERR_DECODE` | −5 | payload did not parse |
| `AOWLSPT_ERR_UNSUPPORTED` | −6 | valid request, this host cannot do it |
| `AOWLSPT_ERR_WRONG_THREAD` | −7 | must be called on the main thread |
| `AOWLSPT_ERR_DISPOSED` | −8 | handle already released |
| `AOWLSPT_ERR_MOD_FAULT` | −9 | the mod raised past its own boundary |
| `AOWLSPT_ERR_CONFIG_PARSE` | −10 | the config **file** did not parse |

The last one is worth its own paragraph, because it is a bug fix that became a
status code. `config_get` used to answer `ERR_NOT_FOUND` for two different
facts, and only one of them is about the key. *"There is no such setting, use
your default"* is ordinary. *"This file did not parse, so none of this mod's
settings are real"* is a broken install — and a mod that carries on there runs
the whole session on defaults while its config sits on disk being ignored.

That is not hypothetical. A three-byte UTF-8 BOM — which Notepad and
`Set-Content -Encoding utf8` write by default — put the mod manager in exactly
that state: `activeLists` read as empty, nothing resolved, and it wrote a
selection file naming only itself, so the next start loaded one mod out of ten
**with no error anywhere**.

The compatibility reasoning is the reason it needed no revision bump: a mod that
tests `!= AOWLSPT_OK` behaves exactly as it did, because −10 is as non-OK as −3
was. A mod that tests `== ERR_NOT_FOUND` to mean "absent, use my default" now
stops matching on a broken file — which is the fix, not a regression.

## The three exports

Every mod library exports exactly these, and nothing else.

```c
/* Cheapest possible probe: the host calls this before anything else and
 * refuses the library on a major mismatch, without running mod code. */
typedef uint32_t   (AOWLSPT_CALL *AowlAbiVersionFn)(void);

/* Fill in `out`. Called before `init`, so it must not depend on host services. */
typedef AowlStatus (AOWLSPT_CALL *AowlDescribeFn)(AowlModInfo* out);

/* Hand over the host API, take back the mod API. The mod stores `host` and may
 * call it from here on. Returning non-OK aborts the load cleanly. */
typedef AowlStatus (AOWLSPT_CALL *AowlInitFn)(const AowlHostApi* host,
                                              AowlModApi* out);
```

The symbol names are spelled out in the header so that both sides agree in one
place:

```c
#define AOWLSPT_SYM_ABI_VERSION "aowlspt_abi_version"
#define AOWLSPT_SYM_DESCRIBE    "aowlspt_describe"
#define AOWLSPT_SYM_INIT        "aowlspt_init"
```

A nimony mod never writes any of these. `exportMod` emits all three — see
[the mod API](api#exporting-a-mod).

## `AowlModInfo` — what the mod says about itself

```c
typedef struct AowlModInfo {
    int32_t   size;        /* sizeof(AowlModInfo)                          */
    uint32_t  abi_version; /* AOWLSPT_ABI_VERSION the mod was built against */
    uint32_t  abi_revision;
    AowlSlice guid;        /* reverse-dns unique id, e.g. "aowl.basement"  */
    AowlSlice name;
    AowlSlice author;
    AowlSlice version;     /* semver                                       */
    AowlSlice spt_range;   /* semver range, e.g. "~4.1.0"                  */
    uint32_t  sides;       /* bitmask: 1<<AowlSide for each side supported */
    uint32_t  flags;       /* AowlModFlags                                 */
} AowlModInfo;
```

| flag | |
|---|---|
| `AOWLSPT_MOD_HOT_RELOADABLE` | implements `state_save` / `state_load`, may be hot-reloaded without a restart |
| `AOWLSPT_MOD_THREAD_SAFE` | the mod's callbacks are safe to call off the main thread |

> `HOT_RELOADABLE` is declared and plumbed and **no host calls `state_save` or
> `state_load` yet**, so a `--watch` reload starts the mod from zero. The flag
> is reported in the mod manager's `listed` payload and nowhere else. Persist
> through the store if a value has to survive. The repository says so in its own
> README rather than letting the flag imply otherwise.

## `AowlModApi` — what the mod provides

```c
typedef struct AowlModApi {
    int32_t size;
    void*   self;   /* handed back as the first argument of every entry below */

    AowlStatus (AOWLSPT_CALL *on_load)  (void* self);
    AowlStatus (AOWLSPT_CALL *on_update)(void* self, int64_t elapsed_ms);
    AowlStatus (AOWLSPT_CALL *on_unload)(void* self);

    AowlStatus (AOWLSPT_CALL *state_save)(void* self, AowlBuffer* out);
    AowlStatus (AOWLSPT_CALL *state_load)(void* self, AowlSlice state);
} AowlModApi;
```

`on_unload` stops the mod's own threads. It **deregisters nothing** — the host
drops every route, subscription, timer and detour itself, and refuses to unload
at all unless a teardown has been registered first.

## `AowlHostApi` — what the mod may ask for

The block is built by `aowl_hostapi_new` in `abi/aowlspt_shim.h` and armed
further by whichever host can honour the later entries.

### Revision 1 — 168 bytes

| field | signature |
|---|---|
| `ctx` | `void*` — opaque host context, passed back verbatim as the first argument of every call |
| `info` | `const AowlHostInfo*` |
| `alloc` / `free` | `void* (ctx, int32_t bytes)` / `void (ctx, void* ptr)` — `alloc(0)` returns `NULL` and is not an error; `free(NULL)` is a no-op |
| `log` | `void (ctx, int32_t level, AowlSlice message)` |
| `last_error` | writes through an out-parameter rather than returning a struct — a 16-byte struct return is where the mingw and MSVC ABIs disagree about hidden-pointer handling, and that disagreement corrupts silently instead of failing to link |
| `config_get` / `config_set` | `(ctx, AowlSlice key, AowlBuffer* out)` / `(ctx, AowlSlice key, AowlSlice value_json)` |
| `db_get` / `db_patch` | `(ctx, AowlSlice path, AowlBuffer* out)` / `(ctx, AowlSlice path, AowlSlice patch_json)` |
| `route_register` | url, kind, handler, user |
| `event_subscribe` / `event_emit` | name, handler / name, payload |
| `call` | `(ctx, AowlSlice target, AowlSlice args_json, AowlBuffer* out)` |
| `resolve` | `(ctx, AowlSlice type_name, AowlHandle* out)` |
| `handle_release` | |
| `patch` | target, kind, handler, user |
| `schedule` | delay/interval, handler |
| `invoke_main` | run a callback on the host's main thread |
| `now_ms` | the host's clock |

### Revision 2 — 192 bytes

| field | signature |
|---|---|
| `store_get` | `(ctx, AowlSlice key, AowlBuffer* out)` |
| `store_set` | `(ctx, AowlSlice key, AowlSlice value)` |
| `store_list` | `(ctx, AowlSlice prefix, AowlBuffer* out)` |

A private, atomic, write-through key/value store per mod. Available on all three
hosts.

### Revision 3 — 208 bytes

`handle_pointer` and `handle_pin`: a live object's **address**, so a mod can
drive it through its own fast-path bindings instead of calling back through the
handle. The difference is 8 ns against 1112 — see [the measurements](il2cpp#what-each-path-costs).

### Revision 4 — 216 bytes

`patch_typed`: a hook handed the **saved registers** instead of JSON. 23 ns
against 627.

### Revision 5 — 224 bytes

`notify_push`: a notification pushed to a session over the game's own notifier
websocket. Backend only.

## The versioning rule, precisely

```c
#define AOWLSPT_HOSTAPI_SIZE_REV1 ((int32_t)offsetof(AowlHostApi, store_get))
#define AOWLSPT_HOSTAPI_SIZE_REV2 ((int32_t)offsetof(AowlHostApi, handle_pointer))
#define AOWLSPT_HOSTAPI_SIZE_REV3 ((int32_t)offsetof(AowlHostApi, patch_typed))
#define AOWLSPT_HOSTAPI_SIZE_REV4 ((int32_t)offsetof(AowlHostApi, notify_push))
#define AOWLSPT_HOSTAPI_SIZE_REV5 ((int32_t)sizeof(AowlHostApi))
```

Those are not decoration. **A mod tests a capability against the boundary the
capability appeared at, never against `sizeof(AowlHostApi)`** — which is right
exactly once and then quietly wrong the next time the struct grows.

Revision 5 is where the watermark stopped being free, and it changes what a
capability test *means*. Only the client host can fill revisions 3 and 4 — they
need a managed heap and a detour engine. Only the backend can fill revision 5 —
it needs a listening socket. One integer cannot say "the fifth and not the
third". Reporting revision 2 would hide `notify_push` from the mod that needs
it; reporting revision 5 over three null pointers would tell a mod to call them,
and **there is no null check available to save it**, because nimony will not
cast a proc field to a pointer to compare it against null. That is *why* every
capability test here is a size test.

So the backend fills the three entries under its watermark with the refusal it
already owed — `AOWLSPT_ERR_UNSUPPORTED`, exactly what those calls already
returned — and only then raises `size`. A boundary test therefore means "there
is a function here that will answer", which is all it ever established.

## The gate under the header

`tests/abi_layout.c` pins every offset under the **real** C compiler and
`tests/abi_layout.nim` asserts nimony agrees. Both are the first two gates of
`aowl test`, and the second is the one that earns its keep:

> A struct mismatch between the two sides does not crash. It reads a length as a
> pointer and fails somewhere else entirely, under load. So nimony's `sizeof` is
> checked against the numbers the real C compiler gives the real header, not
> against a second copy of the same arithmetic.

It has already caught one error.
