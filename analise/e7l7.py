def main():
	a = [0, 4, 6, 8, 2, 10, 12, 14] 
	b = [6, 6, 6, 6, 5, 5, 5, 5] 

	soma = 0
	for i in range(8):
		soma = soma + a[i] + b[i]
	print(soma)
	for i in range(8):
		a[i] = a[i]/soma
		b[i] = b[i]/soma

	print()
	print(a)
	print()
	print(b)
main()
