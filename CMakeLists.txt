cmake_minimum_required(VERSION 3.0.0)
project(kilo VERSION 0.1.0)

add_custom_target(
    format
    COMMAND ${PROJECT_SOURCE_DIR}/format.sh
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

set(CMAKE_C_FLAGS_DEBUG "-g -Werror -Wall -Wextra")

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)

add_subdirectory(src)

add_dependencies(kilo format)
