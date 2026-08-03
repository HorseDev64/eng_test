#!/bin/bash

# Obtener el directorio del script de forma segura
SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"

cmake -S "$SCRIPT_DIR" -B "$SCRIPT_DIR/build" \
  -DCMAKE_BUILD_TYPE=Debug \
  -DGLFW_BUILD_WAYLAND=ON \
  -DGLFW_BUILD_X11=ON \
  -DBUILD_SHARED_LIBS=OFF 

