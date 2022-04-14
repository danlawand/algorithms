#include <stdio.h>
#include <stdlib.h>


int fatorial(int n) {
	if (n == 0) return 1;
	return fatorial(n-1) * n;
}


int permutation(int **A, int called_number, int elements_number, int ind_i, int ind_j, int N) {
	int j, i;

	if (elements_number <= 1) {
		for (j = 0; j < N && lista[ind_i][j] != 1; ++j);
		A[ind_i][ind_j] = j+1;
		return;
	}



	fact = fatorial(elements_number);
	for(i = ind_i; i < ind_i + fact; ++i) {
		for (j = 0; j < n; ++j) {
			lista[ind_i][j] 
		}
		A[][]
		permutation()
		
	}

	for (i = 1; i <= elements_number; ++i) {
		if (i != called_number) {
			ind_i = permutation(A, i, )
		}

	}
}


int max(int *A, int n) {
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	if (argc < 3) {
		printf("Sua execução deve conter os seguintes parâmetros: \n");
		printf("n numero_excucoes\n");
		return 0;
	}
	int n = atoi(argv[1]);
	int numero_excucoes = atoi(argv[2]);

	int fact = fatorial(n);

	int perm[fact][n];
	int lista[fact][n];
	int j = 0;
	for (j = 0; j < n; ++j) {
		for (int i = 0; i < fact; ++i){
			lista[i][j] = 0;
			if (j == 2) lista[i][j] = 1;
			perm[i][j] = 0;
		}
	}
	int ind_i = 0;

	// for (k = 0; k < n; ++k) {
	// 	permutation(perm, n, k);
	// }

	for (j = 0; j < n && lista[ind_i][j] != 1; ++j);
	//j == 2
	printf("%d  ld %d\n",j, lista[ind_i][j]);


	return 0;
}


