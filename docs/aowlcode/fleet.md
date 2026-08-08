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

A **project** is one supervised session on one repo. Three rules define them.

**Every boot starts with zero.** Not "usually zero" — zero, every time. A
project is a decision made for a session, not a setting. Carrying the list
across a boot means the machine comes up and puts sessions on repos nobody asked
about this morning, invisibly, because a config that was already right is the
one thing nobody re-reads.

The single exception is not one: a project whose process is **still alive** is
adopted rather than re-created. The supervisor's children are orphaned rather
than killed when it dies, so a crash-restart five seconds later would otherwise
abandon a live session to keep editing a checkout nobody is watching. Adoption,
never persistence.

**Two ways to work, and the difference is the ending.**

| you say | what happens |
|---|---|
| `work on aowlsem` | **standing** — inbox first, runs until stopped |
| `work on aowlsem: fix the X drop` | **one job** — it reports back and stops |
| the same, at a project already running | **an interrupt** — done, reported, then back to standing |

A task registers no standing goal, so the Stop hook does not hand the work back
and the supervisor does not restart it when it exits: it is allowed to be
finished. When it finishes, its **last message** is pushed to the phone as the
report — taken from the session's output rather than from a tool it has to
remember to call, because a report that depends on the model remembering is one
that is sometimes missing.

A running project is **never re-briefed**. Asking for one that is already
running reports how long it has been up and names where direction goes instead:
a running session holds a context that a second briefing fights with.

**One dial stays adjustable**: how wide it fans out. Setting it writes the
config *and* messages the running session, so it applies to the turn it is in
the middle of rather than at some future restart.

Everything the fleet spawns runs **Opus at medium effort** — projects, the
planner and the concierge alike. Stated in the supervisor rather than left to
whatever the CLI defaults to that week: a session working unattended for hours
is a property of the fleet, not of the machine's current settings.

## Saying it, instead of typing a slash

Slash commands are a keyboard affordance and this is a phone. "work on aowlsem",
"what is aowlsem doing?", "3 agents on aowlsem", "subscribe to aowlsem loud" all
reach the same handlers the slash commands do — one implementation, so the two
cannot drift.

A sentence only becomes a command when it is **unambiguous**: the verb is at the
front, and where the command names an existing project, that project resolves.
"stop the aowlsem gate flaking" is not a stop command, because *the aowlsem gate
flaking* is not a running project. Everything else falls through to a chat
session — the safe direction, where the worst case is an answer instead of an
action.

Names are resolved, not matched literally: "work on the discord integration"
finds `~/aoughwl-discord`. An **ambiguous** name resolves to nothing and lists
the candidates, because guessing between two repos puts a session on the wrong
checkout.

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

## Starting something that does not exist yet

Describe a new project in a sentence and a planning session writes a plan: what
it is, what it deliberately is **not**, the design decisions with their rejected
alternatives, a build order, and the gate that proves it works. That arrives on
the phone with three buttons.

Nothing is created until you tap **Start**. Then the repo is made, the plan is
its first commit, and a project starts with that plan as its standing goal.

The approval step is not ceremony. A one-sentence description is not enough to
build from, and an agent starting from one spends its first hour inventing the
requirements you would have given it in ten seconds. It is also the last moment
where "that is not what I meant" costs nothing. The plan is the model's final
message and the bridge writes the file, so the planning session needs no `Write`
tool at all.

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

The negative cases run first, and the sentence router's are the clearest example
of why: it fails *silently* by construction, since anything it declines to
understand goes to a chat session and comes back with a plausible answer. So the
suite asserts that "the aowlsem gate is flaking, can you stop that from
happening" is **not** a stop command, before it asserts that "stop aowlsem" is.
