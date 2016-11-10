#include <GL/glut.h>
#include <malloc.h>
#include "disk.h"
#include "types.h"

int x = 100;
int c = 0;
Disk *new_Disk()
{
    Disk *d = (Disk *)malloc(sizeof(Disk));
    Point3 pos;
    pos.x = 125;
    pos.y= 100 + x * c;
    c++;
    d->outerRadius = 100;
    d->height = 100;
    d->baseCenter = pos;
    return d;
}
void drawDisk(Disk *this)
{
    Point3 base = this->baseCenter;
    double rad = this->outerRadius;
    double height = this->height;
    glBegin(GL_QUADS);
    glVertex2d(base.x - rad / 2, base.y);
    glVertex2d(base.x - rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y);
    glEnd();
}