import std/syncio
type Meters = distinct int
proc `+`(a, b: Meters): Meters = Meters(int(a) + int(b))
echo int(Meters(3) + Meters(4))
