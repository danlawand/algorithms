# Daniel Angelo Esteves Lawand
# NUSP: 10297693
#
import random

def SomaPares(v, n):
	soma = 0

	for i in range(n):
		if v[i]%2 == 0:
			soma = soma + v[i]
	return soma

def main():
	n = int(input('Tamanho do Vetor '))
	m = int(input('Número de Execuções '))
	v = list(range(n))
	d = dict()
	soma_pares = 0

	random.seed(1)
	for j in range(m):
		for i in range(0, n):
			v[i] =  random.randint(1, 10)

		soma_pares = SomaPares(v, n)
		d[soma_pares] = d.get(soma_pares, 0) + 1


	print()
	print("Soma mais esperada: ", n*3)
	print("Lista: Soma | Ocorrência")
	sort_d = sorted(d.items(), key=lambda x: x[1], reverse=True)
	for items in sort_d:
	    print(items[0], items[1])

main()