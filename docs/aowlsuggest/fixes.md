# Quick-fixes

How a diagnostic becomes a source edit — and why an edit can never corrupt valid
code.

[[toc]]

---

## The auto-fixable set

aowlparser's `fix` field is a *human* hint (`"did you mean '=='?"`,
`"insert ':' at the end of the line"`), not a machine edit. So aowlsuggest maps a
diagnostic to a concrete edit itself, and it does so **only** where the repair is
unambiguous and localized:

| code | repair | example |
|------|--------|---------|
| `assignment-in-condition` | replace the `=` with `==` | `if x = 5:` → `if x == 5:` |
| `comparison-in-binding` | replace the `==` with `=` | `let x == 5` → `let x = 5` |
| `else-if-not-elif` | collapse `else if` to `elif` | `else if b:` → `elif b:` |
| `walrus-in-binding` | replace `:=` with `=` | `let x := 5` → `let x = 5` |
| `arrow-return-type` | rewrite `-> T` return to `: T` | `proc f() -> int` → `proc f(): int` |
| `angle-bracket-generics` | rewrite `<T>` generics to `[T]` | `proc f<T>()` → `proc f[T]()` |
| `mut-not-a-keyword` | rewrite `let/var/const mut x` to `var x` | `let mut x = 5` → `var x = 5` |
| `go-var-notype` | insert the `:` in a `name type` binding | `var x int` → `var x: int` |
| `mismatched-bracket` | swap the wrong close for the one its opener wants | `(1 + 2]` → `(1 + 2)` |
| `expected-colon` | insert `:` at the end of the header | `if c` → `if c:` |
| `missing-routine-equals` | insert `=` after the signature | `proc f()` → `proc f() =` |
| `unterminated-char` | add the missing closing `'` | `'a` → `'a'` |
| `unmatched-close` | delete a surplus close bracket | `x)` → `x` |
| `unclosed-bracket` | add the matching close (single-line) | `(1 + 2` → `(1 + 2)` |
| `tabs-not-allowed` | replace a **mid-line** tab with a space | `let⇥x` → `let x` |
| `unterminated-string` | append the missing closing `"` | `echo "hi` → `echo "hi"` |
| `unterminated-comment` | append the missing `]#` at EOF | `#[ todo` → `#[ todo ]#` |
| `invalid-int-literal` | lower-case an upper-case base prefix | `0O17` → `0o17` |
| `trailing-whitespace` *(style)* | delete the spaces/tabs before the newline | `x = 1␠␠` → `x = 1` |
| `missing-final-newline` *(style)* | append a terminating newline | *(adds `\n`)* |
| `line-ending` *(style)* | rewrite the EOL to the requested LF/CRLF | `x␍␊` → `x␊` |
| `bom-rejected` *(style)* | strip a leading UTF-8 byte-order mark | *(removes BOM)* |
| `redundant-semicolon` *(style)* | delete a redundant trailing `;` | `let x = 5;` → `let x = 5` |

The four *(style)* fixes fire only when the matching policy is opted in with
`--style:` / `--pedantic` (see [Commands](commands#style-lint-policies)); each
touches nothing but insignificant whitespace/BOM, so it can never change what the
program means.

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

Everything else is surfaced as a **suggestion** — reported, never applied.
`expected-condition` ("add a condition") is a good example: the repair is real
but there is no single unambiguous character to insert. `foreign-function-keyword`
(a routine written `fn`/`function`/`fun name() { … }`) is another: fixing it means
replacing both the keyword and the whole `{ }` body with `proc name() = <indented
body>` — a multi-span reformat, so it points at `proc` and leaves the edit to you.
`foreign-block-keyword` (a `class`/`struct`/`interface`/`impl`/`trait`/`namespace`/
`module name { … }` block) is the type/module analogue: it points at `type Name =
object` (or, for a namespace/module, at Nim's file-is-a-module model) and lets you
shape the declaration. `unterminated-backtick`
is another: a backtick identifier may hold spaces and operators, so where the
closer belongs is ambiguous (appending it at the line's end would turn
`` let `a = 1 `` into the nonsense identifier `` `a = 1` `` — which the
syntax-only checker accepts, a fix that verifies yet means something the author
never wrote). The lesson: the checker oracle is *necessary but not sufficient*;
an auto-fix also has to be **unambiguous**, or it stays a suggestion.

**No diagnostic is ever bare.** A suggestion's text is aowlparser's own `fix`
hint when it attached one (context-specific, authoritative); otherwise a crisp
fallback from aowlsuggest's knowledge base — so even a lexer value error (a bad
escape, an out-of-range number, an illegal byte) tells you what to do. A tested
completeness invariant asserts every known code carries guidance, so a newly
added parser code that lacks advice is caught immediately.

## The zero-false-positive loop

This is the heart of the tool. A fix that corrupts valid code is worse than no
fix, so **every** candidate edit is verified against the parser before it is
kept:

1. Run the checker on the current source; collect the error set.
2. Pick the first source-ordered diagnostic with an untried auto-fix.
3. Apply its edit to a candidate copy.
4. Run the checker on the candidate.
5. **Accept** the edit only if it is a strict improvement and introduces *no new
   error code*. Two branches: an **error** fix must make the error count *strictly
   drop*; a **style/warning** fix (there are no errors to remove) must leave the
   error count unchanged, make the *total* diagnostic count strictly drop, and add
   *no new code of any severity*. Otherwise discard it and mark that diagnostic
   tried.
6. On an accepted edit, positions have shifted — reconsider everything and loop.

The checker itself is the oracle. An edit that would break valid code cannot make
the count go down without adding a new code, so it is rejected. The loop
terminates because every accepted edit strictly lowers a bounded count.

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

## Editor & CI surfacing

The same verified fixes flow out to every consumer of the tool. In an editor
(through [aowllsp](aowl-lsp) or the built-in `lsp-server`) each fix is a
`CodeAction`, and a single **`source.fixAll`** action applies all of them at once
— ideal for fix-on-save. In CI, `lint --format:sarif` emits each fix as a SARIF
`fix`, so **GitHub code scanning** renders it as a one-click *Apply fix* button in
the PR, with a stable per-alert fingerprint so it tracks across commits.

## Extending the set

The set covers every repair that is *mechanically unambiguous*; anything that
needs human judgement (which condition to add, object-vs-enum for a missing type
`=`) stays a **suggestion**. Because aowlparser's `fix` hint is prose, each code
needs a hand-written mapping here. The open
[parser API request](the-contract#when-the-json-isnt-enough) asks aowlparser to
emit a structured `edit` instead — at which point `fix` becomes "apply the edit
if present", the verify loop is unchanged, and repairs extend to every code the
parser can fix, with no per-code logic in aowlsuggest.
