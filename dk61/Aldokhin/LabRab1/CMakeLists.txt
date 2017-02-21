cmake_minimum_required(VERSION 3.6)
project(LabRab1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c tools.h calculat.c read.c)
add_executable(LabRab1 ${SOURCE_FILES})