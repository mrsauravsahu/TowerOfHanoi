#include <GL/glut.h>
#include <malloc.h>
#include <stdlib.h>
#include "disk.h"
#include "types.h"

Disk *new_Disk(double x, double y, double outerRadius, double height)
{
    Disk *d = (Disk *)malloc(sizeof(Disk));
    Point3 pos;
    pos.x = x;
    pos.y = y;
    d->outerRadius = outerRadius;
    d->height = height;
    d->baseCenter = pos;
    return d;
}
void drawDisk(Disk *this)
{
    Point3 base = this->baseCenter;
    double rad = this->outerRadius;
    double height = this->height;
    glBegin(GL_QUADS);
    glColor3d(rand() % 255 / 255.0, rand() % 255 / 255.0, rand() % 255 / 255.0);
    glVertex2d(base.x - rad / 2, base.y);
    glVertex2d(base.x - rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y);
    glEnd();
}