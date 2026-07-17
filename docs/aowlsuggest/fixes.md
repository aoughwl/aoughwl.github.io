---
nav_exclude: true
title: Quick-fixes
parent: Suggestions — aowlsuggest
grand_parent: aowlmony
nav_order: 3
---

# Quick-fixes
{: .no_toc }

How a diagnostic becomes a source edit — and why an edit can never corrupt valid
code.
{: .fs-6 .fw-300 }

<details open markdown="block">
  <summary>Contents</summary>
  {: .text-delta }
- TOC
{:toc}
</details>

---

## The auto-fixable set

aowlparser's `fix` field is a *human* hint (`"did you mean '=='?"`,
`"insert ':' at the end of the line"`), not a machine edit. So aowlsuggest maps a
diagnostic to a concrete edit itself, and it does so **only** where the repair is
unambiguous and localized:

| code | repair | example |
|------|--------|---------|
| `assignment-in-condition` | replace the `=` with `==` | `if x = 5:` → `if x == 5:` |
| `mismatched-bracket` | swap the wrong close for the one its opener wants | `(1 + 2]` → `(1 + 2)` |
| `expected-colon` | insert `:` at the end of the header | `if c` → `if c:` |
| `missing-routine-equals` | insert `=` after the signature | `proc f()` → `proc f() =` |
| `unterminated-char` | add the missing closing `'` | `'a` → `'a'` |
| `unmatched-close` | delete a surplus close bracket | `x)` → `x` |
| `unclosed-bracket` | add the matching close (single-line) | `(1 + 2` → `(1 + 2)` |
| `tabs-not-allowed` | replace a **mid-line** tab with a space | `let⇥x` → `let x` |

Each carries a **guard** so a surprising span degrades to "no auto-fix" rather
than a bad splice: the assignment fix checks the span really is a single `=`; the
bracket fixes check the span is a bracket char and read the opener from the
message; the colon/`=` inserts check the line doesn't already end that way; the
tab fix only touches a tab that is *not* indentation (an indentation tab changes
block structure by an unknown amount, so it stays a suggestion).

More aggressive repairs — deleting a bracket, appending a closer — are safe only
because of the verify loop below: `unclosed-bracket`'s "append a closer on this
line" is correct for a single-line bracket and simply *rejected* when the bracket
legitimately spans lines (the edit wouldn't reduce errors there).

Everything else with a repair hint is surfaced as a **suggestion** — reported,
never applied. `expected-condition` ("add a condition") is a good example: the
repair is real but there is no single unambiguous character to insert.

## The zero-false-positive loop

This is the heart of the tool. A fix that corrupts valid code is worse than no
fix, so **every** candidate edit is verified against the parser before it is
kept:

1. Run the checker on the current source; collect the error set.
2. Pick the first source-ordered diagnostic with an untried auto-fix.
3. Apply its edit to a candidate copy.
4. Run the checker on the candidate.
5. **Accept** the edit only if the candidate has *strictly fewer* errors **and**
   introduces *no new error code*. Otherwise discard it and mark that diagnostic
   tried.
6. On an accepted edit, positions have shifted — reconsider everything and loop.

The checker itself is the oracle. An edit that would break valid code cannot make
the error count go down without adding a new error, so it is rejected. The loop
terminates because every accepted edit strictly lowers the error count, which
bounds the number of iterations.

```
apply candidate ─► re-check ─► fewer errors AND no new code? ─► keep ─┐
        ▲                                    │ no                     │
        └──────────── next diagnostic ◄──────┴── discard ◄────────────┘
```

## Cascades

Because the loop re-checks after every accepted edit, independent errors — even
ones that only become visible once an earlier one is repaired — are all handled
in a single `fix` run:

```console
$ cat casc.nim
proc f()
  if a = b:
    echo 1
$ aowlsuggest fix casc.nim --write
fixed casc.nim: applied 2 change(s)
  - insert '=' (was missing-routine-equals at 1:1)
  - change '=' to '==' (was assignment-in-condition at 2:8)
```

## Applying edits

Edits are modelled as byte-offset splices (`textedit.nim`), computed from the
diagnostic's line/column against a line-start index. Multiple edits are applied
in a single left-to-right pass so no splice shifts another's offsets, and the
`--dry-run` diff is a standard LCS-based unified diff between the original and the
repaired source.

## Extending the set

The four-code limit is a *consequence of the contract*, not a design ceiling:
because the `fix` hint is prose, each new code needs a hand-written mapping here.
The open [parser API request](the-contract#when-the-json-isnt-enough) asks
aowlparser to emit a structured `edit` instead — at which point `fix` becomes
"apply the edit if present", the verify loop is unchanged, and repairs extend to
every code the parser can fix, with no per-code logic in aowlsuggest.
