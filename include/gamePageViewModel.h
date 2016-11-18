#ifndef GAMEPAGE_TOH_H
#define GAMEPAGE_TOH_H

#include <malloc.h>
#include <toh.h>

struct __GamePage__
{
  TOH *toh;
  void (*render)(void);
};

typedef struct __GamePage__ GamePageViewModel;
void render_gamePage(void);
GamePageViewModel *new_gamePageViewModel(int n);

GamePageViewModel *vm;
#endif