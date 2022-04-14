def intercala(A, p, q, r):
	B = []
	inversoes = 0
	for i in range(p, q+1):
		B.append(A[i])
	for j in range(r, q, -1):
		B.append(A[j])
	i = 0
	j = r - p
	m = q - p

	for k in range(p, r+1):
		if (B[i] <= B[j]):
			A[k] = B[i]
			i = i+1
		else:
			inversoes = inversoes + m - i + 1
			A[k] = B[j]
			j = j-1
	return inversoes

def mergesort(A, p, r):
	inversoes = 0
	if (p < r):
		q = (int)((p+r)/2) # Theta(1)
		inversoes = mergesort(A, p, q) + inversoes # T(floor(n/2))
		inversoes = mergesort(A, q+1, r) + inversoes # T(ceil(n/2))
		inversoes = intercala(A, p, q, r) + inversoes # Theta(n)
	return inversoes
