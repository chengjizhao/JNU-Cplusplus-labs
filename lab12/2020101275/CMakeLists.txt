cmake_minimum_required(VERSION 3.5)

# 项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置头文件目录
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# 设置库文件输出路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/library)

# 添加静态库
add_library(mylib STATIC src/name/mylibrary.cpp)

# 添加可执行文件
add_executable(myapp main.cpp)

# 链接静态库
target_link_libraries(myapp mylibrary)

# 包含头文件目录
target_include_directories(mylib PUBLIC ${INCLUDE_DIR})