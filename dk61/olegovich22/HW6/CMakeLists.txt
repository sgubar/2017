cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c dk_tool.c dk_tool.h sortValues.h sortValues.c sortPointers.c sortPointers.h dk_list.c dk_list.h)
add_executable(HW6 ${SOURCE_FILES})