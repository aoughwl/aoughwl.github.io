import std/[syncio, tables]
var t = initTable[string, int]()
t["a"] = 1
t["bb"] = 11
echo t.len, " ", t["bb"], " ", t.hasKey("zz")
