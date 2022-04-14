#include <stdlib.h>
#include <stdio.h>

void bubble(int* vetor, int n) {
	int temp, i, noChange;
	noChange = 1;
	while(noChange) {
		noChange = 0;
		for (i = 0; i < n-1; ++i) {
			if (vetor[i] > vetor[i+1]) {
				temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				noChange = 1;
			} 
		}
	}
}