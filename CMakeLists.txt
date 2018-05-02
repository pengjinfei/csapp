cmake_minimum_required(VERSION 3.10)
project(csapp C)

set(CMAKE_C_STANDARD 99)

add_executable(csapp main.c)
add_subdirectory(lib)
target_link_libraries(csapp lib)
