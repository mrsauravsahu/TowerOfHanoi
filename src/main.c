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

int main(int argc, char **argv)
{
    vm = parse(argc, argv);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(vm->window->width, vm->window->height);
    glutInitWindowPosition(vm->window->positionX, vm->window->positionY);
    glutCreateWindow("Tower of Hanoi");
    gluOrtho2D(vm->window->left, vm->window->right, vm->window->bottom, vm->window->top);
    glutDisplayFunc(vm->render);
    glClearColor(1, 1, 1, 1);
    glutCreateMenu(choice);
    glutAddMenuEntry("Solve", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    //Unreachable Code
    quit(EXIT_SUCCESS, "");
}