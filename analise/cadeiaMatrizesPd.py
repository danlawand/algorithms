def main():
	p = [5, 10, 3, 12, 5, 50, 6]
	t = []
	m = []
	n = 7
	for i in range(n):
	# cria a linha i
		linha = [] # lista vazia
		for j in range(n):
			linha.append(0)
		print(len(linha))
		m.append(linha)
		t.append(linha)
	print()
	# for i in range(0, n):
	# 	m[i,i]=0

	for d in range(2, n):
		print("D",d)
		for i in range(1, n-d+1):
			j = i + d-1
			print("Primeiro", i, "", j)
			m[i][j]=10000000
			for k in range(i, j):
				print("   Segundo",i, "", j, " -- k: ", k)
				print("       m[i][k]",m[i][k])
				print("       m[k+1][k]",m[k+1][j])
				print("       p[i-1]",p[i-1])
				print("       p[k]",p[k])
				print("       p[j]",p[j])

				q = (m[i][k]) + (m[k+1][j]) + (p[i-1]*p[k]*p[j])
				
				print("       m[i][j]",m[i][j])
				print("       q",q)
				if q < m[i][j]:
					print("        Menor",i, "", j, " -- k: ", k)
					print("        q",q)
					m[i][j] = q
				print("       m[i][j]",m[i][j])
	print(m[i][j])


	print()
	for i in range(1, n):
		for j in range (1, n):
			print(m[i][j], end=" ")
		print()

main()