cmake_minimum_required(VERSION 3.12)
project(static_library)

# 设置C++标准为C++11
set(CMAKE_CXX_STANDARD 11)

# 设置库的名称和源文件
set(LIBRARY_NAME library)
set(SOURCE_FILES src/name/library.cpp)

# 设置头文件路径
include_directories(include/name)

# 生成静态库
add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES})

# 设置库文件输出路径
set_target_properties(${LIBRARY_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib
)

# 添加可执行文件
add_executable(my_executable src/main.cpp)

# 链接库文件
target_link_libraries(my_executable ${LIBRARY_NAME})