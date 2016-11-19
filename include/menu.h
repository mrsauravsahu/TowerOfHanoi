#ifndef MENU_TOH_H
#define MENU_TOH_H

#include <menu.h>
#include <malloc.h>
#include <GL/glut.h>
#include <types.h>

typedef struct __Menu__
{
    int menuId;
    int optionsCount;
    bool created;
    void (*menuFunction)(int);    
} Menu;

Menu *new_Menu();
void createMenu(Menu *);
void destroyMenu(Menu *);

#endif
