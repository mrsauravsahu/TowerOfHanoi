#include <malloc.h>
#include <game.h>
#include <types.h>

Game *new_Game(int n, void (*solve)(Game *), double height)
{
    Game *g = (Game *)malloc(sizeof(Game));
    g->poles = (Stack **)malloc(sizeof(Stack *) * 3);
    g->poles[Source] = new_Stack(n);
    g->poles[Auxilliary] = new_Stack(n);
    g->poles[Destination] = new_Stack(n);
    g->solve = solve;
    g->disks = n;
    g->height = height;
    return g;
}