import dep

type Scaled = enum SA, SB, SC, SD

proc ords(): int =
  result = ord(SA) + ord(SB) * 10 + ord(SC) * 100 + ord(SD) * 1000

proc eqMask(): int =
  let a = SA
  result = 0
  if a == SA: result = result + 1
  if a == SB: result = result + 2
  if a == SC: result = result + 4
  if a == SD: result = result + 8

proc useDep(): int = depAdd(1, 2)
