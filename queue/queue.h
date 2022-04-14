#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct *queue Queue;
struct queue {
    Node head;
    Node tail;
    int size;
};

void iniate_queue();
bool empty_queue();
void push_queue(int);
int pop_queue();
int head_queue();
int tail_queue();
int size_queue();

#endif