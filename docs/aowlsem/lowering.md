# Lowering reference

What `aowlsem` turns each construct into. The parse form (`.p.aif`) carries bare
identifiers and source shapes; the semchecked form (`.s.aif`) carries mangled
symbols, resolved overloads, concrete types, and explicit conversions. This page
catalogs the canonical transformations, in AIF's parenthesised form.

Notation: `x.0` is a mangled local, `f.0.<mod>` an imported symbol,
`I<hash>` a generic-instance suffix, `<sys>` the `system` module suffix.

[[toc]]

---

## Names, calls & overloads

A bare identifier resolves to its mangled symbol; a call resolves its overload by
arity and argument type and names the exact routine (and instance):

```
;; parse
(call echo x)
;; semchecked  — echo expands, write is resolved to system, arg conversion made explicit
(cmd write.0.<sys> stdout.0.<sys> (hconv (u 64) x.0))
```

Operators lower to their **magic** with an operand-type child, not a routine
call:

```
(infix + a b)     ─►   (add (i 64) a.0 b.0)
(infix <= a b)    ─►   (le  (i 64) a.0 b.0)
```

A `var` parameter is a `(mut T)` location; a use auto-derefs:

```
(param :x . . (mut (i 64)) .)          ;; declaration
… x …            ─►   (hderef x.0)     ;; use
```

## Literals & sized ints

A bare integer literal is `int` (i64). Flowing into a **narrower / differently-
signed** target it gets an explicit conversion — carried by the decl's type slot
for a binding, but spelled out where the slot can't carry it (an `oconstr` field
value, a call argument):

```
;; let x: uint8 = 100     — type slot carries it, value stays bare
(let :x.0 . . (u 8) 100)

;; Color(r: 100)          — kv value slot has no type, so hconv is explicit
(kv r.0 (hconv (u 8) 100))
```

Inside a `const` aggregate every integer leaf is stamped with its width:

```
(kv n.0 (suf 10 "i64"))
```

## Objects & construction

