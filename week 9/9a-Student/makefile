server: etimp.o etmain.o
	gcc -o server etmain.o etimp.o
etimp.o: etimp.c et.h
	gcc -c etimp.c et.h
etmain.o: et.h etmain.c
	gcc -c et.h  etmain.c