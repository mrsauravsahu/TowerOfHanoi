#include "toh.h"
#include "stack.h"
#include "window.h"
#include "disk.h"

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
    int i = 0;
    for (; i < t->disks; ++i)
    {
        push(t->source, *(new_Disk()));
    }
}