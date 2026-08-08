---
repo: aoughwl/aowlcode
---

# Fleet — running Claude Code sessions from a phone

Several Claude Code sessions work overnight on different repos. This is the half
that keeps them alive and the half that lets you steer them from a phone,
without the phone becoming a firehose.

Four problems, four pieces, each usable with the others turned off.

| problem | piece |
|---|---|
| a session told "never stop" stops anyway | Stop hook |
| a session **dies** and nobody notices for days | `fleetd`, the supervisor |
| something needs a human and the human is asleep | the bridge + `aowl-attn` |
| a rebuilt MCP server needs `/plugin-reload` | the relay |

[[toc]]

---

## The message bus is the substrate

Everything rides a maildir on disk. One label is reserved — `user`, the human's
inbox — and anything that needs a person goes there; the bridge is simply the
thing holding that label with a phone attached.

That buys the property that matters at 3am: **when the bridge is down, nothing
is lost.** Items queue on disk and are delivered when it comes back. A
socket-based design would have had to invent that, and it is what makes the
self-repair below safe.

Two transports, [Telegram or Discord](/docs/discord), chosen by one config key.
The bus, the filter, the pairing, the button routing and the digest are
identical either way — only the wire differs.

## The filter is the whole point

Only `question`, `blocked`, `risky`, `failed` and `notice` reach the phone.
Everything else accumulates in a digest you pull on demand.

That list lives in the **sender**, not in the bridge, because "this needs a
human" is a judgement made where the work is, not a formatting decision made at
the edge. The failure being designed against is not missing an alert — it is
sending so many that the channel gets muted, after which the one that mattered
is missed too.

## Projects

A **project** is one repo the fleet looks after and one Claude Code session on
it. There are three things a project can be, and the design is in the difference
between them.

| | |
|---|---|
| 💤 **idle** | its session clears the inbox and then waits. The default. |
| ♾️ **working** | it works without stopping. Inbox first, always. |
| 🔗 **attached** | a session **you** started. Read only: never spawned, nudged or killed. |

**Adding is not starting.** A session working on its own initiative costs tokens
every minute and only some of those minutes were asked for, so working is a
separate, deliberate verb. An idle session comes up, empties whatever is queued
for its label, says what it cleared, and ends its turn.

**Idle costs nothing and still answers.** Ending the turn is the correct outcome
for a session whose job is to wait, so the supervisor lets it *sleep* rather than
respawning it — a respawn loop would start a session every fifteen seconds all
night, and every view would call that healthy. What wakes it is exactly what it
is waiting for: a message queued for its label.

**The inbox comes first in both states.** A message interrupts standing work,
gets done, and then the standing goal resumes. Nothing about "work without
stopping" outranks something a human actually asked for.

**Nothing comes up working after a reboot.** The project *list* survives — those
are the repos the fleet looks after, and re-typing them every reboot is a chore
with nothing behind it. "Keep working on this without stopping" does not: that is
a decision made for an afternoon, and a machine that resumes it silently is
spending on yesterday's intent, invisibly, because a config that was already
right is the one thing nobody re-reads. The single exception is a project whose
process is **still alive** — the supervisor's children are orphaned rather than
killed when it dies, so a crash-restart five seconds later would otherwise
abandon a live session to keep editing a checkout nobody is watching.

**A working project is never re-briefed.** Asking for one that is already working
reports how long it has been up and names where direction goes instead: a running
session holds a context that a second briefing fights with.

**It compacts itself** every two hours. Automatic compaction handles the context
window; this handles the other half — hours of transcript about work that landed
and was pushed long ago.

Everything the fleet spawns runs **Opus at medium effort**, stated in the
supervisor rather than left to whatever the CLI defaults to that week: a session
working unattended for hours is a property of the fleet, not of the machine's
current settings.

## Attaching to a session you are already running

One command adopts a Claude Code session started by hand, in a terminal the human
keeps watching. Nothing is spawned, nudged, goaled or killed — the fleet only
reads.

That is possible because there is nothing to attach *to*. Claude Code already
writes every turn of every session to `~/.claude/projects/<cwd>/<id>.jsonl`, in
the same record shape a supervised worker's redirected stdout has, so the log and
subscription views work against it unchanged. No tty, no terminal multiplexer, no
interference with what is on the screen.

The transcript path is re-resolved every tick rather than pinned, because quitting
and restarting a session produces a new file — and a pinned path would freeze the
log view on a session that ended hours ago while looking exactly like a quiet one.

Attaching over a project the fleet is running is **refused**. Two sessions editing
one checkout is the failure this whole system exists to avoid, and that is the
moment it would happen.

## Commands, not conversation

Every verb is a registered slash command, so the list the client offers as you
type is the whole surface. A message that is not one gets a single line saying so.

