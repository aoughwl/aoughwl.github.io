import std/syncio
proc counter(): proc (): int {.closure.} =
  var n = 0
  result = proc (): int {.closure.} =
    inc n
    n
let c = counter()
discard c()
discard c()
echo c()
