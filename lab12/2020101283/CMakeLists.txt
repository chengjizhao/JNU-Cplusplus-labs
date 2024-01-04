cmake_minimum_required(VERSION 3.0)
project(example)

# 设置源文件和头文件的目录
set(SOURCES src/name/source_file.cpp)
set(HEADERS include/name/header_file.h)

# 设置生成的库的名称和路径
set(LIB_NAME example_lib)
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

# 添加头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 生成静态库
add_library(${LIB_NAME} STATIC ${SOURCES} ${HEADERS})

# 设置库文件输出路径
set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_PATH}
)

# 设置可执行文件依赖该库
add_executable(example_executable main.cpp)
target_link_libraries(example_executable ${LIB_NAME})
