#include "item.h"
#include <iostream>

using namespace std;

Item* Item::newItem(int v) {
    Item* new_item = new Item();
    new_item->v = v;
    return new_item;
}