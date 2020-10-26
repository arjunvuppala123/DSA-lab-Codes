server: dllimp.o dllmain.o
	gcc -o server dllmain.o dllimp.o
dllimp.o: dllimp.c dll.h
	gcc -c dllimp.c dll.h
dllmain.o: dll.h dllmain.c
	gcc -c dll.h  dllmain.c