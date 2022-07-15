#include "kilo/output.h"

#include "kilo/buffer.h"
#include "kilo/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern struct editorConfig E;

void editorScroll()
{
    if (E.cy < E.rowoff) // cursor go out of bound(up)
    {
        E.rowoff = E.cy;
    }
    if (E.cy >= E.rowoff + E.screenrows) // cursor go out of bound(down)
    {
        E.rowoff = E.cy - E.screenrows + 1;
    }
    if (E.cx < E.coloff) // cursor go out of bound(left)
    {
        E.coloff = E.cx;
    }
    if (E.cx >= E.coloff + E.screencols) // cursor go out of bound(right)
    {
        E.coloff = E.cx - E.screencols + 1;
    }
}

void editorRefreshScreen()
{
    editorScroll();

    struct abuf ab = ABUF_INIT;

    abAppend(&ab, "\x1b[?25l", 6);
    abAppend(&ab, "\x1b[H", 3);

    editorDrawRows(&ab);

    char buf[32];
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy - E.rowoff) + 1, (E.cx - E.coloff) + 1);
    abAppend(&ab, buf, strlen(buf));

    abAppend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.b, ab.len);
    abFree(&ab);
}

void editorDrawRows(struct abuf *ab)
{
    int y;
    for (y = 0; y < E.screenrows; y++)
    {
        int filerow = y + E.rowoff;
        if (filerow >= E.numrows)
        {
            if (E.numrows == 0 && y == E.screenrows / 3)
            {
                char welcome[80];
                int welcomelen = snprintf(welcome, sizeof(welcome), "Kilo editor -- version %s", KILO_VERSION);
                if (welcomelen > E.screencols)
                    welcomelen = E.screencols;
                int padding = (E.screencols - welcomelen) / 2;
                if (padding)
                {
                    abAppend(ab, "~", 1);
                    padding--;
                }
                while (padding--)
                    abAppend(ab, " ", 1);
                abAppend(ab, welcome, welcomelen);
            }
            else
            {
                abAppend(ab, "~", 1);
            }
        }
        else
        {
            int len = E.row[filerow].size - E.coloff;
            if (len < 0)
                len = 0;
            if (len > E.screencols) // display columns less than window size
                len = E.screencols;
            abAppend(ab, &E.row[filerow].chars[E.coloff], len);
        }
        abAppend(ab, "\x1b[K", 3);
        if (y < E.screenrows - 1)
        {
            abAppend(ab, "\r\n", 2);
        }
    }
}