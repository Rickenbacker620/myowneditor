#pragma once
#include "kilo/main.h"

void editorScroll();

void editorRefreshScreen();

void editorDrawRows(struct abuf *ab);

void editorSetStatusMessage(const char *fmt, ...);

void editorDrawMessageBar(struct abuf *ab);