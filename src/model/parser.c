#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gamePageViewModel.h"
#include "ai.h"
#include "human.h"
#include "mode.h"
#include "parser.h"
#include "stringops.h"
#include "quit.h"

void showHelp()
{
    printf("Usage: <executable-name> <mode> <number-of-disks>");
    printf("\nmode: [human, ai]");
    printf("\nnumber-of-disks: [integer in 1 to 10]");
}

GamePageViewModel *parse(int argc, char **argv)
{
    Mode mode;
    char *modeString;
    int disks;
    if (argc < 3)
    {
        showHelp();
        quit(EXIT_FAILURE, "\n");
    }
    if (argc == 1)
    {
        mode = getMode();
        disks = getNumberOfDisks();
    }
    else
    {
        modeString = argv[1];
        disks = atoi(argv[2]);
        if (disks < 0 || disks > 10)
        {
            printf("You have entered an invalid number. Try again...\n");
            disks = getNumberOfDisks();
        }
        if (strcmp(modeString, "human") != 0 && strcmp(modeString, "ai") != 0)
        {
            printf("You have entered an invalid mode. Try again...\n");
            mode = getMode();
        }
    }
    switch (mode)
    {
    case Human:
        return new_gamePageViewModel(disks, solveHuman);
    case AI:
        return new_gamePageViewModel(disks, solveAI);
    default:
        //Unreachable Code
        quit(EXIT_SUCCESS, "\n");
    }
}

Mode getMode()
{
    char mode[10];
    do
    {
        printf("Enter mode: [human, ai]: ");
        scanf("%s", mode);
        toUpper(mode);
    } while (strcmp(mode, "HUMAN") && strcmp(mode, "AI"));

    if (strcmp(mode, "HUMAN") == 0)
        return Human;
    else
        return AI;
}

int getNumberOfDisks()
{
    int disks;
    do
    {
        printf("\nEnter number of disks [1 - 10]: ");
        scanf("%d", &disks);
    } while (disks < 0 || disks > 10);
    return disks;
}