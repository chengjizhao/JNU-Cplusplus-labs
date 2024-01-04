cmake_minimum_required(VERSION 3.28.1)
project(task1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Source files
set(SOURCE_FILES
    src/name/task1.cpp
    main.cpp
)

# Header files
set(HEADER_FILES
    include/name/task1.h
)

# Create library
add_library(task1_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Specify include directories
target_include_directories(task1_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Create executable
add_executable(task1_app main.cpp)

# Link executable with the library
target_link_libraries(task1_app PRIVATE task1_lib)

# Specify output directory for both library and executable
set_target_properties(task1_lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
set_target_properties(task1_app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)