#include <stdio.h>

#include "stringops.h"

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        printf("%s", argv[i]);
        toUpper(argv[i]);
        printf(" --> %s\n", argv[i]);
    }
    return 0;
}