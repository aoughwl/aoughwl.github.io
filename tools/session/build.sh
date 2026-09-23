#!/usr/bin/env bash
# Build public/playground/aowli_session.js — the aowli interpreter plus the LIVE
# SESSION seam, as one self-contained browser bundle.
#
#   bash tools/session/build.sh
#
# The lane is aowli's own webtest/build.sh, pointed at this directory's
# webmain_session.nim: nimony frontend (--bits:32) -> .c.nif per module,
# nimony-web's nim_js -> .js per module, then one concatenation with runtime.js
# and jsenv.js in front. It runs under WSL because that is where the toolchain
# lives; everything it reads outside this repo is named here.
#
# aowli's source is taken from `git archive HEAD` of the checkout, NOT from its
# working tree: several people edit that tree, and a bundle built from whatever
# was uncommitted in it is a bundle whose inputs no commit names. Set AOWLI_SRC
# to an already-extracted tree to skip that (which is also how you test an
# uncommitted interpreter change — deliberately explicit, so it cannot happen by
# accident).
set -euo pipefail
NIM=${NIM:-$HOME/nimony}
WEB=${WEB:-$HOME/nimony-web}
AOWLI_GIT=${AOWLI_GIT:-/mnt/c/Users/savant/aowli}
AOWLHL=${AOWLHL:-$HOME/aowlhl/src}
AOWLABI=${AOWLABI:-$HOME/aowlabi/src}
AOWLC=${AOWLC:-$HOME/aowlc/src}
JSFFI="$WEB/tests/jsbackend"
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# WHICH BUNDLE. By default the live-session seam; `ENTRY`/`OUT` build any other
# aowli webmain through the same lane.
#
#   WEBMAIN=webmain_vm OUT=.../aowli_vm.js bash tools/session/build.sh
#
# `WEBMAIN` names one of aowli's own entry points (webmain, webmain_vm,
# webmain_run, webmain_dbg) inside the source tree this script extracts, so it
# is resolved after that extraction. `ENTRY` takes a path directly.
#
# This exists because the shipped `aowli_vm.js`, `aowli.js` and `aowli_run.js`
# are OLDER THAN A FIX THEY NEED. `webvfs.publishMainModule` stores the main
# module under the one name its own symbols carry (`/w/webmod.s.nif`) plus a
# synthesized empty index; without it the VM's eager `compileModule` reaches
# `programs.tryLoadSym`, misses the VFS, and dies with
# `[Assertion Failure] expected 'index' tag`. That is exactly what the
# playground's "the Bytecode VM fell back" message has been reporting: not a VM
# bug, a bundle built before the fix. `aowli_session.js` carries it because it
# was rebuilt after; the others were not, so they need this lane.
ENTRY=${ENTRY:-}
WEBMAIN=${WEBMAIN:-}
OUT=${OUT:-"$HERE/../../public/playground/aowli_session.js"}
# A non-session bundle has no `__sess_*` seam, so the seam check below is only
# for the one that should have it.
WANT_SEAM=${WANT_SEAM:-auto}

SRC="${AOWLI_SRC:-$HOME/.cache/aowl-session/aowli-$$}"
if [ -z "${AOWLI_SRC:-}" ]; then
  mkdir -p "$SRC"
  git -C "$AOWLI_GIT" archive HEAD src webtest/jsenv.js | tar -x -C "$SRC"
  echo "aowli source: $(git -C "$AOWLI_GIT" rev-parse --short HEAD) -> $SRC"
fi

# THE SHIPPED BUNDLE IS NOT BUILT FROM HEAD. As of 2026-09-23 aowli's HEAD
# (2ecd964, Sept 10) is missing interpreter fixes that exist only in its working
# tree, and programs that make host calls depend on them. Until those land,
# build from a snapshot of the working tree:
#
#   D=~/.cache/aowl-session/aowli-wt-$(date +%s); mkdir -p $D/webtest
#   cp -r /mnt/c/Users/savant/aowli/src $D/; cp /mnt/c/Users/savant/aowli/webtest/jsenv.js $D/webtest/
#   AOWLI_SRC=$D bash tools/session/build.sh
#
# and run the session gates before shipping what it produced.

