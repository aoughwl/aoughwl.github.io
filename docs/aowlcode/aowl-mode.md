# Aowl mode — the default-on lock

[[toc]]

---

**Since v1.0, aowl mode is ON by default.** It is the feature the rest of the
plugin was waiting for, and the reason the tools below it finally get used.

## Why a lock at all

Every structural tool in aowlcode existed for months before 1.0 and was still
routinely skipped. The reason was not that the tools were worse — a one-call
`symbols` beats a nine-call `grep -rn` + `sed -n 'A,Bp'` loop on every axis that
matters. The reason is that choosing a structural tool is a *decision* and
shelling out is a *reflex*. Better tools do not win on merit against zero
friction; a staircase does not win against an escalator.

The per-call size guards (`guard-nif-read`, `guard-source-read`,
`guard-generated-grep`) stop the worst single reads. They cannot stop the
pattern that actually empties a context window, which is nine individually
cheap calls in a row. So v1.0 stopped arguing and changed the default.

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

## Off is a state, not an absence

Before 1.0, "no state file" meant *off*. Now it means *`guided`*, and `off` is
something you write down. That inversion has a consequence worth stating
plainly: **`off` expires too.** After `AOWLCODE_MODE_TTL_HOURS` (default 12) any
explicit state — `strict` or `off` — falls back to the baseline. A lock you
lifted this morning is back tomorrow, and a `strict` you forgot in another
terminal cannot strand a session next week. Both failure directions heal.

## It cannot wedge a session

Four independent escape hatches, in increasing order of bluntness:

1. Any Bash command containing `aowlcode-mode` is allowed **even under
   `strict`** — the lock always has a key on the inside.
2. `/aowl-mode off` (or `default`), effective immediately.
3. `AOWLCODE_DEFAULT_MODE=off|guided|strict` moves the baseline for a whole
   machine or a single shell.
4. `AOWLCODE_NO_MODE_GATE=1` disables the hook entirely.

And the hook is fail-open like every other hook in the plugin: any internal
error exits 0 and allows the call.

## The session banner

A `SessionStart` hook injects roughly 200 tokens: the current mode and the
redirect table above, once. This is not decoration, it is arithmetic — an agent
that has not been told the tools exist reaches for `grep`, and by the third
denial the refusal messages alone have cost more than saying it once up front.
The banner is silent when the mode is `off`.

## What to do when the lock blocks something real

Take the redirect. If genuinely **no** tool answers the question, say so and
stop — do not retry with a different shell spelling. That gap is an aowlcode
bug, and surfacing it is more valuable than the workaround, because the
workaround is invisible and the bug report is not. Several tools exist only
because someone hit exactly that wall: `search`, `map`, `changes`, `run`,
`nif_run` and `bisect` were all built from denials that had no good answer yet.
