cmake_minimum_required(VERSION 3.10)
project(cache C)

set(CMAKE_C_STANDARD 99)

set(cache csim.c cachelab.c)
add_executable(cache csim.c)