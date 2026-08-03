# Token budget — what aowlcode actually saves

[[toc]]

---

aowlcode's stated purpose is token thrift. This page is the audit of that claim,
measured rather than asserted. Every number below comes from one of three
sources, all reproducible:

| Source | What it measures | Where |
|---|---|---|
| Claude Code transcripts | bytes each tool result actually put into context, and how many requests re-read them | `~/.claude/projects/*/*.jsonl` |
| A/B harness | the same question answered by a `nimlang` tool vs. the raw shell | `mcp/bench/` |
| `tools/list` dump | fixed schema cost paid on every request | the MCP server itself |

Scope: **142 sessions, 119,060 assistant requests, 33.93 billion input tokens
read.** The per-tool breakdown uses the most recent 40 sessions (16,800
requests, 8.78 MB of tool results) so the numbers reflect the current toolset.

Token counts are estimated at 4 bytes/token unless taken from a `usage` record.
Where a count is an estimate it is labelled as one.

---

## 1. The number that governs everything: 355×

A tool result is not paid for once. It sits in the conversation and is re-read
by **every subsequent request in that session**. Measured across the 40-session
window:

```
one-time tool-result bytes      8.78 MB
bytes actually re-read          3.12 GB
amplification factor            355×
```

Average context size per request across all 142 sessions: **284,982 tokens.**

This is the whole economic case for the plugin, and it is stronger than the
per-call comparisons suggest. A tool that returns 400 bytes instead of 16,000
does not save 15.6 KB — it saves 15.6 KB × the number of requests remaining in
the session. Early-session thrift is worth roughly 355× its face value; a saving
in the last request of a session is worth its face value and nothing more.

It also means the reverse: one careless 400 KB `cat` in the first minute of a
session is not a 400 KB mistake, it is a ~100 M token mistake.

---

## 2. Where the tokens actually go

Amplified (re-read) bytes over 40 sessions, ranked:

| Tool | Calls | Bytes | Amplified | Amp× | Share |
|---|---:|---:|---:|---:|---:|
| `Read` | 1,719 | 4,375,710 | 1.65 GB | 377× | **52.9 %** |
| `Bash` | 4,211 | 2,743,887 | 856 MB | 312× | **27.4 %** |
| `nimlang.search` | 807 | 667,686 | 270 MB | 404× | 8.7 % |
| `Edit` | 1,918 | 296,850 | 96 MB | 325× | 3.1 % |
| `nimlang.api` | 80 | 112,607 | 48 MB | 427× | 1.5 % |
| `nimlang.build` | 249 | 138,292 | 37 MB | 266× | 1.2 % |
| `nimlang.debug_session` | 83 | 87,790 | 25 MB | 288× | 0.8 % |
| `nimlang.compile` | 121 | 64,158 | 24 MB | 367× | 0.8 % |
| `Write` | 401 | 58,291 | 21 MB | 357× | 0.7 % |
| `nimlang.run` | 110 | 43,925 | 18 MB | 419× | 0.6 % |
| `nimlang.outline` | 58 | 46,423 | 14.5 MB | 312× | 0.5 % |
| `nimlang.nif_query` | 29 | 15,627 | 8.7 MB | 554× | 0.3 % |
| `nimlang.nif_render` | 40 | 21,210 | 6.9 MB | 327× | 0.2 % |
| `nimlang.nif_outline` | 11 | 14,008 | 6.1 MB | 439× | 0.2 % |
| `nimlang.decl_of` | 67 | 13,272 | 5.1 MB | 387× | 0.2 % |

**All 26 `nimlang` tools together account for 15.1 % of context drain.
`Read` and `Bash` alone account for 80.3 %.**

That is the single most important finding on this page. aowl mode closed the
`Grep`/`Glob` and shell-archaeology hole, and it worked — `Grep` and `Glob` do
not appear in the table at all. But `Read` was never gated, and `Read` is now
the largest consumer in the system by a factor of two over everything else.
Optimising the structural tools further is work on 15 % of the problem.

