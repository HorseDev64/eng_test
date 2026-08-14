#!/bin/bash

# Obtener el directorio del script de forma segura
SCRIPT_DIR="$(cd -- "$(dirname -- "$0")" && pwd)"

# 1. Crear directorio de build para glfw (usando $SCRIPT_DIR y -p)
mkdir -p "$SCRIPT_DIR/deps/glfw-3.4/build"

# 2. Configurar glfw
# Nota: Se pasa el directorio como primer argumento y las banderas separadas
cmake -S "$SCRIPT_DIR/deps/glfw-3.4" -B "$SCRIPT_DIR/deps/glfw-3.4/build" \
  -DGLFW_BUILD_WAYLAND=ON \
  -DGLFW_BUILD_X11=ON \
  -DBUILD_SHARED_LIBS=OFF \
  -DGLFW_BUILD_EXAMPLES=OFF \
  -DGLFW_BUILD_TESTS=OFF \
  -DGLFW_BUILD_DOCS=OFF

# 3. Configurar tu proyecto principal
cmake -S "$SCRIPT_DIR" -B "$SCRIPT_DIR/build" \
  -DGLFW_BUILD_WAYLAND=ON \
  -DGLFW_BUILD_X11=ON \
  -DBUILD_SHARED_LIBS=OFF 
