cmake_minimum_required(VERSION 3.0.0)
project(kilo VERSION 0.1.0)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall -Wextra")

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)

add_subdirectory(src)
