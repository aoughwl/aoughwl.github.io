---
title: Engineering Notes
nav_order: 2
has_children: true
permalink: /engineering-notes
---

# Engineering Notes
{: .no_toc }

The opinionated side: how the stack got built, what broke along the way, and why
we made the calls we made. Argued and narrative, where the
[Documentation](documentation) stays terse. Every claim here traces to a commit
and a test.
{: .fs-6 .fw-300 }

---

| Note | What's inside |
|:--|:--|
| [Compiler work](nimony) | The record of the compiler engineering behind the stack — the `.passive`/async features and the incremental-compilation wins that make live tooling fast. |
| [Compiler fixes](docs/nimony-fork) | Each fix, root-caused: symptom → cause → fix → the test that proves it. |
| [Changelog](changelog) | The running ledger — every issue closed and feature landed, each with its own writeup. |
