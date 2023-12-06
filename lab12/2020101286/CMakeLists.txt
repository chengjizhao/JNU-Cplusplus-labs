cmake_minimum_required(VERSION 3.0) 
project(MathLibrary)

# 设置项目的头文件路径
include_directories(include)

# 设置生成的库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

# 生成静态库
add_library(math STATIC src/math/operations.cpp)

# 添加可执行文件
add_executable(math_app app/main.cpp)

# 可执行文件依赖于生成的库
target_link_libraries(math_app math)