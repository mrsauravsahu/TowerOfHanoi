#include <GL/glut.h>
#include <stdio.h>

#include "ai.h"
#include "human.h"
#include "disk.h"
#include "stack.h"
#include "gamePageViewModel.h"
#include "parser.h"
#include "quit.h"

GamePageViewModel *vm;
void choice(int ch)
{
    switch (ch)
    {
    case 1:
        vm->game->solve(vm->game);
        break;
    }
}

void init(void)
{
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

int main(int argc, char **argv)
{
    vm = parse(argc, argv);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(vm->window->width, vm->window->height);
    glutInitWindowPosition(vm->window->positionX, vm->window->positionY);
    glutCreateWindow("Tower of Hanoi");
    glutDisplayFunc(vm->render);
    glutReshapeFunc(vm->reshape);
    init();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 1);
    glutCreateMenu(choice);
    glutAddMenuEntry("Solve", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    //Unreachable Code
    quit(EXIT_SUCCESS, "");
}