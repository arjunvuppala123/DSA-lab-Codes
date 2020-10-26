server: 6aimp.o 6amain.o
	gcc -o server 6amain.o 6aimp.o
6aimp.o: 6aimp.c 6a.h
	gcc -c 6aimp.c 6a.h
6amain.o: 6a.h 6amain.c
	gcc -c 6a.h  6amain.c