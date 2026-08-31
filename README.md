# aoughwl.github.io

Source for the aoughwl org docs site → **https://aoughwl.github.io/**

**[VitePress](https://vitepress.dev/)**, built and deployed by GitHub Actions
(`.github/workflows/deploy.yml`) on every push to `main`. Local search is on
(`themeConfig.search.provider: 'local'`), so the index is built at build time
and needs no external service.

> An earlier version of this file said "Jekyll + just-the-docs". That has not
> been true for some time. It is called out here rather than quietly deleted,
> because a stale README reads as authoritative for as long as it survives.

## Building it locally

```bash
npm ci
npm run docs:dev       # dev server with hot reload
npm run docs:build     # production build into .vitepress/dist
npm run docs:preview   # serve the built site
```

## Layout

- `index.md` — home
- `docs/*.md` — one page per project; sub-pages under `docs/<project>/`
- `.vitepress/config.mjs` — the sidebar tree, hand-written **except** for the
  aowlspt reference section (see below)
- `public/` — static assets, copied verbatim. **Do not put `.md` files here**:
  VitePress compiles any markdown under `public/` as a page as well as copying
  it, which is rarely what you want. Use `.txt` for raw documents.

## The aowlspt reference section is GENERATED

Everything under `docs/aowlspt/reference/` — and the `sidebar.json` that
`.vitepress/config.mjs` imports — is emitted by `tools/gendocs.py` **in the
aowlspt repository**, from that repo's actual source. Editing those pages here
is pointless: the next run overwrites them, and in the meantime the edit reads
as authoritative.

To regenerate, from a checkout of aowlspt that has the relevant branch:

```bash
cd /path/to/aowlspt
python tools/gendocs.py \
  --out    /path/to/aoughwl.github.io/docs/aowlspt/reference \
  --public /path/to/aoughwl.github.io/public/aowlspt
```

`--check` exits non-zero if the output would change — that is the CI form, so
a source change that invalidates the docs fails loudly instead of drifting.

What it generates, and from what:

| Pages | Source |
| --- | --- |
| `host-flags` | the `readBoolKey`/`readIntKey`/`readStrKey` call sites in `host/` |
| `abi/*` | `abi/aowlspt_*.h` |
| `mods/*` | each `mods/*/config.json` |
| `api/*` | `aowl/src/aowlspt/*.nim`, via `tools/nimapi.py` |
| `automation/verbs`, `automation/scripts` | `tools/autoscript.nim`, `scripts/*.nim` |
| `automation/api`, `automation/*`, `internals/*` | mirrored markdown from `docs/` |
| `facts` + `public/aowlspt/aowl-facts.txt` | `docs/AOWL_FACTS.md` |

### The publication gate

**aowlspt is private; this repo is public.** Every page the generator produces
passes through a scrub-and-verify step as the last thing it does:

- machine-local user paths are rewritten to `<HOME>`;
- webhook URLs are redacted;
- a page still carrying a personal email address after scrubbing **aborts the
  whole run** rather than being written — it cannot be safely rewritten, so it
  is refused.

The gate is deliberately the last step, so a page added later cannot route
around it by accident. Do not relax it to make a run pass.
