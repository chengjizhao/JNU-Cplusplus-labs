cmake_minimum_required(VERSION 3.10)
   
project(name VERSION 1.0)  
    
set(SOURCE_FILES src/name/mylib.cpp include/name/mylib.h)  
  
include_directories(${PROJECT_SOURCE_DIR}/include/name)  
    
add_library(name ${SOURCE_FILES})  
  
add_executable(your_executable_name your_executable_source.cpp)  
target_link_libraries(your_executable_name name)