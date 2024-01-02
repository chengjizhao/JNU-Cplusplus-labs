# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCES 
    src/name/mylib.cpp
    main.cpp
)

# Include directories
include_directories(include)

# Create static library
add_library(mylib STATIC ${SOURCES})

# Set output paths
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib)

# Create executable
add_executable(main ${SOURCES})

# Link executable with the library
target_link_libraries(main mylib)
