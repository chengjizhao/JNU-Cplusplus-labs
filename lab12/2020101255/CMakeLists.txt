cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

set(LIB_SOURCES    SRC/name1.cpp)
set(LIB_HEADERS    Include/name1.h)


add_library(name1 STATIC ${LIB_SOURCES} ${LIB_HEADERS})

# 设置静态库的输出路径
set_target_properties(name1 PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/lib)


add_executable(main main.cpp)

# 添加可执行文件依赖的静态库
target_link_libraries(main PRIVATE name1)
# 添加头文件搜索路径
target_include_directories(main PRIVATE Include)
