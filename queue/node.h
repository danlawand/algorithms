#ifndef _NODE_H
#define _NODE_H

typedef struct node *Node;
struct node {
    Node next;
    int data;
};

Node newNode(Node, int);

void freeNode();
#endif
