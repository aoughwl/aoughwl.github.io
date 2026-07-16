# aoughwl.github.io

Source for the aoughwl org docs site → **https://aoughwl.github.io/**

Jekyll + the [just-the-docs](https://just-the-docs.com/) remote theme, built by
GitHub Pages. Content:

- `index.md` — home / overview
- `nimony.md` — the headline: **Issues Fixed & Features Added** record for `aoughwl/nimony`
- `libraries.md` / `backends.md` / `tools.md` + `docs/*.md` — the three project
  categories and one page per project (net stack, web/html/css → Libraries;
  aowl-web, aowl-ts/py/hl → Backends; aowl-code, niflens, nimony-lsp → Tools)
- `projects.md` — hidden (`nav_exclude`) all-projects overview at `/projects`

The per-repo READMEs are short stubs that point here; this is the canonical docs.
To add a project page, drop a `docs/<name>.md` with `parent: Nimony Libraries`
(or `Nimony Backends` / `Nimony Tools`) front-matter.
