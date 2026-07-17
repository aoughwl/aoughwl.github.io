---
title: Engineering Notes
nav_order: 20
has_children: true
permalink: /engineering-notes
nav_exclude: true
---

# Engineering Notes
{: .no_toc }

The opinionated side: how the stack got built, what broke along the way, and why
we made the calls we made. Argued and narrative, where the reference docs stay
terse. Every claim here traces to a commit and a test.
{: .fs-6 .fw-300 }

---

| Note | What's inside |
|:--|:--|
| [Changes](nimony) | The one record of everything we've **added** and **fixed** in the compiler — `.passive`/async features, the incremental-compilation wins that make live tooling fast, and the checker/diagnostics fixes. Every row links to its own root-caused writeup. |
