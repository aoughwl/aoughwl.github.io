## Does a `case` over an enum RETURNED FROM A CALL pick the right branch?
##
## The shell's launcher does exactly this shape, and behaves as though a
## returned `RowNone` lands in the first `of` branch (`RowDelete`) — which would
## make it open a delete confirmation on every row, every frame, with nobody
## having clicked anything.

type Action = enum ActNone, ActDelete, ActEdit, ActCopy

var log = 0

proc decide(): Action =
  ## Returns the ZEROTH value, the one the case below does not list.
  result = ActNone

proc runCase() =
  case decide()
  of ActDelete: log = 1
  of ActEdit: log = 2
  of ActCopy: log = 3
  else: log = 99

## The same thing through a local, which is the shape that should certainly work.
proc runCaseViaLocal() =
  let a = decide()
  case a
  of ActDelete: log = 1
  of ActEdit: log = 2
  of ActCopy: log = 3
  else: log = 99

proc viaCall(): int =
  runCase()
  result = log

proc viaLocal(): int =
  runCaseViaLocal()
  result = log

## And the ordinal, to show what the value actually is.
proc ordOfDecide(): int = ord(decide())
