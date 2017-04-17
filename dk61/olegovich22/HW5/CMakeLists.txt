cmake_minimum_required(VERSION 3.6)
project(HW5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h sort.h sort.c search.h search.c)
add_executable(HW5 ${SOURCE_FILES})