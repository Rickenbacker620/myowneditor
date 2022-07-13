#ifndef __MAIN_H__
#define __MAIN_H__

#include "termios.h"

#define CTRL_KEY(k) ((k)&0x1f)

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
    char *chars;
} erow;

struct editorConfig
{
    int cx, cy;
    int screenrows;
    int screencols;
    int numrows;
    erow row;
    struct termios orig_termios;
};


#endif