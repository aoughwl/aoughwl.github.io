## Example: Press To Spawn
##
## A catalog is how a mod publishes what can be spawned. This one is filled by
## this mod alone, but any other mod may add rows to it by name, and every row
## remembers which mod contributed it. That is the whole extension model.
##
## The aoughwl.parts dependency in mod.json is what makes the
## "aoughwl.part" catalog kind exist. Without it createCatalog throws
## "Unknown collection type" and start() never finishes.

import jester
import entities
import input      # the Key enum: pressed(E)
import vec        # Vec3, spawnPart(at: Vec3)
import color

const Parts = "example.press.parts"

var
  eye: Entity
  dropped = 0

proc start() =
  let ground = shape(Plane, "Ground")
  ground.scale(vec3(4.0, 1.0, 4.0))
  ground.color(rgb(0.24, 0.30, 0.22))

  eye = camera("Eye")
  eye.position(vec3(0.0, 3.0, -6.0))
  eye.rotation(vec3(15.0, 0.0, 0.0))

  createCatalog(Parts, "aoughwl.part", "Things example.press can drop")
  addToCatalog(Parts, "ball", "builtin://sphere")
  addToCatalog(Parts, "box", "builtin://cube")

  log("example.press: E drops a ball, R drops a box")

proc drop(item: string) =
  let thing = spawnPart(Parts, item, vec3(0.0, 6.0, 0.0))
  thing.physics(1.0)
  dropped = dropped + 1
  log("dropped " & item & " (" & $dropped & " so far)")

proc update() =
  if pressed(E): drop("ball")
  if pressed(R): drop("box")
