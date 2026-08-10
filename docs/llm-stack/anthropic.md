---
repo: aoughwl/anthropic
---

# anthropic — the Anthropic Messages API in nimony

A typed client over the [Messages API](https://docs.anthropic.com/en/api/messages)
— system prompt, multi-turn messages, tool use, token accounting — plus a
headless CLI (`anthropic -p "…"`) shaped like `claude -p`. Part of the
[LLM stack](/docs/llm-stack); its sibling is
[`openai`](/docs/llm-stack/openai).

> **Status** — Library + CLI in use. Non-streaming calls, tool-use round-trips
> and usage accounting are complete; `stream` yields the finished text as one
> event because the transport has no streaming POST yet (see
> [below](#streaming)). ~270 lines of library, ~110 of CLI.

[[toc]]

---

## Quickstart

```nim
import anthropic

let c = newAnthropic()                      # reads ANTHROPIC_API_KEY

let r = c.messages("claude-haiku-4-5", @[user("What is 2+2?")],
                   system = "You are terse.")
if not r.ok:
  echo "error: ", r.error, " (status ", r.status, ")"
else:
  echo r.text
  echo r.usage.inputTokens, " in / ", r.usage.outputTokens, " out"
```

There is no exception path. `Reply.ok` is the only branch that matters, and it
covers transport failure, a non-2xx status, and an unparseable body alike.

## The client

```nim
proc newAnthropic(apiKey = ""; baseUrl = ""; version = "";
                  profile = "chrome136"; verifyTls = true;
                  timeoutMs = 120000): Anthropic
```

Empty arguments fall back to `ANTHROPIC_API_KEY` / `ANTHROPIC_BASE_URL` and the
`DefaultBaseUrl` / `DefaultVersion` constants. `profile`, `verifyTls` and
`timeoutMs` are handed straight to [`requests`](/docs/net-stack/requests), which
is what actually opens the connection — so pointing the client at a gateway or a
proxy is one argument, not a fork in the code.

## Calls

```nim
proc messages(c: Anthropic; model: string; msgs: seq[Message];
              system = ""; maxTokens = 1024;
              tools: seq[Tool] = @[]; temperature = -1.0): Reply

iterator stream(c: Anthropic; model: string; msgs: seq[Message];
                system = ""; maxTokens = 1024;
                tools: seq[Tool] = @[]): StreamEvent
```

`temperature = -1.0` means "omit the field" — the API's own default applies.
The system prompt is a parameter rather than a turn, matching the wire format.

Multi-turn is just a longer `seq`:

```nim
var turns = @[user("hi"), assistant("hello!"), user("who are you?")]
echo c.messages("claude-haiku-4-5", turns).text
```

## Types

| type | what it is |
|------|-----------|
| `Anthropic` | the client: `apiKey`, `baseUrl`, `version`, `profile`, `verifyTls`, `timeoutMs` |
| `Message` | one turn: `role` (`user` / `assistant`) + `content: seq[ContentBlock]` |
| `ContentBlock` | `cbText` / `cbToolUse` / `cbToolResult` / `cbImage` |
| `Reply` | `ok`, `error`, `status`, `content`, `stopReason`, `usage`, `raw`, and a `.text` helper |
| `StreamEvent` | `evText` / `evToolUse` / `evDone` / `evError` |
| `Tool` | `name`, `description`, `schema` (a JSON-schema object) |
| `Usage` | `inputTokens`, `outputTokens` |

Builders — `user`, `assistant`, `toolResult`, `textBlock`, `tool` — cover the
common shapes so no call site writes JSON by hand. `r.raw` keeps the original
response body for debugging and for accounting against something other than
`usage`.

## Tool use

```nim
let tools = @[tool("get_weather", "look up weather", schema = weatherSchema)]
let r = c.messages("claude-haiku-4-5", @[user("weather in Paris?")], tools = tools)

for b in r.content:
  if b.kind == cbToolUse:
    let out = dispatch(b.toolName, b.toolInput)      # your code
    let follow = c.messages("claude-haiku-4-5",
                            @[user("weather in Paris?"),
                              toolResult(b.toolId, out)])
    echo follow.text
```

`toolInput` is an `aowljson` value, and `toolResult(toolId, content, isError =
false)` builds the turn that answers a call — including the error case, which
the API wants reported as a result rather than as a dropped turn.

## Streaming {#streaming}

`stream` exists and its signature is final, but it does not yet stream. It runs
one blocking `messages` call and yields the completed content as `evText`
blocks followed by `evDone` (or a single `evError`). The reason is one layer
down: the nimony port of [`requests`](/docs/net-stack/requests) has no
streaming-POST verb — `download` is GET-only and there is no SSE frame
assembler — so incremental tokens cannot reach the client at all.

Written against the iterator, your code does not change when that lands:

```nim
for ev in c.stream("claude-haiku-4-5", @[user("count to 5")]):
  case ev.kind
  of evText: stdout.write ev.text
  of evError: echo "error: ", ev.error
  else: discard
```

## The CLI

```sh
anthropic -p "explain this diff" < patch.txt      # headless, prints the answer
anthropic -p "hello" --model claude-haiku-4-5     # pick a cheap model
anthropic -p -                                    # prompt from stdin
echo "summarize" | anthropic -p -
```

| flag | meaning |
|---|---|
| `-p`, `--print <prompt>` | the prompt; `-` reads stdin. A bare first argument works too |
| `-m`, `--model <name>` | model (default `$ANTHROPIC_MODEL`, else `DefaultModel`) |
| `-s`, `--system <text>` | system prompt |
| `--max-tokens <n>` | max output tokens (default 1024) |
| `--stream` | stream the answer (see the caveat above) |
| `-h`, `--help` | usage |

Exit status is `1` on an API or transport error (with the message on stdout),
`2` on a usage error. Nothing but the model's text goes to stdout on success —
that is the property the agent depends on when it shells out to a provider.

## Config

| env | meaning |
|-----|---------|
| `ANTHROPIC_API_KEY` | credential (required unless passed to `newAnthropic`) |
| `ANTHROPIC_BASE_URL` | override the endpoint (proxies, gateways) |
| `ANTHROPIC_MODEL` | default model for the CLI when `--model` is omitted |

## Build

```sh
./build.sh          # builds bin/anthropic
```

Deps resolve by path: `$AOWLJSON/src` and the **nimony port** of requests at
`$AOWL_REQUESTS/nimony` (not `src/`, which is the Nim 2 original), plus the
curl-impersonate library directory passed as `-L` and `-rpath`. `build.sh`
encodes all of it.

MIT — [aoughwl/anthropic](https://github.com/aoughwl/anthropic).