# INTERPRETER ADDITIONS THIS SEAM NEEDS THAT ARE NOT IN AOWLI'S HEAD YET.
#
# Each `aowli-patches/*.patch` is a diff against aowli's `src/`, applied to the
# extracted tree — never to the shared checkout, which other work has dirty.
# A patch that is ALREADY in the tree (it landed upstream, or AOWLI_SRC points
# at a tree that has it) is skipped; one that neither applies nor is present is
# FATAL, because a seam built without it fails at the first call, in the page.
for p in "$HERE"/aowli-patches/*.patch; do
  [ -f "$p" ] || continue
  if patch -p1 -d "$SRC" --dry-run -R -s -f < "$p" >/dev/null 2>&1; then
    echo "patch: $(basename "$p") already present"
  elif patch -p1 -d "$SRC" -s -f < "$p"; then
    echo "patch: $(basename "$p") applied"
  else
    echo "FATAL: $(basename "$p") does not apply to this aowli tree"; exit 1
  fi
done

# Resolved here because a WEBMAIN lives inside the tree that was just extracted.
if [ -z "$ENTRY" ]; then
  if [ -n "$WEBMAIN" ]; then ENTRY="$SRC/src/aowli/$WEBMAIN.nim"
  else ENTRY="$HERE/webmain_session.nim"; fi
fi
[ -f "$ENTRY" ] || { echo "FATAL: no such entry point: $ENTRY"; exit 1; }
echo "entry: $ENTRY -> $OUT"

NIMLOCK="$(command -v nimlock || echo "$HOME/.aowl/bin/nimlock")"
[ -x "$NIMLOCK" ] || NIMLOCK=env
NC="$HERE/.jsnc-$(basename "${ENTRY%.nim}")"
rm -rf "$NC"; mkdir -p "$NC"

echo "== 1. nimony frontend: $(basename "$ENTRY") -> .c.nif =="
"$NIMLOCK" "$NIM/bin/nimony" c --bits:32 --define:nimNativeAlloc \
  -p:"$NIM/src/lib" -p:"$NIM/src/nimony" -p:"$NIM/src/models" \
  -p:"$NIM/src/gear2" -p:"$NIM/src/hexer" -p:"$SRC/src/aowli" -p:"$JSFFI" \
  -p:"$AOWLHL" -p:"$AOWLABI" -p:"$AOWLC" \
  --nimcache:"$NC" "$ENTRY" 2>&1 | grep -viE '^$' | tail -25 || true
echo "   (the 32-bit C link failure above is expected: nothing links here)"

mapfile -t cnifs < <(find "$NC" -name '*.c.nif')
echo "   .c.nif modules: ${#cnifs[@]}"
[ "${#cnifs[@]}" -eq 0 ] && { echo "FATAL: frontend produced nothing"; exit 1; }

echo "== 2. nim_js: .c.nif -> .js =="
todo=0
for c in "${cnifs[@]}"; do
  out="$("$WEB/bin/nim_js" "$c" "${c%.c.nif}.js" 2>&1)" || true
  n=$(echo "$out" | grep -oE '[0-9]+ unsupported' | grep -oE '[0-9]+' || true)
  [ -n "$n" ] && todo=$((todo + n))
done
echo "   unsupported nodes: $todo"

echo "== 3. bundle =="
AF=$(mktemp); FF=$(mktemp); KF=$(mktemp)
jsfiles=(); for c in "${cnifs[@]}"; do jsfiles+=("${c%.c.nif}.js"); done
awk -v AF="$AF" -v FF="$FF" -v KF="$KF" '
  /^\/\/__NIMJS_CONST_ALLOC_BEGIN__$/ { s=1; next }
  /^\/\/__NIMJS_CONST_ALLOC_END__$/   { s=0; next }
  /^\/\/__NIMJS_CONST_FILL_BEGIN__$/  { s=2; next }
  /^\/\/__NIMJS_CONST_FILL_END__$/    { s=0; next }
  /^"use strict";$/                   { next }
  { if (s==1) print > AF; else if (s==2) print > FF; else print > KF }
' "${jsfiles[@]}"
mkdir -p "$(dirname "$OUT")"
cat "$JSFFI/runtime.js" > "$OUT"; echo >> "$OUT"
cat "$SRC/webtest/jsenv.js" >> "$OUT"; echo >> "$OUT"
cat "$AF" "$FF" "$KF" >> "$OUT"
rm -f "$AF" "$FF" "$KF"
echo "   $OUT: $(wc -c < "$OUT") bytes"

# THE FRAME STACK, AND IT IS NOT OPTIONAL HERE.
#
# The Leng JS runtime's `allocFixed` is "a C-stack model: never freed", which is
# correct for a program that runs `main` once and exits and fatal for a session
# that calls `update` and `drawGui` sixty times a second. Without this the page
# dies against the 1 GiB ceiling in well under a minute — measured on this very
# bundle: "leng: out of linear memory (allocFixed 8 bytes at 1073741824)" a few
# seconds into the first mod that draws text every frame.
#
# `tools/frame-arena.mjs` exposes a mark and a release over the bump pointer, and
# `session-worker.js` takes a mark before each per-frame callback and releases it
# after. It patches a GENERATED file, so it has to run after every build; running
# it twice is a no-op.
# The toolchain runs under WSL and node usually does not live there, so the
# Windows install is a first-class candidate rather than a fallback.
# $NODE wins; then WSL's own; then the Windows installs, including the version
# managers (nvm4w puts the active version under C:\nvm4w\nodejs) — because
# "node is not on PATH in WSL" is the normal case here, not an odd one.
NODE="${NODE:-$(command -v node || command -v nodejs || true)}"
if [ -z "$NODE" ]; then
  for cand in /mnt/c/nvm4w/nodejs/node.exe \
              "/mnt/c/Program Files/nodejs/node.exe" \
              "/mnt/c/Program Files (x86)/nodejs/node.exe" \
              /mnt/c/ProgramData/nvm/v*/node.exe \
              "/mnt/c/Users/$USER/AppData/Roaming/nvm/v*/node.exe"; do
    [ -x "$cand" ] && { NODE="$cand"; break; }
  done
