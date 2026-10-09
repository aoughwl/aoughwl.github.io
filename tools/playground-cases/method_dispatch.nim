import std/syncio
type
  Shape = ref object of RootObj
  Square = ref object of Shape
    side: int
  Circle = ref object of Shape
    r: int
method area(s: Shape): int {.base.} = 0
method area(s: Square): int = s.side * s.side
method area(s: Circle): int = 3 * s.r * s.r
let shapes: seq[Shape] = @[Shape(Square(side: 2)), Shape(Circle(r: 1))]
var total = 0
for s in shapes: total = total + area(s)
echo total
