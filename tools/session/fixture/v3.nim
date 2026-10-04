var counter = 0

proc tick(n: int): int =
  counter = counter + n
  result = counter
