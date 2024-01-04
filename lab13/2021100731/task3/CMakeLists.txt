cmake_minimum_required(VERSION 3.5.0)
project(lib_create VERSION 0.1.0 LANGUAGES C CXX)


aux_source_directory(${PROJECT_SOURCE_DIR}/src/. ALL_SRCS)              #包含源文件

include_directories(${PROJECT_SOURCE_DIR}/include/)                     #包含头文件

add_executable(test ${ALL_SRCS})                                        #生成可执行文件


