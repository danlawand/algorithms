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
		q = (int)((p+r)/2)
		inversoes = mergesort(A, p, q) + inversoes
		inversoes = mergesort(A, q+1, r) + inversoes
		inversoes = intercala(A, p, q, r) + inversoes
	return inversoes


def main():
	C = [22, 33, 55, 62, 78, 11, 42, 61, 88, 99]
	A = [5, 2, 4, 3, 1]
	p = 0
	r = 4
	print(mergesort(A, 0, len(A)-1))
	print("----")
	print(mergesort(C, 0, len(C)-1))
main()