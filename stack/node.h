#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>

typedef struct node *node;
struct node {
    Node next;
    int data;
};

Node newNode(Node, int);

void freeNode();
#endif
