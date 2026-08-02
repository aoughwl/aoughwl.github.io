---
repo: aoughwl/aowlhost
---

# aowlhost — run an aowl module as a sandboxed plugin

Runs a compiled aowl/nimony module as a **plugin**, inside a host process that
embeds the [aowli](aowli-release) engine as a library, under a **capability
policy**. The default policy grants nothing: a plugin that opens a file, lists a
directory, spawns a process or reads the environment is halted at the call.

```
$ aowlhost --audit snoop.s.nif
snoop: about to read /etc/hostname
aowlhost: policy grants none
aowli: policy violation: 'readFile' needs capability fs.read on '/etc/hostname';
       this run grants none. Denied — the call did not reach the host.
aowlhost: plugin STOPPED by policy — 1 denied call(s)
$ echo $?
77
```

The same plugin, with one capability granted:

```
$ aowlhost --allow:fs.read snoop.s.nif
snoop: about to read /etc/hostname
LEAK: nimbox
$ echo $?
0
```

[[toc]]

---

## Usage

```
aowlhost [--allow:CAPS] [--allow-path:PREFIX=CAPS] [--audit]
         [--audit-reads:FILE] <plugin.s.nif> [-- ARG...]
```

| capability | grants |
|---|---|
| `fs.read`  | read file contents, list directories |
| `fs.write` | create / write / unlink / rename / chdir |
| `fs.meta`  | stat, cwd, file size, path resolution |
| `process`  | spawn (`system(3)`, the leaf under `execShellCmd`) |
| `env`      | the process environment |
| `all`      | everything — what an unrestricted interpreter run has |

`--allow-path:PREFIX=CAPS` grants those capabilities on everything under
`PREFIX` and nowhere else. That is the unit worth using: *"read exactly this
schema"* rather than *"read the filesystem"*.

Everything after `--` becomes the plugin's `commandLineParams()`. The exit code
is the plugin's own, except **77**, which means "stopped by policy".

## Why the native boundary is the capability boundary

aowli interprets typed [AIF/NIF](aif) over a value model with no pointer into
the host. The only way an interpreted program reaches the outside world is a
**native** — a primitive the engine implements on the program's behalf — and
every one of them funnels through a single `nativeCall`. That makes the native
boundary a *complete* capability boundary rather than a partial one: there is no
second door to also guard.

Enforcement is two layers:

1. **The gate** — `nativeCall` checks the requested native's capabilities before
   dispatching. A denial halts the run through the same path as `quit`, so the
   plugin never receives a substitute value for the call it was denied.
2. **A backstop** — the OS floor (`hostOpen`, `mkdir`, `rmdir`, `unlink`,
   `chdir`, `opendir`, `system`) re-checks at the line that actually issues the
   syscall and reports `EPERM`. The gate covers today's natives; the backstop is
   what keeps a *future* native from reaching the OS by another route.

Three properties the design commits to:

- **Off by default.** The policy is inert until a host installs one, so an
  ordinary interpreter run is unchanged and pays one bool load per native call.
- **Denial is loud.** A denied call never returns an empty string, a nil, or an
  errno the plugin could mistake for "file not found". A capability system whose
  refusal is indistinguishable from a normal failure is worse than none.
- **Denial is not catchable.** The bundled `plugins/snoop.nim` wraps its
  `readFile` in `try`/`except` and the `except` branch never runs — the halt is
  at the native boundary, below the language.

## Provenance

`--audit-reads:FILE` records every **granted** read as
`read<TAB>path<TAB>hash<TAB>size`, hashed FNV-1a/64. The host writes it, not the
plugin, so a plugin can neither forge nor suppress its own provenance.

That record is what makes an *effectful* evaluation checkable rather than merely
permitted: [aowlsem](aowlsem) runs compile-time code (macros, `const`
evaluators) under this same policy and keeps the reads as
`<out>.s.nif.ctfe-reads`, and [aowltest](https://github.com/aoughwl/aowltest)
re-hashes them to decide whether a cached result is still valid.

## The gate

```
bash build.sh
bash tests/run.sh      # 9/9
```

Every denial case is paired with its granted control, because a test that only
checks the trap cannot tell *"the policy denied it"* from *"the read never
worked"*:

| # | case | proves |
|---|---|---|
| 1 | pure plugin, no capabilities | a computation runs to completion with zero authority |
| 2 | `readFile` under no-IO | traps, execution stops there, `except` never runs, no bytes read |
| 3 | same plugin `--allow:fs.read` | reads the file — so #2 is the policy |
| 4 | `writeFile` under no-IO | traps **and the target does not exist on disk** |
| 5 | same plugin `--allow:fs.write,fs.meta` | writes — so #4 is the policy |
| 6 | `--allow:fs.write` only | one capability does not imply another |
| 7 | `--allow-path:` on one file | that file reads; a sibling is denied and named |
| 8 | `--audit-reads:` | the granted read is recorded with its hash |

Case 4's filesystem check is the load-bearing one: the message says the call was
denied, and the absent file shows the syscall was never issued.

## Plugin entry point

The plugin's entry point is its module body. The host loads the typed NIF,
replays imported modules' initialization in dependency order, supplies argv, and
captures everything the plugin writes — plugin output arrives in the host's
buffer rather than going to a descriptor behind the host's back.

Calling a named exported proc instead of the module body needs a call-by-name
entry in the engine's public API, which does not exist yet. Per-path grants are
whole-capability per prefix; narrowing them further (read this file, append to
that one) is the other open direction.
