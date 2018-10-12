cmake_minimum_required(VERSION 3.11)
project(gVM2_C C)

set(CMAKE_C_STANDARD 99)

set(common_header gutils.h)

add_library(memory ${common_header} gvm-machine/memory.h gvm-machine/memory.c)

add_executable(gvm ${common_header} main.c)
target_link_libraries(gvm memory)