cmake_minimum_required(VERSION 3.6)
project(dz1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h tesr.c)
add_executable(dz1 ${SOURCE_FILES})