#include <stdlib.h>
#include <stdio.h>

/*InsertSort Versão Carlinhos*/
void insertSort(int* A, int n) {
	int i, j = 1;
	int chave;
	while (j < n) {
		chave = A[j];
		i = j-1;
		while (i >= 0 && A[i] > chave) {
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = chave;
		++j;
	}
}