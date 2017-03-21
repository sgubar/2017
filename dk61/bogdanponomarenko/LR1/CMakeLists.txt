cmake_minimum_required(VERSION 3.6)
project(untitled1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c
        dk_tool.c
        dk_tool.h )
add_executable(untitled1 ${SOURCE_FILES})