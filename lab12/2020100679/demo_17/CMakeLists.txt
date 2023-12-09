cmake_minimum_required(VERSION 3.5)

project(MyMathLibrary)

# 设置 C++ 标准版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 将库源文件编译成静态库
add_library(math_functions STATIC src/name/math_functions.cpp)

# 编译可执行文件，并链接静态库
add_executable(main src/name/main.cpp)
target_link_libraries(main math_functions)

# 为库和可执行文件指定包含的头文件路径
target_include_directories(math_functions PUBLIC include)
target_include_directories(main PUBLIC include)

# 设置库的输出路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib)

# 设置可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)