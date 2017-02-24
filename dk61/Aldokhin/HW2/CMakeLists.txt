cmake_minimum_required(VERSION 3.6)
project(HW2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.h dk_tool.c)
add_executable(HW2 ${SOURCE_FILES})