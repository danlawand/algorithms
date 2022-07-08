#include "node.h"
#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    Node* head;
    int size;
    public:
        Queue(); // constructor
        void pushQueue(Item* v);
        Item* popQueue();
        int emptyQueue();
        void printQueue();
};

#endif
