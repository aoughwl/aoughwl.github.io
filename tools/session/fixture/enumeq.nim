## Enum EQUALITY, not `case`.
##
## The launcher behaves as though one value compares equal to two different
## enum literals at once: `a != RowNone` reads false (so it IS RowNone) while
## `a == RowDelete` reads true, in the same frame, on the same value.

type Action* = enum ActNone, ActDelete, ActEdit, ActCopy

proc decide(): Action = ActNone

proc isNone(): bool = decide() == ActNone
proc isDelete(): bool = decide() == ActDelete
proc isEdit(): bool = decide() == ActEdit
proc notNone(): bool = decide() != ActNone

## Through a local, which is how `main.nim` does it.
proc localIsDelete(): bool =
  let a = decide()
  result = a == ActDelete

proc localNotNone(): bool =
  let a = decide()
  result = a != ActNone

## The ordinals, to show what is actually being compared.
proc ordValue(): int = ord(decide())
proc ordDelete(): int = ord(ActDelete)
