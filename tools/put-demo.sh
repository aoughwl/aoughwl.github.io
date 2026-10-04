#!/usr/bin/env bash
# Push the gated demo assets to R2, where the licence Worker serves them from.
#
# The playground fetches jester-payload.json and jester-sdk.json from the Worker
# (GET /api/v1/demo/asset/<name>), which reads them out of the `aowl-artifacts`
# bucket. They are deliberately NOT static files on the site (see
# public/playground/.gitignore), so after rebuilding them with
# tools/pack-jester-payload.mjs you must push them here for the live demo to see
# the new bytes.
#
# Needs a wrangler already authenticated to the aoughwl Cloudflare account (the
# same one that deploys aowl-store). --remote targets the real bucket, not the
# local miniflare one.
set -euo pipefail

here="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
pg="$here/public/playground"
bucket="aowl-artifacts"

put() {
  local src="$1" key="$2"
  [ -f "$src" ] || { echo "missing: $src (run tools/pack-jester-payload.mjs first)" >&2; exit 1; }
  echo "→ $key  ($(wc -c < "$src") bytes)"
  wrangler r2 object put "$bucket/$key" --file "$src" \
    --content-type "application/json" --remote
}

put "$pg/jester-payload.json"      "demo/jester-payload.json"
put "$pg/assets/jester-sdk.json"   "demo/jester-sdk.json"

echo "done. the live demo now serves these through the Worker."
