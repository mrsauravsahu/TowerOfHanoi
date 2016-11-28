#include <GL/glut.h>
#include <stdlib.h>

#include "gamePageViewModel.h"
#include "stack.h"
#include "window.h"
#include "disk.h"
#include "constants.h"
#include "ai.h"
#include "initialization.h"
#include "stringops.h"

extern GamePageViewModel *vm;
void (*diskRender)(Disk *);

void reshape_gamePage(int w, int h)
{
  glViewport(0, 0, w, h);
  reshape();
  glutPostRedisplay();
}

void drawPoles()
{
  //Pole Names
  glColor3i(0, 0, 0);
  drawString("SOURCE", SourceX, 700);
  drawString("AUXILIARY", AuxX, 700);
  drawString("DESTINATION", DestX, 700);
}

void render_gamePage(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  if (vm->renderMode == true)
  {

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0, -100, 0);
    gluLookAt(450, 300 + vm->disks * 6, 500, 460, 300 - vm->disks * 4, 0, 0, 1, 0);
    diskRender = drawDisk3D;
  }
  else
  {
    glPushMatrix();
    diskRender = drawDisk2D;
  }

  drawPoles();
  for (int i = 0; i < 3; ++i)
    traverse(vm->game->poles[i], diskRender);
  glPopMatrix();
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
