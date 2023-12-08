cmake_minimum_required(VERSION 3.12)

project(MyProject)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    src/name/mylib.cpp
    src/main.cpp
)

set(HEADERS
    include/name/mylib.h
)

add_library(mylib STATIC ${SOURCES} ${HEADERS})

target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(mylib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib
)

add_executable(myexecutable src/main.cpp)

target_link_libraries(myexecutable PRIVATE mylib)