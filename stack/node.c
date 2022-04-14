#include "node.h"

static void *mallocSafe(size_t);

Node newNode(Node next, int data) {
    Node p = mallocSafe(sizeof(*p));
}

void freeNode(Node p) {
    p->next = NULL;
    free(p);
}

static void *mallocSafe(size_t nbytes) {
    void *p = malloc(nbytes);
    if (p == NULL) {
        printf("Error: Allocation memory failed in module Node.\n");
        exit(0);
    }
    return p;
}