import std/[syncio, options]
proc find(xs: seq[int], v: int): Option[int] =
  for i, x in xs:
    if x == v: return some(i)
  none[int]()
echo find(@[4, 5, 6], 5).isSome
