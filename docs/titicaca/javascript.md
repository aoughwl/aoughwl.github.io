---
title: Titicaca's JavaScript engine
description: The pure-Nimony JavaScript engine inside Titicaca, its realms, and its current limits.
---

# The JavaScript engine

The engine is five modules: `jslex` (tokens), `jsparse` (syntax tree), `jsvalue`
(values and objects), `jsregex` (regular expressions) and `jsinterp` (the
evaluator). `jsdom` then binds the DOM in as host objects.

## Design

It is a tree-walking interpreter. That keeps it small and makes it easy to
inspect and patch, at the cost of speed and of a few language features that need
a suspendable stack (see below).

## Realms

Each frame gets its own realm. A script inside an iframe sees that frame's
`window`, `document` and globals, while the built-in intrinsics (`Object`,
`Array`, `Error`...) are shared with the main realm through the prototype chain.
Name lookup resolves against the realm's global at the root of the scope chain,
so an unbound identifier in a frame finds the frame's globals first. This one
change fixed a whole directory of attribute tests, because many of them run the
same checks in an iframe.

## Language features

Implemented: functions and closures, classes, `let`/`const`, destructuring,
spread, template literals, getters and setters, `Proxy`, `Reflect`,
`Object.defineProperties`, symbols, regular expressions and the usual built-ins.
Prototype rules follow the spec, including `__proto__` accessors and the
immutable-prototype behaviour of the global object.

## Host hooks

- `hostIndexer`: lets the DOM expose live indexed access (`list[i]`) on
  collections without copying them into arrays.
- Reflection: one generic accessor pair serves every reflected attribute rather
  than thousands of hand-written getters.
- Event handler attributes are compiled on first use and cloned with the node.

## Known gaps

- **`await` cannot suspend** and **generators are unimplemented**, because a
  tree-walking evaluator lives on the native stack. A bytecode VM would fix both
  and is the largest single lever left.
- **No JIT.** Speed is that of an interpreter.
- **Out of memory is not recoverable.** The runtime's allocator can fail by
  emptying a sequence and carrying on, so a realm that runs out of memory can
  crash on its next index. The runner fences steps, depth and memory to keep
  this out of results.
