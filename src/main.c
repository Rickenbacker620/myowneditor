#include "kilo/main.h"

#include "kilo/fileio.h"
#include "kilo/input.h"
#include "kilo/output.h"
#include "kilo/terminal.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define _GNU_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

struct termios orig_termios;
struct editorConfig E;

void initEditor()
{
    E.cx = 0;
    E.cy = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
        die("getWindowSize");
}

int main(int argc, char *argv[])
{
    enableRawMode();
    initEditor();

    editorOpen("../texts/horay");
    // if (argc >= 2)
    // {
    //     editorOpen(argv[1]);
    // }

    while (1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    }

    return 0;
}