### The `Edit` correction

`scripts/aowl-ledger` reports `Edit` as 93.9 % of all context, 79.3 KB per call.
That is wrong and the report should not be quoted. `hooks/token-ledger.py`
measures the PostToolUse **hook payload**, which contains `originalFile` — the
entire pre-edit file. Claude Code does not put that in context; it injects a
short confirmation snippet.

```
Edit, per call, hook payload      79,300 bytes
Edit, per call, actual context       154 bytes
over-count                            515×
```

The ledger's headline figure of "110.3 M into context" is inflated by ~12×
overall, and its ranking is inverted: it hides `Read` behind an `Edit` cost that
does not exist. The transcript-based measurement in this page supersedes it.

---

## 3. A/B: tool vs. raw shell, same question

Measured on `mcp/nim` (a 26-file Nimony project). "Raw" is the cheapest
plausible shell/`Read` sequence that answers the same question, not a
worst-case strawman.

| Question | Tool | Tool bytes | Terse | Raw equivalent | Raw bytes | Best saving |
|---|---|---:|---:|---|---:|---:|
| map a 389-line file's declarations | `outline` | 1,236 | **400** | `Read` whole file | 16,567 | **41×** |
| read one proc body | `decl_of` | 334 | — | `Read` whole file | 16,567 | **50×** |
| find every mention of a string | `search` | 438 | n/a | `grep -rn` | 2,313 | **5.3×** |
| a module's public API | `api` | 3,913 | 2,051 | `Read` the source | 22,572 | **11×** |
| outline a 70 KB `.s.nif` | `nif_outline` | 3,239 | 3,229 | `cat` the artifact | 70,490 | **21.8×** |
| find procs in a `.s.nif` | `nif_query` | 14,819 | 8,197 | `cat` the artifact | 70,490 | **8.6×** |
| render NIF as pseudo-Nim | `nif_render` | 5,847 | 5,341 | `cat` the artifact | 70,490 | **13×** |
| where is symbol X declared | `symbols` | 860 | 486 | `grep -rn` | 648 | **1.3×** |
| why did this file fail to build | `compile` | 768 | 482 | raw `nimony c` | 984 | **2.0×** |
| definition + every use of X | `defs_uses` | 336 | 107 | `grep -rn` | 98 | **0.9× — worse** |

Two honest results in that table:

- **`defs_uses` costs more than the grep it replaces** on a narrow symbol in a
  small tree. What it buys is not fewer bytes but a *resolved* answer: which
  definition each use actually binds to, which grep cannot tell you. Sold as a
  token saving it is a loss; sold as correctness it is fine.
- **`compile` only beats raw `nimony c` by 2×** on a small file, and only on the
  failure path — a successful raw compile prints nothing at all, so there is no
  saving to be had. Its real value is `ok: false` as a machine-checkable
  verdict, because `nimony` exits 0 on some failures and the raw exit code
  cannot be trusted.

The large wins are concentrated where the alternative is reading a whole file or
a whole artifact: `outline`, `decl_of`, `nif_*`, `api`.

---

## 4. Global saving

Applying each tool's measured ratio to its amplified byte count over the
40-session window:

```
actually spent, all tools                     3.12 GB   (779.9 M tokens est.)
of which nimlang tools                        0.47 GB   (117.4 M tokens est.)
counterfactual, raw-shell workflow            5.25 GB   (1.31 B tokens est.)
------------------------------------------------------------------
avoided                                       2.13 GB   (532.6 M tokens est.)
saving vs. counterfactual                     40.6 %
```

**Over the last 40 sessions, aowlcode's structural tools avoided an estimated
532.6 million tokens of quota drain — about 40 % of what the same work would
have cost with `grep`/`cat`/`Read`.**

Per-tool contribution to that figure:

