## A library module that belongs to a mod, not to the engine.
##
## It is listed in this mod's `exports`, so any mod that declares a dependency
## on `example.counter` may `import example_counter/counter` and call these.
## The `total` below is the point of the example: there is one of it, shared by
## every mod that imports this module, because the module has one identity in
## the interpreter no matter whose build compiled it.

var total = 0

proc bump*(by: int): int =
  total = total + by
  result = total

proc counted*(): int = total
