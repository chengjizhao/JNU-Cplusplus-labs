cmake_minimum_required(VERSION 3.0)
project(Complex)

set(CMAKE_CXX_STANDARD 11)

# 添加源文件
file(GLOB SOURCES src/*.cpp)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")