| Tool | Ratio used | Amplified saving |
|---|---:|---:|
| `search` | 5.28× | 1,155.7 MB |
| `api` | 5.77× | 229.5 MB |
| `outline` | 13.4× | 179.9 MB |
| `nif_render` | 12.1× | 76.6 MB |
| `build` | 2.89× | 69.3 MB |
| `nif_query` | 4.76× | 32.5 MB |
| `compile` | 1.28× | 6.6 MB |
| `defs_uses` | 0.29× | *negative* |

### What this estimate assumes, and which way it is wrong

- **1:1 call substitution.** Each tool call is assumed to replace exactly one
  shell command. In practice a `grep` usually needs follow-up `Read`s to make
  sense of its hits, and `outline`/`decl_of` frequently replace a *sequence*.
  This makes the estimate **conservative**.
- **Ratios measured on one project** (`mcp/nim`, 26 files). Larger trees make
  `grep` and `cat` worse, not better — also conservative.
- **Amplification is computed per session from real request counts**, not
  assumed. This part is not an estimate.
- **Tools with no shell equivalent** (`debug_session`, `run`, `doctor`,
  `bisect`) are scored at 1.0× — no credit claimed. `debug_session` replaces
  echo-instrumentation loops that would cost a rebuild plus a rerun each, so
  this is understated, but by an amount not measured here.

---

## 5. The fixed cost nobody was counting

26 tools are advertised to the model on **every request**:

```
26 tool schemas             18,220 bytes    ~4,555 tokens per request
```

Over the 40-session window (16,800 requests) that is **~76.5 M tokens spent
describing the toolset** — against 117.4 M tokens for everything those tools
actually returned. **The menu costs 65 % as much as the meal.**

It gets worse when you ask which tools were used. Of the 26, **10 were not
called once in 40 sessions**: `bisect`, `changes`, `debug`, `doctor`,
`explain_crash`, `nif_run`, `phase_report`, `shrink`, `trace`, `trace_diff`.

```
schemas for never-called tools   7,594 bytes   ~1,898 tokens per request
over 40 sessions                               ~31.9 M tokens
over all 142 sessions                         ~226.0 M tokens
```

This cost is invisible to `aowl-ledger` (which only sees tool *calls*) and it is
not something the model can opt out of. It is the direct answer to "does Claude
Code perhaps not count this": it is counted, in `cache_read_input_tokens`, where
nothing attributes it to the plugin.

**The fix already exists in the harness.** Claude Code supports deferred tools —
names advertised, schemas fetched on demand via `ToolSearch`. Moving the 10
never-called tools behind that recovers ~1,900 tokens per request at the cost of
one extra call on the rare occasion they are wanted. This is exactly the
"progressive, explicit to request" model, applied to the tool list itself.

For comparison, 4,555 tokens for 26 tools is *lean* by MCP standards — the
schemas are tight, descriptions average 115 characters. The problem is not
verbosity per tool, it is 10 tools nobody calls.

---

## 6. Terse mode: which tools honour it

`terse` is documented in `docs/aowlcode/tools.md` as "every tool accepts an
optional `terse: bool`". **That is not true: 12 of 26 accept it.** Measured
effect, using many-hit queries so there is something to compress:

| Tool | Full | Terse | Saving |
|---|---:|---:|---:|
| `outline` | 1,964 | 663 | **66 %** |
| `defs_uses` | 257 | 107 | **58 %** |
| `decl_of` | 257 | 134 | **48 %** |
| `api` | 3,913 | 2,051 | **48 %** |
| `nif_query` | 14,819 | 8,197 | **45 %** |
| `symbols` | 860 | 486 | **44 %** |
| `compile` | 768 | 482 | **37 %** |
| `explain_failure` | 1,087 | 854 | **21 %** |
| `nif_render` | 5,847 | 5,341 | 8.7 % |
| `nif_outline` | 3,239 | 3,229 | **0.3 % — inert** |
| `build` | 341 | 341 | **0 % — inert** |
| `phase_report` | — | — | not measured |

