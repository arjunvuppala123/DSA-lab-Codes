server: queueimp.o queuemain.o
	gcc -o server queuemain.o queueimp.o
queueimp.o: queueimp.c queue.h
	gcc -c queueimp.c queue.h
queuemain.o: queue.h queuemain.c
	gcc -c queue.h  queuemain.c