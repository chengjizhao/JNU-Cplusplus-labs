#版本要求
cmake_minimum_required(VERSION 3.12)
#项目
project(namee)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加静态库的源文件，库文件
set(LIB_SOURCES    SRC/myname.cpp)
set(LIB_HEADERS    Include/myname.h)

# 生成静态库
add_library(myname STATIC ${LIB_SOURCES} ${LIB_HEADERS})

# 设置静态库的输出路径
set_target_properties(myname PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Build/lib)
    
# 添加可执行文件目标
add_executable(you main.cpp)
# 添加可执行文件依赖的静态库
target_link_libraries(you PRIVATE myname)
# 添加头文件搜索路径
target_include_directories(you PRIVATE Include)