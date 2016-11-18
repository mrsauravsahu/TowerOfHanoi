#ifndef TYPES_TOH_H
#define TYPES_TOH_H

typedef enum __Boolean__ {
    false,
    true
} bool;

typedef double Point2[2];
typedef struct
{
    double x, y, z;
} Point3;
typedef double Color[3];

typedef enum __Pole__ {
    Source,
    Auxilliary,
    Destination
} Pole;

#endif
