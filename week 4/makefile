server: cllimp.o cllmain.o
	gcc -o server cllmain.o cllimp.o
cllimp.o: cllimp.c cll.h
	gcc -c cllimp.c cll.h
cllmain.o: cll.h cllmain.c
	gcc -c cll.h cllmain.c