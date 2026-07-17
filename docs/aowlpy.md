# aowlpy — idiomatic Python backend

An **idiomatic Python** backend for [nimony](../nimony): Nim types become real
Python objects, not byte offsets.

> **Status: working core** · private repo. The emitter reads a sem'd `.s.nif` and
> produces readable Python 3 that runs **byte-for-byte identical** to native aowl
> across the test corpus (11/11). Access via Discord **timbuktu_guy**.

## What it is (and isn't)

There are two ways to target Python from Nim:

1. **Linear-memory Python** — a `bytearray` + `struct`/`memoryview` as one flat
   heap, pointers as offsets. Reuses [aowlweb](aowlweb)'s `jslayout` engine
   verbatim, but is slow and unreadable. *If ever wanted, it belongs in aowlweb
   as a third linear target — not here.*
2. **Idiomatic Python** — real `class`/`@dataclass`, `list`, `dict`, Python's own
   GC. Readable, fast enough, Pythonic. **This repo is #2.**

Python is in some ways an *easier* idiomatic target than TypeScript:

| | idiomatic value |
|---|---|
| integers | native arbitrary-precision `int` — no `number`/`bigint` split, no wrap footgun |
| `object` | `@dataclass` / `class` |
| `seq[T]` | `list` |
| `Table[K,V]` / `HashSet` | `dict` / `set` |
| `string` | `str` |
| memory | Python's refcount + cycle GC |

## Architecture

Shared with its sibling [aowlts](aowlts): a common aowl→high-level lowering
([aowlhl](aowlhl)) feeds thin per-language emitters. Both consume the
**sem'd, pre-`hexer` NIF** (`.s.nif`) — `echo` stays a named `write` call with the
literal intact, `object` types nominal, `seq[T]` generic, `try`/`raise` structured
— none of the C-model lowering the post-`hexer` `.c.nif` carries. It loads with
existing aowl APIs (`programs.setupProgramForTesting`), so no compiler changes are
needed.

`aowlpy` is the Python analogue of the [aowljs](aowljs) JavaScript emitter and
mirrors its file split: a ~20-line CLI driver (`src/aowlpy_cli.nim`) over an
emitter (`src/emitpy.nim`). The one structural difference from the brace-based JS
emitter is that Python is indentation-sensitive, so statements flow through an
indent-aware `line`/`push`/`pop` layer while expressions are pure string builders.
It walks the same NIF grammar as the interpreter and the JS emitter through the
shared `aowlhl` shape decoders (`decodeLocal` / `decodeParam(s)` / `decodeProc` /
`decodeIf` / `decodeCase`), the pragma classification (`hlclassify`), and the
dependency-first module-init order (`hlload.moduleInitOrder`).

## What the emitter maps

| aowl construct | idiomatic Python |
|---|---|
| `object` / `ref object` | `@dataclass` class (with base-class inheritance) |
| `enum` | `IntEnum`, values referenced as `Enum.member` |
| `seq[T]` / `array` literal | `list` (`@[a, b]` → `[a, b]`) |
| tuple / tuple unpack | `tuple` + indexing |
| `string` / `char` | `str` |
| field access `obj.f` | `obj.f` |
| `proc` / `func` | `def` with parameter and return **type hints** |
| `var` / `out` params | single-element cell boxes with call-site write-back |
| `if`/`elif`/`else`, `while` | native, indentation-structured |
| `case` | `if`/`elif` chain over a once-bound selector (ranges → `lo <= s <= hi`); as expression, each branch assigns the target |
| `for` in `a..<b` / `a..b` | `range(a, b)` / `range(a, b+1)` |
| `for` in `countdown(a, b)` | reverse `range` |
| `for x in xs` / `for i, x in xs` | iteration / `enumerate` |
| `echo` (lowered to `write`) | buffered `sys.stdout.write` (`true`/`false` spelled) |
| arithmetic / bit / comparison / boolean ops | native operators |
| int `div` / `mod` | truncating `_idiv` / `_imod` helpers (aowl truncates toward zero) |
| string builtins (`len`, `&`, `toUpper/LowerAscii`, `strip`, `contains`, …) | native `str`/`len` |
| string relational (`==`/`<`/`>`/…), slicing `s[a..b]`/`s[a..<b]` | native operators / `s[a:b(+1)]` |
| `seq` index-store `s[i] = v`, `newSeq[T](n)` | `s[i] = v` / `[0]*n` |
| `$` / `chr` / `ord` / `abs` / `min` / `max` / math | `str()` / `chr()` / `ord()` / `math.*` |
| overloaded procs | `def` names disambiguated per symbol; each call resolves its own |
| multi-module program | imported user modules' top-level init replayed first |

Foreign declarations (std/`system` routines and generic instantiations that leak
into the module) are skipped: their seq/string/etc. operations are handled
natively at the call sites, so the low-level stdlib bodies are never emitted. A
user proc whose name collides with a builtin (`add`, `len`, …) is *not* rewritten
to the magic — dispatch is gated on symbol origin, not name.

## Build & run

```sh
NIM=/path/to/nimony
$NIM/bin/nimony c -o:bin/aowlpy \
  -p:$NIM/src/lib -p:$NIM/src/nimony -p:$NIM/src/models -p:$NIM/src/gear2 \
  -p:/path/to/aowlhl/src -p:src \
  src/aowlpy_cli.nim

# produce a program's typed NIF, then transpile its main .s.nif
$NIM/bin/nimony c -r --nimcache:/tmp/nc -f prog.nim
bin/aowlpy /tmp/nc/<mainhash>.s.nif > prog.py && python3 prog.py
```

`tests/run.sh` compiles each `tests/*.nim` natively, transpiles the main
`.s.nif`, `py_compile`-checks the emitted Python, runs it, and diffs against the
native output — currently **19/19 byte-identical**. Against the shared differential
corpus (`aowlhl/corpus`, 54 programs vs native nimony) aowlpy sits at **53/54** (the
one fail is the by-design unbounded-int case). `ref object` (class instance +
field mutation, `== nil` → `is None`; ARC/RTTI hooks dropped under GC), inheritance
(`class Derived(Base)`, identity upcast), custom `iterator`s (Python generator `def`
+ `yield`), closures (nested `def`/lambda with lexical capture), **exceptions**
(`try`/`except T as e`/`raise` → native `try`/`except`, `Exception`-derived types as
`class T(Exception)`), **`defer`** (→ `try`/`finally`), **variant objects**
(flattened dataclass), **`distinct`**, **`set`** algebra, seq **`filter`/`map`**
HOFs, and **`HashSet`** → native `set`, all lower to native Python.

## Limitations / TODO

Deliberately deferred (clearly marked in the source): `Table` (blocked by nimony's
effect system), macros, and `var`-param arguments in *expression*
position (statement-position calls get correct cell write-back; expression
position is read-only). Emitted names favour readability over global uniqueness,
so deeply shadowed identifiers across scopes are a known sharp edge.
