cmake_minimum_required(VERSION 3.6)
project(HW7)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h dk_tree.c dk_tree.h)
add_executable(HW7 ${SOURCE_FILES})