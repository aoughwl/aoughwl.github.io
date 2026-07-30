# Aowl mode — the default-on lock

[[toc]]

---

**Default `guided` since v1.0.** A `PreToolUse` hook denies the shell
code-archaeology path so the structural MCP tools are the only route to the
code.

## Rationale

The tools predate 1.0 by months and were bypassed in favour of `grep -rn` +
`sed -n 'A,Bp'` loops. The per-call size guards (`guard-nif-read`,
`guard-source-read`, `guard-generated-grep`) bound a single oversized read; they
do not bound nine individually cheap calls, which is the pattern that empties a
context window. 1.0 changes the default instead.

## What each mode denies

| Mode | Denied | Still allowed |
|---|---|---|
| **`guided`** *(default)* | `Grep`, `Glob`; Bash segments that are a code search (`grep`/`rg`/`ag`/`ack`), a source-or-NIF dump (`cat`/`head`/`tail`/`sed`/`awk`/`less`/`bat`), or a source-tree walk (`find`/`fd`/`tree`) aimed at `.nim`/`.nif`/`src`/a recursive sweep; raw `nim c` / `nimony c` / `nim check` / `nifc` / `hexer` | `git`, test scripts, running a built binary, and every other ordinary shell command; windowed `Read`; `Edit`/`Write` |
| **`strict`** | all of the above **plus Bash outright** | MCP tools, windowed `Read`, `Edit`/`Write`, and the mode toggle |
| **`off`** | nothing | everything |

Every denial carries a redirect table naming the tool that answers the question
that was being asked — and denials are recorded, so `/aowl-mode status` can tell
you how many archaeology calls the lock has intercepted.

```
grep for arbitrary text in the repo    ->  search(pattern)
list files matching a glob             ->  search(pattern, files=true)
grep for a symbol / "where is X"       ->  symbols(name)
where is X defined AND used            ->  defs_uses(name)
read one proc/type body                ->  decl_of(sym)
what's in this file / line ranges      ->  outline(file)
a module's public API                  ->  api(module)
cat/grep a .nif artifact               ->  nif_outline / nif_query
make a .nif readable                   ->  nif_render(file, needle)
diff two phase artifacts               ->  nif_diff / phase_report
nim c / nimony c / nim check           ->  compile / build
why did this fail                      ->  explain_failure
minimise a failing file                ->  shrink
print-debugging / echo instrumentation ->  debug_session
```

## Usage

```
/aowl-mode              # status: mode, where it came from, calls intercepted
/aowl-mode strict       # also deny Bash outright
/aowl-mode guided       # the default, stated explicitly
/aowl-mode off          # lift the lock
/aowl-mode default      # forget the explicit state, whatever it was
```

The hook re-reads its state file on every call, so a toggle takes effect
immediately — no session restart.

## State semantics

No state file ⇒ `guided`. `off` is a written state, not the absence of one, and
carries the same `AOWLCODE_MODE_TTL_HOURS` TTL (default 12) as `strict`: any
explicit state older than the TTL falls back to the baseline. Both stale-state
directions therefore heal — a lifted lock returns, a forgotten `strict` lapses.

## Escape hatches

Four, in increasing order of bluntness:

1. Any Bash command containing `aowlcode-mode` is allowed **even under
   `strict`** — the toggle is always reachable from inside a locked session.
2. `/aowl-mode off` (or `default`), effective immediately.
3. `AOWLCODE_DEFAULT_MODE=off|guided|strict` moves the baseline for a whole
   machine or a single shell.
4. `AOWLCODE_NO_MODE_GATE=1` disables the hook entirely.

The hook is fail-open: any internal error exits 0 and allows the call.

## Session banner

A `SessionStart` hook injects ~200 tokens — current mode plus the redirect table
— once per session, and is silent when the mode is `off`. Cost basis: three
denial messages exceed it.

## When no tool answers

Take the redirect; do not retry with a different shell spelling. If no tool
covers the question, report it — that gap is an aowlcode bug. `search`, `map`,
`changes`, `run`, `nif_run` and `bisect` all originate from denials with no good
answer at the time.
