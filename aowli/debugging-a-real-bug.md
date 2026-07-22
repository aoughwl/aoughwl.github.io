# Debugging a real bug — a case study

[[toc]]

---

A real session: a subtle bug injected into a real nimony library, found with
aowlidbg, fixed. One bug, not a benchmark — presented as it actually happened.

## The library

[`aoughwl/css`](../docs/css), a nimony MDN-typed CSS engine. A harness module
runs `validateValue(prop, value)` over 15 cases and prints
`prop | value | VALID/INVALID | error`.

## The bug

One line, `css/value_lex.nim`, the value tokenizer — the unit-accumulation loop
for a dimension token:

```nim
# correct
while i < n and isIdentCont(s[i]): u.add s[i]; inc i

# injected off-by-one
while i+1 < n and isIdentCont(s[i]): u.add s[i]; inc i
```

`i+1 < n` stops one character early whenever the dimension ends the string, so
the unit string `u` silently drops its last character.

## Symptom

Real `aowli-interp` output with the bug in place:

```
width | 10px | INVALID | at token 1: expected 'auto' | a length | a percentage | … , got '10p'
width | calc(100% - 10px) | INVALID | calc(): unexpected 'x' in argument 1
font-size | 12pt | INVALID | … , got '12p'
```

All three are `VALID` in the correct library. The error text even hints at
it — `got '10p'`, a stray `'x'` — but that's a guess, not a diagnosis.

## The debug session

**First attempt — the wrong move.** `aowli-dbg --break:69` (the line emitting
`vtDimension`) fired **271 times**: line 69 exists in several modules, so the
breakpoint fired mostly inside the unrelated color-keyword matcher, dumping
frames like `s = aliceblue`, `s = aquamarine`, … — noise. Line breakpoints are
file-agnostic; that's the honest lesson.

**Second attempt — scoped to the routine.** `aowli-dbg --break-func:lexValue`
captured every statement inside the tokenizer itself. The real frame capture
for the `10px` input:

```
num = 10
u =
num = 10
u = p          ← should be "px"
```

`num = 10` is correct on both hits. The unit `u` finalizes as `p`, not `px` —
the loop dropped the trailing `x`. That one wrong local is the whole diagnosis:
an off-by-one in the loop bound, found with **no print statements added**.

## The fix

```nim
while i+1 < n and isIdentCont(s[i]): u.add s[i]; inc i
                ↓
while i < n and isIdentCont(s[i]): u.add s[i]; inc i
```

Re-run:

```
width | 10px | VALID
font-size | 12pt | VALID
width | calc(100% - 10px) | VALID
```

## Takeaway

aowlidbg inspects live frame state at a point in the program without
instrumenting the source. `--break-func` is what makes that inspection usable
on a real codebase — it scopes the capture to the routine you actually
suspect, instead of every routine that happens to share a line number. The
wrong value (`u = p` where `"px"` was expected) *is* the diagnosis, once you're
looking at the right frame. This is one real bug, found once, not a claim
about debugging in general.
