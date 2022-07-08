#include <iostream>
#include "queue.h"

using namespace std;

Item* newItem(int v) {
    Item* new_item = new Item();
    new_item->v = v;
    return new_item;
}

int main()
{
    // Create a graph given in the above diagram
    Queue g;
    g.pushQueue(newItem(1));
    Item* i = g.popQueue();
    g.pushQueue(newItem(2));
    i = g.popQueue();
    g.pushQueue(newItem(3));


    g.pushQueue(newItem(4));
    g.pushQueue(newItem(5));
    g.pushQueue(newItem(6));
    
    g.printQueue();
 
    return 0;
}