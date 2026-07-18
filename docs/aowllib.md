# aowllib — the aowl system runtime

`aowllib` is the hand-written C runtime that supplies the `system` / `syncio`
symbols a post-[aowlhexer](aowlhexer) `.c.aif` references, so real programs —
`echo`, strings, seqs, `ref`/variant objects, inheritance with method dispatch,
ARC — link and run **natively** through [aowlc](aowlc) with **no** nimony
`system.c.aif`.

Repo **`aoughwl/aowllib`** (public). Status: **working** — `echo "hello"` and 43
other programs compile to native binaries and pass a **44/44** acceptance suite,
**ASan/UBSan/LSan-clean, leak-free**. It is the largest single unlock in the
[aowlmony](aowlmony) rewrite: it lets a program compile *natively* through the
self-owned stack instead of running under the [aowli](aowli) interpreter.

Per the aoughwl convention this C runtime is the **bootstrap seed & oracle** for
the eventual aowl-source `system` module (Phase 2).

## Why it exists

By the time [aowlhexer](aowlhexer) has lowered a program, ARC calls and runtime
operations are *injected* into the `.c.aif`: they reference runtime symbols
(`write`, the string/seq structs, `=destroy`, `allocFixed`, `arcInc`, …) that
must exist at link time. Nimony satisfies them by compiling its `system` module
to `.c.aif`; aowllib provides them as an aowl-owned C layer instead.

## Linking

Runtime symbols are **module-hashed**: `write.0.syn1lfpjv` is `write`, overload
disambiguator `0`, from the module hashed `syn1lfpjv`; aowlc mangles it to
`write_0_syn1lfpjv`. The main module's own symbols carry an *empty* hash, so:

> an undefined runtime extern is exactly a referenced atom `base.disamb.HASH`
> with a **non-empty** `HASH`.

aowllib is written once with hash-independent names (`aowllib_*` / `Aowllib*`).
`bin/aowllib-cc` collects the undefined externs, maps each `base` through
`runtime/runtime-map.js` onto an aowllib entry point, and injects a per-program
shim right after aowlc's C prelude:

```c
typedef struct { NI fullLen_0; NI rc_0; NI capImpl_0; NC8* data_0; } Aowllib_LongString;
typedef struct { NU bytes_0; Aowllib_LongString* more_0; } Aowllib_string;
typedef Aowllib_string string_0_sysvq0asl;      // type aliased by name
#define write_0_syn1lfpjv  aowllib_write_string  // proc/global aliased by macro
#define stdout_0_syn1lfpjv aowllib_stdout
```

Field names (`bytes_0`, `fullLen_0`, …) are hash-independent — nimony field name
plus a `.disamb` — so aowllib pins them directly; only type/proc *symbols* carry
the module hash and are bridged by the shim. Any runtime symbol aowllib doesn't
cover is printed as a coverage gap and the build fails — never silently stubbed.

```
.c.aif ──aowlc printer──▶ C ──inject shim──▶ gcc + runtime/aowllib.c ──▶ native binary
```

`aowllib-cc` compiles with `-Werror=implicit-function-declaration`: a runtime
call without a prototype would be assumed to return `int` and silently truncate a
64-bit pointer return, so that class is a hard error, not a `-w`-silenced warning.

## Type layouts

Mirror `lib/std/system/*` and `lib/std/syncio.nim`; sizes are the `--bits:64`
native ABI.

| type | C layout | size |
|:--|:--|:--|
| `string` | `{ NU bytes; LongString* more; }` | 16 B |
| `LongString` | `{ NI fullLen; NI rc; NI capImpl; NC8* data; }` | 32 B |
| `seq[T]` | `{ NI len; void* data; }` (`data` → `UncheckedArray[T]`, cap from `allocatedSize`) | 16 B |
| `File` | `{ NI fd; NU flags; }` (raw OS fd, `nimNativeIo`) | 16 B |

**`LongString.data` is a pointer, not an inline flexible array.** nimony declares
it `UncheckedArray[char]` at offset 24; aowllib uses a pointer because (a) that is
exactly what aowlc emits for a string-literal const — `(LongString){ .data_0 =
"hi" }` stores a pointer to real storage, whereas a flexible-array compound
literal reserves no space — and (b) a heap string is then one allocation
(`header + data + NUL`, `data` pointing just past the header) freed by one
`free`. Indexing `s[i]` works because aowlc's `more->data_0[i]` follows the
pointer.

## SSO strings

`slen` = low byte of `bytes` (little-endian). Tiers:

| slen | tier | storage |
|:--|:--|:--|
| ≤ 7 | short | inline, `bytes` byte 1.. |
| 8–14 | medium | inline across `bytes` + `more` |
| 255 | long (heap) | `more->data`, refcounted via `more->rc` |
| 254 | static (literal) | `more->data`, never freed |

