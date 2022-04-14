from .Node import Node

class Deque():
	def __init__(self, first = None, last = None, value = None, parent = None, depth = None):
		if first == None and last == None:
			self.first = Node(value, parent, 0)
			self.last = self.first
		elif first == None:
			self.first = Node(value, parent, depth)
			self.last = last
		elif last == None:
			self.last = Node(value, parent, depth)
			self.first = first
		else:
			self.last = last
			self.first = first

# def LevelAncestor(k, u):
# 	y = D(u) - k
# 	while (D(u) != y):
# 		if (D(u.jump) >= y):
# 			u = u.jump
# 		else:
# 			u = parent(u)
# 	return u

def Size(No):
	return No.depth


def PushBack(deque, value):
	parent = deque.last 
	if deque.first.value != None:
		first = deque.first
	else:
		first = None
	last = None
	depth = Size(deque.last)+1
	return Deque(first, last, value, parent, depth)
	

def PushFront(deque, value):
	parent = deque.first 

	if deque.last.value != None:
		last = deque.last
	else:
		last = None
	first = None
	depth = Size(deque.first)+1
	return Deque(first, last, value, parent, depth)

## Teste "Sev" ta dando errado, talvez tenha que implementar o kth para o pop

def PopBack(deque):
	first = deque.first
	last = deque.last.parent
	return Deque(first, last, None, None, None)

def PopFront(deque):
	first = deque.first.parent
	last = deque.last
	return Deque(first, last, None, None, None)


# def Top(stack):
# 	return stack.pilha.value


# Front(d): devolve o elemento no extremo front de d
# Back(d): devolve o elemento no extremo back de d
# PopFront(d): remove o elemento no extremo front de d
# PopBack(d): remove o elemento no extremo back de d
# Kth(d,k): k-ésimo elemento de d, onde o front é o primeiro elemento de d
# Print(d): imprime todos os elementos da deque d