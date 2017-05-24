cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c Tool.c Tool.h)
add_executable(HW6 ${SOURCE_FILES})