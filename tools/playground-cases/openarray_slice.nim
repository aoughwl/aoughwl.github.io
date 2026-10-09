import std/syncio
proc total(xs: openArray[int]): int =
  result = 0
  for x in xs: result += x
let a = [1, 2, 3, 4, 5]
echo total(a), " ", total(a.toOpenArray(1, 3))
