a.out:  gbtree.o gpila_node.o gqueue_node.o
	gcc -Wall  gbtree.o gpila_node.o gqueue_node.o -o a.out

gbtree.o: gbtree.c gbtree.h
	gcc -Wall -c gbtree.c

gpila_node.o: gpila_node.c gpila_node.h
	gcc -Wall -c gpila_node.c

gqueue_node.o: gqueue_node.c gqueue_node.h
	gcc -Wall -c gqueue_node.c

clean:
	rm *.o a.out