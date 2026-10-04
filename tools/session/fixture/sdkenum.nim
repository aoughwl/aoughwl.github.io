## The same enum questions, but in a module that imports the ModSdk — compiled
## by plain `nimony c`, not by build_mod. Separates "importing the SDK" from
## "the way build_mod builds".
import jester

type Probe = enum PA, PB, PC, PD

proc enumOrds(): int =
  result = ord(PA) + ord(PB) * 10 + ord(PC) * 100 + ord(PD) * 1000

proc enumMask(): int =
  let a = PA
  result = 0
  if a == PA: result = result + 1
  if a == PB: result = result + 2
  if a == PC: result = result + 4
  if a == PD: result = result + 8