`aowllib_str_from_bytes(p, n)` builds inline when `n ≤ 14`, else a heap
`LongString` (slen 255, `rc = 0`). Literals lower to a static `LongString`.

## ARC

Single-threaded (`arcops.nim`); `rc` stores `refcount − 1`, so `0` == unique.

| op | semantics |
|:--|:--|
| `arcInc(rc)` | `++rc` |
| `arcDec(rc)` | `rc == 0 ? free : (--rc, keep)` |
| `arcIsUnique(rc)` | `rc == 0` |

String `=destroy`/`=copy`/`=dup`/`=wasMoved` live in aowllib; seq and user-`ref`
hooks are monomorphised into the program by aowlhexer.

## Coverage

Symbols provided (`runtime/runtime-map.js`):

| area | symbols |
|:--|:--|
| init | `ini` (no-op) |
| io | `write`(string/char/int/uint/bool/float), `stdout`/`stderr`/`stdin`, `nimFlushStdStreams` |
| strings | `&`, `$`(int/uint/bool), `add`(char/str), `len`, `[]`(char index), `[]`(HSlice → substr), `[]=`(COW char store), `newString`, `toOpenArray`(`for c in s`), `=destroy`/`=copy`/`=dup`/`=wasMoved` |
| string compare | `==`, `equalStrings` (case-on-string), `<`, `<=`, `cmp` |
| seq | `recalcCap` (growth); `alloc`/`realloc`/`allocatedSize` do the rest |
| memory | `alloc`/`alloc0`/`realloc`/`dealloc`/`allocatedSize`, `allocFixed`/`deallocFixed` |
| arc | `arcInc`/`arcDec`/`arcIsUnique` |
| panics | `panic`, bounds `nimIcheckB`/`nimIcheckAB`/`nimUcheckB`/`nimUcheckAB`, `oomHandler` |

**Overload resolution.** `write`, `$`, `add`, `==`, `<`, `<=`, `cmp` and the
`=hooks` share one name; `aowllib-cc` picks the target from the call's argument
**type**, read from the IR (literal shape, the same-module declaration, or a typed
node). `write` falls back to a disambiguator table (`0`=string, `1`=bool, `2`=int,
`7`=char) for args whose type can't be read. Comparators only reach the linker as
`string` externs (int/float/char compares lower to C operators), so a non-string
comparator extern is a reported gap, not a mis-bind.

**Program-local return types.** `for c in s` lowers to `toOpenArray(s)` and
`s[a..b]` to `[]`(string, `HSlice`); both return module-hashed structs defined
*after* the shim, so `aowllib-cc` can't `#define` them — it emits a real wrapper
after the type section (`{ str_data(s), str_len(s) }`; slice → inclusive
`aowllib_str_slice_ab`, `a` clamped to 0, `b` to `high(s)`, empty → `""`).

## Inheritance / RTTI

`object of RootObj` works: field access at any depth, `ref` hierarchies, and
**dynamic method dispatch** through the per-type vtable. aowllib supplies the
`RootObj` (`{ Rtti* vt }`) and `Rtti` (`{ int dl; uint32* dy; void* mt[256] }`)
type-info layouts plus the `nimChckNilDisp` dispatch guard; per-type vtable consts
are emitted into the program. `mt` is a fixed 256-slot array (not a flexible
member) so a vtable stays a fully-sized global (ASan-clean); a type with >256
virtual methods fails loudly at compile.

## aowlc printer completions unlocked

Building the suite completed and fixed nine [aowlc](aowlc) printer points:
`(ovf)` overflow-flag reads; prototypes for inline procs; forward declarations for
object/union structs; **value-dependency ordering** of type declarations (a struct
with a by-value field of another is emitted after it); **case-object variant
records** as anonymous C11 unions; and four inheritance points (inline
array/flexarray `aconstr` as a plain aggregate, `flexarray` *definitions* as real
`T x[]`, inherited-field init via `.Q`, base upcast as `.Q`-member access).

## Testing

```sh
npm test            # build every example .c.aif natively + assert output (node + gcc)
npm run test:regen  # regenerate each .c.aif from its .nim first (needs nimony)
```

44 programs assert native output; each runs from a committed `.c.aif` or
`--regen` from `.nim`. 44/44, ASan/UBSan/LSan-clean.

## Not covered

- **`of` type test** (`x of Derived`) — a **nimony** bug, not aowllib's:
  `vtables_backend.nim` emits an `of` check (`display[level] == hash(T)`) whose
  `level`/target hash don't line up with the type's own display array, so it is
  always false. aowlc/aowllib faithfully execute what nimony emits.
- Exceptions beyond `panic` (the `eraiser` error-code path); `$`-of-float
  (`write(File, float)` works, the string-returning `$` isn't wired).
- The aowl-source `system` module (Phase 2) that would replace this hand-written
  C with code compiled *through* the stack — this runtime is its seed & oracle.
