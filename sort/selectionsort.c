#include <stdlib.h>
#include <stdio.h>

void selectionSort(int* vetor, int n) {
	int temp;
	int i, j, k;
	// Ao final da primeira iteração o menor estará no 0
	// ao final da i-ésima iteração o i-ésimo menor estará em i-1 posição
	for (k = 0; k < n; ++k) {
		for (i = k+1; i < n; ++i)
		{
			if (vetor[k] > vetor[i]) {
				temp = vetor[i];
				vetor[i] = vetor[k];
				vetor[k] = temp;
			}
		}
	}
}