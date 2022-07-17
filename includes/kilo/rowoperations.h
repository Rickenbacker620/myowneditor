#pragma once

#include "kilo/main.h"

#include <stddef.h>

int editorRowCxToRx(erow *row, int cx);

int editorRowRxToCx(erow *row, int rx);

void editorUpdateRow(erow *row);

void editorInsertRow(int at, char *s, size_t len);

void editorRowInsertChar(erow *row, int at, int c);

void editorRowDelChar(erow *row, int at);

void editorDelRow(int at);

void editorRowAppendString(erow *row, char *s, size_t len);
