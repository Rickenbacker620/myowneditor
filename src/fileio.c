#include "kilo/fileio.h"

#include "kilo/main.h"
#include "kilo/rowoperations.h"
#include "kilo/terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct editorConfig E;

void editorOpen(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
        die("fopen");
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, fp)) != -1)
    {
        while (linelen > 0 && (line[linelen - 1] == '\n' || line[linelen - 1] == '\r')) // strip return
            linelen--;
        editorAppendRow(line, linelen);
    }
    free(line);
    fclose(fp);
}