## The launcher's exact shape: every enum value has its own `of` branch, there
## is no `else`, and the ZEROTH value's branch is written LAST.
##
## The shell behaves as though a `RowNone` lands in the first branch
## (`RowDelete`) rather than in its own — opening a delete confirmation on
## every row, every frame, with nothing clicked.

type Action = enum ActNone, ActDelete, ActEdit, ActCopy

var hit = 0

proc decide(): Action = ActNone

## Zeroth listed LAST, no `else` — exactly how `main.nim` writes it.
proc lastBranch(): int =
  hit = 0
  let a = decide()
  case a
  of ActDelete: hit = 1
  of ActEdit: hit = 2
  of ActCopy: hit = 3
  of ActNone: hit = 0
  result = hit

## Zeroth listed FIRST, otherwise identical — the control.
proc firstBranch(): int =
  hit = 0
  let a = decide()
  case a
  of ActNone: hit = 0
  of ActDelete: hit = 1
  of ActEdit: hit = 2
  of ActCopy: hit = 3
  result = hit

## And directly on the call, zeroth last.
proc lastBranchOnCall(): int =
  hit = 0
  case decide()
  of ActDelete: hit = 1
  of ActEdit: hit = 2
  of ActCopy: hit = 3
  of ActNone: hit = 0
  result = hit
