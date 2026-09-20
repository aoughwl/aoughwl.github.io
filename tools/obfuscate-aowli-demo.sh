#!/usr/bin/env bash
# obfuscate-aowli-demo.sh — obfuscate the free browser copies of aowli (the
# playground's Run/Debug engines, and the Jester demo's host). These ship with
# no licence check on purpose (it's the free demo); this raises the cost of
# reading them back out, nothing more. See tools/obfuscate.config.json for the
# profile and tools/run-aowli-bundle.mjs for how each file is checked before
# and after: same input, same stdout/stderr/exit, or this script refuses.
#
#   ./tools/obfuscate-aowli-demo.sh            # obfuscate + verify, in place
#   ./tools/obfuscate-aowli-demo.sh --check    # verify only, change nothing
set -euo pipefail
cd "$(dirname "$0")/.."
CFG="tools/obfuscate.config.json"
SP="$(mktemp -d)"; trap 'rm -rf "$SP"' EXIT
CHECK_ONLY=0; [ "${1:-}" = "--check" ] && CHECK_ONLY=1

FILES=(public/playground/aowli.js public/playground/aowli_vm.js
       public/playground/aowli_run.js public/playground/aowli_dbg.js
       public/jester-demo/aowli-host.js)

# A tiny program + its dependency modules, for the before/after run-check.
cat > "$SP/prog.nim" <<'EOF'
import std/syncio
echo "aowli e2e ok"
EOF
NIM="${NIM:-$HOME/nimony}"
"$NIM/bin/nimony" c -p:"$NIM/src/lib" -p:"$NIM/src/nimony" -p:"$NIM/src/models" -p:"$NIM/src/gear2" \
  --nimcache="$SP/nc" "$SP/prog.nim" >/dev/null 2>&1
MAIN="$(find "$SP/nc" -maxdepth 1 -name 'pro*.s.nif' | head -1)"
[ -n "$MAIN" ] || { echo "could not build the check program"; exit 1; }
mkdir -p "$SP/mods"
for f in "$SP/nc"/*.s.nif; do [ "$f" = "$MAIN" ] || cp "$f" "$SP/mods/"; done

check() { # $1 = file to run, $2 = which harness ("jester" | "aowli")
  if [ "$2" = "jester" ]; then
    node tools/run-jester-host.mjs "$1" 2>&1
  else
    node tools/run-aowli-bundle.mjs "$1" "$MAIN" "$SP/mods" --runs 1 2>&1
  fi
}

for f in "${FILES[@]}"; do
  kind="aowli"; [[ "$f" == *jester-demo* ]] && kind="jester"
  echo "== $f"
  before="$(check "$f" "$kind")"
  echo "   before: $before"
  if [ "$CHECK_ONLY" = 1 ]; then continue; fi
  out="$SP/$(basename "$f")"
  npx -y javascript-obfuscator "$f" --output "$out" --config "$CFG" >/dev/null 2>&1
  after="$(check "$out" "$kind")"
  echo "   after:  $after"
  # Compare everything except medianMs (obfuscation itself changes timing).
  b="$(python3 -c "import json,sys; d=json.loads(sys.argv[1]); d.pop('medianMs',None); print(d)" "$before")"
  a="$(python3 -c "import json,sys; d=json.loads(sys.argv[1]); d.pop('medianMs',None); print(d)" "$after")"
  if [ "$b" != "$a" ]; then
    echo "REFUSING: $f behaves differently after obfuscation"
    echo "  before: $b"; echo "  after:  $a"
    exit 1
  fi
  before_sz="$(stat -c%s "$f")"; after_sz="$(stat -c%s "$out")"
  cp "$out" "$f"
  echo "   ok — identical behaviour, $before_sz -> $after_sz bytes"
done
echo "done"
