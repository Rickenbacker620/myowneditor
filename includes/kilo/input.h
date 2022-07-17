#pragma once

int editorReadKey();

void editorProcessKeypress();

void editorMoveCursor(int key);

char *editorPrompt(char *prompt, void (*callback)(char *, int));