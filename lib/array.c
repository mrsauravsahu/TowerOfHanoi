#include <array.h>
#include <malloc.h>

Array2 *new_Array2(int row, int col)
{
    Array2 *a = (Array2 *)malloc(sizeof(Array2));
    a->array =(ARRAYTYPE **)malloc(sizeof(ARRAYTYPE *)*row);
    for (int i = 0; i < row; ++i)
        a->array[i] = (ARRAYTYPE *)malloc(sizeof(ARRAYTYPE) * col);
    a->row = row;
    a->column = col;
    return a;
}

void delete_Array2(Array2 *this)
{
    for (int i = 0; i < this->row; ++i)
        free(this->array[i]);
    free(this->array);
    free(this);
}