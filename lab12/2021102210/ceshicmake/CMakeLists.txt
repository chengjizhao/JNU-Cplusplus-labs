cmake_minimum_required(VERSION 3.15)
project(SortMake)
set(SRC functionh.cpp helloword.cpp)
set(HEAD head.h ./include/name)
add_executable(iwanttofindthisfile ${SRC})
include_directories(${HEAD})
add_library(calc STATIC ${SRC})


