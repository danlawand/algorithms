Queue queue_pointer;

void iniate_queue() {
    queue_pointer->head = NULL;
    queue_pointer->tail = NULL;
    queue_pointer->size = 0;
}

bool empty_queue() {
    if (queue_pointer->head == NULL && queue_pointer->tail == NULL) return 1;
    return 0;
}

void push_queue(int data) {
    Node p = newNode(queue_pointer->head, data);
    queue_pointer->head = p;
    queue_pointer->size += 1;
    if (queue_pointer->size == 1) queue_pointer->tail = queue_pointer->head;
}
int pop_queue() {
    Node p = queue_pointer->tail;
    // need to look if tail and head are the samez
}
int head_queue();
int tail_queue();
int size_queue();