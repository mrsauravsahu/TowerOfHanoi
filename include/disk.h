#ifndef DISK_TOH_H
#define DISK_TOH_H

#include <types.h>

typedef struct
{
    double innerRadius, outerRadius;
    double height;
    Point3 baseCenter;
    Color color;
} Disk;

Disk *new_Disk(double, double, double, double, Color);
void drawDisk(Disk *);

#endif