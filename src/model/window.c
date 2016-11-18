#include <window.h>
#include <malloc.h>
Window *new_Window(int posX, int posY, int w, int h)
{
    Window *win = (Window *)malloc(sizeof(Window));
    win->positionX = posX;
    win->positionY = posY;
    win->width = w;
    win->height = h;

    win->left = 0;
    win->right = 900;
    win->top = 750;
    win->bottom = 0;
    return win;
}