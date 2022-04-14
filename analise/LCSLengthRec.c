LCSLengthRec(x, i, y, j) {
	se i = 0 ou j = 0 devolva 0
	se x[i] = y[j]
		return 1 + LCSLengthRec(x, i-1, y, j-1)
	else
		q1 = LCSLengthRec(x, i-1, y, j)
		q2 = LCSLengthRec(x, i, y, j-1)
		se q1 < q2 
			return q1
		else
			return q2
}