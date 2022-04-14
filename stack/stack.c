#include "stack.h"

static Stack stack_pointer;

void initiate_stack() {
    stack_pointer->top = NULL;
    stack_pointer->size = 0;
}

bool empty_stack() {
    if (stack_pointer->top == NULL) return 1;
    return 0;
}

void push_stack(int data) {
    Node p = newNode(stack_pointer->top, data);
    stack_pointer->top = p;
    stack_pointer->size += 1;
}

int pop_stack() {
    Node p;
    int data;
    if (stack_pointer->top == NULL) return -1;

    data = stack_pointer->top->data;
    p = stack_pointer->top;

    stack_pointer->top = stack_pointer->top->next;
    stack_pointer->size -= 1;

    freeNode(p);
    return data;
}

int top_stack() {
    return stack_pointer->top->data;
}

int size_stack() {
    return stack_pointer->size;
}