## The library mod itself. It reaches its own exported module by the same
## namespaced path its consumers use, which is what keeps the two builds
## agreeing about which module this is.

import jester
import example_counter/counter

proc start() =
  discard bump(3)

proc counterTotal(): int = counted()
