
a.out: test.o btree.o gpila.o glist.o gqueue.o cglist.o
	gcc -Wall test.o btree.o gpila.o glist.o gqueue.o cglist.o -o a.out

test.o: test.c
	gcc -Wall -c test.c

btree.o: btree.c btree.h
	gcc -Wall -c btree.c

gpila.o: gpila.c gpila.h
	gcc -Wall -c gpila.c

glist.o: glist.c glist.h
	gcc -Wall -c glist.c

gqueue.o: gqueue.c gqueue.h
	gcc -Wall -c gqueue.c

cglist.o: cglist.c cglist.h
	gcc -Wall -c cglist.c

clean:
	rm *.o a.out