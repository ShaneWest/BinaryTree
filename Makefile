CC = gcc
CFLAGS = -o binarytree
LDFLAGS = -lm

OBJS = binarymain.o binarytree.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) binarytree
