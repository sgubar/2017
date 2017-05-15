cmake_minimum_required(VERSION 3.6)
project(LW4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h dk_checker.h dk_checker.c)
add_executable(LW4 ${SOURCE_FILES})