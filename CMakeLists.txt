cmake_minimum_required(VERSION 3.12)
project(gVM2_C C)

set(CMAKE_C_STANDARD 99)

add_library(memory gvm-machine/memory.h gvm-machine/memory.c)

add_executable(gvm main.c)
target_link_libraries(gvm memory)