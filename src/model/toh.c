#include <stdlib.h>
#include <toh.h>
#include <stack.h>
#include <window.h>
#include <disk.h>
#include <constants.h>
#include <ai.h>

TOH *new_TOH(int n)
{
    TOH *t = (TOH *)malloc(sizeof(TOH));
    t->disks = n;
    t->height = ((600.0 / n) < 80) ? 600.0 / (n) : 80;
    t->game = new_Game(n, solve_ai, t->height);
    t->window = new_Window(0, 0, 810, 675);
    return t;
}

void setupGame(TOH *t)
{
    double i = 0;
    //Outer radius
    double or = 280;
    //y Coordinate
    double y = 50;
    //Color for the disk
    Color col;
    for (; i < t->disks; ++i)
    {
        col[0] = (rand() % 200) / 255.0;
        col[1] = (rand() % 200) / 255.0;
        col[2] = (rand() % 200) / 255.0;
        push(t->game->poles[Source], *(new_Disk(SourceX, y, or, t->height, col)));
        y += t->height;
        or -= (270 / t->disks);
    }
}
