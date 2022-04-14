from package.Deque import *
def main():
	p = Deque()
	print(type(p))
	s = PushBack(p, 3)
	print(type(s))
	t = PushBack(s, 4)
	print(type(t))
	q = PushFront(t, 2)
	print(type(q))
	qui = PushFront(q, 1)
	print(type(qui))
	six = PopBack(q)
	print(type(six))
	sev = PopBack(six)
	print(type(sev))

	print()
	print("Primeira")
	depth = p.first.depth
	print("Primeira.First.Value", p.first.value, "Depth = ", depth)
	depth = p.last.depth
	print("Primeira.Last.Value", p.last.value, "Depth = ", depth)
	print()
	print("Segunda")
	depth = s.first.depth
	print("Segunda.First.Value", s.first.value, "Depth = ", depth)
	depth = s.last.depth
	print("Segunda.Last.Value", s.last.value, "Depth = ", depth)
	print("Segunda.First.Parent.Value", s.first.parent.value, "  == Primeira")
	print("Segunda.Last.Parent.Value", s.last.parent.value, "  == Primeira")
	print()
	print("Terceira")
	depth = t.first.depth
	print("Terceira.First.Value", t.first.value, " Depth = ", depth, "  == Segunda")
	depth = t.last.depth	
	print("Terceira.Last.Value", t.last.value, " Depth = ", depth)
	print("Terceira.First.Parent.Value", t.first.parent.value, "  == Primeira")
	print("Terceira.Last.Parent.Value", t.last.parent.value, "  == Segunda == Terceira.First")
	print("Terceira.Last.Parent.Parent.Value", t.last.parent.parent.value, "  == Primeira")
	print()
	print("Quarta")
	depth = q.first.depth
	print("Quarta.First.Value", q.first.value, "Depth = ", depth)
	depth = q.last.depth
	print("Quarta.Last.Value", q.last.value, "Depth = ", depth, "  == Terceira.Last")
	print("Quarta.First.Parent.Value", q.first.parent.value, "  == Segunda")
	print("Quarta.Last.Parent.Value", q.last.parent.value, "  == Segunda")
	print("Quarta.First.Parent.Parent.Value", q.first.parent.parent.value, "  == Primeira")
	print("Quarta.Last.Parent.Parent.Value", q.last.parent.parent.value, "  == Primeira")
	print()
	print("Quinta")
	depth = qui.first.depth
	print("Quinta.First.Value", qui.first.value, "Depth = ", depth)
	depth = qui.last.depth	
	print("Quinta.Last.Value", qui.last.value, "Depth = ", depth, "  == Quarta.Last")
	print("Quinta.First.Parent.Value", qui.first.parent.value, "  == Quarta")
	print("Quinta.Last.Parent.Value", qui.last.parent.value, "  == Segunda")
	print("Quinta.First.Parent.Parent.Value", qui.first.parent.parent.value, "  == Segunda")
	print("Quinta.Last.Parent.Parent.Value", qui.last.parent.parent.value, "  == Primeira")
	print("Quinta.First.Parent.Parent.Parent.Value", qui.first.parent.parent.parent.value, "  == Primeira")
	print()

	print("Sexto")
	depth = six.first.depth
	print("Sexto.First.Value", six.first.value, "Depth = ", depth, "  == Quarta.First")
	depth = six.last.depth
	print("Sexto.Last.Value", six.last.value, "Depth = ", depth, "  == Segunda")
	print("Sexto.First.Parent.Value", six.first.parent.value,"  == Segunda")
	print("Sexto.Last.Parent.Value", six.last.parent.value, "  == Primeira")
	print("Sexto.First.Parent.Parent.Value", six.first.parent.parent.value, "  == Primeira")	
	print()

	print("Sétimo")
	depth = sev.first.depth
	print("Sétimo.First.Value", sev.first.value, "Depth = ", depth)
	depth = sev.last.depth	
	print("Sétimo.Last.Value", sev.last.value, "Depth = ", depth)
	print()


main()