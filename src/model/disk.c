#include <GL/glut.h>
#include <malloc.h>
#include <stdlib.h>
#include <disk.h>
#include <types.h>

Disk *new_Disk(int id, double x, double y, double outerRadius, double height, Color color)
{
    Disk *d = (Disk *)malloc(sizeof(Disk));
    d->id = id;
    Point3 pos;
    pos.x = x;
    pos.y = y;

    d->color[0] = color[0];
    d->color[1] = color[1];
    d->color[2] = color[2];

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
    glColor3dv(this->color);
    glVertex2d(base.x - rad / 2, base.y);
    glVertex2d(base.x - rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y + height);
    glVertex2d(base.x + rad / 2, base.y);
    glEnd();
}