#ifndef DISK_TOH_H
#define DISK_TOH_H

#include <types.h>

typedef struct
{
    int id;
    double innerRadius, outerRadius;
    double height;
    Point3 baseCenter;
    Color color;
} Disk;

Disk *new_Disk(int, double, double, double, double, Color);
void drawDisk2D(Disk *);
void drawDisk3D(Disk *);

#endif