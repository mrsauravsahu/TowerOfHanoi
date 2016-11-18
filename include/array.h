#ifndef ARRAY2_TOH_H
#define ARRAY2_TOH_H

#define ARRAYTYPE int

typedef struct __Array2__
{
    ARRAYTYPE **array;
    int row, column;
} Array2;

Array2 *new_Array2(int row, int col);
void delete_Array2(Array2 *this);

#endif