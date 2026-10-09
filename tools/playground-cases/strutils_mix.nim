import std/[syncio, strutils]
echo "Hello".toUpperAscii, " ", "  x  ".strip, " ", "ab".repeat(3), " ", "hello".find('l'), " ", "a-b-c".replace("-", "+")
