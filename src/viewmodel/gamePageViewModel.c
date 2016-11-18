#include <gamePageViewModel.h>
#include <toh.h>
#include <GL/glut.h>

void render_gamePage(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  for (int i = 0; i < 3; ++i)
    traverse(vm->toh->game->poles[i], drawDisk);
  glutSwapBuffers();
}

GamePageViewModel *new_gamePageViewModel(int n)
{
  GamePageViewModel *gm =
      (GamePageViewModel *)malloc(sizeof(GamePageViewModel));
  gm->toh = new_TOH(n);
  gm->render = render_gamePage;
  setupGame(gm->toh);
  return gm;
}