server: 6bimp.o 6bmain.o
	gcc -o server 6bmain.o 6bimp.o
6bimp.o: 6bimp.c 6b.h
	gcc -c 6bimp.c 6b.h
6bmain.o: 6b.h 6bmain.c
	gcc -c 6b.h  6bmain.c