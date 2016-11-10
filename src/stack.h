#ifndef STACK_TOH_H
#define STACK_TOH_H

#include <malloc.h>
#include "disk.h"
#include "types.h"
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
bool isEmpty(Stack *);
void traverse(Stack *, void (*func)(TYPE *));
void destroy(Stack *);
int count(Stack *);

#endif