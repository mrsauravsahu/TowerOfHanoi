#include <GL/glut.h>

#include "types.h"
#include "gamePageViewModel.h"

bool isFullScreen = true;
GamePageViewModel *vm;
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 1);
    glutFullScreen();
}

void toggleFullScreen()
{
    if (isFullScreen == false)
    {
        glutFullScreen();
        isFullScreen = true;
    }
    else
    {
        glutReshapeWindow(vm->window->width, vm->window->height);
        isFullScreen = false;
    }
}

void reshape()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  int myWidth = vm->window->right;
  int myHeight = vm->window->top;

  //Reshaping to accomodate for screen stretch does not look good, hence, commented
  // if (w > h)
  //   glOrtho(-myWidth * w / h, myWidth * w / h, -myHeight, myHeight, 0, 1000);
  // else
  //   glOrtho(-myWidth, myWidth, -myHeight * h / w, myHeight * h / w, 0, 1000);

  if (vm->renderMode == true)
    glOrtho(-myWidth, myWidth, -myHeight, myHeight, 0, 1000);
  else
    gluOrtho2D(0, 900, 0, 750);
}