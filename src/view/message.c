#include <GL/glut.h>
#include <string.h>

#include "message.h"

char message[50];
void message_render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3i(0, 0, 0);
    renderBitmapString(-0.5, 0, GLUT_BITMAP_HELVETICA_12, message);
    glutSwapBuffers();
}

void renderBitmapString(float x, float y, void *font, char *string)
{
    glRasterPos2f(x, y);
    for (int i = 0; string[i] != '\0'; ++i)
        glutBitmapCharacter(font, string[i]);
}

void new_Message(char *str)
{
    strcpy(message, str);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(480, 140);
    int id = glutCreateWindow("Message");
    glutSetWindow(id);
    glutDisplayFunc(message_render);
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1, 1, -1, 1);
}