import std/syncio
var s = 0
for i in 0 ..< 1000000: s += i
echo s
