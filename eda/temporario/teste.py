def main():
	file = open('entrada_deque.txt', 'r')
	Lines = file.readlines()
	for line in Lines:
		if line[0] != '#':
			print(line)
main()