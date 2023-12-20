cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(text01 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/include/name)

file(GLOB ALL_SOURCE src/hello_main.cpp)
message(STATUS "All Source : ${ALL_SOURCE}")
add_library(hello STATIC src/name/hello.cpp)

add_executable(my_hello ${ALL_SOURCE}) 
set_target_properties(hello PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

target_link_libraries(my_hello hello)