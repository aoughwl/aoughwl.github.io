#!/usr/bin/env bash
# Every host-surface figure this site publishes, derived from ONE PINNED COMMIT
# of the engine repository.
#
#   bash tools/jester-pinned-surface.sh
#
# WHY PINNED. The host surface is under active development and moves several
# times a day -- it moved twice while the page quoting it was being edited, and
# two runs of this checker minutes apart disagreed with each other. A count with
# no commit beside it is wrong the moment the surface moves, and chasing the
# moving number only means publishing a figure that is stale by the time anyone
# reads it. A count WITH a commit beside it is true permanently: it stays true
# when the surface reaches five hundred, and a reader can check it by looking at
# that commit. So the site says "440 host calls, at f559ceb" and this script is
# what makes that checkable.
#
# Moving the pin is a deliberate act: change PIN here, re-run
# `node tools/jester-surface.mjs <checkout> --write`, and update the commit named
# in the prose. `npm run claims` is what notices if you did one and not the rest.
#
# It reads the pinned tree through `git archive` rather than checking anything
# out, because the working trees on this machine belong to other people.
set -uo pipefail

PIN=${PIN:-f559ceb}
REPO=${JESTER:-$HOME/Documents/infiniteless-next}

if [ ! -d "$REPO/.git" ]; then
  echo "REFUSED: no Jester checkout at $REPO, so nothing here is evidence."
  exit 2
fi
if ! git -C "$REPO" cat-file -e "$PIN^{commit}" 2>/dev/null; then
  echo "REFUSED: $REPO has no commit $PIN, so nothing here is evidence."
  exit 2
fi

T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
git -C "$REPO" archive "$PIN" \
  Packages/com.infiniteless.runtime/Runtime \
  Packages/com.infiniteless.runtime/ModSdk \
  web/triage.tsv web/triage.mjs 2>/dev/null | tar -x -C "$T"

cd "$T" || exit 2
P=Packages/com.infiniteless.runtime/Runtime
SDK=Packages/com.infiniteless.runtime/ModSdk

echo "pinned-at=$PIN"

# Every call name the bridge answers: the inline `case` labels, plus every
# prefix-owned family it falls through to. The families are DISCOVERED from the
# bridge rather than listed here, so a family nobody told this script about is
# still counted the day it appears.
families() {
  grep -ohE '[A-Za-z]+HostCalls\.Prefix' "$P/Native/AowliHostBridge.cs" |
    sed 's/\.Prefix//' | sort -u
}
allcalls() {
  grep -ohE 'case "infiniteless_[a-z0-9_]+"' "$P/Native/AowliHostBridge.cs" |
    grep -oE 'infiniteless_[a-z0-9_]+'
  for c in $(families); do
    f=$(find "$P" -name "$c.cs")
    q=$(grep -ohE 'Prefix = "infiniteless_[a-z0-9_]+"' "$f" | grep -oE 'infiniteless_[a-z0-9_]+')
    grep -ohE 'case Prefix \+ "[a-z0-9_]+"' "$f" | grep -oE '"[a-z0-9_]+"$' | tr -d '"' | sed "s|^|$q|"
  done
}

echo "host-calls=$(allcalls | sort -u | wc -l | tr -d ' ')"
echo "core-calls=$(grep -ohE 'case "infiniteless_[a-z0-9_]+"' "$P/Native/AowliHostBridge.cs" | grep -oE 'infiniteless_[a-z0-9_]+' | sort -u | wc -l | tr -d ' ')"
echo "families=$(families | wc -l | tr -d ' ')"
fam=0
for c in $(families); do
  f=$(find "$P" -name "$c.cs")
  n=$(grep -ohE 'case Prefix \+ "[a-z0-9_]+"' "$f" | sort -u | wc -l | tr -d ' ')
  fam=$((fam + n))
done
echo "family-calls=$fam"

# The mod side of the same boundary, derived independently. That these agree is
# the check; it is not one number quoted twice.
echo "sdk-decls=$(grep -rhoE 'importc: *"infiniteless_[a-z0-9_]+"' "$SDK/" | grep -oE 'infiniteless_[a-z0-9_]+' | sort -u | wc -l | tr -d ' ')"
echo "sdk-procs=$(grep -rhcE '^(proc|func|iterator|template|macro) [a-zA-Z]+\*' "$SDK"/*.nim | awk '{n+=$1} END {print n}')"
echo "sdk-modules=$(ls "$SDK"/*.nim | wc -l | tr -d ' ')"
echo "host-surface=$(grep -oE 'SemanticVersion\([0-9]+, [0-9]+, [0-9]+\)' "$P/Core/HostSurface.cs" | head -1 | tr -d ' ' | sed 's/SemanticVersion(//;s/)//;s/,/./g')"

# And the third route: the web triage, which has to NAME every call rather than
# count them, and refuses to print while any call is untriaged.
if [ -f web/triage.mjs ]; then
  node web/triage.mjs 2>/dev/null | grep -E '^web-triage-' || echo "web-triage=REFUSED"
fi
