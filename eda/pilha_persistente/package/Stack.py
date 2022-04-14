from .Node import Node

class Stack():
	def __init__(self, value = None, parent = None, depth = 0):
		self.pilha = Node(value, parent, depth)

def Size(stack):
	return stack.pilha.depth

def Push(stack, value):
	parent = stack.pilha
	depth = (Size(stack))+1
	return Stack(value, parent, depth)

def Pop(stack):
	return Stack(stack.pilha.parent.value, stack.pilha.parent.parent, stack.pilha.parent.depth)	

def Top(stack):
	return stack.pilha.value
