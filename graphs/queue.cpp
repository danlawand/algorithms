#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue() {
    this->head = new Node();
    this->head->next = this->head;
    this->head->prev = this->head;
    this->size = 0;
}

void Queue::pushQueue(Item* item) {
    Node* new_node = new Node();
    new_node->item = item;
    new_node->next = head->next;
    new_node->prev = head;
    head->next->prev = new_node;
    head->next = new_node;
    size++;
}

// Its called only when emptyQueue() != true
Item* Queue::popQueue() {
    Node* temp;
    temp = head->prev;
    Item* item = temp->item;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    temp->next = NULL;
    temp->prev = NULL;
    temp->item = NULL;
    temp = NULL;
    size--;
    return item;
}

int Queue::emptyQueue() {
    if (size == 0) return 1;
    return 0;
}

void Queue::printQueue() {
    Node* p;
    p = head->next;
    while (p != head) {
        cout << p->item->v << " ";
        p = p->next;
    }
}
