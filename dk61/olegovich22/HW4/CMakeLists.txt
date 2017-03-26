cmake_minimum_required(VERSION 3.6)
project(HW4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sort.c dk_tool.c sort.h dk_tool.h sort_using_square.c main_using_bubblesort.c)
add_executable(HW4 ${SOURCE_FILES})