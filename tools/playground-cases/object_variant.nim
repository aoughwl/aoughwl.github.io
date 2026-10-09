import std/syncio
type
  Kind = enum kInt, kStr
  Node = object
    case kind: Kind
    of kInt: i: int
    of kStr: s: string
proc show(n: Node): string =
  case n.kind
  of kInt: "int " & $n.i
  of kStr: "str " & n.s
echo show(Node(kind: kInt, i: 7)), "; ", show(Node(kind: kStr, s: "x"))
