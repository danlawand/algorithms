#include <stdlib.h>
#include <stdio.h>


void Intercala(int* A, int p, int q, int r) {
	int max_index = r-p;
	int B[max_index+1];
	int i, j, k;
	for (i = p; i <= q; ++i) {
		B[i-p] = A[i];
	}
	for (i = q+1; i <= r; ++i) {
		B[max_index+q+1-i] = A[i];
	}
	i = 0;
	j = max_index;
	for (k = p; k <= r; ++k) {
		if (B[i]<= B[j]) {
			/*Linhas 21 a 27 são para garantir a estabilidade (= Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.)*/
			/*Para retirar essa parte de estabilidade, basta deixar apenas as linhas 113 e 114*/
			if (i > q-p) {
				A[k] = B[j];
				--j;
			} else {
				A[k] = B[i];
				++i;
			}
		} else {
			A[k] = B[j];
			--j;
		}
	}
}

void MergeSort(int* A, int p, int r) {
	int q;
	if (p < r) {
		q = (int) ((p+r)/2);
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Intercala(A, p, q, r);
	}
}


int main (int argc, char* argv[]) {
    int A[9] = {7, 0, 3, 8, 2, 9, 6, 1, 10};
    MergeSort(A, 0, 8);
    for (int i = 0; i < 9; i++) {
        printf("%d, ", A[i]);
    }
    printf("\n");
}