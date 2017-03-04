cmake_minimum_required(VERSION 3.6)
project(HW3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h)
add_executable(HW3 ${SOURCE_FILES})