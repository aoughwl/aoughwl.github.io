---
repo: aoughwl/aowlmcp
---

# aowlmcp — Model Context Protocol servers in Nimony

`aowlmcp` lets you expose Nimony procedures as LLM-callable tools. It implements
the [Model Context Protocol](https://modelcontextprotocol.io) (MCP) stdio
transport — line-delimited JSON-RPC 2.0 — so any MCP client (Claude Code, Claude
Desktop, editor agents) can call into a server you write in a handful of lines
of Nimony.

It is a **library**, not a framework: no runtime, no C dependencies, and — in
keeping with the rest of the stack — **errors are values, never exceptions
across the wire**. The only thing beneath it is Nimony's standard library.

[[toc]]

---

## Why this exists

MCP is often mistaken for a language capability. It is not: it is JSON-RPC 2.0
with a small fixed method vocabulary — `initialize`, `tools/list`, `tools/call`,
`ping`. Nimony already had the pieces to speak it (`std/syncio` for stdio,
`std/strutils`, `std/tables`) — everything except an ergonomic JSON value type.

So `aowlmcp` is two things:

1. **`aowlmcp/json`** — a plain reference `JsonValue` tree with a
   recursive-descent parser, a compact serializer, and safe nested access. This
   fills the one real gap: Nimony's own `std/json` is NIF-backed, move-only, and
   only indexes the document root, which is awkward to thread through a
   tool-handler API.
2. **`aowlmcp/server`** — the JSON-RPC + MCP loop over stdio: a tool registry,
   method dispatch, and the read-parse-dispatch-write cycle.

The point: **write an MCP tool without leaving Nimony.**

---

## Hello, tool

```nim
import aowlmcp

proc greet(args: JsonValue): JsonValue =
  let who = args{"name"}.getStr("world")
  result = newJObject()
  result["greeting"] = newJString("hello " & who)

let srv = newServer("my-server", "0.1.0")
srv.registerTool("greet", "Greet someone by name.",
  """{"type":"object","properties":{"name":{"type":"string"}},"required":["name"]}""",
  greet)
srv.run()
```

`srv.run()` reads one JSON request per line from stdin, dispatches it, and writes
one JSON response per line to stdout, flushing after each — exactly the MCP stdio
contract. A handler receives the call's `arguments` object as a `JsonValue` and
returns a structured `JsonValue`; the library encodes that as the MCP text
content block. Return an object carrying an `"error"` key to signal a tool-level
failure — the response comes back with `isError: true`.

Build and run:

```sh
git clone https://github.com/aoughwl/aowlmcp
cd aowlmcp
./build.sh examples/echo_server.nim   # → bin/echo_server
./tests/e2e.sh                        # unit + end-to-end tests
```

---

## The JSON value type

`aowlmcp/json` deliberately owns its own value type so tool code reads cleanly:

| Verb | API |
|---|---|
| parse | `parseJson(s, err): JsonValue` — error returned by value, never raised |
| serialize | `$v` — compact; numbers round-trip by lexeme, so any input re-emits faithfully |
| navigate | `v{"key"}` (object), `v.at(i)` (array) — missing paths chain to a JNull |
| read | `getStr`, `getInt`, `getBool`, `len`, `hasKey`, `items`, `pairs` |
| build | `newJObject`, `newJArray`, `newJString`, `newJInt`, `newJBool`, `newJNull`, `obj["k"] = v`, `arr.add v` |

Because a missing path yields a JNull rather than faulting,
`req{"params"}{"name"}.getStr("")` is always safe — no guards, no nil checks.

---

## Protocol coverage

| Method | Behaviour |
|---|---|
| `initialize` | Returns `protocolVersion` `2024-11-05`, `capabilities.tools`, `serverInfo`. |
| `notifications/initialized` / `initialized` | Acknowledged with no response. |
| `ping` | Empty result. |
| `tools/list` | Every registered tool with its `name`, `description`, `inputSchema`. |
| `tools/call` | Dispatches to the handler; wraps the result as a text content block. |
| batch arrays | Each sub-request dispatched; one response line per non-notification. |
| bad JSON | `-32700` parse error (`id: null`). |
| unknown method (with `id`) | `-32601` method not found. |

Tool-level errors ride back as `isError: true` **responses**, not JSON-RPC
errors — JSON-RPC `error` objects are reserved for transport and method faults.
This is the MCP convention, and it matches the reference Python server the
aowlcode plugin ships.

---

## A real toolchain server

`examples/nimtools_server.nim` is the nimony-native cousin of the aowlcode
plugin's Python `server.py` — token-efficient, structured toolchain access over
MCP:

- **`compile(file, toolchain="nimony", extra_args=[])`** — runs the compiler via
  `execCmdEx` and parses `path(line, col) Severity: message` lines into structured
  diagnostics. Because `nimony c` can exit `0` on failure, any `Error:` line marks
  the build as failed.
- **`nif_outline(file)`** — reads a NIF artifact and walks its S-expression to
  list the top-level `(tag name …)` nodes — no subprocess, pure Nimony.

A `tools/call` to `compile` on a broken file returns, verbatim:

```json
{"ok":false,"toolchain":"nimony",
 "diagnostics":[{"file":"bad.nim","line":1,"col":6,
   "severity":"error","message":"undeclared identifier: undefinedThing123"}]}
```

---

## Using it from Claude Code

The [aowlcode](/docs/aowlcode) plugin registers the nimony-native server
alongside its Python one in `.mcp.json`:

```json
"nimtools": {
  "command": "bash",
  "args": ["${CLAUDE_PLUGIN_ROOT}/mcp/nimtools_launch.sh"]
}
```

The launcher locates the `aowlmcp` checkout, builds `bin/nimtools_server` on
first use, and execs it — so the `compile` and `nif_outline` tools appear in
Claude Code with no manual build step. This is the stack dogfooding itself: a
Nimony program, compiled by Nimony, serving tools *about* Nimony to an LLM agent.

---

## Layout

```
src/aowlmcp.nim          umbrella module (import this)
src/aowlmcp/json.nim     JsonValue: parser, serializer, accessors, builders
src/aowlmcp/server.nim   Server: registry, JSON-RPC dispatch, stdio run loop
examples/                echo_server, nimtools_server
tests/tjson.nim          JSON unit tests
tests/e2e.sh             build + drive servers over stdio, assert on responses
```
