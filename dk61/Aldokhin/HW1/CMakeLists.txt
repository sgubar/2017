cmake_minimum_required(VERSION 3.6)
project(untitled4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.h dk_tool.c)
add_executable(untitled4 ${SOURCE_FILES})