#include "kilo/editoroperations.h"

#include "kilo/main.h"
#include "kilo/rowoperations.h"

extern struct editorConfig E;

void editorInsertChar(int c)
{
    if (E.cy == E.numrows)
    {
        editorAppendRow("", 0);
    }
    editorRowInsertChar(&E.row[E.cy], E.cx, c);
    E.cx++;
}