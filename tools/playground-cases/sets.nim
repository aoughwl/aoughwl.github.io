import std/[syncio, sets]
var s = initHashSet[int]()
for i in [1, 2, 2, 3]: s.incl i
echo s.len, " ", s.contains(2)