A value object constructs with `oconstr`; every field is filled in declaration
order (omitted fields take their type's zero value):

```
;; Point(x: 3, y: 4)
(oconstr Point.0. (kv x.0 3) (kv y.0 4))
```

Field access is `dot`; a `ref`/`ptr` receiver auto-derefs to a `ddot`:

```
(dot p.0 x.0)              ;; value object
(ddot r.0 x.0)             ;; ref/ptr receiver
```

A value flowing to a `ref`-typed target is heap-allocated:

```
(oconstr Obj …)   ─►   (newobj (ref Obj (notnil)) …)   ;; via emitValMaybeRef
```

## `ref object`

A `ref object` binds a **ref-alias** whose value type is `ref <.Obj>`; the fields
live under a separate `.Obj` type. Construction allocates:

```
;; type Node = ref object of RootObj (val: int)
(type :Node.0. . . (ref Node.Obj.0. (notnil)))
(type :Node.Obj.0. . . (object RootObj.0.<sys> (fld :val.0 . . (i 64) .)))

;; Node(val: 5)
(newobj (ref Node.Obj.0. (notnil)) (kv val.0 5))
```

## Enums, `case`, and bool discriminators

An `of` label resolves to the member symbol; a **bool** discriminator's labels
are the literal tags, not the bool enum's members:

```
(of (ranges red)   …)   ─►   (of (ranges red.0.) …)     ;; enum
(of (ranges true)  …)   ─►   (of (ranges (true)) …)      ;; bool
```

A non-exhaustive enum `case` with no `else` raises `E0500`; a bool/enum
`case` selector that isn't `bool` triggers exhaustiveness tracking.

## Distinct types & `{.borrow.}`

A `{.borrow.}` operator forwards to the base type's op with each distinct arg
converted down, and — when the op **returns** the distinct type — the result
converted back:

```
;; proc `+`(a, b: Celsius): Celsius {.borrow.}   (Celsius = distinct float)
(asgn result.0
  (dconv Celsius.0.
    (add (f 64) (dconv (f 64) a.0) (dconv (f 64) b.0))))
```

## Generics — instantiation

A generic call/type is instantiated on demand; the instance is content-addressed
by `(origin, type-args)` and memoised. A call names the concrete instance:

```
(call id x)   ─►   (call id.0.I<hash> x.0)      ;; id[int] instance
```

### Generic `ref object`

Emitted as **two abstract declarations** — the ref-alias and its underlying
object — each with its own typevars (alias `T.0`, object `T.1`) and **empty
pragmas** (per-instance lifetime hooks live on the concrete instance, not the
generic decl):

```
;; type Container[T] = ref object of RootObj (items: seq[T])
(type :Container.0. . (typevars (typevar :T.0. . . . .)) .
  (ref (at Container.Obj.0. T.0.) (notnil)))
(type :Container.Obj.0. . (typevars (typevar :T.1. . . . .)) .
  (object RootObj.0.<sys> (fld :items.0 . . (at seq.0.<sys> T.1.) .)))

;; Container[int](items: …)   — constructs the concrete instance, allocated
(newobj (ref Container.Obj.0.I<hash> (notnil)) (kv items.0 …))
```

A generic instance's synthesized lifetime hooks are named **without** a module
suffix (the instance hash already makes them globally unique).

### Generic sum types & value objects

A generic sum type infers its instance from the constructor argument, and its
branch fields resolve inside a generic body:

```
;; let d = Some(99)  ─►  Option[int] inferred; d.val is int
(dot d.0 val.0)                         ;; named-variant branch field, resolved
```

Two-parameter sums (`Either[int, string]`), annotated conversions
(`Option[int](x)`), and type-named value constructors (`Pair(first: 1, second:
2)` → `Pair[int]`) all resolve to the same instance identity.

## Methods & dynamic dispatch

A type with user `method`s carries a `methods` vtable table in its pragmas. An
inheritable object with managed fields that *also* has methods emits **only**
that table — no standalone `=destroy`/`=copy`/… hooks, because destruction routes
through the vtable's destroy slot (filled by a later pass):

```
;; type Animal = object of RootObj (name: string); method sound(a: Animal)
(type :Animal.0. .
  (pragmas (methods (kv "sound\3A…encoded-sig…" sound.0.)))
  (object RootObj.0.<sys> (fld :name.0 . . string.0.<sys> .)))
```

## Templates & macros

An `untyped` template inlines its body at the call site (its parameters are
wildcards that accept any argument):

```
;; template twice(x: untyped) = (x) + (x)   ;   twice(a)
(expr (add (i 64) a.0 a.0))
```

A macro expands via compile-time evaluation; the expansion is checked like
ordinary source.

## Subscript & assignment operators

A user `[]` / `[]=` on an object or `ref` receiver routes to the operator, not
the builtin subscript; a `var` receiver is passed by address; multi-index
`x[i, j]` collects all indices:

```
(at m i)          ─►   (call [].0 m.0 i.0)                  ;; custom []
(asgn (at g r c) v) ─► (call []=.0 (haddr g.0) r.0 c.0 v.0) ;; multi-index []=
```

## Control flow

`if`/`case` in value position become `(expr …)`; each construct lowers to its
typed tag with the condition checked to be `bool` (`E0700` otherwise):

```
(if (elif cond a) (else b))   ;; statement
(expr (if (elif cond (expr a)) (else (expr b))))   ;; value position
```

`defer`, labelled `block`, `try`/`except T as e`/`finally`, and `while` lower to
their typed tags directly; an unconditional `return`/`raise`/`break`/`continue`
followed by a sibling statement raises `E0900`.

---

For the full list of supported constructs see the [main page →
Capabilities](../aowlsem#capabilities); for how these transformations are driven
(demand-driven, fused check+lower) see [Architecture](architecture).
