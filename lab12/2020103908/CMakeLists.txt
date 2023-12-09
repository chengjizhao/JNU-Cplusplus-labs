cmake_minimum_required(VERSION 3.10)

project(MyLibraryExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(include)

# Source files
set(SOURCE_FILES
    src/name/my_library.cpp
    main.cpp
)

# Create a static library
add_library(MyLibrary STATIC ${SOURCE_FILES})

# Specify library output directory
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

# Create the executable
add_executable(main main.cpp)

# Link the executable with the library
target_link_libraries(main PRIVATE MyLibrary)
