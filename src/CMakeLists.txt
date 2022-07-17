add_executable(kilo
    main.c
    input.c
    output.c
    terminal.c
    buffer.c
    fileio.c
    rowoperations.c
    editoroperations.c
    find.c
    )

target_include_directories(kilo PUBLIC ../includes)