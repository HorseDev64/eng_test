cmake_minimum_required(VERSION 3.10)

project(TestEngine C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(deps/glfw-3.4)
add_subdirectory(deps/glad)

file(GLOB SOURCES "src/*.c")

add_executable(TestEngine ${SOURCES})

target_include_directories(TestEngine PRIVATE include)
target_include_directories(TestEngine PRIVATE deps/stb)

target_link_libraries(TestEngine PRIVATE
    glfw
    glad
)





# OLD CMAKE LISTS (JUST IN CASE)





#
#cmake_minimum_required(VERSION 3.10)
#
## Habilita siempre la generación de compile_commands.json
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#project(TestEngine C CXX)
#
#add_subdirectory(deps/glfw-3.4)
#add_subdirectory(deps/glad)
#
#file(GLOB SOURCES "src/*.c")
#
#add_executable(TestEngine ${SOURCES})
#
#
#
#target_include_directories(TestEngine PRIVATE include)
#target_include_directories(TestEngine PRIVATE deps/glfw_3.4/include)
#target_include_directories(TestEngine PRIVATE deps/glad/include)
#
#target_link_libraries(TestEngine PRIVATE glfw)
#