There was a concierge — a session on the other end of the DM that answered
anything typed at it, in prose, and could plan and create new repos. It was
removed. What it mostly produced was a confident paragraph about work nobody had
started, and each one cost a session turn to write. The gate asserts the negative
directly: a plain message must spawn **nothing**.

Project names are resolved rather than matched literally, so a phrase finds the
right checkout. An **ambiguous** name resolves to nothing and lists the
candidates, because guessing between two repos puts a session on the wrong one.

## Subscriptions

A live view of one project, at a volume you choose. The dial is the design, not
a convenience: a session emits several tool calls a second, so the failure mode
of a naive "stream it to me" is a muted channel — the same failure the filter
above exists to prevent, arriving by a different road.

| | forwards |
|---|---|
| `quiet` | what the session **says**, and anything that **failed** |
| `normal` | + its tool calls, runs of one tool collapsed to a line and a count |
| `loud` | every call, uncollapsed |

A failed call is news at **every** level including `quiet`, which is what makes
`quiet` usable overnight. Batched, never per-event: everything new goes out as
one message, at most one per 20s per project.

Subscribing starts from the **end** of the log, and the read position only ever
advances to the last complete line — a record still being written cannot be
parsed, and re-reading it next tick is free where advancing past it would drop
it.

## Repairing itself, with a way back

The fleet can be told what is wrong with it and fix itself. The hazard is
obvious: the thing being rebuilt is the thing that would have to report the
failure, so a bad build takes down the only channel that could tell you, and
nobody is at the machine.

The sequence is **build → gate → restart → watch it come up → promote or
revert**, and three properties make it safe to run unattended:

- **The rollback logic is never rebuilt.** It is a shell script, outside what
  the repair loop compiles. A rollback living inside the binary being replaced
  stops existing exactly when it is needed.
- **The known-good copy is promoted only after the new binaries have actually
  run and produced heartbeats.** "It compiled" and "the gate passed" are not the
  same claim as "it comes up".
- **The report survives the bridge being down**, because it is written to the
  maildir. A failure raised while the bot is dead is delivered when it returns.

A build failure changes nothing and restarts nothing. A red gate discards the
new binaries. A build that passes everything and then fails to come up is
reverted, and you are told which of those three happened.

## Never stopping

A standing goal is advice, and advice does not survive a compaction. The goal is
written where the **Stop hook** reads it; when the session tries to end a turn
the hook blocks and hands the goal back.

Two bounds stop that becoming a spin, and **both escalate to the phone rather
than failing quietly**: a session that comes back having written almost nothing
is saying "ok" in a loop rather than working, so it is allowed to stop and you
are told it is stuck; and a per-hour budget catches a session that has run out
of defined work.

A hook runs *inside* the session, so it can prevent a stop but can do nothing
about a **crash**. That gap is what left one repo dead for 5.8 days with 50
messages queued behind it, and it is why the supervisor exists.

## The supervisor

A worker is `claude -p` with stream-json in and out. The asymmetry is
deliberate: **stdin is a pipe the supervisor holds**, so a nudge can be injected
at any moment, while **stdout is redirected to a file by the shell**. Reading N
children's pipes needs `select` or threads; a file has a *size*, and a size that
stopped growing is a stalled worker. It also means `tail -f` on any worker
works, which a pipe would have taken away.

Compaction is not reimplemented — the client already does it. Rotation is here,
because it is a different thing: past a point you want a *fresh* session
carrying a written handoff, not a compressed transcript.

Restarts are capped per hour. An unattended process that respawns a crashing
child forever is a fork bomb with good intentions; the cap turns "it kept dying"
into a message on your phone.

**Queued work reaches the worker.** The bus assumes a session claims its label
and polls it; one that never gets round to claiming leaves its inbox filling up
while it works, with nothing saying so. The supervisor delivers into the stdin
pipe it already holds — but only when nobody else is listening, never the
worker's own messages, and at most three per tick so a backlog does not become
one enormous turn.

## One human owns the bot

Pairing records the **owner's user id**, not just the channel, and every inbound
message, slash command and button press is checked against it.

Pairing to a channel alone is a property of *where* a message arrived: a group
DM has a channel id like any other, so anyone added to one would inherit the
ability to start sessions and talk to a shell. Replies go to the DM channel
opened with the owner, which is what "always a direct message" actually
requires.

## Gates

Both suites assert **both directions** — what must be pushed and what must
*not*, what must be restarted and what must not. An alerting system that has
stopped alerting looks exactly like a quiet night, and a positive-only suite
stays green through it.

The negative cases run first, and the clearest examples are the ones about not
acting. A plain message must spawn **nothing** — the positive half of that
assertion (a reply was sent) passes whether or not a session was started behind
it. An idle project whose session ended its turn must not be restarted, counted
by how many sessions were spawned rather than by how it looks, because a
supervisor respawning one every fifteen seconds all night is green in every view:
a growing log, a live process, recent activity.
