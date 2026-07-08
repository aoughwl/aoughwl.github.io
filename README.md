# aoughwl.github.io

Source for the aoughwl org docs site → **https://aoughwl.github.io/**

Jekyll + the [just-the-docs](https://just-the-docs.com/) remote theme, built by
GitHub Pages. Content:

- `index.md` — home / overview
- `nimony.md` — the headline: **Issues Fixed & Features Added** record for `aoughwl/nimony`
- `projects.md` + `docs/*.md` — one page per project (nimony-web, nim-code, niflens,
  nimony-lsp, the net stack, web/html/css, nimony-ts/py/hl)

The per-repo READMEs are short stubs that point here; this is the canonical docs.
To add a project page, drop a `docs/<name>.md` with `parent: Projects` front-matter.
