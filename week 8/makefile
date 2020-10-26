server: bstimp.o bstmain.o
	gcc -o server bstmain.o bstimp.o
bstimp.o: bstimp.c bst.h
	gcc -c bstimp.c bst.h
bstmain.o: bst.h bstmain.c
	gcc -c bst.h bstmain.c