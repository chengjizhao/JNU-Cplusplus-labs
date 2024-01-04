cmake_minimum_required(VERSION 3.5)
project(PersonAddressDemo)

set(CMAKE_CXX_STANDARD 14)

# 设置头文件目录
include_directories(include)

# 添加源文件
set(SOURCE_FILES source/main.cpp source/Person.cpp source/Address.cpp)

add_executable(PersonAddressDemo ${SOURCE_FILES})