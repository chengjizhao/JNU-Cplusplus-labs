cmake_minimum_required(VERSION 3.5.0)

project(Person_Address VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/
)

add_library(${PROJECT_NAME} SHARED
        src/main.cpp
)

add_executable(runtest src/main.cpp)