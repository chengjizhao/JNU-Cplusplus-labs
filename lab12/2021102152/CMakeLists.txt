cmake_minimum_required(VERSION 3.5.0)
project(lib_add VERSION 0.1.0 LANGUAGES C CXX)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)              

aux_source_directory(${PROJECT_SOURCE_DIR}/src/. ALL_SRCS)            
aux_source_directory(${PROJECT_SOURCE_DIR}/src/name/. ALL_SRCS)

include_directories(${PROJECT_SOURCE_DIR}/include/name)               

add_library(add_static STATIC ${PROJECT_SOURCE_DIR}/src/name/lib_add.cpp)  
#target_include_directories(add_static PUBLIC ${PROJECT_SOURCE_DIR}/include/add)

add_executable(main ${ALL_SRCS})                                     

target_link_libraries(main PRIVATE add_static)                     
