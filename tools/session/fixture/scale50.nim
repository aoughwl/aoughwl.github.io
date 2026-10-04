## Scale probe: does a module's SIZE break enum literal ordinals?
## The launcher (2900 lines) reads every enum literal as ordinal 0; a small
## module does not. This grows the filler until it breaks.

proc fill0(x: int): int =
  result = x + 0

proc fill1(x: int): int =
  result = x + 1

proc fill2(x: int): int =
  result = x + 2

proc fill3(x: int): int =
  result = x + 3

proc fill4(x: int): int =
  result = x + 4

proc fill5(x: int): int =
  result = x + 5

proc fill6(x: int): int =
  result = x + 6

proc fill7(x: int): int =
  result = x + 7

proc fill8(x: int): int =
  result = x + 8

proc fill9(x: int): int =
  result = x + 9

proc fill10(x: int): int =
  result = x + 10

proc fill11(x: int): int =
  result = x + 11

proc fill12(x: int): int =
  result = x + 12

proc fill13(x: int): int =
  result = x + 13

proc fill14(x: int): int =
  result = x + 14

proc fill15(x: int): int =
  result = x + 15

proc fill16(x: int): int =
  result = x + 16

proc fill17(x: int): int =
  result = x + 17

proc fill18(x: int): int =
  result = x + 18

proc fill19(x: int): int =
  result = x + 19

proc fill20(x: int): int =
  result = x + 20

proc fill21(x: int): int =
  result = x + 21

proc fill22(x: int): int =
  result = x + 22

proc fill23(x: int): int =
  result = x + 23

proc fill24(x: int): int =
  result = x + 24

proc fill25(x: int): int =
  result = x + 25

proc fill26(x: int): int =
  result = x + 26

proc fill27(x: int): int =
  result = x + 27

proc fill28(x: int): int =
  result = x + 28

proc fill29(x: int): int =
  result = x + 29

proc fill30(x: int): int =
  result = x + 30

proc fill31(x: int): int =
  result = x + 31

proc fill32(x: int): int =
  result = x + 32

proc fill33(x: int): int =
  result = x + 33

proc fill34(x: int): int =
  result = x + 34

proc fill35(x: int): int =
  result = x + 35

proc fill36(x: int): int =
  result = x + 36

proc fill37(x: int): int =
  result = x + 37

proc fill38(x: int): int =
  result = x + 38

proc fill39(x: int): int =
  result = x + 39

proc fill40(x: int): int =
  result = x + 40

proc fill41(x: int): int =
  result = x + 41

proc fill42(x: int): int =
  result = x + 42

proc fill43(x: int): int =
  result = x + 43

proc fill44(x: int): int =
  result = x + 44

proc fill45(x: int): int =
  result = x + 45

proc fill46(x: int): int =
  result = x + 46

proc fill47(x: int): int =
  result = x + 47

proc fill48(x: int): int =
  result = x + 48

proc fill49(x: int): int =
  result = x + 49

type Scaled = enum SA, SB, SC, SD

proc ords(): int =
  result = ord(SA) + ord(SB) * 10 + ord(SC) * 100 + ord(SD) * 1000

proc eqMask(): int =
  let a = SA
  result = 0
  if a == SA: result = result + 1
  if a == SB: result = result + 2
  if a == SC: result = result + 4
  if a == SD: result = result + 8

proc keepAlive(): int =
  result = 0
  result = result + fill0(1)
  result = result + fill2(1)
  result = result + fill4(1)
  result = result + fill6(1)
  result = result + fill8(1)
  result = result + fill10(1)
  result = result + fill12(1)
  result = result + fill14(1)
  result = result + fill16(1)
  result = result + fill18(1)
  result = result + fill20(1)
  result = result + fill22(1)
  result = result + fill24(1)
  result = result + fill26(1)
  result = result + fill28(1)
  result = result + fill30(1)
  result = result + fill32(1)
  result = result + fill34(1)
  result = result + fill36(1)
  result = result + fill38(1)
  result = result + fill40(1)
  result = result + fill42(1)
  result = result + fill44(1)
  result = result + fill46(1)
  result = result + fill48(1)
