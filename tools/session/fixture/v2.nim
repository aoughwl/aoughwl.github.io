var counter = 0

proc tick(): int =
  counter = counter + 1
  result = counter * 100
