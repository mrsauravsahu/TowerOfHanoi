#include <GL/glut.h>
#include <stdio.h>

#include "ai.h"
#include "human.h"
#include "disk.h"
#include "stack.h"
#include "gamePageViewModel.h"
#include "parser.h"
#include "quit.h"
#include "initialization.h"

extern GamePageViewModel *vm;
extern bool isFullScreen;
void choice(int ch)
{
    switch (ch)
    {
    case 1:
        glutRemoveMenuItem(1);
        vm->game->solve(vm->game);
        break;
    case 2:
        toggleFullScreen();
        glutPostRedisplay();
        break;
    case 3:
        vm->renderMode = (vm->renderMode == true) ? false : true;
        reshape();
        glutPostRedisplay();
        break;
    case 4:
        quit(EXIT_SUCCESS, "\n");
    }
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

    //Create initial Menu
    glutCreateMenu(choice);
    glutAddMenuEntry("Solve", 1);
    glutAddMenuEntry("Toggle Fullscreen", 2);
    glutAddMenuEntry("Toggle 2D/3D", 3);
    glutAddMenuEntry("Quit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    //Unreachable Code
    quit(EXIT_SUCCESS, "");
}