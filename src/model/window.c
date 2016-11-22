#include <window.h>
#include <malloc.h>
Window *new_Window(int posX, int posY, int disks)
{
    Window *win = (Window *)malloc(sizeof(Window));
    win->positionX = posX;
    win->positionY = posY;
    win->width = 700;
    win->height = 680;

    win->top = 375;
    win->right = 475;

    win->bottom = -win->top;
    win->left = -win->right;
    return win;
}