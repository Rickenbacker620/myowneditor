#pragma once

#include "kilo/main.h"

#include <stddef.h>

int editorRowCxToRx(erow *row, int cx);

void editorUpdateRow(erow *row);

void editorAppendRow(char *s, size_t len);

void editorRowInsertChar(erow *row, int at, int c);