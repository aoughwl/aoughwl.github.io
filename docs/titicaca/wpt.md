---
title: Titicaca and the Web Platform Tests
description: Titicaca's standing on the Web Platform Tests against Ladybird, how the number is made honest, and how to run the tools/wptrun runner yourself.
---

# Web Platform Tests

Tests written alongside an engine only prove it agrees with itself. The
[Web Platform Tests](https://web-platform-tests.org) are what Chrome, Firefox,
Safari and Ladybird are measured by, so they are the one check that can say
whether this engine agrees with the web.

## Standing

On the directories we track, Titicaca passes about **93.5%** of subtests;
Ladybird passes **96.2%** of the same set.

The set: `dom/nodes`, `dom/events`, `url`, `css/css-syntax`, `domparsing`,
`css/selectors` and `html/dom`.

## How it got there

The score started near 12% and moved in steps. The biggest, in order:

- **The runner, not the engine.** A raised step budget and letting the test
  harness draw its results table stopped whole reflection directories being cut
  off while every subtest they ran passed.
- **Generated reflection** from WebIDL for HTML element attributes.
- **A real Selectors implementation** behind `querySelector`, CSSOM and the
  cascade.
- **Frames with their own realm** and their own cascade, which fixed a whole
  directory of tests that repeat their checks in an iframe.
- **CSS Syntax rules** for cutting style sheets, plus `@namespace` and nesting.
- **All 148 named colours**: a family of `:has` invalidation tests was failing
  only because `orangered` and `darkred` were unknown.
- **A CSS Syntax tokenizer and declaration parser**, XML parsing, `innerText`,
  event handler maps, `DOMTokenList`, `Proxy`, and activation behaviour.

## Keeping the number honest

- A test that did not run is never counted as a pass. A file that will not
  parse, a harness that never reported and a file that threw are three different
  numbers.
- A test URL is counted the way wpt.fyi counts it: each `variant` is its own
  test, and worker and shadow-realm scopes are recorded as not applicable, never
  as passes or failures.
- Every test ends as exactly one of: pass, fail, error, budget, memory-cap,
  timeout, crash, unparsed, no-harness or missing-include. A missing include is a
  runner or checkout fault and never counts against the engine.

## Running it

The runner is `tools/wptrun.exe`. It runs the same pure modules the browser
uses, with no window and no network, and serves test resources straight from a
WPT checkout on disk.

```
wptrun --run-dir <wpt-root> <dir> [<dir> ...]
       [--jobs 8] [--cap-mb 1024] [--timeout 30] [--steps 5000000]
       [--json out.json]
wptrun --one     <wpt-root> <relative/test.html[?variant]>   # narrated, one file
wptrun --compare <our.json> <other.json> [<more.json> ...]   # against browser results
wptrun url       <urltestdata.json>
wptrun setters   <setters_tests.json>
```

Typical session:

```
wptrun --run-dir path/to/wpt dom/nodes dom/events url --jobs 8 --cap-mb 2048 --json ours.json
wptrun --compare ours.json ladybird.json chrome.json
```

`--compare` reads result files exported from wpt.fyi runs of other browsers,
which is how the Ladybird figure above is produced.

## Containment

The engine has no garbage collector, so a runaway test could take a machine
down. `--run-dir` therefore never runs a test in its own process. Each test is a
child process inside a Windows Job Object with a hard per-process memory cap, a
job-wide cap, a live-process limit and kill-on-close. The parent kills a child
that passes its wall clock, and refuses to start when concurrency multiplied by
the cap would exceed half of physical memory. Use `--cap-mb 2048` for the
largest directories, and a longer wall clock is applied automatically to tests
marked `timeout=long`.

## Debugging a single test

`--one` narrates one file: what it loaded, what the harness reported and where
it stopped. If a test crashes rather than fails, build a debug copy of the
runner and attach a debugger at exit; release symbols point at the wrong frame.
