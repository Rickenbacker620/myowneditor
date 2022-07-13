#pragma once
#include "kilo/main.h"

void die(const char *s);

void disableRawMode();

void enableRawMode();

int getWindowSize(int *rows, int *cols);

int getCursorPosition(int *rows, int *cols);

void abAppend(struct abuf *ab, const char *s, int len);

void abFree(struct abuf *ab);