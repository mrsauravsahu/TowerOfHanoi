#ifndef STACK_TOH_H
#define STACK_TOH_H

#include "disk.h"
#include <malloc.h>
#define TYPE Disk


typedef struct __Node__
{
    TYPE info;
    struct __Node__ *ptr;
} Node;

typedef struct
{
    Node *top;
    int count, size;
} Stack;

Stack *new_Stack(int);
TYPE peep(Stack *);
void push(Stack *, TYPE);
TYPE pop(Stack *);
void empty();
void display();
void destroy();
int count();
void create();

#endif