#ifndef PAGE_TOH_H
#define PAGE_TOH_H

#include <malloc.h>

typedef struct
{
    void (*display)();
} Page;

Page *new_Page(void (*disp)())
{
    Page *p = (Page *)malloc(sizeof(Page));
    p->display = disp;
    return p;
}

#endif