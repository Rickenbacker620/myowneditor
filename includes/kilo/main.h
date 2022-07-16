#pragma once

#include "termios.h"

#include <time.h>

#define CTRL_KEY(k) ((k)&0x1f)
#define KILO_TAB_STOP 8

enum editorKey
{
    ARROW_LEFT = 1000,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    DEL_KEY,
    HOME_KEY,
    END_KEY,
    PAGE_UP,
    PAGE_DOWN
};

#define KILO_VERSION "0.0.1"

typedef struct erow
{
    int size;
    int rsize;
    char *chars;
    char *render;
} erow;

struct editorConfig
{
    int cx, cy;
    int rx;
    int rowoff;
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct termios orig_termios;
};

struct abuf
{
    char *b;
    int len;
};

// clang-format off
#define ABUF_INIT  { NULL, 0 }
// clang-format on