cmake_minimum_required(VERSION 3.6)
project(LW5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h dk_tree.h dk_tree.c wayList.h wayList.c)
add_executable(LW5 ${SOURCE_FILES})