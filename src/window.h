#ifndef WINDOW_TOH_H
#define WINDOW_TOH_H

typedef struct
{
    int width, height;
    int positionX, positionY;
} Window;

Window *new_Window(int, int, int, int);
#endif