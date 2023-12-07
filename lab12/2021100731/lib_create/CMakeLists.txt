cmake_minimum_required(VERSION 3.5.0)
project(lib_create VERSION 0.1.0 LANGUAGES C CXX)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)                #更改静态库输出位置

aux_source_directory(${PROJECT_SOURCE_DIR}/src/. ALL_SRCS)              #包含源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src/add/. ALL_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/include/add)                  #包含头文件

add_library(add_static STATIC ${PROJECT_SOURCE_DIR}/src/add/add.cpp)    #生成静态库
#target_include_directories(add_static PUBLIC ${PROJECT_SOURCE_DIR}/include/add)

add_executable(main ${ALL_SRCS})                                        #生成可执行文件

target_link_libraries(main PRIVATE add_static)                          #链接文件与静态库



