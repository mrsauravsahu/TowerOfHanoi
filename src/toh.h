#ifndef TOH_TOH_H
#define TOH_TOH_H

#include "stack.h"
#include "window.h"

typedef struct
{
    Stack *source, *aux, *dest;
    Window *window;
    int disks;
} TOH;

TOH *new_TOH();
void setupGame(TOH *t);

#endif