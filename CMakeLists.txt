cmake_minimum_required(VERSION 3.10)

# Habilita siempre la generación de compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(TestEngine C CXX)

add_subdirectory(deps/glfw-3.4)

file(GLOB SOURCES "src/*.c")

add_executable(TestEngine ${SOURCES})



target_include_directories(TestEngine PRIVATE include)
target_include_directories(TestEngine PRIVATE deps/glfw_3.4/include)

target_link_libraries(TestEngine PRIVATE glfw)

