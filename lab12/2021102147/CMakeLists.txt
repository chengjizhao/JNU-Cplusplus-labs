cmake_minimum_required(VERSION 3.15)

project(libbinary)

aux_source_directory(src/Binary LIB_SRC_FILES)

include_directories("./include/Binary")

add_library(binary STATIC ${LIB_SRC_FILES})

add_executable(demo demo.cpp)

target_link_libraries(demo binary)
target_link_libraries(demo -static-libstdc++) #静态连接标准库

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
