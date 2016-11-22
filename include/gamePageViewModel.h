#ifndef GAMEPAGEVIEWMODEL_TOH_H
#define GAMEPAGEVIEWMODEL_TOH_H

#include <menu.h>
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
  void (*reshape)(int, int);
  Menu *menuSystem;
} GamePageViewModel;

void render_gamePage(void);
GamePageViewModel *new_gamePageViewModel(int n, void (*render)(Game *));
void setupGame(GamePageViewModel *);

#endif