#pragma once
#include "kilo/main.h"

void abAppend(struct abuf *ab, const char *s, int len);

void abFree(struct abuf *ab);