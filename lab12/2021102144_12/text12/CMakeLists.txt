cmake_minimum_required(VERSION 3.15)#确认版本

project(libcheng)#名称

aux_source_directory(src/cheng LIB_SRC_FILES)#	这行代码将src/cheng目录下的所有源文件添加到变量LIB_SRC_FILES中。这通常用于自动收集源文件。

include_directories("./include/cheng")#这行代码为项目添加了一个头文件搜索路径，即./include/cheng。

add_library(cheng STATIC ${LIB_SRC_FILES})#这行代码定义了一个名为cheng的静态库，并使用${LIB_SRC_FILES}中的源文件来构建它。

add_executable(text12 text12_main.cpp)#这行代码定义了一个名为text12的可执行文件，并使用text12_main.cpp作为其源文件。

target_link_libraries(text12 cheng)#这行代码将cheng库链接到demo可执行文件中。
target_link_libraries(text12 -static-libstdc++) #静态连接标准库

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#这行代码设置了静态库的输出路径为${PROJECT_BINARY_DIR}/lib，其中${PROJECT_BINARY_DIR}是CMake项目二进制目录的变量。

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)#这行代码设置了可执行文件的输出路径为${PROJECT_BINARY_DIR}/bin。