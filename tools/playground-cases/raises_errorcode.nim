import std/syncio
proc risky(x: int): int {.raises.} =
  if x > 2: raise ValueError
  x * 10
try:
  echo risky(1)
  echo risky(5)
except ErrorCode as e:
  echo "caught ", e
