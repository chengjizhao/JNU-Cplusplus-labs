cmake_minimum_required(VERSION 3.15)

project(libbinary)

aux_source_directory(src/Binary SRC_FILES)

include_directories("./include/Binary")

add_library(binary STATIC ${SRC_FILES})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)