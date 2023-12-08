# CMakeLists.txt

# 设置项目名称
project(MyProject)

# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 设置源文件路径
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 设置静态库名称
set(LIB_NAME mylib)

# 收集源文件
file(GLOB SRC_FILES ${SRC_DIR}/name/*.cpp)

# 收集头文件
file(GLOB HEADER_FILES ${INCLUDE_DIR}/name/*.h)

# 生成静态库
add_library(${LIB_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})

# 设置库的输出路径
set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib
)

# 设置可执行文件名称
set(EXE_NAME myapp)

# 指定可执行文件的源文件
set(EXE_SRC ${SRC_DIR}/main.cpp)

# 生成可执行文件
add_executable(${EXE_NAME} ${EXE_SRC})

# 链接静态库到可执行文件
target_link_libraries(${EXE_NAME} PRIVATE ${LIB_NAME})

# 设置可执行文件的输出路径
set_target_properties(${EXE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}
)
