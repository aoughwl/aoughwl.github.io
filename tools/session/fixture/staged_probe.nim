## Do enum literals have the right ordinals inside a MOD?
##
## Measured: they do not. In `aoughwl.shell` and in `jester.2048`, every literal
## of every enum reads as ordinal 0, so one value compares equal to all of them
## and `case` takes the wrong arm. A plain `nimony c` module does not do this.
## This mod exists to find the smallest thing that does.

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

proc enumCase(): int =
  let a = PA
  case a
  of PA: result = 1
  of PB: result = 2
  of PC: result = 3
  of PD: result = 4

proc start() = discard
