#include <menu.h>
#include <GL/glut.h>
#include <types.h>
#include <stack.h>
#include <gamePageViewModel.h>

Menu *new_Menu()
{
    Menu *m = (Menu *)malloc(sizeof(Menu));
    m->menuId = -1;
    m->optionsCount = 0;
    m->created = false;
    return m;
}
void createMenu(Menu *m)
{
    m->menuId = glutCreateMenu(m->menuFunction);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    m->created = true;
}
void destroyMenu(Menu *m)
{
    glutDestroyMenu(m->menuId);
}
