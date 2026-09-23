---
title: Titicaca and the Web Platform Tests
description: Titicaca's standing on the Web Platform Tests against Ladybird, and how to run the tools/wptrun runner yourself.
---

# Web Platform Tests

Tests written alongside an engine only prove it agrees with itself. The
[Web Platform Tests](https://web-platform-tests.org) are what Chrome, Firefox,
Safari and Ladybird are measured by, so they are the honest yardstick.

## Standing

On the directories we track, Titicaca passes about **93.5%** of subtests;
Ladybird passes **96.2%** of the same set.

The set: `dom/nodes`, `dom/events`, `url`, `css/css-syntax`, `domparsing`,
`css/selectors` and `html/dom`.

Two rules keep the number honest. A test that did not run is never counted as a
pass (a file that will not parse, a harness that never reported, and a file that
threw are three different outcomes). Tests that only apply to worker or
shadow-realm scopes are recorded as not applicable rather than failed.

## Running it

The runner is `tools/wptrun.exe`, built from the engine's tools directory. It
runs the same pure modules the browser uses, with no window and no network, and
serves test resources straight from a WPT checkout on disk.

```
wptrun --run-dir <wpt-root> <dir> [<dir> ...]
       [--jobs 8] [--cap-mb 1024] [--timeout 30] [--steps 5000000]
       [--json out.json]
wptrun --one     <wpt-root> <relative/test.html[?variant]>   # narrated, one file
wptrun --compare <our.json> <other.json> [<more.json> ...]   # against browser results
wptrun url       <urltestdata.json>
wptrun setters   <setters_tests.json>
```

Each test file runs in its own child process inside a Windows Job Object with a
hard memory cap, because the engine has no garbage collector. Use
`--cap-mb 2048` for the largest directories. `--compare` takes result files from
wpt.fyi runs of other browsers, which is how the Ladybird figure is produced.
