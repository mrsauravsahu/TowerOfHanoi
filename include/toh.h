#ifndef TOH_TOH_H
#define TOH_TOH_H

#include <stack.h>
#include <window.h>
#include <game.h>

typedef struct
{
    Game *game;
    Window *window;
    int disks;
    double height;
} TOH;

TOH *new_TOH();
void setupGame(TOH *);

#endif