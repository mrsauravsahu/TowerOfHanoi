#include <human.h>
#include <GL/glut.h>
#include <stack.h>
#include <constants.h>
#include <gamePageViewModel.h>

int menuId;
int optionsCount = 0;
bool created = false;

const char *moves[3][3] = {
    "", "Source -> Auxilliary", "Source -> Destination",
    "Auxilliary -> Source", "", "Auxilliary -> Destination",
    "Destination -> Source", "Destination -> Auxilliary", ""};

void createMenu()
{
    menuId = glutCreateMenu(menuOptions);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    created = true;
}
void cleanOptions()
{
    glutSetMenu(menuId);
    for (int i = 0; i < optionsCount; ++i)
        glutRemoveMenuItem(i + 1);
}
void setValidOptions(Game *game)
{
    glutDestroyMenu(menuId);
    createMenu();
    optionsCount = 0;
    int count[3] = {0};
    for (int i = 0; i < 3; ++i)
    {
        if (isEmpty(game->poles[i]))
            count[i] = -1;
        else
            count[i] = peep(game->poles[i]).id;
    }
    glutSetMenu(menuId);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            if (count[i] > count[j])
            {
                glutAddMenuEntry(moves[i][j], (i + 1) * 10 + j + 1);
                optionsCount++;
            }
            /*else if (count[i] < count[j])
            {
                glutAddMenuEntry(moves[j][i], (j + 1) * 10 + i + 1);
                optionsCount++;
            }*/
        }
    }
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

void menuOptions(int move)
{
    Pole from, to;
    from = move / 10 - 1;
    to = move % 10 - 1;
    mymove(vm->game, from, to);
    setValidOptions(vm->game);
}

void solveHuman(Game *game)
{
    if (created == true)
        glutDestroyMenu(menuId);
    createMenu();
    setValidOptions(game);
}