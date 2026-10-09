import std/[syncio, sequtils]
let xs = @[1, 2, 3, 4, 5]
echo xs.filterIt(it mod 2 == 1).len, " ", xs.mapIt(it * it)[4], " ", xs.foldl(a + b)
