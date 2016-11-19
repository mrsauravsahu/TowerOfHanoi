#ifndef GAMEPAGEVIEWMODEL_TOH_H
#define GAMEPAGEVIEWMODEL_TOH_H

#include <stack.h>
#include <window.h>
#include <game.h>
#include <malloc.h>

typedef struct
{
  Game *game;
  Window *window;
  int disks;
  double height;
  void (*render)(void);
} GamePageViewModel;

void render_gamePage(void);
GamePageViewModel *new_gamePageViewModel(int n, void (*render)(Game *));
void setupGame(GamePageViewModel *);

GamePageViewModel *vm;

#endif