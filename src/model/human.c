#include <human.h>
#include <GL/glut.h>
#include <stack.h>
#include <constants.h>
#include <gamePageViewModel.h>

extern GamePageViewModel *vm;
const char *moves[3][3] = {
    "", "Source -> Auxilliary", "Source -> Destination",
    "Auxilliary -> Source", "", "Auxilliary -> Destination",
    "Destination -> Source", "Destination -> Auxilliary", ""};

void menuOptions(int move)
{
    Pole from, to;
    from = move / 10 - 1;
    to = move % 10 - 1;
    mymove(vm->game, from, to);
    setValidOptions(vm->menuSystem);
}

void mymove(Game *game, Pole from, Pole to)
{
    Point3 base = {0, 50, 0};
    switch (to)
    {
    case Source:
        base.x = SourceX;
        break;
    case Auxilliary:
        base.x = AuxX;
        break;
    case Destination:
        base.x = DestX;
        break;
    }
    if (isEmpty(game->poles[to]) == false)
        base.y = peep(game->poles[to]).baseCenter.y + game->height;
    Disk moving = pop(game->poles[from]);
    moving.baseCenter.x = base.x;
    moving.baseCenter.y = base.y;
    moving.baseCenter.z = base.z;
    push(game->poles[to], moving);
    glutPostRedisplay();
}

void solveHuman()
{
    if (vm->menuSystem->created == false)
    {
        vm->menuSystem->menuFunction = menuOptions;
        vm->menuSystem->created = true;
    }
    else
    {
        destroyMenu(vm->menuSystem);
    }
    createMenu(vm->menuSystem);
    setValidOptions(vm->menuSystem);
}
void setValidOptions(Menu *menu)
{
    destroyMenu(menu);
    createMenu(menu);
    int count[3] = {0};
    for (int i = 0; i < 3; ++i)
    {
        if (isEmpty(vm->game->poles[i]))
            count[i] = -1;
        else
            count[i] = peep(vm->game->poles[i]).id;
    }
    glutSetMenu(menu->menuId);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            if (count[i] > count[j])
                glutAddMenuEntry(moves[i][j], (i + 1) * 10 + j + 1);
        }
    }
}