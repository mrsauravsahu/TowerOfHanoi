#include "stringops.h"

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        str[i] = toupper(str[i]);
}