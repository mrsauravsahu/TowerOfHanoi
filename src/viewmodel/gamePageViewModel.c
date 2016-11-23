#include <GL/glut.h>
#include <stdlib.h>

#include "gamePageViewModel.h"
#include "stack.h"
#include "window.h"
#include "disk.h"
#include "constants.h"
#include "ai.h"

extern GamePageViewModel *vm;

void reshape_gamePage(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  int myWidth = vm->window->right;
  int myHeight = vm->window->top;

  //Reshaping to accomodate for screen stretch does not look good, hence, commented
  // if (w > h)
  //   glOrtho(-myWidth * w / h, myWidth * w / h, -myHeight, myHeight, 0, 1000);
  // else
  //   glOrtho(-myWidth, myWidth, -myHeight * h / w, myHeight * h / w, 0, 1000);
  
  if(vm->renderMode ==true) glOrtho(-myWidth, myWidth, -myHeight, myHeight, 0, 1000);
  else  gluOrtho2D(0, 900, 0, 750);
  glutPostRedisplay();
}

void drawPoles()
{
  //Pole Names
  glColor3i(0, 0, 0);
  glRasterPos2f(SourceX, 700);
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
  glRasterPos2f(AuxX, 700);
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
  glRasterPos2f(DestX, 700);
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
}

void render_gamePage(void)
{
  void (*diskRender)();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (vm->renderMode == true)
  {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, -100, 0);
    gluLookAt(450, 300 + vm->disks * 6, 500, 460, 300 - vm->disks * 4, 0, 0, 1, 0);
    diskRender = drawDisk3D;
  }
  else
  {
    diskRender = drawDisk2D;
  }

  drawPoles();
  for (int i = 0; i < 3; ++i)
    traverse(vm->game->poles[i], diskRender);
  glutSwapBuffers();
}

GamePageViewModel *new_gamePageViewModel(int n, void (*solve)(Game *), bool renderMode)
{
  GamePageViewModel *gm = (GamePageViewModel *)malloc(sizeof(GamePageViewModel));
  gm->render = render_gamePage;
  gm->reshape = reshape_gamePage;
  gm->disks = n;
  gm->height = ((600.0 / n) < 80) ? 600.0 / (n) : 80;
  gm->game = new_Game(n, solve, gm->height);
  gm->window = new_Window(0, 0, n);
  gm->menuSystem = new_Menu();
  gm->renderMode = renderMode;
  setupGame(gm);
  return gm;
}

void setupGame(GamePageViewModel *t)
{
  //Disk ID
  int id = 0;
  //Outer radius
  double or = 140;
  //y Coordinate
  double y = 50;
  //Color for the disk
  Color col;
  for (int i = 0; i < t->disks; ++i)
  {
    col[0] = (rand() % 200) / 255.0;
    col[1] = (rand() % 200) / 255.0;
    col[2] = (rand() % 200) / 255.0;
    push(t->game->poles[Source], *(new_Disk(id++, SourceX, y, or, t->height, col)));
    y += t->height;
    or -= (145 / t->disks);
  }
}
