## A sibling module, so the main module's symbols are resolved the way a real
## mod's are — through the loader and the sidecar index — rather than out of the
## tree the interpreter is already walking.
proc depAdd*(a, b: int): int = a + b
