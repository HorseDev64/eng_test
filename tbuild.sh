
#!/bin/sh

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"

cmake --build "$SCRIPT_DIR/build/"
"$SCRIPT_DIR/build/TestEngine"
