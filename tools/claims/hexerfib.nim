import std/syncio

proc fib(n: int): int =
  if n < 2: n else: fib(n - 1) + fib(n - 2)

proc ack(m, n: int): int =
  if m == 0: n + 1
  elif n == 0: ack(m - 1, 1)
  else: ack(m - 1, ack(m, n - 1))

echo "fib(20)=", fib(20)
echo "ack(3,4)=", ack(3, 4)
echo "fib(25)=", fib(25)
