# Build Instructions

This document explains how to build the project and its dependencies using **CMake** on both **Windows** and **Linux (WSL)**.

---

## 🪟 Windows (MinGW)

### 1️⃣ Build GLFW

From the `glfw` directory:

```bash
cd glfw
mkdir build
cd build
```

Configure GLFW:

```bash
cmake .. -G "MinGW Makefiles" ^
  -DBUILD_SHARED_LIBS=OFF ^           # optional
  -DGLFW_BUILD_EXAMPLES=OFF ^
  -DGLFW_BUILD_TESTS=OFF ^
  -DGLFW_BUILD_DOCS=OFF
```

---

### 2️⃣ Build the main project

From the **root project directory**:

```bash
cmake -S . -B build
cd build
cmake --build .
```

---

###  Windows from WSL (Croos-Compilation: not recommended for debugging, or at least idk how to do it if you do help me please im suffering) 

### Install dependencies

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  cmake \
  pkg-config \
  libx11-dev \
  libxrandr-dev \
  libxinerama-dev \
  libxcursor-dev \
  libxi-dev \
  libxkbcommon-dev \
  libwayland-dev \
  wayland-protocols \
  libegl1-mesa-dev \
  libgl1-mesa-dev
```

### Build GLFW

### Requirements: have installed previously MinGW FROM WSL
### (Using MinGW from windows gives problems, i think, i dunno and im > 
### willing to try it)

```bash

sudo apt update
sudo apt install -y mingw-w64
```

```bash
cmake -S . -B build \
  -DCMAKE_SYSTEM_NAME=Windows \
  -DCMAKE_C_COMPILER=/usr/bin/x86_64-w64-mingw32-gcc \
  -DCMAKE_CXX_COMPILER=/usr/bin/x86_64-w64-mingw32-g++
```

### from ROOT

```bash
cmake -S . -B build \
  -DCMAKE_SYSTEM_NAME=Windows \
  -DCMAKE_C_COMPILER=/usr/bin/x86_64-w64-mingw32-gcc \
  -DCMAKE_CXX_COMPILER=/usr/bin/x86_64-w64-mingw32-g++

cd build
cmake --build .
 -DGLFW_BUILD_DOCS=OFF
```


## 🐧 Linux/WSL  

### Install dependencies


```bash
sudo apt update
sudo apt install -y \
  build-essential \
  cmake \
  pkg-config \
  libx11-dev \
  libxrandr-dev \
  libxinerama-dev \
  libxcursor-dev \
  libxi-dev \
  libxkbcommon-dev \
  libwayland-dev \
  wayland-protocols \
  libegl1-mesa-dev \
  libgl1-mesa-dev
```


### 1️⃣ Build GLFW
From the **glfw directory**

```bash
cd deps/glfw_3.4/
mkdir build
cd build
```

Configure GLFW (if you are on WSL set the -DGLFW_BUILD_WAYLAND to False):

```bash

cmake .. -DGLFW_BUILD_WAYLAND=ON -DGLFW_BUILD_X11=ON -DBUILD_SHARED_LIBS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_DOCS=OFF

```

---
### 2️⃣ Build the main project
 
From the **root project directory**:

```bash
cmake -S . -B  build\
  -DGLFW_BUILD_WAYLAND=ON \
  -DGLFW_BUILD_X11=ON \
  -DBUILD_SHARED_LIBS=OFF

cd build
cmake --build .
```

---

## ⚠️ Notes
- For debugging add this flag in the cmake -S ... :  -DCMAKE_BUILD_TYPE=Debug
- On **WSL**, Wayland is disabled to avoid missing dependencies.
- If you change CMake options, always delete the `build_*` directory before reconfiguring.
```



