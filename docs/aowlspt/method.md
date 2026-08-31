# The measurement discipline

This page describes how aowlspt decides that something is true. It is not
style advice. Every serious defect this project has shipped was a failure of
this discipline rather than a failure of code, and the rules below are each
written against a specific incident.

## A verification that cannot fail IS the bug

Twenty-plus hours of settings-screen defects were all one shape: a check that
could only ever say yes.

- A row relabel sized its write by counting the labels the **donor** had text
  on, then re-read only what it had just written. It reported "0 did not take"
  for sixteen rows that were all visibly wrong on screen.
- A settle-loop counted any tick with `reaped == 0` as STABLE — which is
  indistinguishable from "the thing has not spawned yet" — so it reached its
  threshold and disabled itself permanently *before* the late spawn.
- An offline disassembly proof established, correctly, which field
  `SetGameModeText` writes. It could not establish that the field reaches the
  screen. It did not. The label the player sees was a different object in a
  different scene root.
- The backend selftest asserted with a substring `contains`, so a payload that
  was not valid JSON at all passed for months.

The rule that falls out of these:

> **Assert a property of the finished state, never a property of your own
> write.**

Prefer the negative, because a negative can be falsified and a self-comparison
cannot:

- "No label under this panel still reads the donor's caption."
- "Exactly one stock panel is active."
- "The served payload parses strictly."

If you cannot describe the input that would make your check fail, you have not
written a check.

## Three outcomes, never two

Every verification reports one of:

| Verdict | Meaning |
| --- | --- |
| **PASS** | The asserted property of the finished state was observed to hold. |
| **FAIL** | It was observed not to hold. |
| **INCONCLUSIVE** | It could not be observed. |

**"I could not look" is not a pass.** A search that reports STOPPED EARLY, an
unreadable pointer, a screen that never opened, a log line that never
appeared — every one of those is INCONCLUSIVE, and collapsing it into either
PASS or FAIL destroys the information that matters most.

The live inspector models this correctly, and code that consumes the inspector
must not flatten it back to a boolean.

## Structural is not behavioural

A sibling index, an `activeSelf`, a log line saying `ok` — these are
**evidence**, not proof. The only thing that settles a question about the UI is
reading back what the live tree renders.

The same distinction applies everywhere:

- A symbol present in a binary is evidence the feature was compiled, not proof
  it runs.
- A route registered is evidence the server can answer, not proof the client
  asked.
- A detour installed is evidence the hook exists, not proof it fired.

## Positive controls

A measurement that has never been seen to produce a *different* answer is not
yet a measurement. Before trusting an instrument, run it against a case where
you already know the answer, and confirm it says so.

Concretely: before believing "no bots spawned", confirm the counter can report
a non-zero number at all. Before believing a marker is absent from a binary,
confirm the same check finds a marker you know is present. This costs one extra
run and it is the difference between a result and a hope.

## Disjoint and exhaustive decomposition

When accounting for something measurable — frame time, a bot population, the
bytes of a payload — decompose it into buckets that **do not overlap** and
**add up**, and state the percentage accounted for.

A profile that attributes 40% of a frame and leaves 60% unlabelled has not
found the cost; it has found *a* cost. Say "84% accounted for, 16%
unattributed" rather than presenting the largest bucket as the answer. The
unattributed remainder is a number, and reporting it is what makes the
decomposition checkable.

## Say what you measured, and say when you inferred

A fact recorded as measured that was not measured poisons everything
downstream, because the next reader cannot tell it apart from one that was.
Write **inferred** when you inferred it, and **UNKNOWN** when you could not
establish it.

This applies to documentation as forcefully as to code. A doc that
authoritatively states something false is precisely the failure mode this
project keeps paying for — `docs/SAIN_RVA.md` currently asserts a blocker that
was fixed weeks ago, and that stale claim has cost real time more than once.
That is why the [reference section](./reference/) is generated from source
rather than written by hand.
