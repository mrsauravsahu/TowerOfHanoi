#ifndef GAME_TOH_H
#define GAME_TOH_H

#include <stack.h>

struct __Game__
{
    Stack **poles;
    int disks;
    void (*solve)(struct __Game__ *);
    double height;
};
typedef struct __Game__ Game;

Game *new_Game(int disks, void (*solve)(Game *), double height);

#endif