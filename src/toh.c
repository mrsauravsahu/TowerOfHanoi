#include "toh.h"
#include "stack.h"
#include "window.h"
#include "disk.h"
#include "constants.h"

TOH *new_TOH(int n)
{
    TOH *t = (TOH *)malloc(sizeof(TOH));
    t->disks = n;
    t->source = new_Stack(n);
    t->aux = new_Stack(n);
    t->dest = new_Stack(n);
    t->window = new_Window(0, 0, 1000, 750);
    return t;
}

void setupGame(TOH *t)
{
    double i = 0;
    //Outer radius
    double or = 280;
    //y Coordinate
    double y = 50;
    //Height
    double height = (600.0 / (t->disks) < 100) ? 600.0 / (t->disks) : 100;
    for (; i < t->disks; ++i)
    {
        push(t->source, *(new_Disk(SourceX, y, or, height)));
        y += height;
        or -= (or *0.2);
    }
}