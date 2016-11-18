#include <toh.h>
#include <disk.h>
#include <stack.h>
#include <stdio.h>
#include <gamePageViewModel.h>
#include <GL/glut.h>

extern GamePageViewModel *vm;
void choice(int ch)
{
    switch (ch)
    {
    case 1:
        vm->toh->game->solve(vm->toh->game);
        break;
    }
}

int main(int argc, char **argv)
{
    vm = new_gamePageViewModel(4);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(vm->toh->window->width, vm->toh->window->height);
    glutInitWindowPosition(vm->toh->window->positionX, vm->toh->window->positionY);
    glutCreateWindow("Tower of Hanoi");
    gluOrtho2D(vm->toh->window->left, vm->toh->window->right, vm->toh->window->bottom, vm->toh->window->top);
    glutDisplayFunc(vm->render);
    glClearColor(1, 1, 1, 1);
    //glutFullScreen();
    glutCreateMenu(choice);
    glutAddMenuEntry("Solve", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}