#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX_ARRAY 1000

struct timespec ts;

static double rtclock() {
  struct timespec t;
  clock_gettime(CLOCK_REALTIME, &t);
  return t.tv_sec + t.tv_nsec * 1e-9;
}

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

/*Versão INSERT-SORT Daniel Sozinho**/
void insert(int* vetor, int n) {
	int temp;
	int i, j;
	for (i = 0, j = i+1; j < n && i < n; ++j)
	{
		if (vetor[i] > vetor[j]) {
			temp = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = temp;

			for (int k = i-1; k >= 0; --k) {
				if (vetor[i] < vetor[k]) {
					temp = vetor[i];
					vetor[i] = vetor[k];
					vetor[k] = temp;
					i = k;
				} else {
					break;
				}
			}
			i = j;
		} else {
			++i;
			j = i + 1;
		}
	}
}

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
			/*Linhas 109 a 115 são para garantir a estabilidade (= Um algoritmo de ordenação diz-se estável se preserva a ordem de registros de chaves iguais. Isto é, se tais registros aparecem na sequência ordenada na mesma ordem em que estão na sequência inicial.)*/
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

int particionaAleat(int* A, int p, int r) { 
    int temp, i;
    i = p + (rand() % (r-p+1));
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    return particiona(A, p , r);
}

void quicksortAleat(int* A, int p, int r) {
    int q;
    if (p < r) {
        q = particionaAleat(A, p, r);
        quicksortAleat(A, p, q-1);
        quicksortAleat(A, q+1, r);
    }
}

int main(int argc, char* argv[]) {
	int size_max, repeticoes;
	if (argc < 3) {
		size_max = MAX_ARRAY;
		repeticoes = 10;
		printf("size_max = %d\nrepeticoes = 10\n",MAX_ARRAY);
	} else {
		size_max = atoi(argv[1]);
		repeticoes = atoi(argv[2]);
		printf("size_max = %d\nrepeticoes = %d\n", size_max, repeticoes);
	}
	int vetor[size_max], buffer[size_max];
	double tempo, maximo, minimo, somatorio;
	double a, b;
	

	for (int i = 0; i < size_max; ++i) {
		vetor[i] = rand() % 100;
		buffer[i] = vetor[i];
	}
	// for (int i = 0; i < size_max; ++i) {
	// 	printf("%d - ", vetor[i]);
	// }
	// printf("\n");



	// ######## BUBBLE ################################# 
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		bubble(vetor,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("bubble:     Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);


	// ######## INSERT #################################
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		insertSort(vetor,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("insertSort: Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);

	// ######## SELECTION #################################
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		selectionSort(vetor,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("SelectSort: Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);


	// ######## MERGE #################################
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		MergeSort(vetor,0,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("MergeSort: Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);


	// ######## QUICK #################################
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		quicksort(vetor,0,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("QuickSort: Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);

	// ######## QUICK ALEAT #################################
	somatorio = 0;
	for (int i = 0; i < repeticoes; ++i)
	{
		a = rtclock();
		quicksortAleat(vetor,0,size_max);
		b = rtclock();
		tempo = b-a;
		if (i == 0) { 
			maximo = tempo; 
			minimo = maximo;
		} else {
			if (maximo < tempo) maximo = tempo;	
			if (minimo > tempo) minimo = tempo;
		}
		somatorio = b-a + somatorio;	
		// for (int i = 0; i < size_max; ++i) {
		// 	printf("%d - ", vetor[i]);
		// }
		// printf("\n");

		for (int k = 0; k < size_max; ++k) {
			vetor[k] = buffer[k];
		}
	}
	printf("QuickSortAleat: Max %lf Min %lf Media %lf\n", maximo, minimo, somatorio/(double)repeticoes);
	return 0;
}