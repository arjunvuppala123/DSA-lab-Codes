server: 5aimp.o 5amain.o
	gcc -o server 5amain.o 5aimp.o
5aimp.o: 5aimp.c 5a.h
	gcc -c 5aimp.c 5a.h
5amain.o: 5a.h 5amain.c
	gcc -c 5a.h  5amain.c