# def ABBOtima():


def main():
	e = [10, 20, 30, 15, 5]
	s =[0]
	n = len(e) # n = 5
	for i in range(1, n + 1):
		s.append(e[i-1]+s[i-1])
	r = []
	c = []
	for i in range(n+2):
		linha = []
		line = []
		for j in range(n+1):
			linha.append(0)
			line.append(0)
		c.append(linha)
		r.append(line)

	for d in range(1, n+1):
		for i in range(1, n-d+2):
			j = i + d - 1
			r[i][j] = i
			print("Primeiro", i, "", j)
			c[i][j] = c[i+1][j]
			for k in range(i+1,j+1):
				if (c[i][k-1]+c[k+1][j] < c[i][j]):
					c[i][j] = c[i][k-1] + c[k+1][j]
				if (c[i][k-1]+c[k+1][j] < c[i][j]):
					r[i][j]=k
			c[i][j] = c[i][j]+s[j]-s[i-1]
			print(c[i][j])
	print(c[1][n])
	for linha in c:
		print(linha)
	print()
	for line in r:
		print(line)
main()