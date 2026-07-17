# How this works

aowlmony is not one compiler binary. It is a **pipeline of separate, open stages**,
and that is the whole point.

---

## The usual way: one sealed binary

The classic Nim / Nimony toolchain reaches you as a **built compiler**. Parsing,
semantic checking, lowering, and code generation all happen *inside* that one
program. They are real, well-defined stages — but they're internal: the
intermediate results live in memory, the pass boundaries aren't something you
hold in your hand, and swapping one stage for your own means patching and
rebuilding the compiler. It works, but it's a black box.

## Our way: a pipeline you can see through

aowlmony breaks the same job into **independent tools, one per stage**, with a
stable, textual IR flowing between every one of them:

```
 .nim / .aowl ──► aowlparser ──► aowlsem ──► aowlhexer ──┬─ aowlc  → C / native
    source          parse       semcheck    lower       ├─ aowljs → JavaScript
                                                         └─ aowli  → interpret / VM
```

The IR at every seam is **AIF**, which is **byte-for-byte Nimony's NIF**. Because
the seams are a real format on disk — not a private in-memory structure — a few
things fall out that a sealed binary can't give you:

- **Inspect anything.** Stop after any stage and read exactly what it produced.
  The IR is text; there's nothing hidden between the passes.
- **Run a stage on its own.** `aowlparser` parses, `aowli` interprets — each is a
  tool you can invoke by itself, on its own input, in isolation.
- **Swap a stage.** Since every stage speaks the same AIF (≡ NIF), you can drop
  one of ours in *beside* nimony's own equivalents (`nifler` / `nimsem` /
  `hexer`), or replace it with your own, without touching the rest.
- **Runs where a packed binary can't** — most notably the **browser**: the
  parser, checker, and interpreter are compiled to JavaScript and run
  client-side. Try it in the [playground](https://aoughwl.github.io/playground/).

Same programs, same output — Nim and Nimony code behaves identically — but the
machine that produces it is open at every joint instead of sealed shut.

## The format that makes the seams work

All of this rests on one contract: **AIF ≡ NIF**, byte-for-byte, so each stage is
a genuine drop-in. That's written up in the engineering notes —
**[AIF ≡ NIF](/docs/aif)**.

Then walk the stages themselves, top to bottom, in the nav to the left.
