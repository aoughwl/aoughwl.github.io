---
repo: aoughwl/aowlmcp
---

# aowlmcp — Model Context Protocol servers in Nimony

> ▶️ **[Try it live in the Playground](https://aoughwl.github.io/playground/)** — write and run `.nim` / `.aowl` in your browser, no install.

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

So `aowlmcp` builds on two pieces:

1. **[aowljson](/docs/aowljson)** — a plain reference `JsonValue` tree with a
   recursive-descent parser, a compact serializer, and safe nested access. It
   fills the one real gap (Nimony's own `std/json` is NIF-backed, move-only, and
   only indexes the document root) and lives in its own repo so any project can
   depend on it. `aowlmcp` imports and re-exports it.
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

Provided by [aowljson](/docs/aowljson) (re-exported from `aowlmcp`), so tool code
reads cleanly:

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
| `server/discover` | **(2026-07-28)** Advertises `protocolVersions`, `capabilities` (incl. the `extensions` map), `serverInfo`. Doubles as the stdio back-compat probe. |
| `initialize` | **(legacy 2024-11-05)** Negotiates `protocolVersion` from the client's request, else the legacy version; returns `capabilities`, `serverInfo`. |
| `notifications/initialized` / `initialized` | Acknowledged with no response. |
| `ping` | Empty result. |
| `tools/list` | Every registered tool with its `name`, `description`, `inputSchema`; plus `ttlMs` + `cacheScope` caching hints (2026-07-28). |
| `tools/call` | Dispatches to the handler; wraps the result as a text content block. Can return an `InputRequiredResult` (MRTR) or a task handle (Tasks). |
| `tasks/get` / `tasks/cancel` / `tasks/update` | **(2026-07-28 Tasks extension)** Drive a task handle returned by `tools/call`. |
| batch arrays | Each sub-request dispatched; one response line per non-notification. |
| bad JSON | `-32700` parse error (`id: null`). |
| unknown method (with `id`) | `-32601` method not found. |
| unsupported `_meta` protocol version | `-32602` invalid params. |

Tool-level errors ride back as `isError: true` **responses**, not JSON-RPC
errors — JSON-RPC `error` objects are reserved for transport and method faults.
This is the MCP convention, and it matches the reference Python server the
aowlcode plugin ships.

---

## Two protocol versions: 2024-11-05 and 2026-07-28

The **2026-07-28 revision** is the largest change to MCP since launch: it breaks
with MCP's stateful past. `aowlmcp` speaks **both** the legacy and the new
protocol, negotiated per request, so upgrading a client is never a flag day.

**What changed in 2026-07-28**

- **Stateless core.** The `initialize` / `notifications/initialized` handshake and
  the `Mcp-Session-Id` header are gone. Any server instance can serve any
  request. Instead of a handshake, every request carries its context in `_meta`
  (inside `params`):
  - `io.modelcontextprotocol/protocolVersion`
  - `io.modelcontextprotocol/clientInfo`
  - `io.modelcontextprotocol/clientCapabilities`
- **`server/discover`** replaces `initialize` for capability discovery.
- **Streamable-HTTP routing headers** `Mcp-Method` / `Mcp-Name` let load
  balancers route without inspecting the body. A single-instance aowlmcp server
  accepts and ignores them (the method/name come from the JSON-RPC body).
- **Caching hints** `ttlMs` + `cacheScope` on list responses.
- **MRTR** (Multi-Round-Trip Requests) replaces mid-call server→client requests:
  a tool returns an `InputRequiredResult`, the client re-calls with responses.
- **Tasks** and **MCP Apps** move to negotiated `extensions`.
- **Roots / Sampling / Logging** are deprecated (aowlmcp never shipped them; on
  stdio, log to `stderr`).

**How aowlmcp negotiates.** When a request's `_meta` names a version we don't
support, it's rejected with `-32602`. Requests without `_meta` are treated as
legacy (2024-11-05) and work unchanged. `server/discover` advertises both
versions; the legacy `initialize` still works for old clients.

### Multi-Round-Trip tools (MRTR)

Register with `registerToolMRTR`; the handler receives `inputResponses` and the
echoed `requestState`, and returns `newInputRequired(...)` to ask for input:

```nim
proc deleteFiles(args, inputResponses, requestState: JsonValue): JsonValue =
  if inputResponses.kind != jnObject:           # first call → ask
    let requests = newJObject()
    requests["confirm"] = newJObject()          # {type:"elicitation", …}
    return newInputRequired(requests, $args{"count"}.getInt(0))
  result = newJObject()                          # follow-up → complete
  result["message"] = newJString(
    if inputResponses{"confirm"}.getBool(false): "deleted" else: "cancelled")

srv.registerToolMRTR("delete_files", "…", schema, deleteFiles)
```

### Task tools (Tasks extension)

Register with `registerTaskTool`; `tools/call` returns a `{taskId, status}`
handle and the result is fetched via `tasks/get`. The extension is advertised in
`server/discover` only when a task tool is registered:

```nim
srv.registerTaskTool("slow_sum", "…", schema, slowSum)
```

See `examples/mrtr_server.nim` for both, end to end.

---

## Transports: stdio, HTTP, and HTTP/3

The protocol dispatch is transport-agnostic — one `handleMessage(srv, text)`
turns an incoming JSON-RPC message into the reply text — so aowlmcp offers three
transports over the same server and tools:

- **stdio** — `srv.run()`. Line-delimited JSON-RPC on stdin/stdout, for local
  clients (Claude Code, editors). No networking dependency; `import aowlmcp`
  alone pulls nothing from the net stack.
- **HTTP** — `import aowlmcp/http`; `srv.serveHttp(port)` (or `serveHttpAsync`
  on the single-thread reactor). The modern MCP **Streamable-HTTP** transport,
  for *remote* clients: a client POSTs a JSON-RPC message to `/mcp` and receives
  the response as `application/json` (a notification gets `202`, an unknown path
  `404`). It is served over the [aoughwl net stack](/docs/net-stack) and is
  **opt-in**, so stdio-only servers stay dependency-free.
- **HTTP/3 (QUIC)** — `import aowlmcp/h3`; `srv.serveH3(port, cert, key)`. The
  same Streamable-HTTP contract carried over QUIC/TLS-1.3 on the net stack's
  single-thread [HTTP/3 reactor](/docs/net-stack/reactor). Requires the
  ngtcp2/nghttp3/GnuTLS glue shim and a PEM cert/key. Verified e2e (initialize +
  tools/list + tools/call over QUIC, one thread).

```nim
import aowlmcp
import aowlmcp/http          # opt-in network transport

let srv = newServer("aowlmcp-http", "0.1.0")
srv.registerTool("greet", "Greet someone.", schema, greet)
srv.serveHttp(8130)          # POST JSON-RPC to http://host:8130/mcp
```

```sh
curl -s localhost:8130/mcp -d '{"jsonrpc":"2.0","id":1,"method":"tools/list"}'
```

The same `Server` and the same registered tools work under any transport — you
pick `run()`, `serveHttp()`, or `serveH3()` at the edge. Server-initiated SSE
streaming is intentionally omitted (a pure tools server never pushes); a `GET`
returns 405.

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
src/aowlmcp.nim          umbrella module (import this); re-exports aowljson
src/aowlmcp/server.nim   Server: registry, JSON-RPC dispatch, handleMessage, stdio run
src/aowlmcp/http.nim     opt-in HTTP (Streamable-HTTP) transport over the net stack
src/aowlmcp/h3.nim       opt-in HTTP/3 (QUIC) transport over the net stack's H3 reactor
examples/                echo_server, http_server, nimtools_server
tests/e2e.sh             stdio: build + drive servers, assert on responses
tests/http_e2e.sh        HTTP: build http_server + drive it with curl
```

The `JsonValue` type comes from the [aowljson](/docs/aowljson) dependency; the
HTTP transport additionally depends on the [net stack](/docs/net-stack).
