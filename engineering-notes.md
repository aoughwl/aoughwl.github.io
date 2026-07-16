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
| [The fork](nimony) | The `aoughwl/nimony` record — the compiler fixes and `.passive`/async features that came before the from-scratch stack, and the reason we kept the fork as a reference oracle. |
| [Divergences from upstream](docs/nimony-fork) | Each compiler fix, root-caused: symptom → cause → fix → the test that proves it. |
| [Changelog](changelog) | The running ledger — every issue fixed and feature added, each with its own writeup. |
