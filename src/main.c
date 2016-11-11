#include <GL/glut.h>
#include "toh.h"
TOH *root;
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 1);
    traverse(root->source, drawDisk);
    traverse(root->aux, drawDisk);
    traverse(root->dest, drawDisk);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    root = new_TOH(10);
    setupGame(root);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(root->window->width, root->window->height);
    glutInitWindowPosition(root->window->positionX, root->window->positionY);
    glutCreateWindow("Tower of Hanoi");
    gluOrtho2D(0, root->window->width, 0, root->window->height);
    glutDisplayFunc(render);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return 0;
}