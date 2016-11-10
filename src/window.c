#include "window.h"
#include <malloc.h>
Window *new_Window(int posX, int posY, int w, int h)
{
    Window *win = (Window *)malloc(sizeof(Window));
    win->positionX = posX;
    win->positionY = posY;
    win->width = w;
    win->height = h;
    return win;
}