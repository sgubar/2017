cmake_minimum_required(VERSION 3.6)
project(LW2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h cmake-build-debug/test.c sortbyoleg.c sort.c sort.h)
add_executable(LW2 ${SOURCE_FILES})