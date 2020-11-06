server: heapimp.o heapmain.o
	gcc -o server heapmain.o heapimp.o
heapimp.o: heapimp.c heap.h
	gcc -c heapimp.c heap.h
heapmain.o: heap.h heapmain.c
	gcc -c heap.h  heapmain.c