fi
[ -n "$NODE" ] || { echo "FATAL: no node to run the frame arena with — the bundle would OOM in seconds"; exit 1; }
# A Windows node.exe cannot resolve a `/mnt/c/...` path, so when that is what we
# found, hand it Windows spellings. `wslpath -w` is the conversion.
if [ "${NODE%.exe}" != "$NODE" ]; then
  ARENA_ARG="$(wslpath -w "$HERE/../frame-arena.mjs")"
  OUT_ARG="$(wslpath -w "$OUT")"
else
  ARENA_ARG="$HERE/../frame-arena.mjs"
  OUT_ARG="$OUT"
fi
"$NODE" "$ARENA_ARG" "$OUT_ARG" || { echo "FATAL: the frame arena did not install"; exit 1; }
grep -q "__leng_mark" "$OUT" || { echo "FATAL: the frame arena is not in the bundle"; exit 1; }

# A bundle that built but registered nothing is the failure that costs the most
# time downstream, because it looks exactly like a page bug. Name it here.
if [ "$WANT_SEAM" = auto ]; then
  case "$(basename "$ENTRY")" in webmain_session.nim) WANT_SEAM=1;; *) WANT_SEAM=0;; esac
fi
if [ "$WANT_SEAM" = 1 ]; then
  for sym in __sess_boot __sess_swap __sess_append __sess_call __sess_stop __sess_globals; do
    grep -q "\"$sym\"" "$OUT" || { echo "FATAL: $sym is not in the bundle"; exit 1; }
  done
  echo "   seam: boot/load/has/call/swap/append/stop all present"
fi

# THE FIX THIS LANE EXISTS TO CARRY FORWARD. A bundle without
# `publishMainModule` is one that will die on `expected 'index' tag` the first
# time anything walks the main module eagerly. Name it here rather than letting
# a page discover it.
grep -q "publishMainModule" "$OUT" ||   echo "   WARNING: publishMainModule is not in this bundle — see webvfs.nim"
