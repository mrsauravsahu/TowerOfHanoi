#include <stdio.h>
#include "stack.h"
#include "types.h"

// Allocate memory for a new Stack on the heap
Stack *new_Stack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(TYPE));
    stack->top = NULL;
    stack->count = 0;
    stack->size = size;
    return stack;
};

//Return number of items in the stack
int count(Stack *this) { return this->count; }

// Push new element onto the stack
void push(Stack *this, TYPE data)
{
    Node *tmp;

    if (this->top == NULL)
    {
        this->top = (Node *)malloc(sizeof(Node));
        this->top->ptr = NULL;
        this->top->info = data;
    }
    else
    {
        tmp = (Node *)malloc(sizeof(Node));
        tmp->ptr = this->top;
        tmp->info = data;
        this->top = tmp;
    }
    this->count++;
}

// Pop the topmost element from the stack
TYPE pop(Stack *this)
{
    Node *tmp = this->top;
    tmp = tmp->ptr;
    free(this->top);
    this->top = tmp;
    this->count--;
    return tmp->info;
}

// Peep the topmost element on the stack
TYPE peep(Stack *this) { return this->top->info; }

// Check if stack is empty or not
bool isEmpty(Stack *this)
{
    if (this->top == NULL)
        return true;
    else
        return false;
}

// Deallocate all elements from stack
void destroy(Stack *this)
{
    Node *tmp = this->top;
    while (tmp != NULL)
    {
        tmp = this->top->ptr;
        free(this->top);
        this->top = tmp;
        tmp = tmp->ptr;
    }
    free(tmp);
    this->top = NULL;
    this->count = 0;
}

// Traverse the stack
void traverse(Stack *this, void (*func)(TYPE *))
{
    Node *top = this->top;
    while (top != NULL)
    {
        func(&(top->info));
        top = top->ptr;
    }
}