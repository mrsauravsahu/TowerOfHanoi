#include <GL/glut.h>
#include <malloc.h>
#include <stdlib.h>

#include "disk.h"
#include "types.h"

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
void drawDisk3D(Disk *this)
{
    Point3 base = this->baseCenter;
    double rad = this->outerRadius;
    double height = this->height;

    glPushMatrix();
    glTranslatef(base.x, base.y + height, 0);
    glRotatef(90, 1, 0, 0);

    //Change color to color of the disk
    glColor3dv(this->color);

    //Draw the cylinder -> The tube part
    glPushMatrix();
    GLUquadric *q = gluNewQuadric();
    gluQuadricDrawStyle(q, GLU_FILL);
    gluCylinder(q, rad, rad, height, 80, 80);
    glPopMatrix();

    //Draw the base
    glPushMatrix();
    gluDisk(q, 0, rad, 80, 80);
    glPopMatrix();

    //Draw the top
    glPushMatrix();
    glTranslatef(0, 0, height);
    gluDisk(q, 0, rad, 80, 80);
    glPopMatrix();

    glPopMatrix();

    gluDeleteQuadric(q);
}
void drawDisk2D(Disk *this)
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