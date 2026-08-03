#!/bin/sh

SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"


cmake --build "$SCRIPT_DIR/build/"

gdb -x "$SCRIPT_DIR/.gdb_breakpoints" "$SCRIPT_DIR/build/TestEngine"
