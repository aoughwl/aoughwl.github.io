# The LLM stack

Two nimony clients for the two model APIs the aoughwl agent talks to —
[`anthropic`](/docs/llm-stack/anthropic) (Messages API) and
[`openai`](/docs/llm-stack/openai) (Chat Completions). Same shape in both:
**a library** you `import`, and **a headless `-p` CLI** in the spirit of
`claude -p` / `codex -p`.

Common stance, matching the rest of the stack: nimony-native, no framework
runtime, **error-as-value instead of exceptions** — every call returns a `Reply`
with `ok` / `error` / `status`, so a malformed body or a 429 is data, never a
stray raise.

---

## How it layers

```
anthropic  (Messages API)      openai  (Chat Completions)
   │  library: messages/stream    │  library: chat/stream
   │  CLI:     anthropic -p       │  CLI:     openai -p
   └──────────────┬───────────────┘
                  ├── aowljson    (parse + build request/response JSON)
                  └── requests    (HTTPS via curl-impersonate; TLS profile)
```

Neither library opens a socket itself: both post through
[`requests`](/docs/net-stack/requests), so they inherit its browser-identical
TLS fingerprint (`profile = "chrome136"` by default), its timeouts, and its
never-raises contract. JSON in and out goes through
[`aowljson`](/docs/aowljson).

---

## Libraries

| Library | What it is | Repo |
|---|---|---|
| [anthropic](/docs/llm-stack/anthropic) | Anthropic Messages API client + `anthropic -p` CLI | [aoughwl/anthropic](https://github.com/aoughwl/anthropic) |
| [openai](/docs/llm-stack/openai) | OpenAI Chat Completions client + `openai -p` CLI | [aoughwl/openai](https://github.com/aoughwl/openai) |

Both are small — roughly 250 lines of library plus a 100-line CLI each — because
the wire format is the whole job and `requests` / `aowljson` do the rest.

---

## Why they exist

They are the front ends the substrate-native coding agent
([`aoughwl/code`](https://github.com/aoughwl/code), the `aowlcode` command) uses
when it needs a model to **propose meaning**. The agent's own actions are
substrate queries; a model is consulted, never trusted to write files. Because
the CLI is `-p`-shaped, the agent can equally drive an external `claude -p` or
`codex -p` binary — the four provider choices in `aowlcode login` are the two
libraries here plus those two external agents.

---

## Shared shape

Everything below is true of both repos.

**Client construction** reads the key from the environment unless you pass one:

```nim
let c = newAnthropic()      # ANTHROPIC_API_KEY, ANTHROPIC_BASE_URL
let o = newOpenAI()         # OPENAI_API_KEY,    OPENAI_BASE_URL
```

Both constructors also take `baseUrl`, `profile`, `verifyTls` and `timeoutMs`
(default 120 s), so a proxy, a gateway, or a local OpenAI-compatible server is a
one-argument change.

**Message helpers** build the common turn shapes without hand-written JSON:
`user(...)`, `assistant(...)`, `toolResult(...)`, `tool(...)` — plus
`system(...)` in `openai` (Anthropic takes the system prompt as its own
parameter rather than a turn).

**Replies are values.** Check `r.ok` first; on failure `r.error` explains and
`r.status` carries the HTTP code (`0` means the request never made it out).
`r.raw` keeps the original body for debugging and accounting, and `r.usage`
carries the token counts the agent bills against.

**Tool use round-trips** in both: define a `Tool` with a JSON-schema input, read
the model's call off the reply, dispatch it yourself, and feed a `toolResult`
back as the next turn.

::: warning Streaming is an API, not yet a behaviour
Both libraries expose a `stream` iterator, and both currently perform **one
blocking request** and then yield the finished text as a single `evText` event
followed by `evDone`. The cause is one level down: the nimony port of
[`requests`](/docs/net-stack/requests) has no streaming-POST verb — its only
byte-callback sink, `download`, is GET-only, and there is no SSE frame
assembler. Token-by-token streaming is therefore blocked at the transport, not
in these clients.

The iterator signature is the one real streaming will use, so code written
against `stream` today keeps working unchanged when `requests` grows a
POST-with-callback verb and an SSE parser.
:::

---

## Build

nimony has no package manager; dependencies resolve by path. Each repo's
`build.sh` encodes the two it needs:

```sh
./build.sh          # builds bin/anthropic (or bin/openai)
# under the hood:
#   nimony c --path:$AOWLJSON/src --path:$AOWL_REQUESTS/nimony \
#            --passl:-L<requests>/vendor/curl-impersonate/lib \
#            --passl:-Wl,-rpath,<same> \
#            -o:bin/anthropic bin/anthropic.nim
```

`build.sh` finds [`aowljson`](https://github.com/aoughwl/aowljson) and
[`requests`](https://github.com/aoughwl/requests) next to the checkout or via
`$AOWLJSON` / `$AOWL_REQUESTS`. Note that `requests` must be its **nimony** port
(the `nimony/` subdirectory — `src/` is the Nim 2 original), and that
curl-impersonate needs its vendored library directory passed to the linker; the
scripts handle both.

Both repos are MIT-licensed.
