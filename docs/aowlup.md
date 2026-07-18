# aowlup — the toolchain manager

`aowlup` is **`rustup` for the aowl/nimony stack**. It installs, versions, and
*selects* the components of the compilation pipeline; the driver,
[aowlmony](aowlmony), compiles your code against whatever `aowlup` has selected.
One provisions the toolchain, the other runs it.

Repo: **`aoughwl/aowlup`** (public).

```
aowlup  ── manages the toolchain ──►  ~/.aowl/registry.json  ◄── reads ──  aowlmony
                                       (single source of truth)
```

[[toc]]

---

## Three axes

### Variants — swap any implementation

Every pipeline *slot* has interchangeable implementations, and `aowlup` records
which one is selected:

| slot | variants |
|---|---|
| parser | **aowlparser** (ours) · **nifler** (nimony) |
| sem | **aowlsem** (ours) · **nimsem** (nimony) |
| hexer | **aowlhexer** (ours) · **hexer** (nimony) |

Backends (`native/interp/vm/js/ts/py`) and tooling (`lsp/suggest/fmt/lens`) live
in the same catalog, so new targets are data, not new code.

### Profiles — flip the whole stack at once

| profile | parser | sem | hexer | |
|---|---|---|---|---|
| `aowl`   | aowlparser | aowlsem | aowlhexer | all ours |
| `nimony` | nifler | nimsem | hexer | all nimony |
| `hybrid` | aowlparser | nimsem | aowlhexer | the driver default |

```sh
aowlup profile use nimony     # flip all three passes
aowlup use sem aowlsem        # override one slot on top of the profile
aowlup +nimony doctor         # one-shot ephemeral profile (rustup +toolchain style)
```

### Versions — a nimony version manager, too

Every component is a git checkout. `aowlup status` derives each repo's GitHub
branch and asks whether it is behind — behind / ahead / diverged / up-to-date.
Because the nimony variants (`nifler`/`nimsem`/`hexer`) all resolve to your
nimony checkout, `status` doubles as a **nimony version manager**, tracking
`master`/`devel` against upstream `nim-lang/nimony`.

```sh
aowlup status                 # git rev + GitHub update check per component
aowlup update aowlc --yes     # git pull (ff-only; dry-run without --yes)
aowlup rebuild aowlsem --yes  # rebuild from source
```

## Fresh machine — `aowlup setup`

There is no prebuilt nimony binary, so **setup is the build**. `aowlup setup`
clones the missing component repos and builds them in dependency order —
**nimony first** (the bootstrap compiler, via `nim c -r src/hastur build all`),
then the aoughwl components it compiles. Dry-run by default; `--yes` executes.

```sh
aowlup setup            # show the plan
aowlup setup --yes      # clone + build everything
```

## Editor — `aowlup vscode`

The LSP is just another registry component, so the editor never hardcodes paths.
`aowlup vscode` writes `.vscode/settings.json` for the **nimony VS Code
extension** (`nimony.nimony`), pointing `nimony.serverPath` at the resolved
[aowllsp](aowllsp) and `nimony.nimonyPath` at the compiler — so the editor tracks
whichever profile is active.

```sh
aowlup vscode           # preview the settings
aowlup vscode . --yes   # write .vscode/settings.json here
```

## The registry — one source of truth

`~/.aowl` is the data home: `registry.json` (profile + per-slot overrides + linked
repos) and `backends/<slot>/backend.json` (the resolved invocation contract for
each component). Resolution order for any slot:

```
AOWL_<SLOT> env  →  slot override  →  active profile's variant  →  dev-fallback probe  →  error
```

`aowlup config [--lsp]` emits the resolved payload as JSON — this is exactly what
[aowlmony](aowlmony) reads to run, and what `aowlup vscode` reads to wire the
editor. No component path is ever named on the command line.
