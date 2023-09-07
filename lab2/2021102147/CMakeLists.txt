cmake_minimum_required(VERSION 3.15)

message(WARNING "此项目在Windows上使用MSVC和GCC编译均不会出现乱码，但在Linux上大概率出现乱码")

PROJECT(StudentManager)

set(CMAKE_EXE_LINKER_FLAGS -static)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=gbk>")

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS})