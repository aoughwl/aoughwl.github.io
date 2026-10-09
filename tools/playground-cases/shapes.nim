import std/syncio

type
  Shape = object
    name: string
    sides: int

proc describe(s: Shape): string =
  s.name & " has " & $s.sides & " sides"

let shapes = @[Shape(name: "triangle", sides: 3), Shape(name: "square", sides: 4)]
for s in shapes:
  echo describe(s)
