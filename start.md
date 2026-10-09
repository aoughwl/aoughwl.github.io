---
title: Get started in 5 minutes
description: Run a Nimony program in your browser in one minute, then install the aoughwl toolchain on Linux and build a native binary.
---

# Get started in 5 minutes

Two steps. The first runs in your browser and needs nothing installed. The
second puts the toolchain on a Linux machine; most of its time is spent
compiling.

[[toc]]

## 1. In your browser (1 minute)

Open this program in the playground and press **Run**:

```nim
import std/syncio
echo "hello from aoughwl"
```

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/#c=aW1wb3J0IHN0ZC9zeW5jaW8KZWNobyAiaGVsbG8gZnJvbSBhb3VnaHdsIgo" target="_self">▶ Open hello world in the playground</a>
</div>

What happened: [aowlparser](/docs/aowlparser) parsed the source,
[aowlsem](/docs/aowlsem) type-checked it, and an interpreter ran the result,
all inside your browser tab. Nothing was sent to a server.

Try a program with a type and a procedure:

```nim
import std/syncio

type
  Shape = object
    name: string
    sides: int

proc describe(s: Shape): string =
  s.name & " has " & $s.sides & " sides"

let shapes = @[Shape(name: "triangle", sides: 3), Shape(name: "square", sides: 4)]
for s in shapes:
  echo describe(s)
```

<div class="hero-actions">
<a href="https://aoughwl.github.io/playground/#c=aW1wb3J0IHN0ZC9zeW5jaW8KCnR5cGUKICBTaGFwZSA9IG9iamVjdAogICAgbmFtZTogc3RyaW5nCiAgICBzaWRlczogaW50Cgpwcm9jIGRlc2NyaWJlKHM6IFNoYXBlKTogc3RyaW5nID0KICBzLm5hbWUgJiAiIGhhcyAiICYgJHMuc2lkZXMgJiAiIHNpZGVzIgoKbGV0IHNoYXBlcyA9IEBbU2hhcGUobmFtZTogInRyaWFuZ2xlIiwgc2lkZXM6IDMpLCBTaGFwZShuYW1lOiAic3F1YXJlIiwgc2lkZXM6IDQpXQpmb3IgcyBpbiBzaGFwZXM6CiAgZWNobyBkZXNjcmliZShzKQo" target="_self">▶ Open shapes in the playground</a>
</div>

Things to try while you are there:

- **Change the engine** in the toolbar. *Native JS* compiles your program to
  JavaScript and lets the browser's JIT run it. *Bytecode VM* and *tree-walk*
  interpret it exactly.
- **Make a mistake on purpose**, such as `echo describe(3)`. The error appears
  as you type, from the same type checker the command-line toolchain uses.
- **Share it.** The URL carries your program, so a link reproduces it.

::: tip New to Nim?
Nimony is the next-generation compiler for the [Nim](https://nim-lang.org)
language: Python-like syntax, static types, compiled to C. If you know Python,
most of the examples above read as you expect. Differences from Nim 2 that
catch people early:

- `echo` needs `import std/syncio`.
- A variable may not share its name with the module it is in.
- A nested procedure that uses an outer local must be marked
  `{.closure.}`, and so must the procedure type it is returned as.
- Errors are values of the enum `ErrorCode`: `raise ValueError`, then
  `except ErrorCode as e`. A routine that can raise is marked `{.raises.}`,
  and calling it outside `try` is a compile error. `table[key]` is one such
  routine; `table.getOrDefault(key)` is not.
:::

The playground is checked by running 17 programs through it in a headless
browser: strings, tables, sets, options, closures, object variants, method
dispatch, error handling and a million-iteration loop. 16 pass. The one that
does not is `std/sequtils`' `mapIt` / `filterIt` / `foldl`, which currently
print `nil`; use a `for` loop until that is fixed.

## 2. On your machine (about 3 minutes, mostly compiling)

### What you need

| | |
|:--|:--|
| System | Linux x86-64 with glibc 2.34 or newer (Ubuntu 22.04+, Debian 12+, Fedora 35+) |
| Tools | `git`, `curl`, a C compiler (`gcc`) |
| [Nim 2](https://nim-lang.org/install.html) | used once, to build the Nimony compiler from source |
| [Node.js](https://nodejs.org) | runs the C backend's linker driver |

On macOS and Windows, use the playground for now, or WSL on Windows.

### Install

```sh
# 1. the toolchain manager
curl -fsSL https://raw.githubusercontent.com/aoughwl/aowlup/main/install.sh | sh
export PATH="$HOME/.aowl/bin:$PATH"

# 2. build the compiler and the free components (2 to 3 minutes)
aowlup setup --yes

# 3. the driver
aowlup install aowlmony
```

`aowlup setup` clones each component into its own directory in your home
folder (`~/nimony`, `~/aowlc`, `~/aowlparser`, …) and builds it. A few
components have private source. Setup reports those as `clone failed` and
carries on, and nothing on this page needs them.

Add the `export PATH=…` line to your shell profile to keep it.

### Run a program

```sh
cat > hello.nim <<'EOF'
import std/syncio
echo "hello from aoughwl"
EOF

aowlmony run hello.nim
```

```
hello from aoughwl
  ✓ run · compiled 1.8s · ran 150ms
```

`run` compiled `hello.nim` through the pipeline to C, linked a native binary
and ran it. To keep the binary:

```sh
aowlmony build hello.nim -o hello
./hello
```

### Start a project

```sh
aowlmony new myapp
cd myapp
```

This writes a `mony.toml` and `src/myapp.nim`. Inside the project, plain
`aowlmony run` builds and runs it (the entry point comes from `mony.toml`), and
`aowlmony watch src/myapp.nim` reruns it on every save.

## 3. What to read next

| If you want to | Read |
|:--|:--|
| see what each stage produced | `aowlmony nif hello.nim` prints the paths of the parsed, typed and lowered files; [AIF](/docs/aif) explains the format |
| know why something rebuilt | `aowlmony why hello.nim` |
| check your setup | `aowlup doctor` lists every pipeline slot and what fills it |
| swap our stages for Nimony's | `aowlup profile use nimony`, see [aowlup](/docs/aowlup) |
| set up an editor | [aowllsp](/docs/aowllsp), or `aowlup vscode . --yes` |
| know what is missing | [Parity](/docs/parity) |

## If something goes wrong

- `aowlup doctor` shows which slot is missing or unbuilt.
- `aowlmony` says *a component is not installed* when a command needs one that
  is not there. The interpreter and the TypeScript, Python and WebAssembly
  backends are part of the [paid bundle](/store/), installed with
  `aowlup login YOUR-KEY`.
- Anything else: ask on [Discord](https://discord.gg/nxa3W7w4rJ). Reports of a
  step on this page that did not work for you are the most useful thing you
  can send.
