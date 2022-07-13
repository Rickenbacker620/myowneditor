add_executable(kilo input.c main.c output.c terminal.c buffer.c)

target_include_directories(kilo PUBLIC ../includes)