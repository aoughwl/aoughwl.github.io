---
repo: aoughwl/openai
---

# openai — the OpenAI Chat Completions API in nimony

A typed client over
[Chat Completions](https://platform.openai.com/docs/api-reference/chat) — system
prompt, multi-turn messages, function/tool calling, token accounting — plus a
headless CLI (`openai -p "…"`) shaped like `codex -p`. Part of the
[LLM stack](/docs/llm-stack); its sibling is
[`anthropic`](/docs/llm-stack/anthropic), same shape against the Messages API.

> **Status** — Library + CLI in use. Non-streaming calls, tool-call round-trips
> and usage accounting are complete; `stream` yields the finished text as one
> event because the transport has no streaming POST yet (see
> [below](#streaming)). ~240 lines of library, ~110 of CLI. The Responses
> endpoint is not implemented — `chat` is the whole surface today.

[[toc]]

---

## Quickstart

```nim
import openai

let c = newOpenAI()                         # reads OPENAI_API_KEY

let r = c.chat("gpt-4.1-mini",
               @[system("You are terse."), user("What is 2+2?")])
if not r.ok:
  echo "error: ", r.error, " (status ", r.status, ")"
else:
  echo r.text
  echo r.usage.promptTokens, " in / ", r.usage.completionTokens, " out"
```

No exception path: `Reply.ok` is the only branch, and it covers transport
failure, a non-2xx status, an `error` object in the body, and an unparseable
body alike.

## The client

```nim
proc newOpenAI(apiKey = ""; baseUrl = ""; org = "";
               profile = "chrome136"; verifyTls = true;
               timeoutMs = 120000): OpenAI
```

Empty arguments fall back to `OPENAI_API_KEY` / `OPENAI_BASE_URL` and the
`DefaultBaseUrl` constant. Because `baseUrl` is a plain field, an
OpenAI-compatible endpoint — Azure, a gateway, a proxy, a local model server —
is a constructor argument rather than a code path. `profile`, `verifyTls` and
`timeoutMs` go straight to [`requests`](/docs/net-stack/requests), which opens
the connection.

## Calls

```nim
proc chat(c: OpenAI; model: string; msgs: seq[Message];
          tools: seq[Tool] = @[]; maxTokens = -1;
          temperature = -1.0): Reply

iterator stream(c: OpenAI; model: string; msgs: seq[Message];
                tools: seq[Tool] = @[]): StreamEvent
```

`maxTokens = -1` and `temperature = -1.0` mean "omit the field", so the API's
own defaults apply. The system prompt is a turn here (`system(...)`), not a
separate parameter — that is the one shape difference from the sibling library.

## Types

| type | what it is |
|------|-----------|
| `OpenAI` | the client: `apiKey`, `baseUrl`, `org`, `profile`, `verifyTls`, `timeoutMs` |
| `Message` | one turn: `role` (`system` / `user` / `assistant` / `tool`) + `content`, with `toolCallId` and an optional `name` |
| `Reply` | `ok`, `error`, `status`, `text`, `toolCalls`, `finishReason`, `usage`, `raw` |
| `ToolCall` | `id`, `name`, `arguments` — the raw JSON string, exactly as returned |
| `StreamEvent` | `evText` / `evToolCall` / `evDone` / `evError` |
| `Tool` | `name`, `description`, `schema` (JSON-schema for the function parameters) |
| `Usage` | `promptTokens`, `completionTokens` |

Builders — `system`, `user`, `assistant`, `toolResult`, `tool` — cover the
common shapes so no call site writes JSON by hand. `r.raw` keeps the original
body for debugging and accounting.

## Tool calling

```nim
let tools = @[tool("get_weather", "look up weather", schema = weatherSchema)]
let r = c.chat("gpt-4.1-mini", @[user("weather in Paris?")], tools = tools)

for call in r.toolCalls:
  let out = dispatch(call.name, call.arguments)     # your code
  let follow = c.chat("gpt-4.1-mini",
                      @[user("weather in Paris?"),
                        toolResult(call.id, out)])
  echo follow.text
```

`arguments` is deliberately left as the raw JSON string the API sends — parse it
with [`aowljson`](/docs/aowljson) if you want a value, or hand it straight to
something that expects JSON text. `finishReason` tells you whether the model
stopped because it wants a tool run.

## Streaming {#streaming}

`stream` exists and its signature is final, but it does not yet stream. It runs
one blocking `chat` call and yields the completed text as a single `evText`
followed by `evDone` (or a single `evError`). The cause is one layer down: the
nimony port of [`requests`](/docs/net-stack/requests) has no streaming-POST verb
— `download` is GET-only and there is no SSE frame assembler — so incremental
tokens cannot reach the client at all.

Code written against the iterator does not change when that lands:

```nim
for ev in c.stream("gpt-4.1-mini", @[user("count to 5")]):
  case ev.kind
  of evText: stdout.write ev.text
  of evError: echo "error: ", ev.error
  else: discard
```

## The CLI

```sh
openai -p "explain this diff" < patch.txt        # headless, prints the answer
openai -p "hello" --model gpt-4.1-mini           # pick a cheap model
openai -p -                                      # prompt from stdin
echo "summarize" | openai -p -
```

| flag | meaning |
|---|---|
| `-p`, `--print <prompt>` | the prompt; `-` reads stdin. A bare first argument works too |
| `-m`, `--model <name>` | model (default `$OPENAI_MODEL`, else `DefaultModel`) |
| `-s`, `--system <text>` | system prompt |
| `--max-tokens <n>` | max output tokens (omitted by default) |
| `--stream` | stream the answer (see the caveat above) |
| `-h`, `--help` | usage |

Exit status is `1` on an API or transport error (message on stdout), `2` on a
usage error. On success stdout carries the model's text and nothing else —
which is what makes it drop-in for an agent shelling out to a provider.

## Config

| env | meaning |
|-----|---------|
| `OPENAI_API_KEY` | credential (required unless passed to `newOpenAI`) |
| `OPENAI_BASE_URL` | override the endpoint (Azure, proxies, gateways, local models) |
| `OPENAI_MODEL` | default model for the CLI when `--model` is omitted |

## Build

```sh
./build.sh          # builds bin/openai
```

Deps resolve by path: `$AOWLJSON/src` and the **nimony port** of requests at
`$AOWL_REQUESTS/nimony` (not `src/`, which is the Nim 2 original), plus the
curl-impersonate library directory passed as `-L` and `-rpath`. `build.sh`
encodes all of it.

MIT — [aoughwl/openai](https://github.com/aoughwl/openai).
