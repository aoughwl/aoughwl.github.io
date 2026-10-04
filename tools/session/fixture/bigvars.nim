## A var block shaped like a real mod's: many globals, mixed types, several
## initialised to -1. If any of the -1s reads back as 0, a module-level
## initializer did not run and every mod that guards on `x < 0` is broken.

var
  n0 = -1
  s0 = ""
  f0 = 0.5
  q0: seq[int] = @[]
  b0 = false
  n1 = -1
  n2 = -1
  n3 = -1
  n4 = -1
  n5 = -1
  s5 = ""
  f5 = 0.5
  q5: seq[int] = @[]
  b5 = false
  n6 = -1
  n7 = -1
  n8 = -1
  n9 = -1
  n10 = -1
  s10 = ""
  f10 = 0.5
  q10: seq[int] = @[]
  b10 = false
  n11 = -1
  n12 = -1
  n13 = -1
  n14 = -1
  n15 = -1
  s15 = ""
  f15 = 0.5
  q15: seq[int] = @[]
  b15 = false
  n16 = -1
  n17 = -1
  n18 = -1
  n19 = -1
  n20 = -1
  s20 = ""
  f20 = 0.5
  q20: seq[int] = @[]
  b20 = false
  n21 = -1
  n22 = -1
  n23 = -1
  n24 = -1
  n25 = -1
  s25 = ""
  f25 = 0.5
  q25: seq[int] = @[]
  b25 = false
  n26 = -1
  n27 = -1
  n28 = -1
  n29 = -1
  n30 = -1
  s30 = ""
  f30 = 0.5
  q30: seq[int] = @[]
  b30 = false
  n31 = -1
  n32 = -1
  n33 = -1
  n34 = -1
  n35 = -1
  s35 = ""
  f35 = 0.5
  q35: seq[int] = @[]
  b35 = false
  n36 = -1
  n37 = -1
  n38 = -1
  n39 = -1

proc firstNeg(): int = n0
proc midNeg(): int = n20
proc lastNeg(): int = n39
## How many of them are actually -1. The whole block in one number.
proc negCount(): int =
  result = 0
  if n0 == -1: result = result + 1
  if n1 == -1: result = result + 1
  if n2 == -1: result = result + 1
  if n3 == -1: result = result + 1
  if n4 == -1: result = result + 1
  if n5 == -1: result = result + 1
  if n6 == -1: result = result + 1
  if n7 == -1: result = result + 1
  if n8 == -1: result = result + 1
  if n9 == -1: result = result + 1
  if n10 == -1: result = result + 1
  if n11 == -1: result = result + 1
  if n12 == -1: result = result + 1
  if n13 == -1: result = result + 1
  if n14 == -1: result = result + 1
  if n15 == -1: result = result + 1
  if n16 == -1: result = result + 1
  if n17 == -1: result = result + 1
  if n18 == -1: result = result + 1
  if n19 == -1: result = result + 1
  if n20 == -1: result = result + 1
  if n21 == -1: result = result + 1
  if n22 == -1: result = result + 1
  if n23 == -1: result = result + 1
  if n24 == -1: result = result + 1
  if n25 == -1: result = result + 1
  if n26 == -1: result = result + 1
  if n27 == -1: result = result + 1
  if n28 == -1: result = result + 1
  if n29 == -1: result = result + 1
  if n30 == -1: result = result + 1
  if n31 == -1: result = result + 1
  if n32 == -1: result = result + 1
  if n33 == -1: result = result + 1
  if n34 == -1: result = result + 1
  if n35 == -1: result = result + 1
  if n36 == -1: result = result + 1
  if n37 == -1: result = result + 1
  if n38 == -1: result = result + 1
  if n39 == -1: result = result + 1
