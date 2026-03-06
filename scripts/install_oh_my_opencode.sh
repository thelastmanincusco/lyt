#!/usr/bin/env bash
set -euo pipefail

INSTALL_DOC_URL="https://raw.githubusercontent.com/code-yeongyu/oh-my-opencode/refs/heads/dev/docs/guide/installation.md"
TMP_DOC="$(mktemp)"

cleanup() {
  rm -f "$TMP_DOC"
}
trap cleanup EXIT

echo "Fetching installation guide from: $INSTALL_DOC_URL"
if ! curl -fsSL "$INSTALL_DOC_URL" -o "$TMP_DOC"; then
  echo "ERROR: Unable to fetch installation guide (network/policy restriction)." >&2
  echo "Please run this script in an environment with access to raw.githubusercontent.com." >&2
  exit 1
fi

echo "Guide downloaded to $TMP_DOC"
echo "First 40 lines:"
sed -n '1,40p' "$TMP_DOC"

echo "\nNOTE: This helper intentionally stops here because the installation guide may change over time."
echo "Use the downloaded guide content as source-of-truth for the exact installation/configuration commands."
