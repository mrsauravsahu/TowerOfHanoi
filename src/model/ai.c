#include <ai.h>
#include <stack.h>
#include <constants.h>
#include <stdio.h>
#include <GL/glut.h>
#include <disk.h>
#include <math.h>
#include <array.h>
#include <gamePageViewModel.h>

Array2 *solution;
int i = 0;
void move(int x)
{
    if (x < solution->row)
    {
        int from = solution->array[x][0];
        int to = solution->array[x][1];

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
        if (isEmpty(vm->game->poles[to]) == false)
            base.y = peep(vm->game->poles[to]).baseCenter.y + vm->game->height;
        Disk moving = pop(vm->game->poles[from]);
        moving.baseCenter.x = base.x;
        moving.baseCenter.y = base.y;
        moving.baseCenter.z = base.z;
        push(vm->game->poles[to], moving);
        glutPostRedisplay();
        glutTimerFunc(1000, move, x + 1);
    }
}

void towers(Game *game, int num, Pole from, Pole to, Pole aux)
{
    if (num == 1)
    {
        printf("\nlog: Move disk : %d --> %d", from, to);
        solution->array[i][0] = from;
        solution->array[i][1] = to;
        i++;
        return;
    }
    towers(game, num - 1, from, aux, to);
    printf("\nlog: Move disk : %d --> %d", from, to);
    solution->array[i][0] = from;
    solution->array[i][1] = to;
    i++;
    towers(game, num - 1, aux, to, from);
}

void solve_ai(Game *game)
{
    int moves = (int)(pow(2, game->disks)) - 1;
    solution = new_Array2(moves, 2);
    towers(game, game->disks, 0, 2, 1);
    glutTimerFunc(0, move, 0);
}