cmake_minimum_required(VERSION 3.12)
project(MyProject)
aux_source_directory(src/Shape LIB_SRC)
include_directories("./include/Shape")
add_library(shape STATIC ${LIB_SRC})
add_executable(main main.cpp)
target_link_libraries(main shape)
target_link_libraries(main -static-libstdc++)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)