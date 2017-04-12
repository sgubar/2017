cmake_minimum_required(VERSION 3.6)
project(LW3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.h dk_tool.c sort.h sort.c search.c search.h)
add_executable(LW3 ${SOURCE_FILES})