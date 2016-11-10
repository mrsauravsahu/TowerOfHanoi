#ifndef DISK_TOH_H
#define DISK_TOH_H

#include "types.h"

typedef struct
{
    double innerRadius, outerRadius;
    double height;
    Point3 baseCenter;
} Disk;

Disk *new_Disk();
void drawDisk(Disk *);

#endif