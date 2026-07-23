# Debugging a real bug — a case study

[[toc]]

---

A real session: a subtle bug injected into a real nimony library, found with
aowlidbg, fixed. The kind that's hard to find *without* a debugger — because it
produces a wrong answer with **no error message at all**.

## The library

[`aoughwl/css`](../docs/css), a nimony MDN-typed CSS engine. A harness module
calls `validateValue(prop, value)` and prints `prop | value | VALID/INVALID | error`.

## The bug — one character

`css/validator.nim`, in `valueMatchesToks` — the gate that decides whether a
value *fully* matched its grammar:

```nim
# correct: a full match must consume EVERY token
for e in matchNode(root, 0):
  if e == toks.len: return true
false

# injected:  ==  →  <=
for e in matchNode(root, 0):
  if e <= toks.len: return true
false
```

`matchNode` returns the token positions a match can reach. A full match must
reach the last token — `e == toks.len`. With `<=`, **any partial match** — one
that consumed a valid prefix and stopped — is accepted, and the trailing tokens
are silently ignored.

## Symptom — a wrong answer, and nothing to go on

```
color | red       | VALID   |
color | red green | VALID    ← wrong: `color` takes ONE color
```

`red green` should be `INVALID`. Instead it is `VALID`, with an **empty error
string**. There is nothing to grep for, no farthest-failure message pointing
anywhere — and the buggy line reads perfectly plausibly ("the end position is
within bounds" is exactly what a bounds check *should* say). Reading the source
gives you nothing.

## The debug session — one breakpoint

Break inside the gate and look at what it actually decided:

```sh
aowli-dbg --break-func:valueMatchesToks  <harness.s.aif>
```

The real frame capture at the `return true` for `red green`:

```
prop = color
toks = @[VTok(kind: vtIdent, text: red, …), VTok(kind: vtIdent, text: green, …)]
e    = 1
```

`toks` holds **two** tokens; `e = 1`. The matcher consumed a single token and
the gate returned `true` anyway — the second token (`green`) was never required.
There is the bug, in one frame: a partial match (`e` < `toks.len`) accepted as a
full one. No prints added, no guessing.

> Prefer `--break-func:<routine>` over `--break:<line>`: a line number exists in
> many modules and the capture fires in all of them; a routine name scopes the
> capture to the code you actually suspect.

## The fix

```nim
if e <= toks.len: return true
        ↓
if e == toks.len: return true
```

Re-run → `color | red green | INVALID` again.

## Why this one is the point

An off-by-one that mangles *output* at least leaves a breadcrumb in the error
text. This bug leaves **nothing** — a valid-looking answer, an empty error, a
line that reads correctly. The only way in is to inspect what the code actually
decided, on the actual input, at the moment it decided it. aowlidbg does that
without touching the source: `e = 1` sitting next to a two-token value *is* the
diagnosis. One real bug, found once — but exactly the shape a debugger earns its
keep on.
