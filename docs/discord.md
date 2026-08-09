---
repo: aoughwl/discord
---

# discord — Discord bots for nimony, on the aoughwl net stack

A Discord bot client written in nimony, built on the aoughwl
[net stack](/docs/net-stack): the gateway rides `net → tls → ws`, the REST API
rides `net → tls → http`. No framework runtime and no exceptions — status-based
returns and `lastError` throughout, matching the rest of the stack.

```
gateway (wss)    net -> tls -> ws       receive events
rest    (https)  net -> tls -> http     act on them
```

> **Status** — In production use as the phone-side control surface for
> [aowlcode's fleet](/docs/aowlcode/fleet): DMs, slash commands with deferred
> follow-ups, button rows, typing indicators, and gateway resume after a drop.
> Roughly 950 lines across three files.

[[toc]]

---

## Quickstart

```nim
import discord

var bot = newBot(token)
if not bot.start(): echo bot.lastError

while true:
  var ev = newEvent()
  if bot.poll(500, ev):
    case ev.kind
    of evMessage:
      if not ev.isBot:
        discard bot.say(ev.channelId, "you said: " & ev.content)
    of evInteraction:
      discard bot.choose(ev, "recorded")        # within 3 seconds
      echo optionPrefix(ev.customId), " -> ", optionIndex(ev.customId)
    else: discard
```

`Bot` is one object and one loop. Reconnects, heartbeats and resumes happen
inside `poll` and never surface as an error the caller has to know how to
recover from, because there is exactly one correct recovery.

## Why the two halves are separate

Discord tells you about a button press **over the socket** and makes you answer
it **over HTTP**, within three seconds — or the user is shown "This interaction
failed" even when the work succeeded and was recorded correctly. The two
protocols are therefore both present and joined behind one type.

Slash commands have the same deadline, which is why `deferCommand` exists: a
command whose answer takes longer than three seconds has to say "thinking" on
the wire first, then post the real answer with `followUp`.

## Design notes

**One thread, no async runtime.** A gateway client must read events *and*
heartbeat every ~41s or the server drops it, which a blocking `receive` cannot
do. Rather than threads, the loop waits briefly for readability
(`net.waitReadable`), reads if there is something, and checks the heartbeat
clock either way — so the heartbeat is driven by wall time rather than by luck
about when a message arrives.

**TLS buffers, so `pending()` is checked first.** One TCP read can decrypt into
several WebSocket frames, and the socket is then *not* readable while a complete
message already sits in OpenSSL's buffer. Skipping that check produces a client
that lags by exactly one message, forever.

**The WebSocket owns the TLS socket.** `ws.close` closes the transport itself
and keeps its own copy of the `TlsSocket`, so closing both frees the same `SSL`
twice — a reliable SIGSEGV that fires *only* at shutdown or on a reconnect.

**Buttons carry an index, not a label.** `custom_id` is capped at 100 bytes, so
it encodes `<prefix>|<index>`, decoded by `optionPrefix` / `optionIndex`. If the
encoder and decoder ever disagreed, a press would silently resolve to the wrong
option — the worst available failure for a thing whose only job is "which one
did you pick" — so the round trip is pinned in the gate.

**`heartbeatInterval` starts at 0**, not at Discord's real 41250. A default
equal to the observed value would have made "did we actually parse a HELLO?"
untestable.

**Rate limits are honoured**: 429 with `retry_after`, plus 5xx backoff. A client
that ignores them gets its token temporarily banned.

## Intents, and what they keep out

`DefaultIntents` is `DIRECT_MESSAGES | MESSAGE_CONTENT`, and deliberately does
**not** include `GUILD_MESSAGES` — so a message in a server channel never
reaches the gateway at all. Adding the bot to a server does nothing.

For a bot that controls a machine, that is the design rather than a limitation:
a bot reachable from a server channel is a bot everyone in that server can drive.

**`MESSAGE_CONTENT` is privileged** and must also be ticked in the Developer
Portal. Without it every message arrives with an empty `content`, so the bot
looks broken rather than unauthorised.

Intents are not authentication, though. Pairing to a channel is a property of
*where* a message arrived, not *who* sent it, and a group DM has a channel id
like any other — so a caller that must answer to one person should check the
author's user id, which every event carries.

## API

| | |
|---|---|
| `newBot(token, intents = DefaultIntents)` | Construct. No I/O yet. |
| `start` / `stop` | Open and close the gateway. |
| `poll(timeoutMs, ev) -> bool` | One turn. Handles heartbeats, resumes, reconnects. |
| `say(channelId, text, options = @[], idPrefix = "")` | Send; with `options` it renders a button row. Returns the message id. |
| `choose(ev, note)` | Acknowledge a button press. **Within 3s.** |
| `deferCommand(ev)` / `followUp(appId, ev, text)` | "Thinking…", then the real answer. |
| `registerCommands(appId, cmds)` | Publish the slash-command list. `PUT` replaces the whole set. |
| `typing(channelId)` | "…is typing", for about ten seconds. Re-call while working. |
| `dmChannel(userId)` | Open (or fetch) the DM channel with one user. |
| `verifyToken -> string` | Prove the token over REST and return the bot's user id. |

`Event` carries `kind` (`evMessage`, `evInteraction`, `evCommand`, `evReady`,
`evClosed`), `channelId`, `userId`, `userName`, `content`, `customId`,
`commandName` / `commandArg`, `replyToId` and `isBot`.

### Verify the token before opening a socket

A bad token on the gateway is an opaque close code 4004, which is much harder to
act on than an HTTP 401. `verifyToken` does a REST call first and returns the
bot's own id.

Distinguish *rejected* from *unlucky* when it fails: only 401/403 means the
credential is actually wrong. A 503, a rate limit or a dropped connection is
transient, and treating one as fatal takes a bot offline until a human notices —
observed in the wild, with the resulting message blaming the token.

## The double-close had to be found by shrinking

The socket-ownership bug above is worth a note about *how* it was found, because
the answer at the time was "not with a debugger".

[`aowli`](/docs/aowli) could not run **any** net-stack program. `tcp/native.nim`
declares the POSIX socket constants as bodyless `{.importc.}` globals —
`SOL_SOCKET`, `SO_REUSEADDR`, `O_NONBLOCK` and the rest — and nothing seeded
them, so they hit the interpreter's unbound-importc refusal. A `debug_session`
on the gateway client died at `SOL_SOCKET` *before the program's first line*.

The refusal itself was correct, and that is the interesting part: a zero
`SOL_SOCKET` aims every `setsockopt` at the wrong level, and a zero `O_NONBLOCK`
silently leaves the socket **blocking**. Both of those fail far away from the
line that caused them, so answering with a plausible zero would have been much
worse than halting. The gap was never the refusal — it was that nothing supplied
the values.

That made a whole domain undebuggable at once: `net`, `tls`, `ws`, `http`,
`serve`, `requests` and every client built on them. So the double free was
narrowed by shrinking the program by hand instead, which is why it reads as a
shutdown-only SIGSEGV in the notes above — a bug that never fires in a quick
manual test and could not be stepped through either.

**This is now fixed.** aowli seeds the socket, fcntl and poll constant family
from the system headers, so net-stack programs are debuggable. The values are
taken by compiling a one-file C program that prints each macro on the host,
rather than from memory — several are counter-intuitive (`SO_KEEPALIVE` is 9,
`MSG_NOSIGNAL` is `0x4000`, `O_NONBLOCK` and `SOCK_NONBLOCK` are both 2048) —
and they are **Linux/glibc numbers**, pinned to this host. macOS and the BSDs
disagree loudly: `SOL_SOCKET` is `0xffff` there and `O_NONBLOCK` is 4. A port
means re-running the probe on that host, not editing the table by eye.

## Not using `requests`

[`requests`](/docs/net-stack/requests) was the obvious REST client — it is
libcurl underneath and its `RetryPolicy` already models 429 and `Retry-After`.
It does not currently compile under nimony, so REST is built on `tls` plus
`http`'s incremental response parser instead. This can switch back once it
builds.

## Gate

```bash
./build.sh              # compile the library
tests/run.sh            # unit + a live gateway probe (no credentials needed)
NO_NET=1 tests/run.sh   # unit only
```

Dependencies: [`aowljson`](/docs/aowljson), and `net` / `tcp` / `tls` / `ws` /
`http` from the [net stack](/docs/net-stack).
