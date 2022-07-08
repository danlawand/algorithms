#include "item.h"
#ifndef NODE_H
#define NODE_H

class Node {
public:
    Item* item;
    Node* next;
    Node* prev;
};

#endif
