#ifndef PARSER_TOH_H
#define PARSER_TOH_H

#include "gamePageViewModel.h"
#include "mode.h"

void showHelp();
GamePageViewModel *parse(int, char **);
Mode getMode();
int getNumberOfDisks();

#endif