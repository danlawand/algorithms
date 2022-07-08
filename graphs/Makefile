
CC     = g++
RM     = rm
CFLAGS = -g
OBJS   = client.o queue.o

exe:  $(OBJS)
	$(CC) $(OBJS) -o exe

client.o: client.cpp queue.cpp queue.h node.h item.h 
	$(CC) $(CFLAGS) -c client.cpp

queue.o: queue.cpp queue.h node.h item.h 
	$(CC) $(CFLAGS) -c queue.cpp

clean:
	$(RM) *.o *~ exe