The 14 tools with **no** `terse` parameter at all: `search`, `run`, `changes`,
`map`, `doctor`, `shrink`, `trace`, `trace_diff`, `nif_diff`, `nif_run`,
`bisect`, `debug`, `explain_crash`, `debug_session`.

`search` is the most expensive `nimlang` tool in the system — 807 calls, 270 MB
amplified, 8.7 % of all context drain — and it has no terse mode. That is the
single largest unclaimed win inside the plugin.

### Terse is already on

`NIMLANG_AGGRESSIVE=1` is set in the environment, and `doctor` confirms
`terse_default: true`. Terse is not an opt-in that has been forgotten; it is on,
and the savings above are already being realised on the 12 tools that implement
it. The remaining work is not "turn it on", it is:

1. implement it where it is declared but inert (`nif_outline`, `build`),
2. add it where it is missing and expensive (`search`, `debug_session`),
3. make it the server-side default rather than an env-var default, so a session
   launched without the variable is not silently 2× more expensive.

---

## 7. Ranked work list

By measured value, not by how interesting the work is.

| # | Change | Basis | Est. recovery |
|---|---|---|---|
| 1 | Bound `Read` — redirect whole-file reads to `outline` + `decl_of`, the way aowl mode already redirects `grep` | `Read` = 52.9 % of drain, 2,546 B/call avg; `decl_of` answers the same question at 334 B | up to ~1.2 GB amplified |
| 2 | Bound `Bash` output — cap and tail-truncate at the PreToolUse boundary | `Bash` = 27.4 % of drain over 4,211 calls | up to ~400 MB amplified |
| 3 | Defer the 10 never-called tool schemas behind `ToolSearch` | 1,898 tokens × every request | ~1.9 K tokens/request |
| 4 | Give `search` a terse mode | 8.7 % of drain, no terse today | ~40 % of 270 MB |
| 5 | Implement terse for `nif_outline` and `build` | declared, measured inert | small but they are lies today |
| 6 | Fix `aowl-ledger` to measure context, not hook payload | 515× over-count on `Edit` inverts the whole ranking | correctness |
| 7 | Correct `tools.md`'s "every tool accepts `terse`" | 12 of 26 | correctness |
| 8 | Re-pitch `defs_uses` as correctness, not thrift | measured 0.9×, it costs more than grep | honesty |

Items 1 and 2 are worth more than everything else on this page combined. The
plugin has optimised the 15 % it owns and left the 80 % untouched.

### Why `Read` was not gated, and what gating it would look like

`Read` is the escape hatch that makes aowl mode survivable — the mode
documentation explicitly promises "reading a bounded window of a source file
with `Read(offset=, limit=)` is still allowed", and denying `Read` outright
would wedge sessions. The measurement says the promise is being kept in letter
and not in spirit: 2,546 bytes per call is not a bounded window, it is a file.

A proportionate gate: allow `Read` with an explicit `limit`, and on an unbounded
`Read` of a `.nim`/`.nif` file over N lines, deny with the same redirect table
aowl mode already prints — `outline(file)` for the map, `decl_of(sym)` for the
body, `Read(offset=, limit=)` when a window really is what is wanted. That is
the "progressive, explicit to request" pattern applied where it is worth the
most.

---

## 8. Reproducing this

```bash
mcp/bench/bench.py     # A/B: tool vs raw shell, per question
mcp/bench/bench2.py    # failure path, NIF artifacts, terse no-ops
mcp/bench/bench3.py    # terse effectiveness, many-hit queries
mcp/bench/global.py    # transcripts -> amplification -> global saving
```

`global.py` reads Claude Code's own transcripts, so it re-measures against
whatever the current toolset and usage pattern actually are. Re-run it after any
change on the work list above; the numbers on this page are a snapshot, not a
constant.
