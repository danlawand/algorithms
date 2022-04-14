#include <stdlib.h>
#include <stdio.h>


int particiona(int* A, int p, int r) {
    int temp, i, q, x;
    x = A[r];
    i = p-1;
    for (int j = p; j <= r; j++) {
        if (A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    return i;
}

void quicksort(int* A, int p, int r) {
    int q;
    if (p < r) {
        q = particiona(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main (int argc, char* argv[]) {
    int A[9] = {7, 0, 3, 8, 2, 9, 6, 1, 10};
    quicksort(A, 0, 8);
    for (int i = 0; i < 9; i++) {
        printf("%d, ", A[i]);
    }
    printf("\n");
}