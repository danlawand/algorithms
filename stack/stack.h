#ifndef _STACK_H
#define _STACK_H

#include "node.h"

typedef struct *stack Stack;
struct stack {
    Node top;
    int size;
};
void initiate_stack();
bool empty_stack();
void push_stack(int);
int pop_stack();
int top_stack();
int size_stack();

#endif