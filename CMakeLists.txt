cmake_minimum_required(VERSION 3.10)
project(csapp C)

set(CMAKE_C_STANDARD 99)

#add_executable(csapp main.c)
#add_subdirectory(lib)
#add_subdirectory(labs)
#target_link_libraries(csapp lib)
set(BUILD_DIR ./labs/shell)  #设置编译目录,也就是Makefile文件所在目录
message(${BUILD_DIR}) #打印目录路径
add_custom_target(tsh COMMAND make -C ${BUILD_DIR}) #最关键的就是这句, 设置外部编译文件而不是使用CMakeLists.txt
add_executable(csapp ./labs/shell/tsh.c)