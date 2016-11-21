#include <quit.h>

void quit(int code, char *msg)
{
    printf("%s", msg);
    exit(code);
}