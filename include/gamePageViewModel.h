#ifndef GAMEPAGEVIEWMODEL_TOH_H
#define GAMEPAGEVIEWMODEL_TOH_H

#include <malloc.h>
#include "menu.h"
#include "stack.h"
#include "window.h"
#include "game.h"

typedef struct
{
  Game *game;
  Window *window;
  int disks;
  double height;
  void (*render)(void);
  void (*reshape)(int, int);
  Menu *menuSystem;
  bool renderMode;
} GamePageViewModel;

void render_gamePage(void);
GamePageViewModel *new_gamePageViewModel(int, void (*render)(Game *), bool);
void setupGame(GamePageViewModel *);

#endif