#include <GL/glut.h>
#include <string.h>

#include "stringops.h"

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        str[i] = toupper(str[i]);
}

void drawString(char *str, int x, int y)
{

    int length = strlen(str);
    x -= length * 4;
    glColor3i(0, 0, 0);
    glRasterPos2f(x, y);
    for (int i = 0; i < length; ++i)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}
