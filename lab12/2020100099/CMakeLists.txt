# 设置CMake的版本信息  
cmake_minimum_required(VERSION 3.10)  
  
# 设置项目的名称和版本  
project(library VERSION 1.0.0)  
  
# 设置构建类型为库文件  
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)  
  
# 将源代码添加到项目中  
aux_source_directory(include SRC_FILES)  

# 将头文件添加到项目中  
include_directories(src)  
  
# 创建一个可执行文件，它依赖于我们的库  
add_executable(program ${SRC_FILES})  
  
# 链接到我们的库  
target_link_libraries(program library)